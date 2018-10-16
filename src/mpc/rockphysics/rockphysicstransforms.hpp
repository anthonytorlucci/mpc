/**
 *    \file rockphysicstransforms.hpp
 *    \brief function object and corresponding functions to convert or transform elastic moduli and related rock properties
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_ROCKPHYSICSTRANSFORMS_H
#define MPC_ROCKPHYSICSTRANSFORMS_H

// c++
#include <type_traits>
#include <cmath>

// mpc
#include "mpc/rockphysics/rockphysicstransformstypes.hpp"

/**
* \namespace mpc
*/
namespace mpc {
    namespace rockphysics {

        template <typename T, typename U>
        struct RockPhysicsTransforms {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            static_assert(std::is_base_of<mpc::rockphysics::AbstractScalarRockProperty<T>,U>::value, "U must be derived from mpc::rockphysics::AbstractScalarRockProperty.");

            // U is the return type
            static U Compute() { return U( T() ); };
        };

        // specializations => NOTE: type U is the return type
        //// BulkModulusType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::BulkModulusType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            /* NOTE: (Mavko et al, 2009, Rock Physics Handbook, 2nd edition, Cambridge University Press)
             * The bulk modulus, K, is defined as the ratio of the hydrostatic stress, sigma_0, to the volumetric strain, epsilon_kk:
             *     sigma_0 = (1/3) * sigma_kk = K * epsilon_kk ...TODO
             *
             * The bulk modulus is the reciprocal of the compressibility, beta, which is widely used to describe the volumetric compliance of a liquid, solid, or gas:
             *     beta = 1/K
             */


            // fn() BulkModulusFromLameParameterShearModulus TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = lambda_type.value + (T(2.0/3.0) * mu_type.value);
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromYoungsModulusShearModulus TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = (E_type.value * mu_type.value) / (3.0 * (3.0 * mu_type.value - E_type.value));
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromLameParameterPoissonsRatio TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = lambda_type.value * ((1.0 + nu_type.value) / (3.0 * nu_type.value));
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromShearModulusPoissonsRatio TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = mu_type.value * ((2.0 * (1.0 + nu_type.value)) / (3.0 * (1.0 - 2.0 * nu_type.value)));
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromYoungsModulusPoissonsRatio TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = E_type.value / (3.0 * (1.0 - 2.0 * nu_type.value));
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromCompressionalModulusShearModulus TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::CompressionalModulusType<T>& M_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = M_type.value - ((4.0 / 3.0) * mu_type.value);
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromCompressibilityModulus TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::CompressibilityModulusType<T>& beta_type) {

                T v = 1 / beta_type.value;  // reciprocal of compressibility (!!! NOT LAME PARAMETER !!!)
                return BulkModulusType<T>(v);
            }

            // fn() BulkModulusFromHydrostaticPressureVolumetricStrain TODO
            static BulkModulusType<T> Compute(const mpc::rockphysics::HydrostaticPressureType<T>& sigma_0_type, const mpc::rockphysics::VolumetricStrainType<T>& epsilon_kk) {

                T v = sigma_0_type.value / epsilon_kk.value;
                return BulkModulusType<T>(v);
            }
        };

        //// ShearModulusType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::ShearModulusType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            /*
             * NOTE: (Mavko et al, 2009, Rock Physics Handbook, 2nd edition, Cambridge University Press)
             * The shear modulus, mu, is defined as the ratio of the shear stress to the shear strain:
             *     sigma_ij = 2 * mu * epsilon_ij
             */

            // fn() ShearModulusFromBulkModulusLameParameter
            static ShearModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::LameParamterModulusType<T>& lambda_type) {

                T v = (3.0/2.0) * (K_type.value - lambda_type.value);
                return ShearModulusType<T>(v);
            }

            // fn() ShearModulusFromBulkModulusYoungsModulus
            static ShearModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::YoungsModulusType<T>& E_type) {

                T v = (3.0 * K_type.value * E_type.value) / (9.0 * K_type.value - E_type.value);
                return ShearModulusType<T>(v);
            }

            // fn() ShearModulusFromLameParameterPoissonsRatio
            static ShearModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = lambda_type.value * ((1.0 - 2.0 * nu_type.value) / (2.0 * nu_type.value));
                return ShearModulusType<T>(v);
            }

            // fn() ShearModulusFromBulkModulusPoissonsRatio
            static ShearModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = (3.0 * K_type.value) * ((1.0 - 2.0 * nu_type.value) / (2.0 + 2.0 * nu_type.value));
                return ShearModulusType<T>(v);
            }

            // fn() ShearModulusFromYoungsModulusPoissonsRatio
            static ShearModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = E_type.value / (2.0 + 2.0 * nu_type.value);
                return ShearModulusType<T>(v);
            }
        };

        //// YoungsModulusType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::YoungsModulusType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            /*
             * NOTE: (Mavko et al, 2009, Rock Physics Handbook, 2nd edition, Cambridge University Press)
             * Young's modulus, E, is defined as the ratio of the extensional stress to the extensional strain in a uniaxial stress state:
             *     sigma_33 = E * epsilon_33,
             *         sigma_11 = sigma_22 = sigma_12 = sigma_13 = sigma_23 = 0
             */

            // fn() YoungsModulusFromLameParameterShearModulus
            static YoungsModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = mu_type.value * ((3.0 * lambda_type.value + 2.0 * mu_type.value) / (lambda_type.value + mu_type.value));
                return YoungsModulusType<T>(v);
            }

            // fn() YoungsModulusFromBulkModulusLameParameter
            static YoungsModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::LameParamterModulusType<T>& lambda_type) {

                T v = 9.0 * K_type.value * ((K_type.value - lambda_type.value) / (3.0 * K_type.value - lambda_type.value));
                return YoungsModulusType<T>(v);
            }

            // fn() YoungsModulusFromBulkModulusShearModulus
            static YoungsModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = (9.0 * K_type.value * mu_type.value) / (3.0 * K_type.value + mu_type.value);
                return YoungsModulusType<T>(v);
            }

            // fn() YoungsModulusFromLameParameterPoissonsRatio
            static YoungsModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = (lambda_type.value / nu_type.value) * ((1.0 + nu_type.value) * (1.0 - 2.0 *  nu_type.value));
                return YoungsModulusType<T>(v);
            }

            // fn() YoungsModulusFromShearModulusPoissonsRatio
            static YoungsModulusType<T> Compute(const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = 2.0 * mu_type.value * (1.0 + nu_type.value);
                return YoungsModulusType<T>(v);
            }

            // fn() YoungsModulusFromBulkModulusPoissonsRatio
            static YoungsModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = 3.0 * K_type.value * (1.0 - 2.0 *  nu_type.value);
                return YoungsModulusType<T>(v);
            }
        };

        //// LameParameterModulusType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::LameParamterModulusType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() LameParameterFromBulkModulusShearModulus
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = K_type.value - ((2.0/3.0) * mu_type.value);
                return LameParamterModulusType<T>(v);
            }

            // fn() LameParameterFromYoungsModulusShearModulus
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = mu_type.value * ((E_type.value - 2.0 * mu_type.value) / (3.0 * mu_type.value - E_type.value));
                return LameParamterModulusType<T>(v);
            }

            // fn() LameParameterFromBulkModulusYoungsModulus
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::YoungsModulusType<T>& E_type) {

                T v = 3.0 * K_type.value * ((3.0 * K_type.value - E_type.value) / (9.0 * K_type.value - E_type.value));
                return LameParamterModulusType<T>(v);
            }

            // fn() LameParameterFromShearModulusPoissonsRatio
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = mu_type.value * ((2.0 * nu_type.value) / (1.0 - 2.0 * nu_type.value));
                return LameParamterModulusType<T>(v);
            }

            // fn() LameParameterFromBulkModulusPoissonsRatio
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = 3.0 * K_type.value * (nu_type.value / (1.0 + nu_type.value));
                return LameParamterModulusType<T>(v);
            }

            // fn() LameParameterFromYoungsModulusPoissonsRatio
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = (E_type.value * nu_type.value) / ((1.0 + nu_type.value) * (1.0 - 2.0 * nu_type.value));
                return LameParamterModulusType<T>(v);
            }

            // fn() LameParameterFromCompressionalModulusShearModulus
            static LameParamterModulusType<T> Compute(const mpc::rockphysics::CompressionalModulusType<T>& M_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = M_type.value * (2.0 * mu_type.value);
                return LameParamterModulusType<T>(v);
            }
        };

        //// PoissonsRatioType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::PoissonsRatioType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            /*
             * NOTE: (Mavko et al, 2009, Rock Physics Handbook, 2nd edition, Cambridge University Press)
             * Poisson's ratio, which is defined as minus the ratio of the lateral strain to the axial strian in a uniaxial stress state:
             *     nu = -(epsilon_11 / epsilon_33),
             *         sigma_11 = sigma_22 = sigma_12 = sigma_13 = sigma_23 = 0
             */

            // fn() PoissonsRatioFromLameParameterShearModulus
            static mpc::rockphysics::PoissonsRatioType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = 0.5 * lambda_type.value / (lambda_type.value + mu_type.value);
                return mpc::rockphysics::PoissonsRatioType<T>(v);
            }

            // fn() PoissonsRatioFromBulkModulusLameParameter
            static mpc::rockphysics::PoissonsRatioType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::LameParamterModulusType<T>& lambda_type) {

                T v = lambda_type.value / (3.0 * K_type.value - lambda_type.value);
                return mpc::rockphysics::PoissonsRatioType<T>(v);
            }

            // fn() PoissonsRatioFromBulkModulusShearModulus
            static mpc::rockphysics::PoissonsRatioType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = (3.0 * K_type.value - 2.0 * mu_type.value) / (2.0 * (3.0 * K_type.value + mu_type.value));
                return mpc::rockphysics::PoissonsRatioType<T>(v);
            }

            // fn() PoissonsRatioFromYoungsModulusShearModulus
            static mpc::rockphysics::PoissonsRatioType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = (E_type.value / (2.0 * mu_type.value)) - 1.0;
                return mpc::rockphysics::PoissonsRatioType<T>(v);
            }

            // fn() PoissonsRatioFromBulkModulusYoungsModulus
            static mpc::rockphysics::PoissonsRatioType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::YoungsModulusType<T>& E_type) {

                T v = (3.0 * K_type.value - E_type.value) / (6.0 * K_type.value);
                return mpc::rockphysics::PoissonsRatioType<T>(v);
            }

            // fn() PoissonsRatioFromCompressionalModulusShearModulus
            static mpc::rockphysics::PoissonsRatioType<T> Compute(const mpc::rockphysics::CompressionalModulusType<T>& M_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = (M_type.value - 2.0 * mu_type.value) / (2.0 * (M_type.value - mu_type.value));
                return mpc::rockphysics::PoissonsRatioType<T>(v);
            }
        };

        //// CompressionalModulusType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::CompressionalModulusType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            /*
             * NOTE: (Mavko et al, 2009, Rock Physics Handbook, 2nd edition, Cambridge University Press)
             * P-wave modulus, M = rho * Vp**2, defined as the ratio of the axial stress to the axial strian in a uniaxial strain state:
             *     sigma_33 = M * epsilion_33,
             *         epsilon_11 = epsilon_22 = epsilon_12 = epsilon_13 = epsilon_23 = 0
             */

            // fn() CompressionalModulusFromDensityCompressionalWaveVelocity
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::DensityType<T>& rho_type, const mpc::rockphysics::CompressionalWaveVelocityType<T>& pvel_type) {

                T v = rho_type.value * std::pow(pvel_type.value);
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromLameParameterShearModulus
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = lambda_type.value + 2.0 * mu_type.value;
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromBulkModulusLameParameter
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::LameParamterModulusType<T>& lambda_type) {

                T v = 3.0 * K_type.value - 2.0 * lambda_type.value;
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromBulkModulusShearModulus
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = K_type.value + ((4.0/3.0) * mu_type.value);
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromYoungsModulusShearModulus
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::ShearModulusType<T>& mu_type) {

                T v = mu_type.value * ((4.0 * mu_type.value - E_type.value) / (3.0 * mu_type.value - E_type.value));
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromBulkModulusYoungsModulus
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::YoungsModulusType<T>& E_type) {

                T v = 3.0 * K_type.value * ((3.0 * K_type.value + E_type.value) / (9.0 * K_type.value - E_type.value));
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromLameParameterPoissonsRatio
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = lambda_type.value * ((1.0 - nu_type.value) / (nu_type.value));
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromShearModulusPoissonsRatio
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = mu_type.value * ((2.0 - 2.0 * nu_type.value) / (1.0 - 2.0 * nu_type.value));
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromBulkModulusPoissonsRatio
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = 3.0 * K_type.value * ((1.0 - nu_type.value) / (1.0 + nu_type.value));
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }

            // fn() CompressionalModulusFromYoungsModulusPoissonsRatio
            static mpc::rockphysics::CompressionalModulusType<T> Compute(const mpc::rockphysics::YoungsModulusType<T>& E_type, const mpc::rockphysics::PoissonsRatioType<T>& nu_type) {

                T v = (E_type.value * (1.0 - nu_type.value)) / ((1.0 + nu_type.value) * (1.0 - 2.0 * nu_type.value));
                return mpc::rockphysics::CompressionalModulusType<T>(v);
            }
        };

        //// CompressibilityModulusType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::CompressibilityModulusType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() CompressibilityFromBulkModulus
            static mpc::rockphysics::CompressibilityModulusType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type) {

                T v = 1 / K_type.value;
                return mpc::rockphysics::CompressibilityModulusType<T>(v);
            }
        };

        //// HydrostaticPressureType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::HydrostaticPressureType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() HydrostaticPressureFromBulkModulusVolumetricStrain TODO
            static HydrostaticPressureType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::VolumetricStrainType<T>& epsilon_kk) {

                T v = K_type.value * epsilon_kk.value;
                return HydrostaticPressureType<T>(v);
            }
        };

        //// VolumetricStrainType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::VolumetricStrainType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() VolumetricStrainFromHydrostaticPressureBulkModulus
            static mpc::rockphysics::VolumetricStrainType<T> Compute(const mpc::rockphysics::HydrostaticPressureType<T>& sigma_0_type, const mpc::rockphysics::BulkModulusType<T>& K_type) {

                T v = sigma_0_type.value / K_type.value;
                return mpc::rockphysics::VolumetricStrainType<T>(v);
            }
        };

        //// VpVsRatioType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::VpVsRatioType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() VpVsFromCompressionalWaveVelocityShearWaveVelocity
            static mpc::rockphysics::VpVsRatioType<T> Compute(const mpc::rockphysics::CompressionalWaveVelocityType<T>& pvel_type, const mpc::rockphysics::ShearWaveVelocityType<T>& svel_type) {

                T v = pvel_type.value / svel_type.value;
                return mpc::rockphysics::VpVsRatioType<T>(v);
            }
        };

        //// VsVpRatioType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::VsVpRatioType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() VsVpFromCompressionalWaveVelocityShearWaveVelocity
            static mpc::rockphysics::VsVpRatioType<T> Compute(const mpc::rockphysics::CompressionalWaveVelocityType<T>& pvel_type, const mpc::rockphysics::ShearWaveVelocityType<T>& svel_type) {

                T v = svel_type.value / pvel_type.value;
                return mpc::rockphysics::VsVpRatioType<T>(v);
            }
        };

        //// CompressionalWaveVelocityType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::CompressionalWaveVelocityType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // fn() CompressionalWaveVelocityFromBulkModulusShearModulusDensity(...)
            static CompressionalWaveVelocityType<T> Compute(const mpc::rockphysics::BulkModulusType<T>& K_type, const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::DensityType<T>& rho_type) {

                T v = sqrt((K_type.value + ((4.0/3.0) * mu_type.value)) / rho_type.value);
                return CompressionalWaveVelocityType<T>(v);
            }

            // fn() CompressionalWaveVelocityFromLameParameterShearModulusDensity(...)
            static CompressionalWaveVelocityType<T> Compute(const mpc::rockphysics::LameParamterModulusType<T>& lambda_type, const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::DensityType<T>& rho_type) {

                T v = sqrt((lambda_type.value + (2.0 * mu_type.value)) / rho_type.value);
                return CompressionalWaveVelocityType<T>(v);
            }

            // fn() CompressionalWaveVelocityFromCompressionalModulusDensity(...)
            static CompressionalWaveVelocityType<T> Compute(const mpc::rockphysics::CompressionalModulusType<T>& M_type, const mpc::rockphysics::DensityType<T>& rho_type) {

                T v = sqrt(M_type.value / rho_type.value);
                return CompressionalWaveVelocityType<T>(v);
            }
        };

        //// ShearWaveVelocityType
        template <typename T>
        struct RockPhysicsTransforms< T, mpc::rockphysics::ShearWaveVelocityType<T> > {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            // ShearWaveVelocityFromShearModulusDensity(...)
            static ShearWaveVelocityType<T> Compute(const mpc::rockphysics::ShearModulusType<T>& mu_type, const mpc::rockphysics::DensityType<T>& rho_type) {

                T v = sqrt(mu_type.value / rho_type.value);
                return ShearWaveVelocityType<T>(v);
            }
        };

        // =============================================================================================================
        // convenience functions -> NO TYPE SAFETY!!!
        //// BulkModulusType
        template <typename T>
        static inline T BulkModulusFromLameParameterShearModulus(T lame, T mu) {
            /**
             *  \fn P-wave velocity from bulk modulus, shear modulus, and density
             *  \param lame: lame parameter modulus
             *  \param mu: shear modulus
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::LameParamterModulusType<T>(lame), mpc::rockphysics::ShearModulusType<T>(mu)).value;
        }


        template <typename T>
        static inline T BulkModulusFromYoungsModulusShearModulus(T E, T mu) {
            /**
             *  \fn P-wave velocity from bulk modulus, shear modulus, and density
             *  \param E: Young's modulus
             *  \param mu: shear modulus
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::YoungsModulusType<T>(E), mpc::rockphysics::ShearModulusType<T>(mu)).value;
        }


        template <typename T>
        static inline T BulkModulusFromLameParameterPoissonsRatio(T lame, T nu) {
            /**
             *  \fn P-wave velocity from bulk modulus, shear modulus, and density
             *  \param lame: Lame parameter modulus
             *  \param nu: Poisson's ratio
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::LameParamterModulusType<T>(lame), mpc::rockphysics::PoissonsRatioType<T>(nu)).value;
        }


        template <typename T>
        static inline T BulkModulusFromShearModulusPoissonsRatio(T mu, T nu) {
            /**
             *  \fn P-wave velocity from bulk modulus, shear modulus, and density
             *  \param mu: shear modulus
             *  \param nu: Poisson's ratio
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::ShearModulusType<T>(mu), mpc::rockphysics::PoissonsRatioType<T>(nu)).value;
        }


        template <typename T>
        static inline T BulkModulusFromYoungsModulusPoissonsRatio(T E, T nu) {
            /**
             *  \fn P-wave velocity from bulk modulus, shear modulus, and density
             *  \param E: Lame parameter modulus
             *  \param nu: Poisson's ratio
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::YoungsModulusType<T>(E), mpc::rockphysics::PoissonsRatioType<T>(nu)).value;
        }

        // fn() BulkModulusFromCompressionalModulusShearModulus TODO
        template <typename T>
        static inline T BulkModulusFromCompressionalModulusShearModulus(T M, T mu) {
            /**
             *  \fn P-wave velocity from compressional modulus and shear modulus
             *  \param M: compressional modulus
             *  \param mu: shear modulus
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::CompressionalModulusType<T>(M), mpc::rockphysics::ShearModulusType<T>(mu)).value;
        }

        // fn() BulkModulusFromCompressibilityModulus TODO
        template <typename T>
        static inline T BulkModulusFromCompressibilityModulus(T beta) {
            /**
             *  \fn P-wave velocity from compressibility
             *  \param beta: compressibility
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::CompressibilityModulusType<T>(beta)).value;
        }

        // fn() BulkModulusFromHydrostaticPressureVolumetricStrain TODO
        template <typename T>
        static inline T BulkModulusFromHydrostaticPressureVolumetricStrain(T sigma_0, T epsilon_kk) {
            /**
             *  \fn bulk modulus from hydrostatic pressure and volumetric strain
             *  \param sigma_0: hydrostatic pressure
             *  \param epsilon_kk: volumetric strain
             *  \return: bulk modulus
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::BulkModulusType<T> >::Compute(mpc::rockphysics::HydrostaticPressureType<T>(sigma_0), mpc::rockphysics::VolumetricStrainType<T>(epsilon_kk)).value;
        }


        //// ShearModulusType
        // fn() ShearModulusFromBulkModulusLameParameter

        // fn() ShearModulusFromBulkModulusYoungsModulus

        // fn() ShearModulusFromLameParameterPoissonsRatio

        // fn() ShearModulusFromBulkModulusPoissonsRatio

        // fn() ShearModulusFromYoungsModulusPoissonsRatio

        //// YoungsModulusType
        // fn() YoungsModulusFromLameParameterShearModulus

        // fn() YoungsModulusFromBulkModulusLameParameter

        // fn() YoungsModulusFromBulkModulusShearModulus

        // fn() YoungsModulusFromLameParameterPoissonsRatio

        // fn() YoungsModulusFromShearModulusPoissonsRatio

        // fn() YoungsModulusFromBulkModulusPoissonsRatio

        //// LameParameterModulusType
        // fn() LameParameterFromBulkModulusShearModulus

        // fn() LameParameterFromYoungsModulusShearModulus

        // fn() LameParameterFromBulkModulusYoungsModulus

        // fn() LameParameterFromShearModulusPoissonsRatio

        // fn() LameParameterFromBulkModulusPoissonsRatio

        // fn() LameParameterFromYoungsModulusPoissonsRatio

        // fn() LameParameterFromCompressionalModulusShearModulus


        //// PoissonsRatioType
        // fn() PoissonsRatioFromLameParameterShearModulus

        // fn() PoissonsRatioFromBulkModulusLameParameter

        // fn() PoissonsRatioFromBulkModulusShearModulus

        // fn() PoissonsRatioFromYoungsModulusShearModulus

        // fn() PoissonsRatioFromBulkModulusYoungsModulus

        // fn() PoissonsRatioFromCompressionalModulusShearModulus


        //// CompressionalModulusType
        // fn() CompressionalModulusFromDensityCompressionalWaveVelocity

        // fn() CompressionalModulusFromLameParameterShearModulus

        // fn() CompressionalModulusFromBulkModulusLameParameter

        // fn() CompressionalModulusFromBulkModulusShearModulus

        // fn() CompressionalModulusFromYoungsModulusShearModulus

        // fn() CompressionalModulusFromBulkModulusYoungsModulus

        // fn() CompressionalModulusFromLameParameterPoissonsRatio

        // fn() CompressionalModulusFromShearModulusPoissonsRatio

        // fn() CompressionalModulusFromBulkModulusPoissonsRatio

        // fn() CompressionalModulusFromYoungsModulusPoissonsRatio

        //// CompressibilityModulusType
        // fn() CompressibilityFromBulkModulus


        //// HydrostaticPressureType
        // fn() HydrostaticPressureFromBulkModulusVolumetricStrain


        //// VolumetricStrainType
        // fn() VolumetricStrainFromHydrostaticPressureBulkModulus


        //// VpVsRatioType
        // fn() VpVsFromCompressionalWaveVelocityShearWaveVelocity


        //// VsVpRatioType
        // fn() VsVpFromCompressionalWaveVelocityShearWaveVelocity


        //// CompressionalWaveVelocityType
        template <typename T>
        static inline T CompressionalWaveVelocityFromBulkModulusShearModulusDensity(T K, T mu, T rho) {
            /**
             *  \fn P-wave velocity from bulk modulus, shear modulus, and density
             *  \param K: bulk modulus
             *  \param mu: shear modulus
             *  \param rho: density
             *  \return: p-wave velocity
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            // assert rho !=0; DivideByZero Exception?
            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::CompressionalWaveVelocityType<T> >::Compute(mpc::rockphysics::BulkModulusType<T>(K), mpc::rockphysics::ShearModulusType<T>(mu), mpc::rockphysics::DensityType<T>(rho)).value;
        }

        template <typename T>
        static inline T CompressionalWaveVelocityFromLameParameterShearModulusDensity(T lame, T mu, T rho) {
            /**
             *  \fn P-wave velocity from lame parameter modulus, shear modulus, and density
             *  \param lame: lame parameter modulus
             *  \param mu: shear modulus
             *  \param rho: density
             *  \return: p-wave velocity
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            // assert rho !=0; DivideByZero Exception?
            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::CompressionalWaveVelocityType<T> >::Compute(mpc::rockphysics::LameParamterModulusType<T>(lame), mpc::rockphysics::ShearModulusType<T>(mu), mpc::rockphysics::DensityType<T>(rho)).value;
        }

        // fn() CompressionalWaveVelocityFromCompressionalModulusDensity(...)
        template <typename T>
        static inline T CompressionalWaveVelocityFromCompressionalModulusDensity(T M, T rho) {
            /**
             *  \fn P-wave velocity from compressional modulus, and density
             *  \param M: compressional modulus, a.k.a P-wave modulus
             *  \param rho: density
             *  \return: p-wave velocity
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            // assert rho !=0; DivideByZero Exception?
            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::CompressionalWaveVelocityType<T> >::Compute(mpc::rockphysics::CompressionalModulusType<T>(M), mpc::rockphysics::DensityType<T>(rho)).value;
        }


        //// ShearWaveVelocityType
        template <typename T>
        static inline T ShearWaveVelocityFromShearModulusDensity(T mu, T rho) {
            /**
             *  \fn S-wave velocity from shear modulus and density
             *  \param mu: shear modulus
             *  \param rho: density
             *  \return: s-wave velocity
             */
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            return mpc::rockphysics::RockPhysicsTransforms<T,mpc::rockphysics::ShearWaveVelocityType<T> >::Compute(mpc::rockphysics::ShearModulusType<T>(mu), mpc::rockphysics::DensityType<T>(rho)).value;
        }

    }  // namespace rockphysics
}  // namespace mpc

#endif // MPC_ROCKPHYSICSTRANSFORMS_H
