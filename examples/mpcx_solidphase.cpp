#include "mpcx_solidphase.hpp"

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

void mpcexamples::mpcSolidPhase() {
    /** solid phase */
    std::cout << "" << std::endl;

    // solid phase =====================================================================================================
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

}


