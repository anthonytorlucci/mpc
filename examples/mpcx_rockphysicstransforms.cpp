#include "mpcx_rockphysicstransforms.hpp"

// c++
#include <iostream>

// mpc
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
//#include <mpc/utilities/rptransforms.hpp>

void mpcexamples::mpcRockPhysicsTransforms() {
    /** rock physics transforms */
    std::cout << "" << std::endl;

    // mineral data : quartz
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
    std::cout << "quartz pvel type value: " << quartz_pvel_type.value << std::endl;

    // option 2 : NO TYPE SAFETY!!!
    double quartz_pvel = mpc::rockphysics::CompressionalWaveVelocityFromBulkModulusShearModulusDensity(quartz_bulk_modulus, quartz_shear_modulus, quartz_density);
    std::cout << "quartz pvel value: " << quartz_pvel << std::endl;



    double muscovite_density = mpc::data::MuscoviteDensity<double>();
    double muscovite_bulk_modulus = mpc::data::MuscoviteBulkModulus<double>();
    double muscovite_shear_modulus = mpc::data::MuscoviteShearModulus<double>();

    double montecellite_density = mpc::data::MontecelliteDensity<double>();
    double montecellite_bulk_modulus = mpc::data::MontecelliteBulkModulus<double>();
    double montecellite_shear_modulus = mpc::data::MontecelliteShearModulus<double>();




    // =================================================================================================================
    // data
    // ref : Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
    // p. 161, 170
    const double sand_K = 16.334;     // (GPa)
    const double sand_mu = 6.604;     // (GPa)
    const double sand_rho = 2.24;     // (g/cm**3)
//    mpc::core::KMuRho<double> sand_kmurho = mpc::core::KMuRho<double>(sand_K, sand_mu, sand_rho);
//    std::cout << "sand bulk modulus: " << sand_kmurho.BulkModulus() << std::endl;
//    std::cout << "sand shear modulus: " << sand_kmurho.ShearModulus() << std::endl;
//    std::cout << "sand density: " << sand_kmurho.Density() << std::endl;
//    double sand_pvel = sand_kmurho.PWaveVelocity();  // km/s
//    std::cout << "sand p wave velocity: " << sand_pvel << std::endl;
//    double sand_svel = sand_kmurho.SWaveVelocity();  // km/s
//    std::cout << "sand s wave velocity: " << sand_svel << std::endl;
//    double sand_pr = sand_kmurho.PoissonsRatio();  // dimensionless
//    std::cout << "sand poissons ratio: " << sand_pr << std::endl;

    std::cout << "" << std::endl;
    const double mudrock_K = 15.144;  // (GPa)
    const double mudrock_mu = 4.064;  // (GPa)
    const double mudrock_rho = 2.45;  // (g/cm**3)
//    mpc::core::KMuRho<double> mudrock_kmurho = mpc::core::KMuRho<double>(mudrock_K, mudrock_mu, mudrock_rho);
//    std::cout << "mudrock bulk modulus: " << mudrock_kmurho.BulkModulus() << std::endl;
//    std::cout << "mudrock shear modulus: " << mudrock_kmurho.ShearModulus() << std::endl;
//    std::cout << "mudrock density: " << mudrock_kmurho.Density() << std::endl;
//    double mudrock_pvel = mudrock_kmurho.PWaveVelocity();
//    std::cout << "mudrock p wave velocity: " << mudrock_pvel << std::endl;
//    double mudrock_svel = mudrock_kmurho.SWaveVelocity();
//    std::cout << "mudrock s wave velocity: " << mudrock_svel << std::endl;
//    double mudrock_pr = mudrock_kmurho.PoissonsRatio();
//    std::cout << "mudrock poissons ratio: " << mudrock_pr << std::endl;

    double gas_K = 0.0435;  // GPa
    double gas_rho = 0.1770;  // g/cm**3
//    mpc::core::KMuRho<double> gas_kmurho = mpc::core::KMuRho<double>(gas_K, 0.0, gas_rho);
//    std::cout << "gas bulk modulus: " << gas_kmurho.BulkModulus() << std::endl;
//    std::cout << "gas shear modulus: " << gas_kmurho.ShearModulus() << std::endl;
//    std::cout << "gas density: " << gas_kmurho.Density() << std::endl;
//    double gas_pvel = gas_kmurho.PWaveVelocity();
//    std::cout << "gas p wave velocity: " << gas_pvel << std::endl;
//    double gas_svel = gas_kmurho.SWaveVelocity();
//    std::cout << "gas s wave velocity: " << gas_svel << std::endl;


    double oil_K = 0.3922;  // GPa
    double oil_rho = 0.6359;  // g/cm**3
//    mpc::core::KMuRho<double> oil_kmurho = mpc::core::KMuRho<double>(oil_K, 0.0, oil_rho);
//    std::cout << "oil bulk modulus: " << oil_kmurho.BulkModulus() << std::endl;
//    std::cout << "oil shear modulus: " << oil_kmurho.ShearModulus() << std::endl;
//    std::cout << "oil density: " << oil_kmurho.Density() << std::endl;
//    double oil_pvel = oil_kmurho.PWaveVelocity();
//    std::cout << "oil p wave velocity: " << oil_pvel << std::endl;
//    double oil_svel = oil_kmurho.SWaveVelocity();
//    std::cout << "oil s wave velocity: " << oil_svel << std::endl;

    double brine_K = 2.6819;  // GPa
    double brine_rho = 1.0194;  // g/cm**3
//    mpc::core::KMuRho<double> brine_kmurho = mpc::core::KMuRho<double>(brine_K, 0.0, brine_rho);
//    std::cout << "brine bulk modulus: " << brine_kmurho.BulkModulus() << std::endl;
//    std::cout << "brine shear modulus: " << brine_kmurho.ShearModulus() << std::endl;
//    std::cout << "brine density: " << brine_kmurho.Density() << std::endl;
//    double brine_pvel = brine_kmurho.PWaveVelocity();
//    std::cout << "brine p wave velocity: " << brine_pvel << std::endl;
//    double brine_svel = brine_kmurho.SWaveVelocity();
//    std::cout << "brine s wave velocity: " << brine_svel << std::endl;


}


