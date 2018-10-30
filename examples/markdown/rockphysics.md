# mpcexamples
mechanical properties of crystals and polycrystalline aggregates

---
### rockphysics
The rock physics namespace ...

#### rockphysics transforms
[mpcexamples::mpcRockPhysicsTransforms()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_rockphysicstransforms.cpp)
```cpp
// mineral data : quartz ==========================================
double quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
mpc::rockphysics::BulkModulusType<double> quartz_bulk_modulus_type = mpc::rockphysics::BulkModulusType<double>(quartz_bulk_modulus);
std::cout << "quartz bulk modulus type value : " << quartz_bulk_modulus_type.value << std::endl;

double quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();
mpc::rockphysics::ShearModulusType<double> quartz_shear_modulus_type = mpc::rockphysics::ShearModulusType<double>(quartz_shear_modulus);
std::cout << "quartz shear modulus type value : " << quartz_shear_modulus_type.value << std::endl;

double quartz_density = mpc::data::QuartzDensity<double>();
mpc::rockphysics::DensityType<double> quartz_density_type = mpc::rockphysics::DensityType<double>(quartz_density);
//  NOTE: the object can be created and the value extracted implicitly ...
std::cout << "quartz density type : " << mpc::rockphysics::DensityType<double>(quartz_density).value << std::endl;

/* rock physics transforms! */
mpc::rockphysics::CompressionalWaveVelocityType<double> quartz_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(quartz_bulk_modulus_type, quartz_shear_modulus_type, quartz_density_type);
std::cout << "quartz pvel type value : " << quartz_pvel_type.value << std::endl;

// option 2 : NO TYPE SAFETY!!!
double quartz_pvel = mpc::rockphysics::CompressionalWaveVelocityFromBulkModulusShearModulusDensity(quartz_bulk_modulus, quartz_shear_modulus, quartz_density);
//std::cout << "quartz pvel value : " << quartz_pvel << std::endl;

mpc::rockphysics::ShearWaveVelocityType<double> quartz_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(quartz_shear_modulus_type, quartz_density_type);
std::cout << "quartz svel value : " << quartz_svel_type.value << std::endl;


// mineral data : muscovite ====================================
double muscovite_bulk_modulus = mpc::data::MuscoviteBulkModulus<double>();
mpc::rockphysics::BulkModulusType<double> muscovite_bulk_modulus_type = mpc::rockphysics::BulkModulusType<double>(muscovite_bulk_modulus);
    std::cout << "muscovite bulk modulus type value : " << muscovite_bulk_modulus_type.value << std::endl;

double muscovite_shear_modulus = mpc::data::MuscoviteShearModulus<double>();
mpc::rockphysics::ShearModulusType<double> muscovite_shear_modulus_type = mpc::rockphysics::ShearModulusType<double>(muscovite_shear_modulus);
std::cout << "muscovite shear modulus type value : " << muscovite_shear_modulus_type.value << std::endl;

double muscovite_density = mpc::data::MuscoviteDensity<double>();
mpc::rockphysics::DensityType<double> muscovite_density_type = mpc::rockphysics::DensityType<double>(muscovite_density);
//  NOTE: the object can be created and the value extracted implicitly ...
std::cout << "muscovite density type : " << mpc::rockphysics::DensityType<double>(muscovite_density).value << std::endl;

/* rock physics transforms! */
mpc::rockphysics::CompressionalWaveVelocityType<double> muscovite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(muscovite_bulk_modulus_type, muscovite_shear_modulus_type, muscovite_density_type);
std::cout << "muscovite pvel type value : " << muscovite_pvel_type.value << std::endl;

mpc::rockphysics::ShearWaveVelocityType<double> muscovite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(muscovite_shear_modulus_type, muscovite_density_type);
std::cout << "muscovite svel value : " << quartz_svel_type.value << std::endl;



// mineral data : montecellite ======================================
double montecellite_bulk_modulus = mpc::data::MontecelliteBulkModulus<double>();
mpc::rockphysics::BulkModulusType<double> montecellite_bulk_modulus_type = mpc::rockphysics::BulkModulusType<double>(montecellite_bulk_modulus);
std::cout << "montecellite bulk modulus type value : " << montecellite_bulk_modulus_type.value << std::endl;

double montecellite_shear_modulus = mpc::data::MontecelliteShearModulus<double>();
mpc::rockphysics::ShearModulusType<double> montecellite_shear_modulus_type = mpc::rockphysics::ShearModulusType<double>(montecellite_shear_modulus);
std::cout << "montecellite shear modulus type value : " << montecellite_shear_modulus_type.value << std::endl;

double montecellite_density = mpc::data::MontecelliteDensity<double>();
mpc::rockphysics::DensityType<double> montecellite_density_type = mpc::rockphysics::DensityType<double>(montecellite_density);
//  NOTE: the object can be created and the value extracted implicitly ...
std::cout << "montecellite density type : " << mpc::rockphysics::DensityType<double>(montecellite_density).value << std::endl;

/* rock physics transforms! */
mpc::rockphysics::CompressionalWaveVelocityType<double> montecellite_pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(montecellite_bulk_modulus_type, montecellite_shear_modulus_type, montecellite_density_type);
std::cout << "montecellite pvel type value : " << montecellite_pvel_type.value << std::endl;

mpc::rockphysics::ShearWaveVelocityType<double> montecellite_svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(montecellite_shear_modulus_type, montecellite_density_type);
std::cout << "montecellite svel value : " << montecellite_svel_type.value << std::endl;
```
Output

    quartz bulk modulus type value : 37.8
    quartz shear modulus type value : 44.3
    quartz density type : 2.648
    quartz pvel type value : 6.04823
    quartz svel value : 4.09018
    muscovite bulk modulus type value : 58.2
    muscovite shear modulus type value : 35.3
    muscovite density type : 2.844
    muscovite pvel type value : 6.08388
    muscovite svel value : 4.09018
    montecellite bulk modulus type value : 106
    montecellite shear modulus type value : 55.2
    montecellite density type : 3.116
    montecellite pvel type value : 7.59197
    montecellite svel value : 4.20892

#### tensor invariants
Values that do not change under rotation of a tensor are known as invariants ... (e.g., scalars)

Bulk modulus and shear modulus are two examples of scalar values that can be extracted from the stiffness tensor and compliance tensor components ...
> see DWit R., 2008, Elastic constants and thermal expansion averages of a nontextured polycrystal: Journal of Mechanics of Materials and Structures, 3, 195-212.

[mpcexamples::mpcTensorInvariants()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_tensorinvariants.cpp)

Augite
```cpp
// Augite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration augite_symmetry_group_enum = mpc::data::AugiteSymmetryClass();
auto augite_density = mpc::data::AugiteDensity<double>();
auto augite_bulk_modulus = mpc::data::AugiteBulkModulus<double>();
auto augite_shear_modulus = mpc::data::AugiteShearModulus<double>();
mpc::core::StiffnessTensor<double> augite_stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();
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
mpc::rockphysics::MakeIsotropicStiffnessTensor(augite_bulk_modulus, augite_shear_modulus, augite_stiffness_tensor);
mpc::rockphysics::MakeIsotropicComplianceTensor(augite_bulk_modulus, augite_shear_modulus, augite_compliance_tensor_from_augite_stiffness_tensor);
```
Output

    augite bulk modulus (ref)           : 95
    augite bulk modulus (voigt)         : 101.056
    augite bulk modulus (ruess)         : 90.247
    augite bulk modulus vrh difference  : 0.651288
    augite shear modulus (ref)          : 59
    augite shear modulus (voigt)        : 60.0133
    augite shear modulus (ruess)        : 55.9459
    augite shear modulus vrh difference : 1.02039

```cpp
// Albite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration albite_symmetry_group_enum = mpc::data::AlbiteSymmetryClass();
auto albite_density = mpc::data::AlbiteDensity<double>();
auto albite_bulk_modulus = mpc::data::AlbiteBulkModulus<double>();
auto albite_shear_modulus = mpc::data::AlbiteShearModulus<double>();
mpc::core::StiffnessTensor<double> albite_stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();
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
mpc::rockphysics::MakeIsotropicStiffnessTensor(albite_bulk_modulus, albite_shear_modulus, albite_stiffness_tensor);
mpc::rockphysics::MakeIsotropicComplianceTensor(albite_bulk_modulus, albite_shear_modulus, albite_compliance_tensor_from_albite_stiffness_tensor);
```
Output

    albite bulk modulus (ref)           : 56.9
    albite bulk modulus (voigt)         : 60.7333
    albite bulk modulus (ruess)         : 53.0155
    albite bulk modulus vrh difference  : 0.0255678
    albite shear modulus (ref)          : 28.6
    albite shear modulus (voigt)        : 30.86
    albite shear modulus (ruess)        : 26.2328
    albite shear modulus vrh difference : 0.0535925

```cpp
// Anorthite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration anorthite_symmetry_group_enum = mpc::data::AnorthiteSymmetryClass();
auto anorthite_density = mpc::data::AnorthiteDensity<double>();
auto anorthite_bulk_modulus = mpc::data::AnorthiteBulkModulus<double>();
auto anorthite_shear_modulus = mpc::data::AnorthiteShearModulus<double>();
mpc::core::StiffnessTensor<double> anorthite_stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();
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
mpc::rockphysics::MakeIsotropicStiffnessTensor(anorthite_bulk_modulus, anorthite_shear_modulus, anorthite_stiffness_tensor);
mpc::rockphysics::MakeIsotropicComplianceTensor(anorthite_bulk_modulus, anorthite_shear_modulus, anorthite_compliance_tensor_from_anorthite_stiffness_tensor);
```
Output

    anorthite bulk modulus (ref)           : 84.2
    anorthite bulk modulus (voigt)         : 89
    anorthite bulk modulus (ruess)         : 79.3075
    anorthite bulk modulus vrh difference  : 0.0462339
    anorthite shear modulus (ref)          : 39.9
    anorthite shear modulus (voigt)        : 42.88
    anorthite shear modulus (ruess)        : 37.0035
    anorthite shear modulus vrh difference : 0.0417266

```cpp
// Labradorite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration labradorite_symmetry_group_enum = mpc::data::LabradoriteSymmetryClass();
auto labradorite_density = mpc::data::LabradoriteDensity<double>();
auto labradorite_bulk_modulus = mpc::data::LabradoriteBulkModulus<double>();
auto labradorite_shear_modulus = mpc::data::LabradoriteShearModulus<double>();
mpc::core::StiffnessTensor<double> labradorite_stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();
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
mpc::rockphysics::MakeIsotropicStiffnessTensor(labradorite_bulk_modulus, labradorite_shear_modulus, labradorite_stiffness_tensor);
mpc::rockphysics::MakeIsotropicComplianceTensor(labradorite_bulk_modulus, labradorite_shear_modulus, labradorite_compliance_tensor_from_labradorite_stiffness_tensor);
```
Output

    labradorite bulk modulus (ref)           : 74.5
    labradorite bulk modulus (voigt)         : 75.9778
    labradorite bulk modulus (ruess)         : 73.0566
    labradorite bulk modulus vrh difference  : 0.017185
    labradorite shear modulus (ref)          : 33.7
    labradorite shear modulus (voigt)        : 36.6067
    labradorite shear modulus (ruess)        : 30.8125
    labradorite shear modulus vrh difference : 0.00956797

```cpp
// Microcline
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration microcline_symmetry_group_enum = mpc::data::MicroclineSymmetryClass();
auto microcline_density = mpc::data::MicroclineDensity<double>();
auto microcline_bulk_modulus = mpc::data::MicroclineBulkModulus<double>();
auto microcline_shear_modulus = mpc::data::MicroclineShearModulus<double>();
mpc::core::StiffnessTensor<double> microcline_stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();
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
mpc::rockphysics::MakeIsotropicStiffnessTensor(microcline_bulk_modulus, microcline_shear_modulus, microcline_stiffness_tensor);
mpc::rockphysics::MakeIsotropicComplianceTensor(microcline_bulk_modulus, microcline_shear_modulus, microcline_compliance_tensor_from_microcline_stiffness_tensor);
```
Output

    microcline bulk modulus (ref)           : 55.4
    microcline bulk modulus (voigt)         : 59.8222
    microcline bulk modulus (ruess)         : 50.9205
    microcline bulk modulus vrh difference  : 0.0286181
    microcline shear modulus (ref)          : 28.1
    microcline shear modulus (voigt)        : 32.3533
    microcline shear modulus (ruess)        : 23.9034
    microcline shear modulus vrh difference : 0.0283745

```cpp
// Oligoclase
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration oligoclase_symmetry_group_enum = mpc::data::OligoclaseSymmetryClass();
auto oligoclase_density = mpc::data::OligoclaseDensity<double>();
auto oligoclase_bulk_modulus = mpc::data::OligoclaseBulkModulus<double>();
auto oligoclase_shear_modulus = mpc::data::OligoclaseShearModulus<double>();
mpc::core::StiffnessTensor<double> oligoclase_stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();
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
mpc::rockphysics::MakeIsotropicStiffnessTensor(oligoclase_bulk_modulus, oligoclase_shear_modulus, oligoclase_stiffness_tensor);
mpc::rockphysics::MakeIsotropicComplianceTensor(oligoclase_bulk_modulus, oligoclase_shear_modulus, oligoclase_compliance_tensor_from_oligoclase_stiffness_tensor);
```
Output

    oligoclase bulk modulus (ref)           : 62
    oligoclase bulk modulus (voigt)         : 68.3111
    oligoclase bulk modulus (ruess)         : 55.6244
    oligoclase bulk modulus vrh difference  : 0.0322383
    oligoclase shear modulus (ref)          : 29.3
    oligoclase shear modulus (voigt)        : 32.5867
    oligoclase shear modulus (ruess)        : 25.9506
    oligoclase shear modulus vrh difference : 0.0313896

```cpp
// Coesite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration coesite_symmetry_group_enum = mpc::data::CoesiteSymmetryClass();
auto coesite_density = mpc::data::CoesiteDensity<double>();
auto coesite_bulk_modulus = mpc::data::CoesiteBulkModulus<double>();
auto coesite_shear_modulus = mpc::data::CoesiteShearModulus<double>();
mpc::core::StiffnessTensor<double> coesite_stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();
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
```
Output

    coesite bulk modulus (ref)           : 113.7
    coesite bulk modulus (voigt)         : 118.222
    coesite bulk modulus (ruess)         : 109.059
    coesite bulk modulus vrh difference  : 0.0594572
    coesite shear modulus (ref)          : 61.6
    coesite shear modulus (voigt)        : 66.7933
    coesite shear modulus (ruess)        : 56.3595
    coesite shear modulus vrh difference : 0.0235787

```cpp
// Epidote
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration epidote_symmetry_group_enum = mpc::data::EpidoteSymmetryClass();
auto epidote_density = mpc::data::EpidoteDensity<double>();
auto epidote_bulk_modulus = mpc::data::EpidoteBulkModulus<double>();
auto epidote_shear_modulus = mpc::data::EpidoteShearModulus<double>();
mpc::core::StiffnessTensor<double> epidote_stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();
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
```
Output

    epidote bulk modulus (ref)           : 106.2
    epidote bulk modulus (voigt)         : 107.411
    epidote bulk modulus (ruess)         : 104.899
    epidote bulk modulus vrh difference  : 0.0451256
    epidote shear modulus (ref)          : 61.2
    epidote shear modulus (voigt)        : 64.9867
    epidote shear modulus (ruess)        : 57.4187
    epidote shear modulus vrh difference : 0.00269099

```cpp
// Hornblende
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration hornblende_symmetry_group_enum = mpc::data::HornblendeSymmetryClass();
auto hornblende_density = mpc::data::HornblendeDensity<double>();
auto hornblende_bulk_modulus = mpc::data::HornblendeBulkModulus<double>();
auto hornblende_shear_modulus = mpc::data::HornblendeShearModulus<double>();
mpc::core::StiffnessTensor<double> hornblende_stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();
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
```
Output

    hornblende bulk modulus (ref)           : 87
    hornblende bulk modulus (voigt)         : 90.1
    hornblende bulk modulus (ruess)         : 84.1703
    hornblende bulk modulus vrh difference  : 0.13517
    hornblende shear modulus (ref)          : 43
    hornblende shear modulus (voigt)        : 44.9
    hornblende shear modulus (ruess)        : 41.4087
    hornblende shear modulus vrh difference : 0.154365

```cpp
// Muscovite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration muscovite_symmetry_group_enum = mpc::data::MuscoviteSymmetryClass();
auto muscovite_density = mpc::data::MuscoviteDensity<double>();
auto muscovite_bulk_modulus = mpc::data::MuscoviteBulkModulus<double>();
auto muscovite_shear_modulus = mpc::data::MuscoviteShearModulus<double>();
mpc::core::StiffnessTensor<double> muscovite_stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();
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
```
Output

    muscovite bulk modulus (ref)           : 58.2
    muscovite bulk modulus (voigt)         : 67.7111
    muscovite bulk modulus (ruess)         : 48.7109
    muscovite bulk modulus vrh difference  : 0.0109966
    muscovite shear modulus (ref)          : 35.3
    muscovite shear modulus (voigt)        : 43.0667
    muscovite shear modulus (ruess)        : 27.5864
    muscovite shear modulus vrh difference : 0.0265437

```cpp
// Gypsum
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration gypsum_symmetry_group_enum = mpc::data::GypsumSymmetryClass();
auto gypsum_density = mpc::data::GypsumDensity<double>();
auto gypsum_bulk_modulus = mpc::data::GypsumBulkModulus<double>();
auto gypsum_shear_modulus = mpc::data::GypsumShearModulus<double>();
mpc::core::StiffnessTensor<double> gypsum_stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();
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
```
Output

    gypsum bulk modulus (ref)           : 42
    gypsum bulk modulus (voigt)         : 44.2111
    gypsum bulk modulus (ruess)         : 41.1256
    gypsum bulk modulus vrh difference  : 0.668369
    gypsum shear modulus (ref)          : 15.4
    gypsum shear modulus (voigt)        : 17.3067
    gypsum shear modulus (ruess)        : 13.0633
    gypsum shear modulus vrh difference : 0.215001

```cpp
// Enstatite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration enstatite_symmetry_group_enum = mpc::data::EnstatiteSymmetryClass();
auto enstatite_density = mpc::data::EnstatiteDensity<double>();
auto enstatite_bulk_modulus = mpc::data::EnstatiteBulkModulus<double>();
auto enstatite_shear_modulus = mpc::data::EnstatiteShearModulus<double>();
mpc::core::StiffnessTensor<double> enstatite_stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();
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
```
Output

    enstatite bulk modulus (ref)           : 107.8
    enstatite bulk modulus (voigt)         : 108.289
    enstatite bulk modulus (ruess)         : 107.285
    enstatite bulk modulus vrh difference  : 0.0133038
    enstatite shear modulus (ref)          : 75.7
    enstatite shear modulus (voigt)        : 76.1533
    enstatite shear modulus (ruess)        : 75.1821
    enstatite shear modulus vrh difference : 0.0323062

```cpp
// Forsterite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration forsterite_symmetry_group_enum = mpc::data::ForsteriteSymmetryClass();
auto forsterite_density = mpc::data::ForsteriteDensity<double>();
auto forsterite_bulk_modulus = mpc::data::ForsteriteBulkModulus<double>();
auto forsterite_shear_modulus = mpc::data::ForsteriteShearModulus<double>();
mpc::core::StiffnessTensor<double> forsterite_stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();
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
```
Output

    forsterite bulk modulus (ref)           : 129.5
    forsterite bulk modulus (voigt)         : 131.667
    forsterite bulk modulus (ruess)         : 127.273
    forsterite bulk modulus vrh difference  : 0.0301388
    forsterite shear modulus (ref)          : 81.1
    forsterite shear modulus (voigt)        : 82.58
    forsterite shear modulus (ruess)        : 79.5405
    forsterite shear modulus vrh difference : 0.0397749

```cpp
// Fayalite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration fayalite_symmetry_group_enum = mpc::data::FayaliteSymmetryClass();
auto fayalite_density = mpc::data::FayaliteDensity<double>();
auto fayalite_bulk_modulus = mpc::data::FayaliteBulkModulus<double>();
auto fayalite_shear_modulus = mpc::data::FayaliteShearModulus<double>();
mpc::core::StiffnessTensor<double> fayalite_stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();
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
```
Output

    fayalite bulk modulus (ref)           : 134
    fayalite bulk modulus (voigt)         : 135.778
    fayalite bulk modulus (ruess)         : 130.833
    fayalite bulk modulus vrh difference  : 0.694409
    fayalite shear modulus (ref)          : 50.7
    fayalite shear modulus (voigt)        : 53.0267
    fayalite shear modulus (ruess)        : 48.4129
    fayalite shear modulus vrh difference : 0.0198034

```cpp
// Montecellite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration montecellite_symmetry_group_enum = mpc::data::MontecelliteSymmetryClass();
auto montecellite_density = mpc::data::MontecelliteDensity<double>();
auto montecellite_bulk_modulus = mpc::data::MontecelliteBulkModulus<double>();
auto montecellite_shear_modulus = mpc::data::MontecelliteShearModulus<double>();
mpc::core::StiffnessTensor<double> montecellite_stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();
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
```
Output

    montecellite bulk modulus (ref)           : 106
    montecellite bulk modulus (voigt)         : 107.111
    montecellite bulk modulus (ruess)         : 105.022
    montecellite bulk modulus vrh difference  : 0.0664202
    montecellite shear modulus (ref)          : 55.2
    montecellite shear modulus (voigt)        : 56.1267
    montecellite shear modulus (ruess)        : 54.6933
    montecellite shear modulus vrh difference : 0.209998

```cpp
// Andalusite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration andalusite_symmetry_group_enum = mpc::data::AndalusiteSymmetryClass();
auto andalusite_density = mpc::data::AndalusiteDensity<double>();
auto andalusite_bulk_modulus = mpc::data::AndalusiteBulkModulus<double>();
auto andalusite_shear_modulus = mpc::data::AndalusiteShearModulus<double>();
mpc::core::StiffnessTensor<double> andalusite_stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();
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
```
Output

    andalusite bulk modulus (ref)           : 162
    andalusite bulk modulus (voigt)         : 165.9
    andalusite bulk modulus (ruess)         : 160.873
    andalusite bulk modulus vrh difference  : 1.38634
    andalusite shear modulus (ref)          : 99.1
    andalusite shear modulus (voigt)        : 100.4
    andalusite shear modulus (ruess)        : 96.384
    andalusite shear modulus vrh difference : 0.707992

```cpp
// Silimanite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration silimanite_symmetry_group_enum = mpc::data::SilimaniteSymmetryClass();
auto silimanite_density = mpc::data::SilimaniteDensity<double>();
auto silimanite_bulk_modulus = mpc::data::SilimaniteBulkModulus<double>();
auto silimanite_shear_modulus = mpc::data::SilimaniteShearModulus<double>();
mpc::core::StiffnessTensor<double> silimanite_stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();
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
```
Output

    silimanite bulk modulus (ref)           : 170.8
    silimanite bulk modulus (voigt)         : 175.667
    silimanite bulk modulus (ruess)         : 173.358
    silimanite bulk modulus vrh difference  : 3.71239
    silimanite shear modulus (ref)          : 91.5
    silimanite shear modulus (voigt)        : 96.54
    silimanite shear modulus (ruess)        : 84.1468
    silimanite shear modulus vrh difference : 1.15659

```cpp
// Barite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration barite_symmetry_group_enum = mpc::data::BariteSymmetryClass();
auto barite_density = mpc::data::BariteDensity<double>();
auto barite_bulk_modulus = mpc::data::BariteBulkModulus<double>();
auto barite_shear_modulus = mpc::data::BariteShearModulus<double>();
mpc::core::StiffnessTensor<double> barite_stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();
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
```
Output

    barite bulk modulus (ref)           : 58.2
    barite bulk modulus (voigt)         : 58.3111
    barite bulk modulus (ruess)         : 58.0794
    barite bulk modulus vrh difference  : 0.0047429
    barite shear modulus (ref)          : 23.2
    barite shear modulus (voigt)        : 25.1467
    barite shear modulus (ruess)        : 21.3276
    barite shear modulus vrh difference : 0.0371473

```cpp
// Anhydrite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration anhydrite_symmetry_group_enum = mpc::data::AnhydriteSymmetryClass();
auto anhydrite_density = mpc::data::AnhydriteDensity<double>();
auto anhydrite_bulk_modulus = mpc::data::AnhydriteBulkModulus<double>();
auto anhydrite_shear_modulus = mpc::data::AnhydriteShearModulus<double>();
mpc::core::StiffnessTensor<double> anhydrite_stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();
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
```
Output

    anhydrite bulk modulus (ref)           : 54.9
    anhydrite bulk modulus (voigt)         : 57.5111
    anhydrite bulk modulus (ruess)         : 52.2206
    anhydrite bulk modulus vrh difference  : 0.0341442
    anhydrite shear modulus (ref)          : 29.3
    anhydrite shear modulus (voigt)        : 35.4867
    anhydrite shear modulus (ruess)        : 23.1695
    anhydrite shear modulus vrh difference : 0.0280691

```cpp
// Dolomite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration dolomite_symmetry_group_enum = mpc::data::DolomiteSymmetryClass();
auto dolomite_density = mpc::data::DolomiteDensity<double>();
auto dolomite_bulk_modulus = mpc::data::DolomiteBulkModulus<double>();
auto dolomite_shear_modulus = mpc::data::DolomiteShearModulus<double>();
mpc::core::StiffnessTensor<double> dolomite_stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();
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
```
Output

    dolomite bulk modulus (ref)           : 94.9
    dolomite bulk modulus (voigt)         : 99.4
    dolomite bulk modulus (ruess)         : 90.3028
    dolomite bulk modulus vrh difference  : 0.048605
    dolomite shear modulus (ref)          : 45.7
    dolomite shear modulus (voigt)        : 51.8
    dolomite shear modulus (ruess)        : 39.6748
    dolomite shear modulus vrh difference : 0.0373919

```cpp
// Rutile
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration rutile_symmetry_group_enum = mpc::data::RutileSymmetryClass();
auto rutile_density = mpc::data::RutileDensity<double>();
auto rutile_bulk_modulus = mpc::data::RutileBulkModulus<double>();
auto rutile_shear_modulus = mpc::data::RutileShearModulus<double>();
mpc::core::StiffnessTensor<double> rutile_stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();
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
```
Output

    rutile bulk modulus (ref)           : 215.5
    rutile bulk modulus (voigt)         : 217.333
    rutile bulk modulus (ruess)         : 208.574
    rutile bulk modulus vrh difference  : 2.54623
    rutile shear modulus (ref)          : 112.4
    rutile shear modulus (voigt)        : 124.6
    rutile shear modulus (ruess)        : 98.6538
    rutile shear modulus vrh difference : 0.773115

```cpp
// Zircon
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration zircon_symmetry_group_enum = mpc::data::ZirconSymmetryClass();
auto zircon_density = mpc::data::ZirconDensity<double>();
auto zircon_bulk_modulus = mpc::data::ZirconBulkModulus<double>();
auto zircon_shear_modulus = mpc::data::ZirconShearModulus<double>();
mpc::core::StiffnessTensor<double> zircon_stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();
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
```
Output

    zircon bulk modulus (ref)           : 223.9
    zircon bulk modulus (voigt)         : 232.222
    zircon bulk modulus (ruess)         : 215.486
    zircon bulk modulus vrh difference  : 0.0459422
    zircon shear modulus (ref)          : 66.6
    zircon shear modulus (voigt)        : 71.3333
    zircon shear modulus (ruess)        : 61.8869
    zircon shear modulus vrh difference : 0.0101149

```cpp
// Corundum
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration corundum_symmetry_group_enum = mpc::data::CorundumSymmetryClass();
auto corundum_density = mpc::data::CorundumDensity<double>();
auto corundum_bulk_modulus = mpc::data::CorundumBulkModulus<double>();
auto corundum_shear_modulus = mpc::data::CorundumShearModulus<double>();
mpc::core::StiffnessTensor<double> corundum_stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();
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
```
Output

    corundum bulk modulus (ref)           : 253.5
    corundum bulk modulus (voigt)         : 253.667
    corundum bulk modulus (ruess)         : 253.339
    corundum bulk modulus vrh difference  : 0.00292398
    corundum shear modulus (ref)          : 163.2
    corundum shear modulus (voigt)        : 165.62
    corundum shear modulus (ruess)        : 160.814
    corundum shear modulus vrh difference : 0.0169498

```cpp
// Calcite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration calcite_symmetry_group_enum = mpc::data::CalciteSymmetryClass();
auto calcite_density = mpc::data::CalciteDensity<double>();
auto calcite_bulk_modulus = mpc::data::CalciteBulkModulus<double>();
auto calcite_shear_modulus = mpc::data::CalciteShearModulus<double>();
mpc::core::StiffnessTensor<double> calcite_stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();
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
```
Output

    calcite bulk modulus (ref)           : 73.3
    calcite bulk modulus (voigt)         : 76.0222
    calcite bulk modulus (ruess)         : 70.5955
    calcite bulk modulus vrh difference  : 0.00888201
    calcite shear modulus (ref)          : 32
    calcite shear modulus (voigt)        : 36.8033
    calcite shear modulus (ruess)        : 27.1329
    calcite shear modulus vrh difference : 0.0318946

```cpp
// Quartz
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration quartz_symmetry_group_enum = mpc::data::QuartzSymmetryClass();
auto quartz_density = mpc::data::QuartzDensity<double>();
auto quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
auto quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();
mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
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
```
Output

    quartz bulk modulus (ref)           : 37.8
    quartz bulk modulus (voigt)         : 38.1222
    quartz bulk modulus (ruess)         : 37.5602
    quartz bulk modulus vrh difference  : 0.041217
    quartz shear modulus (ref)          : 44.3
    quartz shear modulus (voigt)        : 47.6033
    quartz shear modulus (ruess)        : 40.9831
    quartz shear modulus vrh difference : 0.00676328

```cpp
// Tourmaline
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration tourmaline_symmetry_group_enum = mpc::data::TourmalineSymmetryClass();
auto tourmaline_density = mpc::data::TourmalineDensity<double>();
auto tourmaline_bulk_modulus = mpc::data::TourmalineBulkModulus<double>();
auto tourmaline_shear_modulus = mpc::data::TourmalineShearModulus<double>();
mpc::core::StiffnessTensor<double> tourmaline_stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();
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
```
Output

    tourmaline bulk modulus (ref)           : 127.2
    tourmaline bulk modulus (voigt)         : 134.044
    tourmaline bulk modulus (ruess)         : 120.419
    tourmaline bulk modulus vrh difference  : 0.0315494
    tourmaline shear modulus (ref)          : 81.5
    tourmaline shear modulus (voigt)        : 84.0467
    tourmaline shear modulus (ruess)        : 78.9298
    tourmaline shear modulus vrh difference : 0.0117694

```cpp
// Beryl
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration beryl_symmetry_group_enum = mpc::data::BerylSymmetryClass();
auto beryl_density = mpc::data::BerylDensity<double>();
auto beryl_bulk_modulus = mpc::data::BerylBulkModulus<double>();
auto beryl_shear_modulus = mpc::data::BerylShearModulus<double>();
mpc::core::StiffnessTensor<double> beryl_stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();
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
```
Output

    beryl bulk modulus (ref)           : 176
    beryl bulk modulus (voigt)         : 176.844
    beryl bulk modulus (ruess)         : 176.299
    beryl bulk modulus vrh difference  : 0.571784
    beryl shear modulus (ref)          : 78.8
    beryl shear modulus (voigt)        : 79.7067
    beryl shear modulus (ruess)        : 77.8084
    beryl shear modulus vrh difference : 0.042444

```cpp
// Graphite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration graphite_symmetry_group_enum = mpc::data::GraphiteSymmetryClass();
auto graphite_density = mpc::data::GraphiteDensity<double>();
auto graphite_bulk_modulus = mpc::data::GraphiteBulkModulus<double>();
auto graphite_shear_modulus = mpc::data::GraphiteShearModulus<double>();
mpc::core::StiffnessTensor<double> graphite_stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();
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
```
Output

    graphite bulk modulus (ref)           : 161
    graphite bulk modulus (voigt)         : 286.278
    graphite bulk modulus (ruess)         : 35.7622
    graphite bulk modulus vrh difference  : 0.0199743
    graphite shear modulus (ref)          : 109.3
    graphite shear modulus (voigt)        : 217.887
    graphite shear modulus (ruess)        : 0.745207
    graphite shear modulus vrh difference : 0.0159369

```cpp
// Wusite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration wusite_symmetry_group_enum = mpc::data::WusiteSymmetryClass();
auto wusite_density = mpc::data::WusiteDensity<double>();
auto wusite_bulk_modulus = mpc::data::WusiteBulkModulus<double>();
auto wusite_shear_modulus = mpc::data::WusiteShearModulus<double>();
mpc::core::StiffnessTensor<double> wusite_stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();
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
```
Output

    wusite bulk modulus (ref)           : 181.4
    wusite bulk modulus (voigt)         : 181.433
    wusite bulk modulus (ruess)         : 181.433
    wusite bulk modulus vrh difference  : 0.0333333
    wusite shear modulus (ref)          : 46.1
    wusite shear modulus (voigt)        : 46.1
    wusite shear modulus (ruess)        : 46.0372
    wusite shear modulus vrh difference : 0.0314103

```cpp
// Manganosite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration manganosite_symmetry_group_enum = mpc::data::ManganositeSymmetryClass();
auto manganosite_density = mpc::data::ManganositeDensity<double>();
auto manganosite_bulk_modulus = mpc::data::ManganositeBulkModulus<double>();
auto manganosite_shear_modulus = mpc::data::ManganositeShearModulus<double>();
mpc::core::StiffnessTensor<double> manganosite_stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();
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
```
Output

    manganosite bulk modulus (ref)           : 153
    manganosite bulk modulus (voigt)         : 153
    manganosite bulk modulus (ruess)         : 153
    manganosite bulk modulus vrh difference  : 0
    manganosite shear modulus (ref)          : 68.1
    manganosite shear modulus (voigt)        : 69
    manganosite shear modulus (ruess)        : 67.1163
    manganosite shear modulus vrh difference : 0.0418605

```cpp
// Periclase
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration periclase_symmetry_group_enum = mpc::data::PericlaseSymmetryClass();
auto periclase_density = mpc::data::PericlaseDensity<double>();
auto periclase_bulk_modulus = mpc::data::PericlaseBulkModulus<double>();
auto periclase_shear_modulus = mpc::data::PericlaseShearModulus<double>();
mpc::core::StiffnessTensor<double> periclase_stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();
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
```
Output

    periclase bulk modulus (ref)           : 160
    periclase bulk modulus (voigt)         : 160
    periclase bulk modulus (ruess)         : 160
    periclase bulk modulus vrh difference  : 2.84217e-14
    periclase shear modulus (ref)          : 130.3
    periclase shear modulus (voigt)        : 133.2
    periclase shear modulus (ruess)        : 127.371
    periclase shear modulus vrh difference : 0.0143908

```cpp
// Magnetite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration magnetite_symmetry_group_enum = mpc::data::MagnetiteSymmetryClass();
auto magnetite_density = mpc::data::MagnetiteDensity<double>();
auto magnetite_bulk_modulus = mpc::data::MagnetiteBulkModulus<double>();
auto magnetite_shear_modulus = mpc::data::MagnetiteShearModulus<double>();
mpc::core::StiffnessTensor<double> magnetite_stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();
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
```
Output

    magnetite bulk modulus (ref)           : 162
    magnetite bulk modulus (voigt)         : 162
    magnetite bulk modulus (ruess)         : 162
    magnetite bulk modulus vrh difference  : 0
    magnetite shear modulus (ref)          : 91.2
    magnetite shear modulus (voigt)        : 91.62
    magnetite shear modulus (ruess)        : 90.7663
    magnetite shear modulus vrh difference : 0.00682561

```cpp
// Chromite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration chromite_symmetry_group_enum = mpc::data::ChromiteSymmetryClass();
auto chromite_density = mpc::data::ChromiteDensity<double>();
auto chromite_bulk_modulus = mpc::data::ChromiteBulkModulus<double>();
auto chromite_shear_modulus = mpc::data::ChromiteShearModulus<double>();
mpc::core::StiffnessTensor<double> chromite_stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();
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
```
Output

    chromite bulk modulus (ref)           : 203.3
    chromite bulk modulus (voigt)         : 203.333
    chromite bulk modulus (ruess)         : 203.333
    chromite bulk modulus vrh difference  : 0.0333333
    chromite shear modulus (ref)          : 104.9
    chromite shear modulus (voigt)        : 105.8
    chromite shear modulus (ruess)        : 103.922
    chromite shear modulus vrh difference : 0.0389222

```cpp
// Spinel
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration spinel_symmetry_group_enum = mpc::data::SpinelSymmetryClass();
auto spinel_density = mpc::data::SpinelDensity<double>();
auto spinel_bulk_modulus = mpc::data::SpinelBulkModulus<double>();
auto spinel_shear_modulus = mpc::data::SpinelShearModulus<double>();
mpc::core::StiffnessTensor<double> spinel_stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();
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
```
Output

    spinel bulk modulus (ref)           : 197.9
    spinel bulk modulus (voigt)         : 197.9
    spinel bulk modulus (ruess)         : 197.9
    spinel bulk modulus vrh difference  : 2.84217e-14
    spinel shear modulus (ref)          : 108.5
    spinel shear modulus (voigt)        : 118.38
    spinel shear modulus (ruess)        : 98.5175
    spinel shear modulus vrh difference : 0.0512399

```cpp
// Pyrite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration pyrite_symmetry_group_enum = mpc::data::PyriteSymmetryClass();
auto pyrite_density = mpc::data::PyriteDensity<double>();
auto pyrite_bulk_modulus = mpc::data::PyriteBulkModulus<double>();
auto pyrite_shear_modulus = mpc::data::PyriteShearModulus<double>();
mpc::core::StiffnessTensor<double> pyrite_stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();
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
```
Output

    pyrite bulk modulus (ref)           : 142.7
    pyrite bulk modulus (voigt)         : 142.733
    pyrite bulk modulus (ruess)         : 142.733
    pyrite bulk modulus vrh difference  : 0.0333333
    pyrite shear modulus (ref)          : 125.7
    pyrite shear modulus (voigt)        : 128.6
    pyrite shear modulus (ruess)        : 122.746
    pyrite shear modulus vrh difference : 0.0270848

```cpp
// Galena
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration galena_symmetry_group_enum = mpc::data::GalenaSymmetryClass();
auto galena_density = mpc::data::GalenaDensity<double>();
auto galena_bulk_modulus = mpc::data::GalenaBulkModulus<double>();
auto galena_shear_modulus = mpc::data::GalenaShearModulus<double>();
mpc::core::StiffnessTensor<double> galena_stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();
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
```
Output

    galena bulk modulus (ref)           : 58.6
    galena bulk modulus (voigt)         : 58.6
    galena bulk modulus (ruess)         : 58.6
    galena bulk modulus vrh difference  : 7.10543e-15
    galena shear modulus (ref)          : 31.9
    galena shear modulus (voigt)        : 34.32
    galena shear modulus (ruess)        : 29.5123
    galena shear modulus vrh difference : 0.0161281

```cpp
// Sphalerite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration sphalerite_symmetry_group_enum = mpc::data::SphaleriteSymmetryClass();
auto sphalerite_density = mpc::data::SphaleriteDensity<double>();
auto sphalerite_bulk_modulus = mpc::data::SphaleriteBulkModulus<double>();
auto sphalerite_shear_modulus = mpc::data::SphaleriteShearModulus<double>();
mpc::core::StiffnessTensor<double> sphalerite_stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();
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
```
Output

    sphalerite bulk modulus (ref)           : 77.1
    sphalerite bulk modulus (voigt)         : 77.0667
    sphalerite bulk modulus (ruess)         : 77.0667
    sphalerite bulk modulus vrh difference  : 0.0333333
    sphalerite shear modulus (ref)          : 31.5
    sphalerite shear modulus (voigt)        : 34.24
    sphalerite shear modulus (ruess)        : 28.6999
    sphalerite shear modulus vrh difference : 0.0300344

```cpp
// Fluorite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration fluorite_symmetry_group_enum = mpc::data::FluoriteSymmetryClass();
auto fluorite_density = mpc::data::FluoriteDensity<double>();
auto fluorite_bulk_modulus = mpc::data::FluoriteBulkModulus<double>();
auto fluorite_shear_modulus = mpc::data::FluoriteShearModulus<double>();
mpc::core::StiffnessTensor<double> fluorite_stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();
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
```
Output

    fluorite bulk modulus (ref)           : 86.3
    fluorite bulk modulus (voigt)         : 86.3333
    fluorite bulk modulus (ruess)         : 86.3333
    fluorite bulk modulus vrh difference  : 0.0333333
    fluorite shear modulus (ref)          : 42.4
    fluorite shear modulus (voigt)        : 43.94
    fluorite shear modulus (ruess)        : 40.8517
    fluorite shear modulus vrh difference : 0.00414216

```cpp
// Halite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration halite_symmetry_group_enum = mpc::data::HaliteSymmetryClass();
auto halite_density = mpc::data::HaliteDensity<double>();
auto halite_bulk_modulus = mpc::data::HaliteBulkModulus<double>();
auto halite_shear_modulus = mpc::data::HaliteShearModulus<double>();
mpc::core::StiffnessTensor<double> halite_stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();
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
```
Output

    halite bulk modulus (ref)           : 24.9
    halite bulk modulus (voigt)         : 24.9
    halite bulk modulus (ruess)         : 24.9
    halite bulk modulus vrh difference  : 0
    halite shear modulus (ref)          : 14.7
    halite shear modulus (voigt)        : 14.94
    halite shear modulus (ruess)        : 14.5109
    halite shear modulus vrh difference : 0.0254653

```cpp
// Sylvite
std::cout << "" << std::endl;
mpc::core::SymmetryGroupEnumeration sylvite_symmetry_group_enum = mpc::data::SylviteSymmetryClass();
auto sylvite_density = mpc::data::SylviteDensity<double>();
auto sylvite_bulk_modulus = mpc::data::SylviteBulkModulus<double>();
auto sylvite_shear_modulus = mpc::data::SylviteShearModulus<double>();
mpc::core::StiffnessTensor<double> sylvite_stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();
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
```
Output

    sylvite bulk modulus (ref)           : 18.1
    sylvite bulk modulus (voigt)         : 18.1
    sylvite bulk modulus (ruess)         : 18.1
    sylvite bulk modulus vrh difference  : 0
    sylvite shear modulus (ref)          : 9.4
    sylvite shear modulus (voigt)        : 10.482
    sylvite shear modulus (ruess)        : 8.36797
    sylvite shear modulus vrh difference : 0.0249847

#### fluid phase
> see Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
[mpcexamples::mpcFluidPhase()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_fluidphase.cpp)
```cpp
double gas_K = 0.0435;  // GPa
double gas_rho = 0.1770;  // g/cm**3

double oil_K = 0.3922;  // GPa
double oil_rho = 0.6359;  // g/cm**3

double brine_K = 2.6819;  // GPa
double brine_rho = 1.0194;  // g/cm**3

auto fluid_mixture_gas_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(gas_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(gas_rho), mpc::rockphysics::VolumeFractionType<double>(0.2));

auto fluid_mixture_oil_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(oil_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(oil_rho), mpc::rockphysics::VolumeFractionType<double>(0.3));

auto fluid_mixture_brine_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(brine_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(brine_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

//auto brine_K_type = std::get<0>(fluid_mixture_brine_tuple);

std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > fluid_mixture_vec{
    fluid_mixture_gas_tuple,
    fluid_mixture_oil_tuple,
    fluid_mixture_brine_tuple
};

mpc::rockphysics::FluidPhase<double> fluid_mixture = mpc::rockphysics::FluidPhase(fluid_mixture_vec);

std::vector< mpc::rockphysics::BulkModulusType<double> > fluid_mixture_K_type_vec = fluid_mixture.BulkModulusTypeVector();
std::vector< mpc::rockphysics::ShearModulusType<double> > fluid_mixture_mu_type_vec = fluid_mixture.ShearModulusTypeVector();
std::vector< mpc::rockphysics::DensityType<double> > fluid_mixture_rho_type_vec = fluid_mixture.DensityTypeVector();
std::vector< mpc::rockphysics::VolumeFractionType<double> > fluid_mixture_vf_type_vec = fluid_mixture.VolumeFractionTypeVector();

for (int i=0; i<fluid_mixture_K_type_vec.size(); ++i) {
    std::cout << "component " << i << std::endl;
    std::cout << "fluid mixture K type : " << fluid_mixture_K_type_vec[i].value << std::endl;
    std::cout << "fluid mixture mu type : " << fluid_mixture_mu_type_vec[i].value << std::endl;
    std::cout << "fluid mixture rho type : " << fluid_mixture_rho_type_vec[i].value << std::endl;
    std::cout << "fluid mixture vf type : " << fluid_mixture_vf_type_vec[i].value << std::endl;
    std::cout << "" << std::endl;
}

mpc::rockphysics::BulkModulusType<double> fluid_mixture_effective_bulkmodulus = fluid_mixture.EffectiveBulkModulusType();
std::cout << "fluid mixture effective bulkmodulus value: " << fluid_mixture_effective_bulkmodulus.value << std::endl;
mpc::rockphysics::ShearModulusType<double> fluid_mixture_effective_shearmodulus = fluid_mixture.EffectiveShearModulusType();
std::cout << "fluid mixture effective shearmodulus value: " << fluid_mixture_effective_shearmodulus.value << std::endl;
mpc::rockphysics::DensityType<double> fluid_mixture_effective_density = fluid_mixture.EffectiveDensityType();
std::cout << "fluid mixture effective density value: " << fluid_mixture_effective_density.value << std::endl;

// change volume fraction values
std::vector<double> vf_new{0.7,0.2,0.1};
fluid_mixture.VolumeFractionTypeVector(vf_new);

std::vector< mpc::rockphysics::VolumeFractionType<double> > fluid_mixture_vf_type_vec_new = fluid_mixture.VolumeFractionTypeVector();

std::cout << "" << std::endl;
for (int i=0; i<fluid_mixture_vf_type_vec_new.size(); ++i) {
    std::cout << "component " << i << std::endl;
    //std::cout << "fluid mixture K type : " << fluid_mixture_K_type_vec[i].value << std::endl;
    //std::cout << "fluid mixture mu type : " << fluid_mixture_mu_type_vec[i].value << std::endl;
    //std::cout << "fluid mixture rho type : " << fluid_mixture_rho_type_vec[i].value << std::endl;
    std::cout << "fluid mixture vf type new : " << fluid_mixture_vf_type_vec_new[i].value << std::endl;
    std::cout << "" << std::endl;
}

mpc::rockphysics::BulkModulusType<double> fluid_mixture_effective_bulkmodulus_new = fluid_mixture.EffectiveBulkModulusType();
std::cout << "fluid mixture effective bulkmodulus value new: " << fluid_mixture_effective_bulkmodulus_new.value << std::endl;
mpc::rockphysics::ShearModulusType<double> fluid_mixture_effective_shearmodulus_new = fluid_mixture.EffectiveShearModulusType();
std::cout << "fluid mixture effective shearmodulus value new: " << fluid_mixture_effective_shearmodulus_new.value << std::endl;
mpc::rockphysics::DensityType<double> fluid_mixture_effective_density_new = fluid_mixture.EffectiveDensityType();
std::cout << "fluid mixture effective density value new: " << fluid_mixture_effective_density_new.value << std::endl;
```
Output

    component 0
    fluid mixture K type : 0.0435
    fluid mixture mu type : 0
    fluid mixture rho type : 0.177
    fluid mixture vf type : 0.2

    component 1
    fluid mixture K type : 0.3922
    fluid mixture mu type : 0
    fluid mixture rho type : 0.6359
    fluid mixture vf type : 0.3

    component 2
    fluid mixture K type : 2.6819
    fluid mixture mu type : 0
    fluid mixture rho type : 1.0194
    fluid mixture vf type : 0.5

    fluid mixture effective bulkmodulus value: 0.180211
    fluid mixture effective shearmodulus value: 0
    fluid mixture effective density value: 0.73587

    component 0
    fluid mixture vf type new : 0.7

    component 1
    fluid mixture vf type new : 0.2

    component 2
    fluid mixture vf type new : 0.1

    fluid mixture effective bulkmodulus value new: 0.0600991
    fluid mixture effective shearmodulus value new: 0
    fluid mixture effective density value new: 0.35302

#### solid phase
> see Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
[mpcexamples::mpcSolidPhase()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_solidphase.cpp)
```cpp
// mineral data
double quartz_rho = mpc::data::QuartzDensity<double>();
double quartz_K = mpc::data::QuartzBulkModulus<double>();
double quartz_mu = mpc::data::QuartzShearModulus<double>();

double muscovite_rho = mpc::data::MuscoviteDensity<double>();
double muscovite_K = mpc::data::MuscoviteBulkModulus<double>();
double muscovite_mu = mpc::data::MuscoviteShearModulus<double>();

double montecellite_rho = mpc::data::MontecelliteDensity<double>();
double montecellite_K = mpc::data::MontecelliteBulkModulus<double>();
double montecellite_mu = mpc::data::MontecelliteShearModulus<double>();

auto solid_mixture_quartz_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(quartz_K), mpc::rockphysics::ShearModulusType<double>(quartz_mu), mpc::rockphysics::DensityType<double>(quartz_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

auto solid_mixture_muscovite_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(muscovite_K), mpc::rockphysics::ShearModulusType<double>(muscovite_mu), mpc::rockphysics::DensityType<double>(muscovite_rho), mpc::rockphysics::VolumeFractionType<double>(0.3));

auto solid_mixture_montecellite_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(montecellite_K), mpc::rockphysics::ShearModulusType<double>(montecellite_mu), mpc::rockphysics::DensityType<double>(montecellite_rho), mpc::rockphysics::VolumeFractionType<double>(0.2));

//auto brine_K_type = std::get<0>(fluid_mixture_brine_tuple);

std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > solid_mixture_vec{
    solid_mixture_quartz_tuple,
    solid_mixture_muscovite_tuple,
    solid_mixture_montecellite_tuple
};

mpc::rockphysics::SolidPhase<double> solid_mixture = mpc::rockphysics::SolidPhase(solid_mixture_vec);

std::vector< mpc::rockphysics::BulkModulusType<double> > solid_mixture_K_type_vec = solid_mixture.BulkModulusTypeVector();
std::vector< mpc::rockphysics::ShearModulusType<double> > solid_mixture_mu_type_vec = solid_mixture.ShearModulusTypeVector();
std::vector< mpc::rockphysics::DensityType<double> > solid_mixture_rho_type_vec = solid_mixture.DensityTypeVector();
std::vector< mpc::rockphysics::VolumeFractionType<double> > solid_mixture_vf_type_vec = solid_mixture.VolumeFractionTypeVector();

for (int i=0; i<solid_mixture_K_type_vec.size(); ++i) {
    std::cout << "component " << i << std::endl;
    std::cout << "solid mixture K type : " << solid_mixture_K_type_vec[i].value << std::endl;
    std::cout << "solid mixture mu type : " << solid_mixture_mu_type_vec[i].value << std::endl;
    std::cout << "solid mixture rho type : " << solid_mixture_rho_type_vec[i].value << std::endl;
    std::cout << "solid mixture vf type : " << solid_mixture_vf_type_vec[i].value << std::endl;
    std::cout << "" << std::endl;
}

mpc::rockphysics::BulkModulusType<double> solid_mixture_effective_bulkmodulus = solid_mixture.EffectiveBulkModulusType();
std::cout << "solid mixture effective bulkmodulus value: " << solid_mixture_effective_bulkmodulus.value << std::endl;
mpc::rockphysics::ShearModulusType<double> solid_mixture_effective_shearmodulus = solid_mixture.EffectiveShearModulusType();
std::cout << "solid mixture effective shearmodulus value: " << solid_mixture_effective_shearmodulus.value << std::endl;
mpc::rockphysics::DensityType<double> solid_mixture_effective_density = solid_mixture.EffectiveDensityType();
std::cout << "solid mixture effective density value: " << solid_mixture_effective_density.value << std::endl;

// rock physics transforms
mpc::rockphysics::CompressionalWaveVelocityType<double> solid_mixture_pwave_velocity_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(solid_mixture_effective_bulkmodulus, solid_mixture_effective_shearmodulus, solid_mixture_effective_density);
std::cout << "solid mixture pwave velocity value : " << solid_mixture_pwave_velocity_type.value << std::endl;

mpc::rockphysics::ShearWaveVelocityType<double> solid_mixture_swave_velocity_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(solid_mixture_effective_shearmodulus, solid_mixture_effective_density);
std::cout << "solid mixture swave velocity value : " << solid_mixture_swave_velocity_type.value << std::endl;



// Upper and Lower bound member functions for solid phase
std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_upper = solid_mixture.VoigtUpperBound();
std::cout << "k upper : " << kmu_upper.first.value << std::endl;
std::cout << "mu upper : " << kmu_upper.second.value << std::endl;

std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_lower = solid_mixture.RuessLowerBound();
std::cout << "k lower : " << kmu_lower.first.value << std::endl;
std::cout << "mu lower : " << kmu_lower.second.value << std::endl;

double vrh_coefficient = 025;  // 0 - Ruess, 1 - Voigt
mpc::rockphysics::BulkModulusType<double> vrh_bulkmodulus_type = mpc::rockphysics::BulkModulusType<double>(0.5 * (kmu_upper.first.value + kmu_lower.first.value));
mpc::rockphysics::ShearModulusType<double> vrh_shearmodulus_type = mpc::rockphysics::ShearModulusType<double>(0.5 * (kmu_upper.second.value + kmu_lower.second.value));

// rock physics transforms
mpc::rockphysics::CompressionalWaveVelocityType<double> vrh_pwave_velocity_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(vrh_bulkmodulus_type, vrh_shearmodulus_type, solid_mixture_effective_density);
std::cout << "vrh pwave velocity value : " << vrh_pwave_velocity_type.value << std::endl;

mpc::rockphysics::ShearWaveVelocityType<double> vrh_swave_velocity_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(vrh_shearmodulus_type, solid_mixture_effective_density);
std::cout << "vrh swave velocity value : " << vrh_swave_velocity_type.value << std::endl;



// change volume fraction values { quartz_vf, muscovite_vf, montecellite_vf }
std::cout << "\nNew volume fractions" << std::endl;
std::vector<double> vf_new{0.7,0.2,0.1};
solid_mixture.VolumeFractionTypeVector(vf_new);

// effective values after changing the volume fraction of each mineral
solid_mixture_effective_bulkmodulus = solid_mixture.EffectiveBulkModulusType();
std::cout << "solid mixture effective bulkmodulus value: " << solid_mixture_effective_bulkmodulus.value << std::endl;
solid_mixture_effective_shearmodulus = solid_mixture.EffectiveShearModulusType();
std::cout << "solid mixture effective shearmodulus value: " << solid_mixture_effective_shearmodulus.value << std::endl;
solid_mixture_effective_density = solid_mixture.EffectiveDensityType();
std::cout << "solid mixture effective density value: " << solid_mixture_effective_density.value << std::endl;

// rock physics transforms
solid_mixture_pwave_velocity_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(solid_mixture_effective_bulkmodulus, solid_mixture_effective_shearmodulus, solid_mixture_effective_density);
std::cout << "solid mixture pwave velocity value : " << solid_mixture_pwave_velocity_type.value << std::endl;

solid_mixture_swave_velocity_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(solid_mixture_effective_shearmodulus, solid_mixture_effective_density);
std::cout << "solid mixture swave velocity value : " << solid_mixture_swave_velocity_type.value << std::endl;
```
Output

    component 0
    solid mixture K type : 37.8
    solid mixture mu type : 44.3
    solid mixture rho type : 2.648
    solid mixture vf type : 0.5

    component 1
    solid mixture K type : 58.2
    solid mixture mu type : 35.3
    solid mixture rho type : 2.844
    solid mixture vf type : 0.3

    component 2
    solid mixture K type : 106
    solid mixture mu type : 55.2
    solid mixture rho type : 3.116
    solid mixture vf type : 0.2

    solid mixture effective bulkmodulus value: 53.4483
    solid mixture effective shearmodulus value: 43.2498
    solid mixture effective density value: 2.8004
    solid mixture pwave velocity value : 6.29906
    solid mixture swave velocity value : 3.9299
    k upper : 57.56
    mu upper : 43.78
    k lower : 49.3366
    mu lower : 42.7196
    vrh pwave velocity value : 6.29906
    vrh swave velocity value : 3.9299

    New volume fractions
    solid mixture effective bulkmodulus value: 46.1856
    solid mixture effective shearmodulus value: 43.2739
    solid mixture effective density value: 2.734
    solid mixture pwave velocity value : 6.16418
    solid mixture swave velocity value : 3.97845



#### mixing laws (scalar composites)
[mpcexamples::mpcMixingLaws()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_mixinglaws.cpp)
```cpp
double PrivateCalcKSat(double K_porous_rockframe, double K_mineral_matrix, double K_fluid, double porosity) {
    //double K_porous_rockframe = 1.5 * effective_shearmodulus;  // over-simplified assumption
    double tmp_numerator = std::pow(1.0 - (K_porous_rockframe / K_mineral_matrix), 2);
    double tmp_denominator = (porosity / K_fluid) + ((1.0 - porosity) / K_mineral_matrix) - (K_porous_rockframe / std::pow(K_mineral_matrix, 2));

    return K_porous_rockframe + (tmp_numerator / tmp_denominator);
}
```
The above function calculates the saturated bulk modulus from the bulk modulus of the rock frame (a.k.a., dry frame), bulk modulus of the mineral matrix (solid material), the bulk modulus of the fluid composite, and the porosity (volume fraction of fluids in the overall solid/fluid composite).
> Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440

```cpp
// data
// ref : Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
// p. 161, 170
const double gas_K = 0.0435;  // GPa
const double gas_rho = 0.1770;  // g/cm**3
const double oil_K = 0.3922;  // GPa
const double oil_rho = 0.6359;  // g/cm**3
const double brine_K = 2.6819;  // GPa
const double brine_rho = 1.0194;  // g/cm**3

// initialize variables
double background_fluid_K = brine_K;
double background_fluid_rho = brine_rho;
double foreground_fluid_K = oil_K;
double foreground_fluid_rho = oil_rho;

double background_solid_K = mpc::data::QuartzBulkModulus<double>();
double background_solid_mu = mpc::data::QuartzShearModulus<double>();
double background_solid_rho = mpc::data::QuartzDensity<double>();
double foreground_solid_K = mpc::data::MuscoviteBulkModulus<double>();
double foreground_solid_mu = mpc::data::MuscoviteShearModulus<double>();
double foreground_solid_rho = mpc::data::MuscoviteDensity<double>();

double fluid_volume_fraction = 0.25;  // default porosity
double solid_volume_fraction = 0.75;
double hill_weighting_coefficient = 0.5;  // default (1/2)
double porosity = 0.25;


// mpc
auto background_fluid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(background_fluid_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(background_fluid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

auto foreground_fluid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(foreground_fluid_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(foreground_fluid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > fluid_mixture_vec{
    background_fluid_mixture_tuple,
    foreground_fluid_mixture_tuple
};

mpc::rockphysics::FluidPhase<double> fluidphase = mpc::rockphysics::FluidPhase(fluid_mixture_vec);

auto background_solid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(background_solid_K), mpc::rockphysics::ShearModulusType<double>(background_solid_mu), mpc::rockphysics::DensityType<double>(background_solid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

auto foreground_solid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(foreground_solid_K), mpc::rockphysics::ShearModulusType<double>(foreground_solid_mu), mpc::rockphysics::DensityType<double>(foreground_solid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));


std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > solid_mixture_vec{
    background_solid_mixture_tuple,
    foreground_solid_mixture_tuple
};

mpc::rockphysics::SolidPhase<double> solidphase = mpc::rockphysics::SolidPhase(solid_mixture_vec);

// initialize upper and lower bound pairs
std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_upper = solidphase.VoigtUpperBound();

std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_lower = solidphase.RuessLowerBound();

double solid_effective_density = 1.0;
double solid_effective_bulkmodulus = 1.0;
double solid_effective_shearmodulus = 1.0;
double fluid_effective_density = 1.0;
double fluid_effective_bulkmodulus = 1.0;
double fluid_effective_shearmodulus = 1.0;
double porous_rockframe_bulkmodulus = 1.0;
double composite_saturated_bulkmodulus = 1.0;
double composite_shearmodulus = 1.0;
double composite_density = 1.0;
double composite_pwave_velocity = 1.0;
double composite_swave_velocity = 1.0;
double composite_VpVs_ratio = 1.0;
double composite_VsVp_ratio = 1.0;
double composite_poissons_ratio = 1.0;

// fluid phase
// increasing row index corresponds to increasing BACKGROUND fluid saturation
double background_fluid_saturation = 0.2;  // the volume fraction of brine
auto vf_vec_values = std::vector<double>({ background_fluid_saturation, 1.0 - background_fluid_saturation });

fluidphase.VolumeFractionTypeVector(vf_vec_values);
fluid_effective_bulkmodulus = fluidphase.EffectiveBulkModulusType().value;
fluid_effective_shearmodulus = fluidphase.EffectiveShearModulusType().value;
fluid_effective_density = fluidphase.EffectiveDensityType().value;
std::cout << "fluid phase effective bulk modulus : " << fluid_effective_bulkmodulus << std::endl;
std::cout << "fluid phase effective shear modulus : " << fluid_effective_shearmodulus << std::endl;
std::cout << "fluid phase effective density : " << fluid_effective_density << std::endl;

// solid phase
// increasing column index corresponds to increasing BACKGROUND solid concentration
double background_solid_concentration = 0.2;  // the volume fraction of quartz
vf_vec_values = std::vector<double>({ background_solid_concentration, 1.0 - background_solid_concentration });

solidphase.VolumeFractionTypeVector(vf_vec_values);
kmu_upper = solidphase.VoigtUpperBound();
kmu_lower = solidphase.RuessLowerBound();
std::cout << "solid phase bulk modulus upper bound : " << kmu_upper.first.value << std::endl;
std::cout << "solid phase bulk modulus lower bound : " << kmu_lower.first.value << std::endl;
std::cout << "solid phase shear modulus upper bound : " << kmu_upper.second.value << std::endl;
std::cout << "solid phase shear modulus lower bound : " << kmu_lower.second.value << std::endl;

solid_effective_density = solidphase.EffectiveDensityType().value;
std::cout << "solid effective density : " << solid_effective_density << std::endl;

std::cout << "Hill weighting coefficient : " << hill_weighting_coefficient << std::endl;
solid_effective_shearmodulus = (kmu_upper.second.value * hill_weighting_coefficient) + (kmu_lower.second.value * (1-hill_weighting_coefficient));  // 0 -> Ruess lower bound; 1 -> Voigt upper bound

solid_effective_bulkmodulus = (kmu_upper.first.value * hill_weighting_coefficient) + (kmu_lower.first.value * (1-hill_weighting_coefficient));  // 0 -> Ruess lower bound; 1 -> Voigt upper bound
porous_rockframe_bulkmodulus = 1.5 * solid_effective_shearmodulus;  // oversimiplified assumption!!!!
std::cout << "porous rockframe bulk modulus : " << porous_rockframe_bulkmodulus << std::endl;
std::cout << "\n!!! NOTE: this is an oversimplification for modeling purposes !!!\n" << std::endl;
composite_saturated_bulkmodulus = PrivateCalcKSat(porous_rockframe_bulkmodulus, solid_effective_bulkmodulus, fluid_effective_bulkmodulus, fluid_volume_fraction);


composite_shearmodulus = solid_effective_shearmodulus;  // no influence from fluid
composite_density = 0.5 * (solid_effective_density + fluid_effective_density);

std::cout << "porosity" << porosity << std::endl;
std::cout << "composite bulkmodulus" << composite_saturated_bulkmodulus << std::endl;
mpc::rockphysics::BulkModulusType<double> K_type = mpc::rockphysics::BulkModulusType<double>(composite_saturated_bulkmodulus);
mpc::rockphysics::ShearModulusType<double> mu_type = mpc::rockphysics::ShearModulusType<double>(solid_effective_shearmodulus);
mpc::rockphysics::DensityType<double> rho_type = mpc::rockphysics::DensityType<double>(0.5 * (solid_effective_density + fluid_effective_density));
mpc::rockphysics::CompressionalWaveVelocityType<double> pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(K_type, mu_type, rho_type);
    composite_pwave_velocity = pvel_type.value;

mpc::rockphysics::ShearWaveVelocityType<double> svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mu_type, rho_type);
composite_swave_velocity = svel_type.value;

composite_VpVs_ratio = composite_pwave_velocity / composite_swave_velocity;
composite_VsVp_ratio = composite_swave_velocity / composite_pwave_velocity;

mpc::rockphysics::PoissonsRatioType<double> nu_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::PoissonsRatioType<double> >::Compute(K_type, mu_type);
composite_poissons_ratio = nu_type.value;


std::cout << "saturated bulk modulus : " << composite_saturated_bulkmodulus << std::endl;
std::cout << "effective shear modulus : " << composite_shearmodulus << std::endl;
std::cout << "effective density : " << composite_density << std::endl;
std::cout << "effective p-wave velocity : " << composite_pwave_velocity << std::endl;
std::cout << "effective s-wave velocity : " << composite_swave_velocity << std::endl;
std::cout << "effective Vp/Vs ratio : " << composite_VpVs_ratio << std::endl;
std::cout << "effective Vs/Vp ratio : " << composite_VsVp_ratio << std::endl;
std::cout << "effective Poisson's ratio : " << composite_poissons_ratio << std::endl;
```
Output

    fluid phase effective bulk modulus : 0.472959
    fluid phase effective shear modulus : 0
    fluid phase effective density : 0.7126
    solid phase bulk modulus upper bound : 54.12
    solid phase bulk modulus lower bound : 52.5301
    solid phase shear modulus upper bound : 37.1
    solid phase shear modulus lower bound : 36.7951
    solid effective density : 2.8048
    Hill weighting coefficient : 0.5
    porous rockframe bulk modulus : 55.4213

    !!! NOTE: this is an oversimplification for modeling purposes !!!

    porosity0.25
    composite bulkmodulus55.4242
    saturated bulk modulus : 55.4242
    effective shear modulus : 36.9475
    effective density : 1.7587
    effective p-wave velocity : 7.71528
    effective s-wave velocity : 4.5835
    effective Vp/Vs ratio : 1.68327
    effective Vs/Vp ratio : 0.59408
    effective Poisson's ratio : 0.227285

### references
* Bass, J.D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63.
* Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
* Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440
* Thomsen, Leon, 2014, Understanding seismic anisotropy in exploration and exploitation, second edition: Society of Exploration Geophysics.
