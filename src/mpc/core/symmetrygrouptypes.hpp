/**
 *    @file symmetrygrouptypes.hpp
 *    @brief classes that describe the different symmetry groups supported
 * by mpc as types used for template specializations
 *
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_SYMMETRYENUMERATION_H
#define MPC_SYMMETRYENUMERATION_H

// c++ standard
#include <set>
#include <iostream>
#include <type_traits>

// blitz++
#include <blitz/array.h>

// mpc
#include "tensorcomponent.hpp"

namespace mpc {
namespace core {
// symmetry classes
enum class SymmetryGroupEnumeration {
        NONE,
        TRICLINIC,
        MONOCLINIC_X2,
        MONOCLINIC_X3,
        ORTHORHOMBIC,
        HEXAGONAL,
        TETRAGONAL7,
        TETRAGONAL6,
        TRIGONAL7,
        TRIGONAL6,
        CUBIC,
        ISOTROPIC
};

struct SymmetryGroupEnumerationInterface {

//    SYMMETRY symmetry;

        static std::string ToStr(SymmetryGroupEnumeration symmetry_enum) {
                switch (symmetry_enum) {
                case SymmetryGroupEnumeration::TRICLINIC:
                        return "triclinic";
                case SymmetryGroupEnumeration::MONOCLINIC_X2:
                        return "monoclinic_x2";
                case SymmetryGroupEnumeration::MONOCLINIC_X3:
                        return "monoclinic_x3";
                case SymmetryGroupEnumeration::ORTHORHOMBIC:
                        return "orthorhombic";
                case SymmetryGroupEnumeration::HEXAGONAL:
                        return "hexagonal";
                case SymmetryGroupEnumeration::TETRAGONAL7:
                        return "tetragonal_7";
                case SymmetryGroupEnumeration::TETRAGONAL6:
                        return "tetragonal_6";
                case SymmetryGroupEnumeration::TRIGONAL7:
                        return "trigonal_7";
                case SymmetryGroupEnumeration::TRIGONAL6:
                        return "trigonal_6";
                case SymmetryGroupEnumeration::CUBIC:
                        return "cubic";
                case SymmetryGroupEnumeration::ISOTROPIC:
                        return "isotropic";
                case SymmetryGroupEnumeration::NONE:
                        return "none";
//        default:
//            return "unknown";
                }

                return std::string();
        }
};

inline std::ostream& operator<<(std::ostream& os, SymmetryGroupEnumeration symmetry_enum) {
        os << SymmetryGroupEnumerationInterface::ToStr(symmetry_enum);
        return os;
}

// SymmetryEnumerationTypes => type_traits??
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::NONE> symmetry_none_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::TRICLINIC> symmetry_triclinic_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::MONOCLINIC_X2> symmetry_monoclinicX2_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::MONOCLINIC_X3> symmetry_monoclinicX3_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::ORTHORHOMBIC> symmetry_orthorhombic_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::HEXAGONAL> symmetry_hexagonal_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::TETRAGONAL7> symmetry_tetragonal7_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::TETRAGONAL6> symmetry_tetragonal6_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::TRIGONAL7> symmetry_trigonal7_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::TRIGONAL6> symmetry_trigonal6_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::CUBIC> symmetry_cubic_t;
typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::ISOTROPIC> symmetry_isotropic_t;

//==============================================================================

struct SymmetryGroupBase {};
// each of the following types can be verified to have SymmetryGroupBase as the base object for tempalte specialization; in other words, HasSymmetryGroupBase is a trait and T requires HasSymmetryGroupBase is a concept
struct NoneSymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::NONE;
        const int number_of_independent_components= 81;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::NONE;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 81;
        }
};

struct TriclinicSymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::TRICLINIC;
        const int number_of_independent_components= 21;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::TRICLINIC;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 21;
        }
};

struct MonoclinicX2SymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::MONOCLINIC_X2;
        const int number_of_independent_components= 13;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::MONOCLINIC_X2;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 13;
        }
};

struct MonoclinicX3SymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::MONOCLINIC_X3;
        const int number_of_independent_components= 13;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::MONOCLINIC_X3;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 13;
        }
};

struct OrthorhombicSymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::ORTHORHOMBIC;
        const int number_of_independent_components= 9;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::ORTHORHOMBIC;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 9;
        }
};

struct HexagonalSymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::HEXAGONAL;
        const int number_of_independent_components= 5;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::HEXAGONAL;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 5;
        }
};

struct Tetragonal7SymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::TETRAGONAL7;
        const int number_of_independent_components= 7;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::TETRAGONAL7;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 7;
        }
};

struct Tetragonal6SymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::TETRAGONAL6;
        const int number_of_independent_components= 6;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::TETRAGONAL6;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 6;
        }
};

struct Trigonal7SymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::TRIGONAL7;
        const int number_of_independent_components= 7;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::TRIGONAL7;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 7;
        }
};

struct Trigonal6SymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::TRIGONAL6;
        const int number_of_independent_components= 6;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::TRIGONAL6;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 6;
        }
};

struct CubicSymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::CUBIC;
        const int number_of_independent_components= 3;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::CUBIC;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 3;
        }
};

struct IsotropicSymmetryGroupType : public SymmetryGroupBase {
        const SymmetryGroupEnumeration symmetry_group_enumeration = SymmetryGroupEnumeration::ISOTROPIC;
        const int number_of_independent_components= 2;

        constexpr static inline SymmetryGroupEnumeration SymmetryGroupEnum() {
                return SymmetryGroupEnumeration::ISOTROPIC;
        }
        constexpr static inline int NumberOfIndependentComponents() {
                return 2;
        }
};


//Veldhuizen, Todd, Using C++ Template Metaprograms in Lippman, Stanley B., 1996, C++ Gems: SIGS Books.
// Template Metaprogram Version for switch

template <SymmetryGroupEnumeration Sym>
struct SymmetryGroupType {};

// specializations
template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::NONE> {
        using type = NoneSymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::TRICLINIC> {
        using type = TriclinicSymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::MONOCLINIC_X2> {
        using type = MonoclinicX2SymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::MONOCLINIC_X3> {
        using type = MonoclinicX3SymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::ORTHORHOMBIC> {
        using type = OrthorhombicSymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::HEXAGONAL> {
        using type = HexagonalSymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::TETRAGONAL7> {
        using type = Tetragonal7SymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::TETRAGONAL6> {
        using type = Tetragonal6SymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::TRIGONAL7> {
        using type = Trigonal7SymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::TRIGONAL6> {
        using type = Trigonal6SymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::CUBIC> {
        using type = CubicSymmetryGroupType;
};

template <>
struct SymmetryGroupType<SymmetryGroupEnumeration::ISOTROPIC> {
        using type = IsotropicSymmetryGroupType;
};


}  // namespace core
}  // namespace mpc

#endif //MPC_SYMMETRYENUMERATION_H
