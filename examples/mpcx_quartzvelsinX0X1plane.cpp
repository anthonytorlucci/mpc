#include "mpcx_quartzvelsinX0X1plane.hpp"

// c++
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/core/csrelationship.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/tensorinvariants.hpp>
#include <mpc/mechanics/greenchristoffel.hpp>
#include <mpc/transformation/eulerrotation.hpp>
#include <mpc/transformation/transformer.hpp>
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/constants.hpp>
#include <mpc/utilities/norm.hpp>
#include <mpc/utilities/arithmeticaverage.hpp>
#include <mpc/utilities/harmonicaverage.hpp>


void mpcexamples::mpcQuartzVelsInX0X1Plane() {
    std::cout << "" << std::endl;

    double quartz_density = mpc::data::QuartzDensity<double>();
    double quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
    double quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();
    std::cout << "density : " << quartz_density << std::endl;
    std::cout << "K moduli : " << quartz_bulk_modulus << std::endl;
    std::cout << "mu moduli : " << quartz_shear_modulus << std::endl;

    mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > quartz_voigt_moduli = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(quartz_stiffness_tensor);

    mpc::rockphysics::CompressionalWaveVelocityType<double> quartz_voigt_vp = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(quartz_voigt_moduli.first), mpc::rockphysics::ShearModulusType<double>(quartz_voigt_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> quartz_voigt_vs = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(quartz_voigt_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "K Voigt moduli : " << quartz_voigt_moduli.first.value << std::endl;
    std::cout << "mu Voigt moduli : " << quartz_voigt_moduli.second.value << std::endl;
    std::cout << "Vp Voigt : " << quartz_voigt_vp.value << std::endl;
    std::cout << "Vs Voigt : " << quartz_voigt_vs.value << std::endl;

    mpc::core::ComplianceTensor<double> quartz_compliance_tensor_cs = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(quartz_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > quartz_ruess_moduli = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(quartz_compliance_tensor_cs);

    mpc::rockphysics::CompressionalWaveVelocityType<double> quartz_ruess_vp = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(quartz_ruess_moduli.first), mpc::rockphysics::ShearModulusType<double>(quartz_ruess_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> quartz_ruess_vs = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(quartz_ruess_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "K Ruess moduli : " << quartz_ruess_moduli.first.value << std::endl;
    std::cout << "mu Ruess moduli : " << quartz_ruess_moduli.second.value << std::endl;
    std::cout << "Vp Ruess : " << quartz_ruess_vp.value << std::endl;
    std::cout << "Vs Ruess : " << quartz_ruess_vs.value << std::endl;

    // VRH
    double quartz_vrh_K = 0.5 * (quartz_voigt_moduli.first.value + quartz_ruess_moduli.first.value);
    double quartz_vrh_mu = 0.5 * (quartz_voigt_moduli.second.value + quartz_ruess_moduli.second.value);

    mpc::rockphysics::CompressionalWaveVelocityType<double> quartz_vrh_vp = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(quartz_vrh_K), mpc::rockphysics::ShearModulusType<double>(quartz_vrh_mu), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> quartz_vrh_vs = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(quartz_vrh_mu), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "K VRH moduli : " << quartz_vrh_K << std::endl;
    std::cout << "mu VRH moduli : " << quartz_vrh_mu << std::endl;
    std::cout << "Vp VRH : " << quartz_vrh_vp.value << std::endl;
    std::cout << "Vs VRH : " << quartz_vrh_vs.value << std::endl;

    // vels as a function of angle in x0-x1 plane (rotate about x2)
    blitz::Array<double,1> normal_vector = blitz::Array<double,1>(3);
    normal_vector = 1, 0, 0;

    const double PI = mpc::utilities::PI<double>;
    const double TWO_PI = 2.0 * PI;
    const int DIVISOR = 16;
    const double DBL_DIVISOR = double(DIVISOR);
    // Euler transformation tensor arguments
    double phi0 = 0.0;
    double phi1 = 0.0;
    double phi2 = 0.0;

    mpc::transformation::EulerRotationX3X1X3<double> eulerRotation;  // function object
    mpc::transformation::Transformer<double,1> trans_fo;  // function object
    blitz::Array<double,2> rot = eulerRotation(phi0, phi1, phi2);  // transformation tensor

    mpc::mechanics::GreenChristoffel<double> greenchristoffel = mpc::mechanics::GreenChristoffel<double>();  // function object

    for (int i=0; i<DIVISOR; ++i) {
        phi0 = (i/DBL_DIVISOR) * TWO_PI;
        std::cout << "phi : " << phi0 << std::endl;
        rot = eulerRotation(phi0, phi1, phi2);
        //std::cout << "rot : " << rot << std::endl;
        blitz::Array<double,1> rotated_normal_vector = trans_fo(normal_vector, rot);
        mpc::utilities::Normalize(rotated_normal_vector);  // new normal
        //
        greenchristoffel.SetComponents(quartz_stiffness_tensor, rotated_normal_vector);
        std::array<double,3> phase_velocities = greenchristoffel.PhaseVelocities(quartz_density);
        std::cout << "phase velocity [0] : " << phase_velocities[0] << std::endl;
        std::cout << "phase velocity [1] : " << phase_velocities[1] << std::endl;
        std::cout << "phase velocity [2] : " << phase_velocities[2] << std::endl;
        std::cout << "" << std::endl;
    }

}
