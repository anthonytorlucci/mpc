/**
 *    \file tensorinvariants.hpp
 *    \brief tensor invariants - reduction in tensor rank by contraction,
 * usually to a rank zero tensor or scalar; for stiffness and compliance
 * tensors, the bulk and shear modulii can be derived from the invariants
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_TENSORINVARIANTS_H
#define MPC_TENSORINVARIANTS_H

// c++
#include <iostream>
#include <utility>

// blitz
#include <blitz/array.h>

// mpc
#include "mpc/core/stressstrain.hpp"
#include "mpc/core/stiffnesscompliance.hpp"
#include "mpc/utilities/constants.hpp"
#include "mpc/utilities/kroneckerdelta.hpp"
#include "mpc/rockphysics/rockphysicstransformstypes.hpp"

namespace mpc {
    namespace rockphysics {

        // based on DeWit (2008)
        template <typename T>
        std::pair< mpc::rockphysics::BulkModulusType<T>,mpc::rockphysics::ShearModulusType<T> > GetVoigtBulkAndShearModulusFromStiffnessTensor(mpc::core::StiffnessTensor<T>& c) {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            T k = 0;
            T mu = 0;
            T one_third = T(1.0/3.0);
            T one_ninth = T(1.0/9.0);
            T one_tenth = T(0.1);
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    k += one_ninth * c.tensor(i,i,j,j);
                    mu += one_tenth * (c.tensor(i,j,i,j) - (one_third * c.tensor(i,i,j,j)));
                }
            }

            mpc::rockphysics::BulkModulusType<T> k_type = mpc::rockphysics::BulkModulusType<T>(k);
            mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(mu);
            return std::pair< mpc::rockphysics::BulkModulusType<T>,mpc::rockphysics::ShearModulusType<T> >{k_type,mu_type};
        }

        template <typename T>
        std::pair< mpc::rockphysics::BulkModulusType<T>,mpc::rockphysics::ShearModulusType<T> > GetRuessBulkAndShearModulusFromCompliance(mpc::core::ComplianceTensor<T>& s) {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            T k_r = 0; // reciprocal of bulk modulus
            T mu_r = 0; // reciprocal of shear modulus
            T two_fifths = T(2.0/5.0);
            T one_third = T(1.0/3.0);
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    k_r += s.tensor(i,i,j,j);
                    mu_r += two_fifths * (s.tensor(i,j,i,j) - (one_third * s.tensor(i,i,j,j)));
                }
            }

            mpc::rockphysics::BulkModulusType<T> k_type = mpc::rockphysics::BulkModulusType<T>(T(1.0 / k_r));
            mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(T(1.0 / mu_r));
            return std::pair< mpc::rockphysics::BulkModulusType<T>,mpc::rockphysics::ShearModulusType<T> >{k_type,mu_type};
        }

        template <typename T>
        void MakeIsotropicStiffnessTensor(T kappa, T mu, mpc::core::StiffnessTensor<T>& c) {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            c.tensor = 0; // zero out all components
            blitz::Array<T,2> kdelta = mpc::utilities::KroneckerDelta<T,3>();

            T two_thirds = T(2.0/3.0);
            T tmp1 = 0;
            T tmp2 = 0;

            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            tmp1 = kappa * kdelta(i,j) * kdelta(k,l);
                            tmp2 = (kdelta(i,k) * kdelta(j,l)) + (kdelta(i,l) * kdelta(j,k)) - (two_thirds * kdelta(i,j) * kdelta(k,l));
                            c.tensor(i,j,k,l) = tmp1 + (mu * tmp2);
                        }
                    }
                }
            }
        }

        template <typename T>
        void MakeIsotropicComplianceTensor(T kappa, T mu, mpc::core::ComplianceTensor<T>& s) {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            s.tensor = 0;
            T ninek_r = T(1.0 / (9.0 * kappa));
            T fourmu_r = T(1.0/ (4.0 * mu));
            T two_thirds = T(2.0/3.0);
            T tmp1 = 0;
            T tmp2 = 0;

            blitz::Array<T,2> kdelta = mpc::utilities::KroneckerDelta<T,3>();

            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            tmp1 = ninek_r * kdelta(i,j) * kdelta(k,l);
                            tmp2 = (kdelta(i,k) * kdelta(j,l)) + (kdelta(i,l) * kdelta(j,k)) - (two_thirds * kdelta(i,j) * kdelta(k,l));
                            s.tensor(i,j,k,l) = tmp1 + (fourmu_r * tmp2);
                        }
                    }
                }
            }
        }

        // based on Helbig (1994)
        // NOTE: assumes tensors are 3 dimensional
        template <typename T>
        T Rank2TensorContraction(const mpc::core::TensorRank2Base<T>& gamma_ij) {
            // alpha = trace(tensor_ij)
            // produces a scalar quantity that is invariant with respect to coordinates
            return gamma_ij.tensor(0,0) + gamma_ij.tensor(1,1) + gamma_ij.tensor(2,2);
        }

        // specialization of Rank2TensorContraction
        template <typename T>
        T StressTensorContraction(const mpc::core::StressTensor<T>& sigma_ij) {
            // sigma_kk = (sigma_ik) * (kronecker_delta_ik)
            // sigma_kk = trace(sigma_ij)
            // sigma_kk = 3 * sigma_0 where sigma_0 is the hydrostatic stress, pressure, or mean stress
            // produces a scalar quantity that is invariant with respect to coordinates
            return sigma_ij.tensor(0,0) + sigma_ij.tensor(1,1) + sigma_ij.tensor(2,2);
        }

        // specialization of Rank2TensorContraction
        template <typename T>
        T StrainTensorContraction(const mpc::core::StrainTensor<T>& epsilon_ij) {
            // epsilon_kk = (epsilon_ik) * (kronecker_delta_ik)
            // epsion_kk = trace(epsilon_ij)
            // epsilon_kk is the volumetric strain
            // produces a scalar quantity that is invariant with respect to coordinates
            return epsilon_ij.tensor(0,0) + epsilon_ij.tensor(1,1) + epsilon_ij.tensor(2,2);
        }

        template <typename T>
        mpc::core::TensorRank2Base<T> DilationalStiffnessTensorContraction(const mpc::core::StiffnessTensor<T>& c_ijkl) {
            // TODO:
            // reduces the rank of the tensor from 4 to 2
            return mpc::core::TensorRank2Base<T>();
        }

        template <typename T>
        mpc::core::TensorRank2Base<T> VoigtStiffnessTensorContraction(const mpc::core::StiffnessTensor<T>& c_ijkl) {
            // TODO:
            // reduces the rank of the tensor from 4 to 2
            return mpc::core::TensorRank2Base<T>();
        }

        template <typename T>
        mpc::core::TensorRank2Base<T> HydrostaticPressureComplianceTensorContraction(const mpc::core::ComplianceTensor<T>& s_ijkl) {
            // TODO:
            // reduces the rank of the tensor from 4 to 2
            return mpc::core::TensorRank2Base<T>();
        }

        template <typename T>
        mpc::core::TensorRank2Base<T> RuessComplianceTensorContraction(const mpc::core::ComplianceTensor<T>& s_ijkl) {
            // TODO:
            // reduces the rank of the tensor from 4 to 2
            return mpc::core::TensorRank2Base<T>();
        }



    }  // namespace rockphysics
}  // namespace mpc

#endif // MPC_TENSORINVARIANTS_H
