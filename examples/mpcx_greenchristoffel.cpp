#include "mpcx_greenchristoffel.hpp"

// c++
#include <iostream>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/core/csrelationship.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
//#include <mpc/rockphysics/tensorinvariants.hpp>
#include <mpc/mechanics/greenchristoffel.hpp>

void mpcexamples::mpcGreenChristoffel() {
    /** Green-Christoffel */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::utilities::PrintTensorComponents<double,1> print_tensor_components_double_1_fo;
    mpc::utilities::PrintTensorComponents<double,2> print_tensor_components_double_2_fo;
    mpc::utilities::PrintTensorComponents<double,4> print_tensor_components_double_4_fo;

    // mineral properties
    // Augite
    mpc::core::SymmetryGroupEnumeration augite_symmetry_group_enum = mpc::data::AugiteSymmetryClass();
    auto augite_density = mpc::data::AugiteDensity<double>();
    auto augite_C11 = mpc::data::AugiteC11<double>();
    auto augite_C12 = mpc::data::AugiteC12<double>();
    auto augite_C13 = mpc::data::AugiteC13<double>();
    auto augite_C14 = mpc::data::AugiteC14<double>();
    auto augite_C15 = mpc::data::AugiteC15<double>();
    auto augite_C16 = mpc::data::AugiteC16<double>();
    auto augite_C22 = mpc::data::AugiteC22<double>();
    auto augite_C23 = mpc::data::AugiteC23<double>();
    auto augite_C24 = mpc::data::AugiteC24<double>();
    auto augite_C25 = mpc::data::AugiteC25<double>();
    auto augite_C26 = mpc::data::AugiteC26<double>();
    auto augite_C33 = mpc::data::AugiteC33<double>();
    auto augite_C34 = mpc::data::AugiteC34<double>();
    auto augite_C35 = mpc::data::AugiteC35<double>();
    auto augite_C36 = mpc::data::AugiteC36<double>();
    auto augite_C44 = mpc::data::AugiteC44<double>();
    auto augite_C45 = mpc::data::AugiteC45<double>();
    auto augite_C46 = mpc::data::AugiteC46<double>();
    auto augite_C55 = mpc::data::AugiteC55<double>();
    auto augite_C56 = mpc::data::AugiteC56<double>();
    auto augite_C66 = mpc::data::AugiteC66<double>();
    auto augite_bulk_modulus = mpc::data::AugiteBulkModulus<double>();
    auto augite_shear_modulus = mpc::data::AugiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> augite_stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();

    // Albite
    mpc::core::SymmetryGroupEnumeration albite_symmetry_group_enum = mpc::data::AlbiteSymmetryClass();
    auto albite_density = mpc::data::AlbiteDensity<double>();
    auto albite_C11 = mpc::data::AlbiteC11<double>();
    auto albite_C12 = mpc::data::AlbiteC12<double>();
    auto albite_C13 = mpc::data::AlbiteC13<double>();
    auto albite_C14 = mpc::data::AlbiteC14<double>();
    auto albite_C15 = mpc::data::AlbiteC15<double>();
    auto albite_C16 = mpc::data::AlbiteC16<double>();
    auto albite_C22 = mpc::data::AlbiteC22<double>();
    auto albite_C23 = mpc::data::AlbiteC23<double>();
    auto albite_C24 = mpc::data::AlbiteC24<double>();
    auto albite_C25 = mpc::data::AlbiteC25<double>();
    auto albite_C26 = mpc::data::AlbiteC26<double>();
    auto albite_C33 = mpc::data::AlbiteC33<double>();
    auto albite_C34 = mpc::data::AlbiteC34<double>();
    auto albite_C35 = mpc::data::AlbiteC35<double>();
    auto albite_C36 = mpc::data::AlbiteC36<double>();
    auto albite_C44 = mpc::data::AlbiteC44<double>();
    auto albite_C45 = mpc::data::AlbiteC45<double>();
    auto albite_C46 = mpc::data::AlbiteC46<double>();
    auto albite_C55 = mpc::data::AlbiteC55<double>();
    auto albite_C56 = mpc::data::AlbiteC56<double>();
    auto albite_C66 = mpc::data::AlbiteC66<double>();
    auto albite_bulk_modulus = mpc::data::AlbiteBulkModulus<double>();
    auto albite_shear_modulus = mpc::data::AlbiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> albite_stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();

    // Anorthite
    mpc::core::SymmetryGroupEnumeration anorthite_symmetry_group_enum = mpc::data::AnorthiteSymmetryClass();
    auto anorthite_density = mpc::data::AnorthiteDensity<double>();
    auto anorthite_C11 = mpc::data::AnorthiteC11<double>();
    auto anorthite_C12 = mpc::data::AnorthiteC12<double>();
    auto anorthite_C13 = mpc::data::AnorthiteC13<double>();
    auto anorthite_C14 = mpc::data::AnorthiteC14<double>();
    auto anorthite_C15 = mpc::data::AnorthiteC15<double>();
    auto anorthite_C16 = mpc::data::AnorthiteC16<double>();
    auto anorthite_C22 = mpc::data::AnorthiteC22<double>();
    auto anorthite_C23 = mpc::data::AnorthiteC23<double>();
    auto anorthite_C24 = mpc::data::AnorthiteC24<double>();
    auto anorthite_C25 = mpc::data::AnorthiteC25<double>();
    auto anorthite_C26 = mpc::data::AnorthiteC26<double>();
    auto anorthite_C33 = mpc::data::AnorthiteC33<double>();
    auto anorthite_C34 = mpc::data::AnorthiteC34<double>();
    auto anorthite_C35 = mpc::data::AnorthiteC35<double>();
    auto anorthite_C36 = mpc::data::AnorthiteC36<double>();
    auto anorthite_C44 = mpc::data::AnorthiteC44<double>();
    auto anorthite_C45 = mpc::data::AnorthiteC45<double>();
    auto anorthite_C46 = mpc::data::AnorthiteC46<double>();
    auto anorthite_C55 = mpc::data::AnorthiteC55<double>();
    auto anorthite_C56 = mpc::data::AnorthiteC56<double>();
    auto anorthite_C66 = mpc::data::AnorthiteC66<double>();
    auto anorthite_bulk_modulus = mpc::data::AnorthiteBulkModulus<double>();
    auto anorthite_shear_modulus = mpc::data::AnorthiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> anorthite_stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();

    // Labradorite
    mpc::core::SymmetryGroupEnumeration labradorite_symmetry_group_enum = mpc::data::LabradoriteSymmetryClass();
    auto labradorite_density = mpc::data::LabradoriteDensity<double>();
    auto labradorite_C11 = mpc::data::LabradoriteC11<double>();
    auto labradorite_C12 = mpc::data::LabradoriteC12<double>();
    auto labradorite_C13 = mpc::data::LabradoriteC13<double>();
    auto labradorite_C14 = mpc::data::LabradoriteC14<double>();
    auto labradorite_C15 = mpc::data::LabradoriteC15<double>();
    auto labradorite_C16 = mpc::data::LabradoriteC16<double>();
    auto labradorite_C22 = mpc::data::LabradoriteC22<double>();
    auto labradorite_C23 = mpc::data::LabradoriteC23<double>();
    auto labradorite_C24 = mpc::data::LabradoriteC24<double>();
    auto labradorite_C25 = mpc::data::LabradoriteC25<double>();
    auto labradorite_C26 = mpc::data::LabradoriteC26<double>();
    auto labradorite_C33 = mpc::data::LabradoriteC33<double>();
    auto labradorite_C34 = mpc::data::LabradoriteC34<double>();
    auto labradorite_C35 = mpc::data::LabradoriteC35<double>();
    auto labradorite_C36 = mpc::data::LabradoriteC36<double>();
    auto labradorite_C44 = mpc::data::LabradoriteC44<double>();
    auto labradorite_C45 = mpc::data::LabradoriteC45<double>();
    auto labradorite_C46 = mpc::data::LabradoriteC46<double>();
    auto labradorite_C55 = mpc::data::LabradoriteC55<double>();
    auto labradorite_C56 = mpc::data::LabradoriteC56<double>();
    auto labradorite_C66 = mpc::data::LabradoriteC66<double>();
    auto labradorite_bulk_modulus = mpc::data::LabradoriteBulkModulus<double>();
    auto labradorite_shear_modulus = mpc::data::LabradoriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> labradorite_stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();

    // Microcline
    mpc::core::SymmetryGroupEnumeration microcline_symmetry_group_enum = mpc::data::MicroclineSymmetryClass();
    auto microcline_density = mpc::data::MicroclineDensity<double>();
    auto microcline_C11 = mpc::data::MicroclineC11<double>();
    auto microcline_C12 = mpc::data::MicroclineC12<double>();
    auto microcline_C13 = mpc::data::MicroclineC13<double>();
    auto microcline_C14 = mpc::data::MicroclineC14<double>();
    auto microcline_C15 = mpc::data::MicroclineC15<double>();
    auto microcline_C16 = mpc::data::MicroclineC16<double>();
    auto microcline_C22 = mpc::data::MicroclineC22<double>();
    auto microcline_C23 = mpc::data::MicroclineC23<double>();
    auto microcline_C24 = mpc::data::MicroclineC24<double>();
    auto microcline_C25 = mpc::data::MicroclineC25<double>();
    auto microcline_C26 = mpc::data::MicroclineC26<double>();
    auto microcline_C33 = mpc::data::MicroclineC33<double>();
    auto microcline_C34 = mpc::data::MicroclineC34<double>();
    auto microcline_C35 = mpc::data::MicroclineC35<double>();
    auto microcline_C36 = mpc::data::MicroclineC36<double>();
    auto microcline_C44 = mpc::data::MicroclineC44<double>();
    auto microcline_C45 = mpc::data::MicroclineC45<double>();
    auto microcline_C46 = mpc::data::MicroclineC46<double>();
    auto microcline_C55 = mpc::data::MicroclineC55<double>();
    auto microcline_C56 = mpc::data::MicroclineC56<double>();
    auto microcline_C66 = mpc::data::MicroclineC66<double>();
    auto microcline_bulk_modulus = mpc::data::MicroclineBulkModulus<double>();
    auto microcline_shear_modulus = mpc::data::MicroclineShearModulus<double>();
    mpc::core::StiffnessTensor<double> microcline_stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();

    // Oligoclase
    mpc::core::SymmetryGroupEnumeration oligoclase_symmetry_group_enum = mpc::data::OligoclaseSymmetryClass();
    auto oligoclase_density = mpc::data::OligoclaseDensity<double>();
    auto oligoclase_C11 = mpc::data::OligoclaseC11<double>();
    auto oligoclase_C12 = mpc::data::OligoclaseC12<double>();
    auto oligoclase_C13 = mpc::data::OligoclaseC13<double>();
    auto oligoclase_C14 = mpc::data::OligoclaseC14<double>();
    auto oligoclase_C15 = mpc::data::OligoclaseC15<double>();
    auto oligoclase_C16 = mpc::data::OligoclaseC16<double>();
    auto oligoclase_C22 = mpc::data::OligoclaseC22<double>();
    auto oligoclase_C23 = mpc::data::OligoclaseC23<double>();
    auto oligoclase_C24 = mpc::data::OligoclaseC24<double>();
    auto oligoclase_C25 = mpc::data::OligoclaseC25<double>();
    auto oligoclase_C26 = mpc::data::OligoclaseC26<double>();
    auto oligoclase_C33 = mpc::data::OligoclaseC33<double>();
    auto oligoclase_C34 = mpc::data::OligoclaseC34<double>();
    auto oligoclase_C35 = mpc::data::OligoclaseC35<double>();
    auto oligoclase_C36 = mpc::data::OligoclaseC36<double>();
    auto oligoclase_C44 = mpc::data::OligoclaseC44<double>();
    auto oligoclase_C45 = mpc::data::OligoclaseC45<double>();
    auto oligoclase_C46 = mpc::data::OligoclaseC46<double>();
    auto oligoclase_C55 = mpc::data::OligoclaseC55<double>();
    auto oligoclase_C56 = mpc::data::OligoclaseC56<double>();
    auto oligoclase_C66 = mpc::data::OligoclaseC66<double>();
    auto oligoclase_bulk_modulus = mpc::data::OligoclaseBulkModulus<double>();
    auto oligoclase_shear_modulus = mpc::data::OligoclaseShearModulus<double>();
    mpc::core::StiffnessTensor<double> oligoclase_stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();

    // Coesite
    mpc::core::SymmetryGroupEnumeration coesite_symmetry_group_enum = mpc::data::CoesiteSymmetryClass();
    auto coesite_density = mpc::data::CoesiteDensity<double>();
    auto coesite_C11 = mpc::data::CoesiteC11<double>();
    auto coesite_C12 = mpc::data::CoesiteC12<double>();
    auto coesite_C13 = mpc::data::CoesiteC13<double>();
    auto coesite_C14 = mpc::data::CoesiteC14<double>();
    auto coesite_C15 = mpc::data::CoesiteC15<double>();
    auto coesite_C16 = mpc::data::CoesiteC16<double>();
    auto coesite_C22 = mpc::data::CoesiteC22<double>();
    auto coesite_C23 = mpc::data::CoesiteC23<double>();
    auto coesite_C24 = mpc::data::CoesiteC24<double>();
    auto coesite_C25 = mpc::data::CoesiteC25<double>();
    auto coesite_C26 = mpc::data::CoesiteC26<double>();
    auto coesite_C33 = mpc::data::CoesiteC33<double>();
    auto coesite_C34 = mpc::data::CoesiteC34<double>();
    auto coesite_C35 = mpc::data::CoesiteC35<double>();
    auto coesite_C36 = mpc::data::CoesiteC36<double>();
    auto coesite_C44 = mpc::data::CoesiteC44<double>();
    auto coesite_C45 = mpc::data::CoesiteC45<double>();
    auto coesite_C46 = mpc::data::CoesiteC46<double>();
    auto coesite_C55 = mpc::data::CoesiteC55<double>();
    auto coesite_C56 = mpc::data::CoesiteC56<double>();
    auto coesite_C66 = mpc::data::CoesiteC66<double>();
    auto coesite_bulk_modulus = mpc::data::CoesiteBulkModulus<double>();
    auto coesite_shear_modulus = mpc::data::CoesiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> coesite_stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();

    // Epidote
    mpc::core::SymmetryGroupEnumeration epidote_symmetry_group_enum = mpc::data::EpidoteSymmetryClass();
    auto epidote_density = mpc::data::EpidoteDensity<double>();
    auto epidote_C11 = mpc::data::EpidoteC11<double>();
    auto epidote_C12 = mpc::data::EpidoteC12<double>();
    auto epidote_C13 = mpc::data::EpidoteC13<double>();
    auto epidote_C14 = mpc::data::EpidoteC14<double>();
    auto epidote_C15 = mpc::data::EpidoteC15<double>();
    auto epidote_C16 = mpc::data::EpidoteC16<double>();
    auto epidote_C22 = mpc::data::EpidoteC22<double>();
    auto epidote_C23 = mpc::data::EpidoteC23<double>();
    auto epidote_C24 = mpc::data::EpidoteC24<double>();
    auto epidote_C25 = mpc::data::EpidoteC25<double>();
    auto epidote_C26 = mpc::data::EpidoteC26<double>();
    auto epidote_C33 = mpc::data::EpidoteC33<double>();
    auto epidote_C34 = mpc::data::EpidoteC34<double>();
    auto epidote_C35 = mpc::data::EpidoteC35<double>();
    auto epidote_C36 = mpc::data::EpidoteC36<double>();
    auto epidote_C44 = mpc::data::EpidoteC44<double>();
    auto epidote_C45 = mpc::data::EpidoteC45<double>();
    auto epidote_C46 = mpc::data::EpidoteC46<double>();
    auto epidote_C55 = mpc::data::EpidoteC55<double>();
    auto epidote_C56 = mpc::data::EpidoteC56<double>();
    auto epidote_C66 = mpc::data::EpidoteC66<double>();
    auto epidote_bulk_modulus = mpc::data::EpidoteBulkModulus<double>();
    auto epidote_shear_modulus = mpc::data::EpidoteShearModulus<double>();
    mpc::core::StiffnessTensor<double> epidote_stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();

    // Hornblende
    mpc::core::SymmetryGroupEnumeration hornblende_symmetry_group_enum = mpc::data::HornblendeSymmetryClass();
    auto hornblende_density = mpc::data::HornblendeDensity<double>();
    auto hornblende_C11 = mpc::data::HornblendeC11<double>();
    auto hornblende_C12 = mpc::data::HornblendeC12<double>();
    auto hornblende_C13 = mpc::data::HornblendeC13<double>();
    auto hornblende_C14 = mpc::data::HornblendeC14<double>();
    auto hornblende_C15 = mpc::data::HornblendeC15<double>();
    auto hornblende_C16 = mpc::data::HornblendeC16<double>();
    auto hornblende_C22 = mpc::data::HornblendeC22<double>();
    auto hornblende_C23 = mpc::data::HornblendeC23<double>();
    auto hornblende_C24 = mpc::data::HornblendeC24<double>();
    auto hornblende_C25 = mpc::data::HornblendeC25<double>();
    auto hornblende_C26 = mpc::data::HornblendeC26<double>();
    auto hornblende_C33 = mpc::data::HornblendeC33<double>();
    auto hornblende_C34 = mpc::data::HornblendeC34<double>();
    auto hornblende_C35 = mpc::data::HornblendeC35<double>();
    auto hornblende_C36 = mpc::data::HornblendeC36<double>();
    auto hornblende_C44 = mpc::data::HornblendeC44<double>();
    auto hornblende_C45 = mpc::data::HornblendeC45<double>();
    auto hornblende_C46 = mpc::data::HornblendeC46<double>();
    auto hornblende_C55 = mpc::data::HornblendeC55<double>();
    auto hornblende_C56 = mpc::data::HornblendeC56<double>();
    auto hornblende_C66 = mpc::data::HornblendeC66<double>();
    auto hornblende_bulk_modulus = mpc::data::HornblendeBulkModulus<double>();
    auto hornblende_shear_modulus = mpc::data::HornblendeShearModulus<double>();
    mpc::core::StiffnessTensor<double> hornblende_stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();

    // Muscovite
    mpc::core::SymmetryGroupEnumeration muscovite_symmetry_group_enum = mpc::data::MuscoviteSymmetryClass();
    auto muscovite_density = mpc::data::MuscoviteDensity<double>();
    auto muscovite_C11 = mpc::data::MuscoviteC11<double>();
    auto muscovite_C12 = mpc::data::MuscoviteC12<double>();
    auto muscovite_C13 = mpc::data::MuscoviteC13<double>();
    auto muscovite_C14 = mpc::data::MuscoviteC14<double>();
    auto muscovite_C15 = mpc::data::MuscoviteC15<double>();
    auto muscovite_C16 = mpc::data::MuscoviteC16<double>();
    auto muscovite_C22 = mpc::data::MuscoviteC22<double>();
    auto muscovite_C23 = mpc::data::MuscoviteC23<double>();
    auto muscovite_C24 = mpc::data::MuscoviteC24<double>();
    auto muscovite_C25 = mpc::data::MuscoviteC25<double>();
    auto muscovite_C26 = mpc::data::MuscoviteC26<double>();
    auto muscovite_C33 = mpc::data::MuscoviteC33<double>();
    auto muscovite_C34 = mpc::data::MuscoviteC34<double>();
    auto muscovite_C35 = mpc::data::MuscoviteC35<double>();
    auto muscovite_C36 = mpc::data::MuscoviteC36<double>();
    auto muscovite_C44 = mpc::data::MuscoviteC44<double>();
    auto muscovite_C45 = mpc::data::MuscoviteC45<double>();
    auto muscovite_C46 = mpc::data::MuscoviteC46<double>();
    auto muscovite_C55 = mpc::data::MuscoviteC55<double>();
    auto muscovite_C56 = mpc::data::MuscoviteC56<double>();
    auto muscovite_C66 = mpc::data::MuscoviteC66<double>();
    auto muscovite_bulk_modulus = mpc::data::MuscoviteBulkModulus<double>();
    auto muscovite_shear_modulus = mpc::data::MuscoviteShearModulus<double>();
    mpc::core::StiffnessTensor<double> muscovite_stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();

    // Gypsum
    mpc::core::SymmetryGroupEnumeration gypsum_symmetry_group_enum = mpc::data::GypsumSymmetryClass();
    auto gypsum_density = mpc::data::GypsumDensity<double>();
    auto gypsum_C11 = mpc::data::GypsumC11<double>();
    auto gypsum_C12 = mpc::data::GypsumC12<double>();
    auto gypsum_C13 = mpc::data::GypsumC13<double>();
    auto gypsum_C14 = mpc::data::GypsumC14<double>();
    auto gypsum_C15 = mpc::data::GypsumC15<double>();
    auto gypsum_C16 = mpc::data::GypsumC16<double>();
    auto gypsum_C22 = mpc::data::GypsumC22<double>();
    auto gypsum_C23 = mpc::data::GypsumC23<double>();
    auto gypsum_C24 = mpc::data::GypsumC24<double>();
    auto gypsum_C25 = mpc::data::GypsumC25<double>();
    auto gypsum_C26 = mpc::data::GypsumC26<double>();
    auto gypsum_C33 = mpc::data::GypsumC33<double>();
    auto gypsum_C34 = mpc::data::GypsumC34<double>();
    auto gypsum_C35 = mpc::data::GypsumC35<double>();
    auto gypsum_C36 = mpc::data::GypsumC36<double>();
    auto gypsum_C44 = mpc::data::GypsumC44<double>();
    auto gypsum_C45 = mpc::data::GypsumC45<double>();
    auto gypsum_C46 = mpc::data::GypsumC46<double>();
    auto gypsum_C55 = mpc::data::GypsumC55<double>();
    auto gypsum_C56 = mpc::data::GypsumC56<double>();
    auto gypsum_C66 = mpc::data::GypsumC66<double>();
    auto gypsum_bulk_modulus = mpc::data::GypsumBulkModulus<double>();
    auto gypsum_shear_modulus = mpc::data::GypsumShearModulus<double>();
    mpc::core::StiffnessTensor<double> gypsum_stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();

    // Enstatite
    mpc::core::SymmetryGroupEnumeration enstatite_symmetry_group_enum = mpc::data::EnstatiteSymmetryClass();
    auto enstatite_density = mpc::data::EnstatiteDensity<double>();
    auto enstatite_C11 = mpc::data::EnstatiteC11<double>();
    auto enstatite_C12 = mpc::data::EnstatiteC12<double>();
    auto enstatite_C13 = mpc::data::EnstatiteC13<double>();
    auto enstatite_C14 = mpc::data::EnstatiteC14<double>();
    auto enstatite_C15 = mpc::data::EnstatiteC15<double>();
    auto enstatite_C16 = mpc::data::EnstatiteC16<double>();
    auto enstatite_C22 = mpc::data::EnstatiteC22<double>();
    auto enstatite_C23 = mpc::data::EnstatiteC23<double>();
    auto enstatite_C24 = mpc::data::EnstatiteC24<double>();
    auto enstatite_C25 = mpc::data::EnstatiteC25<double>();
    auto enstatite_C26 = mpc::data::EnstatiteC26<double>();
    auto enstatite_C33 = mpc::data::EnstatiteC33<double>();
    auto enstatite_C34 = mpc::data::EnstatiteC34<double>();
    auto enstatite_C35 = mpc::data::EnstatiteC35<double>();
    auto enstatite_C36 = mpc::data::EnstatiteC36<double>();
    auto enstatite_C44 = mpc::data::EnstatiteC44<double>();
    auto enstatite_C45 = mpc::data::EnstatiteC45<double>();
    auto enstatite_C46 = mpc::data::EnstatiteC46<double>();
    auto enstatite_C55 = mpc::data::EnstatiteC55<double>();
    auto enstatite_C56 = mpc::data::EnstatiteC56<double>();
    auto enstatite_C66 = mpc::data::EnstatiteC66<double>();
    auto enstatite_bulk_modulus = mpc::data::EnstatiteBulkModulus<double>();
    auto enstatite_shear_modulus = mpc::data::EnstatiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> enstatite_stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();

    // Forsterite
    mpc::core::SymmetryGroupEnumeration forsterite_symmetry_group_enum = mpc::data::ForsteriteSymmetryClass();
    auto forsterite_density = mpc::data::ForsteriteDensity<double>();
    auto forsterite_C11 = mpc::data::ForsteriteC11<double>();
    auto forsterite_C12 = mpc::data::ForsteriteC12<double>();
    auto forsterite_C13 = mpc::data::ForsteriteC13<double>();
    auto forsterite_C14 = mpc::data::ForsteriteC14<double>();
    auto forsterite_C15 = mpc::data::ForsteriteC15<double>();
    auto forsterite_C16 = mpc::data::ForsteriteC16<double>();
    auto forsterite_C22 = mpc::data::ForsteriteC22<double>();
    auto forsterite_C23 = mpc::data::ForsteriteC23<double>();
    auto forsterite_C24 = mpc::data::ForsteriteC24<double>();
    auto forsterite_C25 = mpc::data::ForsteriteC25<double>();
    auto forsterite_C26 = mpc::data::ForsteriteC26<double>();
    auto forsterite_C33 = mpc::data::ForsteriteC33<double>();
    auto forsterite_C34 = mpc::data::ForsteriteC34<double>();
    auto forsterite_C35 = mpc::data::ForsteriteC35<double>();
    auto forsterite_C36 = mpc::data::ForsteriteC36<double>();
    auto forsterite_C44 = mpc::data::ForsteriteC44<double>();
    auto forsterite_C45 = mpc::data::ForsteriteC45<double>();
    auto forsterite_C46 = mpc::data::ForsteriteC46<double>();
    auto forsterite_C55 = mpc::data::ForsteriteC55<double>();
    auto forsterite_C56 = mpc::data::ForsteriteC56<double>();
    auto forsterite_C66 = mpc::data::ForsteriteC66<double>();
    auto forsterite_bulk_modulus = mpc::data::ForsteriteBulkModulus<double>();
    auto forsterite_shear_modulus = mpc::data::ForsteriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> forsterite_stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();

    // Fayalite
    mpc::core::SymmetryGroupEnumeration fayalite_symmetry_group_enum = mpc::data::FayaliteSymmetryClass();
    auto fayalite_density = mpc::data::FayaliteDensity<double>();
    auto fayalite_C11 = mpc::data::FayaliteC11<double>();
    auto fayalite_C12 = mpc::data::FayaliteC12<double>();
    auto fayalite_C13 = mpc::data::FayaliteC13<double>();
    auto fayalite_C14 = mpc::data::FayaliteC14<double>();
    auto fayalite_C15 = mpc::data::FayaliteC15<double>();
    auto fayalite_C16 = mpc::data::FayaliteC16<double>();
    auto fayalite_C22 = mpc::data::FayaliteC22<double>();
    auto fayalite_C23 = mpc::data::FayaliteC23<double>();
    auto fayalite_C24 = mpc::data::FayaliteC24<double>();
    auto fayalite_C25 = mpc::data::FayaliteC25<double>();
    auto fayalite_C26 = mpc::data::FayaliteC26<double>();
    auto fayalite_C33 = mpc::data::FayaliteC33<double>();
    auto fayalite_C34 = mpc::data::FayaliteC34<double>();
    auto fayalite_C35 = mpc::data::FayaliteC35<double>();
    auto fayalite_C36 = mpc::data::FayaliteC36<double>();
    auto fayalite_C44 = mpc::data::FayaliteC44<double>();
    auto fayalite_C45 = mpc::data::FayaliteC45<double>();
    auto fayalite_C46 = mpc::data::FayaliteC46<double>();
    auto fayalite_C55 = mpc::data::FayaliteC55<double>();
    auto fayalite_C56 = mpc::data::FayaliteC56<double>();
    auto fayalite_C66 = mpc::data::FayaliteC66<double>();
    auto fayalite_bulk_modulus = mpc::data::FayaliteBulkModulus<double>();
    auto fayalite_shear_modulus = mpc::data::FayaliteShearModulus<double>();
    mpc::core::StiffnessTensor<double> fayalite_stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();

    // Montecellite
    mpc::core::SymmetryGroupEnumeration montecellite_symmetry_group_enum = mpc::data::MontecelliteSymmetryClass();
    auto montecellite_density = mpc::data::MontecelliteDensity<double>();
    auto montecellite_C11 = mpc::data::MontecelliteC11<double>();
    auto montecellite_C12 = mpc::data::MontecelliteC12<double>();
    auto montecellite_C13 = mpc::data::MontecelliteC13<double>();
    auto montecellite_C14 = mpc::data::MontecelliteC14<double>();
    auto montecellite_C15 = mpc::data::MontecelliteC15<double>();
    auto montecellite_C16 = mpc::data::MontecelliteC16<double>();
    auto montecellite_C22 = mpc::data::MontecelliteC22<double>();
    auto montecellite_C23 = mpc::data::MontecelliteC23<double>();
    auto montecellite_C24 = mpc::data::MontecelliteC24<double>();
    auto montecellite_C25 = mpc::data::MontecelliteC25<double>();
    auto montecellite_C26 = mpc::data::MontecelliteC26<double>();
    auto montecellite_C33 = mpc::data::MontecelliteC33<double>();
    auto montecellite_C34 = mpc::data::MontecelliteC34<double>();
    auto montecellite_C35 = mpc::data::MontecelliteC35<double>();
    auto montecellite_C36 = mpc::data::MontecelliteC36<double>();
    auto montecellite_C44 = mpc::data::MontecelliteC44<double>();
    auto montecellite_C45 = mpc::data::MontecelliteC45<double>();
    auto montecellite_C46 = mpc::data::MontecelliteC46<double>();
    auto montecellite_C55 = mpc::data::MontecelliteC55<double>();
    auto montecellite_C56 = mpc::data::MontecelliteC56<double>();
    auto montecellite_C66 = mpc::data::MontecelliteC66<double>();
    auto montecellite_bulk_modulus = mpc::data::MontecelliteBulkModulus<double>();
    auto montecellite_shear_modulus = mpc::data::MontecelliteShearModulus<double>();
    mpc::core::StiffnessTensor<double> montecellite_stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();

    // Andalusite
    mpc::core::SymmetryGroupEnumeration andalusite_symmetry_group_enum = mpc::data::AndalusiteSymmetryClass();
    auto andalusite_density = mpc::data::AndalusiteDensity<double>();
    auto andalusite_C11 = mpc::data::AndalusiteC11<double>();
    auto andalusite_C12 = mpc::data::AndalusiteC12<double>();
    auto andalusite_C13 = mpc::data::AndalusiteC13<double>();
    auto andalusite_C14 = mpc::data::AndalusiteC14<double>();
    auto andalusite_C15 = mpc::data::AndalusiteC15<double>();
    auto andalusite_C16 = mpc::data::AndalusiteC16<double>();
    auto andalusite_C22 = mpc::data::AndalusiteC22<double>();
    auto andalusite_C23 = mpc::data::AndalusiteC23<double>();
    auto andalusite_C24 = mpc::data::AndalusiteC24<double>();
    auto andalusite_C25 = mpc::data::AndalusiteC25<double>();
    auto andalusite_C26 = mpc::data::AndalusiteC26<double >();
    auto andalusite_C33 = mpc::data::AndalusiteC33<double>();
    auto andalusite_C34 = mpc::data::AndalusiteC34<double>();
    auto andalusite_C35 = mpc::data::AndalusiteC35<double>();
    auto andalusite_C36 = mpc::data::AndalusiteC36<double>();
    auto andalusite_C44 = mpc::data::AndalusiteC44<double>();
    auto andalusite_C45 = mpc::data::AndalusiteC45<double>();
    auto andalusite_C46 = mpc::data::AndalusiteC46<double>();
    auto andalusite_C55 = mpc::data::AndalusiteC55<double>();
    auto andalusite_C56 = mpc::data::AndalusiteC56<double>();
    auto andalusite_C66 = mpc::data::AndalusiteC66<double>();
    auto andalusite_bulk_modulus = mpc::data::AndalusiteBulkModulus<double>();
    auto andalusite_shear_modulus = mpc::data::AndalusiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> andalusite_stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();

    // Silimanite
    mpc::core::SymmetryGroupEnumeration silimanite_symmetry_group_enum = mpc::data::SilimaniteSymmetryClass();
    auto silimanite_density = mpc::data::SilimaniteDensity<double>();
    auto silimanite_C11 = mpc::data::SilimaniteC11<double>();
    auto silimanite_C12 = mpc::data::SilimaniteC12<double>();
    auto silimanite_C13 = mpc::data::SilimaniteC13<double>();
    auto silimanite_C14 = mpc::data::SilimaniteC14<double>();
    auto silimanite_C15 = mpc::data::SilimaniteC15<double>();
    auto silimanite_C16 = mpc::data::SilimaniteC16<double>();
    auto silimanite_C22 = mpc::data::SilimaniteC22<double>();
    auto silimanite_C23 = mpc::data::SilimaniteC23<double>();
    auto silimanite_C24 = mpc::data::SilimaniteC24<double>();
    auto silimanite_C25 = mpc::data::SilimaniteC25<double>();
    auto silimanite_C26 = mpc::data::SilimaniteC26<double>();
    auto silimanite_C33 = mpc::data::SilimaniteC33<double>();
    auto silimanite_C34 = mpc::data::SilimaniteC34<double>();
    auto silimanite_C35 = mpc::data::SilimaniteC35<double>();
    auto silimanite_C36 = mpc::data::SilimaniteC36<double>();
    auto silimanite_C44 = mpc::data::SilimaniteC44<double>();
    auto silimanite_C45 = mpc::data::SilimaniteC45<double>();
    auto silimanite_C46 = mpc::data::SilimaniteC46<double>();
    auto silimanite_C55 = mpc::data::SilimaniteC55<double>();
    auto silimanite_C56 = mpc::data::SilimaniteC56<double>();
    auto silimanite_C66 = mpc::data::SilimaniteC66<double>();
    auto silimanite_bulk_modulus = mpc::data::SilimaniteBulkModulus<double>();
    auto silimanite_shear_modulus = mpc::data::SilimaniteShearModulus<double>();
    mpc::core::StiffnessTensor<double> silimanite_stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();

    // Barite
    mpc::core::SymmetryGroupEnumeration barite_symmetry_group_enum = mpc::data::BariteSymmetryClass();
    auto barite_density = mpc::data::BariteDensity<double>();
    auto barite_C11 = mpc::data::BariteC11<double>();
    auto barite_C12 = mpc::data::BariteC12<double>();
    auto barite_C13 = mpc::data::BariteC13<double>();
    auto barite_C14 = mpc::data::BariteC14<double>();
    auto barite_C15 = mpc::data::BariteC15<double>();
    auto barite_C16 = mpc::data::BariteC16<double>();
    auto barite_C22 = mpc::data::BariteC22<double>();
    auto barite_C23 = mpc::data::BariteC23<double>();
    auto barite_C24 = mpc::data::BariteC24<double>();
    auto barite_C25 = mpc::data::BariteC25<double>();
    auto barite_C26 = mpc::data::BariteC26<double>();
    auto barite_C33 = mpc::data::BariteC33<double>();
    auto barite_C34 = mpc::data::BariteC34<double>();
    auto barite_C35 = mpc::data::BariteC35<double>();
    auto barite_C36 = mpc::data::BariteC36<double>();
    auto barite_C44 = mpc::data::BariteC44<double>();
    auto barite_C45 = mpc::data::BariteC45<double>();
    auto barite_C46 = mpc::data::BariteC46<double>();
    auto barite_C55 = mpc::data::BariteC55<double>();
    auto barite_C56 = mpc::data::BariteC56<double>();
    auto barite_C66 = mpc::data::BariteC66<double>();
    auto barite_bulk_modulus = mpc::data::BariteBulkModulus<double>();
    auto barite_shear_modulus = mpc::data::BariteShearModulus<double>();
    mpc::core::StiffnessTensor<double> barite_stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();

    // Anhydrite
    mpc::core::SymmetryGroupEnumeration anhydrite_symmetry_group_enum = mpc::data::AnhydriteSymmetryClass();
    auto anhydrite_density = mpc::data::AnhydriteDensity<double>();
    auto anhydrite_C11 = mpc::data::AnhydriteC11<double>();
    auto anhydrite_C12 = mpc::data::AnhydriteC12<double>();
    auto anhydrite_C13 = mpc::data::AnhydriteC13<double>();
    auto anhydrite_C14 = mpc::data::AnhydriteC14<double>();
    auto anhydrite_C15 = mpc::data::AnhydriteC15<double>();
    auto anhydrite_C16 = mpc::data::AnhydriteC16<double>();
    auto anhydrite_C22 = mpc::data::AnhydriteC22<double>();
    auto anhydrite_C23 = mpc::data::AnhydriteC23<double>();
    auto anhydrite_C24 = mpc::data::AnhydriteC24<double>();
    auto anhydrite_C25 = mpc::data::AnhydriteC25<double>();
    auto anhydrite_C26 = mpc::data::AnhydriteC26<double>();
    auto anhydrite_C33 = mpc::data::AnhydriteC33<double>();
    auto anhydrite_C34 = mpc::data::AnhydriteC34<double>();
    auto anhydrite_C35 = mpc::data::AnhydriteC35<double>();
    auto anhydrite_C36 = mpc::data::AnhydriteC36<double>();
    auto anhydrite_C44 = mpc::data::AnhydriteC44<double>();
    auto anhydrite_C45 = mpc::data::AnhydriteC45<double>();
    auto anhydrite_C46 = mpc::data::AnhydriteC46<double>();
    auto anhydrite_C55 = mpc::data::AnhydriteC55<double>();
    auto anhydrite_C56 = mpc::data::AnhydriteC56<double>();
    auto anhydrite_C66 = mpc::data::AnhydriteC66<double>();
    auto anhydrite_bulk_modulus = mpc::data::AnhydriteBulkModulus<double>();
    auto anhydrite_shear_modulus = mpc::data::AnhydriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> anhydrite_stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();

    // Dolomite
    mpc::core::SymmetryGroupEnumeration dolomite_symmetry_group_enum = mpc::data::DolomiteSymmetryClass();
    auto dolomite_density = mpc::data::DolomiteDensity<double>();
    auto dolomite_C11 = mpc::data::DolomiteC11<double>();
    auto dolomite_C12 = mpc::data::DolomiteC12<double>();
    auto dolomite_C13 = mpc::data::DolomiteC13<double>();
    auto dolomite_C14 = mpc::data::DolomiteC14<double>();
    auto dolomite_C15 = mpc::data::DolomiteC15<double>();
    auto dolomite_C16 = mpc::data::DolomiteC16<double>();
    auto dolomite_C22 = mpc::data::DolomiteC22<double>();
    auto dolomite_C23 = mpc::data::DolomiteC23<double>();
    auto dolomite_C24 = mpc::data::DolomiteC24<double>();
    auto dolomite_C25 = mpc::data::DolomiteC25<double>();
    auto dolomite_C26 = mpc::data::DolomiteC26<double>();
    auto dolomite_C33 = mpc::data::DolomiteC33<double>();
    auto dolomite_C34 = mpc::data::DolomiteC34<double>();
    auto dolomite_C35 = mpc::data::DolomiteC35<double>();
    auto dolomite_C36 = mpc::data::DolomiteC36<double>();
    auto dolomite_C44 = mpc::data::DolomiteC44<double>();
    auto dolomite_C45 = mpc::data::DolomiteC45<double>();
    auto dolomite_C46 = mpc::data::DolomiteC46<double>();
    auto dolomite_C55 = mpc::data::DolomiteC55<double>();
    auto dolomite_C56 = mpc::data::DolomiteC56<double>();
    auto dolomite_C66 = mpc::data::DolomiteC66<double>();
    auto dolomite_bulk_modulus = mpc::data::DolomiteBulkModulus<double>();
    auto dolomite_shear_modulus = mpc::data::DolomiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> dolomite_stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();

    // Rutile
    mpc::core::SymmetryGroupEnumeration rutile_symmetry_group_enum = mpc::data::RutileSymmetryClass();
    auto rutile_density = mpc::data::RutileDensity<double>();
    auto rutile_C11 = mpc::data::RutileC11<double>();
    auto rutile_C12 = mpc::data::RutileC12<double>();
    auto rutile_C13 = mpc::data::RutileC13<double>();
    auto rutile_C14 = mpc::data::RutileC14<double>();
    auto rutile_C15 = mpc::data::RutileC15<double>();
    auto rutile_C16 = mpc::data::RutileC16<double>();
    auto rutile_C22 = mpc::data::RutileC22<double>();
    auto rutile_C23 = mpc::data::RutileC23<double>();
    auto rutile_C24 = mpc::data::RutileC24<double>();
    auto rutile_C25 = mpc::data::RutileC25<double>();
    auto rutile_C26 = mpc::data::RutileC26<double>();
    auto rutile_C33 = mpc::data::RutileC33<double>();
    auto rutile_C34 = mpc::data::RutileC34<double>();
    auto rutile_C35 = mpc::data::RutileC35<double>();
    auto rutile_C36 = mpc::data::RutileC36<double>();
    auto rutile_C44 = mpc::data::RutileC44<double>();
    auto rutile_C45 = mpc::data::RutileC45<double>();
    auto rutile_C46 = mpc::data::RutileC46<double>();
    auto rutile_C55 = mpc::data::RutileC55<double>();
    auto rutile_C56 = mpc::data::RutileC56<double>();
    auto rutile_C66 = mpc::data::RutileC66<double>();
    auto rutile_bulk_modulus = mpc::data::RutileBulkModulus<double>();
    auto rutile_shear_modulus = mpc::data::RutileShearModulus<double>();
    mpc::core::StiffnessTensor<double> rutile_stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();

    // Zircon
    mpc::core::SymmetryGroupEnumeration zircon_symmetry_group_enum = mpc::data::ZirconSymmetryClass();
    auto zircon_density = mpc::data::ZirconDensity<double>();
    auto zircon_C11 = mpc::data::ZirconC11<double>();
    auto zircon_C12 = mpc::data::ZirconC12<double>();
    auto zircon_C13 = mpc::data::ZirconC13<double>();
    auto zircon_C14 = mpc::data::ZirconC14<double>();
    auto zircon_C15 = mpc::data::ZirconC15<double>();
    auto zircon_C16 = mpc::data::ZirconC16<double>();
    auto zircon_C22 = mpc::data::ZirconC22<double>();
    auto zircon_C23 = mpc::data::ZirconC23<double>();
    auto zircon_C24 = mpc::data::ZirconC24<double>();
    auto zircon_C25 = mpc::data::ZirconC25<double>();
    auto zircon_C26 = mpc::data::ZirconC26<double>();
    auto zircon_C33 = mpc::data::ZirconC33<double>();
    auto zircon_C34 = mpc::data::ZirconC34<double>();
    auto zircon_C35 = mpc::data::ZirconC35<double>();
    auto zircon_C36 = mpc::data::ZirconC36<double>();
    auto zircon_C44 = mpc::data::ZirconC44<double>();
    auto zircon_C45 = mpc::data::ZirconC45<double>();
    auto zircon_C46 = mpc::data::ZirconC46<double>();
    auto zircon_C55 = mpc::data::ZirconC55<double>();
    auto zircon_C56 = mpc::data::ZirconC56<double>();
    auto zircon_C66 = mpc::data::ZirconC66<double>();
    auto zircon_bulk_modulus = mpc::data::ZirconBulkModulus<double>();
    auto zircon_shear_modulus = mpc::data::ZirconShearModulus<double>();
    mpc::core::StiffnessTensor<double> zircon_stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();

    // Corundum
    mpc::core::SymmetryGroupEnumeration corundum_symmetry_group_enum = mpc::data::CorundumSymmetryClass();
    auto corundum_density = mpc::data::CorundumDensity<double>();
    auto corundum_C11 = mpc::data::CorundumC11<double>();
    auto corundum_C12 = mpc::data::CorundumC12<double>();
    auto corundum_C13 = mpc::data::CorundumC13<double>();
    auto corundum_C14 = mpc::data::CorundumC14<double>();
    auto corundum_C15 = mpc::data::CorundumC15<double>();
    auto corundum_C16 = mpc::data::CorundumC16<double>();
    auto corundum_C22 = mpc::data::CorundumC22<double>();
    auto corundum_C23 = mpc::data::CorundumC23<double>();
    auto corundum_C24 = mpc::data::CorundumC24<double>();
    auto corundum_C25 = mpc::data::CorundumC25<double>();
    auto corundum_C26 = mpc::data::CorundumC26<double>();
    auto corundum_C33 = mpc::data::CorundumC33<double>();
    auto corundum_C34 = mpc::data::CorundumC34<double>();
    auto corundum_C35 = mpc::data::CorundumC35<double>();
    auto corundum_C36 = mpc::data::CorundumC36<double>();
    auto corundum_C44 = mpc::data::CorundumC44<double>();
    auto corundum_C45 = mpc::data::CorundumC45<double>();
    auto corundum_C46 = mpc::data::CorundumC46<double>();
    auto corundum_C55 = mpc::data::CorundumC55<double>();
    auto corundum_C56 = mpc::data::CorundumC56<double>();
    auto corundum_C66 = mpc::data::CorundumC66<double>();
    auto corundum_bulk_modulus = mpc::data::CorundumBulkModulus<double>();
    auto corundum_shear_modulus = mpc::data::CorundumShearModulus<double>();
    mpc::core::StiffnessTensor<double> corundum_stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();

    // Calcite
    mpc::core::SymmetryGroupEnumeration calcite_symmetry_group_enum = mpc::data::CalciteSymmetryClass();
    auto calcite_density = mpc::data::CalciteDensity<double>();
    auto calcite_C11 = mpc::data::CalciteC11<double>();
    auto calcite_C12 = mpc::data::CalciteC12<double>();
    auto calcite_C13 = mpc::data::CalciteC13<double>();
    auto calcite_C14 = mpc::data::CalciteC14<double>();
    auto calcite_C15 = mpc::data::CalciteC15<double>();
    auto calcite_C16 = mpc::data::CalciteC16<double>();
    auto calcite_C22 = mpc::data::CalciteC22<double>();
    auto calcite_C23 = mpc::data::CalciteC23<double>();
    auto calcite_C24 = mpc::data::CalciteC24<double>();
    auto calcite_C25 = mpc::data::CalciteC25<double>();
    auto calcite_C26 = mpc::data::CalciteC26<double>();
    auto calcite_C33 = mpc::data::CalciteC33<double>();
    auto calcite_C34 = mpc::data::CalciteC34<double>();
    auto calcite_C35 = mpc::data::CalciteC35<double>();
    auto calcite_C36 = mpc::data::CalciteC36<double>();
    auto calcite_C44 = mpc::data::CalciteC44<double>();
    auto calcite_C45 = mpc::data::CalciteC45<double>();
    auto calcite_C46 = mpc::data::CalciteC46<double>();
    auto calcite_C55 = mpc::data::CalciteC55<double>();
    auto calcite_C56 = mpc::data::CalciteC56<double>();
    auto calcite_C66 = mpc::data::CalciteC66<double>();
    auto calcite_bulk_modulus = mpc::data::CalciteBulkModulus<double>();
    auto calcite_shear_modulus = mpc::data::CalciteShearModulus<double>();
    mpc::core::StiffnessTensor<double> calcite_stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();

    // Quartz
    mpc::core::SymmetryGroupEnumeration quartz_symmetry_group_enum = mpc::data::QuartzSymmetryClass();
    auto quartz_density = mpc::data::QuartzDensity<double>();
    auto quartz_C11 = mpc::data::QuartzC11<double>();
    auto quartz_C12 = mpc::data::QuartzC12<double>();
    auto quartz_C13 = mpc::data::QuartzC13<double>();
    auto quartz_C14 = mpc::data::QuartzC14<double>();
    auto quartz_C15 = mpc::data::QuartzC15<double>();
    auto quartz_C16 = mpc::data::QuartzC16<double>();
    auto quartz_C22 = mpc::data::QuartzC22<double>();
    auto quartz_C23 = mpc::data::QuartzC23<double>();
    auto quartz_C24 = mpc::data::QuartzC24<double>();
    auto quartz_C25 = mpc::data::QuartzC25<double>();
    auto quartz_C26 = mpc::data::QuartzC26<double>();
    auto quartz_C33 = mpc::data::QuartzC33<double>();
    auto quartz_C34 = mpc::data::QuartzC34<double>();
    auto quartz_C35 = mpc::data::QuartzC35<double>();
    auto quartz_C36 = mpc::data::QuartzC36<double>();
    auto quartz_C44 = mpc::data::QuartzC44<double>();
    auto quartz_C45 = mpc::data::QuartzC45<double>();
    auto quartz_C46 = mpc::data::QuartzC46<double>();
    auto quartz_C55 = mpc::data::QuartzC55<double>();
    auto quartz_C56 = mpc::data::QuartzC56<double>();
    auto quartz_C66 = mpc::data::QuartzC66<double>();
    auto quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
    auto quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();
    mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();

    // Tourmaline
    mpc::core::SymmetryGroupEnumeration tourmaline_symmetry_group_enum = mpc::data::TourmalineSymmetryClass();
    auto tourmaline_density = mpc::data::TourmalineDensity<double>();
    auto tourmaline_C11 = mpc::data::TourmalineC11<double>();
    auto tourmaline_C12 = mpc::data::TourmalineC12<double>();
    auto tourmaline_C13 = mpc::data::TourmalineC13<double>();
    auto tourmaline_C14 = mpc::data::TourmalineC14<double>();
    auto tourmaline_C15 = mpc::data::TourmalineC15<double>();
    auto tourmaline_C16 = mpc::data::TourmalineC16<double>();
    auto tourmaline_C22 = mpc::data::TourmalineC22<double>();
    auto tourmaline_C23 = mpc::data::TourmalineC23<double>();
    auto tourmaline_C24 = mpc::data::TourmalineC24<double>();
    auto tourmaline_C25 = mpc::data::TourmalineC25<double>();
    auto tourmaline_C26 = mpc::data::TourmalineC26<double>();
    auto tourmaline_C33 = mpc::data::TourmalineC33<double>();
    auto tourmaline_C34 = mpc::data::TourmalineC34<double>();
    auto tourmaline_C35 = mpc::data::TourmalineC35<double>();
    auto tourmaline_C36 = mpc::data::TourmalineC36<double>();
    auto tourmaline_C44 = mpc::data::TourmalineC44<double>();
    auto tourmaline_C45 = mpc::data::TourmalineC45<double>();
    auto tourmaline_C46 = mpc::data::TourmalineC46<double>();
    auto tourmaline_C55 = mpc::data::TourmalineC55<double>();
    auto tourmaline_C56 = mpc::data::TourmalineC56<double>();
    auto tourmaline_C66 = mpc::data::TourmalineC66<double>();
    auto tourmaline_bulk_modulus = mpc::data::TourmalineBulkModulus<double>();
    auto tourmaline_shear_modulus = mpc::data::TourmalineShearModulus<double>();
    mpc::core::StiffnessTensor<double> tourmaline_stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();

    // Beryl
    mpc::core::SymmetryGroupEnumeration beryl_symmetry_group_enum = mpc::data::BerylSymmetryClass();
    auto beryl_density = mpc::data::BerylDensity<double>();
    auto beryl_C11 = mpc::data::BerylC11<double>();
    auto beryl_C12 = mpc::data::BerylC12<double>();
    auto beryl_C13 = mpc::data::BerylC13<double>();
    auto beryl_C14 = mpc::data::BerylC14<double>();
    auto beryl_C15 = mpc::data::BerylC15<double>();
    auto beryl_C16 = mpc::data::BerylC16<double>();
    auto beryl_C22 = mpc::data::BerylC22<double>();
    auto beryl_C23 = mpc::data::BerylC23<double>();
    auto beryl_C24 = mpc::data::BerylC24<double>();
    auto beryl_C25 = mpc::data::BerylC25<double>();
    auto beryl_C26 = mpc::data::BerylC26<double>();
    auto beryl_C33 = mpc::data::BerylC33<double>();
    auto beryl_C34 = mpc::data::BerylC34<double>();
    auto beryl_C35 = mpc::data::BerylC35<double>();
    auto beryl_C36 = mpc::data::BerylC36<double>();
    auto beryl_C44 = mpc::data::BerylC44<double>();
    auto beryl_C45 = mpc::data::BerylC45<double>();
    auto beryl_C46 = mpc::data::BerylC46<double>();
    auto beryl_C55 = mpc::data::BerylC55<double>();
    auto beryl_C56 = mpc::data::BerylC56<double>();
    auto beryl_C66 = mpc::data::BerylC66<double>();
    auto beryl_bulk_modulus = mpc::data::BerylBulkModulus<double>();
    auto beryl_shear_modulus = mpc::data::BerylShearModulus<double>();
    mpc::core::StiffnessTensor<double> beryl_stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();

    // Graphite
    mpc::core::SymmetryGroupEnumeration graphite_symmetry_group_enum = mpc::data::GraphiteSymmetryClass();
    auto graphite_density = mpc::data::GraphiteDensity<double>();
    auto graphite_C11 = mpc::data::GraphiteC11<double>();
    auto graphite_C12 = mpc::data::GraphiteC12<double>();
    auto graphite_C13 = mpc::data::GraphiteC13<double>();
    auto graphite_C14 = mpc::data::GraphiteC14<double>();
    auto graphite_C15 = mpc::data::GraphiteC15<double>();
    auto graphite_C16 = mpc::data::GraphiteC16<double>();
    auto graphite_C22 = mpc::data::GraphiteC22<double>();
    auto graphite_C23 = mpc::data::GraphiteC23<double>();
    auto graphite_C24 = mpc::data::GraphiteC24<double>();
    auto graphite_C25 = mpc::data::GraphiteC25<double>();
    auto graphite_C26 = mpc::data::GraphiteC26<double>();
    auto graphite_C33 = mpc::data::GraphiteC33<double>();
    auto graphite_C34 = mpc::data::GraphiteC34<double>();
    auto graphite_C35 = mpc::data::GraphiteC35<double>();
    auto graphite_C36 = mpc::data::GraphiteC36<double>();
    auto graphite_C44 = mpc::data::GraphiteC44<double>();
    auto graphite_C45 = mpc::data::GraphiteC45<double>();
    auto graphite_C46 = mpc::data::GraphiteC46<double>();
    auto graphite_C55 = mpc::data::GraphiteC55<double>();
    auto graphite_C56 = mpc::data::GraphiteC56<double>();
    auto graphite_C66 = mpc::data::GraphiteC66<double>();
    auto graphite_bulk_modulus = mpc::data::GraphiteBulkModulus<double>();
    auto graphite_shear_modulus = mpc::data::GraphiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> graphite_stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();

    // Wusite
    mpc::core::SymmetryGroupEnumeration wusite_symmetry_group_enum = mpc::data::WusiteSymmetryClass();
    auto wusite_density = mpc::data::WusiteDensity<double>();
    auto wusite_C11 = mpc::data::WusiteC11<double>();
    auto wusite_C12 = mpc::data::WusiteC12<double>();
    auto wusite_C13 = mpc::data::WusiteC13<double>();
    auto wusite_C14 = mpc::data::WusiteC14<double>();
    auto wusite_C15 = mpc::data::WusiteC15<double>();
    auto wusite_C16 = mpc::data::WusiteC16<double>();
    auto wusite_C22 = mpc::data::WusiteC22<double>();
    auto wusite_C23 = mpc::data::WusiteC23<double>();
    auto wusite_C24 = mpc::data::WusiteC24<double>();
    auto wusite_C25 = mpc::data::WusiteC25<double>();
    auto wusite_C26 = mpc::data::WusiteC26<double>();
    auto wusite_C33 = mpc::data::WusiteC33<double>();
    auto wusite_C34 = mpc::data::WusiteC34<double>();
    auto wusite_C35 = mpc::data::WusiteC35<double>();
    auto wusite_C36 = mpc::data::WusiteC36<double>();
    auto wusite_C44 = mpc::data::WusiteC44<double>();
    auto wusite_C45 = mpc::data::WusiteC45<double>();
    auto wusite_C46 = mpc::data::WusiteC46<double>();
    auto wusite_C55 = mpc::data::WusiteC55<double>();
    auto wusite_C56 = mpc::data::WusiteC56<double>();
    auto wusite_C66 = mpc::data::WusiteC66<double>();
    auto wusite_bulk_modulus = mpc::data::WusiteBulkModulus<double>();
    auto wusite_shear_modulus = mpc::data::WusiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> wusite_stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();

    // Manganosite
    mpc::core::SymmetryGroupEnumeration manganosite_symmetry_group_enum = mpc::data::ManganositeSymmetryClass();
    auto manganosite_density = mpc::data::ManganositeDensity<double>();
    auto manganosite_C11 = mpc::data::ManganositeC11<double>();
    auto manganosite_C12 = mpc::data::ManganositeC12<double>();
    auto manganosite_C13 = mpc::data::ManganositeC13<double>();
    auto manganosite_C14 = mpc::data::ManganositeC14<double>();
    auto manganosite_C15 = mpc::data::ManganositeC15<double>();
    auto manganosite_C16 = mpc::data::ManganositeC16<double>();
    auto manganosite_C22 = mpc::data::ManganositeC22<double>();
    auto manganosite_C23 = mpc::data::ManganositeC23<double>();
    auto manganosite_C24 = mpc::data::ManganositeC24<double>();
    auto manganosite_C25 = mpc::data::ManganositeC25<double>();
    auto manganosite_C26 = mpc::data::ManganositeC26<double>();
    auto manganosite_C33 = mpc::data::ManganositeC33<double>();
    auto manganosite_C34 = mpc::data::ManganositeC34<double>();
    auto manganosite_C35 = mpc::data::ManganositeC35<double>();
    auto manganosite_C36 = mpc::data::ManganositeC36<double>();
    auto manganosite_C44 = mpc::data::ManganositeC44<double>();
    auto manganosite_C45 = mpc::data::ManganositeC45<double>();
    auto manganosite_C46 = mpc::data::ManganositeC46<double>();
    auto manganosite_C55 = mpc::data::ManganositeC55<double>();
    auto manganosite_C56 = mpc::data::ManganositeC56<double>();
    auto manganosite_C66 = mpc::data::ManganositeC66<double>();
    auto manganosite_bulk_modulus = mpc::data::ManganositeBulkModulus<double>();
    auto manganosite_shear_modulus = mpc::data::ManganositeShearModulus<double>();
    mpc::core::StiffnessTensor<double> manganosite_stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();

    // Periclase
    mpc::core::SymmetryGroupEnumeration periclase_symmetry_group_enum = mpc::data::PericlaseSymmetryClass();
    auto periclase_density = mpc::data::PericlaseDensity<double>();
    auto periclase_C11 = mpc::data::PericlaseC11<double>();
    auto periclase_C12 = mpc::data::PericlaseC12<double>();
    auto periclase_C13 = mpc::data::PericlaseC13<double>();
    auto periclase_C14 = mpc::data::PericlaseC14<double>();
    auto periclase_C15 = mpc::data::PericlaseC15<double>();
    auto periclase_C16 = mpc::data::PericlaseC16<double>();
    auto periclase_C22 = mpc::data::PericlaseC22<double>();
    auto periclase_C23 = mpc::data::PericlaseC23<double>();
    auto periclase_C24 = mpc::data::PericlaseC24<double>();
    auto periclase_C25 = mpc::data::PericlaseC25<double>();
    auto periclase_C26 = mpc::data::PericlaseC26<double>();
    auto periclase_C33 = mpc::data::PericlaseC33<double>();
    auto periclase_C34 = mpc::data::PericlaseC34<double>();
    auto periclase_C35 = mpc::data::PericlaseC35<double>();
    auto periclase_C36 = mpc::data::PericlaseC36<double>();
    auto periclase_C44 = mpc::data::PericlaseC44<double>();
    auto periclase_C45 = mpc::data::PericlaseC45<double>();
    auto periclase_C46 = mpc::data::PericlaseC46<double>();
    auto periclase_C55 = mpc::data::PericlaseC55<double>();
    auto periclase_C56 = mpc::data::PericlaseC56<double>();
    auto periclase_C66 = mpc::data::PericlaseC66<double>();
    auto periclase_bulk_modulus = mpc::data::PericlaseBulkModulus<double>();
    auto periclase_shear_modulus = mpc::data::PericlaseShearModulus<double>();
    mpc::core::StiffnessTensor<double> periclase_stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();

    // Magnetite
    mpc::core::SymmetryGroupEnumeration magnetite_symmetry_group_enum = mpc::data::MagnetiteSymmetryClass();
    auto magnetite_density = mpc::data::MagnetiteDensity<double>();
    auto magnetite_C11 = mpc::data::MagnetiteC11<double>();
    auto magnetite_C12 = mpc::data::MagnetiteC12<double>();
    auto magnetite_C13 = mpc::data::MagnetiteC13<double>();
    auto magnetite_C14 = mpc::data::MagnetiteC14<double>();
    auto magnetite_C15 = mpc::data::MagnetiteC15<double>();
    auto magnetite_C16 = mpc::data::MagnetiteC16<double>();
    auto magnetite_C22 = mpc::data::MagnetiteC22<double>();
    auto magnetite_C23 = mpc::data::MagnetiteC23<double>();
    auto magnetite_C24 = mpc::data::MagnetiteC24<double>();
    auto magnetite_C25 = mpc::data::MagnetiteC25<double>();
    auto magnetite_C26 = mpc::data::MagnetiteC26<double>();
    auto magnetite_C33 = mpc::data::MagnetiteC33<double>();
    auto magnetite_C34 = mpc::data::MagnetiteC34<double>();
    auto magnetite_C35 = mpc::data::MagnetiteC35<double>();
    auto magnetite_C36 = mpc::data::MagnetiteC36<double>();
    auto magnetite_C44 = mpc::data::MagnetiteC44<double>();
    auto magnetite_C45 = mpc::data::MagnetiteC45<double>();
    auto magnetite_C46 = mpc::data::MagnetiteC46<double>();
    auto magnetite_C55 = mpc::data::MagnetiteC55<double>();
    auto magnetite_C56 = mpc::data::MagnetiteC56<double>();
    auto magnetite_C66 = mpc::data::MagnetiteC66<double>();
    auto magnetite_bulk_modulus = mpc::data::MagnetiteBulkModulus<double>();
    auto magnetite_shear_modulus = mpc::data::MagnetiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> magnetite_stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();

    // Chromite
    mpc::core::SymmetryGroupEnumeration chromite_symmetry_group_enum = mpc::data::ChromiteSymmetryClass();
    auto chromite_density = mpc::data::ChromiteDensity<double>();
    auto chromite_C11 = mpc::data::ChromiteC11<double>();
    auto chromite_C12 = mpc::data::ChromiteC12<double>();
    auto chromite_C13 = mpc::data::ChromiteC13<double>();
    auto chromite_C14 = mpc::data::ChromiteC14<double>();
    auto chromite_C15 = mpc::data::ChromiteC15<double>();
    auto chromite_C16 = mpc::data::ChromiteC16<double>();
    auto chromite_C22 = mpc::data::ChromiteC22<double>();
    auto chromite_C23 = mpc::data::ChromiteC23<double>();
    auto chromite_C24 = mpc::data::ChromiteC24<double>();
    auto chromite_C25 = mpc::data::ChromiteC25<double>();
    auto chromite_C26 = mpc::data::ChromiteC26<double>();
    auto chromite_C33 = mpc::data::ChromiteC33<double>();
    auto chromite_C34 = mpc::data::ChromiteC34<double>();
    auto chromite_C35 = mpc::data::ChromiteC35<double>();
    auto chromite_C36 = mpc::data::ChromiteC36<double>();
    auto chromite_C44 = mpc::data::ChromiteC44<double>();
    auto chromite_C45 = mpc::data::ChromiteC45<double>();
    auto chromite_C46 = mpc::data::ChromiteC46<double>();
    auto chromite_C55 = mpc::data::ChromiteC55<double>();
    auto chromite_C56 = mpc::data::ChromiteC56<double>();
    auto chromite_C66 = mpc::data::ChromiteC66<double>();
    auto chromite_bulk_modulus = mpc::data::ChromiteBulkModulus<double>();
    auto chromite_shear_modulus = mpc::data::ChromiteShearModulus<double>();
    mpc::core::StiffnessTensor<double> chromite_stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();

    // Spinel
    mpc::core::SymmetryGroupEnumeration spinel_symmetry_group_enum = mpc::data::SpinelSymmetryClass();
    auto spinel_density = mpc::data::SpinelDensity<double>();
    auto spinel_C11 = mpc::data::SpinelC11<double>();
    auto spinel_C12 = mpc::data::SpinelC12<double>();
    auto spinel_C13 = mpc::data::SpinelC13<double>();
    auto spinel_C14 = mpc::data::SpinelC14<double>();
    auto spinel_C15 = mpc::data::SpinelC15<double>();
    auto spinel_C16 = mpc::data::SpinelC16<double>();
    auto spinel_C22 = mpc::data::SpinelC22<double>();
    auto spinel_C23 = mpc::data::SpinelC23<double>();
    auto spinel_C24 = mpc::data::SpinelC24<double>();
    auto spinel_C25 = mpc::data::SpinelC25<double>();
    auto spinel_C26 = mpc::data::SpinelC26<double>();
    auto spinel_C33 = mpc::data::SpinelC33<double>();
    auto spinel_C34 = mpc::data::SpinelC34<double>();
    auto spinel_C35 = mpc::data::SpinelC35<double>();
    auto spinel_C36 = mpc::data::SpinelC36<double>();
    auto spinel_C44 = mpc::data::SpinelC44<double>();
    auto spinel_C45 = mpc::data::SpinelC45<double>();
    auto spinel_C46 = mpc::data::SpinelC46<double>();
    auto spinel_C55 = mpc::data::SpinelC55<double>();
    auto spinel_C56 = mpc::data::SpinelC56<double>();
    auto spinel_C66 = mpc::data::SpinelC66<double>();
    auto spinel_bulk_modulus = mpc::data::SpinelBulkModulus<double>();
    auto spinel_shear_modulus = mpc::data::SpinelShearModulus<double>();
    mpc::core::StiffnessTensor<double> spinel_stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();

    // Pyrite
    mpc::core::SymmetryGroupEnumeration pyrite_symmetry_group_enum = mpc::data::PyriteSymmetryClass();
    auto pyrite_density = mpc::data::PyriteDensity<double>();
    auto pyrite_C11 = mpc::data::PyriteC11<double>();
    auto pyrite_C12 = mpc::data::PyriteC12<double>();
    auto pyrite_C13 = mpc::data::PyriteC13<double>();
    auto pyrite_C14 = mpc::data::PyriteC14<double>();
    auto pyrite_C15 = mpc::data::PyriteC15<double>();
    auto pyrite_C16 = mpc::data::PyriteC16<double>();
    auto pyrite_C22 = mpc::data::PyriteC22<double>();
    auto pyrite_C23 = mpc::data::PyriteC23<double>();
    auto pyrite_C24 = mpc::data::PyriteC24<double>();
    auto pyrite_C25 = mpc::data::PyriteC25<double>();
    auto pyrite_C26 = mpc::data::PyriteC26<double>();
    auto pyrite_C33 = mpc::data::PyriteC33<double>();
    auto pyrite_C34 = mpc::data::PyriteC34<double>();
    auto pyrite_C35 = mpc::data::PyriteC35<double>();
    auto pyrite_C36 = mpc::data::PyriteC36<double>();
    auto pyrite_C44 = mpc::data::PyriteC44<double>();
    auto pyrite_C45 = mpc::data::PyriteC45<double>();
    auto pyrite_C46 = mpc::data::PyriteC46<double>();
    auto pyrite_C55 = mpc::data::PyriteC55<double>();
    auto pyrite_C56 = mpc::data::PyriteC56<double>();
    auto pyrite_C66 = mpc::data::PyriteC66<double>();
    auto pyrite_bulk_modulus = mpc::data::PyriteBulkModulus<double>();
    auto pyrite_shear_modulus = mpc::data::PyriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> pyrite_stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();

    // Galena
    mpc::core::SymmetryGroupEnumeration galena_symmetry_group_enum = mpc::data::GalenaSymmetryClass();
    auto galena_density = mpc::data::GalenaDensity<double>();
    auto galena_C11 = mpc::data::GalenaC11<double>();
    auto galena_C12 = mpc::data::GalenaC12<double>();
    auto galena_C13 = mpc::data::GalenaC13<double>();
    auto galena_C14 = mpc::data::GalenaC14<double>();
    auto galena_C15 = mpc::data::GalenaC15<double>();
    auto galena_C16 = mpc::data::GalenaC16<double>();
    auto galena_C22 = mpc::data::GalenaC22<double>();
    auto galena_C23 = mpc::data::GalenaC23<double>();
    auto galena_C24 = mpc::data::GalenaC24<double>();
    auto galena_C25 = mpc::data::GalenaC25<double>();
    auto galena_C26 = mpc::data::GalenaC26<double>();
    auto galena_C33 = mpc::data::GalenaC33<double>();
    auto galena_C34 = mpc::data::GalenaC34<double>();
    auto galena_C35 = mpc::data::GalenaC35<double>();
    auto galena_C36 = mpc::data::GalenaC36<double>();
    auto galena_C44 = mpc::data::GalenaC44<double>();
    auto galena_C45 = mpc::data::GalenaC45<double>();
    auto galena_C46 = mpc::data::GalenaC46<double>();
    auto galena_C55 = mpc::data::GalenaC55<double>();
    auto galena_C56 = mpc::data::GalenaC56<double>();
    auto galena_C66 = mpc::data::GalenaC66<double>();
    auto galena_bulk_modulus = mpc::data::GalenaBulkModulus<double>();
    auto galena_shear_modulus = mpc::data::GalenaShearModulus<double>();
    mpc::core::StiffnessTensor<double> galena_stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();


    // Sphalerite
    mpc::core::SymmetryGroupEnumeration sphalerite_symmetry_group_enum = mpc::data::SphaleriteSymmetryClass();
    auto sphalerite_density = mpc::data::SphaleriteDensity<double>();
    auto sphalerite_C11 = mpc::data::SphaleriteC11<double>();
    auto sphalerite_C12 = mpc::data::SphaleriteC12<double>();
    auto sphalerite_C13 = mpc::data::SphaleriteC13<double>();
    auto sphalerite_C14 = mpc::data::SphaleriteC14<double>();
    auto sphalerite_C15 = mpc::data::SphaleriteC15<double>();
    auto sphalerite_C16 = mpc::data::SphaleriteC16<double>();
    auto sphalerite_C22 = mpc::data::SphaleriteC22<double>();
    auto sphalerite_C23 = mpc::data::SphaleriteC23<double>();
    auto sphalerite_C24 = mpc::data::SphaleriteC24<double>();
    auto sphalerite_C25 = mpc::data::SphaleriteC25<double>();
    auto sphalerite_C26 = mpc::data::SphaleriteC26<double>();
    auto sphalerite_C33 = mpc::data::SphaleriteC33<double>();
    auto sphalerite_C34 = mpc::data::SphaleriteC34<double>();
    auto sphalerite_C35 = mpc::data::SphaleriteC35<double>();
    auto sphalerite_C36 = mpc::data::SphaleriteC36<double>();
    auto sphalerite_C44 = mpc::data::SphaleriteC44<double>();
    auto sphalerite_C45 = mpc::data::SphaleriteC45<double>();
    auto sphalerite_C46 = mpc::data::SphaleriteC46<double>();
    auto sphalerite_C55 = mpc::data::SphaleriteC55<double>();
    auto sphalerite_C56 = mpc::data::SphaleriteC56<double>();
    auto sphalerite_C66 = mpc::data::SphaleriteC66<double>();
    auto sphalerite_bulk_modulus = mpc::data::SphaleriteBulkModulus<double>();
    auto sphalerite_shear_modulus = mpc::data::SphaleriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> sphalerite_stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();

    // Fluorite
    mpc::core::SymmetryGroupEnumeration fluorite_symmetry_group_enum = mpc::data::FluoriteSymmetryClass();
    auto fluorite_density = mpc::data::FluoriteDensity<double>();
    auto fluorite_C11 = mpc::data::FluoriteC11<double>();
    auto fluorite_C12 = mpc::data::FluoriteC12<double>();
    auto fluorite_C13 = mpc::data::FluoriteC13<double>();
    auto fluorite_C14 = mpc::data::FluoriteC14<double>();
    auto fluorite_C15 = mpc::data::FluoriteC15<double>();
    auto fluorite_C16 = mpc::data::FluoriteC16<double>();
    auto fluorite_C22 = mpc::data::FluoriteC22<double>();
    auto fluorite_C23 = mpc::data::FluoriteC23<double>();
    auto fluorite_C24 = mpc::data::FluoriteC24<double>();
    auto fluorite_C25 = mpc::data::FluoriteC25<double>();
    auto fluorite_C26 = mpc::data::FluoriteC26<double>();
    auto fluorite_C33 = mpc::data::FluoriteC33<double>();
    auto fluorite_C34 = mpc::data::FluoriteC34<double>();
    auto fluorite_C35 = mpc::data::FluoriteC35<double>();
    auto fluorite_C36 = mpc::data::FluoriteC36<double>();
    auto fluorite_C44 = mpc::data::FluoriteC44<double>();
    auto fluorite_C45 = mpc::data::FluoriteC45<double>();
    auto fluorite_C46 = mpc::data::FluoriteC46<double>();
    auto fluorite_C55 = mpc::data::FluoriteC55<double>();
    auto fluorite_C56 = mpc::data::FluoriteC56<double>();
    auto fluorite_C66 = mpc::data::FluoriteC66<double>();
    auto fluorite_bulk_modulus = mpc::data::FluoriteBulkModulus<double>();
    auto fluorite_shear_modulus = mpc::data::FluoriteShearModulus<double>();
    mpc::core::StiffnessTensor<double> fluorite_stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();

    // Halite
    mpc::core::SymmetryGroupEnumeration halite_symmetry_group_enum = mpc::data::HaliteSymmetryClass();
    auto halite_density = mpc::data::HaliteDensity<double>();
    auto halite_C11 = mpc::data::HaliteC11<double>();
    auto halite_C12 = mpc::data::HaliteC12<double>();
    auto halite_C13 = mpc::data::HaliteC13<double>();
    auto halite_C14 = mpc::data::HaliteC14<double>();
    auto halite_C15 = mpc::data::HaliteC15<double>();
    auto halite_C16 = mpc::data::HaliteC16<double>();
    auto halite_C22 = mpc::data::HaliteC22<double>();
    auto halite_C23 = mpc::data::HaliteC23<double>();
    auto halite_C24 = mpc::data::HaliteC24<double>();
    auto halite_C25 = mpc::data::HaliteC25<double>();
    auto halite_C26 = mpc::data::HaliteC26<double>();
    auto halite_C33 = mpc::data::HaliteC33<double>();
    auto halite_C34 = mpc::data::HaliteC34<double>();
    auto halite_C35 = mpc::data::HaliteC35<double>();
    auto halite_C36 = mpc::data::HaliteC36<double>();
    auto halite_C44 = mpc::data::HaliteC44<double>();
    auto halite_C45 = mpc::data::HaliteC45<double>();
    auto halite_C46 = mpc::data::HaliteC46<double>();
    auto halite_C55 = mpc::data::HaliteC55<double>();
    auto halite_C56 = mpc::data::HaliteC56<double>();
    auto halite_C66 = mpc::data::HaliteC66<double>();
    auto halite_bulk_modulus = mpc::data::HaliteBulkModulus<double>();
    auto halite_shear_modulus = mpc::data::HaliteShearModulus<double>();
    mpc::core::StiffnessTensor<double> halite_stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();

    // Sylvite
    mpc::core::SymmetryGroupEnumeration sylvite_symmetry_group_enum = mpc::data::SylviteSymmetryClass();
    auto sylvite_density = mpc::data::SylviteDensity<double>();
    auto sylvite_C11 = mpc::data::SylviteC11<double>();
    auto sylvite_C12 = mpc::data::SylviteC12<double>();
    auto sylvite_C13 = mpc::data::SylviteC13<double>();
    auto sylvite_C14 = mpc::data::SylviteC14<double>();
    auto sylvite_C15 = mpc::data::SylviteC15<double>();
    auto sylvite_C16 = mpc::data::SylviteC16<double>();
    auto sylvite_C22 = mpc::data::SylviteC22<double>();
    auto sylvite_C23 = mpc::data::SylviteC23<double>();
    auto sylvite_C24 = mpc::data::SylviteC24<double>();
    auto sylvite_C25 = mpc::data::SylviteC25<double>();
    auto sylvite_C26 = mpc::data::SylviteC26<double>();
    auto sylvite_C33 = mpc::data::SylviteC33<double>();
    auto sylvite_C34 = mpc::data::SylviteC34<double>();
    auto sylvite_C35 = mpc::data::SylviteC35<double>();
    auto sylvite_C36 = mpc::data::SylviteC36<double>();
    auto sylvite_C44 = mpc::data::SylviteC44<double>();
    auto sylvite_C45 = mpc::data::SylviteC45<double>();
    auto sylvite_C46 = mpc::data::SylviteC46<double>();
    auto sylvite_C55 = mpc::data::SylviteC55<double>();
    auto sylvite_C56 = mpc::data::SylviteC56<double>();
    auto sylvite_C66 = mpc::data::SylviteC66<double>();
    auto sylvite_bulk_modulus = mpc::data::SylviteBulkModulus<double>();
    auto sylvite_shear_modulus = mpc::data::SylviteShearModulus<double>();
    mpc::core::StiffnessTensor<double> sylvite_stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();


    // normal vectors parallel to coordinate axes
    blitz::Array<double,1> normal_vector_x0 = blitz::Array<double,1>(3);
    normal_vector_x0 = 1, 0, 0;
    blitz::Array<double,1> normal_vector_x1 = blitz::Array<double,1>(3);
    normal_vector_x1 = 0, 1, 0;
    blitz::Array<double,1> normal_vector_x2 = blitz::Array<double,1>(3);
    normal_vector_x2 = 0, 0, 1;

    // Augite
    //std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> augite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    augite_greenchristoffel.SetComponents(augite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> augite_phase_velocities_x0 = augite_greenchristoffel.PhaseVelocities(augite_density);
    std::cout << "augite phase velocity (x0) [0] : " << augite_phase_velocities_x0[0] << std::endl;
    std::cout << "augite phase velocity (x0) [1] : " << augite_phase_velocities_x0[1] << std::endl;
    std::cout << "augite phase velocity (x0) [2] : " << augite_phase_velocities_x0[2] << std::endl;

    augite_greenchristoffel.SetComponents(augite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> augite_phase_velocities_x1 = augite_greenchristoffel.PhaseVelocities(augite_density);
    std::cout << "augite phase velocity (x1) [0] : " << augite_phase_velocities_x1[0] << std::endl;
    std::cout << "augite phase velocity (x1) [1] : " << augite_phase_velocities_x1[1] << std::endl;
    std::cout << "augite phase velocity (x1) [2] : " << augite_phase_velocities_x1[2] << std::endl;

    augite_greenchristoffel.SetComponents(augite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> augite_phase_velocities_x2 = augite_greenchristoffel.PhaseVelocities(augite_density);
    std::cout << "augite phase velocity (x2) [0] : " << augite_phase_velocities_x2[0] << std::endl;
    std::cout << "augite phase velocity (x2) [1] : " << augite_phase_velocities_x2[1] << std::endl;
    std::cout << "augite phase velocity (x2) [2] : " << augite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> augite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(augite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(augite_shear_modulus), mpc::rockphysics::DensityType<double>(augite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> augite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(augite_shear_modulus), mpc::rockphysics::DensityType<double>(augite_density));

    std::cout << "augite iso pwave velocity :      " << augite_pvel_type.value << std::endl;
    std::cout << "augite iso swave velocity :      " << augite_svel_type.value << std::endl;

    // Albite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> albite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    albite_greenchristoffel.SetComponents(albite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> albite_phase_velocities_x0 = albite_greenchristoffel.PhaseVelocities(albite_density);
    std::cout << "albite phase velocity (x0) [0] : " << albite_phase_velocities_x0[0] << std::endl;
    std::cout << "albite phase velocity (x0) [1] : " << albite_phase_velocities_x0[1] << std::endl;
    std::cout << "albite phase velocity (x0) [2] : " << albite_phase_velocities_x0[2] << std::endl;

    albite_greenchristoffel.SetComponents(albite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> albite_phase_velocities_x1 = albite_greenchristoffel.PhaseVelocities(albite_density);
    std::cout << "albite phase velocity (x1) [0] : " << albite_phase_velocities_x1[0] << std::endl;
    std::cout << "albite phase velocity (x1) [1] : " << albite_phase_velocities_x1[1] << std::endl;
    std::cout << "albite phase velocity (x1) [2] : " << albite_phase_velocities_x1[2] << std::endl;

    albite_greenchristoffel.SetComponents(albite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> albite_phase_velocities_x2 = albite_greenchristoffel.PhaseVelocities(albite_density);
    std::cout << "albite phase velocity (x2) [0] : " << albite_phase_velocities_x2[0] << std::endl;
    std::cout << "albite phase velocity (x2) [1] : " << albite_phase_velocities_x2[1] << std::endl;
    std::cout << "albite phase velocity (x2) [2] : " << albite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> albite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(albite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(albite_shear_modulus), mpc::rockphysics::DensityType<double>(albite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> albite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(albite_shear_modulus), mpc::rockphysics::DensityType<double>(albite_density));

    std::cout << "albite iso pwave velocity :      " << albite_pvel_type.value << std::endl;
    std::cout << "albite iso swave velocity :      " << albite_svel_type.value << std::endl;

    // Anorthite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> anorthite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    anorthite_greenchristoffel.SetComponents(anorthite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> anorthite_phase_velocities_x0 = anorthite_greenchristoffel.PhaseVelocities(anorthite_density);
    std::cout << "anorthite phase velocity (x0) [0] : " << anorthite_phase_velocities_x0[0] << std::endl;
    std::cout << "anorthite phase velocity (x0) [1] : " << anorthite_phase_velocities_x0[1] << std::endl;
    std::cout << "anorthite phase velocity (x0) [2] : " << anorthite_phase_velocities_x0[2] << std::endl;

    anorthite_greenchristoffel.SetComponents(anorthite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> anorthite_phase_velocities_x1 = anorthite_greenchristoffel.PhaseVelocities(anorthite_density);
    std::cout << "anorthite phase velocity (x1) [0] : " << anorthite_phase_velocities_x1[0] << std::endl;
    std::cout << "anorthite phase velocity (x1) [1] : " << anorthite_phase_velocities_x1[1] << std::endl;
    std::cout << "anorthite phase velocity (x1) [2] : " << anorthite_phase_velocities_x1[2] << std::endl;

    anorthite_greenchristoffel.SetComponents(anorthite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> anorthite_phase_velocities_x2 = anorthite_greenchristoffel.PhaseVelocities(anorthite_density);
    std::cout << "anorthite phase velocity (x2) [0] : " << anorthite_phase_velocities_x2[0] << std::endl;
    std::cout << "anorthite phase velocity (x2) [1] : " << anorthite_phase_velocities_x2[1] << std::endl;
    std::cout << "anorthite phase velocity (x2) [2] : " << anorthite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> anorthite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(anorthite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(anorthite_shear_modulus), mpc::rockphysics::DensityType<double>(anorthite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> anorthite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(anorthite_shear_modulus), mpc::rockphysics::DensityType<double>(anorthite_density));

    std::cout << "anorthite iso pwave velocity :      " << anorthite_pvel_type.value << std::endl;
    std::cout << "anorthite iso swave velocity :      " << anorthite_svel_type.value << std::endl;

    // Labradorite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> labradorite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    labradorite_greenchristoffel.SetComponents(labradorite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> labradorite_phase_velocities_x0 = labradorite_greenchristoffel.PhaseVelocities(labradorite_density);
    std::cout << "labradorite phase velocity (x0) [0] : " << labradorite_phase_velocities_x0[0] << std::endl;
    std::cout << "labradorite phase velocity (x0) [1] : " << labradorite_phase_velocities_x0[1] << std::endl;
    std::cout << "labradorite phase velocity (x0) [2] : " << labradorite_phase_velocities_x0[2] << std::endl;

    labradorite_greenchristoffel.SetComponents(labradorite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> labradorite_phase_velocities_x1 = labradorite_greenchristoffel.PhaseVelocities(labradorite_density);
    std::cout << "labradorite phase velocity (x1) [0] : " << labradorite_phase_velocities_x1[0] << std::endl;
    std::cout << "labradorite phase velocity (x1) [1] : " << labradorite_phase_velocities_x1[1] << std::endl;
    std::cout << "labradorite phase velocity (x1) [2] : " << labradorite_phase_velocities_x1[2] << std::endl;

    labradorite_greenchristoffel.SetComponents(labradorite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> labradorite_phase_velocities_x2 = labradorite_greenchristoffel.PhaseVelocities(labradorite_density);
    std::cout << "labradorite phase velocity (x2) [0] : " << labradorite_phase_velocities_x2[0] << std::endl;
    std::cout << "labradorite phase velocity (x2) [1] : " << labradorite_phase_velocities_x2[1] << std::endl;
    std::cout << "labradorite phase velocity (x2) [2] : " << labradorite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> labradorite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(labradorite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(labradorite_shear_modulus), mpc::rockphysics::DensityType<double>(labradorite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> labradorite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(labradorite_shear_modulus), mpc::rockphysics::DensityType<double>(labradorite_density));

    std::cout << "labradorite iso pwave velocity :      " << labradorite_pvel_type.value << std::endl;
    std::cout << "labradorite iso swave velocity :      " << labradorite_svel_type.value << std::endl;

    // Microcline
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> microcline_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    microcline_greenchristoffel.SetComponents(microcline_stiffness_tensor, normal_vector_x0);
    std::array<double,3> microcline_phase_velocities_x0 = microcline_greenchristoffel.PhaseVelocities(microcline_density);
    std::cout << "microcline phase velocity (x0) [0] : " << microcline_phase_velocities_x0[0] << std::endl;
    std::cout << "microcline phase velocity (x0) [1] : " << microcline_phase_velocities_x0[1] << std::endl;
    std::cout << "microcline phase velocity (x0) [2] : " << microcline_phase_velocities_x0[2] << std::endl;

    microcline_greenchristoffel.SetComponents(microcline_stiffness_tensor, normal_vector_x1);
    std::array<double,3> microcline_phase_velocities_x1 = microcline_greenchristoffel.PhaseVelocities(microcline_density);
    std::cout << "microcline phase velocity (x1) [0] : " << microcline_phase_velocities_x1[0] << std::endl;
    std::cout << "microcline phase velocity (x1) [1] : " << microcline_phase_velocities_x1[1] << std::endl;
    std::cout << "microcline phase velocity (x1) [2] : " << microcline_phase_velocities_x1[2] << std::endl;

    microcline_greenchristoffel.SetComponents(microcline_stiffness_tensor, normal_vector_x2);
    std::array<double,3> microcline_phase_velocities_x2 = microcline_greenchristoffel.PhaseVelocities(microcline_density);
    std::cout << "microcline phase velocity (x2) [0] : " << microcline_phase_velocities_x2[0] << std::endl;
    std::cout << "microcline phase velocity (x2) [1] : " << microcline_phase_velocities_x2[1] << std::endl;
    std::cout << "microcline phase velocity (x2) [2] : " << microcline_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> microcline_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(microcline_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(microcline_shear_modulus), mpc::rockphysics::DensityType<double>(microcline_density));

    mpc::rockphysics::ShearWaveVelocityType<double> microcline_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(microcline_shear_modulus), mpc::rockphysics::DensityType<double>(microcline_density));

    std::cout << "microcline iso pwave velocity :      " << microcline_pvel_type.value << std::endl;
    std::cout << "microcline iso swave velocity :      " << microcline_svel_type.value << std::endl;

    // Oligoclase
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> oligoclase_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    oligoclase_greenchristoffel.SetComponents(oligoclase_stiffness_tensor, normal_vector_x0);
    std::array<double,3> oligoclase_phase_velocities_x0 = oligoclase_greenchristoffel.PhaseVelocities(oligoclase_density);
    std::cout << "oligoclase phase velocity (x0) [0] : " << oligoclase_phase_velocities_x0[0] << std::endl;
    std::cout << "oligoclase phase velocity (x0) [1] : " << oligoclase_phase_velocities_x0[1] << std::endl;
    std::cout << "oligoclase phase velocity (x0) [2] : " << oligoclase_phase_velocities_x0[2] << std::endl;

    oligoclase_greenchristoffel.SetComponents(oligoclase_stiffness_tensor, normal_vector_x1);
    std::array<double,3> oligoclase_phase_velocities_x1 = oligoclase_greenchristoffel.PhaseVelocities(oligoclase_density);
    std::cout << "oligoclase phase velocity (x1) [0] : " << oligoclase_phase_velocities_x1[0] << std::endl;
    std::cout << "oligoclase phase velocity (x1) [1] : " << oligoclase_phase_velocities_x1[1] << std::endl;
    std::cout << "oligoclase phase velocity (x1) [2] : " << oligoclase_phase_velocities_x1[2] << std::endl;

    oligoclase_greenchristoffel.SetComponents(oligoclase_stiffness_tensor, normal_vector_x2);
    std::array<double,3> oligoclase_phase_velocities_x2 = oligoclase_greenchristoffel.PhaseVelocities(oligoclase_density);
    std::cout << "oligoclase phase velocity (x2) [0] : " << oligoclase_phase_velocities_x2[0] << std::endl;
    std::cout << "oligoclase phase velocity (x2) [1] : " << oligoclase_phase_velocities_x2[1] << std::endl;
    std::cout << "oligoclase phase velocity (x2) [2] : " << oligoclase_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> oligoclase_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(oligoclase_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(oligoclase_shear_modulus), mpc::rockphysics::DensityType<double>(oligoclase_density));

    mpc::rockphysics::ShearWaveVelocityType<double> oligoclase_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(oligoclase_shear_modulus), mpc::rockphysics::DensityType<double>(oligoclase_density));

    std::cout << "oligoclase iso pwave velocity :      " << oligoclase_pvel_type.value << std::endl;
    std::cout << "oligoclase iso swave velocity :      " << oligoclase_svel_type.value << std::endl;

    // Coesite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> coesite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    coesite_greenchristoffel.SetComponents(coesite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> coesite_phase_velocities_x0 = coesite_greenchristoffel.PhaseVelocities(coesite_density);
    std::cout << "coesite phase velocity (x0) [0] : " << coesite_phase_velocities_x0[0] << std::endl;
    std::cout << "coesite phase velocity (x0) [1] : " << coesite_phase_velocities_x0[1] << std::endl;
    std::cout << "coesite phase velocity (x0) [2] : " << coesite_phase_velocities_x0[2] << std::endl;

    coesite_greenchristoffel.SetComponents(coesite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> coesite_phase_velocities_x1 = coesite_greenchristoffel.PhaseVelocities(coesite_density);
    std::cout << "coesite phase velocity (x1) [0] : " << coesite_phase_velocities_x1[0] << std::endl;
    std::cout << "coesite phase velocity (x1) [1] : " << coesite_phase_velocities_x1[1] << std::endl;
    std::cout << "coesite phase velocity (x1) [2] : " << coesite_phase_velocities_x1[2] << std::endl;

    coesite_greenchristoffel.SetComponents(coesite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> coesite_phase_velocities_x2 = coesite_greenchristoffel.PhaseVelocities(coesite_density);
    std::cout << "coesite phase velocity (x2) [0] : " << coesite_phase_velocities_x2[0] << std::endl;
    std::cout << "coesite phase velocity (x2) [1] : " << coesite_phase_velocities_x2[1] << std::endl;
    std::cout << "coesite phase velocity (x2) [2] : " << coesite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> coesite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(coesite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(coesite_shear_modulus), mpc::rockphysics::DensityType<double>(coesite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> coesite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(coesite_shear_modulus), mpc::rockphysics::DensityType<double>(coesite_density));

    std::cout << "coesite iso pwave velocity :      " << coesite_pvel_type.value << std::endl;
    std::cout << "coesite iso swave velocity :      " << coesite_svel_type.value << std::endl;

    // Epidote
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> epidote_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    epidote_greenchristoffel.SetComponents(epidote_stiffness_tensor, normal_vector_x0);
    std::array<double,3> epidote_phase_velocities_x0 = epidote_greenchristoffel.PhaseVelocities(epidote_density);
    std::cout << "epidote phase velocity (x0) [0] : " << epidote_phase_velocities_x0[0] << std::endl;
    std::cout << "epidote phase velocity (x0) [1] : " << epidote_phase_velocities_x0[1] << std::endl;
    std::cout << "epidote phase velocity (x0) [2] : " << epidote_phase_velocities_x0[2] << std::endl;

    epidote_greenchristoffel.SetComponents(epidote_stiffness_tensor, normal_vector_x1);
    std::array<double,3> epidote_phase_velocities_x1 = epidote_greenchristoffel.PhaseVelocities(epidote_density);
    std::cout << "epidote phase velocity (x1) [0] : " << epidote_phase_velocities_x1[0] << std::endl;
    std::cout << "epidote phase velocity (x1) [1] : " << epidote_phase_velocities_x1[1] << std::endl;
    std::cout << "epidote phase velocity (x1) [2] : " << epidote_phase_velocities_x1[2] << std::endl;

    epidote_greenchristoffel.SetComponents(epidote_stiffness_tensor, normal_vector_x2);
    std::array<double,3> epidote_phase_velocities_x2 = epidote_greenchristoffel.PhaseVelocities(epidote_density);
    std::cout << "epidote phase velocity (x2) [0] : " << epidote_phase_velocities_x2[0] << std::endl;
    std::cout << "epidote phase velocity (x2) [1] : " << epidote_phase_velocities_x2[1] << std::endl;
    std::cout << "epidote phase velocity (x2) [2] : " << epidote_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> epidote_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(epidote_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(epidote_shear_modulus), mpc::rockphysics::DensityType<double>(epidote_density));

    mpc::rockphysics::ShearWaveVelocityType<double> epidote_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(epidote_shear_modulus), mpc::rockphysics::DensityType<double>(epidote_density));

    std::cout << "epidote iso pwave velocity :      " << epidote_pvel_type.value << std::endl;
    std::cout << "epidote iso swave velocity :      " << epidote_svel_type.value << std::endl;

    // Hornblende
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> hornblende_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    hornblende_greenchristoffel.SetComponents(hornblende_stiffness_tensor, normal_vector_x0);
    std::array<double,3> hornblende_phase_velocities_x0 = hornblende_greenchristoffel.PhaseVelocities(hornblende_density);
    std::cout << "hornblende phase velocity (x0) [0] : " << hornblende_phase_velocities_x0[0] << std::endl;
    std::cout << "hornblende phase velocity (x0) [1] : " << hornblende_phase_velocities_x0[1] << std::endl;
    std::cout << "hornblende phase velocity (x0) [2] : " << hornblende_phase_velocities_x0[2] << std::endl;

    hornblende_greenchristoffel.SetComponents(hornblende_stiffness_tensor, normal_vector_x1);
    std::array<double,3> hornblende_phase_velocities_x1 = hornblende_greenchristoffel.PhaseVelocities(hornblende_density);
    std::cout << "hornblende phase velocity (x1) [0] : " << hornblende_phase_velocities_x1[0] << std::endl;
    std::cout << "hornblende phase velocity (x1) [1] : " << hornblende_phase_velocities_x1[1] << std::endl;
    std::cout << "hornblende phase velocity (x1) [2] : " << hornblende_phase_velocities_x1[2] << std::endl;

    hornblende_greenchristoffel.SetComponents(hornblende_stiffness_tensor, normal_vector_x2);
    std::array<double,3> hornblende_phase_velocities_x2 = hornblende_greenchristoffel.PhaseVelocities(hornblende_density);
    std::cout << "hornblende phase velocity (x2) [0] : " << hornblende_phase_velocities_x2[0] << std::endl;
    std::cout << "hornblende phase velocity (x2) [1] : " << hornblende_phase_velocities_x2[1] << std::endl;
    std::cout << "hornblende phase velocity (x2) [2] : " << hornblende_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> hornblende_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(hornblende_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(hornblende_shear_modulus), mpc::rockphysics::DensityType<double>(hornblende_density));

    mpc::rockphysics::ShearWaveVelocityType<double> hornblende_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(hornblende_shear_modulus), mpc::rockphysics::DensityType<double>(hornblende_density));

    std::cout << "hornblende iso pwave velocity :      " << hornblende_pvel_type.value << std::endl;
    std::cout << "hornblende iso swave velocity :      " << hornblende_svel_type.value << std::endl;

    // Muscovite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> muscovite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    muscovite_greenchristoffel.SetComponents(muscovite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> muscovite_phase_velocities_x0 = muscovite_greenchristoffel.PhaseVelocities(muscovite_density);
    std::cout << "muscovite phase velocity (x0) [0] : " << muscovite_phase_velocities_x0[0] << std::endl;
    std::cout << "muscovite phase velocity (x0) [1] : " << muscovite_phase_velocities_x0[1] << std::endl;
    std::cout << "muscovite phase velocity (x0) [2] : " << muscovite_phase_velocities_x0[2] << std::endl;

    muscovite_greenchristoffel.SetComponents(muscovite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> muscovite_phase_velocities_x1 = muscovite_greenchristoffel.PhaseVelocities(muscovite_density);
    std::cout << "muscovite phase velocity (x1) [0] : " << muscovite_phase_velocities_x1[0] << std::endl;
    std::cout << "muscovite phase velocity (x1) [1] : " << muscovite_phase_velocities_x1[1] << std::endl;
    std::cout << "muscovite phase velocity (x1) [2] : " << muscovite_phase_velocities_x1[2] << std::endl;

    muscovite_greenchristoffel.SetComponents(muscovite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> muscovite_phase_velocities_x2 = muscovite_greenchristoffel.PhaseVelocities(muscovite_density);
    std::cout << "muscovite phase velocity (x2) [0] : " << muscovite_phase_velocities_x2[0] << std::endl;
    std::cout << "muscovite phase velocity (x2) [1] : " << muscovite_phase_velocities_x2[1] << std::endl;
    std::cout << "muscovite phase velocity (x2) [2] : " << muscovite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> muscovite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(muscovite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(muscovite_shear_modulus), mpc::rockphysics::DensityType<double>(muscovite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> muscovite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(muscovite_shear_modulus), mpc::rockphysics::DensityType<double>(muscovite_density));

    std::cout << "muscovite iso pwave velocity :      " << muscovite_pvel_type.value << std::endl;
    std::cout << "muscovite iso swave velocity :      " << muscovite_svel_type.value << std::endl;

    // Gypsum
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> gypsum_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    gypsum_greenchristoffel.SetComponents(gypsum_stiffness_tensor, normal_vector_x0);
    std::array<double,3> gypsum_phase_velocities_x0 = gypsum_greenchristoffel.PhaseVelocities(gypsum_density);
    std::cout << "gypsum phase velocity (x0) [0] : " << gypsum_phase_velocities_x0[0] << std::endl;
    std::cout << "gypsum phase velocity (x0) [1] : " << gypsum_phase_velocities_x0[1] << std::endl;
    std::cout << "gypsum phase velocity (x0) [2] : " << gypsum_phase_velocities_x0[2] << std::endl;

    gypsum_greenchristoffel.SetComponents(gypsum_stiffness_tensor, normal_vector_x1);
    std::array<double,3> gypsum_phase_velocities_x1 = gypsum_greenchristoffel.PhaseVelocities(gypsum_density);
    std::cout << "gypsum phase velocity (x1) [0] : " << gypsum_phase_velocities_x1[0] << std::endl;
    std::cout << "gypsum phase velocity (x1) [1] : " << gypsum_phase_velocities_x1[1] << std::endl;
    std::cout << "gypsum phase velocity (x1) [2] : " << gypsum_phase_velocities_x1[2] << std::endl;

    gypsum_greenchristoffel.SetComponents(gypsum_stiffness_tensor, normal_vector_x2);
    std::array<double,3> gypsum_phase_velocities_x2 = gypsum_greenchristoffel.PhaseVelocities(gypsum_density);
    std::cout << "gypsum phase velocity (x2) [0] : " << gypsum_phase_velocities_x2[0] << std::endl;
    std::cout << "gypsum phase velocity (x2) [1] : " << gypsum_phase_velocities_x2[1] << std::endl;
    std::cout << "gypsum phase velocity (x2) [2] : " << gypsum_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> gypsum_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(gypsum_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(gypsum_shear_modulus), mpc::rockphysics::DensityType<double>(gypsum_density));

    mpc::rockphysics::ShearWaveVelocityType<double> gypsum_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(gypsum_shear_modulus), mpc::rockphysics::DensityType<double>(gypsum_density));

    std::cout << "gypsum iso pwave velocity :      " << gypsum_pvel_type.value << std::endl;
    std::cout << "gypsum iso swave velocity :      " << gypsum_svel_type.value << std::endl;

    // Enstatite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> enstatite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    enstatite_greenchristoffel.SetComponents(enstatite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> enstatite_phase_velocities_x0 = enstatite_greenchristoffel.PhaseVelocities(enstatite_density);
    std::cout << "enstatite phase velocity (x0) [0] : " << enstatite_phase_velocities_x0[0] << std::endl;
    std::cout << "enstatite phase velocity (x0) [1] : " << enstatite_phase_velocities_x0[1] << std::endl;
    std::cout << "enstatite phase velocity (x0) [2] : " << enstatite_phase_velocities_x0[2] << std::endl;

    enstatite_greenchristoffel.SetComponents(enstatite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> enstatite_phase_velocities_x1 = enstatite_greenchristoffel.PhaseVelocities(enstatite_density);
    std::cout << "enstatite phase velocity (x1) [0] : " << enstatite_phase_velocities_x1[0] << std::endl;
    std::cout << "enstatite phase velocity (x1) [1] : " << enstatite_phase_velocities_x1[1] << std::endl;
    std::cout << "enstatite phase velocity (x1) [2] : " << enstatite_phase_velocities_x1[2] << std::endl;

    enstatite_greenchristoffel.SetComponents(enstatite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> enstatite_phase_velocities_x2 = enstatite_greenchristoffel.PhaseVelocities(enstatite_density);
    std::cout << "enstatite phase velocity (x2) [0] : " << enstatite_phase_velocities_x2[0] << std::endl;
    std::cout << "enstatite phase velocity (x2) [1] : " << enstatite_phase_velocities_x2[1] << std::endl;
    std::cout << "enstatite phase velocity (x2) [2] : " << enstatite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> enstatite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(enstatite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(enstatite_shear_modulus), mpc::rockphysics::DensityType<double>(enstatite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> enstatite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(enstatite_shear_modulus), mpc::rockphysics::DensityType<double>(enstatite_density));

    std::cout << "enstatite iso pwave velocity :      " << enstatite_pvel_type.value << std::endl;
    std::cout << "enstatite iso swave velocity :      " << enstatite_svel_type.value << std::endl;

    // Forsterite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> forsterite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    forsterite_greenchristoffel.SetComponents(forsterite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> forsterite_phase_velocities_x0 = forsterite_greenchristoffel.PhaseVelocities(forsterite_density);
    std::cout << "forsterite phase velocity (x0) [0] : " << forsterite_phase_velocities_x0[0] << std::endl;
    std::cout << "forsterite phase velocity (x0) [1] : " << forsterite_phase_velocities_x0[1] << std::endl;
    std::cout << "forsterite phase velocity (x0) [2] : " << forsterite_phase_velocities_x0[2] << std::endl;

    forsterite_greenchristoffel.SetComponents(forsterite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> forsterite_phase_velocities_x1 = forsterite_greenchristoffel.PhaseVelocities(forsterite_density);
    std::cout << "forsterite phase velocity (x1) [0] : " << forsterite_phase_velocities_x1[0] << std::endl;
    std::cout << "forsterite phase velocity (x1) [1] : " << forsterite_phase_velocities_x1[1] << std::endl;
    std::cout << "forsterite phase velocity (x1) [2] : " << forsterite_phase_velocities_x1[2] << std::endl;

    forsterite_greenchristoffel.SetComponents(forsterite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> forsterite_phase_velocities_x2 = forsterite_greenchristoffel.PhaseVelocities(forsterite_density);
    std::cout << "forsterite phase velocity (x2) [0] : " << forsterite_phase_velocities_x2[0] << std::endl;
    std::cout << "forsterite phase velocity (x2) [1] : " << forsterite_phase_velocities_x2[1] << std::endl;
    std::cout << "forsterite phase velocity (x2) [2] : " << forsterite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> forsterite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(forsterite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(forsterite_shear_modulus), mpc::rockphysics::DensityType<double>(forsterite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> forsterite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(forsterite_shear_modulus), mpc::rockphysics::DensityType<double>(forsterite_density));

    std::cout << "forsterite iso pwave velocity :      " << forsterite_pvel_type.value << std::endl;
    std::cout << "forsterite iso swave velocity :      " << forsterite_svel_type.value << std::endl;

    // Fayalite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> fayalite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    fayalite_greenchristoffel.SetComponents(fayalite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> fayalite_phase_velocities_x0 = fayalite_greenchristoffel.PhaseVelocities(fayalite_density);
    std::cout << "fayalite phase velocity (x0) [0] : " << fayalite_phase_velocities_x0[0] << std::endl;
    std::cout << "fayalite phase velocity (x0) [1] : " << fayalite_phase_velocities_x0[1] << std::endl;
    std::cout << "fayalite phase velocity (x0) [2] : " << fayalite_phase_velocities_x0[2] << std::endl;

    fayalite_greenchristoffel.SetComponents(fayalite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> fayalite_phase_velocities_x1 = fayalite_greenchristoffel.PhaseVelocities(fayalite_density);
    std::cout << "fayalite phase velocity (x1) [0] : " << fayalite_phase_velocities_x1[0] << std::endl;
    std::cout << "fayalite phase velocity (x1) [1] : " << fayalite_phase_velocities_x1[1] << std::endl;
    std::cout << "fayalite phase velocity (x1) [2] : " << fayalite_phase_velocities_x1[2] << std::endl;

    fayalite_greenchristoffel.SetComponents(fayalite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> fayalite_phase_velocities_x2 = fayalite_greenchristoffel.PhaseVelocities(fayalite_density);
    std::cout << "fayalite phase velocity (x2) [0] : " << fayalite_phase_velocities_x2[0] << std::endl;
    std::cout << "fayalite phase velocity (x2) [1] : " << fayalite_phase_velocities_x2[1] << std::endl;
    std::cout << "fayalite phase velocity (x2) [2] : " << fayalite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> fayalite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(fayalite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(fayalite_shear_modulus), mpc::rockphysics::DensityType<double>(fayalite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> fayalite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(fayalite_shear_modulus), mpc::rockphysics::DensityType<double>(fayalite_density));

    std::cout << "fayalite iso pwave velocity :      " << fayalite_pvel_type.value << std::endl;
    std::cout << "fayalite iso swave velocity :      " << fayalite_svel_type.value << std::endl;

    // Montecellite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> montecellite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    montecellite_greenchristoffel.SetComponents(montecellite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> montecellite_phase_velocities_x0 = montecellite_greenchristoffel.PhaseVelocities(montecellite_density);
    std::cout << "montecellite phase velocity (x0) [0] : " << montecellite_phase_velocities_x0[0] << std::endl;
    std::cout << "montecellite phase velocity (x0) [1] : " << montecellite_phase_velocities_x0[1] << std::endl;
    std::cout << "montecellite phase velocity (x0) [2] : " << montecellite_phase_velocities_x0[2] << std::endl;

    montecellite_greenchristoffel.SetComponents(montecellite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> montecellite_phase_velocities_x1 = montecellite_greenchristoffel.PhaseVelocities(montecellite_density);
    std::cout << "montecellite phase velocity (x1) [0] : " << montecellite_phase_velocities_x1[0] << std::endl;
    std::cout << "montecellite phase velocity (x1) [1] : " << montecellite_phase_velocities_x1[1] << std::endl;
    std::cout << "montecellite phase velocity (x1) [2] : " << montecellite_phase_velocities_x1[2] << std::endl;

    montecellite_greenchristoffel.SetComponents(montecellite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> montecellite_phase_velocities_x2 = montecellite_greenchristoffel.PhaseVelocities(montecellite_density);
    std::cout << "montecellite phase velocity (x2) [0] : " << montecellite_phase_velocities_x2[0] << std::endl;
    std::cout << "montecellite phase velocity (x2) [1] : " << montecellite_phase_velocities_x2[1] << std::endl;
    std::cout << "montecellite phase velocity (x2) [2] : " << montecellite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> montecellite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(montecellite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(montecellite_shear_modulus), mpc::rockphysics::DensityType<double>(montecellite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> montecellite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(montecellite_shear_modulus), mpc::rockphysics::DensityType<double>(montecellite_density));

    std::cout << "montecellite iso pwave velocity :      " << montecellite_pvel_type.value << std::endl;
    std::cout << "montecellite iso swave velocity :      " << montecellite_svel_type.value << std::endl;

    // Andalusite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> andalusite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    andalusite_greenchristoffel.SetComponents(andalusite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> andalusite_phase_velocities_x0 = andalusite_greenchristoffel.PhaseVelocities(andalusite_density);
    std::cout << "andalusite phase velocity (x0) [0] : " << andalusite_phase_velocities_x0[0] << std::endl;
    std::cout << "andalusite phase velocity (x0) [1] : " << andalusite_phase_velocities_x0[1] << std::endl;
    std::cout << "andalusite phase velocity (x0) [2] : " << andalusite_phase_velocities_x0[2] << std::endl;

    andalusite_greenchristoffel.SetComponents(andalusite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> andalusite_phase_velocities_x1 = andalusite_greenchristoffel.PhaseVelocities(andalusite_density);
    std::cout << "andalusite phase velocity (x1) [0] : " << andalusite_phase_velocities_x1[0] << std::endl;
    std::cout << "andalusite phase velocity (x1) [1] : " << andalusite_phase_velocities_x1[1] << std::endl;
    std::cout << "andalusite phase velocity (x1) [2] : " << andalusite_phase_velocities_x1[2] << std::endl;

    andalusite_greenchristoffel.SetComponents(andalusite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> andalusite_phase_velocities_x2 = andalusite_greenchristoffel.PhaseVelocities(andalusite_density);
    std::cout << "andalusite phase velocity (x2) [0] : " << andalusite_phase_velocities_x2[0] << std::endl;
    std::cout << "andalusite phase velocity (x2) [1] : " << andalusite_phase_velocities_x2[1] << std::endl;
    std::cout << "andalusite phase velocity (x2) [2] : " << andalusite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> andalusite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(andalusite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(andalusite_shear_modulus), mpc::rockphysics::DensityType<double>(andalusite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> andalusite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(andalusite_shear_modulus), mpc::rockphysics::DensityType<double>(andalusite_density));

    std::cout << "andalusite iso pwave velocity :      " << andalusite_pvel_type.value << std::endl;
    std::cout << "andalusite iso swave velocity :      " << andalusite_svel_type.value << std::endl;

    // Silimanite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> silimanite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    silimanite_greenchristoffel.SetComponents(silimanite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> silimanite_phase_velocities_x0 = silimanite_greenchristoffel.PhaseVelocities(silimanite_density);
    std::cout << "silimanite phase velocity (x0) [0] : " << silimanite_phase_velocities_x0[0] << std::endl;
    std::cout << "silimanite phase velocity (x0) [1] : " << silimanite_phase_velocities_x0[1] << std::endl;
    std::cout << "silimanite phase velocity (x0) [2] : " << silimanite_phase_velocities_x0[2] << std::endl;

    silimanite_greenchristoffel.SetComponents(silimanite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> silimanite_phase_velocities_x1 = silimanite_greenchristoffel.PhaseVelocities(silimanite_density);
    std::cout << "silimanite phase velocity (x1) [0] : " << silimanite_phase_velocities_x1[0] << std::endl;
    std::cout << "silimanite phase velocity (x1) [1] : " << silimanite_phase_velocities_x1[1] << std::endl;
    std::cout << "silimanite phase velocity (x1) [2] : " << silimanite_phase_velocities_x1[2] << std::endl;

    silimanite_greenchristoffel.SetComponents(silimanite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> silimanite_phase_velocities_x2 = silimanite_greenchristoffel.PhaseVelocities(silimanite_density);
    std::cout << "silimanite phase velocity (x2) [0] : " << silimanite_phase_velocities_x2[0] << std::endl;
    std::cout << "silimanite phase velocity (x2) [1] : " << silimanite_phase_velocities_x2[1] << std::endl;
    std::cout << "silimanite phase velocity (x2) [2] : " << silimanite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> silimanite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(silimanite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(silimanite_shear_modulus), mpc::rockphysics::DensityType<double>(silimanite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> silimanite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(silimanite_shear_modulus), mpc::rockphysics::DensityType<double>(silimanite_density));

    std::cout << "silimanite iso pwave velocity :      " << silimanite_pvel_type.value << std::endl;
    std::cout << "silimanite iso swave velocity :      " << silimanite_svel_type.value << std::endl;

    // Barite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> barite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    barite_greenchristoffel.SetComponents(barite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> barite_phase_velocities_x0 = barite_greenchristoffel.PhaseVelocities(barite_density);
    std::cout << "barite phase velocity (x0) [0] : " << barite_phase_velocities_x0[0] << std::endl;
    std::cout << "barite phase velocity (x0) [1] : " << barite_phase_velocities_x0[1] << std::endl;
    std::cout << "barite phase velocity (x0) [2] : " << barite_phase_velocities_x0[2] << std::endl;

    barite_greenchristoffel.SetComponents(barite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> barite_phase_velocities_x1 = barite_greenchristoffel.PhaseVelocities(barite_density);
    std::cout << "barite phase velocity (x1) [0] : " << barite_phase_velocities_x1[0] << std::endl;
    std::cout << "barite phase velocity (x1) [1] : " << barite_phase_velocities_x1[1] << std::endl;
    std::cout << "barite phase velocity (x1) [2] : " << barite_phase_velocities_x1[2] << std::endl;

    barite_greenchristoffel.SetComponents(barite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> barite_phase_velocities_x2 = barite_greenchristoffel.PhaseVelocities(barite_density);
    std::cout << "barite phase velocity (x2) [0] : " << barite_phase_velocities_x2[0] << std::endl;
    std::cout << "barite phase velocity (x2) [1] : " << barite_phase_velocities_x2[1] << std::endl;
    std::cout << "barite phase velocity (x2) [2] : " << barite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> barite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(barite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(barite_shear_modulus), mpc::rockphysics::DensityType<double>(barite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> barite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(barite_shear_modulus), mpc::rockphysics::DensityType<double>(barite_density));

    std::cout << "barite iso pwave velocity :      " << barite_pvel_type.value << std::endl;
    std::cout << "barite iso swave velocity :      " << barite_svel_type.value << std::endl;

    // Anhydrite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> anhydrite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    anhydrite_greenchristoffel.SetComponents(anhydrite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> anhydrite_phase_velocities_x0 = anhydrite_greenchristoffel.PhaseVelocities(anhydrite_density);
    std::cout << "anhydrite phase velocity (x0) [0] : " << anhydrite_phase_velocities_x0[0] << std::endl;
    std::cout << "anhydrite phase velocity (x0) [1] : " << anhydrite_phase_velocities_x0[1] << std::endl;
    std::cout << "anhydrite phase velocity (x0) [2] : " << anhydrite_phase_velocities_x0[2] << std::endl;

    anhydrite_greenchristoffel.SetComponents(anhydrite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> anhydrite_phase_velocities_x1 = anhydrite_greenchristoffel.PhaseVelocities(anhydrite_density);
    std::cout << "anhydrite phase velocity (x1) [0] : " << anhydrite_phase_velocities_x1[0] << std::endl;
    std::cout << "anhydrite phase velocity (x1) [1] : " << anhydrite_phase_velocities_x1[1] << std::endl;
    std::cout << "anhydrite phase velocity (x1) [2] : " << anhydrite_phase_velocities_x1[2] << std::endl;

    anhydrite_greenchristoffel.SetComponents(anhydrite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> anhydrite_phase_velocities_x2 = anhydrite_greenchristoffel.PhaseVelocities(anhydrite_density);
    std::cout << "anhydrite phase velocity (x2) [0] : " << anhydrite_phase_velocities_x2[0] << std::endl;
    std::cout << "anhydrite phase velocity (x2) [1] : " << anhydrite_phase_velocities_x2[1] << std::endl;
    std::cout << "anhydrite phase velocity (x2) [2] : " << anhydrite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> anhydrite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(anhydrite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(anhydrite_shear_modulus), mpc::rockphysics::DensityType<double>(anhydrite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> anhydrite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(anhydrite_shear_modulus), mpc::rockphysics::DensityType<double>(anhydrite_density));

    std::cout << "anhydrite iso pwave velocity :      " << anhydrite_pvel_type.value << std::endl;
    std::cout << "anhydrite iso swave velocity :      " << anhydrite_svel_type.value << std::endl;

    // Dolomite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> dolomite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    dolomite_greenchristoffel.SetComponents(dolomite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> dolomite_phase_velocities_x0 = dolomite_greenchristoffel.PhaseVelocities(dolomite_density);
    std::cout << "dolomite phase velocity (x0) [0] : " << dolomite_phase_velocities_x0[0] << std::endl;
    std::cout << "dolomite phase velocity (x0) [1] : " << dolomite_phase_velocities_x0[1] << std::endl;
    std::cout << "dolomite phase velocity (x0) [2] : " << dolomite_phase_velocities_x0[2] << std::endl;

    dolomite_greenchristoffel.SetComponents(dolomite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> dolomite_phase_velocities_x1 = dolomite_greenchristoffel.PhaseVelocities(dolomite_density);
    std::cout << "dolomite phase velocity (x1) [0] : " << dolomite_phase_velocities_x1[0] << std::endl;
    std::cout << "dolomite phase velocity (x1) [1] : " << dolomite_phase_velocities_x1[1] << std::endl;
    std::cout << "dolomite phase velocity (x1) [2] : " << dolomite_phase_velocities_x1[2] << std::endl;

    dolomite_greenchristoffel.SetComponents(dolomite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> dolomite_phase_velocities_x2 = dolomite_greenchristoffel.PhaseVelocities(dolomite_density);
    std::cout << "dolomite phase velocity (x2) [0] : " << dolomite_phase_velocities_x2[0] << std::endl;
    std::cout << "dolomite phase velocity (x2) [1] : " << dolomite_phase_velocities_x2[1] << std::endl;
    std::cout << "dolomite phase velocity (x2) [2] : " << dolomite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> dolomite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(dolomite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(dolomite_shear_modulus), mpc::rockphysics::DensityType<double>(dolomite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> dolomite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(dolomite_shear_modulus), mpc::rockphysics::DensityType<double>(dolomite_density));

    std::cout << "dolomite iso pwave velocity :      " << dolomite_pvel_type.value << std::endl;
    std::cout << "dolomite iso swave velocity :      " << dolomite_svel_type.value << std::endl;

    // Rutile
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> rutile_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    rutile_greenchristoffel.SetComponents(rutile_stiffness_tensor, normal_vector_x0);
    std::array<double,3> rutile_phase_velocities_x0 = rutile_greenchristoffel.PhaseVelocities(rutile_density);
    std::cout << "rutile phase velocity (x0) [0] : " << rutile_phase_velocities_x0[0] << std::endl;
    std::cout << "rutile phase velocity (x0) [1] : " << rutile_phase_velocities_x0[1] << std::endl;
    std::cout << "rutile phase velocity (x0) [2] : " << rutile_phase_velocities_x0[2] << std::endl;

    rutile_greenchristoffel.SetComponents(rutile_stiffness_tensor, normal_vector_x1);
    std::array<double,3> rutile_phase_velocities_x1 = rutile_greenchristoffel.PhaseVelocities(rutile_density);
    std::cout << "rutile phase velocity (x1) [0] : " << rutile_phase_velocities_x1[0] << std::endl;
    std::cout << "rutile phase velocity (x1) [1] : " << rutile_phase_velocities_x1[1] << std::endl;
    std::cout << "rutile phase velocity (x1) [2] : " << rutile_phase_velocities_x1[2] << std::endl;

    rutile_greenchristoffel.SetComponents(rutile_stiffness_tensor, normal_vector_x2);
    std::array<double,3> rutile_phase_velocities_x2 = rutile_greenchristoffel.PhaseVelocities(rutile_density);
    std::cout << "rutile phase velocity (x2) [0] : " << rutile_phase_velocities_x2[0] << std::endl;
    std::cout << "rutile phase velocity (x2) [1] : " << rutile_phase_velocities_x2[1] << std::endl;
    std::cout << "rutile phase velocity (x2) [2] : " << rutile_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> rutile_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(rutile_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(rutile_shear_modulus), mpc::rockphysics::DensityType<double>(rutile_density));

    mpc::rockphysics::ShearWaveVelocityType<double> rutile_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(rutile_shear_modulus), mpc::rockphysics::DensityType<double>(rutile_density));

    std::cout << "rutile iso pwave velocity :      " << rutile_pvel_type.value << std::endl;
    std::cout << "rutile iso swave velocity :      " << rutile_svel_type.value << std::endl;

    // Zircon
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> zircon_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    zircon_greenchristoffel.SetComponents(zircon_stiffness_tensor, normal_vector_x0);
    std::array<double,3> zircon_phase_velocities_x0 = zircon_greenchristoffel.PhaseVelocities(zircon_density);
    std::cout << "zircon phase velocity (x0) [0] : " << zircon_phase_velocities_x0[0] << std::endl;
    std::cout << "zircon phase velocity (x0) [1] : " << zircon_phase_velocities_x0[1] << std::endl;
    std::cout << "zircon phase velocity (x0) [2] : " << zircon_phase_velocities_x0[2] << std::endl;

    zircon_greenchristoffel.SetComponents(zircon_stiffness_tensor, normal_vector_x1);
    std::array<double,3> zircon_phase_velocities_x1 = zircon_greenchristoffel.PhaseVelocities(zircon_density);
    std::cout << "zircon phase velocity (x1) [0] : " << zircon_phase_velocities_x1[0] << std::endl;
    std::cout << "zircon phase velocity (x1) [1] : " << zircon_phase_velocities_x1[1] << std::endl;
    std::cout << "zircon phase velocity (x1) [2] : " << zircon_phase_velocities_x1[2] << std::endl;

    zircon_greenchristoffel.SetComponents(zircon_stiffness_tensor, normal_vector_x2);
    std::array<double,3> zircon_phase_velocities_x2 = zircon_greenchristoffel.PhaseVelocities(zircon_density);
    std::cout << "zircon phase velocity (x2) [0] : " << zircon_phase_velocities_x2[0] << std::endl;
    std::cout << "zircon phase velocity (x2) [1] : " << zircon_phase_velocities_x2[1] << std::endl;
    std::cout << "zircon phase velocity (x2) [2] : " << zircon_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> zircon_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(zircon_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(zircon_shear_modulus), mpc::rockphysics::DensityType<double>(zircon_density));

    mpc::rockphysics::ShearWaveVelocityType<double> zircon_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(zircon_shear_modulus), mpc::rockphysics::DensityType<double>(zircon_density));

    std::cout << "zircon iso pwave velocity :      " << zircon_pvel_type.value << std::endl;
    std::cout << "zircon iso swave velocity :      " << zircon_svel_type.value << std::endl;

    // Corundum
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> corundum_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    corundum_greenchristoffel.SetComponents(corundum_stiffness_tensor, normal_vector_x0);
    std::array<double,3> corundum_phase_velocities_x0 = corundum_greenchristoffel.PhaseVelocities(corundum_density);
    std::cout << "corundum phase velocity (x0) [0] : " << corundum_phase_velocities_x0[0] << std::endl;
    std::cout << "corundum phase velocity (x0) [1] : " << corundum_phase_velocities_x0[1] << std::endl;
    std::cout << "corundum phase velocity (x0) [2] : " << corundum_phase_velocities_x0[2] << std::endl;

    corundum_greenchristoffel.SetComponents(corundum_stiffness_tensor, normal_vector_x1);
    std::array<double,3> corundum_phase_velocities_x1 = corundum_greenchristoffel.PhaseVelocities(corundum_density);
    std::cout << "corundum phase velocity (x1) [0] : " << corundum_phase_velocities_x1[0] << std::endl;
    std::cout << "corundum phase velocity (x1) [1] : " << corundum_phase_velocities_x1[1] << std::endl;
    std::cout << "corundum phase velocity (x1) [2] : " << corundum_phase_velocities_x1[2] << std::endl;

    corundum_greenchristoffel.SetComponents(corundum_stiffness_tensor, normal_vector_x2);
    std::array<double,3> corundum_phase_velocities_x2 = corundum_greenchristoffel.PhaseVelocities(corundum_density);
    std::cout << "corundum phase velocity (x2) [0] : " << corundum_phase_velocities_x2[0] << std::endl;
    std::cout << "corundum phase velocity (x2) [1] : " << corundum_phase_velocities_x2[1] << std::endl;
    std::cout << "corundum phase velocity (x2) [2] : " << corundum_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> corundum_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(corundum_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(corundum_shear_modulus), mpc::rockphysics::DensityType<double>(corundum_density));

    mpc::rockphysics::ShearWaveVelocityType<double> corundum_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(corundum_shear_modulus), mpc::rockphysics::DensityType<double>(corundum_density));

    std::cout << "corundum iso pwave velocity :      " << corundum_pvel_type.value << std::endl;
    std::cout << "corundum iso swave velocity :      " << corundum_svel_type.value << std::endl;

    // Calcite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> calcite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    calcite_greenchristoffel.SetComponents(calcite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> calcite_phase_velocities_x0 = calcite_greenchristoffel.PhaseVelocities(calcite_density);
    std::cout << "calcite phase velocity (x0) [0] : " << calcite_phase_velocities_x0[0] << std::endl;
    std::cout << "calcite phase velocity (x0) [1] : " << calcite_phase_velocities_x0[1] << std::endl;
    std::cout << "calcite phase velocity (x0) [2] : " << calcite_phase_velocities_x0[2] << std::endl;

    calcite_greenchristoffel.SetComponents(calcite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> calcite_phase_velocities_x1 = calcite_greenchristoffel.PhaseVelocities(calcite_density);
    std::cout << "calcite phase velocity (x1) [0] : " << calcite_phase_velocities_x1[0] << std::endl;
    std::cout << "calcite phase velocity (x1) [1] : " << calcite_phase_velocities_x1[1] << std::endl;
    std::cout << "calcite phase velocity (x1) [2] : " << calcite_phase_velocities_x1[2] << std::endl;

    calcite_greenchristoffel.SetComponents(calcite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> calcite_phase_velocities_x2 = calcite_greenchristoffel.PhaseVelocities(calcite_density);
    std::cout << "calcite phase velocity (x2) [0] : " << calcite_phase_velocities_x2[0] << std::endl;
    std::cout << "calcite phase velocity (x2) [1] : " << calcite_phase_velocities_x2[1] << std::endl;
    std::cout << "calcite phase velocity (x2) [2] : " << calcite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> calcite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(calcite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(calcite_shear_modulus), mpc::rockphysics::DensityType<double>(calcite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> calcite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(calcite_shear_modulus), mpc::rockphysics::DensityType<double>(calcite_density));

    std::cout << "calcite iso pwave velocity :      " << calcite_pvel_type.value << std::endl;
    std::cout << "calcite iso swave velocity :      " << calcite_svel_type.value << std::endl;

    // Quartz
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> quartz_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    quartz_greenchristoffel.SetComponents(quartz_stiffness_tensor, normal_vector_x0);
    std::array<double,3> quartz_phase_velocities_x0 = quartz_greenchristoffel.PhaseVelocities(quartz_density);
    std::cout << "quartz phase velocity (x0) [0] : " << quartz_phase_velocities_x0[0] << std::endl;
    std::cout << "quartz phase velocity (x0) [1] : " << quartz_phase_velocities_x0[1] << std::endl;
    std::cout << "quartz phase velocity (x0) [2] : " << quartz_phase_velocities_x0[2] << std::endl;

    quartz_greenchristoffel.SetComponents(quartz_stiffness_tensor, normal_vector_x1);
    std::array<double,3> quartz_phase_velocities_x1 = quartz_greenchristoffel.PhaseVelocities(quartz_density);
    std::cout << "quartz phase velocity (x1) [0] : " << quartz_phase_velocities_x1[0] << std::endl;
    std::cout << "quartz phase velocity (x1) [1] : " << quartz_phase_velocities_x1[1] << std::endl;
    std::cout << "quartz phase velocity (x1) [2] : " << quartz_phase_velocities_x1[2] << std::endl;

    quartz_greenchristoffel.SetComponents(quartz_stiffness_tensor, normal_vector_x2);
    std::array<double,3> quartz_phase_velocities_x2 = quartz_greenchristoffel.PhaseVelocities(quartz_density);
    std::cout << "quartz phase velocity (x2) [0] : " << quartz_phase_velocities_x2[0] << std::endl;
    std::cout << "quartz phase velocity (x2) [1] : " << quartz_phase_velocities_x2[1] << std::endl;
    std::cout << "quartz phase velocity (x2) [2] : " << quartz_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> quartz_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(quartz_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(quartz_shear_modulus), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> quartz_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(quartz_shear_modulus), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "quartz iso pwave velocity :      " << quartz_pvel_type.value << std::endl;
    std::cout << "quartz iso swave velocity :      " << quartz_svel_type.value << std::endl;

    // Tourmaline
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> tourmaline_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    tourmaline_greenchristoffel.SetComponents(tourmaline_stiffness_tensor, normal_vector_x0);
    std::array<double,3> tourmaline_phase_velocities_x0 = tourmaline_greenchristoffel.PhaseVelocities(tourmaline_density);
    std::cout << "tourmaline phase velocity (x0) [0] : " << tourmaline_phase_velocities_x0[0] << std::endl;
    std::cout << "tourmaline phase velocity (x0) [1] : " << tourmaline_phase_velocities_x0[1] << std::endl;
    std::cout << "tourmaline phase velocity (x0) [2] : " << tourmaline_phase_velocities_x0[2] << std::endl;

    tourmaline_greenchristoffel.SetComponents(tourmaline_stiffness_tensor, normal_vector_x1);
    std::array<double,3> tourmaline_phase_velocities_x1 = tourmaline_greenchristoffel.PhaseVelocities(tourmaline_density);
    std::cout << "tourmaline phase velocity (x1) [0] : " << tourmaline_phase_velocities_x1[0] << std::endl;
    std::cout << "tourmaline phase velocity (x1) [1] : " << tourmaline_phase_velocities_x1[1] << std::endl;
    std::cout << "tourmaline phase velocity (x1) [2] : " << tourmaline_phase_velocities_x1[2] << std::endl;

    tourmaline_greenchristoffel.SetComponents(tourmaline_stiffness_tensor, normal_vector_x2);
    std::array<double,3> tourmaline_phase_velocities_x2 = tourmaline_greenchristoffel.PhaseVelocities(tourmaline_density);
    std::cout << "tourmaline phase velocity (x2) [0] : " << tourmaline_phase_velocities_x2[0] << std::endl;
    std::cout << "tourmaline phase velocity (x2) [1] : " << tourmaline_phase_velocities_x2[1] << std::endl;
    std::cout << "tourmaline phase velocity (x2) [2] : " << tourmaline_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> tourmaline_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(tourmaline_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(tourmaline_shear_modulus), mpc::rockphysics::DensityType<double>(tourmaline_density));

    mpc::rockphysics::ShearWaveVelocityType<double> tourmaline_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(tourmaline_shear_modulus), mpc::rockphysics::DensityType<double>(tourmaline_density));

    std::cout << "tourmaline iso pwave velocity :      " << tourmaline_pvel_type.value << std::endl;
    std::cout << "tourmaline iso swave velocity :      " << tourmaline_svel_type.value << std::endl;

    // Beryl
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> beryl_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    beryl_greenchristoffel.SetComponents(beryl_stiffness_tensor, normal_vector_x0);
    std::array<double,3> beryl_phase_velocities_x0 = beryl_greenchristoffel.PhaseVelocities(beryl_density);
    std::cout << "beryl phase velocity (x0) [0] : " << beryl_phase_velocities_x0[0] << std::endl;
    std::cout << "beryl phase velocity (x0) [1] : " << beryl_phase_velocities_x0[1] << std::endl;
    std::cout << "beryl phase velocity (x0) [2] : " << beryl_phase_velocities_x0[2] << std::endl;

    beryl_greenchristoffel.SetComponents(beryl_stiffness_tensor, normal_vector_x1);
    std::array<double,3> beryl_phase_velocities_x1 = beryl_greenchristoffel.PhaseVelocities(beryl_density);
    std::cout << "beryl phase velocity (x1) [0] : " << beryl_phase_velocities_x1[0] << std::endl;
    std::cout << "beryl phase velocity (x1) [1] : " << beryl_phase_velocities_x1[1] << std::endl;
    std::cout << "beryl phase velocity (x1) [2] : " << beryl_phase_velocities_x1[2] << std::endl;

    beryl_greenchristoffel.SetComponents(beryl_stiffness_tensor, normal_vector_x2);
    std::array<double,3> beryl_phase_velocities_x2 = beryl_greenchristoffel.PhaseVelocities(beryl_density);
    std::cout << "beryl phase velocity (x2) [0] : " << beryl_phase_velocities_x2[0] << std::endl;
    std::cout << "beryl phase velocity (x2) [1] : " << beryl_phase_velocities_x2[1] << std::endl;
    std::cout << "beryl phase velocity (x2) [2] : " << beryl_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> beryl_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(beryl_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(beryl_shear_modulus), mpc::rockphysics::DensityType<double>(beryl_density));

    mpc::rockphysics::ShearWaveVelocityType<double> beryl_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(beryl_shear_modulus), mpc::rockphysics::DensityType<double>(beryl_density));

    std::cout << "beryl iso pwave velocity :      " << beryl_pvel_type.value << std::endl;
    std::cout << "beryl iso swave velocity :      " << beryl_svel_type.value << std::endl;

    // Graphite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> graphite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    graphite_greenchristoffel.SetComponents(graphite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> graphite_phase_velocities_x0 = graphite_greenchristoffel.PhaseVelocities(graphite_density);
    std::cout << "graphite phase velocity (x0) [0] : " << graphite_phase_velocities_x0[0] << std::endl;
    std::cout << "graphite phase velocity (x0) [1] : " << graphite_phase_velocities_x0[1] << std::endl;
    std::cout << "graphite phase velocity (x0) [2] : " << graphite_phase_velocities_x0[2] << std::endl;

    graphite_greenchristoffel.SetComponents(graphite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> graphite_phase_velocities_x1 = graphite_greenchristoffel.PhaseVelocities(graphite_density);
    std::cout << "graphite phase velocity (x1) [0] : " << graphite_phase_velocities_x1[0] << std::endl;
    std::cout << "graphite phase velocity (x1) [1] : " << graphite_phase_velocities_x1[1] << std::endl;
    std::cout << "graphite phase velocity (x1) [2] : " << graphite_phase_velocities_x1[2] << std::endl;

    graphite_greenchristoffel.SetComponents(graphite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> graphite_phase_velocities_x2 = graphite_greenchristoffel.PhaseVelocities(graphite_density);
    std::cout << "graphite phase velocity (x2) [0] : " << graphite_phase_velocities_x2[0] << std::endl;
    std::cout << "graphite phase velocity (x2) [1] : " << graphite_phase_velocities_x2[1] << std::endl;
    std::cout << "graphite phase velocity (x2) [2] : " << graphite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> graphite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(graphite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(graphite_shear_modulus), mpc::rockphysics::DensityType<double>(graphite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> graphite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(graphite_shear_modulus), mpc::rockphysics::DensityType<double>(graphite_density));

    std::cout << "graphite iso pwave velocity :      " << graphite_pvel_type.value << std::endl;
    std::cout << "graphite iso swave velocity :      " << graphite_svel_type.value << std::endl;

    // Wusite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> wusite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    wusite_greenchristoffel.SetComponents(wusite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> wusite_phase_velocities_x0 = wusite_greenchristoffel.PhaseVelocities(wusite_density);
    std::cout << "wusite phase velocity (x0) [0] : " << wusite_phase_velocities_x0[0] << std::endl;
    std::cout << "wusite phase velocity (x0) [1] : " << wusite_phase_velocities_x0[1] << std::endl;
    std::cout << "wusite phase velocity (x0) [2] : " << wusite_phase_velocities_x0[2] << std::endl;

    wusite_greenchristoffel.SetComponents(wusite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> wusite_phase_velocities_x1 = wusite_greenchristoffel.PhaseVelocities(wusite_density);
    std::cout << "wusite phase velocity (x1) [0] : " << wusite_phase_velocities_x1[0] << std::endl;
    std::cout << "wusite phase velocity (x1) [1] : " << wusite_phase_velocities_x1[1] << std::endl;
    std::cout << "wusite phase velocity (x1) [2] : " << wusite_phase_velocities_x1[2] << std::endl;

    wusite_greenchristoffel.SetComponents(wusite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> wusite_phase_velocities_x2 = wusite_greenchristoffel.PhaseVelocities(wusite_density);
    std::cout << "wusite phase velocity (x2) [0] : " << wusite_phase_velocities_x2[0] << std::endl;
    std::cout << "wusite phase velocity (x2) [1] : " << wusite_phase_velocities_x2[1] << std::endl;
    std::cout << "wusite phase velocity (x2) [2] : " << wusite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> wusite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(wusite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(wusite_shear_modulus), mpc::rockphysics::DensityType<double>(wusite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> wusite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(wusite_shear_modulus), mpc::rockphysics::DensityType<double>(wusite_density));

    std::cout << "wusite iso pwave velocity :      " << wusite_pvel_type.value << std::endl;
    std::cout << "wusite iso swave velocity :      " << wusite_svel_type.value << std::endl;

    // Manganosite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> manganosite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    manganosite_greenchristoffel.SetComponents(manganosite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> manganosite_phase_velocities_x0 = manganosite_greenchristoffel.PhaseVelocities(manganosite_density);
    std::cout << "manganosite phase velocity (x0) [0] : " << manganosite_phase_velocities_x0[0] << std::endl;
    std::cout << "manganosite phase velocity (x0) [1] : " << manganosite_phase_velocities_x0[1] << std::endl;
    std::cout << "manganosite phase velocity (x0) [2] : " << manganosite_phase_velocities_x0[2] << std::endl;

    manganosite_greenchristoffel.SetComponents(manganosite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> manganosite_phase_velocities_x1 = manganosite_greenchristoffel.PhaseVelocities(manganosite_density);
    std::cout << "manganosite phase velocity (x1) [0] : " << manganosite_phase_velocities_x1[0] << std::endl;
    std::cout << "manganosite phase velocity (x1) [1] : " << manganosite_phase_velocities_x1[1] << std::endl;
    std::cout << "manganosite phase velocity (x1) [2] : " << manganosite_phase_velocities_x1[2] << std::endl;

    manganosite_greenchristoffel.SetComponents(manganosite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> manganosite_phase_velocities_x2 = manganosite_greenchristoffel.PhaseVelocities(manganosite_density);
    std::cout << "manganosite phase velocity (x2) [0] : " << manganosite_phase_velocities_x2[0] << std::endl;
    std::cout << "manganosite phase velocity (x2) [1] : " << manganosite_phase_velocities_x2[1] << std::endl;
    std::cout << "manganosite phase velocity (x2) [2] : " << manganosite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> manganosite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(manganosite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(manganosite_shear_modulus), mpc::rockphysics::DensityType<double>(manganosite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> manganosite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(manganosite_shear_modulus), mpc::rockphysics::DensityType<double>(manganosite_density));

    std::cout << "manganosite iso pwave velocity :      " << manganosite_pvel_type.value << std::endl;
    std::cout << "manganosite iso swave velocity :      " << manganosite_svel_type.value << std::endl;

    // Periclase
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> periclase_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    periclase_greenchristoffel.SetComponents(periclase_stiffness_tensor, normal_vector_x0);
    std::array<double,3> periclase_phase_velocities_x0 = periclase_greenchristoffel.PhaseVelocities(periclase_density);
    std::cout << "periclase phase velocity (x0) [0] : " << periclase_phase_velocities_x0[0] << std::endl;
    std::cout << "periclase phase velocity (x0) [1] : " << periclase_phase_velocities_x0[1] << std::endl;
    std::cout << "periclase phase velocity (x0) [2] : " << periclase_phase_velocities_x0[2] << std::endl;

    periclase_greenchristoffel.SetComponents(periclase_stiffness_tensor, normal_vector_x1);
    std::array<double,3> periclase_phase_velocities_x1 = periclase_greenchristoffel.PhaseVelocities(periclase_density);
    std::cout << "periclase phase velocity (x1) [0] : " << periclase_phase_velocities_x1[0] << std::endl;
    std::cout << "periclase phase velocity (x1) [1] : " << periclase_phase_velocities_x1[1] << std::endl;
    std::cout << "periclase phase velocity (x1) [2] : " << periclase_phase_velocities_x1[2] << std::endl;

    periclase_greenchristoffel.SetComponents(periclase_stiffness_tensor, normal_vector_x2);
    std::array<double,3> periclase_phase_velocities_x2 = periclase_greenchristoffel.PhaseVelocities(periclase_density);
    std::cout << "periclase phase velocity (x2) [0] : " << periclase_phase_velocities_x2[0] << std::endl;
    std::cout << "periclase phase velocity (x2) [1] : " << periclase_phase_velocities_x2[1] << std::endl;
    std::cout << "periclase phase velocity (x2) [2] : " << periclase_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> periclase_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(periclase_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(periclase_shear_modulus), mpc::rockphysics::DensityType<double>(periclase_density));

    mpc::rockphysics::ShearWaveVelocityType<double> periclase_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(periclase_shear_modulus), mpc::rockphysics::DensityType<double>(periclase_density));

    std::cout << "periclase iso pwave velocity :      " << periclase_pvel_type.value << std::endl;
    std::cout << "periclase iso swave velocity :      " << periclase_svel_type.value << std::endl;

    // Magnetite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> magnetite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    magnetite_greenchristoffel.SetComponents(magnetite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> magnetite_phase_velocities_x0 = magnetite_greenchristoffel.PhaseVelocities(magnetite_density);
    std::cout << "magnetite phase velocity (x0) [0] : " << magnetite_phase_velocities_x0[0] << std::endl;
    std::cout << "magnetite phase velocity (x0) [1] : " << magnetite_phase_velocities_x0[1] << std::endl;
    std::cout << "magnetite phase velocity (x0) [2] : " << magnetite_phase_velocities_x0[2] << std::endl;

    magnetite_greenchristoffel.SetComponents(magnetite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> magnetite_phase_velocities_x1 = magnetite_greenchristoffel.PhaseVelocities(magnetite_density);
    std::cout << "magnetite phase velocity (x1) [0] : " << magnetite_phase_velocities_x1[0] << std::endl;
    std::cout << "magnetite phase velocity (x1) [1] : " << magnetite_phase_velocities_x1[1] << std::endl;
    std::cout << "magnetite phase velocity (x1) [2] : " << magnetite_phase_velocities_x1[2] << std::endl;

    magnetite_greenchristoffel.SetComponents(magnetite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> magnetite_phase_velocities_x2 = magnetite_greenchristoffel.PhaseVelocities(magnetite_density);
    std::cout << "magnetite phase velocity (x2) [0] : " << magnetite_phase_velocities_x2[0] << std::endl;
    std::cout << "magnetite phase velocity (x2) [1] : " << magnetite_phase_velocities_x2[1] << std::endl;
    std::cout << "magnetite phase velocity (x2) [2] : " << magnetite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> magnetite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(magnetite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(magnetite_shear_modulus), mpc::rockphysics::DensityType<double>(magnetite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> magnetite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(magnetite_shear_modulus), mpc::rockphysics::DensityType<double>(magnetite_density));

    std::cout << "magnetite iso pwave velocity :      " << magnetite_pvel_type.value << std::endl;
    std::cout << "magnetite iso swave velocity :      " << magnetite_svel_type.value << std::endl;

    // Chromite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> chromite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    chromite_greenchristoffel.SetComponents(chromite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> chromite_phase_velocities_x0 = chromite_greenchristoffel.PhaseVelocities(chromite_density);
    std::cout << "chromite phase velocity (x0) [0] : " << chromite_phase_velocities_x0[0] << std::endl;
    std::cout << "chromite phase velocity (x0) [1] : " << chromite_phase_velocities_x0[1] << std::endl;
    std::cout << "chromite phase velocity (x0) [2] : " << chromite_phase_velocities_x0[2] << std::endl;

    chromite_greenchristoffel.SetComponents(chromite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> chromite_phase_velocities_x1 = chromite_greenchristoffel.PhaseVelocities(chromite_density);
    std::cout << "chromite phase velocity (x1) [0] : " << chromite_phase_velocities_x1[0] << std::endl;
    std::cout << "chromite phase velocity (x1) [1] : " << chromite_phase_velocities_x1[1] << std::endl;
    std::cout << "chromite phase velocity (x1) [2] : " << chromite_phase_velocities_x1[2] << std::endl;

    chromite_greenchristoffel.SetComponents(chromite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> chromite_phase_velocities_x2 = chromite_greenchristoffel.PhaseVelocities(chromite_density);
    std::cout << "chromite phase velocity (x2) [0] : " << chromite_phase_velocities_x2[0] << std::endl;
    std::cout << "chromite phase velocity (x2) [1] : " << chromite_phase_velocities_x2[1] << std::endl;
    std::cout << "chromite phase velocity (x2) [2] : " << chromite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> chromite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(chromite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(chromite_shear_modulus), mpc::rockphysics::DensityType<double>(chromite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> chromite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(chromite_shear_modulus), mpc::rockphysics::DensityType<double>(chromite_density));

    std::cout << "chromite iso pwave velocity :      " << chromite_pvel_type.value << std::endl;
    std::cout << "chromite iso swave velocity :      " << chromite_svel_type.value << std::endl;

    // Spinel
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> spinel_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    spinel_greenchristoffel.SetComponents(spinel_stiffness_tensor, normal_vector_x0);
    std::array<double,3> spinel_phase_velocities_x0 = spinel_greenchristoffel.PhaseVelocities(spinel_density);
    std::cout << "spinel phase velocity (x0) [0] : " << spinel_phase_velocities_x0[0] << std::endl;
    std::cout << "spinel phase velocity (x0) [1] : " << spinel_phase_velocities_x0[1] << std::endl;
    std::cout << "spinel phase velocity (x0) [2] : " << spinel_phase_velocities_x0[2] << std::endl;

    spinel_greenchristoffel.SetComponents(spinel_stiffness_tensor, normal_vector_x1);
    std::array<double,3> spinel_phase_velocities_x1 = spinel_greenchristoffel.PhaseVelocities(spinel_density);
    std::cout << "spinel phase velocity (x1) [0] : " << spinel_phase_velocities_x1[0] << std::endl;
    std::cout << "spinel phase velocity (x1) [1] : " << spinel_phase_velocities_x1[1] << std::endl;
    std::cout << "spinel phase velocity (x1) [2] : " << spinel_phase_velocities_x1[2] << std::endl;

    spinel_greenchristoffel.SetComponents(spinel_stiffness_tensor, normal_vector_x2);
    std::array<double,3> spinel_phase_velocities_x2 = spinel_greenchristoffel.PhaseVelocities(spinel_density);
    std::cout << "spinel phase velocity (x2) [0] : " << spinel_phase_velocities_x2[0] << std::endl;
    std::cout << "spinel phase velocity (x2) [1] : " << spinel_phase_velocities_x2[1] << std::endl;
    std::cout << "spinel phase velocity (x2) [2] : " << spinel_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> spinel_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(spinel_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(spinel_shear_modulus), mpc::rockphysics::DensityType<double>(spinel_density));

    mpc::rockphysics::ShearWaveVelocityType<double> spinel_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(spinel_shear_modulus), mpc::rockphysics::DensityType<double>(spinel_density));

    std::cout << "spinel iso pwave velocity :      " << spinel_pvel_type.value << std::endl;
    std::cout << "spinel iso swave velocity :      " << spinel_svel_type.value << std::endl;

    // Pyrite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> pyrite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    pyrite_greenchristoffel.SetComponents(pyrite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> pyrite_phase_velocities_x0 = pyrite_greenchristoffel.PhaseVelocities(pyrite_density);
    std::cout << "pyrite phase velocity (x0) [0] : " << pyrite_phase_velocities_x0[0] << std::endl;
    std::cout << "pyrite phase velocity (x0) [1] : " << pyrite_phase_velocities_x0[1] << std::endl;
    std::cout << "pyrite phase velocity (x0) [2] : " << pyrite_phase_velocities_x0[2] << std::endl;

    pyrite_greenchristoffel.SetComponents(pyrite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> pyrite_phase_velocities_x1 = pyrite_greenchristoffel.PhaseVelocities(pyrite_density);
    std::cout << "pyrite phase velocity (x1) [0] : " << pyrite_phase_velocities_x1[0] << std::endl;
    std::cout << "pyrite phase velocity (x1) [1] : " << pyrite_phase_velocities_x1[1] << std::endl;
    std::cout << "pyrite phase velocity (x1) [2] : " << pyrite_phase_velocities_x1[2] << std::endl;

    pyrite_greenchristoffel.SetComponents(pyrite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> pyrite_phase_velocities_x2 = pyrite_greenchristoffel.PhaseVelocities(pyrite_density);
    std::cout << "pyrite phase velocity (x2) [0] : " << pyrite_phase_velocities_x2[0] << std::endl;
    std::cout << "pyrite phase velocity (x2) [1] : " << pyrite_phase_velocities_x2[1] << std::endl;
    std::cout << "pyrite phase velocity (x2) [2] : " << pyrite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> pyrite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(pyrite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(pyrite_shear_modulus), mpc::rockphysics::DensityType<double>(pyrite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> pyrite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(pyrite_shear_modulus), mpc::rockphysics::DensityType<double>(pyrite_density));

    std::cout << "pyrite iso pwave velocity :      " << pyrite_pvel_type.value << std::endl;
    std::cout << "pyrite iso swave velocity :      " << pyrite_svel_type.value << std::endl;

    // Galena
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> galena_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    galena_greenchristoffel.SetComponents(galena_stiffness_tensor, normal_vector_x0);
    std::array<double,3> galena_phase_velocities_x0 = galena_greenchristoffel.PhaseVelocities(galena_density);
    std::cout << "galena phase velocity (x0) [0] : " << galena_phase_velocities_x0[0] << std::endl;
    std::cout << "galena phase velocity (x0) [1] : " << galena_phase_velocities_x0[1] << std::endl;
    std::cout << "galena phase velocity (x0) [2] : " << galena_phase_velocities_x0[2] << std::endl;

    galena_greenchristoffel.SetComponents(galena_stiffness_tensor, normal_vector_x1);
    std::array<double,3> galena_phase_velocities_x1 = galena_greenchristoffel.PhaseVelocities(galena_density);
    std::cout << "galena phase velocity (x1) [0] : " << galena_phase_velocities_x1[0] << std::endl;
    std::cout << "galena phase velocity (x1) [1] : " << galena_phase_velocities_x1[1] << std::endl;
    std::cout << "galena phase velocity (x1) [2] : " << galena_phase_velocities_x1[2] << std::endl;

    galena_greenchristoffel.SetComponents(galena_stiffness_tensor, normal_vector_x2);
    std::array<double,3> galena_phase_velocities_x2 = galena_greenchristoffel.PhaseVelocities(galena_density);
    std::cout << "galena phase velocity (x2) [0] : " << galena_phase_velocities_x2[0] << std::endl;
    std::cout << "galena phase velocity (x2) [1] : " << galena_phase_velocities_x2[1] << std::endl;
    std::cout << "galena phase velocity (x2) [2] : " << galena_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> galena_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(galena_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(galena_shear_modulus), mpc::rockphysics::DensityType<double>(galena_density));

    mpc::rockphysics::ShearWaveVelocityType<double> galena_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(galena_shear_modulus), mpc::rockphysics::DensityType<double>(galena_density));

    std::cout << "galena iso pwave velocity :      " << galena_pvel_type.value << std::endl;
    std::cout << "galena iso swave velocity :      " << galena_svel_type.value << std::endl;

    // Sphalerite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> sphalerite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    sphalerite_greenchristoffel.SetComponents(sphalerite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> sphalerite_phase_velocities_x0 = sphalerite_greenchristoffel.PhaseVelocities(sphalerite_density);
    std::cout << "sphalerite phase velocity (x0) [0] : " << sphalerite_phase_velocities_x0[0] << std::endl;
    std::cout << "sphalerite phase velocity (x0) [1] : " << sphalerite_phase_velocities_x0[1] << std::endl;
    std::cout << "sphalerite phase velocity (x0) [2] : " << sphalerite_phase_velocities_x0[2] << std::endl;

    sphalerite_greenchristoffel.SetComponents(sphalerite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> sphalerite_phase_velocities_x1 = sphalerite_greenchristoffel.PhaseVelocities(sphalerite_density);
    std::cout << "sphalerite phase velocity (x1) [0] : " << sphalerite_phase_velocities_x1[0] << std::endl;
    std::cout << "sphalerite phase velocity (x1) [1] : " << sphalerite_phase_velocities_x1[1] << std::endl;
    std::cout << "sphalerite phase velocity (x1) [2] : " << sphalerite_phase_velocities_x1[2] << std::endl;

    sphalerite_greenchristoffel.SetComponents(sphalerite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> sphalerite_phase_velocities_x2 = sphalerite_greenchristoffel.PhaseVelocities(sphalerite_density);
    std::cout << "sphalerite phase velocity (x2) [0] : " << sphalerite_phase_velocities_x2[0] << std::endl;
    std::cout << "sphalerite phase velocity (x2) [1] : " << sphalerite_phase_velocities_x2[1] << std::endl;
    std::cout << "sphalerite phase velocity (x2) [2] : " << sphalerite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> sphalerite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(sphalerite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(sphalerite_shear_modulus), mpc::rockphysics::DensityType<double>(sphalerite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> sphalerite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(sphalerite_shear_modulus), mpc::rockphysics::DensityType<double>(sphalerite_density));

    std::cout << "sphalerite iso pwave velocity :      " << sphalerite_pvel_type.value << std::endl;
    std::cout << "sphalerite iso swave velocity :      " << sphalerite_svel_type.value << std::endl;

    // Fluorite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> fluorite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    fluorite_greenchristoffel.SetComponents(fluorite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> fluorite_phase_velocities_x0 = fluorite_greenchristoffel.PhaseVelocities(fluorite_density);
    std::cout << "fluorite phase velocity (x0) [0] : " << fluorite_phase_velocities_x0[0] << std::endl;
    std::cout << "fluorite phase velocity (x0) [1] : " << fluorite_phase_velocities_x0[1] << std::endl;
    std::cout << "fluorite phase velocity (x0) [2] : " << fluorite_phase_velocities_x0[2] << std::endl;

    fluorite_greenchristoffel.SetComponents(fluorite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> fluorite_phase_velocities_x1 = fluorite_greenchristoffel.PhaseVelocities(fluorite_density);
    std::cout << "fluorite phase velocity (x1) [0] : " << fluorite_phase_velocities_x1[0] << std::endl;
    std::cout << "fluorite phase velocity (x1) [1] : " << fluorite_phase_velocities_x1[1] << std::endl;
    std::cout << "fluorite phase velocity (x1) [2] : " << fluorite_phase_velocities_x1[2] << std::endl;

    fluorite_greenchristoffel.SetComponents(fluorite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> fluorite_phase_velocities_x2 = fluorite_greenchristoffel.PhaseVelocities(fluorite_density);
    std::cout << "fluorite phase velocity (x2) [0] : " << fluorite_phase_velocities_x2[0] << std::endl;
    std::cout << "fluorite phase velocity (x2) [1] : " << fluorite_phase_velocities_x2[1] << std::endl;
    std::cout << "fluorite phase velocity (x2) [2] : " << fluorite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> fluorite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(fluorite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(fluorite_shear_modulus), mpc::rockphysics::DensityType<double>(fluorite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> fluorite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(fluorite_shear_modulus), mpc::rockphysics::DensityType<double>(fluorite_density));

    std::cout << "fluorite iso pwave velocity :      " << fluorite_pvel_type.value << std::endl;
    std::cout << "fluorite iso swave velocity :      " << fluorite_svel_type.value << std::endl;

    // Halite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> halite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    halite_greenchristoffel.SetComponents(halite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> halite_phase_velocities_x0 = halite_greenchristoffel.PhaseVelocities(halite_density);
    std::cout << "halite phase velocity (x0) [0] : " << halite_phase_velocities_x0[0] << std::endl;
    std::cout << "halite phase velocity (x0) [1] : " << halite_phase_velocities_x0[1] << std::endl;
    std::cout << "halite phase velocity (x0) [2] : " << halite_phase_velocities_x0[2] << std::endl;

    halite_greenchristoffel.SetComponents(halite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> halite_phase_velocities_x1 = halite_greenchristoffel.PhaseVelocities(halite_density);
    std::cout << "halite phase velocity (x1) [0] : " << halite_phase_velocities_x1[0] << std::endl;
    std::cout << "halite phase velocity (x1) [1] : " << halite_phase_velocities_x1[1] << std::endl;
    std::cout << "halite phase velocity (x1) [2] : " << halite_phase_velocities_x1[2] << std::endl;

    halite_greenchristoffel.SetComponents(halite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> halite_phase_velocities_x2 = halite_greenchristoffel.PhaseVelocities(halite_density);
    std::cout << "halite phase velocity (x2) [0] : " << halite_phase_velocities_x2[0] << std::endl;
    std::cout << "halite phase velocity (x2) [1] : " << halite_phase_velocities_x2[1] << std::endl;
    std::cout << "halite phase velocity (x2) [2] : " << halite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> halite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(halite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(halite_shear_modulus), mpc::rockphysics::DensityType<double>(halite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> halite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(halite_shear_modulus), mpc::rockphysics::DensityType<double>(halite_density));

    std::cout << "halite iso pwave velocity :      " << halite_pvel_type.value << std::endl;
    std::cout << "halite iso swave velocity :      " << halite_svel_type.value << std::endl;

    // Sylvite
    std::cout << "" << std::endl;
    mpc::mechanics::GreenChristoffel<double> sylvite_greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    sylvite_greenchristoffel.SetComponents(sylvite_stiffness_tensor, normal_vector_x0);
    std::array<double,3> sylvite_phase_velocities_x0 = sylvite_greenchristoffel.PhaseVelocities(sylvite_density);
    std::cout << "sylvite phase velocity (x0) [0] : " << sylvite_phase_velocities_x0[0] << std::endl;
    std::cout << "sylvite phase velocity (x0) [1] : " << sylvite_phase_velocities_x0[1] << std::endl;
    std::cout << "sylvite phase velocity (x0) [2] : " << sylvite_phase_velocities_x0[2] << std::endl;

    sylvite_greenchristoffel.SetComponents(sylvite_stiffness_tensor, normal_vector_x1);
    std::array<double,3> sylvite_phase_velocities_x1 = sylvite_greenchristoffel.PhaseVelocities(sylvite_density);
    std::cout << "sylvite phase velocity (x1) [0] : " << sylvite_phase_velocities_x1[0] << std::endl;
    std::cout << "sylvite phase velocity (x1) [1] : " << sylvite_phase_velocities_x1[1] << std::endl;
    std::cout << "sylvite phase velocity (x1) [2] : " << sylvite_phase_velocities_x1[2] << std::endl;

    sylvite_greenchristoffel.SetComponents(sylvite_stiffness_tensor, normal_vector_x2);
    std::array<double,3> sylvite_phase_velocities_x2 = sylvite_greenchristoffel.PhaseVelocities(sylvite_density);
    std::cout << "sylvite phase velocity (x2) [0] : " << sylvite_phase_velocities_x2[0] << std::endl;
    std::cout << "sylvite phase velocity (x2) [1] : " << sylvite_phase_velocities_x2[1] << std::endl;
    std::cout << "sylvite phase velocity (x2) [2] : " << sylvite_phase_velocities_x2[2] << std::endl;

    mpc::rockphysics::CompressionalWaveVelocityType<double> sylvite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(sylvite_bulk_modulus), mpc::rockphysics::ShearModulusType<double>(sylvite_shear_modulus), mpc::rockphysics::DensityType<double>(sylvite_density));

    mpc::rockphysics::ShearWaveVelocityType<double> sylvite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(sylvite_shear_modulus), mpc::rockphysics::DensityType<double>(sylvite_density));

    std::cout << "sylvite iso pwave velocity :      " << sylvite_pvel_type.value << std::endl;
    std::cout << "sylvite iso swave velocity :      " << sylvite_svel_type.value << std::endl;
}
