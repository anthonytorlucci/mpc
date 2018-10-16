#include "mpcx_tensorinvariants.hpp"

// c++
#include <iostream>
#include <cmath>

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/core/csrelationship.hpp>
#include <mpc/rockphysics/tensorinvariants.hpp>

void mpcexamples::mpcTensorInvariants() {
    /** tensor invariants */
    mpc::utilities::PrintTensorComponents<double,4> print_tensor_components_double_4_fo;

    // mineral properties
    // Augite
    mpc::core::SymmetryGroupEnumeration augite_symmetry_group_enum = mpc::data::AugiteSymmetryClass();
    auto augite_density = mpc::data::AugiteDensity<double>();
//    auto augite_C11 = mpc::data::AugiteC11<double>();
//    auto augite_C12 = mpc::data::AugiteC12<double>();
//    auto augite_C13 = mpc::data::AugiteC13<double>();
//    auto augite_C14 = mpc::data::AugiteC14<double>();
//    auto augite_C15 = mpc::data::AugiteC15<double>();
//    auto augite_C16 = mpc::data::AugiteC16<double>();
//    auto augite_C22 = mpc::data::AugiteC22<double>();
//    auto augite_C23 = mpc::data::AugiteC23<double>();
//    auto augite_C24 = mpc::data::AugiteC24<double>();
//    auto augite_C25 = mpc::data::AugiteC25<double>();
//    auto augite_C26 = mpc::data::AugiteC26<double>();
//    auto augite_C33 = mpc::data::AugiteC33<double>();
//    auto augite_C34 = mpc::data::AugiteC34<double>();
//    auto augite_C35 = mpc::data::AugiteC35<double>();
//    auto augite_C36 = mpc::data::AugiteC36<double>();
//    auto augite_C44 = mpc::data::AugiteC44<double>();
//    auto augite_C45 = mpc::data::AugiteC45<double>();
//    auto augite_C46 = mpc::data::AugiteC46<double>();
//    auto augite_C55 = mpc::data::AugiteC55<double>();
//    auto augite_C56 = mpc::data::AugiteC56<double>();
//    auto augite_C66 = mpc::data::AugiteC66<double>();
    auto augite_bulk_modulus = mpc::data::AugiteBulkModulus<double>();
    auto augite_shear_modulus = mpc::data::AugiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> augite_stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();

    // Albite
    mpc::core::SymmetryGroupEnumeration albite_symmetry_group_enum = mpc::data::AlbiteSymmetryClass();
    auto albite_density = mpc::data::AlbiteDensity<double>();
//    auto albite_C11 = mpc::data::AlbiteC11<double>();
//    auto albite_C12 = mpc::data::AlbiteC12<double>();
//    auto albite_C13 = mpc::data::AlbiteC13<double>();
//    auto albite_C14 = mpc::data::AlbiteC14<double>();
//    auto albite_C15 = mpc::data::AlbiteC15<double>();
//    auto albite_C16 = mpc::data::AlbiteC16<double>();
//    auto albite_C22 = mpc::data::AlbiteC22<double>();
//    auto albite_C23 = mpc::data::AlbiteC23<double>();
//    auto albite_C24 = mpc::data::AlbiteC24<double>();
//    auto albite_C25 = mpc::data::AlbiteC25<double>();
//    auto albite_C26 = mpc::data::AlbiteC26<double>();
//    auto albite_C33 = mpc::data::AlbiteC33<double>();
//    auto albite_C34 = mpc::data::AlbiteC34<double>();
//    auto albite_C35 = mpc::data::AlbiteC35<double>();
//    auto albite_C36 = mpc::data::AlbiteC36<double>();
//    auto albite_C44 = mpc::data::AlbiteC44<double>();
//    auto albite_C45 = mpc::data::AlbiteC45<double>();
//    auto albite_C46 = mpc::data::AlbiteC46<double>();
//    auto albite_C55 = mpc::data::AlbiteC55<double>();
//    auto albite_C56 = mpc::data::AlbiteC56<double>();
//    auto albite_C66 = mpc::data::AlbiteC66<double>();
    auto albite_bulk_modulus = mpc::data::AlbiteBulkModulus<double>();
    auto albite_shear_modulus = mpc::data::AlbiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> albite_stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();

    // Anorthite
    mpc::core::SymmetryGroupEnumeration anorthite_symmetry_group_enum = mpc::data::AnorthiteSymmetryClass();
    auto anorthite_density = mpc::data::AnorthiteDensity<double>();
//    auto anorthite_C11 = mpc::data::AnorthiteC11<double>();
//    auto anorthite_C12 = mpc::data::AnorthiteC12<double>();
//    auto anorthite_C13 = mpc::data::AnorthiteC13<double>();
//    auto anorthite_C14 = mpc::data::AnorthiteC14<double>();
//    auto anorthite_C15 = mpc::data::AnorthiteC15<double>();
//    auto anorthite_C16 = mpc::data::AnorthiteC16<double>();
//    auto anorthite_C22 = mpc::data::AnorthiteC22<double>();
//    auto anorthite_C23 = mpc::data::AnorthiteC23<double>();
//    auto anorthite_C24 = mpc::data::AnorthiteC24<double>();
//    auto anorthite_C25 = mpc::data::AnorthiteC25<double>();
//    auto anorthite_C26 = mpc::data::AnorthiteC26<double>();
//    auto anorthite_C33 = mpc::data::AnorthiteC33<double>();
//    auto anorthite_C34 = mpc::data::AnorthiteC34<double>();
//    auto anorthite_C35 = mpc::data::AnorthiteC35<double>();
//    auto anorthite_C36 = mpc::data::AnorthiteC36<double>();
//    auto anorthite_C44 = mpc::data::AnorthiteC44<double>();
//    auto anorthite_C45 = mpc::data::AnorthiteC45<double>();
//    auto anorthite_C46 = mpc::data::AnorthiteC46<double>();
//    auto anorthite_C55 = mpc::data::AnorthiteC55<double>();
//    auto anorthite_C56 = mpc::data::AnorthiteC56<double>();
//    auto anorthite_C66 = mpc::data::AnorthiteC66<double>();
    auto anorthite_bulk_modulus = mpc::data::AnorthiteBulkModulus<double>();
    auto anorthite_shear_modulus = mpc::data::AnorthiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> anorthite_stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();

    // Labradorite
    mpc::core::SymmetryGroupEnumeration labradorite_symmetry_group_enum = mpc::data::LabradoriteSymmetryClass();
    auto labradorite_density = mpc::data::LabradoriteDensity<double>();
//    auto labradorite_C11 = mpc::data::LabradoriteC11<double>();
//    auto labradorite_C12 = mpc::data::LabradoriteC12<double>();
//    auto labradorite_C13 = mpc::data::LabradoriteC13<double>();
//    auto labradorite_C14 = mpc::data::LabradoriteC14<double>();
//    auto labradorite_C15 = mpc::data::LabradoriteC15<double>();
//    auto labradorite_C16 = mpc::data::LabradoriteC16<double>();
//    auto labradorite_C22 = mpc::data::LabradoriteC22<double>();
//    auto labradorite_C23 = mpc::data::LabradoriteC23<double>();
//    auto labradorite_C24 = mpc::data::LabradoriteC24<double>();
//    auto labradorite_C25 = mpc::data::LabradoriteC25<double>();
//    auto labradorite_C26 = mpc::data::LabradoriteC26<double>();
//    auto labradorite_C33 = mpc::data::LabradoriteC33<double>();
//    auto labradorite_C34 = mpc::data::LabradoriteC34<double>();
//    auto labradorite_C35 = mpc::data::LabradoriteC35<double>();
//    auto labradorite_C36 = mpc::data::LabradoriteC36<double>();
//    auto labradorite_C44 = mpc::data::LabradoriteC44<double>();
//    auto labradorite_C45 = mpc::data::LabradoriteC45<double>();
//    auto labradorite_C46 = mpc::data::LabradoriteC46<double>();
//    auto labradorite_C55 = mpc::data::LabradoriteC55<double>();
//    auto labradorite_C56 = mpc::data::LabradoriteC56<double>();
//    auto labradorite_C66 = mpc::data::LabradoriteC66<double>();
    auto labradorite_bulk_modulus = mpc::data::LabradoriteBulkModulus<double>();
    auto labradorite_shear_modulus = mpc::data::LabradoriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> labradorite_stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();

    // Microcline
    mpc::core::SymmetryGroupEnumeration microcline_symmetry_group_enum = mpc::data::MicroclineSymmetryClass();
    auto microcline_density = mpc::data::MicroclineDensity<double>();
//    auto microcline_C11 = mpc::data::MicroclineC11<double>();
//    auto microcline_C12 = mpc::data::MicroclineC12<double>();
//    auto microcline_C13 = mpc::data::MicroclineC13<double>();
//    auto microcline_C14 = mpc::data::MicroclineC14<double>();
//    auto microcline_C15 = mpc::data::MicroclineC15<double>();
//    auto microcline_C16 = mpc::data::MicroclineC16<double>();
//    auto microcline_C22 = mpc::data::MicroclineC22<double>();
//    auto microcline_C23 = mpc::data::MicroclineC23<double>();
//    auto microcline_C24 = mpc::data::MicroclineC24<double>();
//    auto microcline_C25 = mpc::data::MicroclineC25<double>();
//    auto microcline_C26 = mpc::data::MicroclineC26<double>();
//    auto microcline_C33 = mpc::data::MicroclineC33<double>();
//    auto microcline_C34 = mpc::data::MicroclineC34<double>();
//    auto microcline_C35 = mpc::data::MicroclineC35<double>();
//    auto microcline_C36 = mpc::data::MicroclineC36<double>();
//    auto microcline_C44 = mpc::data::MicroclineC44<double>();
//    auto microcline_C45 = mpc::data::MicroclineC45<double>();
//    auto microcline_C46 = mpc::data::MicroclineC46<double>();
//    auto microcline_C55 = mpc::data::MicroclineC55<double>();
//    auto microcline_C56 = mpc::data::MicroclineC56<double>();
//    auto microcline_C66 = mpc::data::MicroclineC66<double>();
    auto microcline_bulk_modulus = mpc::data::MicroclineBulkModulus<double>();
    auto microcline_shear_modulus = mpc::data::MicroclineShearModulus<double>();
    mpc::core::StiffnessTensor<double> microcline_stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();

    // Oligoclase
    mpc::core::SymmetryGroupEnumeration oligoclase_symmetry_group_enum = mpc::data::OligoclaseSymmetryClass();
    auto oligoclase_density = mpc::data::OligoclaseDensity<double>();
//    auto oligoclase_C11 = mpc::data::OligoclaseC11<double>();
//    auto oligoclase_C12 = mpc::data::OligoclaseC12<double>();
//    auto oligoclase_C13 = mpc::data::OligoclaseC13<double>();
//    auto oligoclase_C14 = mpc::data::OligoclaseC14<double>();
//    auto oligoclase_C15 = mpc::data::OligoclaseC15<double>();
//    auto oligoclase_C16 = mpc::data::OligoclaseC16<double>();
//    auto oligoclase_C22 = mpc::data::OligoclaseC22<double>();
//    auto oligoclase_C23 = mpc::data::OligoclaseC23<double>();
//    auto oligoclase_C24 = mpc::data::OligoclaseC24<double>();
//    auto oligoclase_C25 = mpc::data::OligoclaseC25<double>();
//    auto oligoclase_C26 = mpc::data::OligoclaseC26<double>();
//    auto oligoclase_C33 = mpc::data::OligoclaseC33<double>();
//    auto oligoclase_C34 = mpc::data::OligoclaseC34<double>();
//    auto oligoclase_C35 = mpc::data::OligoclaseC35<double>();
//    auto oligoclase_C36 = mpc::data::OligoclaseC36<double>();
//    auto oligoclase_C44 = mpc::data::OligoclaseC44<double>();
//    auto oligoclase_C45 = mpc::data::OligoclaseC45<double>();
//    auto oligoclase_C46 = mpc::data::OligoclaseC46<double>();
//    auto oligoclase_C55 = mpc::data::OligoclaseC55<double>();
//    auto oligoclase_C56 = mpc::data::OligoclaseC56<double>();
//    auto oligoclase_C66 = mpc::data::OligoclaseC66<double>();
    auto oligoclase_bulk_modulus = mpc::data::OligoclaseBulkModulus<double>();
    auto oligoclase_shear_modulus = mpc::data::OligoclaseShearModulus<double>();
    mpc::core::StiffnessTensor<double> oligoclase_stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();

    // Coesite
    mpc::core::SymmetryGroupEnumeration coesite_symmetry_group_enum = mpc::data::CoesiteSymmetryClass();
    auto coesite_density = mpc::data::CoesiteDensity<double>();
//    auto coesite_C11 = mpc::data::CoesiteC11<double>();
//    auto coesite_C12 = mpc::data::CoesiteC12<double>();
//    auto coesite_C13 = mpc::data::CoesiteC13<double>();
//    auto coesite_C14 = mpc::data::CoesiteC14<double>();
//    auto coesite_C15 = mpc::data::CoesiteC15<double>();
//    auto coesite_C16 = mpc::data::CoesiteC16<double>();
//    auto coesite_C22 = mpc::data::CoesiteC22<double>();
//    auto coesite_C23 = mpc::data::CoesiteC23<double>();
//    auto coesite_C24 = mpc::data::CoesiteC24<double>();
//    auto coesite_C25 = mpc::data::CoesiteC25<double>();
//    auto coesite_C26 = mpc::data::CoesiteC26<double>();
//    auto coesite_C33 = mpc::data::CoesiteC33<double>();
//    auto coesite_C34 = mpc::data::CoesiteC34<double>();
//    auto coesite_C35 = mpc::data::CoesiteC35<double>();
//    auto coesite_C36 = mpc::data::CoesiteC36<double>();
//    auto coesite_C44 = mpc::data::CoesiteC44<double>();
//    auto coesite_C45 = mpc::data::CoesiteC45<double>();
//    auto coesite_C46 = mpc::data::CoesiteC46<double>();
//    auto coesite_C55 = mpc::data::CoesiteC55<double>();
//    auto coesite_C56 = mpc::data::CoesiteC56<double>();
//    auto coesite_C66 = mpc::data::CoesiteC66<double>();
    auto coesite_bulk_modulus = mpc::data::CoesiteBulkModulus<double>();
    auto coesite_shear_modulus = mpc::data::CoesiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> coesite_stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();

    // Epidote
    mpc::core::SymmetryGroupEnumeration epidote_symmetry_group_enum = mpc::data::EpidoteSymmetryClass();
    auto epidote_density = mpc::data::EpidoteDensity<double>();
//    auto epidote_C11 = mpc::data::EpidoteC11<double>();
//    auto epidote_C12 = mpc::data::EpidoteC12<double>();
//    auto epidote_C13 = mpc::data::EpidoteC13<double>();
//    auto epidote_C14 = mpc::data::EpidoteC14<double>();
//    auto epidote_C15 = mpc::data::EpidoteC15<double>();
//    auto epidote_C16 = mpc::data::EpidoteC16<double>();
//    auto epidote_C22 = mpc::data::EpidoteC22<double>();
//    auto epidote_C23 = mpc::data::EpidoteC23<double>();
//    auto epidote_C24 = mpc::data::EpidoteC24<double>();
//    auto epidote_C25 = mpc::data::EpidoteC25<double>();
//    auto epidote_C26 = mpc::data::EpidoteC26<double>();
//    auto epidote_C33 = mpc::data::EpidoteC33<double>();
//    auto epidote_C34 = mpc::data::EpidoteC34<double>();
//    auto epidote_C35 = mpc::data::EpidoteC35<double>();
//    auto epidote_C36 = mpc::data::EpidoteC36<double>();
//    auto epidote_C44 = mpc::data::EpidoteC44<double>();
//    auto epidote_C45 = mpc::data::EpidoteC45<double>();
//    auto epidote_C46 = mpc::data::EpidoteC46<double>();
//    auto epidote_C55 = mpc::data::EpidoteC55<double>();
//    auto epidote_C56 = mpc::data::EpidoteC56<double>();
//    auto epidote_C66 = mpc::data::EpidoteC66<double>();
    auto epidote_bulk_modulus = mpc::data::EpidoteBulkModulus<double>();
    auto epidote_shear_modulus = mpc::data::EpidoteShearModulus<double>();
    mpc::core::StiffnessTensor<double> epidote_stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();

    // Hornblende
    mpc::core::SymmetryGroupEnumeration hornblende_symmetry_group_enum = mpc::data::HornblendeSymmetryClass();
    auto hornblende_density = mpc::data::HornblendeDensity<double>();
//    auto hornblende_C11 = mpc::data::HornblendeC11<double>();
//    auto hornblende_C12 = mpc::data::HornblendeC12<double>();
//    auto hornblende_C13 = mpc::data::HornblendeC13<double>();
//    auto hornblende_C14 = mpc::data::HornblendeC14<double>();
//    auto hornblende_C15 = mpc::data::HornblendeC15<double>();
//    auto hornblende_C16 = mpc::data::HornblendeC16<double>();
//    auto hornblende_C22 = mpc::data::HornblendeC22<double>();
//    auto hornblende_C23 = mpc::data::HornblendeC23<double>();
//    auto hornblende_C24 = mpc::data::HornblendeC24<double>();
//    auto hornblende_C25 = mpc::data::HornblendeC25<double>();
//    auto hornblende_C26 = mpc::data::HornblendeC26<double>();
//    auto hornblende_C33 = mpc::data::HornblendeC33<double>();
//    auto hornblende_C34 = mpc::data::HornblendeC34<double>();
//    auto hornblende_C35 = mpc::data::HornblendeC35<double>();
//    auto hornblende_C36 = mpc::data::HornblendeC36<double>();
//    auto hornblende_C44 = mpc::data::HornblendeC44<double>();
//    auto hornblende_C45 = mpc::data::HornblendeC45<double>();
//    auto hornblende_C46 = mpc::data::HornblendeC46<double>();
//    auto hornblende_C55 = mpc::data::HornblendeC55<double>();
//    auto hornblende_C56 = mpc::data::HornblendeC56<double>();
//    auto hornblende_C66 = mpc::data::HornblendeC66<double>();
    auto hornblende_bulk_modulus = mpc::data::HornblendeBulkModulus<double>();
    auto hornblende_shear_modulus = mpc::data::HornblendeShearModulus<double>();
    mpc::core::StiffnessTensor<double> hornblende_stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();

    // Muscovite
    mpc::core::SymmetryGroupEnumeration muscovite_symmetry_group_enum = mpc::data::MuscoviteSymmetryClass();
    auto muscovite_density = mpc::data::MuscoviteDensity<double>();
//    auto muscovite_C11 = mpc::data::MuscoviteC11<double>();
//    auto muscovite_C12 = mpc::data::MuscoviteC12<double>();
//    auto muscovite_C13 = mpc::data::MuscoviteC13<double>();
//    auto muscovite_C14 = mpc::data::MuscoviteC14<double>();
//    auto muscovite_C15 = mpc::data::MuscoviteC15<double>();
//    auto muscovite_C16 = mpc::data::MuscoviteC16<double>();
//    auto muscovite_C22 = mpc::data::MuscoviteC22<double>();
//    auto muscovite_C23 = mpc::data::MuscoviteC23<double>();
//    auto muscovite_C24 = mpc::data::MuscoviteC24<double>();
//    auto muscovite_C25 = mpc::data::MuscoviteC25<double>();
//    auto muscovite_C26 = mpc::data::MuscoviteC26<double>();
//    auto muscovite_C33 = mpc::data::MuscoviteC33<double>();
//    auto muscovite_C34 = mpc::data::MuscoviteC34<double>();
//    auto muscovite_C35 = mpc::data::MuscoviteC35<double>();
//    auto muscovite_C36 = mpc::data::MuscoviteC36<double>();
//    auto muscovite_C44 = mpc::data::MuscoviteC44<double>();
//    auto muscovite_C45 = mpc::data::MuscoviteC45<double>();
//    auto muscovite_C46 = mpc::data::MuscoviteC46<double>();
//    auto muscovite_C55 = mpc::data::MuscoviteC55<double>();
//    auto muscovite_C56 = mpc::data::MuscoviteC56<double>();
//    auto muscovite_C66 = mpc::data::MuscoviteC66<double>();
    auto muscovite_bulk_modulus = mpc::data::MuscoviteBulkModulus<double>();
    auto muscovite_shear_modulus = mpc::data::MuscoviteShearModulus<double>();
    mpc::core::StiffnessTensor<double> muscovite_stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();

    // Gypsum
    mpc::core::SymmetryGroupEnumeration gypsum_symmetry_group_enum = mpc::data::GypsumSymmetryClass();
    auto gypsum_density = mpc::data::GypsumDensity<double>();
//    auto gypsum_C11 = mpc::data::GypsumC11<double>();
//    auto gypsum_C12 = mpc::data::GypsumC12<double>();
//    auto gypsum_C13 = mpc::data::GypsumC13<double>();
//    auto gypsum_C14 = mpc::data::GypsumC14<double>();
//    auto gypsum_C15 = mpc::data::GypsumC15<double>();
//    auto gypsum_C16 = mpc::data::GypsumC16<double>();
//    auto gypsum_C22 = mpc::data::GypsumC22<double>();
//    auto gypsum_C23 = mpc::data::GypsumC23<double>();
//    auto gypsum_C24 = mpc::data::GypsumC24<double>();
//    auto gypsum_C25 = mpc::data::GypsumC25<double>();
//    auto gypsum_C26 = mpc::data::GypsumC26<double>();
//    auto gypsum_C33 = mpc::data::GypsumC33<double>();
//    auto gypsum_C34 = mpc::data::GypsumC34<double>();
//    auto gypsum_C35 = mpc::data::GypsumC35<double>();
//    auto gypsum_C36 = mpc::data::GypsumC36<double>();
//    auto gypsum_C44 = mpc::data::GypsumC44<double>();
//    auto gypsum_C45 = mpc::data::GypsumC45<double>();
//    auto gypsum_C46 = mpc::data::GypsumC46<double>();
//    auto gypsum_C55 = mpc::data::GypsumC55<double>();
//    auto gypsum_C56 = mpc::data::GypsumC56<double>();
//    auto gypsum_C66 = mpc::data::GypsumC66<double>();
    auto gypsum_bulk_modulus = mpc::data::GypsumBulkModulus<double>();
    auto gypsum_shear_modulus = mpc::data::GypsumShearModulus<double>();
    mpc::core::StiffnessTensor<double> gypsum_stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();

    // Enstatite
    mpc::core::SymmetryGroupEnumeration enstatite_symmetry_group_enum = mpc::data::EnstatiteSymmetryClass();
    auto enstatite_density = mpc::data::EnstatiteDensity<double>();
//    auto enstatite_C11 = mpc::data::EnstatiteC11<double>();
//    auto enstatite_C12 = mpc::data::EnstatiteC12<double>();
//    auto enstatite_C13 = mpc::data::EnstatiteC13<double>();
//    auto enstatite_C14 = mpc::data::EnstatiteC14<double>();
//    auto enstatite_C15 = mpc::data::EnstatiteC15<double>();
//    auto enstatite_C16 = mpc::data::EnstatiteC16<double>();
//    auto enstatite_C22 = mpc::data::EnstatiteC22<double>();
//    auto enstatite_C23 = mpc::data::EnstatiteC23<double>();
//    auto enstatite_C24 = mpc::data::EnstatiteC24<double>();
//    auto enstatite_C25 = mpc::data::EnstatiteC25<double>();
//    auto enstatite_C26 = mpc::data::EnstatiteC26<double>();
//    auto enstatite_C33 = mpc::data::EnstatiteC33<double>();
//    auto enstatite_C34 = mpc::data::EnstatiteC34<double>();
//    auto enstatite_C35 = mpc::data::EnstatiteC35<double>();
//    auto enstatite_C36 = mpc::data::EnstatiteC36<double>();
//    auto enstatite_C44 = mpc::data::EnstatiteC44<double>();
//    auto enstatite_C45 = mpc::data::EnstatiteC45<double>();
//    auto enstatite_C46 = mpc::data::EnstatiteC46<double>();
//    auto enstatite_C55 = mpc::data::EnstatiteC55<double>();
//    auto enstatite_C56 = mpc::data::EnstatiteC56<double>();
//    auto enstatite_C66 = mpc::data::EnstatiteC66<double>();
    auto enstatite_bulk_modulus = mpc::data::EnstatiteBulkModulus<double>();
    auto enstatite_shear_modulus = mpc::data::EnstatiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> enstatite_stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();

    // Forsterite
    mpc::core::SymmetryGroupEnumeration forsterite_symmetry_group_enum = mpc::data::ForsteriteSymmetryClass();
    auto forsterite_density = mpc::data::ForsteriteDensity<double>();
//    auto forsterite_C11 = mpc::data::ForsteriteC11<double>();
//    auto forsterite_C12 = mpc::data::ForsteriteC12<double>();
//    auto forsterite_C13 = mpc::data::ForsteriteC13<double>();
//    auto forsterite_C14 = mpc::data::ForsteriteC14<double>();
//    auto forsterite_C15 = mpc::data::ForsteriteC15<double>();
//    auto forsterite_C16 = mpc::data::ForsteriteC16<double>();
//    auto forsterite_C22 = mpc::data::ForsteriteC22<double>();
//    auto forsterite_C23 = mpc::data::ForsteriteC23<double>();
//    auto forsterite_C24 = mpc::data::ForsteriteC24<double>();
//    auto forsterite_C25 = mpc::data::ForsteriteC25<double>();
//    auto forsterite_C26 = mpc::data::ForsteriteC26<double>();
//    auto forsterite_C33 = mpc::data::ForsteriteC33<double>();
//    auto forsterite_C34 = mpc::data::ForsteriteC34<double>();
//    auto forsterite_C35 = mpc::data::ForsteriteC35<double>();
//    auto forsterite_C36 = mpc::data::ForsteriteC36<double>();
//    auto forsterite_C44 = mpc::data::ForsteriteC44<double>();
//    auto forsterite_C45 = mpc::data::ForsteriteC45<double>();
//    auto forsterite_C46 = mpc::data::ForsteriteC46<double>();
//    auto forsterite_C55 = mpc::data::ForsteriteC55<double>();
//    auto forsterite_C56 = mpc::data::ForsteriteC56<double>();
//    auto forsterite_C66 = mpc::data::ForsteriteC66<double>();
    auto forsterite_bulk_modulus = mpc::data::ForsteriteBulkModulus<double>();
    auto forsterite_shear_modulus = mpc::data::ForsteriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> forsterite_stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();

    // Fayalite
    mpc::core::SymmetryGroupEnumeration fayalite_symmetry_group_enum = mpc::data::FayaliteSymmetryClass();
    auto fayalite_density = mpc::data::FayaliteDensity<double>();
//    auto fayalite_C11 = mpc::data::FayaliteC11<double>();
//    auto fayalite_C12 = mpc::data::FayaliteC12<double>();
//    auto fayalite_C13 = mpc::data::FayaliteC13<double>();
//    auto fayalite_C14 = mpc::data::FayaliteC14<double>();
//    auto fayalite_C15 = mpc::data::FayaliteC15<double>();
//    auto fayalite_C16 = mpc::data::FayaliteC16<double>();
//    auto fayalite_C22 = mpc::data::FayaliteC22<double>();
//    auto fayalite_C23 = mpc::data::FayaliteC23<double>();
//    auto fayalite_C24 = mpc::data::FayaliteC24<double>();
//    auto fayalite_C25 = mpc::data::FayaliteC25<double>();
//    auto fayalite_C26 = mpc::data::FayaliteC26<double>();
//    auto fayalite_C33 = mpc::data::FayaliteC33<double>();
//    auto fayalite_C34 = mpc::data::FayaliteC34<double>();
//    auto fayalite_C35 = mpc::data::FayaliteC35<double>();
//    auto fayalite_C36 = mpc::data::FayaliteC36<double>();
//    auto fayalite_C44 = mpc::data::FayaliteC44<double>();
//    auto fayalite_C45 = mpc::data::FayaliteC45<double>();
//    auto fayalite_C46 = mpc::data::FayaliteC46<double>();
//    auto fayalite_C55 = mpc::data::FayaliteC55<double>();
//    auto fayalite_C56 = mpc::data::FayaliteC56<double>();
//    auto fayalite_C66 = mpc::data::FayaliteC66<double>();
    auto fayalite_bulk_modulus = mpc::data::FayaliteBulkModulus<double>();
    auto fayalite_shear_modulus = mpc::data::FayaliteShearModulus<double>();
    mpc::core::StiffnessTensor<double> fayalite_stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();

    // Montecellite
    mpc::core::SymmetryGroupEnumeration montecellite_symmetry_group_enum = mpc::data::MontecelliteSymmetryClass();
    auto montecellite_density = mpc::data::MontecelliteDensity<double>();
//    auto montecellite_C11 = mpc::data::MontecelliteC11<double>();
//    auto montecellite_C12 = mpc::data::MontecelliteC12<double>();
//    auto montecellite_C13 = mpc::data::MontecelliteC13<double>();
//    auto montecellite_C14 = mpc::data::MontecelliteC14<double>();
//    auto montecellite_C15 = mpc::data::MontecelliteC15<double>();
//    auto montecellite_C16 = mpc::data::MontecelliteC16<double>();
//    auto montecellite_C22 = mpc::data::MontecelliteC22<double>();
//    auto montecellite_C23 = mpc::data::MontecelliteC23<double>();
//    auto montecellite_C24 = mpc::data::MontecelliteC24<double>();
//    auto montecellite_C25 = mpc::data::MontecelliteC25<double>();
//    auto montecellite_C26 = mpc::data::MontecelliteC26<double>();
//    auto montecellite_C33 = mpc::data::MontecelliteC33<double>();
//    auto montecellite_C34 = mpc::data::MontecelliteC34<double>();
//    auto montecellite_C35 = mpc::data::MontecelliteC35<double>();
//    auto montecellite_C36 = mpc::data::MontecelliteC36<double>();
//    auto montecellite_C44 = mpc::data::MontecelliteC44<double>();
//    auto montecellite_C45 = mpc::data::MontecelliteC45<double>();
//    auto montecellite_C46 = mpc::data::MontecelliteC46<double>();
//    auto montecellite_C55 = mpc::data::MontecelliteC55<double>();
//    auto montecellite_C56 = mpc::data::MontecelliteC56<double>();
//    auto montecellite_C66 = mpc::data::MontecelliteC66<double>();
    auto montecellite_bulk_modulus = mpc::data::MontecelliteBulkModulus<double>();
    auto montecellite_shear_modulus = mpc::data::MontecelliteShearModulus<double>();
    mpc::core::StiffnessTensor<double> montecellite_stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();

    // Andalusite
    mpc::core::SymmetryGroupEnumeration andalusite_symmetry_group_enum = mpc::data::AndalusiteSymmetryClass();
    auto andalusite_density = mpc::data::AndalusiteDensity<double>();
//    auto andalusite_C11 = mpc::data::AndalusiteC11<double>();
//    auto andalusite_C12 = mpc::data::AndalusiteC12<double>();
//    auto andalusite_C13 = mpc::data::AndalusiteC13<double>();
//    auto andalusite_C14 = mpc::data::AndalusiteC14<double>();
//    auto andalusite_C15 = mpc::data::AndalusiteC15<double>();
//    auto andalusite_C16 = mpc::data::AndalusiteC16<double>();
//    auto andalusite_C22 = mpc::data::AndalusiteC22<double>();
//    auto andalusite_C23 = mpc::data::AndalusiteC23<double>();
//    auto andalusite_C24 = mpc::data::AndalusiteC24<double>();
//    auto andalusite_C25 = mpc::data::AndalusiteC25<double>();
//    auto andalusite_C26 = mpc::data::AndalusiteC26<double>();
//    auto andalusite_C33 = mpc::data::AndalusiteC33<double>();
//    auto andalusite_C34 = mpc::data::AndalusiteC34<double>();
//    auto andalusite_C35 = mpc::data::AndalusiteC35<double>();
//    auto andalusite_C36 = mpc::data::AndalusiteC36<double>();
//    auto andalusite_C44 = mpc::data::AndalusiteC44<double>();
//    auto andalusite_C45 = mpc::data::AndalusiteC45<double>();
//    auto andalusite_C46 = mpc::data::AndalusiteC46<double>();
//    auto andalusite_C55 = mpc::data::AndalusiteC55<double>();
//    auto andalusite_C56 = mpc::data::AndalusiteC56<double>();
//    auto andalusite_C66 = mpc::data::AndalusiteC66<double>();
    auto andalusite_bulk_modulus = mpc::data::AndalusiteBulkModulus<double>();
    auto andalusite_shear_modulus = mpc::data::AndalusiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> andalusite_stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();

    // Silimanite
    mpc::core::SymmetryGroupEnumeration silimanite_symmetry_group_enum = mpc::data::SilimaniteSymmetryClass();
    auto silimanite_density = mpc::data::SilimaniteDensity<double>();
//    auto silimanite_C11 = mpc::data::SilimaniteC11<double>();
//    auto silimanite_C12 = mpc::data::SilimaniteC12<double>();
//    auto silimanite_C13 = mpc::data::SilimaniteC13<double>();
//    auto silimanite_C14 = mpc::data::SilimaniteC14<double>();
//    auto silimanite_C15 = mpc::data::SilimaniteC15<double>();
//    auto silimanite_C16 = mpc::data::SilimaniteC16<double>();
//    auto silimanite_C22 = mpc::data::SilimaniteC22<double>();
//    auto silimanite_C23 = mpc::data::SilimaniteC23<double>();
//    auto silimanite_C24 = mpc::data::SilimaniteC24<double>();
//    auto silimanite_C25 = mpc::data::SilimaniteC25<double>();
//    auto silimanite_C26 = mpc::data::SilimaniteC26<double>();
//    auto silimanite_C33 = mpc::data::SilimaniteC33<double>();
//    auto silimanite_C34 = mpc::data::SilimaniteC34<double>();
//    auto silimanite_C35 = mpc::data::SilimaniteC35<double>();
//    auto silimanite_C36 = mpc::data::SilimaniteC36<double>();
//    auto silimanite_C44 = mpc::data::SilimaniteC44<double>();
//    auto silimanite_C45 = mpc::data::SilimaniteC45<double>();
//    auto silimanite_C46 = mpc::data::SilimaniteC46<double>();
//    auto silimanite_C55 = mpc::data::SilimaniteC55<double>();
//    auto silimanite_C56 = mpc::data::SilimaniteC56<double>();
//    auto silimanite_C66 = mpc::data::SilimaniteC66<double>();
    auto silimanite_bulk_modulus = mpc::data::SilimaniteBulkModulus<double>();
    auto silimanite_shear_modulus = mpc::data::SilimaniteShearModulus<double>();
    mpc::core::StiffnessTensor<double> silimanite_stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();

    // Barite
    mpc::core::SymmetryGroupEnumeration barite_symmetry_group_enum = mpc::data::BariteSymmetryClass();
    auto barite_density = mpc::data::BariteDensity<double>();
//    auto barite_C11 = mpc::data::BariteC11<double>();
//    auto barite_C12 = mpc::data::BariteC12<double>();
//    auto barite_C13 = mpc::data::BariteC13<double>();
//    auto barite_C14 = mpc::data::BariteC14<double>();
//    auto barite_C15 = mpc::data::BariteC15<double>();
//    auto barite_C16 = mpc::data::BariteC16<double>();
//    auto barite_C22 = mpc::data::BariteC22<double>();
//    auto barite_C23 = mpc::data::BariteC23<double>();
//    auto barite_C24 = mpc::data::BariteC24<double>();
//    auto barite_C25 = mpc::data::BariteC25<double>();
//    auto barite_C26 = mpc::data::BariteC26<double>();
//    auto barite_C33 = mpc::data::BariteC33<double>();
//    auto barite_C34 = mpc::data::BariteC34<double>();
//    auto barite_C35 = mpc::data::BariteC35<double>();
//    auto barite_C36 = mpc::data::BariteC36<double>();
//    auto barite_C44 = mpc::data::BariteC44<double>();
//    auto barite_C45 = mpc::data::BariteC45<double>();
//    auto barite_C46 = mpc::data::BariteC46<double>();
//    auto barite_C55 = mpc::data::BariteC55<double>();
//    auto barite_C56 = mpc::data::BariteC56<double>();
//    auto barite_C66 = mpc::data::BariteC66<double>();
    auto barite_bulk_modulus = mpc::data::BariteBulkModulus<double>();
    auto barite_shear_modulus = mpc::data::BariteShearModulus<double>();
    mpc::core::StiffnessTensor<double> barite_stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();

    // Anhydrite
    mpc::core::SymmetryGroupEnumeration anhydrite_symmetry_group_enum = mpc::data::AnhydriteSymmetryClass();
    auto anhydrite_density = mpc::data::AnhydriteDensity<double>();
//    auto anhydrite_C11 = mpc::data::AnhydriteC11<double>();
//    auto anhydrite_C12 = mpc::data::AnhydriteC12<double>();
//    auto anhydrite_C13 = mpc::data::AnhydriteC13<double>();
//    auto anhydrite_C14 = mpc::data::AnhydriteC14<double>();
//    auto anhydrite_C15 = mpc::data::AnhydriteC15<double>();
//    auto anhydrite_C16 = mpc::data::AnhydriteC16<double>();
//    auto anhydrite_C22 = mpc::data::AnhydriteC22<double>();
//    auto anhydrite_C23 = mpc::data::AnhydriteC23<double>();
//    auto anhydrite_C24 = mpc::data::AnhydriteC24<double>();
//    auto anhydrite_C25 = mpc::data::AnhydriteC25<double>();
//    auto anhydrite_C26 = mpc::data::AnhydriteC26<double>();
//    auto anhydrite_C33 = mpc::data::AnhydriteC33<double>();
//    auto anhydrite_C34 = mpc::data::AnhydriteC34<double>();
//    auto anhydrite_C35 = mpc::data::AnhydriteC35<double>();
//    auto anhydrite_C36 = mpc::data::AnhydriteC36<double>();
//    auto anhydrite_C44 = mpc::data::AnhydriteC44<double>();
//    auto anhydrite_C45 = mpc::data::AnhydriteC45<double>();
//    auto anhydrite_C46 = mpc::data::AnhydriteC46<double>();
//    auto anhydrite_C55 = mpc::data::AnhydriteC55<double>();
//    auto anhydrite_C56 = mpc::data::AnhydriteC56<double>();
//    auto anhydrite_C66 = mpc::data::AnhydriteC66<double>();
    auto anhydrite_bulk_modulus = mpc::data::AnhydriteBulkModulus<double>();
    auto anhydrite_shear_modulus = mpc::data::AnhydriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> anhydrite_stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();

    // Dolomite
    mpc::core::SymmetryGroupEnumeration dolomite_symmetry_group_enum = mpc::data::DolomiteSymmetryClass();
    auto dolomite_density = mpc::data::DolomiteDensity<double>();
//    auto dolomite_C11 = mpc::data::DolomiteC11<double>();
//    auto dolomite_C12 = mpc::data::DolomiteC12<double>();
//    auto dolomite_C13 = mpc::data::DolomiteC13<double>();
//    auto dolomite_C14 = mpc::data::DolomiteC14<double>();
//    auto dolomite_C15 = mpc::data::DolomiteC15<double>();
//    auto dolomite_C16 = mpc::data::DolomiteC16<double>();
//    auto dolomite_C22 = mpc::data::DolomiteC22<double>();
//    auto dolomite_C23 = mpc::data::DolomiteC23<double>();
//    auto dolomite_C24 = mpc::data::DolomiteC24<double>();
//    auto dolomite_C25 = mpc::data::DolomiteC25<double>();
//    auto dolomite_C26 = mpc::data::DolomiteC26<double>();
//    auto dolomite_C33 = mpc::data::DolomiteC33<double>();
//    auto dolomite_C34 = mpc::data::DolomiteC34<double>();
//    auto dolomite_C35 = mpc::data::DolomiteC35<double>();
//    auto dolomite_C36 = mpc::data::DolomiteC36<double>();
//    auto dolomite_C44 = mpc::data::DolomiteC44<double>();
//    auto dolomite_C45 = mpc::data::DolomiteC45<double>();
//    auto dolomite_C46 = mpc::data::DolomiteC46<double>();
//    auto dolomite_C55 = mpc::data::DolomiteC55<double>();
//    auto dolomite_C56 = mpc::data::DolomiteC56<double>();
//    auto dolomite_C66 = mpc::data::DolomiteC66<double>();
    auto dolomite_bulk_modulus = mpc::data::DolomiteBulkModulus<double>();
    auto dolomite_shear_modulus = mpc::data::DolomiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> dolomite_stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();

    // Rutile
    mpc::core::SymmetryGroupEnumeration rutile_symmetry_group_enum = mpc::data::RutileSymmetryClass();
    auto rutile_density = mpc::data::RutileDensity<double>();
//    auto rutile_C11 = mpc::data::RutileC11<double>();
//    auto rutile_C12 = mpc::data::RutileC12<double>();
//    auto rutile_C13 = mpc::data::RutileC13<double>();
//    auto rutile_C14 = mpc::data::RutileC14<double>();
//    auto rutile_C15 = mpc::data::RutileC15<double>();
//    auto rutile_C16 = mpc::data::RutileC16<double>();
//    auto rutile_C22 = mpc::data::RutileC22<double>();
//    auto rutile_C23 = mpc::data::RutileC23<double>();
//    auto rutile_C24 = mpc::data::RutileC24<double>();
//    auto rutile_C25 = mpc::data::RutileC25<double>();
//    auto rutile_C26 = mpc::data::RutileC26<double>();
//    auto rutile_C33 = mpc::data::RutileC33<double>();
//    auto rutile_C34 = mpc::data::RutileC34<double>();
//    auto rutile_C35 = mpc::data::RutileC35<double>();
//    auto rutile_C36 = mpc::data::RutileC36<double>();
//    auto rutile_C44 = mpc::data::RutileC44<double>();
//    auto rutile_C45 = mpc::data::RutileC45<double>();
//    auto rutile_C46 = mpc::data::RutileC46<double>();
//    auto rutile_C55 = mpc::data::RutileC55<double>();
//    auto rutile_C56 = mpc::data::RutileC56<double>();
//    auto rutile_C66 = mpc::data::RutileC66<double>();
    auto rutile_bulk_modulus = mpc::data::RutileBulkModulus<double>();
    auto rutile_shear_modulus = mpc::data::RutileShearModulus<double>();
    mpc::core::StiffnessTensor<double> rutile_stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();

    // Zircon
    mpc::core::SymmetryGroupEnumeration zircon_symmetry_group_enum = mpc::data::ZirconSymmetryClass();
    auto zircon_density = mpc::data::ZirconDensity<double>();
//    auto zircon_C11 = mpc::data::ZirconC11<double>();
//    auto zircon_C12 = mpc::data::ZirconC12<double>();
//    auto zircon_C13 = mpc::data::ZirconC13<double>();
//    auto zircon_C14 = mpc::data::ZirconC14<double>();
//    auto zircon_C15 = mpc::data::ZirconC15<double>();
//    auto zircon_C16 = mpc::data::ZirconC16<double>();
//    auto zircon_C22 = mpc::data::ZirconC22<double>();
//    auto zircon_C23 = mpc::data::ZirconC23<double>();
//    auto zircon_C24 = mpc::data::ZirconC24<double>();
//    auto zircon_C25 = mpc::data::ZirconC25<double>();
//    auto zircon_C26 = mpc::data::ZirconC26<double>();
//    auto zircon_C33 = mpc::data::ZirconC33<double>();
//    auto zircon_C34 = mpc::data::ZirconC34<double>();
//    auto zircon_C35 = mpc::data::ZirconC35<double>();
//    auto zircon_C36 = mpc::data::ZirconC36<double>();
//    auto zircon_C44 = mpc::data::ZirconC44<double>();
//    auto zircon_C45 = mpc::data::ZirconC45<double>();
//    auto zircon_C46 = mpc::data::ZirconC46<double>();
//    auto zircon_C55 = mpc::data::ZirconC55<double>();
//    auto zircon_C56 = mpc::data::ZirconC56<double>();
//    auto zircon_C66 = mpc::data::ZirconC66<double>();
    auto zircon_bulk_modulus = mpc::data::ZirconBulkModulus<double>();
    auto zircon_shear_modulus = mpc::data::ZirconShearModulus<double>();
    mpc::core::StiffnessTensor<double> zircon_stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();

    // Corundum
    mpc::core::SymmetryGroupEnumeration corundum_symmetry_group_enum = mpc::data::CorundumSymmetryClass();
    auto corundum_density = mpc::data::CorundumDensity<double>();
//    auto corundum_C11 = mpc::data::CorundumC11<double>();
//    auto corundum_C12 = mpc::data::CorundumC12<double>();
//    auto corundum_C13 = mpc::data::CorundumC13<double>();
//    auto corundum_C14 = mpc::data::CorundumC14<double>();
//    auto corundum_C15 = mpc::data::CorundumC15<double>();
//    auto corundum_C16 = mpc::data::CorundumC16<double>();
//    auto corundum_C22 = mpc::data::CorundumC22<double>();
//    auto corundum_C23 = mpc::data::CorundumC23<double>();
//    auto corundum_C24 = mpc::data::CorundumC24<double>();
//    auto corundum_C25 = mpc::data::CorundumC25<double>();
//    auto corundum_C26 = mpc::data::CorundumC26<double>();
//    auto corundum_C33 = mpc::data::CorundumC33<double>();
//    auto corundum_C34 = mpc::data::CorundumC34<double>();
//    auto corundum_C35 = mpc::data::CorundumC35<double>();
//    auto corundum_C36 = mpc::data::CorundumC36<double>();
//    auto corundum_C44 = mpc::data::CorundumC44<double>();
//    auto corundum_C45 = mpc::data::CorundumC45<double>();
//    auto corundum_C46 = mpc::data::CorundumC46<double>();
//    auto corundum_C55 = mpc::data::CorundumC55<double>();
//    auto corundum_C56 = mpc::data::CorundumC56<double>();
//    auto corundum_C66 = mpc::data::CorundumC66<double>();
    auto corundum_bulk_modulus = mpc::data::CorundumBulkModulus<double>();
    auto corundum_shear_modulus = mpc::data::CorundumShearModulus<double>();
    mpc::core::StiffnessTensor<double> corundum_stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();

    // Calcite
    mpc::core::SymmetryGroupEnumeration calcite_symmetry_group_enum = mpc::data::CalciteSymmetryClass();
    auto calcite_density = mpc::data::CalciteDensity<double>();
//    auto calcite_C11 = mpc::data::CalciteC11<double>();
//    auto calcite_C12 = mpc::data::CalciteC12<double>();
//    auto calcite_C13 = mpc::data::CalciteC13<double>();
//    auto calcite_C14 = mpc::data::CalciteC14<double>();
//    auto calcite_C15 = mpc::data::CalciteC15<double>();
//    auto calcite_C16 = mpc::data::CalciteC16<double>();
//    auto calcite_C22 = mpc::data::CalciteC22<double>();
//    auto calcite_C23 = mpc::data::CalciteC23<double>();
//    auto calcite_C24 = mpc::data::CalciteC24<double>();
//    auto calcite_C25 = mpc::data::CalciteC25<double>();
//    auto calcite_C26 = mpc::data::CalciteC26<double>();
//    auto calcite_C33 = mpc::data::CalciteC33<double>();
//    auto calcite_C34 = mpc::data::CalciteC34<double>();
//    auto calcite_C35 = mpc::data::CalciteC35<double>();
//    auto calcite_C36 = mpc::data::CalciteC36<double>();
//    auto calcite_C44 = mpc::data::CalciteC44<double>();
//    auto calcite_C45 = mpc::data::CalciteC45<double>();
//    auto calcite_C46 = mpc::data::CalciteC46<double>();
//    auto calcite_C55 = mpc::data::CalciteC55<double>();
//    auto calcite_C56 = mpc::data::CalciteC56<double>();
//    auto calcite_C66 = mpc::data::CalciteC66<double>();
    auto calcite_bulk_modulus = mpc::data::CalciteBulkModulus<double>();
    auto calcite_shear_modulus = mpc::data::CalciteShearModulus<double>();
    mpc::core::StiffnessTensor<double> calcite_stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();

    // Quartz
    mpc::core::SymmetryGroupEnumeration quartz_symmetry_group_enum = mpc::data::QuartzSymmetryClass();
    auto quartz_density = mpc::data::QuartzDensity<double>();
//    auto quartz_C11 = mpc::data::QuartzC11<double>();
//    auto quartz_C12 = mpc::data::QuartzC12<double>();
//    auto quartz_C13 = mpc::data::QuartzC13<double>();
//    auto quartz_C14 = mpc::data::QuartzC14<double>();
//    auto quartz_C15 = mpc::data::QuartzC15<double>();
//    auto quartz_C16 = mpc::data::QuartzC16<double>();
//    auto quartz_C22 = mpc::data::QuartzC22<double>();
//    auto quartz_C23 = mpc::data::QuartzC23<double>();
//    auto quartz_C24 = mpc::data::QuartzC24<double>();
//    auto quartz_C25 = mpc::data::QuartzC25<double>();
//    auto quartz_C26 = mpc::data::QuartzC26<double>();
//    auto quartz_C33 = mpc::data::QuartzC33<double>();
//    auto quartz_C34 = mpc::data::QuartzC34<double>();
//    auto quartz_C35 = mpc::data::QuartzC35<double>();
//    auto quartz_C36 = mpc::data::QuartzC36<double>();
//    auto quartz_C44 = mpc::data::QuartzC44<double>();
//    auto quartz_C45 = mpc::data::QuartzC45<double>();
//    auto quartz_C46 = mpc::data::QuartzC46<double>();
//    auto quartz_C55 = mpc::data::QuartzC55<double>();
//    auto quartz_C56 = mpc::data::QuartzC56<double>();
//    auto quartz_C66 = mpc::data::QuartzC66<double>();
    auto quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
    auto quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();
    mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();

    // Tourmaline
    mpc::core::SymmetryGroupEnumeration tourmaline_symmetry_group_enum = mpc::data::TourmalineSymmetryClass();
    auto tourmaline_density = mpc::data::TourmalineDensity<double>();
//    auto tourmaline_C11 = mpc::data::TourmalineC11<double>();
//    auto tourmaline_C12 = mpc::data::TourmalineC12<double>();
//    auto tourmaline_C13 = mpc::data::TourmalineC13<double>();
//    auto tourmaline_C14 = mpc::data::TourmalineC14<double>();
//    auto tourmaline_C15 = mpc::data::TourmalineC15<double>();
//    auto tourmaline_C16 = mpc::data::TourmalineC16<double>();
//    auto tourmaline_C22 = mpc::data::TourmalineC22<double>();
//    auto tourmaline_C23 = mpc::data::TourmalineC23<double>();
//    auto tourmaline_C24 = mpc::data::TourmalineC24<double>();
//    auto tourmaline_C25 = mpc::data::TourmalineC25<double>();
//    auto tourmaline_C26 = mpc::data::TourmalineC26<double>();
//    auto tourmaline_C33 = mpc::data::TourmalineC33<double>();
//    auto tourmaline_C34 = mpc::data::TourmalineC34<double>();
//    auto tourmaline_C35 = mpc::data::TourmalineC35<double>();
//    auto tourmaline_C36 = mpc::data::TourmalineC36<double>();
//    auto tourmaline_C44 = mpc::data::TourmalineC44<double>();
//    auto tourmaline_C45 = mpc::data::TourmalineC45<double>();
//    auto tourmaline_C46 = mpc::data::TourmalineC46<double>();
//    auto tourmaline_C55 = mpc::data::TourmalineC55<double>();
//    auto tourmaline_C56 = mpc::data::TourmalineC56<double>();
//    auto tourmaline_C66 = mpc::data::TourmalineC66<double>();
    auto tourmaline_bulk_modulus = mpc::data::TourmalineBulkModulus<double>();
    auto tourmaline_shear_modulus = mpc::data::TourmalineShearModulus<double>();
    mpc::core::StiffnessTensor<double> tourmaline_stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();

    // Beryl
    mpc::core::SymmetryGroupEnumeration beryl_symmetry_group_enum = mpc::data::BerylSymmetryClass();
    auto beryl_density = mpc::data::BerylDensity<double>();
//    auto beryl_C11 = mpc::data::BerylC11<double>();
//    auto beryl_C12 = mpc::data::BerylC12<double>();
//    auto beryl_C13 = mpc::data::BerylC13<double>();
//    auto beryl_C14 = mpc::data::BerylC14<double>();
//    auto beryl_C15 = mpc::data::BerylC15<double>();
//    auto beryl_C16 = mpc::data::BerylC16<double>();
//    auto beryl_C22 = mpc::data::BerylC22<double>();
//    auto beryl_C23 = mpc::data::BerylC23<double>();
//    auto beryl_C24 = mpc::data::BerylC24<double>();
//    auto beryl_C25 = mpc::data::BerylC25<double>();
//    auto beryl_C26 = mpc::data::BerylC26<double>();
//    auto beryl_C33 = mpc::data::BerylC33<double>();
//    auto beryl_C34 = mpc::data::BerylC34<double>();
//    auto beryl_C35 = mpc::data::BerylC35<double>();
//    auto beryl_C36 = mpc::data::BerylC36<double>();
//    auto beryl_C44 = mpc::data::BerylC44<double>();
//    auto beryl_C45 = mpc::data::BerylC45<double>();
//    auto beryl_C46 = mpc::data::BerylC46<double>();
//    auto beryl_C55 = mpc::data::BerylC55<double>();
//    auto beryl_C56 = mpc::data::BerylC56<double>();
//    auto beryl_C66 = mpc::data::BerylC66<double>();
    auto beryl_bulk_modulus = mpc::data::BerylBulkModulus<double>();
    auto beryl_shear_modulus = mpc::data::BerylShearModulus<double>();
    mpc::core::StiffnessTensor<double> beryl_stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();

    // Graphite
    mpc::core::SymmetryGroupEnumeration graphite_symmetry_group_enum = mpc::data::GraphiteSymmetryClass();
    auto graphite_density = mpc::data::GraphiteDensity<double>();
//    auto graphite_C11 = mpc::data::GraphiteC11<double>();
//    auto graphite_C12 = mpc::data::GraphiteC12<double>();
//    auto graphite_C13 = mpc::data::GraphiteC13<double>();
//    auto graphite_C14 = mpc::data::GraphiteC14<double>();
//    auto graphite_C15 = mpc::data::GraphiteC15<double>();
//    auto graphite_C16 = mpc::data::GraphiteC16<double>();
//    auto graphite_C22 = mpc::data::GraphiteC22<double>();
//    auto graphite_C23 = mpc::data::GraphiteC23<double>();
//    auto graphite_C24 = mpc::data::GraphiteC24<double>();
//    auto graphite_C25 = mpc::data::GraphiteC25<double>();
//    auto graphite_C26 = mpc::data::GraphiteC26<double>();
//    auto graphite_C33 = mpc::data::GraphiteC33<double>();
//    auto graphite_C34 = mpc::data::GraphiteC34<double>();
//    auto graphite_C35 = mpc::data::GraphiteC35<double>();
//    auto graphite_C36 = mpc::data::GraphiteC36<double>();
//    auto graphite_C44 = mpc::data::GraphiteC44<double>();
//    auto graphite_C45 = mpc::data::GraphiteC45<double>();
//    auto graphite_C46 = mpc::data::GraphiteC46<double>();
//    auto graphite_C55 = mpc::data::GraphiteC55<double>();
//    auto graphite_C56 = mpc::data::GraphiteC56<double>();
//    auto graphite_C66 = mpc::data::GraphiteC66<double>();
    auto graphite_bulk_modulus = mpc::data::GraphiteBulkModulus<double>();
    auto graphite_shear_modulus = mpc::data::GraphiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> graphite_stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();

    // Wusite
    mpc::core::SymmetryGroupEnumeration wusite_symmetry_group_enum = mpc::data::WusiteSymmetryClass();
    auto wusite_density = mpc::data::WusiteDensity<double>();
//    auto wusite_C11 = mpc::data::WusiteC11<double>();
//    auto wusite_C12 = mpc::data::WusiteC12<double>();
//    auto wusite_C13 = mpc::data::WusiteC13<double>();
//    auto wusite_C14 = mpc::data::WusiteC14<double>();
//    auto wusite_C15 = mpc::data::WusiteC15<double>();
//    auto wusite_C16 = mpc::data::WusiteC16<double>();
//    auto wusite_C22 = mpc::data::WusiteC22<double>();
//    auto wusite_C23 = mpc::data::WusiteC23<double>();
//    auto wusite_C24 = mpc::data::WusiteC24<double>();
//    auto wusite_C25 = mpc::data::WusiteC25<double>();
//    auto wusite_C26 = mpc::data::WusiteC26<double>();
//    auto wusite_C33 = mpc::data::WusiteC33<double>();
//    auto wusite_C34 = mpc::data::WusiteC34<double>();
//    auto wusite_C35 = mpc::data::WusiteC35<double>();
//    auto wusite_C36 = mpc::data::WusiteC36<double>();
//    auto wusite_C44 = mpc::data::WusiteC44<double>();
//    auto wusite_C45 = mpc::data::WusiteC45<double>();
//    auto wusite_C46 = mpc::data::WusiteC46<double>();
//    auto wusite_C55 = mpc::data::WusiteC55<double>();
//    auto wusite_C56 = mpc::data::WusiteC56<double>();
//    auto wusite_C66 = mpc::data::WusiteC66<double>();
    auto wusite_bulk_modulus = mpc::data::WusiteBulkModulus<double>();
    auto wusite_shear_modulus = mpc::data::WusiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> wusite_stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();

    // Manganosite
    mpc::core::SymmetryGroupEnumeration manganosite_symmetry_group_enum = mpc::data::ManganositeSymmetryClass();
    auto manganosite_density = mpc::data::ManganositeDensity<double>();
//    auto manganosite_C11 = mpc::data::ManganositeC11<double>();
//    auto manganosite_C12 = mpc::data::ManganositeC12<double>();
//    auto manganosite_C13 = mpc::data::ManganositeC13<double>();
//    auto manganosite_C14 = mpc::data::ManganositeC14<double>();
//    auto manganosite_C15 = mpc::data::ManganositeC15<double>();
//    auto manganosite_C16 = mpc::data::ManganositeC16<double>();
//    auto manganosite_C22 = mpc::data::ManganositeC22<double>();
//    auto manganosite_C23 = mpc::data::ManganositeC23<double>();
//    auto manganosite_C24 = mpc::data::ManganositeC24<double>();
//    auto manganosite_C25 = mpc::data::ManganositeC25<double>();
//    auto manganosite_C26 = mpc::data::ManganositeC26<double>();
//    auto manganosite_C33 = mpc::data::ManganositeC33<double>();
//    auto manganosite_C34 = mpc::data::ManganositeC34<double>();
//    auto manganosite_C35 = mpc::data::ManganositeC35<double>();
//    auto manganosite_C36 = mpc::data::ManganositeC36<double>();
//    auto manganosite_C44 = mpc::data::ManganositeC44<double>();
//    auto manganosite_C45 = mpc::data::ManganositeC45<double>();
//    auto manganosite_C46 = mpc::data::ManganositeC46<double>();
//    auto manganosite_C55 = mpc::data::ManganositeC55<double>();
//    auto manganosite_C56 = mpc::data::ManganositeC56<double>();
//    auto manganosite_C66 = mpc::data::ManganositeC66<double>();
    auto manganosite_bulk_modulus = mpc::data::ManganositeBulkModulus<double>();
    auto manganosite_shear_modulus = mpc::data::ManganositeShearModulus<double>();
    mpc::core::StiffnessTensor<double> manganosite_stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();

    // Periclase
    mpc::core::SymmetryGroupEnumeration periclase_symmetry_group_enum = mpc::data::PericlaseSymmetryClass();
    auto periclase_density = mpc::data::PericlaseDensity<double>();
//    auto periclase_C11 = mpc::data::PericlaseC11<double>();
//    auto periclase_C12 = mpc::data::PericlaseC12<double>();
//    auto periclase_C13 = mpc::data::PericlaseC13<double>();
//    auto periclase_C14 = mpc::data::PericlaseC14<double>();
//    auto periclase_C15 = mpc::data::PericlaseC15<double>();
//    auto periclase_C16 = mpc::data::PericlaseC16<double>();
//    auto periclase_C22 = mpc::data::PericlaseC22<double>();
//    auto periclase_C23 = mpc::data::PericlaseC23<double>();
//    auto periclase_C24 = mpc::data::PericlaseC24<double>();
//    auto periclase_C25 = mpc::data::PericlaseC25<double>();
//    auto periclase_C26 = mpc::data::PericlaseC26<double>();
//    auto periclase_C33 = mpc::data::PericlaseC33<double>();
//    auto periclase_C34 = mpc::data::PericlaseC34<double>();
//    auto periclase_C35 = mpc::data::PericlaseC35<double>();
//    auto periclase_C36 = mpc::data::PericlaseC36<double>();
//    auto periclase_C44 = mpc::data::PericlaseC44<double>();
//    auto periclase_C45 = mpc::data::PericlaseC45<double>();
//    auto periclase_C46 = mpc::data::PericlaseC46<double>();
//    auto periclase_C55 = mpc::data::PericlaseC55<double>();
//    auto periclase_C56 = mpc::data::PericlaseC56<double>();
//    auto periclase_C66 = mpc::data::PericlaseC66<double>();
    auto periclase_bulk_modulus = mpc::data::PericlaseBulkModulus<double>();
    auto periclase_shear_modulus = mpc::data::PericlaseShearModulus<double>();
    mpc::core::StiffnessTensor<double> periclase_stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();

    // Magnetite
    mpc::core::SymmetryGroupEnumeration magnetite_symmetry_group_enum = mpc::data::MagnetiteSymmetryClass();
    auto magnetite_density = mpc::data::MagnetiteDensity<double>();
//    auto magnetite_C11 = mpc::data::MagnetiteC11<double>();
//    auto magnetite_C12 = mpc::data::MagnetiteC12<double>();
//    auto magnetite_C13 = mpc::data::MagnetiteC13<double>();
//    auto magnetite_C14 = mpc::data::MagnetiteC14<double>();
//    auto magnetite_C15 = mpc::data::MagnetiteC15<double>();
//    auto magnetite_C16 = mpc::data::MagnetiteC16<double>();
//    auto magnetite_C22 = mpc::data::MagnetiteC22<double>();
//    auto magnetite_C23 = mpc::data::MagnetiteC23<double>();
//    auto magnetite_C24 = mpc::data::MagnetiteC24<double>();
//    auto magnetite_C25 = mpc::data::MagnetiteC25<double>();
//    auto magnetite_C26 = mpc::data::MagnetiteC26<double>();
//    auto magnetite_C33 = mpc::data::MagnetiteC33<double>();
//    auto magnetite_C34 = mpc::data::MagnetiteC34<double>();
//    auto magnetite_C35 = mpc::data::MagnetiteC35<double>();
//    auto magnetite_C36 = mpc::data::MagnetiteC36<double>();
//    auto magnetite_C44 = mpc::data::MagnetiteC44<double>();
//    auto magnetite_C45 = mpc::data::MagnetiteC45<double>();
//    auto magnetite_C46 = mpc::data::MagnetiteC46<double>();
//    auto magnetite_C55 = mpc::data::MagnetiteC55<double>();
//    auto magnetite_C56 = mpc::data::MagnetiteC56<double>();
//    auto magnetite_C66 = mpc::data::MagnetiteC66<double>();
    auto magnetite_bulk_modulus = mpc::data::MagnetiteBulkModulus<double>();
    auto magnetite_shear_modulus = mpc::data::MagnetiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> magnetite_stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();

    // Chromite
    mpc::core::SymmetryGroupEnumeration chromite_symmetry_group_enum = mpc::data::ChromiteSymmetryClass();
    auto chromite_density = mpc::data::ChromiteDensity<double>();
//    auto chromite_C11 = mpc::data::ChromiteC11<double>();
//    auto chromite_C12 = mpc::data::ChromiteC12<double>();
//    auto chromite_C13 = mpc::data::ChromiteC13<double>();
//    auto chromite_C14 = mpc::data::ChromiteC14<double>();
//    auto chromite_C15 = mpc::data::ChromiteC15<double>();
//    auto chromite_C16 = mpc::data::ChromiteC16<double>();
//    auto chromite_C22 = mpc::data::ChromiteC22<double>();
//    auto chromite_C23 = mpc::data::ChromiteC23<double>();
//    auto chromite_C24 = mpc::data::ChromiteC24<double>();
//    auto chromite_C25 = mpc::data::ChromiteC25<double>();
//    auto chromite_C26 = mpc::data::ChromiteC26<double>();
//    auto chromite_C33 = mpc::data::ChromiteC33<double>();
//    auto chromite_C34 = mpc::data::ChromiteC34<double>();
//    auto chromite_C35 = mpc::data::ChromiteC35<double>();
//    auto chromite_C36 = mpc::data::ChromiteC36<double>();
//    auto chromite_C44 = mpc::data::ChromiteC44<double>();
//    auto chromite_C45 = mpc::data::ChromiteC45<double>();
//    auto chromite_C46 = mpc::data::ChromiteC46<double>();
//    auto chromite_C55 = mpc::data::ChromiteC55<double>();
//    auto chromite_C56 = mpc::data::ChromiteC56<double>();
//    auto chromite_C66 = mpc::data::ChromiteC66<double>();
    auto chromite_bulk_modulus = mpc::data::ChromiteBulkModulus<double>();
    auto chromite_shear_modulus = mpc::data::ChromiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> chromite_stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();

    // Spinel
    mpc::core::SymmetryGroupEnumeration spinel_symmetry_group_enum = mpc::data::SpinelSymmetryClass();
    auto spinel_density = mpc::data::SpinelDensity<double>();
//    auto spinel_C11 = mpc::data::SpinelC11<double>();
//    auto spinel_C12 = mpc::data::SpinelC12<double>();
//    auto spinel_C13 = mpc::data::SpinelC13<double>();
//    auto spinel_C14 = mpc::data::SpinelC14<double>();
//    auto spinel_C15 = mpc::data::SpinelC15<double>();
//    auto spinel_C16 = mpc::data::SpinelC16<double>();
//    auto spinel_C22 = mpc::data::SpinelC22<double>();
//    auto spinel_C23 = mpc::data::SpinelC23<double>();
//    auto spinel_C24 = mpc::data::SpinelC24<double>();
//    auto spinel_C25 = mpc::data::SpinelC25<double>();
//    auto spinel_C26 = mpc::data::SpinelC26<double>();
//    auto spinel_C33 = mpc::data::SpinelC33<double>();
//    auto spinel_C34 = mpc::data::SpinelC34<double>();
//    auto spinel_C35 = mpc::data::SpinelC35<double>();
//    auto spinel_C36 = mpc::data::SpinelC36<double>();
//    auto spinel_C44 = mpc::data::SpinelC44<double>();
//    auto spinel_C45 = mpc::data::SpinelC45<double>();
//    auto spinel_C46 = mpc::data::SpinelC46<double>();
//    auto spinel_C55 = mpc::data::SpinelC55<double>();
//    auto spinel_C56 = mpc::data::SpinelC56<double>();
//    auto spinel_C66 = mpc::data::SpinelC66<double>();
    auto spinel_bulk_modulus = mpc::data::SpinelBulkModulus<double>();
    auto spinel_shear_modulus = mpc::data::SpinelShearModulus<double>();
    mpc::core::StiffnessTensor<double> spinel_stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();

    // Pyrite
    mpc::core::SymmetryGroupEnumeration pyrite_symmetry_group_enum = mpc::data::PyriteSymmetryClass();
    auto pyrite_density = mpc::data::PyriteDensity<double>();
//    auto pyrite_C11 = mpc::data::PyriteC11<double>();
//    auto pyrite_C12 = mpc::data::PyriteC12<double>();
//    auto pyrite_C13 = mpc::data::PyriteC13<double>();
//    auto pyrite_C14 = mpc::data::PyriteC14<double>();
//    auto pyrite_C15 = mpc::data::PyriteC15<double>();
//    auto pyrite_C16 = mpc::data::PyriteC16<double>();
//    auto pyrite_C22 = mpc::data::PyriteC22<double>();
//    auto pyrite_C23 = mpc::data::PyriteC23<double>();
//    auto pyrite_C24 = mpc::data::PyriteC24<double>();
//    auto pyrite_C25 = mpc::data::PyriteC25<double>();
//    auto pyrite_C26 = mpc::data::PyriteC26<double>();
//    auto pyrite_C33 = mpc::data::PyriteC33<double>();
//    auto pyrite_C34 = mpc::data::PyriteC34<double>();
//    auto pyrite_C35 = mpc::data::PyriteC35<double>();
//    auto pyrite_C36 = mpc::data::PyriteC36<double>();
//    auto pyrite_C44 = mpc::data::PyriteC44<double>();
//    auto pyrite_C45 = mpc::data::PyriteC45<double>();
//    auto pyrite_C46 = mpc::data::PyriteC46<double>();
//    auto pyrite_C55 = mpc::data::PyriteC55<double>();
//    auto pyrite_C56 = mpc::data::PyriteC56<double>();
//    auto pyrite_C66 = mpc::data::PyriteC66<double>();
    auto pyrite_bulk_modulus = mpc::data::PyriteBulkModulus<double>();
    auto pyrite_shear_modulus = mpc::data::PyriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> pyrite_stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();

    // Galena
    mpc::core::SymmetryGroupEnumeration galena_symmetry_group_enum = mpc::data::GalenaSymmetryClass();
    auto galena_density = mpc::data::GalenaDensity<double>();
//    auto galena_C11 = mpc::data::GalenaC11<double>();
//    auto galena_C12 = mpc::data::GalenaC12<double>();
//    auto galena_C13 = mpc::data::GalenaC13<double>();
//    auto galena_C14 = mpc::data::GalenaC14<double>();
//    auto galena_C15 = mpc::data::GalenaC15<double>();
//    auto galena_C16 = mpc::data::GalenaC16<double>();
//    auto galena_C22 = mpc::data::GalenaC22<double>();
//    auto galena_C23 = mpc::data::GalenaC23<double>();
//    auto galena_C24 = mpc::data::GalenaC24<double>();
//    auto galena_C25 = mpc::data::GalenaC25<double>();
//    auto galena_C26 = mpc::data::GalenaC26<double>();
//    auto galena_C33 = mpc::data::GalenaC33<double>();
//    auto galena_C34 = mpc::data::GalenaC34<double>();
//    auto galena_C35 = mpc::data::GalenaC35<double>();
//    auto galena_C36 = mpc::data::GalenaC36<double>();
//    auto galena_C44 = mpc::data::GalenaC44<double>();
//    auto galena_C45 = mpc::data::GalenaC45<double>();
//    auto galena_C46 = mpc::data::GalenaC46<double>();
//    auto galena_C55 = mpc::data::GalenaC55<double>();
//    auto galena_C56 = mpc::data::GalenaC56<double>();
//    auto galena_C66 = mpc::data::GalenaC66<double>();
    auto galena_bulk_modulus = mpc::data::GalenaBulkModulus<double>();
    auto galena_shear_modulus = mpc::data::GalenaShearModulus<double>();
    mpc::core::StiffnessTensor<double> galena_stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();


    // Sphalerite
    mpc::core::SymmetryGroupEnumeration sphalerite_symmetry_group_enum = mpc::data::SphaleriteSymmetryClass();
    auto sphalerite_density = mpc::data::SphaleriteDensity<double>();
//    auto sphalerite_C11 = mpc::data::SphaleriteC11<double>();
//    auto sphalerite_C12 = mpc::data::SphaleriteC12<double>();
//    auto sphalerite_C13 = mpc::data::SphaleriteC13<double>();
//    auto sphalerite_C14 = mpc::data::SphaleriteC14<double>();
//    auto sphalerite_C15 = mpc::data::SphaleriteC15<double>();
//    auto sphalerite_C16 = mpc::data::SphaleriteC16<double>();
//    auto sphalerite_C22 = mpc::data::SphaleriteC22<double>();
//    auto sphalerite_C23 = mpc::data::SphaleriteC23<double>();
//    auto sphalerite_C24 = mpc::data::SphaleriteC24<double>();
//    auto sphalerite_C25 = mpc::data::SphaleriteC25<double>();
//    auto sphalerite_C26 = mpc::data::SphaleriteC26<double>();
//    auto sphalerite_C33 = mpc::data::SphaleriteC33<double>();
//    auto sphalerite_C34 = mpc::data::SphaleriteC34<double>();
//    auto sphalerite_C35 = mpc::data::SphaleriteC35<double>();
//    auto sphalerite_C36 = mpc::data::SphaleriteC36<double>();
//    auto sphalerite_C44 = mpc::data::SphaleriteC44<double>();
//    auto sphalerite_C45 = mpc::data::SphaleriteC45<double>();
//    auto sphalerite_C46 = mpc::data::SphaleriteC46<double>();
//    auto sphalerite_C55 = mpc::data::SphaleriteC55<double>();
//    auto sphalerite_C56 = mpc::data::SphaleriteC56<double>();
//    auto sphalerite_C66 = mpc::data::SphaleriteC66<double>();
    auto sphalerite_bulk_modulus = mpc::data::SphaleriteBulkModulus<double>();
    auto sphalerite_shear_modulus = mpc::data::SphaleriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> sphalerite_stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();

    // Fluorite
    mpc::core::SymmetryGroupEnumeration fluorite_symmetry_group_enum = mpc::data::FluoriteSymmetryClass();
    auto fluorite_density = mpc::data::FluoriteDensity<double>();
//    auto fluorite_C11 = mpc::data::FluoriteC11<double>();
//    auto fluorite_C12 = mpc::data::FluoriteC12<double>();
//    auto fluorite_C13 = mpc::data::FluoriteC13<double>();
//    auto fluorite_C14 = mpc::data::FluoriteC14<double>();
//    auto fluorite_C15 = mpc::data::FluoriteC15<double>();
//    auto fluorite_C16 = mpc::data::FluoriteC16<double>();
//    auto fluorite_C22 = mpc::data::FluoriteC22<double>();
//    auto fluorite_C23 = mpc::data::FluoriteC23<double>();
//    auto fluorite_C24 = mpc::data::FluoriteC24<double>();
//    auto fluorite_C25 = mpc::data::FluoriteC25<double>();
//    auto fluorite_C26 = mpc::data::FluoriteC26<double>();
//    auto fluorite_C33 = mpc::data::FluoriteC33<double>();
//    auto fluorite_C34 = mpc::data::FluoriteC34<double>();
//    auto fluorite_C35 = mpc::data::FluoriteC35<double>();
//    auto fluorite_C36 = mpc::data::FluoriteC36<double>();
//    auto fluorite_C44 = mpc::data::FluoriteC44<double>();
//    auto fluorite_C45 = mpc::data::FluoriteC45<double>();
//    auto fluorite_C46 = mpc::data::FluoriteC46<double>();
//    auto fluorite_C55 = mpc::data::FluoriteC55<double>();
//    auto fluorite_C56 = mpc::data::FluoriteC56<double>();
//    auto fluorite_C66 = mpc::data::FluoriteC66<double>();
    auto fluorite_bulk_modulus = mpc::data::FluoriteBulkModulus<double>();
    auto fluorite_shear_modulus = mpc::data::FluoriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> fluorite_stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();

    // Halite
    mpc::core::SymmetryGroupEnumeration halite_symmetry_group_enum = mpc::data::HaliteSymmetryClass();
    auto halite_density = mpc::data::HaliteDensity<double>();
//    auto halite_C11 = mpc::data::HaliteC11<double>();
//    auto halite_C12 = mpc::data::HaliteC12<double>();
//    auto halite_C13 = mpc::data::HaliteC13<double>();
//    auto halite_C14 = mpc::data::HaliteC14<double>();
//    auto halite_C15 = mpc::data::HaliteC15<double>();
//    auto halite_C16 = mpc::data::HaliteC16<double>();
//    auto halite_C22 = mpc::data::HaliteC22<double>();
//    auto halite_C23 = mpc::data::HaliteC23<double>();
//    auto halite_C24 = mpc::data::HaliteC24<double>();
//    auto halite_C25 = mpc::data::HaliteC25<double>();
//    auto halite_C26 = mpc::data::HaliteC26<double>();
//    auto halite_C33 = mpc::data::HaliteC33<double>();
//    auto halite_C34 = mpc::data::HaliteC34<double>();
//    auto halite_C35 = mpc::data::HaliteC35<double>();
//    auto halite_C36 = mpc::data::HaliteC36<double>();
//    auto halite_C44 = mpc::data::HaliteC44<double>();
//    auto halite_C45 = mpc::data::HaliteC45<double>();
//    auto halite_C46 = mpc::data::HaliteC46<double>();
//    auto halite_C55 = mpc::data::HaliteC55<double>();
//    auto halite_C56 = mpc::data::HaliteC56<double>();
//    auto halite_C66 = mpc::data::HaliteC66<double>();
    auto halite_bulk_modulus = mpc::data::HaliteBulkModulus<double>();
    auto halite_shear_modulus = mpc::data::HaliteShearModulus<double>();
    mpc::core::StiffnessTensor<double> halite_stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();

    // Sylvite
    mpc::core::SymmetryGroupEnumeration sylvite_symmetry_group_enum = mpc::data::SylviteSymmetryClass();
    auto sylvite_density = mpc::data::SylviteDensity<double>();
//    auto sylvite_C11 = mpc::data::SylviteC11<double>();
//    auto sylvite_C12 = mpc::data::SylviteC12<double>();
//    auto sylvite_C13 = mpc::data::SylviteC13<double>();
//    auto sylvite_C14 = mpc::data::SylviteC14<double>();
//    auto sylvite_C15 = mpc::data::SylviteC15<double>();
//    auto sylvite_C16 = mpc::data::SylviteC16<double>();
//    auto sylvite_C22 = mpc::data::SylviteC22<double>();
//    auto sylvite_C23 = mpc::data::SylviteC23<double>();
//    auto sylvite_C24 = mpc::data::SylviteC24<double>();
//    auto sylvite_C25 = mpc::data::SylviteC25<double>();
//    auto sylvite_C26 = mpc::data::SylviteC26<double>();
//    auto sylvite_C33 = mpc::data::SylviteC33<double>();
//    auto sylvite_C34 = mpc::data::SylviteC34<double>();
//    auto sylvite_C35 = mpc::data::SylviteC35<double>();
//    auto sylvite_C36 = mpc::data::SylviteC36<double>();
//    auto sylvite_C44 = mpc::data::SylviteC44<double>();
//    auto sylvite_C45 = mpc::data::SylviteC45<double>();
//    auto sylvite_C46 = mpc::data::SylviteC46<double>();
//    auto sylvite_C55 = mpc::data::SylviteC55<double>();
//    auto sylvite_C56 = mpc::data::SylviteC56<double>();
//    auto sylvite_C66 = mpc::data::SylviteC66<double>();
    auto sylvite_bulk_modulus = mpc::data::SylviteBulkModulus<double>();
    auto sylvite_shear_modulus = mpc::data::SylviteShearModulus<double>();
    mpc::core::StiffnessTensor<double> sylvite_stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();

    // tensor invariants
    // Augite
    mpc::core::ComplianceTensor<double> augite_compliance_tensor_from_augite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(augite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > augite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(augite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > augite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(augite_compliance_tensor_from_augite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double augite_k_vrh = 0.5 * (augite_k_mu_voigt.first.value + augite_k_mu_reuss.first.value);
    std::cout << "augite bulk modulus (ref)           : " << augite_bulk_modulus << std::endl;
    std::cout << "augite bulk modulus (voigt)         : " << augite_k_mu_voigt.first.value << std::endl;
    std::cout << "augite bulk modulus (ruess)         : " << augite_k_mu_reuss.first.value << std::endl;
    std::cout << "augite bulk modulus vrh difference  : " << std::abs(augite_k_vrh - augite_bulk_modulus) << std::endl;
    double augite_mu_vrh = 0.5 * (augite_k_mu_voigt.second.value + augite_k_mu_reuss.second.value);
    std::cout << "augite shear modulus (ref)          : " << augite_shear_modulus << std::endl;
    std::cout << "augite shear modulus (voigt)        : " << augite_k_mu_voigt.second.value << std::endl;
    std::cout << "augite shear modulus (ruess)        : " << augite_k_mu_reuss.second.value << std::endl;
    std::cout << "augite shear modulus vrh difference : " << std::abs(augite_mu_vrh - augite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    //mpc::rockphysics::MakeIsotropicStiffnessTensor(augite_bulk_modulus, augite_shear_modulus, augite_stiffness_tensor);
    //mpc::rockphysics::MakeIsotropicComplianceTensor(augite_bulk_modulus, augite_shear_modulus, augite_compliance_tensor_from_augite_stiffness_tensor);

    // Albite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> albite_compliance_tensor_from_albite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(albite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > albite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(albite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > albite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(albite_compliance_tensor_from_albite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double albite_k_vrh = 0.5 * (albite_k_mu_voigt.first.value + albite_k_mu_reuss.first.value);
    std::cout << "albite bulk modulus (ref)           : " << albite_bulk_modulus << std::endl;
    std::cout << "albite bulk modulus (voigt)         : " << albite_k_mu_voigt.first.value << std::endl;
    std::cout << "albite bulk modulus (ruess)         : " << albite_k_mu_reuss.first.value << std::endl;
    std::cout << "albite bulk modulus vrh difference  : " << std::abs(albite_k_vrh - albite_bulk_modulus) << std::endl;
    double albite_mu_vrh = 0.5 * (albite_k_mu_voigt.second.value + albite_k_mu_reuss.second.value);
    std::cout << "albite shear modulus (ref)          : " << albite_shear_modulus << std::endl;
    std::cout << "albite shear modulus (voigt)        : " << albite_k_mu_voigt.second.value << std::endl;
    std::cout << "albite shear modulus (ruess)        : " << albite_k_mu_reuss.second.value << std::endl;
    std::cout << "albite shear modulus vrh difference : " << std::abs(albite_mu_vrh - albite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    //mpc::rockphysics::MakeIsotropicStiffnessTensor(albite_bulk_modulus, albite_shear_modulus, albite_stiffness_tensor);
    //mpc::rockphysics::MakeIsotropicComplianceTensor(albite_bulk_modulus, albite_shear_modulus, albite_compliance_tensor_from_albite_stiffness_tensor);

    // Anorthite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> anorthite_compliance_tensor_from_anorthite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(anorthite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > anorthite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(anorthite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > anorthite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(anorthite_compliance_tensor_from_anorthite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double anorthite_k_vrh = 0.5 * (anorthite_k_mu_voigt.first.value + anorthite_k_mu_reuss.first.value);
    std::cout << "anorthite bulk modulus (ref)           : " << anorthite_bulk_modulus << std::endl;
    std::cout << "anorthite bulk modulus (voigt)         : " << anorthite_k_mu_voigt.first.value << std::endl;
    std::cout << "anorthite bulk modulus (ruess)         : " << anorthite_k_mu_reuss.first.value << std::endl;
    std::cout << "anorthite bulk modulus vrh difference  : " << std::abs(anorthite_k_vrh - anorthite_bulk_modulus) << std::endl;
    double anorthite_mu_vrh = 0.5 * (anorthite_k_mu_voigt.second.value + anorthite_k_mu_reuss.second.value);
    std::cout << "anorthite shear modulus (ref)          : " << anorthite_shear_modulus << std::endl;
    std::cout << "anorthite shear modulus (voigt)        : " << anorthite_k_mu_voigt.second.value << std::endl;
    std::cout << "anorthite shear modulus (ruess)        : " << anorthite_k_mu_reuss.second.value << std::endl;
    std::cout << "anorthite shear modulus vrh difference : " << std::abs(anorthite_mu_vrh - anorthite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    //mpc::rockphysics::MakeIsotropicStiffnessTensor(anorthite_bulk_modulus, anorthite_shear_modulus, anorthite_stiffness_tensor);
    //mpc::rockphysics::MakeIsotropicComplianceTensor(anorthite_bulk_modulus, anorthite_shear_modulus, anorthite_compliance_tensor_from_anorthite_stiffness_tensor);

    // Labradorite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> labradorite_compliance_tensor_from_labradorite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(labradorite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > labradorite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(labradorite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > labradorite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(labradorite_compliance_tensor_from_labradorite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double labradorite_k_vrh = 0.5 * (labradorite_k_mu_voigt.first.value + labradorite_k_mu_reuss.first.value);
    std::cout << "labradorite bulk modulus (ref)           : " << labradorite_bulk_modulus << std::endl;
    std::cout << "labradorite bulk modulus (voigt)         : " << labradorite_k_mu_voigt.first.value << std::endl;
    std::cout << "labradorite bulk modulus (ruess)         : " << labradorite_k_mu_reuss.first.value << std::endl;
    std::cout << "labradorite bulk modulus vrh difference  : " << std::abs(labradorite_k_vrh - labradorite_bulk_modulus) << std::endl;
    double labradorite_mu_vrh = 0.5 * (labradorite_k_mu_voigt.second.value + labradorite_k_mu_reuss.second.value);
    std::cout << "labradorite shear modulus (ref)          : " << labradorite_shear_modulus << std::endl;
    std::cout << "labradorite shear modulus (voigt)        : " << labradorite_k_mu_voigt.second.value << std::endl;
    std::cout << "labradorite shear modulus (ruess)        : " << labradorite_k_mu_reuss.second.value << std::endl;
    std::cout << "labradorite shear modulus vrh difference : " << std::abs(labradorite_mu_vrh - labradorite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    //mpc::rockphysics::MakeIsotropicStiffnessTensor(labradorite_bulk_modulus, labradorite_shear_modulus, labradorite_stiffness_tensor);
    //mpc::rockphysics::MakeIsotropicComplianceTensor(labradorite_bulk_modulus, labradorite_shear_modulus, labradorite_compliance_tensor_from_labradorite_stiffness_tensor);

    // Microcline
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> microcline_compliance_tensor_from_microcline_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(microcline_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > microcline_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(microcline_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > microcline_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(microcline_compliance_tensor_from_microcline_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double microcline_k_vrh = 0.5 * (microcline_k_mu_voigt.first.value + microcline_k_mu_reuss.first.value);
    std::cout << "microcline bulk modulus (ref)           : " << microcline_bulk_modulus << std::endl;
    std::cout << "microcline bulk modulus (voigt)         : " << microcline_k_mu_voigt.first.value << std::endl;
    std::cout << "microcline bulk modulus (ruess)         : " << microcline_k_mu_reuss.first.value << std::endl;
    std::cout << "microcline bulk modulus vrh difference  : " << std::abs(microcline_k_vrh - microcline_bulk_modulus) << std::endl;
    double microcline_mu_vrh = 0.5 * (microcline_k_mu_voigt.second.value + microcline_k_mu_reuss.second.value);
    std::cout << "microcline shear modulus (ref)          : " << microcline_shear_modulus << std::endl;
    std::cout << "microcline shear modulus (voigt)        : " << microcline_k_mu_voigt.second.value << std::endl;
    std::cout << "microcline shear modulus (ruess)        : " << microcline_k_mu_reuss.second.value << std::endl;
    std::cout << "microcline shear modulus vrh difference : " << std::abs(microcline_mu_vrh - microcline_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    //mpc::rockphysics::MakeIsotropicStiffnessTensor(microcline_bulk_modulus, microcline_shear_modulus, microcline_stiffness_tensor);
    //mpc::rockphysics::MakeIsotropicComplianceTensor(microcline_bulk_modulus, microcline_shear_modulus, microcline_compliance_tensor_from_microcline_stiffness_tensor);

    // Oligoclase
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> oligoclase_compliance_tensor_from_oligoclase_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(oligoclase_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > oligoclase_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(oligoclase_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > oligoclase_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(oligoclase_compliance_tensor_from_oligoclase_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double oligoclase_k_vrh = 0.5 * (oligoclase_k_mu_voigt.first.value + oligoclase_k_mu_reuss.first.value);
    std::cout << "oligoclase bulk modulus (ref)           : " << oligoclase_bulk_modulus << std::endl;
    std::cout << "oligoclase bulk modulus (voigt)         : " << oligoclase_k_mu_voigt.first.value << std::endl;
    std::cout << "oligoclase bulk modulus (ruess)         : " << oligoclase_k_mu_reuss.first.value << std::endl;
    std::cout << "oligoclase bulk modulus vrh difference  : " << std::abs(oligoclase_k_vrh - oligoclase_bulk_modulus) << std::endl;
    double oligoclase_mu_vrh = 0.5 * (oligoclase_k_mu_voigt.second.value + oligoclase_k_mu_reuss.second.value);
    std::cout << "oligoclase shear modulus (ref)          : " << oligoclase_shear_modulus << std::endl;
    std::cout << "oligoclase shear modulus (voigt)        : " << oligoclase_k_mu_voigt.second.value << std::endl;
    std::cout << "oligoclase shear modulus (ruess)        : " << oligoclase_k_mu_reuss.second.value << std::endl;
    std::cout << "oligoclase shear modulus vrh difference : " << std::abs(oligoclase_mu_vrh - oligoclase_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    //mpc::rockphysics::MakeIsotropicStiffnessTensor(oligoclase_bulk_modulus, oligoclase_shear_modulus, oligoclase_stiffness_tensor);
    //mpc::rockphysics::MakeIsotropicComplianceTensor(oligoclase_bulk_modulus, oligoclase_shear_modulus, oligoclase_compliance_tensor_from_oligoclase_stiffness_tensor);

    // Coesite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> coesite_compliance_tensor_from_coesite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(coesite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > coesite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(coesite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > coesite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(coesite_compliance_tensor_from_coesite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double coesite_k_vrh = 0.5 * (coesite_k_mu_voigt.first.value + coesite_k_mu_reuss.first.value);
    std::cout << "coesite bulk modulus (ref)           : " << coesite_bulk_modulus << std::endl;
    std::cout << "coesite bulk modulus (voigt)         : " << coesite_k_mu_voigt.first.value << std::endl;
    std::cout << "coesite bulk modulus (ruess)         : " << coesite_k_mu_reuss.first.value << std::endl;
    std::cout << "coesite bulk modulus vrh difference  : " << std::abs(coesite_k_vrh - coesite_bulk_modulus) << std::endl;
    double coesite_mu_vrh = 0.5 * (coesite_k_mu_voigt.second.value + coesite_k_mu_reuss.second.value);
    std::cout << "coesite shear modulus (ref)          : " << coesite_shear_modulus << std::endl;
    std::cout << "coesite shear modulus (voigt)        : " << coesite_k_mu_voigt.second.value << std::endl;
    std::cout << "coesite shear modulus (ruess)        : " << coesite_k_mu_reuss.second.value << std::endl;
    std::cout << "coesite shear modulus vrh difference : " << std::abs(coesite_mu_vrh - coesite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(coesite_bulk_modulus, coesite_shear_modulus, coesite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(coesite_bulk_modulus, coesite_shear_modulus, coesite_compliance_tensor_from_coesite_stiffness_tensor);

    // Epidote
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> epidote_compliance_tensor_from_epidote_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(epidote_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > epidote_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(epidote_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > epidote_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(epidote_compliance_tensor_from_epidote_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double epidote_k_vrh = 0.5 * (epidote_k_mu_voigt.first.value + epidote_k_mu_reuss.first.value);
    std::cout << "epidote bulk modulus (ref)           : " << epidote_bulk_modulus << std::endl;
    std::cout << "epidote bulk modulus (voigt)         : " << epidote_k_mu_voigt.first.value << std::endl;
    std::cout << "epidote bulk modulus (ruess)         : " << epidote_k_mu_reuss.first.value << std::endl;
    std::cout << "epidote bulk modulus vrh difference  : " << std::abs(epidote_k_vrh - epidote_bulk_modulus) << std::endl;
    double epidote_mu_vrh = 0.5 * (epidote_k_mu_voigt.second.value + epidote_k_mu_reuss.second.value);
    std::cout << "epidote shear modulus (ref)          : " << epidote_shear_modulus << std::endl;
    std::cout << "epidote shear modulus (voigt)        : " << epidote_k_mu_voigt.second.value << std::endl;
    std::cout << "epidote shear modulus (ruess)        : " << epidote_k_mu_reuss.second.value << std::endl;
    std::cout << "epidote shear modulus vrh difference : " << std::abs(epidote_mu_vrh - epidote_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(epidote_bulk_modulus, epidote_shear_modulus, epidote_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(epidote_bulk_modulus, epidote_shear_modulus, epidote_compliance_tensor_from_epidote_stiffness_tensor);

    // Hornblende
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> hornblende_compliance_tensor_from_hornblende_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(hornblende_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > hornblende_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(hornblende_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > hornblende_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(hornblende_compliance_tensor_from_hornblende_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double hornblende_k_vrh = 0.5 * (hornblende_k_mu_voigt.first.value + hornblende_k_mu_reuss.first.value);
    std::cout << "hornblende bulk modulus (ref)           : " << hornblende_bulk_modulus << std::endl;
    std::cout << "hornblende bulk modulus (voigt)         : " << hornblende_k_mu_voigt.first.value << std::endl;
    std::cout << "hornblende bulk modulus (ruess)         : " << hornblende_k_mu_reuss.first.value << std::endl;
    std::cout << "hornblende bulk modulus vrh difference  : " << std::abs(hornblende_k_vrh - hornblende_bulk_modulus) << std::endl;
    double hornblende_mu_vrh = 0.5 * (hornblende_k_mu_voigt.second.value + hornblende_k_mu_reuss.second.value);
    std::cout << "hornblende shear modulus (ref)          : " << hornblende_shear_modulus << std::endl;
    std::cout << "hornblende shear modulus (voigt)        : " << hornblende_k_mu_voigt.second.value << std::endl;
    std::cout << "hornblende shear modulus (ruess)        : " << hornblende_k_mu_reuss.second.value << std::endl;
    std::cout << "hornblende shear modulus vrh difference : " << std::abs(hornblende_mu_vrh - hornblende_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(hornblende_bulk_modulus, hornblende_shear_modulus, hornblende_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(hornblende_bulk_modulus, hornblende_shear_modulus, hornblende_compliance_tensor_from_hornblende_stiffness_tensor);

    // Muscovite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> muscovite_compliance_tensor_from_muscovite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(muscovite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > muscovite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(muscovite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > muscovite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(muscovite_compliance_tensor_from_muscovite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double muscovite_k_vrh = 0.5 * (muscovite_k_mu_voigt.first.value + muscovite_k_mu_reuss.first.value);
    std::cout << "muscovite bulk modulus (ref)           : " << muscovite_bulk_modulus << std::endl;
    std::cout << "muscovite bulk modulus (voigt)         : " << muscovite_k_mu_voigt.first.value << std::endl;
    std::cout << "muscovite bulk modulus (ruess)         : " << muscovite_k_mu_reuss.first.value << std::endl;
    std::cout << "muscovite bulk modulus vrh difference  : " << std::abs(muscovite_k_vrh - muscovite_bulk_modulus) << std::endl;
    double muscovite_mu_vrh = 0.5 * (muscovite_k_mu_voigt.second.value + muscovite_k_mu_reuss.second.value);
    std::cout << "muscovite shear modulus (ref)          : " << muscovite_shear_modulus << std::endl;
    std::cout << "muscovite shear modulus (voigt)        : " << muscovite_k_mu_voigt.second.value << std::endl;
    std::cout << "muscovite shear modulus (ruess)        : " << muscovite_k_mu_reuss.second.value << std::endl;
    std::cout << "muscovite shear modulus vrh difference : " << std::abs(muscovite_mu_vrh - muscovite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(muscovite_bulk_modulus, muscovite_shear_modulus, muscovite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(muscovite_bulk_modulus, muscovite_shear_modulus, muscovite_compliance_tensor_from_muscovite_stiffness_tensor);

    // Gypsum
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> gypsum_compliance_tensor_from_gypsum_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(gypsum_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > gypsum_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(gypsum_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > gypsum_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(gypsum_compliance_tensor_from_gypsum_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double gypsum_k_vrh = 0.5 * (gypsum_k_mu_voigt.first.value + gypsum_k_mu_reuss.first.value);
    std::cout << "gypsum bulk modulus (ref)           : " << gypsum_bulk_modulus << std::endl;
    std::cout << "gypsum bulk modulus (voigt)         : " << gypsum_k_mu_voigt.first.value << std::endl;
    std::cout << "gypsum bulk modulus (ruess)         : " << gypsum_k_mu_reuss.first.value << std::endl;
    std::cout << "gypsum bulk modulus vrh difference  : " << std::abs(gypsum_k_vrh - gypsum_bulk_modulus) << std::endl;
    double gypsum_mu_vrh = 0.5 * (gypsum_k_mu_voigt.second.value + gypsum_k_mu_reuss.second.value);
    std::cout << "gypsum shear modulus (ref)          : " << gypsum_shear_modulus << std::endl;
    std::cout << "gypsum shear modulus (voigt)        : " << gypsum_k_mu_voigt.second.value << std::endl;
    std::cout << "gypsum shear modulus (ruess)        : " << gypsum_k_mu_reuss.second.value << std::endl;
    std::cout << "gypsum shear modulus vrh difference : " << std::abs(gypsum_mu_vrh - gypsum_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(gypsum_bulk_modulus, gypsum_shear_modulus, gypsum_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(gypsum_bulk_modulus, gypsum_shear_modulus, gypsum_compliance_tensor_from_gypsum_stiffness_tensor);

    // Enstatite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> enstatite_compliance_tensor_from_enstatite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(enstatite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > enstatite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(enstatite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > enstatite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(enstatite_compliance_tensor_from_enstatite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double enstatite_k_vrh = 0.5 * (enstatite_k_mu_voigt.first.value + enstatite_k_mu_reuss.first.value);
    std::cout << "enstatite bulk modulus (ref)           : " << enstatite_bulk_modulus << std::endl;
    std::cout << "enstatite bulk modulus (voigt)         : " << enstatite_k_mu_voigt.first.value << std::endl;
    std::cout << "enstatite bulk modulus (ruess)         : " << enstatite_k_mu_reuss.first.value << std::endl;
    std::cout << "enstatite bulk modulus vrh difference  : " << std::abs(enstatite_k_vrh - enstatite_bulk_modulus) << std::endl;
    double enstatite_mu_vrh = 0.5 * (enstatite_k_mu_voigt.second.value + enstatite_k_mu_reuss.second.value);
    std::cout << "enstatite shear modulus (ref)          : " << enstatite_shear_modulus << std::endl;
    std::cout << "enstatite shear modulus (voigt)        : " << enstatite_k_mu_voigt.second.value << std::endl;
    std::cout << "enstatite shear modulus (ruess)        : " << enstatite_k_mu_reuss.second.value << std::endl;
    std::cout << "enstatite shear modulus vrh difference : " << std::abs(enstatite_mu_vrh - enstatite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(enstatite_bulk_modulus, enstatite_shear_modulus, enstatite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(enstatite_bulk_modulus, enstatite_shear_modulus, enstatite_compliance_tensor_from_enstatite_stiffness_tensor);

    // Forsterite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> forsterite_compliance_tensor_from_forsterite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(forsterite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > forsterite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(forsterite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > forsterite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(forsterite_compliance_tensor_from_forsterite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double forsterite_k_vrh = 0.5 * (forsterite_k_mu_voigt.first.value + forsterite_k_mu_reuss.first.value);
    std::cout << "forsterite bulk modulus (ref)           : " << forsterite_bulk_modulus << std::endl;
    std::cout << "forsterite bulk modulus (voigt)         : " << forsterite_k_mu_voigt.first.value << std::endl;
    std::cout << "forsterite bulk modulus (ruess)         : " << forsterite_k_mu_reuss.first.value << std::endl;
    std::cout << "forsterite bulk modulus vrh difference  : " << std::abs(forsterite_k_vrh - forsterite_bulk_modulus) << std::endl;
    double forsterite_mu_vrh = 0.5 * (forsterite_k_mu_voigt.second.value + forsterite_k_mu_reuss.second.value);
    std::cout << "forsterite shear modulus (ref)          : " << forsterite_shear_modulus << std::endl;
    std::cout << "forsterite shear modulus (voigt)        : " << forsterite_k_mu_voigt.second.value << std::endl;
    std::cout << "forsterite shear modulus (ruess)        : " << forsterite_k_mu_reuss.second.value << std::endl;
    std::cout << "forsterite shear modulus vrh difference : " << std::abs(forsterite_mu_vrh - forsterite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(forsterite_bulk_modulus, forsterite_shear_modulus, forsterite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(forsterite_bulk_modulus, forsterite_shear_modulus, forsterite_compliance_tensor_from_forsterite_stiffness_tensor);

    // Fayalite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> fayalite_compliance_tensor_from_fayalite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(fayalite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > fayalite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(fayalite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > fayalite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(fayalite_compliance_tensor_from_fayalite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double fayalite_k_vrh = 0.5 * (fayalite_k_mu_voigt.first.value + fayalite_k_mu_reuss.first.value);
    std::cout << "fayalite bulk modulus (ref)           : " << fayalite_bulk_modulus << std::endl;
    std::cout << "fayalite bulk modulus (voigt)         : " << fayalite_k_mu_voigt.first.value << std::endl;
    std::cout << "fayalite bulk modulus (ruess)         : " << fayalite_k_mu_reuss.first.value << std::endl;
    std::cout << "fayalite bulk modulus vrh difference  : " << std::abs(fayalite_k_vrh - fayalite_bulk_modulus) << std::endl;
    double fayalite_mu_vrh = 0.5 * (fayalite_k_mu_voigt.second.value + fayalite_k_mu_reuss.second.value);
    std::cout << "fayalite shear modulus (ref)          : " << fayalite_shear_modulus << std::endl;
    std::cout << "fayalite shear modulus (voigt)        : " << fayalite_k_mu_voigt.second.value << std::endl;
    std::cout << "fayalite shear modulus (ruess)        : " << fayalite_k_mu_reuss.second.value << std::endl;
    std::cout << "fayalite shear modulus vrh difference : " << std::abs(fayalite_mu_vrh - fayalite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(fayalite_bulk_modulus, fayalite_shear_modulus, fayalite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(fayalite_bulk_modulus, fayalite_shear_modulus, fayalite_compliance_tensor_from_fayalite_stiffness_tensor);

    // Montecellite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> montecellite_compliance_tensor_from_montecellite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(montecellite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > montecellite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(montecellite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > montecellite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(montecellite_compliance_tensor_from_montecellite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double montecellite_k_vrh = 0.5 * (montecellite_k_mu_voigt.first.value + montecellite_k_mu_reuss.first.value);
    std::cout << "montecellite bulk modulus (ref)           : " << montecellite_bulk_modulus << std::endl;
    std::cout << "montecellite bulk modulus (voigt)         : " << montecellite_k_mu_voigt.first.value << std::endl;
    std::cout << "montecellite bulk modulus (ruess)         : " << montecellite_k_mu_reuss.first.value << std::endl;
    std::cout << "montecellite bulk modulus vrh difference  : " << std::abs(montecellite_k_vrh - montecellite_bulk_modulus) << std::endl;
    double montecellite_mu_vrh = 0.5 * (montecellite_k_mu_voigt.second.value + montecellite_k_mu_reuss.second.value);
    std::cout << "montecellite shear modulus (ref)          : " << montecellite_shear_modulus << std::endl;
    std::cout << "montecellite shear modulus (voigt)        : " << montecellite_k_mu_voigt.second.value << std::endl;
    std::cout << "montecellite shear modulus (ruess)        : " << montecellite_k_mu_reuss.second.value << std::endl;
    std::cout << "montecellite shear modulus vrh difference : " << std::abs(montecellite_mu_vrh - montecellite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(montecellite_bulk_modulus, montecellite_shear_modulus, montecellite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(montecellite_bulk_modulus, montecellite_shear_modulus, montecellite_compliance_tensor_from_montecellite_stiffness_tensor);

    // Andalusite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> andalusite_compliance_tensor_from_andalusite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(andalusite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > andalusite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(andalusite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > andalusite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(andalusite_compliance_tensor_from_andalusite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double andalusite_k_vrh = 0.5 * (andalusite_k_mu_voigt.first.value + andalusite_k_mu_reuss.first.value);
    std::cout << "andalusite bulk modulus (ref)           : " << andalusite_bulk_modulus << std::endl;
    std::cout << "andalusite bulk modulus (voigt)         : " << andalusite_k_mu_voigt.first.value << std::endl;
    std::cout << "andalusite bulk modulus (ruess)         : " << andalusite_k_mu_reuss.first.value << std::endl;
    std::cout << "andalusite bulk modulus vrh difference  : " << std::abs(andalusite_k_vrh - andalusite_bulk_modulus) << std::endl;
    double andalusite_mu_vrh = 0.5 * (andalusite_k_mu_voigt.second.value + andalusite_k_mu_reuss.second.value);
    std::cout << "andalusite shear modulus (ref)          : " << andalusite_shear_modulus << std::endl;
    std::cout << "andalusite shear modulus (voigt)        : " << andalusite_k_mu_voigt.second.value << std::endl;
    std::cout << "andalusite shear modulus (ruess)        : " << andalusite_k_mu_reuss.second.value << std::endl;
    std::cout << "andalusite shear modulus vrh difference : " << std::abs(andalusite_mu_vrh - andalusite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(andalusite_bulk_modulus, andalusite_shear_modulus, andalusite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(andalusite_bulk_modulus, andalusite_shear_modulus, andalusite_compliance_tensor_from_andalusite_stiffness_tensor);

    // Silimanite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> silimanite_compliance_tensor_from_silimanite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(silimanite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > silimanite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(silimanite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > silimanite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(silimanite_compliance_tensor_from_silimanite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double silimanite_k_vrh = 0.5 * (silimanite_k_mu_voigt.first.value + silimanite_k_mu_reuss.first.value);
    std::cout << "silimanite bulk modulus (ref)           : " << silimanite_bulk_modulus << std::endl;
    std::cout << "silimanite bulk modulus (voigt)         : " << silimanite_k_mu_voigt.first.value << std::endl;
    std::cout << "silimanite bulk modulus (ruess)         : " << silimanite_k_mu_reuss.first.value << std::endl;
    std::cout << "silimanite bulk modulus vrh difference  : " << std::abs(silimanite_k_vrh - silimanite_bulk_modulus) << std::endl;
    double silimanite_mu_vrh = 0.5 * (silimanite_k_mu_voigt.second.value + silimanite_k_mu_reuss.second.value);
    std::cout << "silimanite shear modulus (ref)          : " << silimanite_shear_modulus << std::endl;
    std::cout << "silimanite shear modulus (voigt)        : " << silimanite_k_mu_voigt.second.value << std::endl;
    std::cout << "silimanite shear modulus (ruess)        : " << silimanite_k_mu_reuss.second.value << std::endl;
    std::cout << "silimanite shear modulus vrh difference : " << std::abs(silimanite_mu_vrh - silimanite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(silimanite_bulk_modulus, silimanite_shear_modulus, silimanite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(silimanite_bulk_modulus, silimanite_shear_modulus, silimanite_compliance_tensor_from_silimanite_stiffness_tensor);

    // Barite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> barite_compliance_tensor_from_barite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(barite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > barite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(barite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > barite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(barite_compliance_tensor_from_barite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double barite_k_vrh = 0.5 * (barite_k_mu_voigt.first.value + barite_k_mu_reuss.first.value);
    std::cout << "barite bulk modulus (ref)           : " << barite_bulk_modulus << std::endl;
    std::cout << "barite bulk modulus (voigt)         : " << barite_k_mu_voigt.first.value << std::endl;
    std::cout << "barite bulk modulus (ruess)         : " << barite_k_mu_reuss.first.value << std::endl;
    std::cout << "barite bulk modulus vrh difference  : " << std::abs(barite_k_vrh - barite_bulk_modulus) << std::endl;
    double barite_mu_vrh = 0.5 * (barite_k_mu_voigt.second.value + barite_k_mu_reuss.second.value);
    std::cout << "barite shear modulus (ref)          : " << barite_shear_modulus << std::endl;
    std::cout << "barite shear modulus (voigt)        : " << barite_k_mu_voigt.second.value << std::endl;
    std::cout << "barite shear modulus (ruess)        : " << barite_k_mu_reuss.second.value << std::endl;
    std::cout << "barite shear modulus vrh difference : " << std::abs(barite_mu_vrh - barite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(barite_bulk_modulus, barite_shear_modulus, barite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(barite_bulk_modulus, barite_shear_modulus, barite_compliance_tensor_from_barite_stiffness_tensor);

    // Anhydrite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> anhydrite_compliance_tensor_from_anhydrite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(anhydrite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > anhydrite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(anhydrite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > anhydrite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(anhydrite_compliance_tensor_from_anhydrite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double anhydrite_k_vrh = 0.5 * (anhydrite_k_mu_voigt.first.value + anhydrite_k_mu_reuss.first.value);
    std::cout << "anhydrite bulk modulus (ref)           : " << anhydrite_bulk_modulus << std::endl;
    std::cout << "anhydrite bulk modulus (voigt)         : " << anhydrite_k_mu_voigt.first.value << std::endl;
    std::cout << "anhydrite bulk modulus (ruess)         : " << anhydrite_k_mu_reuss.first.value << std::endl;
    std::cout << "anhydrite bulk modulus vrh difference  : " << std::abs(anhydrite_k_vrh - anhydrite_bulk_modulus) << std::endl;
    double anhydrite_mu_vrh = 0.5 * (anhydrite_k_mu_voigt.second.value + anhydrite_k_mu_reuss.second.value);
    std::cout << "anhydrite shear modulus (ref)          : " << anhydrite_shear_modulus << std::endl;
    std::cout << "anhydrite shear modulus (voigt)        : " << anhydrite_k_mu_voigt.second.value << std::endl;
    std::cout << "anhydrite shear modulus (ruess)        : " << anhydrite_k_mu_reuss.second.value << std::endl;
    std::cout << "anhydrite shear modulus vrh difference : " << std::abs(anhydrite_mu_vrh - anhydrite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(anhydrite_bulk_modulus, anhydrite_shear_modulus, anhydrite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(anhydrite_bulk_modulus, anhydrite_shear_modulus, anhydrite_compliance_tensor_from_anhydrite_stiffness_tensor);

    // Dolomite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> dolomite_compliance_tensor_from_dolomite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(dolomite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > dolomite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(dolomite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > dolomite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(dolomite_compliance_tensor_from_dolomite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double dolomite_k_vrh = 0.5 * (dolomite_k_mu_voigt.first.value + dolomite_k_mu_reuss.first.value);
    std::cout << "dolomite bulk modulus (ref)           : " << dolomite_bulk_modulus << std::endl;
    std::cout << "dolomite bulk modulus (voigt)         : " << dolomite_k_mu_voigt.first.value << std::endl;
    std::cout << "dolomite bulk modulus (ruess)         : " << dolomite_k_mu_reuss.first.value << std::endl;
    std::cout << "dolomite bulk modulus vrh difference  : " << std::abs(dolomite_k_vrh - dolomite_bulk_modulus) << std::endl;
    double dolomite_mu_vrh = 0.5 * (dolomite_k_mu_voigt.second.value + dolomite_k_mu_reuss.second.value);
    std::cout << "dolomite shear modulus (ref)          : " << dolomite_shear_modulus << std::endl;
    std::cout << "dolomite shear modulus (voigt)        : " << dolomite_k_mu_voigt.second.value << std::endl;
    std::cout << "dolomite shear modulus (ruess)        : " << dolomite_k_mu_reuss.second.value << std::endl;
    std::cout << "dolomite shear modulus vrh difference : " << std::abs(dolomite_mu_vrh - dolomite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(dolomite_bulk_modulus, dolomite_shear_modulus, dolomite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(dolomite_bulk_modulus, dolomite_shear_modulus, dolomite_compliance_tensor_from_dolomite_stiffness_tensor);

    // Rutile
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> rutile_compliance_tensor_from_rutile_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(rutile_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > rutile_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(rutile_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > rutile_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(rutile_compliance_tensor_from_rutile_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double rutile_k_vrh = 0.5 * (rutile_k_mu_voigt.first.value + rutile_k_mu_reuss.first.value);
    std::cout << "rutile bulk modulus (ref)           : " << rutile_bulk_modulus << std::endl;
    std::cout << "rutile bulk modulus (voigt)         : " << rutile_k_mu_voigt.first.value << std::endl;
    std::cout << "rutile bulk modulus (ruess)         : " << rutile_k_mu_reuss.first.value << std::endl;
    std::cout << "rutile bulk modulus vrh difference  : " << std::abs(rutile_k_vrh - rutile_bulk_modulus) << std::endl;
    double rutile_mu_vrh = 0.5 * (rutile_k_mu_voigt.second.value + rutile_k_mu_reuss.second.value);
    std::cout << "rutile shear modulus (ref)          : " << rutile_shear_modulus << std::endl;
    std::cout << "rutile shear modulus (voigt)        : " << rutile_k_mu_voigt.second.value << std::endl;
    std::cout << "rutile shear modulus (ruess)        : " << rutile_k_mu_reuss.second.value << std::endl;
    std::cout << "rutile shear modulus vrh difference : " << std::abs(rutile_mu_vrh - rutile_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(rutile_bulk_modulus, rutile_shear_modulus, rutile_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(rutile_bulk_modulus, rutile_shear_modulus, rutile_compliance_tensor_from_rutile_stiffness_tensor);

    // Zircon
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> zircon_compliance_tensor_from_zircon_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(zircon_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > zircon_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(zircon_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > zircon_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(zircon_compliance_tensor_from_zircon_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double zircon_k_vrh = 0.5 * (zircon_k_mu_voigt.first.value + zircon_k_mu_reuss.first.value);
    std::cout << "zircon bulk modulus (ref)           : " << zircon_bulk_modulus << std::endl;
    std::cout << "zircon bulk modulus (voigt)         : " << zircon_k_mu_voigt.first.value << std::endl;
    std::cout << "zircon bulk modulus (ruess)         : " << zircon_k_mu_reuss.first.value << std::endl;
    std::cout << "zircon bulk modulus vrh difference  : " << std::abs(zircon_k_vrh - zircon_bulk_modulus) << std::endl;
    double zircon_mu_vrh = 0.5 * (zircon_k_mu_voigt.second.value + zircon_k_mu_reuss.second.value);
    std::cout << "zircon shear modulus (ref)          : " << zircon_shear_modulus << std::endl;
    std::cout << "zircon shear modulus (voigt)        : " << zircon_k_mu_voigt.second.value << std::endl;
    std::cout << "zircon shear modulus (ruess)        : " << zircon_k_mu_reuss.second.value << std::endl;
    std::cout << "zircon shear modulus vrh difference : " << std::abs(zircon_mu_vrh - zircon_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(zircon_bulk_modulus, zircon_shear_modulus, zircon_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(zircon_bulk_modulus, zircon_shear_modulus, zircon_compliance_tensor_from_zircon_stiffness_tensor);

    // Corundum
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> corundum_compliance_tensor_from_corundum_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(corundum_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > corundum_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(corundum_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > corundum_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(corundum_compliance_tensor_from_corundum_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double corundum_k_vrh = 0.5 * (corundum_k_mu_voigt.first.value + corundum_k_mu_reuss.first.value);
    std::cout << "corundum bulk modulus (ref)           : " << corundum_bulk_modulus << std::endl;
    std::cout << "corundum bulk modulus (voigt)         : " << corundum_k_mu_voigt.first.value << std::endl;
    std::cout << "corundum bulk modulus (ruess)         : " << corundum_k_mu_reuss.first.value << std::endl;
    std::cout << "corundum bulk modulus vrh difference  : " << std::abs(corundum_k_vrh - corundum_bulk_modulus) << std::endl;
    double corundum_mu_vrh = 0.5 * (corundum_k_mu_voigt.second.value + corundum_k_mu_reuss.second.value);
    std::cout << "corundum shear modulus (ref)          : " << corundum_shear_modulus << std::endl;
    std::cout << "corundum shear modulus (voigt)        : " << corundum_k_mu_voigt.second.value << std::endl;
    std::cout << "corundum shear modulus (ruess)        : " << corundum_k_mu_reuss.second.value << std::endl;
    std::cout << "corundum shear modulus vrh difference : " << std::abs(corundum_mu_vrh - corundum_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(corundum_bulk_modulus, corundum_shear_modulus, corundum_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(corundum_bulk_modulus, corundum_shear_modulus, corundum_compliance_tensor_from_corundum_stiffness_tensor);

    // Calcite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> calcite_compliance_tensor_from_calcite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(calcite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > calcite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(calcite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > calcite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(calcite_compliance_tensor_from_calcite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double calcite_k_vrh = 0.5 * (calcite_k_mu_voigt.first.value + calcite_k_mu_reuss.first.value);
    std::cout << "calcite bulk modulus (ref)           : " << calcite_bulk_modulus << std::endl;
    std::cout << "calcite bulk modulus (voigt)         : " << calcite_k_mu_voigt.first.value << std::endl;
    std::cout << "calcite bulk modulus (ruess)         : " << calcite_k_mu_reuss.first.value << std::endl;
    std::cout << "calcite bulk modulus vrh difference  : " << std::abs(calcite_k_vrh - calcite_bulk_modulus) << std::endl;
    double calcite_mu_vrh = 0.5 * (calcite_k_mu_voigt.second.value + calcite_k_mu_reuss.second.value);
    std::cout << "calcite shear modulus (ref)          : " << calcite_shear_modulus << std::endl;
    std::cout << "calcite shear modulus (voigt)        : " << calcite_k_mu_voigt.second.value << std::endl;
    std::cout << "calcite shear modulus (ruess)        : " << calcite_k_mu_reuss.second.value << std::endl;
    std::cout << "calcite shear modulus vrh difference : " << std::abs(calcite_mu_vrh - calcite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(calcite_bulk_modulus, calcite_shear_modulus, calcite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(calcite_bulk_modulus, calcite_shear_modulus, calcite_compliance_tensor_from_calcite_stiffness_tensor);

    // Quartz
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> quartz_compliance_tensor_from_quartz_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(quartz_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > quartz_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(quartz_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > quartz_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(quartz_compliance_tensor_from_quartz_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double quartz_k_vrh = 0.5 * (quartz_k_mu_voigt.first.value + quartz_k_mu_reuss.first.value);
    std::cout << "quartz bulk modulus (ref)           : " << quartz_bulk_modulus << std::endl;
    std::cout << "quartz bulk modulus (voigt)         : " << quartz_k_mu_voigt.first.value << std::endl;
    std::cout << "quartz bulk modulus (ruess)         : " << quartz_k_mu_reuss.first.value << std::endl;
    std::cout << "quartz bulk modulus vrh difference  : " << std::abs(quartz_k_vrh - quartz_bulk_modulus) << std::endl;
    double quartz_mu_vrh = 0.5 * (quartz_k_mu_voigt.second.value + quartz_k_mu_reuss.second.value);
    std::cout << "quartz shear modulus (ref)          : " << quartz_shear_modulus << std::endl;
    std::cout << "quartz shear modulus (voigt)        : " << quartz_k_mu_voigt.second.value << std::endl;
    std::cout << "quartz shear modulus (ruess)        : " << quartz_k_mu_reuss.second.value << std::endl;
    std::cout << "quartz shear modulus vrh difference : " << std::abs(quartz_mu_vrh - quartz_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(quartz_bulk_modulus, quartz_shear_modulus, quartz_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(quartz_bulk_modulus, quartz_shear_modulus, quartz_compliance_tensor_from_quartz_stiffness_tensor);

    // Tourmaline
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> tourmaline_compliance_tensor_from_tourmaline_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(tourmaline_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > tourmaline_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(tourmaline_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > tourmaline_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(tourmaline_compliance_tensor_from_tourmaline_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double tourmaline_k_vrh = 0.5 * (tourmaline_k_mu_voigt.first.value + tourmaline_k_mu_reuss.first.value);
    std::cout << "tourmaline bulk modulus (ref)           : " << tourmaline_bulk_modulus << std::endl;
    std::cout << "tourmaline bulk modulus (voigt)         : " << tourmaline_k_mu_voigt.first.value << std::endl;
    std::cout << "tourmaline bulk modulus (ruess)         : " << tourmaline_k_mu_reuss.first.value << std::endl;
    std::cout << "tourmaline bulk modulus vrh difference  : " << std::abs(tourmaline_k_vrh - tourmaline_bulk_modulus) << std::endl;
    double tourmaline_mu_vrh = 0.5 * (tourmaline_k_mu_voigt.second.value + tourmaline_k_mu_reuss.second.value);
    std::cout << "tourmaline shear modulus (ref)          : " << tourmaline_shear_modulus << std::endl;
    std::cout << "tourmaline shear modulus (voigt)        : " << tourmaline_k_mu_voigt.second.value << std::endl;
    std::cout << "tourmaline shear modulus (ruess)        : " << tourmaline_k_mu_reuss.second.value << std::endl;
    std::cout << "tourmaline shear modulus vrh difference : " << std::abs(tourmaline_mu_vrh - tourmaline_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(tourmaline_bulk_modulus, tourmaline_shear_modulus, tourmaline_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(tourmaline_bulk_modulus, tourmaline_shear_modulus, tourmaline_compliance_tensor_from_tourmaline_stiffness_tensor);

    // Beryl
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> beryl_compliance_tensor_from_beryl_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(beryl_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > beryl_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(beryl_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > beryl_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(beryl_compliance_tensor_from_beryl_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double beryl_k_vrh = 0.5 * (beryl_k_mu_voigt.first.value + beryl_k_mu_reuss.first.value);
    std::cout << "beryl bulk modulus (ref)           : " << beryl_bulk_modulus << std::endl;
    std::cout << "beryl bulk modulus (voigt)         : " << beryl_k_mu_voigt.first.value << std::endl;
    std::cout << "beryl bulk modulus (ruess)         : " << beryl_k_mu_reuss.first.value << std::endl;
    std::cout << "beryl bulk modulus vrh difference  : " << std::abs(beryl_k_vrh - beryl_bulk_modulus) << std::endl;
    double beryl_mu_vrh = 0.5 * (beryl_k_mu_voigt.second.value + beryl_k_mu_reuss.second.value);
    std::cout << "beryl shear modulus (ref)          : " << beryl_shear_modulus << std::endl;
    std::cout << "beryl shear modulus (voigt)        : " << beryl_k_mu_voigt.second.value << std::endl;
    std::cout << "beryl shear modulus (ruess)        : " << beryl_k_mu_reuss.second.value << std::endl;
    std::cout << "beryl shear modulus vrh difference : " << std::abs(beryl_mu_vrh - beryl_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(beryl_bulk_modulus, beryl_shear_modulus, beryl_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(beryl_bulk_modulus, beryl_shear_modulus, beryl_compliance_tensor_from_beryl_stiffness_tensor);

    // Graphite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> graphite_compliance_tensor_from_graphite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(graphite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > graphite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(graphite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > graphite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(graphite_compliance_tensor_from_graphite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double graphite_k_vrh = 0.5 * (graphite_k_mu_voigt.first.value + graphite_k_mu_reuss.first.value);
    std::cout << "graphite bulk modulus (ref)           : " << graphite_bulk_modulus << std::endl;
    std::cout << "graphite bulk modulus (voigt)         : " << graphite_k_mu_voigt.first.value << std::endl;
    std::cout << "graphite bulk modulus (ruess)         : " << graphite_k_mu_reuss.first.value << std::endl;
    std::cout << "graphite bulk modulus vrh difference  : " << std::abs(graphite_k_vrh - graphite_bulk_modulus) << std::endl;
    double graphite_mu_vrh = 0.5 * (graphite_k_mu_voigt.second.value + graphite_k_mu_reuss.second.value);
    std::cout << "graphite shear modulus (ref)          : " << graphite_shear_modulus << std::endl;
    std::cout << "graphite shear modulus (voigt)        : " << graphite_k_mu_voigt.second.value << std::endl;
    std::cout << "graphite shear modulus (ruess)        : " << graphite_k_mu_reuss.second.value << std::endl;
    std::cout << "graphite shear modulus vrh difference : " << std::abs(graphite_mu_vrh - graphite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(graphite_bulk_modulus, graphite_shear_modulus, graphite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(graphite_bulk_modulus, graphite_shear_modulus, graphite_compliance_tensor_from_graphite_stiffness_tensor);

    // Wusite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> wusite_compliance_tensor_from_wusite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(wusite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > wusite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(wusite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > wusite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(wusite_compliance_tensor_from_wusite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double wusite_k_vrh = 0.5 * (wusite_k_mu_voigt.first.value + wusite_k_mu_reuss.first.value);
    std::cout << "wusite bulk modulus (ref)           : " << wusite_bulk_modulus << std::endl;
    std::cout << "wusite bulk modulus (voigt)         : " << wusite_k_mu_voigt.first.value << std::endl;
    std::cout << "wusite bulk modulus (ruess)         : " << wusite_k_mu_reuss.first.value << std::endl;
    std::cout << "wusite bulk modulus vrh difference  : " << std::abs(wusite_k_vrh - wusite_bulk_modulus) << std::endl;
    double wusite_mu_vrh = 0.5 * (wusite_k_mu_voigt.second.value + wusite_k_mu_reuss.second.value);
    std::cout << "wusite shear modulus (ref)          : " << wusite_shear_modulus << std::endl;
    std::cout << "wusite shear modulus (voigt)        : " << wusite_k_mu_voigt.second.value << std::endl;
    std::cout << "wusite shear modulus (ruess)        : " << wusite_k_mu_reuss.second.value << std::endl;
    std::cout << "wusite shear modulus vrh difference : " << std::abs(wusite_mu_vrh - wusite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(wusite_bulk_modulus, wusite_shear_modulus, wusite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(wusite_bulk_modulus, wusite_shear_modulus, wusite_compliance_tensor_from_wusite_stiffness_tensor);

    // Manganosite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> manganosite_compliance_tensor_from_manganosite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(manganosite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > manganosite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(manganosite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > manganosite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(manganosite_compliance_tensor_from_manganosite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double manganosite_k_vrh = 0.5 * (manganosite_k_mu_voigt.first.value + manganosite_k_mu_reuss.first.value);
    std::cout << "manganosite bulk modulus (ref)           : " << manganosite_bulk_modulus << std::endl;
    std::cout << "manganosite bulk modulus (voigt)         : " << manganosite_k_mu_voigt.first.value << std::endl;
    std::cout << "manganosite bulk modulus (ruess)         : " << manganosite_k_mu_reuss.first.value << std::endl;
    std::cout << "manganosite bulk modulus vrh difference  : " << std::abs(manganosite_k_vrh - manganosite_bulk_modulus) << std::endl;
    double manganosite_mu_vrh = 0.5 * (manganosite_k_mu_voigt.second.value + manganosite_k_mu_reuss.second.value);
    std::cout << "manganosite shear modulus (ref)          : " << manganosite_shear_modulus << std::endl;
    std::cout << "manganosite shear modulus (voigt)        : " << manganosite_k_mu_voigt.second.value << std::endl;
    std::cout << "manganosite shear modulus (ruess)        : " << manganosite_k_mu_reuss.second.value << std::endl;
    std::cout << "manganosite shear modulus vrh difference : " << std::abs(manganosite_mu_vrh - manganosite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(manganosite_bulk_modulus, manganosite_shear_modulus, manganosite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(manganosite_bulk_modulus, manganosite_shear_modulus, manganosite_compliance_tensor_from_manganosite_stiffness_tensor);

    // Periclase
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> periclase_compliance_tensor_from_periclase_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(periclase_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > periclase_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(periclase_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > periclase_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(periclase_compliance_tensor_from_periclase_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double periclase_k_vrh = 0.5 * (periclase_k_mu_voigt.first.value + periclase_k_mu_reuss.first.value);
    std::cout << "periclase bulk modulus (ref)           : " << periclase_bulk_modulus << std::endl;
    std::cout << "periclase bulk modulus (voigt)         : " << periclase_k_mu_voigt.first.value << std::endl;
    std::cout << "periclase bulk modulus (ruess)         : " << periclase_k_mu_reuss.first.value << std::endl;
    std::cout << "periclase bulk modulus vrh difference  : " << std::abs(periclase_k_vrh - periclase_bulk_modulus) << std::endl;
    double periclase_mu_vrh = 0.5 * (periclase_k_mu_voigt.second.value + periclase_k_mu_reuss.second.value);
    std::cout << "periclase shear modulus (ref)          : " << periclase_shear_modulus << std::endl;
    std::cout << "periclase shear modulus (voigt)        : " << periclase_k_mu_voigt.second.value << std::endl;
    std::cout << "periclase shear modulus (ruess)        : " << periclase_k_mu_reuss.second.value << std::endl;
    std::cout << "periclase shear modulus vrh difference : " << std::abs(periclase_mu_vrh - periclase_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(periclase_bulk_modulus, periclase_shear_modulus, periclase_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(periclase_bulk_modulus, periclase_shear_modulus, periclase_compliance_tensor_from_periclase_stiffness_tensor);

    // Magnetite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> magnetite_compliance_tensor_from_magnetite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(magnetite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > magnetite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(magnetite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > magnetite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(magnetite_compliance_tensor_from_magnetite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double magnetite_k_vrh = 0.5 * (magnetite_k_mu_voigt.first.value + magnetite_k_mu_reuss.first.value);
    std::cout << "magnetite bulk modulus (ref)           : " << magnetite_bulk_modulus << std::endl;
    std::cout << "magnetite bulk modulus (voigt)         : " << magnetite_k_mu_voigt.first.value << std::endl;
    std::cout << "magnetite bulk modulus (ruess)         : " << magnetite_k_mu_reuss.first.value << std::endl;
    std::cout << "magnetite bulk modulus vrh difference  : " << std::abs(magnetite_k_vrh - magnetite_bulk_modulus) << std::endl;
    double magnetite_mu_vrh = 0.5 * (magnetite_k_mu_voigt.second.value + magnetite_k_mu_reuss.second.value);
    std::cout << "magnetite shear modulus (ref)          : " << magnetite_shear_modulus << std::endl;
    std::cout << "magnetite shear modulus (voigt)        : " << magnetite_k_mu_voigt.second.value << std::endl;
    std::cout << "magnetite shear modulus (ruess)        : " << magnetite_k_mu_reuss.second.value << std::endl;
    std::cout << "magnetite shear modulus vrh difference : " << std::abs(magnetite_mu_vrh - magnetite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(magnetite_bulk_modulus, magnetite_shear_modulus, magnetite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(magnetite_bulk_modulus, magnetite_shear_modulus, magnetite_compliance_tensor_from_magnetite_stiffness_tensor);

    // Chromite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> chromite_compliance_tensor_from_chromite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(chromite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > chromite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(chromite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > chromite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(chromite_compliance_tensor_from_chromite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double chromite_k_vrh = 0.5 * (chromite_k_mu_voigt.first.value + chromite_k_mu_reuss.first.value);
    std::cout << "chromite bulk modulus (ref)           : " << chromite_bulk_modulus << std::endl;
    std::cout << "chromite bulk modulus (voigt)         : " << chromite_k_mu_voigt.first.value << std::endl;
    std::cout << "chromite bulk modulus (ruess)         : " << chromite_k_mu_reuss.first.value << std::endl;
    std::cout << "chromite bulk modulus vrh difference  : " << std::abs(chromite_k_vrh - chromite_bulk_modulus) << std::endl;
    double chromite_mu_vrh = 0.5 * (chromite_k_mu_voigt.second.value + chromite_k_mu_reuss.second.value);
    std::cout << "chromite shear modulus (ref)          : " << chromite_shear_modulus << std::endl;
    std::cout << "chromite shear modulus (voigt)        : " << chromite_k_mu_voigt.second.value << std::endl;
    std::cout << "chromite shear modulus (ruess)        : " << chromite_k_mu_reuss.second.value << std::endl;
    std::cout << "chromite shear modulus vrh difference : " << std::abs(chromite_mu_vrh - chromite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(chromite_bulk_modulus, chromite_shear_modulus, chromite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(chromite_bulk_modulus, chromite_shear_modulus, chromite_compliance_tensor_from_chromite_stiffness_tensor);

    // Spinel
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> spinel_compliance_tensor_from_spinel_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(spinel_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > spinel_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(spinel_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > spinel_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(spinel_compliance_tensor_from_spinel_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double spinel_k_vrh = 0.5 * (spinel_k_mu_voigt.first.value + spinel_k_mu_reuss.first.value);
    std::cout << "spinel bulk modulus (ref)           : " << spinel_bulk_modulus << std::endl;
    std::cout << "spinel bulk modulus (voigt)         : " << spinel_k_mu_voigt.first.value << std::endl;
    std::cout << "spinel bulk modulus (ruess)         : " << spinel_k_mu_reuss.first.value << std::endl;
    std::cout << "spinel bulk modulus vrh difference  : " << std::abs(spinel_k_vrh - spinel_bulk_modulus) << std::endl;
    double spinel_mu_vrh = 0.5 * (spinel_k_mu_voigt.second.value + spinel_k_mu_reuss.second.value);
    std::cout << "spinel shear modulus (ref)          : " << spinel_shear_modulus << std::endl;
    std::cout << "spinel shear modulus (voigt)        : " << spinel_k_mu_voigt.second.value << std::endl;
    std::cout << "spinel shear modulus (ruess)        : " << spinel_k_mu_reuss.second.value << std::endl;
    std::cout << "spinel shear modulus vrh difference : " << std::abs(spinel_mu_vrh - spinel_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(spinel_bulk_modulus, spinel_shear_modulus, spinel_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(spinel_bulk_modulus, spinel_shear_modulus, spinel_compliance_tensor_from_spinel_stiffness_tensor);

    // Pyrite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> pyrite_compliance_tensor_from_pyrite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(pyrite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > pyrite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(pyrite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > pyrite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(pyrite_compliance_tensor_from_pyrite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double pyrite_k_vrh = 0.5 * (pyrite_k_mu_voigt.first.value + pyrite_k_mu_reuss.first.value);
    std::cout << "pyrite bulk modulus (ref)           : " << pyrite_bulk_modulus << std::endl;
    std::cout << "pyrite bulk modulus (voigt)         : " << pyrite_k_mu_voigt.first.value << std::endl;
    std::cout << "pyrite bulk modulus (ruess)         : " << pyrite_k_mu_reuss.first.value << std::endl;
    std::cout << "pyrite bulk modulus vrh difference  : " << std::abs(pyrite_k_vrh - pyrite_bulk_modulus) << std::endl;
    double pyrite_mu_vrh = 0.5 * (pyrite_k_mu_voigt.second.value + pyrite_k_mu_reuss.second.value);
    std::cout << "pyrite shear modulus (ref)          : " << pyrite_shear_modulus << std::endl;
    std::cout << "pyrite shear modulus (voigt)        : " << pyrite_k_mu_voigt.second.value << std::endl;
    std::cout << "pyrite shear modulus (ruess)        : " << pyrite_k_mu_reuss.second.value << std::endl;
    std::cout << "pyrite shear modulus vrh difference : " << std::abs(pyrite_mu_vrh - pyrite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(pyrite_bulk_modulus, pyrite_shear_modulus, pyrite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(pyrite_bulk_modulus, pyrite_shear_modulus, pyrite_compliance_tensor_from_pyrite_stiffness_tensor);

    // Galena
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> galena_compliance_tensor_from_galena_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(galena_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > galena_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(galena_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > galena_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(galena_compliance_tensor_from_galena_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double galena_k_vrh = 0.5 * (galena_k_mu_voigt.first.value + galena_k_mu_reuss.first.value);
    std::cout << "galena bulk modulus (ref)           : " << galena_bulk_modulus << std::endl;
    std::cout << "galena bulk modulus (voigt)         : " << galena_k_mu_voigt.first.value << std::endl;
    std::cout << "galena bulk modulus (ruess)         : " << galena_k_mu_reuss.first.value << std::endl;
    std::cout << "galena bulk modulus vrh difference  : " << std::abs(galena_k_vrh - galena_bulk_modulus) << std::endl;
    double galena_mu_vrh = 0.5 * (galena_k_mu_voigt.second.value + galena_k_mu_reuss.second.value);
    std::cout << "galena shear modulus (ref)          : " << galena_shear_modulus << std::endl;
    std::cout << "galena shear modulus (voigt)        : " << galena_k_mu_voigt.second.value << std::endl;
    std::cout << "galena shear modulus (ruess)        : " << galena_k_mu_reuss.second.value << std::endl;
    std::cout << "galena shear modulus vrh difference : " << std::abs(galena_mu_vrh - galena_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(galena_bulk_modulus, galena_shear_modulus, galena_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(galena_bulk_modulus, galena_shear_modulus, galena_compliance_tensor_from_galena_stiffness_tensor);

    // Sphalerite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> sphalerite_compliance_tensor_from_sphalerite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(sphalerite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > sphalerite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(sphalerite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > sphalerite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(sphalerite_compliance_tensor_from_sphalerite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double sphalerite_k_vrh = 0.5 * (sphalerite_k_mu_voigt.first.value + sphalerite_k_mu_reuss.first.value);
    std::cout << "sphalerite bulk modulus (ref)           : " << sphalerite_bulk_modulus << std::endl;
    std::cout << "sphalerite bulk modulus (voigt)         : " << sphalerite_k_mu_voigt.first.value << std::endl;
    std::cout << "sphalerite bulk modulus (ruess)         : " << sphalerite_k_mu_reuss.first.value << std::endl;
    std::cout << "sphalerite bulk modulus vrh difference  : " << std::abs(sphalerite_k_vrh - sphalerite_bulk_modulus) << std::endl;
    double sphalerite_mu_vrh = 0.5 * (sphalerite_k_mu_voigt.second.value + sphalerite_k_mu_reuss.second.value);
    std::cout << "sphalerite shear modulus (ref)          : " << sphalerite_shear_modulus << std::endl;
    std::cout << "sphalerite shear modulus (voigt)        : " << sphalerite_k_mu_voigt.second.value << std::endl;
    std::cout << "sphalerite shear modulus (ruess)        : " << sphalerite_k_mu_reuss.second.value << std::endl;
    std::cout << "sphalerite shear modulus vrh difference : " << std::abs(sphalerite_mu_vrh - sphalerite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(sphalerite_bulk_modulus, sphalerite_shear_modulus, sphalerite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(sphalerite_bulk_modulus, sphalerite_shear_modulus, sphalerite_compliance_tensor_from_sphalerite_stiffness_tensor);

    // Fluorite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> fluorite_compliance_tensor_from_fluorite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(fluorite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > fluorite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(fluorite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > fluorite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(fluorite_compliance_tensor_from_fluorite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double fluorite_k_vrh = 0.5 * (fluorite_k_mu_voigt.first.value + fluorite_k_mu_reuss.first.value);
    std::cout << "fluorite bulk modulus (ref)           : " << fluorite_bulk_modulus << std::endl;
    std::cout << "fluorite bulk modulus (voigt)         : " << fluorite_k_mu_voigt.first.value << std::endl;
    std::cout << "fluorite bulk modulus (ruess)         : " << fluorite_k_mu_reuss.first.value << std::endl;
    std::cout << "fluorite bulk modulus vrh difference  : " << std::abs(fluorite_k_vrh - fluorite_bulk_modulus) << std::endl;
    double fluorite_mu_vrh = 0.5 * (fluorite_k_mu_voigt.second.value + fluorite_k_mu_reuss.second.value);
    std::cout << "fluorite shear modulus (ref)          : " << fluorite_shear_modulus << std::endl;
    std::cout << "fluorite shear modulus (voigt)        : " << fluorite_k_mu_voigt.second.value << std::endl;
    std::cout << "fluorite shear modulus (ruess)        : " << fluorite_k_mu_reuss.second.value << std::endl;
    std::cout << "fluorite shear modulus vrh difference : " << std::abs(fluorite_mu_vrh - fluorite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(fluorite_bulk_modulus, fluorite_shear_modulus, fluorite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(fluorite_bulk_modulus, fluorite_shear_modulus, fluorite_compliance_tensor_from_fluorite_stiffness_tensor);

    // Halite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> halite_compliance_tensor_from_halite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(halite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > halite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(halite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > halite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(halite_compliance_tensor_from_halite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double halite_k_vrh = 0.5 * (halite_k_mu_voigt.first.value + halite_k_mu_reuss.first.value);
    std::cout << "halite bulk modulus (ref)           : " << halite_bulk_modulus << std::endl;
    std::cout << "halite bulk modulus (voigt)         : " << halite_k_mu_voigt.first.value << std::endl;
    std::cout << "halite bulk modulus (ruess)         : " << halite_k_mu_reuss.first.value << std::endl;
    std::cout << "halite bulk modulus vrh difference  : " << std::abs(halite_k_vrh - halite_bulk_modulus) << std::endl;
    double halite_mu_vrh = 0.5 * (halite_k_mu_voigt.second.value + halite_k_mu_reuss.second.value);
    std::cout << "halite shear modulus (ref)          : " << halite_shear_modulus << std::endl;
    std::cout << "halite shear modulus (voigt)        : " << halite_k_mu_voigt.second.value << std::endl;
    std::cout << "halite shear modulus (ruess)        : " << halite_k_mu_reuss.second.value << std::endl;
    std::cout << "halite shear modulus vrh difference : " << std::abs(halite_mu_vrh - halite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(halite_bulk_modulus, halite_shear_modulus, halite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(halite_bulk_modulus, halite_shear_modulus, halite_compliance_tensor_from_halite_stiffness_tensor);

    // Sylvite
    std::cout << "" << std::endl;
    mpc::core::ComplianceTensor<double> sylvite_compliance_tensor_from_sylvite_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(sylvite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > sylvite_k_mu_voigt = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(sylvite_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > sylvite_k_mu_reuss = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(sylvite_compliance_tensor_from_sylvite_stiffness_tensor);
    // compare mineral data values for K and mu to vrh from above
    double sylvite_k_vrh = 0.5 * (sylvite_k_mu_voigt.first.value + sylvite_k_mu_reuss.first.value);
    std::cout << "sylvite bulk modulus (ref)           : " << sylvite_bulk_modulus << std::endl;
    std::cout << "sylvite bulk modulus (voigt)         : " << sylvite_k_mu_voigt.first.value << std::endl;
    std::cout << "sylvite bulk modulus (ruess)         : " << sylvite_k_mu_reuss.first.value << std::endl;
    std::cout << "sylvite bulk modulus vrh difference  : " << std::abs(sylvite_k_vrh - sylvite_bulk_modulus) << std::endl;
    double sylvite_mu_vrh = 0.5 * (sylvite_k_mu_voigt.second.value + sylvite_k_mu_reuss.second.value);
    std::cout << "sylvite shear modulus (ref)          : " << sylvite_shear_modulus << std::endl;
    std::cout << "sylvite shear modulus (voigt)        : " << sylvite_k_mu_voigt.second.value << std::endl;
    std::cout << "sylvite shear modulus (ruess)        : " << sylvite_k_mu_reuss.second.value << std::endl;
    std::cout << "sylvite shear modulus vrh difference : " << std::abs(sylvite_mu_vrh - sylvite_shear_modulus) << std::endl;
    // NOTE: careful; this function will modify the tensor data!!!
    mpc::rockphysics::MakeIsotropicStiffnessTensor(sylvite_bulk_modulus, sylvite_shear_modulus, sylvite_stiffness_tensor);
    mpc::rockphysics::MakeIsotropicComplianceTensor(sylvite_bulk_modulus, sylvite_shear_modulus, sylvite_compliance_tensor_from_sylvite_stiffness_tensor);

    // TODO: stress tensor invariant / contraction
    // TODO: strain tensor invariant / contraction
    // TODO: dilational stiffness tensor invariant / contraction
    // TODO: Voigt stiffness tensor invariant / contraction
    // TODO: hydrostatic pressure compliance tensor invariant / contraction
    // TODO: Ruess compliance tensor invariant / contraction

}
