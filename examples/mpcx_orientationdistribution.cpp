#include "mpcx_orientationdistribution.hpp"

// c++
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <array>
#include <cmath>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/core/csrelationship.hpp>
#include <mpc/mechanics/greenchristoffel.hpp>
#include <mpc/transformation/eulerrotation.hpp>
#include <mpc/transformation/transformer.hpp>
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/constants.hpp>
#include <mpc/utilities/norm.hpp>
#include <mpc/utilities/arithmeticaverage.hpp>
#include <mpc/utilities/harmonicaverage.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/tensorinvariants.hpp>

void mpcexamples::mpcOrientationDistribution() {
    // orientation distribution

    std::cout << "" << std::endl;

    mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
    mpc::core::StiffnessTensor<double> average_stiffness_tensor = mpc::core::StiffnessTensor<double>();
    average_stiffness_tensor.tensor = 0.0;  // just to be sure

    const double PI = mpc::utilities::PI<double>;
    const double TWO_PI = 2.0 * PI;
    const int DIVISOR = 16;
    const double DBL_DIVISOR = double(DIVISOR);
    // Euler transformation tensor arguments
    double phi0 = 0.0;
    double phi1 = 0.0;
    double phi2 = 0.0;
    double orientation_fraction = 1.0/(std::pow(DBL_DIVISOR,3));

    mpc::transformation::EulerRotationX3X1X3<double> eulerRotation;  // function object
    mpc::transformation::Transformer<double,4> trans4_fo;  // function object
    blitz::Array<double,2> rot = eulerRotation(phi0, phi1, phi2);  // transformation tensor

    for (int i=0; i<DIVISOR; ++i) {
        phi0 = (double(i)/DBL_DIVISOR) * TWO_PI;
        for (int j=0; j<DIVISOR; ++j) {
            phi1 = (double(j)/DBL_DIVISOR) * PI;  // note the max is pi not 2*pi
            for (int k=0; k<DIVISOR; ++k) {
                phi2 = (double(k)/DBL_DIVISOR) * TWO_PI;
                rot = eulerRotation(phi0, phi1, phi2);  // transformation tensor
                blitz::Array<double,4> trans_tensor = trans4_fo(quartz_stiffness_tensor.tensor, rot);
                trans_tensor *= orientation_fraction;  // multiply each component by the volume fraction (orientation)
                average_stiffness_tensor.tensor += trans_tensor;
            }
        }
    }

    double quartz_density = mpc::data::QuartzDensity<double>();
    double quartz_bulk_modulus = mpc::data::QuartzBulkModulus<double>();
    double quartz_shear_modulus = mpc::data::QuartzShearModulus<double>();
    std::cout << "density : " << quartz_density << std::endl;
    std::cout << "K moduli : " << quartz_bulk_modulus << std::endl;
    std::cout << "mu moduli : " << quartz_shear_modulus << std::endl;

    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > average_voigt_moduli = mpc::rockphysics::GetVoigtBulkAndShearModulusFromStiffnessTensor(average_stiffness_tensor);

    mpc::rockphysics::CompressionalWaveVelocityType<double> average_voigt_vp = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(average_voigt_moduli.first), mpc::rockphysics::ShearModulusType<double>(average_voigt_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> average_voigt_vs = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(average_voigt_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "K Voigt moduli : " << average_voigt_moduli.first.value << std::endl;
    std::cout << "mu Voigt moduli : " << average_voigt_moduli.second.value << std::endl;
    std::cout << "Vp Voigt : " << average_voigt_vp.value << std::endl;
    std::cout << "Vs Voigt : " << average_voigt_vs.value << std::endl;

    mpc::core::ComplianceTensor<double> average_compliance_tensor_cs = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(average_stiffness_tensor);
    std::pair< mpc::rockphysics::BulkModulusType<double>,mpc::rockphysics::ShearModulusType<double> > average_ruess_moduli = mpc::rockphysics::GetRuessBulkAndShearModulusFromCompliance(average_compliance_tensor_cs);

    mpc::rockphysics::CompressionalWaveVelocityType<double> average_ruess_vp = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(average_ruess_moduli.first), mpc::rockphysics::ShearModulusType<double>(average_ruess_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> average_ruess_vs = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(average_ruess_moduli.second), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "K Ruess moduli : " << average_ruess_moduli.first.value << std::endl;
    std::cout << "mu Ruess moduli : " << average_ruess_moduli.second.value << std::endl;
    std::cout << "Vp Ruess : " << average_ruess_vp.value << std::endl;
    std::cout << "Vs Ruess : " << average_ruess_vs.value << std::endl;

    // VRH
    double average_vrh_K = 0.5 * (average_voigt_moduli.first.value + average_ruess_moduli.first.value);
    double average_vrh_mu = 0.5 * (average_voigt_moduli.second.value + average_ruess_moduli.second.value);

    mpc::rockphysics::CompressionalWaveVelocityType<double> average_vrh_vp = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(mpc::rockphysics::BulkModulusType<double>(average_vrh_K), mpc::rockphysics::ShearModulusType<double>(average_vrh_mu), mpc::rockphysics::DensityType<double>(quartz_density));

    mpc::rockphysics::ShearWaveVelocityType<double> average_vrh_vs = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mpc::rockphysics::ShearModulusType<double>(average_vrh_mu), mpc::rockphysics::DensityType<double>(quartz_density));

    std::cout << "K VRH moduli : " << average_vrh_K << std::endl;
    std::cout << "mu VRH moduli : " << average_vrh_mu << std::endl;
    std::cout << "Vp VRH : " << average_vrh_vp.value << std::endl;
    std::cout << "Vs VRH : " << average_vrh_vs.value << std::endl;

}
