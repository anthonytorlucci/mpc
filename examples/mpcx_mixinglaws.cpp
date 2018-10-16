#include "mpcx_mixinglaws.hpp"

// c++
#include <iostream>

// mpc
#include <mpc/utilities/arithmeticaverage.hpp>
#include <mpc/utilities/harmonicaverage.hpp>
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>

void mpcexamples::mpcMixingLaws() {
    /** mixing laws */
    std::cout << "" << std::endl;

    mpc::utilities::WeightedArithmeticAverage<double,0> weighted_arithmetic_average_dbl0; // mass balance, Voigt bounds
    mpc::utilities::WeightedHarmonicAverage<double,0> weighted_harmonic_average_dbl0; // Ruess bounds

    // mineral data
    double quartz_density = mpc::data::QuartzDensity<double>();
    double quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
    double quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();

    double muscovite_density = mpc::data::MuscoviteDensity<double>();
    double muscovite_bulk_modulus = mpc::data::MuscoviteBulkModulus<double>();
    double muscovite_shear_modulus = mpc::data::MuscoviteShearModulus<double>();

    double montecellite_density = mpc::data::MontecelliteDensity<double>();
    double montecellite_bulk_modulus = mpc::data::MontecelliteBulkModulus<double>();
    double montecellite_shear_modulus = mpc::data::MontecelliteShearModulus<double>();

    // set the data
    std::vector<double> densities{ quartz_density, muscovite_density, montecellite_density };
    std::vector<double> K_moduli{ quartz_bulk_modulus, muscovite_bulk_modulus, montecellite_bulk_modulus };
    std::vector<double> mu_moduli{ quartz_shear_modulus, muscovite_shear_modulus, montecellite_shear_modulus };
    std::vector<double> volume_fractions{ 0.5, 0.3, 0.2 }; // must sum to one!!!

    std::cout << "\ndensities" << std::endl;
    for (auto dens : densities) {
        std::cout << dens << std::endl;
    }
    std::cout << "\nbulk moduli" << std::endl;
    for (auto K_mod : K_moduli) {
        std::cout << K_mod << std::endl;
    }
    std::cout << "\nshear moduli" << std::endl;
    for (auto mu_mod : mu_moduli) {
        std::cout << mu_mod << std::endl;
    }


    double mean_rho = weighted_arithmetic_average_dbl0(densities, volume_fractions); // mass balance equation
    double upper_K = weighted_arithmetic_average_dbl0(K_moduli, volume_fractions);
    double upper_mu = weighted_arithmetic_average_dbl0(mu_moduli, volume_fractions);
    double lower_K = weighted_harmonic_average_dbl0(K_moduli, volume_fractions);
    double lower_mu = weighted_harmonic_average_dbl0(mu_moduli, volume_fractions);

    std::cout << "\nmean density" << std::endl;
    std::cout << mean_rho << std::endl;

    std::cout << "\nVoigt upper bound bulk modulus" << std::endl;
    std::cout << upper_K << std::endl;

    std::cout << "\nVoigt upper bound shear modulus" << std::endl;
    std::cout << upper_mu << std::endl;

    std::cout << "\nRuess lower bound bulk modulus" << std::endl;
    std::cout << lower_K << std::endl;

    std::cout << "\nRuess lower bound shear modulus" << std::endl;
    std::cout << lower_mu << std::endl;

    // simple rock physics transforms
//    double upper_vp = mpc::utilities::PvelFromBulkModulusShearModulusDensity<double>(upper_K, upper_mu, mean_rho);
//    double upper_vs = mpc::utilities::SvelFromShearModulusDensity<double>(upper_mu, mean_rho);
//    double lower_vp = mpc::utilities::PvelFromBulkModulusShearModulusDensity<double>(lower_K, lower_mu, mean_rho);
//    double lower_vs = mpc::utilities::SvelFromShearModulusDensity<double>(lower_mu, mean_rho);
//
//    std::cout << "\nVoigt upper bound p-wave velocity" << std::endl;
//    std::cout << upper_vp << std::endl;
//
//    std::cout << "\nVoigt upper bound s-wave velocity" << std::endl;
//    std::cout << upper_vs << std::endl;
//
//    std::cout << "\nRuess lower bound p-wave velocity" << std::endl;
//    std::cout << lower_vp << std::endl;
//
//    std::cout << "\nRuess lower bound s-wave velocity" << std::endl;
//    std::cout << lower_vs << std::endl;

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


