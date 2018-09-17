/**
 *    \file mineraldatatensors.hpp
 *    \brief functions that return stiffness tensor objects from the mineral data properties
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef MINERALDATATENSORSANDMATRICES_H
#define MINERALDATATENSORSANDMATRICES_H

#include <set>

#include "mineraldataproperties.hpp"

#include "../core/symmetrygrouptypes.hpp"
#include "../core/stiffnesscompliance.hpp"

namespace mpc {
namespace data {

// Augite
template <typename T>
mpc::core::StiffnessTensor<T> AugiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::AugiteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Augite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AugiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Albite
template <typename T>
mpc::core::StiffnessTensor<T> AlbiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::AlbiteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Albite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AlbiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); //https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;

}

// Anorthite
template <typename T>
mpc::core::StiffnessTensor<T> AnorthiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::AnorthiteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Anorthite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnorthiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Labradorite
template <typename T>
mpc::core::StiffnessTensor<T> LabradoriteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::LabradoriteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Labradorite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::LabradoriteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Microcline
template <typename T>
mpc::core::StiffnessTensor<T> MicroclineStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::MicroclineSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Microcline in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MicroclineC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Oligoclase
template <typename T>
mpc::core::StiffnessTensor<T> OligoclaseStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::OligoclaseSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Oligoclase in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::OligoclaseC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Coesite
template <typename T>
mpc::core::StiffnessTensor<T> CoesiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::CoesiteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Coesite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CoesiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Epidote
template <typename T>
mpc::core::StiffnessTensor<T> EpidoteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::EpidoteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Epidote in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EpidoteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Hornblende
template <typename T>
mpc::core::StiffnessTensor<T> HornblendeStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::HornblendeSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Hornblende in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::HornblendeC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Muscovite
template <typename T>
mpc::core::StiffnessTensor<T> MuscoviteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::MuscoviteSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Muscovite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MuscoviteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Gypsum
template <typename T>
mpc::core::StiffnessTensor<T> GypsumStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::MONOCLINIC_X2
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::GypsumSymmetryClass() == mpc::core::SYMMETRY::MONOCLINIC_X2, "symmetry type mismatch; verify symmetry of Gypsum in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c15, T c22, T c23, T c25, T c33, T c35, T c44, T c46, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC15<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC35<T>(), mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC46<T>(), mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GypsumC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Enstatite
template <typename T>
mpc::core::StiffnessTensor<T> EnstatiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::EnstatiteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Enstatite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        //void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Forsterite
template <typename T>
mpc::core::StiffnessTensor<T> ForsteriteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::ForsteriteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Forsterite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::EnstatiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Fayalite
template <typename T>
mpc::core::StiffnessTensor<T> FayaliteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::FayaliteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Fayalite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::FayaliteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Montecellite
template <typename T>
mpc::core::StiffnessTensor<T> MontecelliteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::MontecelliteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Montecellite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::MontecelliteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Andalusite
template <typename T>
mpc::core::StiffnessTensor<T> AndalusiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::AndalusiteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Andalusite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AndalusiteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Silimanite
template <typename T>
mpc::core::StiffnessTensor<T> SilimaniteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::SilimaniteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Silimanite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::SilimaniteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Barite
template <typename T>
mpc::core::StiffnessTensor<T> BariteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::BariteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Barite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BariteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Anhydrite
template <typename T>
mpc::core::StiffnessTensor<T> AnhydriteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::ORTHORHOMBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::AnhydriteSymmetryClass() == mpc::core::SYMMETRY::ORTHORHOMBIC, "symmetry type mismatch; verify symmetry of Anhydrite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c22, T c23, T c33, T c44, T c55, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC22<T>(), mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC23<T>(), mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC55<T>(), mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::AnhydriteC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Dolomite
template <typename T>
mpc::core::StiffnessTensor<T> DolomiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TRIGONAL7
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::DolomiteSymmetryClass() == mpc::core::SYMMETRY::TRIGONAL7, "symmetry type mismatch; verify symmetry of Dolomite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c14, T c25, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC14<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC25<T>(), mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::DolomiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Trigonal7SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Rutile
template <typename T>
mpc::core::StiffnessTensor<T> RutileStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TETRAGONAL6
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::RutileSymmetryClass() == mpc::core::SYMMETRY::TETRAGONAL6, "symmetry type mismatch; verify symmetry of Rutile in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c33, T c44, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::RutileC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::RutileC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::RutileC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::RutileC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::RutileC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::RutileC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Tetragonal6SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Zircon
template <typename T>
mpc::core::StiffnessTensor<T> ZirconStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TETRAGONAL6
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::ZirconSymmetryClass() == mpc::core::SYMMETRY::TETRAGONAL6, "symmetry type mismatch; verify symmetry of Zircon in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c33, T c44, T c66)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::ZirconC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::ZirconC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::ZirconC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::ZirconC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::ZirconC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::ZirconC66<T>(), mpc::core::TensorRank4ComponentIndex(0,1,0,1))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Tetragonal6SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Corundum
template <typename T>
mpc::core::StiffnessTensor<T> CorundumStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TRIGONAL6
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::CorundumSymmetryClass() == mpc::core::SYMMETRY::TRIGONAL6, "symmetry type mismatch; verify symmetry of Corundum in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c14, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::CorundumC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::CorundumC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::CorundumC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CorundumC14<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CorundumC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CorundumC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Trigonal6SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Calcite
template <typename T>
mpc::core::StiffnessTensor<T> CalciteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TRIGONAL6
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::CalciteSymmetryClass() == mpc::core::SYMMETRY::TRIGONAL6, "symmetry type mismatch; verify symmetry of Calcite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c14, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::CalciteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::CalciteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::CalciteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CalciteC14<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CalciteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::CalciteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Trigonal6SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Quartz
template <typename T>
mpc::core::StiffnessTensor<T> QuartzStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TRIGONAL6
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::QuartzSymmetryClass() == mpc::core::SYMMETRY::TRIGONAL6, "symmetry type mismatch; verify symmetry of Quartz in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c14, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::QuartzC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::QuartzC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::QuartzC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::QuartzC14<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::QuartzC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::QuartzC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Trigonal6SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Tourmaline
template <typename T>
mpc::core::StiffnessTensor<T> TourmalineStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::TRIGONAL6
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::TourmalineSymmetryClass() == mpc::core::SYMMETRY::TRIGONAL6, "symmetry type mismatch; verify symmetry of Tourmaline in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c14, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::TourmalineC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::TourmalineC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::TourmalineC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::TourmalineC14<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::TourmalineC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::TourmalineC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::Trigonal6SymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Beryl
template <typename T>
mpc::core::StiffnessTensor<T> BerylStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::HEXAGONAL
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::BerylSymmetryClass() == mpc::core::SYMMETRY::HEXAGONAL, "symmetry type mismatch; verify symmetry of Beryl in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::BerylC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::BerylC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::BerylC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BerylC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::BerylC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Graphite
template <typename T>
mpc::core::StiffnessTensor<T> GraphiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::HEXAGONAL
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::GraphiteSymmetryClass() == mpc::core::SYMMETRY::HEXAGONAL, "symmetry type mismatch; verify symmetry of Graphite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c13, T c33, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::GraphiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::GraphiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::GraphiteC13<T>(), mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GraphiteC33<T>(), mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                mpc::core::TensorRank4Component<T>(mpc::data::GraphiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Wusite
template <typename T>
mpc::core::StiffnessTensor<T> WusiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::WusiteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Wusite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::WusiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::WusiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::WusiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Manganosite
template <typename T>
mpc::core::StiffnessTensor<T> ManganositeStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::ManganositeSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Manganosite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::ManganositeC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::ManganositeC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::ManganositeC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Periclase
template <typename T>
mpc::core::StiffnessTensor<T> PericlaseStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::PericlaseSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Periclase in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::PericlaseC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::PericlaseC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::PericlaseC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Magnetite
template <typename T>
mpc::core::StiffnessTensor<T> MagnetiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::MagnetiteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Magnetite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::MagnetiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::MagnetiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::MagnetiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Chromite
template <typename T>
mpc::core::StiffnessTensor<T> ChromiteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::ChromiteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Chromite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::ChromiteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::ChromiteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::ChromiteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Spinel
template <typename T>
mpc::core::StiffnessTensor<T> SpinelStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::SpinelSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Spinel in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::SpinelC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::SpinelC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::SpinelC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Pyrite
template <typename T>
mpc::core::StiffnessTensor<T> PyriteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::PyriteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Pyrite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::PyriteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::PyriteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::PyriteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Galena
template <typename T>
mpc::core::StiffnessTensor<T> GalenaStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::GalenaSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Galena in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::GalenaC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::GalenaC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::GalenaC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Sphalerite
template <typename T>
mpc::core::StiffnessTensor<T> SphaleriteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::SphaleriteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Sphalerite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::SphaleriteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::SphaleriteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::SphaleriteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Fluorite
template <typename T>
mpc::core::StiffnessTensor<T> FluoriteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::FluoriteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Fluorite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::FluoriteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::FluoriteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::FluoriteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Halite
template <typename T>
mpc::core::StiffnessTensor<T> HaliteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::HaliteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Halite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::HaliteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::HaliteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::HaliteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

// Sylvite
template <typename T>
mpc::core::StiffnessTensor<T> SylviteStiffnessTensor() {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // type:=> mpc::core::SYMMETRY::CUBIC
        // TODO: FIX below:non-constexpr function AugiteSymmetryClass() cannot be used in a constant expression
        //static_assert(mpc::SylviteSymmetryClass() == mpc::core::SYMMETRY::CUBIC, "symmetry type mismatch; verify symmetry of Sylvite in mineraldataproperties.h ");
        mpc::core::StiffnessTensor<T> stiffness_tensor = mpc::core::StiffnessTensor<T>();
        // void SetComponents(T c11, T c12, T c44)
        std::set< mpc::core::TensorRank4Component<T> > tmp_set{
                mpc::core::TensorRank4Component<T>(mpc::data::SylviteC11<T>(), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                mpc::core::TensorRank4Component<T>(mpc::data::SylviteC12<T>(), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                mpc::core::TensorRank4Component<T>(mpc::data::SylviteC44<T>(), mpc::core::TensorRank4ComponentIndex(1,2,1,2))
        };
        stiffness_tensor.template SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(tmp_set); // https://stackoverflow.com/questions/3786360/confusing-template-error
        return stiffness_tensor;
}

}  // END namespace data
}  // END namespace mpc

#endif // MINERALDATATENSORSANDMATRICES_H
