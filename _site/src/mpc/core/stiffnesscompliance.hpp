/**
 *    \file stiffnesscompliance.hpp
 *    \brief stiffness and compliance tensor classes; part of the core data structures
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef MPC_STIFFNESSCOMPLIANCE_H
#define MPC_STIFFNESSCOMPLIANCE_H

#include <iostream>
#include <set>

// blitz
#include <blitz/array.h>

// mpc
#include "symmetrygrouptypes.hpp"
#include "cstypes.hpp"
#include "tensorcomponent.hpp"
#include "symmetrycomponents.hpp"
#include "../util/matrixnotation.hpp"

namespace mpc {
namespace core {

/**
* \class TensorRank4Interface
* \brief simple interface for tensors of rank 4
*/
template <typename T>
struct TensorRank4Interface {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //virtual void SetComponents(std::set< mpc::core::TensorRank4Component<T> >& components) = 0;  // ???  http://www.modernescpp.com/index.php/c-core-guidelines-class-hierarchies
};

/**
* \class TensorRank4Base
* \brief base class for tensors of rank 4
*
* The tensors in mpc are three dimensional cartesian tensors; this base class provides
*/
template <typename T>
struct TensorRank4Base : TensorRank4Interface<T> {
        blitz::Array<T,4> tensor = blitz::Array<T,4>(3, 3, 3, 3, blitz::ColumnMajorArray<4>());
        TensorRank4Base() {
                tensor = 0.0;
        }
};

/**
* \class StiffnessTensor
* \brief stiffness tensor class with function to set the components with a given symmety type
*/
template <typename T>
struct StiffnessTensor : TensorRank4Base<T> {
        using TensorRank4Base<T>::tensor;
        typedef mpc::core::StiffnessType cstype;

        template <typename S>
        void SetComponentsWithSymmetry(std::set< mpc::core::TensorRank4Component<T> >& components) {
                static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
                // TODO: assert IsComponentSetSymmetryCompliant<>()...
                mpc::core::TensorRank4SymmetryComponents<T,mpc::core::StiffnessType,S>(components);

                // if S is NoneSymmetryType, assign components to tensor
                if (S::SymmetryGroupEnum() == mpc::core::SymmetryGroupEnumeration::NONE) {
                        for (auto c : components) {
                                // need blitz::TinyVector<int,4> for Index
                                auto index = mpc::core::TensorRank4ComponentIndex::ToBlitzTinyVector(c.Index());
                                tensor(index) = c.Value();
                        }
                }
                // else, the type is one of symmetry, thus use matrix notation
                else {
                        blitz::Array<T,2> mat = blitz::Array<T,2>(6,6,blitz::ColumnMajorArray<2>());

                        for (auto c : components) {
                                mpc::core::TensorRank4ComponentIndex c_index = c.Index();
                                int p = mpc::util::GetVoigtMatrixIndex(c_index.FirstIndex(), c_index.SecondIndex());
                                int q = mpc::util::GetVoigtMatrixIndex(c_index.ThirdIndex(), c_index.FourthIndex());

                                mat(p,q) = c.Value();
                                mat(q,p) = c.Value(); // voigt matrix is symmetrical
                        }
                        // matrix to tensor
                        mpc::util::VoigtMatrixToStiffnessTensor(mat, tensor);
                }

        }

};

/**
* \class ComplianceTensor
* \brief compliance tensor class with function to set the components with a given symmety type
*/
template <typename T>
struct ComplianceTensor : TensorRank4Base<T> {
        using TensorRank4Base<T>::tensor;
        typedef mpc::core::ComplianceType cstype;

        template <typename S>
        void SetComponentsWithSymmetry(std::set< mpc::core::TensorRank4Component<T> >& components) {
                static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
                // TODO: assert IsComponentSetSymmetryCompliant<>()...
                mpc::core::TensorRank4SymmetryComponents<T,mpc::core::ComplianceType,S>(components);

                // if S is NoneSymmetryType, assign components to tensor
                if (S::SymmetryGroupEnum() == mpc::core::SymmetryGroupEnumeration::NONE) {
                        for (auto c : components) {
                                // need blitz::TinyVector<int,4> for Index
                                auto index = mpc::core::TensorRank4ComponentIndex::ToBlitzTinyVector(c.Index());
                                tensor(index) = c.Value();
                        }
                }
                // else, the type is one of symmetry, thus use matrix notation
                else {
                        blitz::Array<T,2> mat = blitz::Array<T,2>(6,6,blitz::ColumnMajorArray<2>());

                        for (auto c : components) {
                                mpc::core::TensorRank4ComponentIndex c_index = c.Index();
                                int p = mpc::util::GetVoigtMatrixIndex(c_index.FirstIndex(), c_index.SecondIndex());
                                int q = mpc::util::GetVoigtMatrixIndex(c_index.ThirdIndex(), c_index.FourthIndex());

                                mat(p,q) = c.Value();
                                mat(q,p) = c.Value(); // voigt matrix is symmetrical
                        }
                        // matrix to tensor
                        mpc::util::VoigtMatrixToStiffnessTensor(mat, tensor);
                }

        }
};
//
}  // namespace core
}  // namespace mpc

#endif // MPC_STIFFNESSCOMPLIANCE_H
