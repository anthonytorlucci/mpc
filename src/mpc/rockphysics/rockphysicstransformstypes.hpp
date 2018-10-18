/**
 *    \file rockphysicstransformstypes.hpp
 *    \brief types corresponding to the most common physical properties in rock physics
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_ROCKPHYSICSTRANSFORMSTYPES_H
#define MPC_ROCKPHYSICSTRANSFORMSTYPES_H

// c++
#include <type_traits>
#include <string>

/**
* \namespace mpc
*/
namespace mpc {
    namespace rockphysics {

        template <typename T>
        struct AbstractScalarRockProperty {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            T value;
            std::string description;
        };

        // supported rock properties
        template <typename T>
        struct BulkModulusType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr BulkModulusType(T val) {
                assert(val > 0);
                value = val;
                description = "bulk modulus";
            }
        };

        template <typename T>
        struct ShearModulusType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr ShearModulusType(T val) {
                assert(val >= 0);
                value = val;
                description = "shear modulus";
            }
        };

        template <typename T>
        struct YoungsModulusType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr YoungsModulusType(T val) {
                value = val;
                description = "Young's modulus";
            }
        };

        template <typename T>
        struct LameParamterModulusType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr LameParamterModulusType(T val) {
                value = val;
                description = "Lame parameter modulus";
            }
        };

        template <typename T>
        struct PoissonsRatioType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr PoissonsRatioType(T val) {
                assert(val < 0.5);
                value = val;
                description = "Poisson's ratio";
            }
        };

        template <typename T>
        struct CompressionalModulusType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr CompressionalModulusType(T val) {
                assert(val>=0);
                value = val;
                description = "compressional modulus";
            }
        };

        template <typename T>
        struct CompressibilityModulusType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr CompressibilityModulusType(T val) {
                value = val;
                description = "compressibility modulus";
            }
        };

        template <typename T>
        struct DensityType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr DensityType(T val) {
                assert(val >0);
                value = val;
                description = "density";
            }
        };

        template <typename T>
        struct HydrostaticPressureType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr HydrostaticPressureType(T val) {
                value = val;
                description = "hydrostatic pressure";
            }
        };

        template <typename T>
        struct VolumetricStrainType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr VolumetricStrainType(T val) {
                value = val;
                description = "volumetric strain";
            }
        };

        template <typename T>
        struct VpVsRatioType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr VpVsRatioType(T val) {
                value = val;
                description = "Vp/Vs ratio";
            }
        };

        template <typename T>
        struct VsVpRatioType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr VsVpRatioType(T val) {
                value = val;
                description = "Vs/Vp ratio";
            }
        };

        template <typename T>
        struct CompressionalWaveVelocityType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr CompressionalWaveVelocityType(T val) {
                assert(val >=0);
                value = val;
                description = "compressional wave velocity";
            }
        };

        template <typename T>
        struct ShearWaveVelocityType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            constexpr ShearWaveVelocityType(T val) {
                assert(val >=0);
                value = val;
                description = "shear wave velocity";
            }
        };

        template <typename T>
        struct VolumeFractionType : public AbstractScalarRockProperty<T> {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            using AbstractScalarRockProperty<T>::value;
            using AbstractScalarRockProperty<T>::description;

            // NOTE: this type is more of an abstraction than a specific rock property type; could be used to represent porosity, saturation, or just volume fraction of a constituent in a scalar composite...

            constexpr VolumeFractionType(T val) {
                assert(val <=1);
                assert(val >=0);
                value = val;
                description = "volume fraction";
            }
        };




    }  // namespace rockphysics
}  // namespace mpc

#endif // MPC_ROCKPHYSICSTRANSFORMSTYPES_H
