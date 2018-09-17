/**
 *    \file tensorinvariants.hpp
 *    \brief tensor invariants - reduction in tensor rank by contraction,
 * usually to a rank zero tensor or scalar; for stiffness and compliance
 * tensors, the bulk and shear modulii can be derived from the invariants
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef MPC_TENSORINVARIANTS_H
#define MPC_TENSORINVARIANTS_H

#include <iostream>
#include <utility>

// blitz
#include <blitz/array.h>

// mpc
#include "stiffnesscompliance.hpp"
#include "../util/constants.hpp"
#include "../util/kroneckerdelta.hpp"

namespace mpc {
namespace core {

// based on DeWit (2008)
template <typename T>
std::pair<T,T> GetVoigtBulkAndShearModulusFromStiffnessTensor(mpc::core::StiffnessTensor<T>& c) {
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

        return std::pair<T,T>{k,mu};
}

template <typename T>
std::pair<T,T> GetRuessBulkAndShearModulusFromCompliance(mpc::core::ComplianceTensor<T>& s) {
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

        return std::pair<T,T>{T(1.0 / k_r),T(1.0 / mu_r)};
}

template <typename T>
void MakeIsotropicStiffnessTensor(T kappa, T mu, mpc::core::StiffnessTensor<T>& c) {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        c.tensor = 0; // zero out all components
        blitz::Array<T,2> kdelta = mpc::util::KroneckerDelta<T,3>();

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

        blitz::Array<T,2> kdelta = mpc::util::KroneckerDelta<T,3>();

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

}  // namespace core
}  // namespace mpc

#endif // MPC_TENSORINVARIANTS_H
