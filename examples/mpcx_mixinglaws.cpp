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

double PrivateCalcKSat(double K_porous_rockframe, double K_mineral_matrix, double K_fluid, double porosity);

void mpcexamples::mpcMixingLaws() {
    /** mixing laws */
    std::cout << "" << std::endl;

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


    // TODO: change Hill weighting coefficient and redo analysis


}

double PrivateCalcKSat(double K_porous_rockframe, double K_mineral_matrix, double K_fluid, double porosity) {
    // (Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440)

    //double K_porous_rockframe = 1.5 * effective_shearmodulus;  // over-simplified assumption
    double tmp_numerator = std::pow(1.0 - (K_porous_rockframe / K_mineral_matrix), 2);
    double tmp_denominator = (porosity / K_fluid) + ((1.0 - porosity) / K_mineral_matrix) - (K_porous_rockframe / std::pow(K_mineral_matrix, 2));

    return K_porous_rockframe + (tmp_numerator / tmp_denominator);
}


