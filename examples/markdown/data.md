# mpcexamples
mechanical properties of crystals and polycrystalline aggregates

---
### data
> Bass, J.D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63.

#### mineral data

[mpcexamples::mpcMineralData()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_mineraldata.cpp)
Augite
```cpp
/** mineral data */
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
```


Augite    
```cpp
mpc::core::StiffnessTensor<double> augite_stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(augite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 181.6
    component(0,0,0,1) : 0
    component(0,0,0,2) : 19.9
    component(0,0,1,0) : 0
    component(0,0,1,1) : 73.4
    component(0,0,1,2) : 0
    component(0,0,2,0) : 19.9
    component(0,0,2,1) : 0
    component(0,0,2,2) : 72.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 55.8
    component(0,1,0,2) : 0
    component(0,1,1,0) : 55.8
    component(0,1,1,1) : 0
    component(0,1,1,2) : 4.3
    component(0,1,2,0) : 0
    component(0,1,2,1) : 4.3
    component(0,1,2,2) : 0
    component(0,2,0,0) : 19.9
    component(0,2,0,1) : 0
    component(0,2,0,2) : 51.1
    component(0,2,1,0) : 0
    component(0,2,1,1) : 16.6
    component(0,2,1,2) : 0
    component(0,2,2,0) : 51.1
    component(0,2,2,1) : 0
    component(0,2,2,2) : 24.6
    component(1,0,0,0) : 0
    component(1,0,0,1) : 55.8
    component(1,0,0,2) : 0
    component(1,0,1,0) : 55.8
    component(1,0,1,1) : 0
    component(1,0,1,2) : 4.3
    component(1,0,2,0) : 0
    component(1,0,2,1) : 4.3
    component(1,0,2,2) : 0
    component(1,1,0,0) : 73.4
    component(1,1,0,1) : 0
    component(1,1,0,2) : 16.6
    component(1,1,1,0) : 0
    component(1,1,1,1) : 150.7
    component(1,1,1,2) : 0
    component(1,1,2,0) : 16.6
    component(1,1,2,1) : 0
    component(1,1,2,2) : 33.9
    component(1,2,0,0) : 0
    component(1,2,0,1) : 4.3
    component(1,2,0,2) : 0
    component(1,2,1,0) : 4.3
    component(1,2,1,1) : 0
    component(1,2,1,2) : 69.7
    component(1,2,2,0) : 0
    component(1,2,2,1) : 69.7
    component(1,2,2,2) : 0
    component(2,0,0,0) : 19.9
    component(2,0,0,1) : 0
    component(2,0,0,2) : 51.1
    component(2,0,1,0) : 0
    component(2,0,1,1) : 16.6
    component(2,0,1,2) : 0
    component(2,0,2,0) : 51.1
    component(2,0,2,1) : 0
    component(2,0,2,2) : 24.6
    component(2,1,0,0) : 0
    component(2,1,0,1) : 4.3
    component(2,1,0,2) : 0
    component(2,1,1,0) : 4.3
    component(2,1,1,1) : 0
    component(2,1,1,2) : 69.7
    component(2,1,2,0) : 0
    component(2,1,2,1) : 69.7
    component(2,1,2,2) : 0
    component(2,2,0,0) : 72.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : 24.6
    component(2,2,1,0) : 0
    component(2,2,1,1) : 33.9
    component(2,2,1,2) : 0
    component(2,2,2,0) : 24.6
    component(2,2,2,1) : 0
    component(2,2,2,2) : 217.8

Albite    
```cpp
mpc::core::StiffnessTensor<double> albite_stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(albite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 74
    component(0,0,0,1) : 0
    component(0,0,0,2) : -6.6
    component(0,0,1,0) : 0
    component(0,0,1,1) : 36.4
    component(0,0,1,2) : 0
    component(0,0,2,0) : -6.6
    component(0,0,2,1) : 0
    component(0,0,2,2) : 39.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 32
    component(0,1,0,2) : 0
    component(0,1,1,0) : 32
    component(0,1,1,1) : 0
    component(0,1,1,2) : -2.5
    component(0,1,2,0) : 0
    component(0,1,2,1) : -2.5
    component(0,1,2,2) : 0
    component(0,2,0,0) : -6.6
    component(0,2,0,1) : 0
    component(0,2,0,2) : 29.6
    component(0,2,1,0) : 0
    component(0,2,1,1) : -12.8
    component(0,2,1,2) : 0
    component(0,2,2,0) : 29.6
    component(0,2,2,1) : 0
    component(0,2,2,2) : -20
    component(1,0,0,0) : 0
    component(1,0,0,1) : 32
    component(1,0,0,2) : 0
    component(1,0,1,0) : 32
    component(1,0,1,1) : 0
    component(1,0,1,2) : -2.5
    component(1,0,2,0) : 0
    component(1,0,2,1) : -2.5
    component(1,0,2,2) : 0
    component(1,1,0,0) : 36.4
    component(1,1,0,1) : 0
    component(1,1,0,2) : -12.8
    component(1,1,1,0) : 0
    component(1,1,1,1) : 131
    component(1,1,1,2) : 0
    component(1,1,2,0) : -12.8
    component(1,1,2,1) : 0
    component(1,1,2,2) : 31
    component(1,2,0,0) : 0
    component(1,2,0,1) : -2.5
    component(1,2,0,2) : 0
    component(1,2,1,0) : -2.5
    component(1,2,1,1) : 0
    component(1,2,1,2) : 17.3
    component(1,2,2,0) : 0
    component(1,2,2,1) : 17.3
    component(1,2,2,2) : 0
    component(2,0,0,0) : -6.6
    component(2,0,0,1) : 0
    component(2,0,0,2) : 29.6
    component(2,0,1,0) : 0
    component(2,0,1,1) : -12.8
    component(2,0,1,2) : 0
    component(2,0,2,0) : 29.6
    component(2,0,2,1) : 0
    component(2,0,2,2) : -20
    component(2,1,0,0) : 0
    component(2,1,0,1) : -2.5
    component(2,1,0,2) : 0
    component(2,1,1,0) : -2.5
    component(2,1,1,1) : 0
    component(2,1,1,2) : 17.3
    component(2,1,2,0) : 0
    component(2,1,2,1) : 17.3
    component(2,1,2,2) : 0
    component(2,2,0,0) : 39.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : -20
    component(2,2,1,0) : 0
    component(2,2,1,1) : 31
    component(2,2,1,2) : 0
    component(2,2,2,0) : -20
    component(2,2,2,1) : 0
    component(2,2,2,2) : 128

Anorthite    
```cpp
mpc::core::StiffnessTensor<double> anorthite_stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(anorthite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 124
    component(0,0,0,1) : 0
    component(0,0,0,2) : -19
    component(0,0,1,0) : 0
    component(0,0,1,1) : 66
    component(0,0,1,2) : 0
    component(0,0,2,0) : -19
    component(0,0,2,1) : 0
    component(0,0,2,2) : 50
    component(0,1,0,0) : 0
    component(0,1,0,1) : 41.5
    component(0,1,0,2) : 0
    component(0,1,1,0) : 41.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : -1
    component(0,1,2,0) : 0
    component(0,1,2,1) : -1
    component(0,1,2,2) : 0
    component(0,2,0,0) : -19
    component(0,2,0,1) : 0
    component(0,2,0,2) : 40.4
    component(0,2,1,0) : 0
    component(0,2,1,1) : -7
    component(0,2,1,2) : 0
    component(0,2,2,0) : 40.4
    component(0,2,2,1) : 0
    component(0,2,2,2) : -18
    component(1,0,0,0) : 0
    component(1,0,0,1) : 41.5
    component(1,0,0,2) : 0
    component(1,0,1,0) : 41.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : -1
    component(1,0,2,0) : 0
    component(1,0,2,1) : -1
    component(1,0,2,2) : 0
    component(1,1,0,0) : 66
    component(1,1,0,1) : 0
    component(1,1,0,2) : -7
    component(1,1,1,0) : 0
    component(1,1,1,1) : 205
    component(1,1,1,2) : 0
    component(1,1,2,0) : -7
    component(1,1,2,1) : 0
    component(1,1,2,2) : 42
    component(1,2,0,0) : 0
    component(1,2,0,1) : -1
    component(1,2,0,2) : 0
    component(1,2,1,0) : -1
    component(1,2,1,1) : 0
    component(1,2,1,2) : 23.5
    component(1,2,2,0) : 0
    component(1,2,2,1) : 23.5
    component(1,2,2,2) : 0
    component(2,0,0,0) : -19
    component(2,0,0,1) : 0
    component(2,0,0,2) : 40.4
    component(2,0,1,0) : 0
    component(2,0,1,1) : -7
    component(2,0,1,2) : 0
    component(2,0,2,0) : 40.4
    component(2,0,2,1) : 0
    component(2,0,2,2) : -18
    component(2,1,0,0) : 0
    component(2,1,0,1) : -1
    component(2,1,0,2) : 0
    component(2,1,1,0) : -1
    component(2,1,1,1) : 0
    component(2,1,1,2) : 23.5
    component(2,1,2,0) : 0
    component(2,1,2,1) : 23.5
    component(2,1,2,2) : 0
    component(2,2,0,0) : 50
    component(2,2,0,1) : 0
    component(2,2,0,2) : -18
    component(2,2,1,0) : 0
    component(2,2,1,1) : 42
    component(2,2,1,2) : 0
    component(2,2,2,0) : -18
    component(2,2,2,1) : 0
    component(2,2,2,2) : 156

Labradorite    
```cpp
mpc::core::StiffnessTensor<double> labradorite_stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();
print_tensor_components_double_4_fo(labradorite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 99.4
    component(0,0,0,1) : 0
    component(0,0,0,2) : -2.5
    component(0,0,1,0) : 0
    component(0,0,1,1) : 62.8
    component(0,0,1,2) : 0
    component(0,0,2,0) : -2.5
    component(0,0,2,1) : 0
    component(0,0,2,2) : 48.7
    component(0,1,0,0) : 0
    component(0,1,0,1) : 37.1
    component(0,1,0,2) : 0
    component(0,1,1,0) : 37.1
    component(0,1,1,1) : 0
    component(0,1,1,2) : -5.4
    component(0,1,2,0) : 0
    component(0,1,2,1) : -5.4
    component(0,1,2,2) : 0
    component(0,2,0,0) : -2.5
    component(0,2,0,1) : 0
    component(0,2,0,2) : 34.5
    component(0,2,1,0) : 0
    component(0,2,1,1) : -10.7
    component(0,2,1,2) : 0
    component(0,2,2,0) : 34.5
    component(0,2,2,1) : 0
    component(0,2,2,2) : -12.4
    component(1,0,0,0) : 0
    component(1,0,0,1) : 37.1
    component(1,0,0,2) : 0
    component(1,0,1,0) : 37.1
    component(1,0,1,1) : 0
    component(1,0,1,2) : -5.4
    component(1,0,2,0) : 0
    component(1,0,2,1) : -5.4
    component(1,0,2,2) : 0
    component(1,1,0,0) : 62.8
    component(1,1,0,1) : 0
    component(1,1,0,2) : -10.7
    component(1,1,1,0) : 0
    component(1,1,1,1) : 158
    component(1,1,1,2) : 0
    component(1,1,2,0) : -10.7
    component(1,1,2,1) : 0
    component(1,1,2,2) : 26.7
    component(1,2,0,0) : 0
    component(1,2,0,1) : -5.4
    component(1,2,0,2) : 0
    component(1,2,1,0) : -5.4
    component(1,2,1,1) : 0
    component(1,2,1,2) : 21.7
    component(1,2,2,0) : 0
    component(1,2,2,1) : 21.7
    component(1,2,2,2) : 0
    component(2,0,0,0) : -2.5
    component(2,0,0,1) : 0
    component(2,0,0,2) : 34.5
    component(2,0,1,0) : 0
    component(2,0,1,1) : -10.7
    component(2,0,1,2) : 0
    component(2,0,2,0) : 34.5
    component(2,0,2,1) : 0
    component(2,0,2,2) : -12.4
    component(2,1,0,0) : 0
    component(2,1,0,1) : -5.4
    component(2,1,0,2) : 0
    component(2,1,1,0) : -5.4
    component(2,1,1,1) : 0
    component(2,1,1,2) : 21.7
    component(2,1,2,0) : 0
    component(2,1,2,1) : 21.7
    component(2,1,2,2) : 0
    component(2,2,0,0) : 48.7
    component(2,2,0,1) : 0
    component(2,2,0,2) : -12.4
    component(2,2,1,0) : 0
    component(2,2,1,1) : 26.7
    component(2,2,1,2) : 0
    component(2,2,2,0) : -12.4
    component(2,2,2,1) : 0
    component(2,2,2,2) : 150

Microcline    
```cpp
mpc::core::StiffnessTensor<double> microcline_stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();
print_tensor_components_double_4_fo(microcline_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 67
    component(0,0,0,1) : 0
    component(0,0,0,2) : -0.2
    component(0,0,1,0) : 0
    component(0,0,1,1) : 45.3
    component(0,0,1,2) : 0
    component(0,0,2,0) : -0.2
    component(0,0,2,1) : 0
    component(0,0,2,2) : 26.5
    component(0,1,0,0) : 0
    component(0,1,0,1) : 36.4
    component(0,1,0,2) : 0
    component(0,1,1,0) : 36.4
    component(0,1,1,1) : 0
    component(0,1,1,2) : -1.9
    component(0,1,2,0) : 0
    component(0,1,2,1) : -1.9
    component(0,1,2,2) : 0
    component(0,2,0,0) : -0.2
    component(0,2,0,1) : 0
    component(0,2,0,2) : 23.8
    component(0,2,1,0) : 0
    component(0,2,1,1) : -12.3
    component(0,2,1,2) : 0
    component(0,2,2,0) : 23.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : -15
    component(1,0,0,0) : 0
    component(1,0,0,1) : 36.4
    component(1,0,0,2) : 0
    component(1,0,1,0) : 36.4
    component(1,0,1,1) : 0
    component(1,0,1,2) : -1.9
    component(1,0,2,0) : 0
    component(1,0,2,1) : -1.9
    component(1,0,2,2) : 0
    component(1,1,0,0) : 45.3
    component(1,1,0,1) : 0
    component(1,1,0,2) : -12.3
    component(1,1,1,0) : 0
    component(1,1,1,1) : 169
    component(1,1,1,2) : 0
    component(1,1,2,0) : -12.3
    component(1,1,2,1) : 0
    component(1,1,2,2) : 20.4
    component(1,2,0,0) : 0
    component(1,2,0,1) : -1.9
    component(1,2,0,2) : 0
    component(1,2,1,0) : -1.9
    component(1,2,1,1) : 0
    component(1,2,1,2) : 14.3
    component(1,2,2,0) : 0
    component(1,2,2,1) : 14.3
    component(1,2,2,2) : 0
    component(2,0,0,0) : -0.2
    component(2,0,0,1) : 0
    component(2,0,0,2) : 23.8
    component(2,0,1,0) : 0
    component(2,0,1,1) : -12.3
    component(2,0,1,2) : 0
    component(2,0,2,0) : 23.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : -15
    component(2,1,0,0) : 0
    component(2,1,0,1) : -1.9
    component(2,1,0,2) : 0
    component(2,1,1,0) : -1.9
    component(2,1,1,1) : 0
    component(2,1,1,2) : 14.3
    component(2,1,2,0) : 0
    component(2,1,2,1) : 14.3
    component(2,1,2,2) : 0
    component(2,2,0,0) : 26.5
    component(2,2,0,1) : 0
    component(2,2,0,2) : -15
    component(2,2,1,0) : 0
    component(2,2,1,1) : 20.4
    component(2,2,1,2) : 0
    component(2,2,2,0) : -15
    component(2,2,2,1) : 0
    component(2,2,2,2) : 118

Oligoclase    
```cpp
mpc::core::StiffnessTensor<double> oligoclase_stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();
print_tensor_components_double_4_fo(oligoclase_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 80.8
    component(0,0,0,1) : 0
    component(0,0,0,2) : -15.7
    component(0,0,1,0) : 0
    component(0,0,1,1) : 37.9
    component(0,0,1,2) : 0
    component(0,0,2,0) : -15.7
    component(0,0,2,1) : 0
    component(0,0,2,2) : 52.9
    component(0,1,0,0) : 0
    component(0,1,0,1) : 35.7
    component(0,1,0,2) : 0
    component(0,1,1,0) : 35.7
    component(0,1,1,1) : 0
    component(0,1,1,2) : -0.9
    component(0,1,2,0) : 0
    component(0,1,2,1) : -0.9
    component(0,1,2,2) : 0
    component(0,2,0,0) : -15.7
    component(0,2,0,1) : 0
    component(0,2,0,2) : 27.1
    component(0,2,1,0) : 0
    component(0,2,1,1) : -23.7
    component(0,2,1,2) : 0
    component(0,2,2,0) : 27.1
    component(0,2,2,1) : 0
    component(0,2,2,2) : -6
    component(1,0,0,0) : 0
    component(1,0,0,1) : 35.7
    component(1,0,0,2) : 0
    component(1,0,1,0) : 35.7
    component(1,0,1,1) : 0
    component(1,0,1,2) : -0.9
    component(1,0,2,0) : 0
    component(1,0,2,1) : -0.9
    component(1,0,2,2) : 0
    component(1,1,0,0) : 37.9
    component(1,1,0,1) : 0
    component(1,1,0,2) : -23.7
    component(1,1,1,0) : 0
    component(1,1,1,1) : 163
    component(1,1,1,2) : 0
    component(1,1,2,0) : -23.7
    component(1,1,2,1) : 0
    component(1,1,2,2) : 32.7
    component(1,2,0,0) : 0
    component(1,2,0,1) : -0.9
    component(1,2,0,2) : 0
    component(1,2,1,0) : -0.9
    component(1,2,1,1) : 0
    component(1,2,1,2) : 18.7
    component(1,2,2,0) : 0
    component(1,2,2,1) : 18.7
    component(1,2,2,2) : 0
    component(2,0,0,0) : -15.7
    component(2,0,0,1) : 0
    component(2,0,0,2) : 27.1
    component(2,0,1,0) : 0
    component(2,0,1,1) : -23.7
    component(2,0,1,2) : 0
    component(2,0,2,0) : 27.1
    component(2,0,2,1) : 0
    component(2,0,2,2) : -6
    component(2,1,0,0) : 0
    component(2,1,0,1) : -0.9
    component(2,1,0,2) : 0
    component(2,1,1,0) : -0.9
    component(2,1,1,1) : 0
    component(2,1,1,2) : 18.7
    component(2,1,2,0) : 0
    component(2,1,2,1) : 18.7
    component(2,1,2,2) : 0
    component(2,2,0,0) : 52.9
    component(2,2,0,1) : 0
    component(2,2,0,2) : -6
    component(2,2,1,0) : 0
    component(2,2,1,1) : 32.7
    component(2,2,1,2) : 0
    component(2,2,2,0) : -6
    component(2,2,2,1) : 0
    component(2,2,2,2) : 124

Coesite    
```cpp
mpc::core::StiffnessTensor<double> coesite_stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(coesite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 160.8
    component(0,0,0,1) : 0
    component(0,0,0,2) : -36.2
    component(0,0,1,0) : 0
    component(0,0,1,1) : 82.1
    component(0,0,1,2) : 0
    component(0,0,2,0) : -36.2
    component(0,0,2,1) : 0
    component(0,0,2,2) : 102.9
    component(0,1,0,0) : 0
    component(0,1,0,1) : 58.8
    component(0,1,0,2) : 0
    component(0,1,1,0) : 58.8
    component(0,1,1,1) : 0
    component(0,1,1,2) : 9.9
    component(0,1,2,0) : 0
    component(0,1,2,1) : 9.9
    component(0,1,2,2) : 0
    component(0,2,0,0) : -36.2
    component(0,2,0,1) : 0
    component(0,2,0,2) : 73.3
    component(0,2,1,0) : 0
    component(0,2,1,1) : 2.6
    component(0,2,1,2) : 0
    component(0,2,2,0) : 73.3
    component(0,2,2,1) : 0
    component(0,2,2,2) : -39.3
    component(1,0,0,0) : 0
    component(1,0,0,1) : 58.8
    component(1,0,0,2) : 0
    component(1,0,1,0) : 58.8
    component(1,0,1,1) : 0
    component(1,0,1,2) : 9.9
    component(1,0,2,0) : 0
    component(1,0,2,1) : 9.9
    component(1,0,2,2) : 0
    component(1,1,0,0) : 82.1
    component(1,1,0,1) : 0
    component(1,1,0,2) : 2.6
    component(1,1,1,0) : 0
    component(1,1,1,1) : 230.4
    component(1,1,1,2) : 0
    component(1,1,2,0) : 2.6
    component(1,1,2,1) : 0
    component(1,1,2,2) : 35.6
    component(1,2,0,0) : 0
    component(1,2,0,1) : 9.9
    component(1,2,0,2) : 0
    component(1,2,1,0) : 9.9
    component(1,2,1,1) : 0
    component(1,2,1,2) : 67.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 67.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : -36.2
    component(2,0,0,1) : 0
    component(2,0,0,2) : 73.3
    component(2,0,1,0) : 0
    component(2,0,1,1) : 2.6
    component(2,0,1,2) : 0
    component(2,0,2,0) : 73.3
    component(2,0,2,1) : 0
    component(2,0,2,2) : -39.3
    component(2,1,0,0) : 0
    component(2,1,0,1) : 9.9
    component(2,1,0,2) : 0
    component(2,1,1,0) : 9.9
    component(2,1,1,1) : 0
    component(2,1,1,2) : 67.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 67.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 102.9
    component(2,2,0,1) : 0
    component(2,2,0,2) : -39.3
    component(2,2,1,0) : 0
    component(2,2,1,1) : 35.6
    component(2,2,1,2) : 0
    component(2,2,2,0) : -39.3
    component(2,2,2,1) : 0
    component(2,2,2,2) : 231.6

Epidote    
```cpp
mpc::core::StiffnessTensor<double> epidote_stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();
print_tensor_components_double_4_fo(epidote_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 211.8
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 66.3
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 45.2
    component(0,1,0,0) : 0
    component(0,1,0,1) : 77.5
    component(0,1,0,2) : 0
    component(0,1,1,0) : 77.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : -3.4
    component(0,1,2,0) : 0
    component(0,1,2,1) : -3.4
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 43.2
    component(0,2,1,0) : 0
    component(0,2,1,1) : -8.2
    component(0,2,1,2) : 0
    component(0,2,2,0) : 43.2
    component(0,2,2,1) : 0
    component(0,2,2,2) : -14.3
    component(1,0,0,0) : 0
    component(1,0,0,1) : 77.5
    component(1,0,0,2) : 0
    component(1,0,1,0) : 77.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : -3.4
    component(1,0,2,0) : 0
    component(1,0,2,1) : -3.4
    component(1,0,2,2) : 0
    component(1,1,0,0) : 66.3
    component(1,1,0,1) : 0
    component(1,1,0,2) : -8.2
    component(1,1,1,0) : 0
    component(1,1,1,1) : 238.7
    component(1,1,1,2) : 0
    component(1,1,2,0) : -8.2
    component(1,1,2,1) : 0
    component(1,1,2,2) : 45.6
    component(1,2,0,0) : 0
    component(1,2,0,1) : -3.4
    component(1,2,0,2) : 0
    component(1,2,1,0) : -3.4
    component(1,2,1,1) : 0
    component(1,2,1,2) : 39.1
    component(1,2,2,0) : 0
    component(1,2,2,1) : 39.1
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 43.2
    component(2,0,1,0) : 0
    component(2,0,1,1) : -8.2
    component(2,0,1,2) : 0
    component(2,0,2,0) : 43.2
    component(2,0,2,1) : 0
    component(2,0,2,2) : -14.3
    component(2,1,0,0) : 0
    component(2,1,0,1) : -3.4
    component(2,1,0,2) : 0
    component(2,1,1,0) : -3.4
    component(2,1,1,1) : 0
    component(2,1,1,2) : 39.1
    component(2,1,2,0) : 0
    component(2,1,2,1) : 39.1
    component(2,1,2,2) : 0
    component(2,2,0,0) : 45.2
    component(2,2,0,1) : 0
    component(2,2,0,2) : -14.3
    component(2,2,1,0) : 0
    component(2,2,1,1) : 45.6
    component(2,2,1,2) : 0
    component(2,2,2,0) : -14.3
    component(2,2,2,1) : 0
    component(2,2,2,2) : 202

Hornblende    
```cpp
mpc::core::StiffnessTensor<double> hornblende_stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();
print_tensor_components_double_4_fo(hornblende_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 116
    component(0,0,0,1) : 0
    component(0,0,0,2) : 4.3
    component(0,0,1,0) : 0
    component(0,0,1,1) : 44.9
    component(0,0,1,2) : 0
    component(0,0,2,0) : 4.3
    component(0,0,2,1) : 0
    component(0,0,2,2) : 61.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 36.8
    component(0,1,0,2) : 0
    component(0,1,1,0) : 36.8
    component(0,1,1,1) : 0
    component(0,1,1,2) : -6.2
    component(0,1,2,0) : 0
    component(0,1,2,1) : -6.2
    component(0,1,2,2) : 0
    component(0,2,0,0) : 4.3
    component(0,2,0,1) : 0
    component(0,2,0,2) : 31.8
    component(0,2,1,0) : 0
    component(0,2,1,1) : -2.5
    component(0,2,1,2) : 0
    component(0,2,2,0) : 31.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 10
    component(1,0,0,0) : 0
    component(1,0,0,1) : 36.8
    component(1,0,0,2) : 0
    component(1,0,1,0) : 36.8
    component(1,0,1,1) : 0
    component(1,0,1,2) : -6.2
    component(1,0,2,0) : 0
    component(1,0,2,1) : -6.2
    component(1,0,2,2) : 0
    component(1,1,0,0) : 44.9
    component(1,1,0,1) : 0
    component(1,1,0,2) : -2.5
    component(1,1,1,0) : 0
    component(1,1,1,1) : 159.7
    component(1,1,1,2) : 0
    component(1,1,2,0) : -2.5
    component(1,1,2,1) : 0
    component(1,1,2,2) : 65.5
    component(1,2,0,0) : 0
    component(1,2,0,1) : -6.2
    component(1,2,0,2) : 0
    component(1,2,1,0) : -6.2
    component(1,2,1,1) : 0
    component(1,2,1,2) : 57.4
    component(1,2,2,0) : 0
    component(1,2,2,1) : 57.4
    component(1,2,2,2) : 0
    component(2,0,0,0) : 4.3
    component(2,0,0,1) : 0
    component(2,0,0,2) : 31.8
    component(2,0,1,0) : 0
    component(2,0,1,1) : -2.5
    component(2,0,1,2) : 0
    component(2,0,2,0) : 31.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 10
    component(2,1,0,0) : 0
    component(2,1,0,1) : -6.2
    component(2,1,0,2) : 0
    component(2,1,1,0) : -6.2
    component(2,1,1,1) : 0
    component(2,1,1,2) : 57.4
    component(2,1,2,0) : 0
    component(2,1,2,1) : 57.4
    component(2,1,2,2) : 0
    component(2,2,0,0) : 61.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : 10
    component(2,2,1,0) : 0
    component(2,2,1,1) : 65.5
    component(2,2,1,2) : 0
    component(2,2,2,0) : 10
    component(2,2,2,1) : 0
    component(2,2,2,2) : 191.6

Muscovite    
```cpp
mpc::core::StiffnessTensor<double> muscovite_stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();
print_tensor_components_double_4_fo(muscovite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 184.3
    component(0,0,0,1) : 0
    component(0,0,0,2) : -2
    component(0,0,1,0) : 0
    component(0,0,1,1) : 48.3
    component(0,0,1,2) : 0
    component(0,0,2,0) : -2
    component(0,0,2,1) : 0
    component(0,0,2,2) : 23.8
    component(0,1,0,0) : 0
    component(0,1,0,1) : 72.4
    component(0,1,0,2) : 0
    component(0,1,1,0) : 72.4
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0.5
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0.5
    component(0,1,2,2) : 0
    component(0,2,0,0) : -2
    component(0,2,0,1) : 0
    component(0,2,0,2) : 17.6
    component(0,2,1,0) : 0
    component(0,2,1,1) : 3.9
    component(0,2,1,2) : 0
    component(0,2,2,0) : 17.6
    component(0,2,2,1) : 0
    component(0,2,2,2) : 1.2
    component(1,0,0,0) : 0
    component(1,0,0,1) : 72.4
    component(1,0,0,2) : 0
    component(1,0,1,0) : 72.4
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0.5
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0.5
    component(1,0,2,2) : 0
    component(1,1,0,0) : 48.3
    component(1,1,0,1) : 0
    component(1,1,0,2) : 3.9
    component(1,1,1,0) : 0
    component(1,1,1,1) : 178.4
    component(1,1,1,2) : 0
    component(1,1,2,0) : 3.9
    component(1,1,2,1) : 0
    component(1,1,2,2) : 21.7
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0.5
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0.5
    component(1,2,1,1) : 0
    component(1,2,1,2) : 16
    component(1,2,2,0) : 0
    component(1,2,2,1) : 16
    component(1,2,2,2) : 0
    component(2,0,0,0) : -2
    component(2,0,0,1) : 0
    component(2,0,0,2) : 17.6
    component(2,0,1,0) : 0
    component(2,0,1,1) : 3.9
    component(2,0,1,2) : 0
    component(2,0,2,0) : 17.6
    component(2,0,2,1) : 0
    component(2,0,2,2) : 1.2
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0.5
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0.5
    component(2,1,1,1) : 0
    component(2,1,1,2) : 16
    component(2,1,2,0) : 0
    component(2,1,2,1) : 16
    component(2,1,2,2) : 0
    component(2,2,0,0) : 23.8
    component(2,2,0,1) : 0
    component(2,2,0,2) : 1.2
    component(2,2,1,0) : 0
    component(2,2,1,1) : 21.7
    component(2,2,1,2) : 0
    component(2,2,2,0) : 1.2
    component(2,2,2,1) : 0
    component(2,2,2,2) : 59.1

Gypsum    
```cpp
mpc::core::StiffnessTensor<double> gypsum_stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();
print_tensor_components_double_4_fo(gypsum_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 78.6
    component(0,0,0,1) : 0
    component(0,0,0,2) : -7
    component(0,0,1,0) : 0
    component(0,0,1,1) : 41
    component(0,0,1,2) : 0
    component(0,0,2,0) : -7
    component(0,0,2,1) : 0
    component(0,0,2,2) : 26.8
    component(0,1,0,0) : 0
    component(0,1,0,1) : 10.4
    component(0,1,0,2) : 0
    component(0,1,1,0) : 10.4
    component(0,1,1,1) : 0
    component(0,1,1,2) : -1.6
    component(0,1,2,0) : 0
    component(0,1,2,1) : -1.6
    component(0,1,2,2) : 0
    component(0,2,0,0) : -7
    component(0,2,0,1) : 0
    component(0,2,0,2) : 26.4
    component(0,2,1,0) : 0
    component(0,2,1,1) : 3.1
    component(0,2,1,2) : 0
    component(0,2,2,0) : 26.4
    component(0,2,2,1) : 0
    component(0,2,2,2) : -17.4
    component(1,0,0,0) : 0
    component(1,0,0,1) : 10.4
    component(1,0,0,2) : 0
    component(1,0,1,0) : 10.4
    component(1,0,1,1) : 0
    component(1,0,1,2) : -1.6
    component(1,0,2,0) : 0
    component(1,0,2,1) : -1.6
    component(1,0,2,2) : 0
    component(1,1,0,0) : 41
    component(1,1,0,1) : 0
    component(1,1,0,2) : 3.1
    component(1,1,1,0) : 0
    component(1,1,1,1) : 62.7
    component(1,1,1,2) : 0
    component(1,1,2,0) : 3.1
    component(1,1,2,1) : 0
    component(1,1,2,2) : 24.2
    component(1,2,0,0) : 0
    component(1,2,0,1) : -1.6
    component(1,2,0,2) : 0
    component(1,2,1,0) : -1.6
    component(1,2,1,1) : 0
    component(1,2,1,2) : 9.1
    component(1,2,2,0) : 0
    component(1,2,2,1) : 9.1
    component(1,2,2,2) : 0
    component(2,0,0,0) : -7
    component(2,0,0,1) : 0
    component(2,0,0,2) : 26.4
    component(2,0,1,0) : 0
    component(2,0,1,1) : 3.1
    component(2,0,1,2) : 0
    component(2,0,2,0) : 26.4
    component(2,0,2,1) : 0
    component(2,0,2,2) : -17.4
    component(2,1,0,0) : 0
    component(2,1,0,1) : -1.6
    component(2,1,0,2) : 0
    component(2,1,1,0) : -1.6
    component(2,1,1,1) : 0
    component(2,1,1,2) : 9.1
    component(2,1,2,0) : 0
    component(2,1,2,1) : 9.1
    component(2,1,2,2) : 0
    component(2,2,0,0) : 26.8
    component(2,2,0,1) : 0
    component(2,2,0,2) : -17.4
    component(2,2,1,0) : 0
    component(2,2,1,1) : 24.2
    component(2,2,1,2) : 0
    component(2,2,2,0) : -17.4
    component(2,2,2,1) : 0
    component(2,2,2,2) : 72.6

Enstatite    
```cpp
mpc::core::StiffnessTensor<double> enstatite_stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(enstatite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 224.7
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 72.4
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 54.1
    component(0,1,0,0) : 0
    component(0,1,0,1) : 81.6
    component(0,1,0,2) : 0
    component(0,1,1,0) : 81.6
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 75.9
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 75.9
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 81.6
    component(1,0,0,2) : 0
    component(1,0,1,0) : 81.6
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 72.4
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 177.9
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 52.7
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 77.6
    component(1,2,2,0) : 0
    component(1,2,2,1) : 77.6
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 75.9
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 75.9
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 77.6
    component(2,1,2,0) : 0
    component(2,1,2,1) : 77.6
    component(2,1,2,2) : 0
    component(2,2,0,0) : 54.1
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 52.7
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 213.6

Forsterite    
```cpp
mpc::core::StiffnessTensor<double> forsterite_stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();
print_tensor_components_double_4_fo(forsterite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 328
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 69
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 69
    component(0,1,0,0) : 0
    component(0,1,0,1) : 80.9
    component(0,1,0,2) : 0
    component(0,1,1,0) : 80.9
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 81.3
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 81.3
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 80.9
    component(1,0,0,2) : 0
    component(1,0,1,0) : 80.9
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 69
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 200
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 73
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 66.7
    component(1,2,2,0) : 0
    component(1,2,2,1) : 66.7
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 81.3
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 81.3
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 66.7
    component(2,1,2,0) : 0
    component(2,1,2,1) : 66.7
    component(2,1,2,2) : 0
    component(2,2,0,0) : 69
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 73
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 235

Fayalite    
```cpp
mpc::core::StiffnessTensor<double> fayalite_stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();
print_tensor_components_double_4_fo(fayalite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 266
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 94
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 92
    component(0,1,0,0) : 0
    component(0,1,0,1) : 57
    component(0,1,0,2) : 0
    component(0,1,1,0) : 57
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 46.5
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 46.5
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 57
    component(1,0,0,2) : 0
    component(1,0,1,0) : 57
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 94
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 168
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 92
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 32.3
    component(1,2,2,0) : 0
    component(1,2,2,1) : 32.3
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 46.5
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 46.5
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 32.3
    component(2,1,2,0) : 0
    component(2,1,2,1) : 32.3
    component(2,1,2,2) : 0
    component(2,2,0,0) : 92
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 92
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 232

Montecellite    
```cpp
mpc::core::StiffnessTensor<double> montecellite_stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();
print_tensor_components_double_4_fo(montecellite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 216
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 59
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 71
    component(0,1,0,0) : 0
    component(0,1,0,1) : 59.2
    component(0,1,0,2) : 0
    component(0,1,1,0) : 59.2
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 56.5
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 56.5
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 59.2
    component(1,0,0,2) : 0
    component(1,0,1,0) : 59.2
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 59
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 150
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 77
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 50.6
    component(1,2,2,0) : 0
    component(1,2,2,1) : 50.6
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 56.5
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 56.5
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 50.6
    component(2,1,2,0) : 0
    component(2,1,2,1) : 50.6
    component(2,1,2,2) : 0
    component(2,2,0,0) : 71
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 77
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 184

Andalusite    
```cpp
mpc::core::StiffnessTensor<double> andalusite_stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(andalusite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 233.4
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 97.7
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 116.2
    component(0,1,0,0) : 0
    component(0,1,0,1) : 112.3
    component(0,1,0,2) : 0
    component(0,1,1,0) : 112.3
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 87.8
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 87.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 112.3
    component(1,0,0,2) : 0
    component(1,0,1,0) : 112.3
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 97.7
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 289
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 81.4
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 99.5
    component(1,2,2,0) : 0
    component(1,2,2,1) : 99.5
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 87.8
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 87.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 99.5
    component(2,1,2,0) : 0
    component(2,1,2,1) : 99.5
    component(2,1,2,2) : 0
    component(2,2,0,0) : 116.2
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 81.4
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 380.1

Silimanite    
```cpp
mpc::core::StiffnessTensor<double> silimanite_stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();
print_tensor_components_double_4_fo(silimanite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 287.3
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 158.6
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 83.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 89.3
    component(0,1,0,2) : 0
    component(0,1,1,0) : 89.3
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 80.7
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 80.7
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 89.3
    component(1,0,0,2) : 0
    component(1,0,1,0) : 89.3
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 158.6
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 231.9
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 94.7
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 122.4
    component(1,2,2,0) : 0
    component(1,2,2,1) : 122.4
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 80.7
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 80.7
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 122.4
    component(2,1,2,0) : 0
    component(2,1,2,1) : 122.4
    component(2,1,2,2) : 0
    component(2,2,0,0) : 83.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 94.7
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 388.4

Barite    
```cpp
mpc::core::StiffnessTensor<double> barite_stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();
print_tensor_components_double_4_fo(barite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 95.1
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 51.3
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 33.6
    component(0,1,0,0) : 0
    component(0,1,0,1) : 27.7
    component(0,1,0,2) : 0
    component(0,1,1,0) : 27.7
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 29
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 29
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 27.7
    component(1,0,0,2) : 0
    component(1,0,1,0) : 27.7
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 51.3
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 83.7
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 32.8
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 11.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 11.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 29
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 29
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 11.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 11.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 33.6
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 32.8
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 110.6

Anhydrite    
```cpp
mpc::core::StiffnessTensor<double> anhydrite_stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();
print_tensor_components_double_4_fo(anhydrite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 93.8
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 16.5
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 15.2
    component(0,1,0,0) : 0
    component(0,1,0,1) : 9.3
    component(0,1,0,2) : 0
    component(0,1,1,0) : 9.3
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 26.5
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 26.5
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 9.3
    component(1,0,0,2) : 0
    component(1,0,1,0) : 9.3
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 16.5
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 185
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 31.7
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 32.5
    component(1,2,2,0) : 0
    component(1,2,2,1) : 32.5
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 26.5
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 26.5
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 32.5
    component(2,1,2,0) : 0
    component(2,1,2,1) : 32.5
    component(2,1,2,2) : 0
    component(2,2,0,0) : 15.2
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 31.7
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 112

Dolomite    
```cpp
mpc::core::StiffnessTensor<double> dolomite_stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(dolomite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 205
    component(0,0,0,1) : 0
    component(0,0,0,2) : 13.7
    component(0,0,1,0) : 0
    component(0,0,1,1) : 71
    component(0,0,1,2) : -19.5
    component(0,0,2,0) : 13.7
    component(0,0,2,1) : -19.5
    component(0,0,2,2) : 57.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 67
    component(0,1,0,2) : -19.5
    component(0,1,1,0) : 67
    component(0,1,1,1) : 0
    component(0,1,1,2) : -13.7
    component(0,1,2,0) : -19.5
    component(0,1,2,1) : -13.7
    component(0,1,2,2) : 0
    component(0,2,0,0) : 13.7
    component(0,2,0,1) : -19.5
    component(0,2,0,2) : 39.8
    component(0,2,1,0) : -19.5
    component(0,2,1,1) : -13.7
    component(0,2,1,2) : 0
    component(0,2,2,0) : 39.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 67
    component(1,0,0,2) : -19.5
    component(1,0,1,0) : 67
    component(1,0,1,1) : 0
    component(1,0,1,2) : -13.7
    component(1,0,2,0) : -19.5
    component(1,0,2,1) : -13.7
    component(1,0,2,2) : 0
    component(1,1,0,0) : 71
    component(1,1,0,1) : 0
    component(1,1,0,2) : -13.7
    component(1,1,1,0) : 0
    component(1,1,1,1) : 205
    component(1,1,1,2) : 19.5
    component(1,1,2,0) : -13.7
    component(1,1,2,1) : 19.5
    component(1,1,2,2) : 57.4
    component(1,2,0,0) : -19.5
    component(1,2,0,1) : -13.7
    component(1,2,0,2) : 0
    component(1,2,1,0) : -13.7
    component(1,2,1,1) : 19.5
    component(1,2,1,2) : 39.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 39.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 13.7
    component(2,0,0,1) : -19.5
    component(2,0,0,2) : 39.8
    component(2,0,1,0) : -19.5
    component(2,0,1,1) : -13.7
    component(2,0,1,2) : 0
    component(2,0,2,0) : 39.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : -19.5
    component(2,1,0,1) : -13.7
    component(2,1,0,2) : 0
    component(2,1,1,0) : -13.7
    component(2,1,1,1) : 19.5
    component(2,1,1,2) : 39.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 39.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 57.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 57.4
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 113

Rutile    
```cpp
mpc::core::StiffnessTensor<double> rutile_stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();
print_tensor_components_double_4_fo(rutile_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 269
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 177
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 146
    component(0,1,0,0) : 0
    component(0,1,0,1) : 192
    component(0,1,0,2) : 0
    component(0,1,1,0) : 192
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 124
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 124
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 192
    component(1,0,0,2) : 0
    component(1,0,1,0) : 192
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 177
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 269
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 146
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 124
    component(1,2,2,0) : 0
    component(1,2,2,1) : 124
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 124
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 124
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 124
    component(2,1,2,0) : 0
    component(2,1,2,1) : 124
    component(2,1,2,2) : 0
    component(2,2,0,0) : 146
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 146
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 480

Zircon    
```cpp
mpc::core::StiffnessTensor<double> zircon_stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();
print_tensor_components_double_4_fo(zircon_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 256
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 175
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 214
    component(0,1,0,0) : 0
    component(0,1,0,1) : 116
    component(0,1,0,2) : 0
    component(0,1,1,0) : 116
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 73.5
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 73.5
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 116
    component(1,0,0,2) : 0
    component(1,0,1,0) : 116
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 175
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 256
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 214
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 73.5
    component(1,2,2,0) : 0
    component(1,2,2,1) : 73.5
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 73.5
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 73.5
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 73.5
    component(2,1,2,0) : 0
    component(2,1,2,1) : 73.5
    component(2,1,2,2) : 0
    component(2,2,0,0) : 214
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 214
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 372

Corundum    
```cpp
mpc::core::StiffnessTensor<double> corundum_stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();
print_tensor_components_double_4_fo(corundum_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 497
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 162
    component(0,0,1,2) : -21.9
    component(0,0,2,0) : 0
    component(0,0,2,1) : -21.9
    component(0,0,2,2) : 116
    component(0,1,0,0) : 0
    component(0,1,0,1) : 167.5
    component(0,1,0,2) : -21.9
    component(0,1,1,0) : 167.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : -21.9
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : -21.9
    component(0,2,0,2) : 146.8
    component(0,2,1,0) : -21.9
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 146.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 167.5
    component(1,0,0,2) : -21.9
    component(1,0,1,0) : 167.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : -21.9
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 162
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 497
    component(1,1,1,2) : 21.9
    component(1,1,2,0) : 0
    component(1,1,2,1) : 21.9
    component(1,1,2,2) : 116
    component(1,2,0,0) : -21.9
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 21.9
    component(1,2,1,2) : 146.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 146.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : -21.9
    component(2,0,0,2) : 146.8
    component(2,0,1,0) : -21.9
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 146.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : -21.9
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 21.9
    component(2,1,1,2) : 146.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 146.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 116
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 116
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 501

Calcite    
```cpp
mpc::core::StiffnessTensor<double> calcite_stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();
print_tensor_components_double_4_fo(calcite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 144
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 53.9
    component(0,0,1,2) : -20.5
    component(0,0,2,0) : 0
    component(0,0,2,1) : -20.5
    component(0,0,2,2) : 51.1
    component(0,1,0,0) : 0
    component(0,1,0,1) : 45.05
    component(0,1,0,2) : -20.5
    component(0,1,1,0) : 45.05
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : -20.5
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : -20.5
    component(0,2,0,2) : 33.5
    component(0,2,1,0) : -20.5
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 33.5
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 45.05
    component(1,0,0,2) : -20.5
    component(1,0,1,0) : 45.05
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : -20.5
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 53.9
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 144
    component(1,1,1,2) : 20.5
    component(1,1,2,0) : 0
    component(1,1,2,1) : 20.5
    component(1,1,2,2) : 51.1
    component(1,2,0,0) : -20.5
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 20.5
    component(1,2,1,2) : 33.5
    component(1,2,2,0) : 0
    component(1,2,2,1) : 33.5
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : -20.5
    component(2,0,0,2) : 33.5
    component(2,0,1,0) : -20.5
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 33.5
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : -20.5
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 20.5
    component(2,1,1,2) : 33.5
    component(2,1,2,0) : 0
    component(2,1,2,1) : 33.5
    component(2,1,2,2) : 0
    component(2,2,0,0) : 51.1
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 51.1
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 84

Quartz    
```cpp
mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
print_tensor_components_double_4_fo(quartz_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 86.6
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 6.7
    component(0,0,1,2) : -17.8
    component(0,0,2,0) : 0
    component(0,0,2,1) : -17.8
    component(0,0,2,2) : 12.6
    component(0,1,0,0) : 0
    component(0,1,0,1) : 39.95
    component(0,1,0,2) : -17.8
    component(0,1,1,0) : 39.95
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : -17.8
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : -17.8
    component(0,2,0,2) : 57.8
    component(0,2,1,0) : -17.8
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 57.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 39.95
    component(1,0,0,2) : -17.8
    component(1,0,1,0) : 39.95
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : -17.8
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 6.7
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 86.6
    component(1,1,1,2) : 17.8
    component(1,1,2,0) : 0
    component(1,1,2,1) : 17.8
    component(1,1,2,2) : 12.6
    component(1,2,0,0) : -17.8
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 17.8
    component(1,2,1,2) : 57.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 57.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : -17.8
    component(2,0,0,2) : 57.8
    component(2,0,1,0) : -17.8
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 57.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : -17.8
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 17.8
    component(2,1,1,2) : 57.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 57.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 12.6
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 12.6
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 106.1

Tourmaline    
```cpp
mpc::core::StiffnessTensor<double> tourmaline_stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();
print_tensor_components_double_4_fo(tourmaline_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 305
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 108
    component(0,0,1,2) : -6
    component(0,0,2,0) : 0
    component(0,0,2,1) : -6
    component(0,0,2,2) : 51
    component(0,1,0,0) : 0
    component(0,1,0,1) : 98.5
    component(0,1,0,2) : -6
    component(0,1,1,0) : 98.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : -6
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : -6
    component(0,2,0,2) : 64.8
    component(0,2,1,0) : -6
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 64.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 98.5
    component(1,0,0,2) : -6
    component(1,0,1,0) : 98.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : -6
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 108
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 305
    component(1,1,1,2) : 6
    component(1,1,2,0) : 0
    component(1,1,2,1) : 6
    component(1,1,2,2) : 51
    component(1,2,0,0) : -6
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 6
    component(1,2,1,2) : 64.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 64.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : -6
    component(2,0,0,2) : 64.8
    component(2,0,1,0) : -6
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 64.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : -6
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 6
    component(2,1,1,2) : 64.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 64.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 51
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 51
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 176.4

Beryl    
```cpp
mpc::core::StiffnessTensor<double> beryl_stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();
print_tensor_components_double_4_fo(beryl_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 304.2
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 123.8
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 114.5
    component(0,1,0,0) : 0
    component(0,1,0,1) : 90.2
    component(0,1,0,2) : 0
    component(0,1,1,0) : 90.2
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 65.3
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 65.3
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 90.2
    component(1,0,0,2) : 0
    component(1,0,1,0) : 90.2
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 123.8
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 304.2
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 114.5
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 65.3
    component(1,2,2,0) : 0
    component(1,2,2,1) : 65.3
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 65.3
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 65.3
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 65.3
    component(2,1,2,0) : 0
    component(2,1,2,1) : 65.3
    component(2,1,2,2) : 0
    component(2,2,0,0) : 114.5
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 114.5
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 277.6

Graphite    
```cpp
mpc::core::StiffnessTensor<double> graphite_stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(graphite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 1060
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 180
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 15
    component(0,1,0,0) : 0
    component(0,1,0,1) : 440
    component(0,1,0,2) : 0
    component(0,1,1,0) : 440
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 0.3
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 0.3
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 440
    component(1,0,0,2) : 0
    component(1,0,1,0) : 440
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 180
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1060
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 15
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 0.3
    component(1,2,2,0) : 0
    component(1,2,2,1) : 0.3
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 0.3
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 0.3
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 0.3
    component(2,1,2,0) : 0
    component(2,1,2,1) : 0.3
    component(2,1,2,2) : 0
    component(2,2,0,0) : 15
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 15
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 36.5

Wusite    
```cpp
mpc::core::StiffnessTensor<double> wusite_stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(wusite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 245.7
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 149.3
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 149.3
    component(0,1,0,0) : 0
    component(0,1,0,1) : 44.7
    component(0,1,0,2) : 0
    component(0,1,1,0) : 44.7
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 44.7
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 44.7
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 44.7
    component(1,0,0,2) : 0
    component(1,0,1,0) : 44.7
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 149.3
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 245.7
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 149.3
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 44.7
    component(1,2,2,0) : 0
    component(1,2,2,1) : 44.7
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 44.7
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 44.7
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 44.7
    component(2,1,2,0) : 0
    component(2,1,2,1) : 44.7
    component(2,1,2,2) : 0
    component(2,2,0,0) : 149.3
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 149.3
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 245.7

Manganosite    
```cpp
mpc::core::StiffnessTensor<double> manganosite_stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();
print_tensor_components_double_4_fo(manganosite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 227
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 116
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 116
    component(0,1,0,0) : 0
    component(0,1,0,1) : 78
    component(0,1,0,2) : 0
    component(0,1,1,0) : 78
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 78
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 78
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 78
    component(1,0,0,2) : 0
    component(1,0,1,0) : 78
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 116
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 227
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 116
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 78
    component(1,2,2,0) : 0
    component(1,2,2,1) : 78
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 78
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 78
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 78
    component(2,1,2,0) : 0
    component(2,1,2,1) : 78
    component(2,1,2,2) : 0
    component(2,2,0,0) : 116
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 116
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 227

Periclase    
```cpp
mpc::core::StiffnessTensor<double> periclase_stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();
print_tensor_components_double_4_fo(periclase_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 294
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 93
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 93
    component(0,1,0,0) : 0
    component(0,1,0,1) : 155
    component(0,1,0,2) : 0
    component(0,1,1,0) : 155
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 155
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 155
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 155
    component(1,0,0,2) : 0
    component(1,0,1,0) : 155
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 93
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 294
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 93
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 155
    component(1,2,2,0) : 0
    component(1,2,2,1) : 155
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 155
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 155
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 155
    component(2,1,2,0) : 0
    component(2,1,2,1) : 155
    component(2,1,2,2) : 0
    component(2,2,0,0) : 93
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 93
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 294

Magnetite    
```cpp
mpc::core::StiffnessTensor<double> magnetite_stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(magnetite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 270
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 108
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 108
    component(0,1,0,0) : 0
    component(0,1,0,1) : 98.7
    component(0,1,0,2) : 0
    component(0,1,1,0) : 98.7
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 98.7
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 98.7
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 98.7
    component(1,0,0,2) : 0
    component(1,0,1,0) : 98.7
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 108
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 270
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 108
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 98.7
    component(1,2,2,0) : 0
    component(1,2,2,1) : 98.7
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 98.7
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 98.7
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 98.7
    component(2,1,2,0) : 0
    component(2,1,2,1) : 98.7
    component(2,1,2,2) : 0
    component(2,2,0,0) : 108
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 108
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 270

Chromite    
```cpp
mpc::core::StiffnessTensor<double> chromite_stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();
print_tensor_components_double_4_fo(chromite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 322
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 144
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 144
    component(0,1,0,0) : 0
    component(0,1,0,1) : 117
    component(0,1,0,2) : 0
    component(0,1,1,0) : 117
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 117
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 117
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 117
    component(1,0,0,2) : 0
    component(1,0,1,0) : 117
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 144
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 322
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 144
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 117
    component(1,2,2,0) : 0
    component(1,2,2,1) : 117
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 117
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 117
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 117
    component(2,1,2,0) : 0
    component(2,1,2,1) : 117
    component(2,1,2,2) : 0
    component(2,2,0,0) : 144
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 144
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 322

MINERAL    
```cpp
// Spinel
mpc::core::StiffnessTensor<double> spinel_stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();
print_tensor_components_double_4_fo(spinel_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 282.9
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 155.4
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 155.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 154.8
    component(0,1,0,2) : 0
    component(0,1,1,0) : 154.8
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 154.8
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 154.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 154.8
    component(1,0,0,2) : 0
    component(1,0,1,0) : 154.8
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 155.4
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 282.9
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 155.4
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 154.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 154.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 154.8
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 154.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 154.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 154.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 155.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 155.4
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 282.9

Pyrite    
```cpp
mpc::core::StiffnessTensor<double> pyrite_stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();
print_tensor_components_double_4_fo(pyrite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 361
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 33.6
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 33.6
    component(0,1,0,0) : 0
    component(0,1,0,1) : 105.2
    component(0,1,0,2) : 0
    component(0,1,1,0) : 105.2
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 105.2
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 105.2
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 105.2
    component(1,0,0,2) : 0
    component(1,0,1,0) : 105.2
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 33.6
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 361
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 33.6
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 105.2
    component(1,2,2,0) : 0
    component(1,2,2,1) : 105.2
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 105.2
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 105.2
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 105.2
    component(2,1,2,0) : 0
    component(2,1,2,1) : 105.2
    component(2,1,2,2) : 0
    component(2,2,0,0) : 33.6
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 33.6
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 361

Galena    
```cpp
mpc::core::StiffnessTensor<double> galena_stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();
print_tensor_components_double_4_fo(galena_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 127
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 24.4
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 24.4
    component(0,1,0,0) : 0
    component(0,1,0,1) : 23
    component(0,1,0,2) : 0
    component(0,1,1,0) : 23
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 23
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 23
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 23
    component(1,0,0,2) : 0
    component(1,0,1,0) : 23
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 24.4
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 127
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 24.4
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 23
    component(1,2,2,0) : 0
    component(1,2,2,1) : 23
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 23
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 23
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 23
    component(2,1,2,0) : 0
    component(2,1,2,1) : 23
    component(2,1,2,2) : 0
    component(2,2,0,0) : 24.4
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 24.4
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 127

MINERAL    
```cpp
// Sphalerite
mpc::core::StiffnessTensor<double> sphalerite_stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();
print_tensor_components_double_4_fo(sphalerite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 102
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 64.6
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 64.6
    component(0,1,0,0) : 0
    component(0,1,0,1) : 44.6
    component(0,1,0,2) : 0
    component(0,1,1,0) : 44.6
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 44.6
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 44.6
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 44.6
    component(1,0,0,2) : 0
    component(1,0,1,0) : 44.6
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 64.6
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 102
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 64.6
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 44.6
    component(1,2,2,0) : 0
    component(1,2,2,1) : 44.6
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 44.6
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 44.6
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 44.6
    component(2,1,2,0) : 0
    component(2,1,2,1) : 44.6
    component(2,1,2,2) : 0
    component(2,2,0,0) : 64.6
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 64.6
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 102

Fluorite    
```cpp
mpc::core::StiffnessTensor<double> fluorite_stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();
print_tensor_components_double_4_fo(fluorite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 165
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 47
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 47
    component(0,1,0,0) : 0
    component(0,1,0,1) : 33.9
    component(0,1,0,2) : 0
    component(0,1,1,0) : 33.9
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 33.9
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 33.9
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 33.9
    component(1,0,0,2) : 0
    component(1,0,1,0) : 33.9
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 47
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 165
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 47
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 33.9
    component(1,2,2,0) : 0
    component(1,2,2,1) : 33.9
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 33.9
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 33.9
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 33.9
    component(2,1,2,0) : 0
    component(2,1,2,1) : 33.9
    component(2,1,2,2) : 0
    component(2,2,0,0) : 47
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 47
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 165

Halite    
```cpp
mpc::core::StiffnessTensor<double> halite_stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();
print_tensor_components_double_4_fo(halite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 49.1
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 12.8
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 12.8
    component(0,1,0,0) : 0
    component(0,1,0,1) : 12.8
    component(0,1,0,2) : 0
    component(0,1,1,0) : 12.8
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 12.8
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 12.8
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 12.8
    component(1,0,0,2) : 0
    component(1,0,1,0) : 12.8
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 12.8
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 49.1
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 12.8
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 12.8
    component(1,2,2,0) : 0
    component(1,2,2,1) : 12.8
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 12.8
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 12.8
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 12.8
    component(2,1,2,0) : 0
    component(2,1,2,1) : 12.8
    component(2,1,2,2) : 0
    component(2,2,0,0) : 12.8
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 12.8
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 49.1

Sylvite    
```cpp
mpc::core::StiffnessTensor<double> sylvite_stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();
print_tensor_components_double_4_fo(sylvite_stiffness_tensor.tensor);
```
Output

    component(0,0,0,0) : 40.5
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 6.9
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 6.9
    component(0,1,0,0) : 0
    component(0,1,0,1) : 6.27
    component(0,1,0,2) : 0
    component(0,1,1,0) : 6.27
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 6.27
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 6.27
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 6.27
    component(1,0,0,2) : 0
    component(1,0,1,0) : 6.27
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 6.9
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 40.5
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 6.9
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 6.27
    component(1,2,2,0) : 0
    component(1,2,2,1) : 6.27
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 6.27
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 6.27
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 6.27
    component(2,1,2,0) : 0
    component(2,1,2,1) : 6.27
    component(2,1,2,2) : 0
    component(2,2,0,0) : 6.9
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 6.9
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 40.5


#### symmetry matrix representation
script for printing stiffness or compliance tensor components in matrix form (no scalars!)
> Thomsen, L., 2014, Understanding Seismic Anisotropy in Exploration and Exploitation
> Tsvankin, I., 2001, Seismic Signatures and Analysis of Reflection Data in Anisotropic Media
[mpcexamples::mpcSymmetryMatrixRepresentation()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_symmetrymatrixrepresentation.cpp)
```cpp
// mineral data tensors
// Augite
mpc::core::StiffnessTensor<double> augite_stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();
std::cout << "\nAugite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;


// Albite
mpc::core::StiffnessTensor<double> albite_stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();
std::cout << "\nAlbite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Anorthite
mpc::core::StiffnessTensor<double> anorthite_stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();
std::cout << "\nAnorthite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Labradorite
mpc::core::StiffnessTensor<double> labradorite_stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();
std::cout << "\nLabradorite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Microcline
mpc::core::StiffnessTensor<double> microcline_stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();
std::cout << "\nMicrocline Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Oligoclase
mpc::core::StiffnessTensor<double> oligoclase_stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();
std::cout << "\nOligoclase Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Coesite
mpc::core::StiffnessTensor<double> coesite_stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();
std::cout << "\nCoesite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Epidote
mpc::core::StiffnessTensor<double> epidote_stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();
std::cout << "\nEpidote Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Hornblende
mpc::core::StiffnessTensor<double> hornblende_stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();
std::cout << "\nHornblende Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Muscovite
mpc::core::StiffnessTensor<double> muscovite_stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();
std::cout << "\nMuscovite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Gypsum
mpc::core::StiffnessTensor<double> gypsum_stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();
std::cout << "\nGypsum Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Enstatite
mpc::core::StiffnessTensor<double> enstatite_stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();
std::cout << "\nEnstatite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Forsterite
mpc::core::StiffnessTensor<double> forsterite_stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();
std::cout << "\nForsterite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Fayalite
mpc::core::StiffnessTensor<double> fayalite_stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();
std::cout << "\nFayalite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Montecellite
mpc::core::StiffnessTensor<double> montecellite_stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();
std::cout << "\nMontecellite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Andalusite
mpc::core::StiffnessTensor<double> andalusite_stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();
std::cout << "\nAndalusite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Silimanite
mpc::core::StiffnessTensor<double> silimanite_stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();
std::cout << "\nSilimanite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Barite
mpc::core::StiffnessTensor<double> barite_stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();
std::cout << "\nBarite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Anhydrite
mpc::core::StiffnessTensor<double> anhydrite_stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();
std::cout << "\nAnhydrite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Dolomite
mpc::core::StiffnessTensor<double> dolomite_stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();
std::cout << "\nDolomite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Rutile
mpc::core::StiffnessTensor<double> rutile_stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();
std::cout << "\nRutile Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Zircon
mpc::core::StiffnessTensor<double> zircon_stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();
std::cout << "\nZircon Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Corundum
mpc::core::StiffnessTensor<double> corundum_stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();
std::cout << "\nCorundum Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Calcite
mpc::core::StiffnessTensor<double> calcite_stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();
std::cout << "\nCalcite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Quartz
mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
std::cout << "\nQuartz Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Tourmaline
mpc::core::StiffnessTensor<double> tourmaline_stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();
std::cout << "\nTourmaline Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Beryl
mpc::core::StiffnessTensor<double> beryl_stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();
std::cout << "\nBeryl Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Graphite
mpc::core::StiffnessTensor<double> graphite_stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();
std::cout << "\nGraphite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Wusite
mpc::core::StiffnessTensor<double> wusite_stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();
std::cout << "\nWusite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Manganosite
mpc::core::StiffnessTensor<double> manganosite_stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();
std::cout << "\nManganosite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Periclase
mpc::core::StiffnessTensor<double> periclase_stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();
std::cout << "\nPericlase Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Magnetite
mpc::core::StiffnessTensor<double> magnetite_stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();
std::cout << "\nMagnetite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Chromite
mpc::core::StiffnessTensor<double> chromite_stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();
std::cout << "\nChromite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Spinel
mpc::core::StiffnessTensor<double> spinel_stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();
std::cout << "\nSpinel Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Pyrite
mpc::core::StiffnessTensor<double> pyrite_stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();
std::cout << "\nPyrite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Galena
mpc::core::StiffnessTensor<double> galena_stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();
std::cout << "\nGalena Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Sphalerite
mpc::core::StiffnessTensor<double> sphalerite_stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();
std::cout << "\nSphalerite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Fluorite
mpc::core::StiffnessTensor<double> fluorite_stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();
std::cout << "\nFluorite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Halite
mpc::core::StiffnessTensor<double> halite_stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();
std::cout << "\nHalite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;

// Sylvite
mpc::core::StiffnessTensor<double> sylvite_stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();
std::cout << "\nSylvite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,0,0) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,0,0) << " "
          << std::endl;
std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,1,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,1,1) << " "
          << std::endl;
std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,2,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,2,2) << " "
          << std::endl;
std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,1,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,1,2) << " "
          << std::endl;
std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,0,2) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,0,2) << " "
          << std::endl;
std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,0,1) << " "
          << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,0,1) << " "
          << std::endl;
```
Output

    Augite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  181.6   73.4   72.4      0   19.9      0
     [1]   73.4  150.7   33.9      0   16.6      0
     [2]   72.4   33.9  217.8      0   24.6      0
     [3]      0      0      0   69.7      0    4.3
     [4]   19.9   16.6   24.6      0   51.1      0
     [5]      0      0      0    4.3      0   55.8

    Albite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]     74   36.4   39.4      0   -6.6      0
     [1]   36.4    131     31      0  -12.8      0
     [2]   39.4     31    128      0    -20      0
     [3]      0      0      0   17.3      0   -2.5
     [4]   -6.6  -12.8    -20      0   29.6      0
     [5]      0      0      0   -2.5      0     32

    Anorthite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    124     66     50      0    -19      0
     [1]     66    205     42      0     -7      0
     [2]     50     42    156      0    -18      0
     [3]      0      0      0   23.5      0     -1
     [4]    -19     -7    -18      0   40.4      0
     [5]      0      0      0     -1      0   41.5

    Labradorite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   99.4   62.8   48.7      0   -2.5      0
     [1]   62.8    158   26.7      0  -10.7      0
     [2]   48.7   26.7    150      0  -12.4      0
     [3]      0      0      0   21.7      0   -5.4
     [4]   -2.5  -10.7  -12.4      0   34.5      0
     [5]      0      0      0   -5.4      0   37.1

    Microcline Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]     67   45.3   26.5      0   -0.2      0
     [1]   45.3    169   20.4      0  -12.3      0
     [2]   26.5   20.4    118      0    -15      0
     [3]      0      0      0   14.3      0   -1.9
     [4]   -0.2  -12.3    -15      0   23.8      0
     [5]      0      0      0   -1.9      0   36.4

    Oligoclase Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   80.8   37.9   52.9      0  -15.7      0
     [1]   37.9    163   32.7      0  -23.7      0
     [2]   52.9   32.7    124      0     -6      0
     [3]      0      0      0   18.7      0   -0.9
     [4]  -15.7  -23.7     -6      0   27.1      0
     [5]      0      0      0   -0.9      0   35.7

    Coesite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  160.8   82.1  102.9      0  -36.2      0
     [1]   82.1  230.4   35.6      0    2.6      0
     [2]  102.9   35.6  231.6      0  -39.3      0
     [3]      0      0      0   67.8      0    9.9
     [4]  -36.2    2.6  -39.3      0   73.3      0
     [5]      0      0      0    9.9      0   58.8

    Epidote Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  211.8   66.3   45.2      0      0      0
     [1]   66.3  238.7   45.6      0   -8.2      0
     [2]   45.2   45.6    202      0  -14.3      0
     [3]      0      0      0   39.1      0   -3.4
     [4]      0   -8.2  -14.3      0   43.2      0
     [5]      0      0      0   -3.4      0   77.5

    Hornblende Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    116   44.9   61.4      0    4.3      0
     [1]   44.9  159.7   65.5      0   -2.5      0
     [2]   61.4   65.5  191.6      0     10      0
     [3]      0      0      0   57.4      0   -6.2
     [4]    4.3   -2.5     10      0   31.8      0
     [5]      0      0      0   -6.2      0   36.8

    Muscovite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  184.3   48.3   23.8      0     -2      0
     [1]   48.3  178.4   21.7      0    3.9      0
     [2]   23.8   21.7   59.1      0    1.2      0
     [3]      0      0      0     16      0    0.5
     [4]     -2    3.9    1.2      0   17.6      0
     [5]      0      0      0    0.5      0   72.4

    Gypsum Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   78.6     41   26.8      0     -7      0
     [1]     41   62.7   24.2      0    3.1      0
     [2]   26.8   24.2   72.6      0  -17.4      0
     [3]      0      0      0    9.1      0   -1.6
     [4]     -7    3.1  -17.4      0   26.4      0
     [5]      0      0      0   -1.6      0   10.4

    Enstatite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  224.7   72.4   54.1      0      0      0
     [1]   72.4  177.9   52.7      0      0      0
     [2]   54.1   52.7  213.6      0      0      0
     [3]      0      0      0   77.6      0      0
     [4]      0      0      0      0   75.9      0
     [5]      0      0      0      0      0   81.6

    Forsterite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    328     69     69      0      0      0
     [1]     69    200     73      0      0      0
     [2]     69     73    235      0      0      0
     [3]      0      0      0   66.7      0      0
     [4]      0      0      0      0   81.3      0
     [5]      0      0      0      0      0   80.9

    Fayalite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    266     94     92      0      0      0
     [1]     94    168     92      0      0      0
     [2]     92     92    232      0      0      0
     [3]      0      0      0   32.3      0      0
     [4]      0      0      0      0   46.5      0
     [5]      0      0      0      0      0     57

    Montecellite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    216     59     71      0      0      0
     [1]     59    150     77      0      0      0
     [2]     71     77    184      0      0      0
     [3]      0      0      0   50.6      0      0
     [4]      0      0      0      0   56.5      0
     [5]      0      0      0      0      0   59.2

    Andalusite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  233.4   97.7  116.2      0      0      0
     [1]   97.7    289   81.4      0      0      0
     [2]  116.2   81.4  380.1      0      0      0
     [3]      0      0      0   99.5      0      0
     [4]      0      0      0      0   87.8      0
     [5]      0      0      0      0      0  112.3

    Silimanite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  287.3  158.6   83.4      0      0      0
     [1]  158.6  231.9   94.7      0      0      0
     [2]   83.4   94.7  388.4      0      0      0
     [3]      0      0      0  122.4      0      0
     [4]      0      0      0      0   80.7      0
     [5]      0      0      0      0      0   89.3

    Barite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   95.1   51.3   33.6      0      0      0
     [1]   51.3   83.7   32.8      0      0      0
     [2]   33.6   32.8  110.6      0      0      0
     [3]      0      0      0   11.8      0      0
     [4]      0      0      0      0     29      0
     [5]      0      0      0      0      0   27.7

    Anhydrite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   93.8   16.5   15.2      0      0      0
     [1]   16.5    185   31.7      0      0      0
     [2]   15.2   31.7    112      0      0      0
     [3]      0      0      0   32.5      0      0
     [4]      0      0      0      0   26.5      0
     [5]      0      0      0      0      0    9.3

    Dolomite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    205     71   57.4  -19.5   13.7      0
     [1]     71    205   57.4   19.5  -13.7      0
     [2]   57.4   57.4    113      0      0      0
     [3]  -19.5   19.5      0   39.8      0  -13.7
     [4]   13.7  -13.7      0      0   39.8  -19.5
     [5]      0      0      0  -13.7  -19.5     67

    Rutile Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    269    177    146      0      0      0
     [1]    177    269    146      0      0      0
     [2]    146    146    480      0      0      0
     [3]      0      0      0    124      0      0
     [4]      0      0      0      0    124      0
     [5]      0      0      0      0      0    192

    Zircon Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    256    175    214      0      0      0
     [1]    175    256    214      0      0      0
     [2]    214    214    372      0      0      0
     [3]      0      0      0   73.5      0      0
     [4]      0      0      0      0   73.5      0
     [5]      0      0      0      0      0    116

    Corundum Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    497    162    116  -21.9      0      0
     [1]    162    497    116   21.9      0      0
     [2]    116    116    501      0      0      0
     [3]  -21.9   21.9      0  146.8      0      0
     [4]      0      0      0      0  146.8  -21.9
     [5]      0      0      0      0  -21.9  167.5

    Calcite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    144   53.9   51.1  -20.5      0      0
     [1]   53.9    144   51.1   20.5      0      0
     [2]   51.1   51.1     84      0      0      0
     [3]  -20.5   20.5      0   33.5      0      0
     [4]      0      0      0      0   33.5  -20.5
     [5]      0      0      0      0  -20.5  45.05

    Quartz Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   86.6    6.7   12.6  -17.8      0      0
     [1]    6.7   86.6   12.6   17.8      0      0
     [2]   12.6   12.6  106.1      0      0      0
     [3]  -17.8   17.8      0   57.8      0      0
     [4]      0      0      0      0   57.8  -17.8
     [5]      0      0      0      0  -17.8  39.95

    Tourmaline Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    305    108     51     -6      0      0
     [1]    108    305     51      6      0      0
     [2]     51     51  176.4      0      0      0
     [3]     -6      6      0   64.8      0      0
     [4]      0      0      0      0   64.8     -6
     [5]      0      0      0      0     -6   98.5

    Beryl Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  304.2  123.8  114.5      0      0      0
     [1]  123.8  304.2  114.5      0      0      0
     [2]  114.5  114.5  277.6      0      0      0
     [3]      0      0      0   65.3      0      0
     [4]      0      0      0      0   65.3      0
     [5]      0      0      0      0      0   90.2

    Graphite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   1060    180     15      0      0      0
     [1]    180   1060     15      0      0      0
     [2]     15     15   36.5      0      0      0
     [3]      0      0      0    0.3      0      0
     [4]      0      0      0      0    0.3      0
     [5]      0      0      0      0      0    440

    Wusite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  245.7  149.3  149.3      0      0      0
     [1]  149.3  245.7  149.3      0      0      0
     [2]  149.3  149.3  245.7      0      0      0
     [3]      0      0      0   44.7      0      0
     [4]      0      0      0      0   44.7      0
     [5]      0      0      0      0      0   44.7

    Manganosite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    227    116    116      0      0      0
     [1]    116    227    116      0      0      0
     [2]    116    116    227      0      0      0
     [3]      0      0      0     78      0      0
     [4]      0      0      0      0     78      0
     [5]      0      0      0      0      0     78

    Periclase Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    294     93     93      0      0      0
     [1]     93    294     93      0      0      0
     [2]     93     93    294      0      0      0
     [3]      0      0      0    155      0      0
     [4]      0      0      0      0    155      0
     [5]      0      0      0      0      0    155

    Magnetite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    270    108    108      0      0      0
     [1]    108    270    108      0      0      0
     [2]    108    108    270      0      0      0
     [3]      0      0      0   98.7      0      0
     [4]      0      0      0      0   98.7      0
     [5]      0      0      0      0      0   98.7

    Chromite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    322    144    144      0      0      0
     [1]    144    322    144      0      0      0
     [2]    144    144    322      0      0      0
     [3]      0      0      0    117      0      0
     [4]      0      0      0      0    117      0
     [5]      0      0      0      0      0    117

    Spinel Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]  282.9  155.4  155.4      0      0      0
     [1]  155.4  282.9  155.4      0      0      0
     [2]  155.4  155.4  282.9      0      0      0
     [3]      0      0      0  154.8      0      0
     [4]      0      0      0      0  154.8      0
     [5]      0      0      0      0      0  154.8

    Pyrite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    361   33.6   33.6      0      0      0
     [1]   33.6    361   33.6      0      0      0
     [2]   33.6   33.6    361      0      0      0
     [3]      0      0      0  105.2      0      0
     [4]      0      0      0      0  105.2      0
     [5]      0      0      0      0      0  105.2

    Galena Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    127   24.4   24.4      0      0      0
     [1]   24.4    127   24.4      0      0      0
     [2]   24.4   24.4    127      0      0      0
     [3]      0      0      0     23      0      0
     [4]      0      0      0      0     23      0
     [5]      0      0      0      0      0     23

    Sphalerite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    102   64.6   64.6      0      0      0
     [1]   64.6    102   64.6      0      0      0
     [2]   64.6   64.6    102      0      0      0
     [3]      0      0      0   44.6      0      0
     [4]      0      0      0      0   44.6      0
     [5]      0      0      0      0      0   44.6

    Fluorite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]    165     47     47      0      0      0
     [1]     47    165     47      0      0      0
     [2]     47     47    165      0      0      0
     [3]      0      0      0   33.9      0      0
     [4]      0      0      0      0   33.9      0
     [5]      0      0      0      0      0   33.9

    Halite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   49.1   12.8   12.8      0      0      0
     [1]   12.8   49.1   12.8      0      0      0
     [2]   12.8   12.8   49.1      0      0      0
     [3]      0      0      0   12.8      0      0
     [4]      0      0      0      0   12.8      0
     [5]      0      0      0      0      0   12.8

    Sylvite Stiffness Tensor in Voigt Matrix Notation
    kl/ij   [0]    [1]    [2]    [3]    [4]    [5]
     [0]   40.5    6.9    6.9      0      0      0
     [1]    6.9   40.5    6.9      0      0      0
     [2]    6.9    6.9   40.5      0      0      0
     [3]      0      0      0   6.27      0      0
     [4]      0      0      0      0   6.27      0
     [5]      0      0      0      0      0   6.27

---
### references
* Bass, J.D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63.
* Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
* Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440
* Thomsen, Leon, 2014, Understanding seismic anisotropy in exploration and exploitation, second edition: Society of Exploration Geophysics.
