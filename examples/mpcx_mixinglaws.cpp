#include "mpcx_mixinglaws.hpp"

// c++
#include <iostream>
#include <vector>
#include <tuple>

// mpc
//#include <mpc/utilities/arithmeticaverage.hpp>
//#include <mpc/utilities/harmonicaverage.hpp>
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>

void mpcexamples::mpcMixingLaws() {
    /** mixing laws */
    std::cout << "" << std::endl;

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


    // solid phase
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

    // TODO: change volume fraction values

    // Upper and Lower bound member functions for solid phase
    std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_upper = solid_mixture.VoigtUpperBound();
    std::cout << "k upper : " << kmu_upper.first.value << std::endl;
    std::cout << "mu upper : " << kmu_upper.second.value << std::endl;

    std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_lower = solid_mixture.RuessLowerBound();
    std::cout << "k lower : " << kmu_lower.first.value << std::endl;
    std::cout << "mu lower : " << kmu_lower.second.value << std::endl;

    // TODO: rock physics transforms




    // data
    // ref : Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
    // p. 161, 170
//    const double sand_K = 16.334;     // (GPa)
//    const double sand_mu = 6.604;     // (GPa)
//    const double sand_rho = 2.24;     // (g/cm**3)
//
//
//    const double mudrock_K = 15.144;  // (GPa)
//    const double mudrock_mu = 4.064;  // (GPa)
//    const double mudrock_rho = 2.45;  // (g/cm**3)



}


