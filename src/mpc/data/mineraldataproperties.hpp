/**
*    @file mineraldataproperties.hpp
*    @brief functions that return mineral data property values from
* the literature
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MINERALDATAPROPERTIES_H
#define MINERALDATAPROPERTIES_H

#include "../core/symmetrygrouptypes.hpp"

namespace mpc {
namespace data {

// Augite
static inline mpc::core::SymmetryGroupEnumeration AugiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T AugiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(3.32); }

template <typename T>
static inline T AugiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(181.6); }

template<typename T>
static inline T AugiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(73.4); }

template<typename T>
static inline T AugiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(72.4); }

template<typename T>
static inline T AugiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(19.9); }

template<typename T>
static inline T AugiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(150.7); }

template<typename T>
static inline T AugiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(33.9); }

template<typename T>
static inline T AugiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(16.6); }

template<typename T>
static inline T AugiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(217.8); }

template<typename T>
static inline T AugiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(24.6); }

template<typename T>
static inline T AugiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(69.7); }

template<typename T>
static inline T AugiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(4.3); }

template<typename T>
static inline T AugiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(51.1); }

template<typename T>
static inline T AugiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(0.0); }

template<typename T>
static inline T AugiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(55.8); }

template<typename T>
static inline T AugiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(95.0); }

template<typename T>
static inline T AugiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return static_cast<T>(59.0); }

static inline std::string AugiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Albite
static inline mpc::core::SymmetryGroupEnumeration AlbiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T AlbiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 74.0; }

template<typename T>
static inline T AlbiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 36.4; }

template<typename T>
static inline T AlbiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 39.4; }

template<typename T>
static inline T AlbiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -6.6; }

template<typename T>
static inline T AlbiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 131.0; }

template<typename T>
static inline T AlbiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 31.0; }

template<typename T>
static inline T AlbiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -12.8; }

template<typename T>
static inline T AlbiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 128.0; }

template<typename T>
static inline T AlbiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -20.0; }

template<typename T>
static inline T AlbiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 17.3; }

template<typename T>
static inline T AlbiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -2.5; }

template<typename T>
static inline T AlbiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 29.6; }

template<typename T>
static inline T AlbiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AlbiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 32; }

template<typename T>
static inline T AlbiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 56.9; }

template<typename T>
static inline T AlbiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 28.6; }

static inline std::string AlbiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Anorthite
static inline mpc::core::SymmetryGroupEnumeration AnorthiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T AnorthiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 124.0; }

template<typename T>
static inline T AnorthiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 66.0; }

template<typename T>
static inline T AnorthiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 50.0; }

template<typename T>
static inline T AnorthiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -19.0; }

template<typename T>
static inline T AnorthiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 205.0; }

template<typename T>
static inline T AnorthiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 42.0; }

template<typename T>
static inline T AnorthiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -7.0; }

template<typename T>
static inline T AnorthiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 156.0; }

template<typename T>
static inline T AnorthiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -18.0; }

template<typename T>
static inline T AnorthiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.5; }

template<typename T>
static inline T AnorthiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -1.0; }

template<typename T>
static inline T AnorthiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 40.4; }

template<typename T>
static inline T AnorthiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnorthiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 41.5; }

template<typename T>
static inline T AnorthiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 84.2; }

template<typename T>
static inline T AnorthiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 39.9; }

static inline std::string AnorthiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Labradorite
static inline mpc::core::SymmetryGroupEnumeration LabradoriteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T LabradoriteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 99.4; }

template<typename T>
static inline T LabradoriteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 62.8; }

template<typename T>
static inline T LabradoriteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 48.7; }

template<typename T>
static inline T LabradoriteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -2.5; }

template<typename T>
static inline T LabradoriteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 158.0; }

template<typename T>
static inline T LabradoriteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 26.7; }

template<typename T>
static inline T LabradoriteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -10.7; }

template<typename T>
static inline T LabradoriteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 150.0; }

template<typename T>
static inline T LabradoriteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -12.4; }

template<typename T>
static inline T LabradoriteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 21.7; }

template<typename T>
static inline T LabradoriteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -5.4; }

template<typename T>
static inline T LabradoriteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 34.5; }

template<typename T>
static inline T LabradoriteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T LabradoriteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 37.1; }

template<typename T>
static inline T LabradoriteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 74.5; }

template<typename T>
static inline T LabradoriteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.7; }

static inline std::string LabradoriteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Microcline
static inline mpc::core::SymmetryGroupEnumeration MicroclineSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T MicroclineDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 67.0; }

template<typename T>
static inline T MicroclineC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 45.3; }

template<typename T>
static inline T MicroclineC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 26.5; }

template<typename T>
static inline T MicroclineC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -0.2; }

template<typename T>
static inline T MicroclineC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 169.0; }

template<typename T>
static inline T MicroclineC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 20.4; }

template<typename T>
static inline T MicroclineC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -12.3; }

template<typename T>
static inline T MicroclineC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 118.0; }

template<typename T>
static inline T MicroclineC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -15.0; }

template<typename T>
static inline T MicroclineC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 14.3; }

template<typename T>
static inline T MicroclineC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -1.9; }

template<typename T>
static inline T MicroclineC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.8; }

template<typename T>
static inline T MicroclineC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MicroclineC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 36.4; }

template<typename T>
static inline T MicroclineBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 55.4; }

template<typename T>
static inline T MicroclineShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 28.1; }

static inline std::string MicroclineReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Oligoclase
static inline mpc::core::SymmetryGroupEnumeration OligoclaseSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T OligoclaseDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 80.8; }

template<typename T>
static inline T OligoclaseC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 37.9; }

template<typename T>
static inline T OligoclaseC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 52.9; }

template<typename T>
static inline T OligoclaseC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -15.7; }

template<typename T>
static inline T OligoclaseC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 163.0; }

template<typename T>
static inline T OligoclaseC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 32.7; }

template<typename T>
static inline T OligoclaseC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -23.7; }

template<typename T>
static inline T OligoclaseC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 124.0; }

template<typename T>
static inline T OligoclaseC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -6.0; }

template<typename T>
static inline T OligoclaseC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 18.7; }

template<typename T>
static inline T OligoclaseC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -0.9; }

template<typename T>
static inline T OligoclaseC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 27.1; }

template<typename T>
static inline T OligoclaseC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T OligoclaseC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 35.7; }

template<typename T>
static inline T OligoclaseBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 62.0; }

template<typename T>
static inline T OligoclaseShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 29.3; }

static inline std::string OligoclaseReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Coesite
static inline mpc::core::SymmetryGroupEnumeration CoesiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T CoesiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.911; }

template<typename T>
static inline T CoesiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 160.8; }

template<typename T>
static inline T CoesiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 82.1; }

template<typename T>
static inline T CoesiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 102.9; }

template<typename T>
static inline T CoesiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -36.2; }

template<typename T>
static inline T CoesiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 230.4; }

template<typename T>
static inline T CoesiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 35.6; }

template<typename T>
static inline T CoesiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.6; }

template<typename T>
static inline T CoesiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 231.6; }

template<typename T>
static inline T CoesiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -39.3; }

template<typename T>
static inline T CoesiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 67.8; }

template<typename T>
static inline T CoesiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 9.9; }

template<typename T>
static inline T CoesiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 73.3; }

template<typename T>
static inline T CoesiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CoesiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 58.8; }

template<typename T>
static inline T CoesiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 113.7; }

template<typename T>
static inline T CoesiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 61.6; }

static inline std::string CoesiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Epidote
static inline mpc::core::SymmetryGroupEnumeration EpidoteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T EpidoteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.4; }

template<typename T>
static inline T EpidoteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 211.8; }

template<typename T>
static inline T EpidoteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 66.3; }

template<typename T>
static inline T EpidoteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 45.2; }

template<typename T>
static inline T EpidoteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 238.7; }

template<typename T>
static inline T EpidoteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 45.6; }

template<typename T>
static inline T EpidoteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -8.2; }

template<typename T>
static inline T EpidoteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 202.0; }

template<typename T>
static inline T EpidoteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -14.3; }

template<typename T>
static inline T EpidoteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 39.1; }

template<typename T>
static inline T EpidoteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -3.4; }

template<typename T>
static inline T EpidoteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 43.2; }

template<typename T>
static inline T EpidoteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EpidoteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 77.5; }

template<typename T>
static inline T EpidoteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 106.2; }

template<typename T>
static inline T EpidoteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 61.2; }

static inline std::string EpidoteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Hornblende
static inline mpc::core::SymmetryGroupEnumeration HornblendeSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T HornblendeDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.12; }

template<typename T>
static inline T HornblendeC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T HornblendeC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.9; }

template<typename T>
static inline T HornblendeC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 61.4; }

template<typename T>
static inline T HornblendeC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 4.3; }

template<typename T>
static inline T HornblendeC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 159.7; }

template<typename T>
static inline T HornblendeC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 65.5; }

template<typename T>
static inline T HornblendeC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -2.5; }

template<typename T>
static inline T HornblendeC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 191.6; }

template<typename T>
static inline T HornblendeC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 10.0; }

template<typename T>
static inline T HornblendeC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 57.4; }

template<typename T>
static inline T HornblendeC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -6.2; }

template<typename T>
static inline T HornblendeC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 31.8; }

template<typename T>
static inline T HornblendeC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HornblendeC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 36.8; }

template<typename T>
static inline T HornblendeBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 87.0; }

template<typename T>
static inline T HornblendeShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 43.0; }

static inline std::string HornblendeReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Muscovite
static inline mpc::core::SymmetryGroupEnumeration MuscoviteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T MuscoviteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.844; }

template<typename T>
static inline T MuscoviteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 184.3; }

template<typename T>
static inline T MuscoviteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 48.3; }

template<typename T>
static inline T MuscoviteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.8; }

template<typename T>
static inline T MuscoviteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -2.0; }

template<typename T>
static inline T MuscoviteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 178.4; }

template<typename T>
static inline T MuscoviteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 21.7; }

template<typename T>
static inline T MuscoviteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.9; }

template<typename T>
static inline T MuscoviteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 59.1; }

template<typename T>
static inline T MuscoviteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 1.2; }

template<typename T>
static inline T MuscoviteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 16.0; }

template<typename T>
static inline T MuscoviteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.5; }

template<typename T>
static inline T MuscoviteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 17.6; }

template<typename T>
static inline T MuscoviteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MuscoviteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 72.4; }

template<typename T>
static inline T MuscoviteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 58.2; }

template<typename T>
static inline T MuscoviteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 35.3; }

static inline std::string MuscoviteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Gypsum
static inline mpc::core::SymmetryGroupEnumeration GypsumSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2; }

template<typename T>
static inline T GypsumDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.317; }

template<typename T>
static inline T GypsumC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 78.6; }

template<typename T>
static inline T GypsumC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 41.0; }

template<typename T>
static inline T GypsumC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 26.8; }

template<typename T>
static inline T GypsumC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -7.0; }

template<typename T>
static inline T GypsumC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 62.7; }

template<typename T>
static inline T GypsumC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 24.2; }

template<typename T>
static inline T GypsumC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.1; }

template<typename T>
static inline T GypsumC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 72.6; }

template<typename T>
static inline T GypsumC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -17.4; }

template<typename T>
static inline T GypsumC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 9.1; }

template<typename T>
static inline T GypsumC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -1.6; }

template<typename T>
static inline T GypsumC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 26.4; }

template<typename T>
static inline T GypsumC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GypsumC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 10.4; }

template<typename T>
static inline T GypsumBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 42.0; }

template<typename T>
static inline T GypsumShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 15.4; }

static inline std::string GypsumReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Enstatite
static inline mpc::core::SymmetryGroupEnumeration EnstatiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T EnstatiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.198; }

template<typename T>
static inline T EnstatiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 224.7; }

template<typename T>
static inline T EnstatiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 72.4; }

template<typename T>
static inline T EnstatiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 54.1; }

template<typename T>
static inline T EnstatiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 177.9; }

template<typename T>
static inline T EnstatiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 52.7; }

template<typename T>
static inline T EnstatiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 213.6; }

template<typename T>
static inline T EnstatiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 77.6; }

template<typename T>
static inline T EnstatiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 75.9; }

template<typename T>
static inline T EnstatiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T EnstatiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 81.6; }

template<typename T>
static inline T EnstatiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 107.8; }

template<typename T>
static inline T EnstatiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 75.7; }

static inline std::string EnstatiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }


// Forsterite
static inline mpc::core::SymmetryGroupEnumeration ForsteriteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T ForsteriteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.221; }

template<typename T>
static inline T ForsteriteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 328.0; }

template<typename T>
static inline T ForsteriteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 69.0; }

template<typename T>
static inline T ForsteriteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 69.0; }

template<typename T>
static inline T ForsteriteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 200.0; }

template<typename T>
static inline T ForsteriteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 73.0; }

template<typename T>
static inline T ForsteriteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 235.0; }

template<typename T>
static inline T ForsteriteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 66.7; }

template<typename T>
static inline T ForsteriteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 81.3; }

template<typename T>
static inline T ForsteriteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ForsteriteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 80.9; }

template<typename T>
static inline T ForsteriteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 129.5; }

template<typename T>
static inline T ForsteriteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 81.1; }

static inline std::string ForsteriteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }


// Fayalite
static inline mpc::core::SymmetryGroupEnumeration FayaliteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T FayaliteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 4.38; }

template<typename T>
static inline T FayaliteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 266.0; }

template<typename T>
static inline T FayaliteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 94.0; }

template<typename T>
static inline T FayaliteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 92.0; }

template<typename T>
static inline T FayaliteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 168.0; }

template<typename T>
static inline T FayaliteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 92.0; }

template<typename T>
static inline T FayaliteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 232.0; }

template<typename T>
static inline T FayaliteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 32.3; }

template<typename T>
static inline T FayaliteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 46.5; }

template<typename T>
static inline T FayaliteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FayaliteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 57.0; }

template<typename T>
static inline T FayaliteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 134.0; }

template<typename T>
static inline T FayaliteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 50.7; }

static inline std::string FayaliteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }


// Montecellite
static inline mpc::core::SymmetryGroupEnumeration MontecelliteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T MontecelliteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.116; }

template<typename T>
static inline T MontecelliteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 216.0; }

template<typename T>
static inline T MontecelliteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 59.0; }

template<typename T>
static inline T MontecelliteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 71.0; }

template<typename T>
static inline T MontecelliteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 150.0; }

template<typename T>
static inline T MontecelliteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 77.0; }

template<typename T>
static inline T MontecelliteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 184.0; }

template<typename T>
static inline T MontecelliteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 50.6; }

template<typename T>
static inline T MontecelliteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 56.5; }

template<typename T>
static inline T MontecelliteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MontecelliteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 59.2; }

template<typename T>
static inline T MontecelliteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 106.0; }

template<typename T>
static inline T MontecelliteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 55.2; }

static inline std::string MontecelliteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Andalusite
static inline mpc::core::SymmetryGroupEnumeration AndalusiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T AndalusiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.145; }

template<typename T>
static inline T AndalusiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 233.4; }

template<typename T>
static inline T AndalusiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 97.7; }

template<typename T>
static inline T AndalusiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.2; }

template<typename T>
static inline T AndalusiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 289.0; }

template<typename T>
static inline T AndalusiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 81.4; }

template<typename T>
static inline T AndalusiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 380.1; }

template<typename T>
static inline T AndalusiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 99.5; }

template<typename T>
static inline T AndalusiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 87.8; }

template<typename T>
static inline T AndalusiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AndalusiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 112.3; }

template<typename T>
static inline T AndalusiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 162.0; }

template<typename T>
static inline T AndalusiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 99.1; }

static inline std::string AndalusiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Silimanite
static inline mpc::core::SymmetryGroupEnumeration SilimaniteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T SilimaniteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.241; }

template<typename T>
static inline T SilimaniteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 287.3; }

template<typename T>
static inline T SilimaniteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 158.6; }

template<typename T>
static inline T SilimaniteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 83.4; }

template<typename T>
static inline T SilimaniteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 231.9; }

template<typename T>
static inline T SilimaniteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 94.7; }

template<typename T>
static inline T SilimaniteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 388.4; }

template<typename T>
static inline T SilimaniteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 122.4; }

template<typename T>
static inline T SilimaniteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 80.7; }

template<typename T>
static inline T SilimaniteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SilimaniteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 89.3; }

template<typename T>
static inline T SilimaniteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 170.8; }

template<typename T>
static inline T SilimaniteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 91.5; }

static inline std::string SilimaniteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Barite
static inline mpc::core::SymmetryGroupEnumeration BariteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T BariteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 4.473; }

template<typename T>
static inline T BariteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 95.1; }

template<typename T>
static inline T BariteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 51.3; }

template<typename T>
static inline T BariteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.6; }

template<typename T>
static inline T BariteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 83.7; }

template<typename T>
static inline T BariteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 32.8; }

template<typename T>
static inline T BariteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 110.6; }

template<typename T>
static inline T BariteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 11.8; }

template<typename T>
static inline T BariteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 29.0; }

template<typename T>
static inline T BariteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BariteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 27.7; }

template<typename T>
static inline T BariteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 58.2; }

template<typename T>
static inline T BariteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.2; }

static inline std::string BariteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Anhydrite
static inline mpc::core::SymmetryGroupEnumeration AnhydriteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC; }

template<typename T>
static inline T AnhydriteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.963; }

template<typename T>
static inline T AnhydriteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 93.8; }

template<typename T>
static inline T AnhydriteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 16.5; }

template<typename T>
static inline T AnhydriteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 15.2; }

template<typename T>
static inline T AnhydriteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 185.0; }

template<typename T>
static inline T AnhydriteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 31.7; }

template<typename T>
static inline T AnhydriteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 112.0; }

template<typename T>
static inline T AnhydriteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 32.5; }

template<typename T>
static inline T AnhydriteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 26.5; }

template<typename T>
static inline T AnhydriteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T AnhydriteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 9.3; }

template<typename T>
static inline T AnhydriteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 54.9; }

template<typename T>
static inline T AnhydriteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 29.3; }

static inline std::string AnhydriteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Dolomite
static inline mpc::core::SymmetryGroupEnumeration DolomiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TRIGONAL7; }

template<typename T>
static inline T DolomiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.795; }

template<typename T>
static inline T DolomiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 205.0; }

template<typename T>
static inline T DolomiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 71.0; }

template<typename T>
static inline T DolomiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 57.4; }

template<typename T>
static inline T DolomiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -19.5; }

template<typename T>
static inline T DolomiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 13.7; }

template<typename T>
static inline T DolomiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T DolomiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 205.0; }

template<typename T>
static inline T DolomiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 57.4; }

template<typename T>
static inline T DolomiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 19.5; }

template<typename T>
static inline T DolomiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -13.7; }

template<typename T>
static inline T DolomiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T DolomiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 113.0; }

template<typename T>
static inline T DolomiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T DolomiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T DolomiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T DolomiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 39.8; }

template<typename T>
static inline T DolomiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T DolomiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -13.7; }

template<typename T>
static inline T DolomiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 39.8; }

template<typename T>
static inline T DolomiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -19.5; }

template<typename T>
static inline T DolomiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 67.0; }

template<typename T>
static inline T DolomiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 94.9; }

template<typename T>
static inline T DolomiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 45.7; }

static inline std::string DolomiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Rutile
static inline mpc::core::SymmetryGroupEnumeration RutileSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TETRAGONAL6; }

template<typename T>
static inline T RutileDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 4.260; }

template<typename T>
static inline T RutileC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 269.0; }

template<typename T>
static inline T RutileC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 177.0; }

template<typename T>
static inline T RutileC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 146.0; }

template<typename T>
static inline T RutileC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 269.0; }

template<typename T>
static inline T RutileC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 146.0; }

template<typename T>
static inline T RutileC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 480.0; }

template<typename T>
static inline T RutileC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 124.0; }

template<typename T>
static inline T RutileC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 124.0; }

template<typename T>
static inline T RutileC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T RutileC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 192.0; }

template<typename T>
static inline T RutileBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 215.5; }

template<typename T>
static inline T RutileShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 112.4; }

static inline std::string RutileReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Zircon
static inline mpc::core::SymmetryGroupEnumeration ZirconSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TETRAGONAL6; }

template<typename T>
static inline T ZirconDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 4.700; }

template<typename T>
static inline T ZirconC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 256.0; }

template<typename T>
static inline T ZirconC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 175.0; }

template<typename T>
static inline T ZirconC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 214.0; }

template<typename T>
static inline T ZirconC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 256.0; }

template<typename T>
static inline T ZirconC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 214.0; }

template<typename T>
static inline T ZirconC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 372.0; }

template<typename T>
static inline T ZirconC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 73.5; }

template<typename T>
static inline T ZirconC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 73.5; }

template<typename T>
static inline T ZirconC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ZirconC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T ZirconBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 223.9; }

template<typename T>
static inline T ZirconShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 66.6; }

static inline std::string ZirconReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Corundum
static inline mpc::core::SymmetryGroupEnumeration CorundumSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TRIGONAL6; }

template<typename T>
static inline T CorundumDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.982; }

template<typename T>
static inline T CorundumC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 497.0; }

template<typename T>
static inline T CorundumC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 162.0; }

template<typename T>
static inline T CorundumC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T CorundumC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -21.9; }

template<typename T>
static inline T CorundumC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 497.0; }

template<typename T>
static inline T CorundumC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T CorundumC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 21.9; }

template<typename T>
static inline T CorundumC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 501.0; }

template<typename T>
static inline T CorundumC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 146.8; }

template<typename T>
static inline T CorundumC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CorundumC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 146.8; }

template<typename T>
static inline T CorundumC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -21.9; }

template<typename T>
static inline T CorundumC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 167.5; }

template<typename T>
static inline T CorundumBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 253.5; }

template<typename T>
static inline T CorundumShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 163.2; }

static inline std::string CorundumReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Calcite
static inline mpc::core::SymmetryGroupEnumeration CalciteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TRIGONAL6; }

template<typename T>
static inline T CalciteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.712; }

template<typename T>
static inline T CalciteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 144.0; }

template<typename T>
static inline T CalciteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 53.9; }

template<typename T>
static inline T CalciteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 51.1; }

template<typename T>
static inline T CalciteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -20.5; }

template<typename T>
static inline T CalciteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 144.0; }

template<typename T>
static inline T CalciteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 51.1; }

template<typename T>
static inline T CalciteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 20.5; }

template<typename T>
static inline T CalciteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 84.0; }

template<typename T>
static inline T CalciteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.5; }

template<typename T>
static inline T CalciteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T CalciteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.5; }

template<typename T>
static inline T CalciteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -20.5; }

template<typename T>
static inline T CalciteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 45.05; }

template<typename T>
static inline T CalciteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 73.3; }

template<typename T>
static inline T CalciteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 32.0; }

static inline std::string CalciteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Quartz
static inline mpc::core::SymmetryGroupEnumeration QuartzSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TRIGONAL6; }

template<typename T>
static inline T QuartzDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.648; }

template<typename T>
static inline T QuartzC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 86.6; }

template<typename T>
static inline T QuartzC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.7; }

template<typename T>
static inline T QuartzC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.6; }

template<typename T>
static inline T QuartzC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -17.8; }

template<typename T>
static inline T QuartzC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 86.6; }

template<typename T>
static inline T QuartzC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.6; }

template<typename T>
static inline T QuartzC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 17.8; }

template<typename T>
static inline T QuartzC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 106.1; }

template<typename T>
static inline T QuartzC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 57.8; }

template<typename T>
static inline T QuartzC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T QuartzC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 57.8; }

template<typename T>
static inline T QuartzC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -17.8; }

template<typename T>
static inline T QuartzC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 39.95; }

template<typename T>
static inline T QuartzBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 37.8; }

template<typename T>
static inline T QuartzShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.3; }

static inline std::string QuartzReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Tourmaline
static inline mpc::core::SymmetryGroupEnumeration TourmalineSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::TRIGONAL6; }

template<typename T>
static inline T TourmalineDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.100; }

template<typename T>
static inline T TourmalineC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 305.0; }

template<typename T>
static inline T TourmalineC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 108.0; }

template<typename T>
static inline T TourmalineC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 51.0; }

template<typename T>
static inline T TourmalineC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -6.0; }

template<typename T>
static inline T TourmalineC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 305.0; }

template<typename T>
static inline T TourmalineC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 51.0; }

template<typename T>
static inline T TourmalineC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.0; }

template<typename T>
static inline T TourmalineC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 176.4; }

template<typename T>
static inline T TourmalineC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 64.8; }

template<typename T>
static inline T TourmalineC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T TourmalineC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 64.8; }

template<typename T>
static inline T TourmalineC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return -6.0; }

template<typename T>
static inline T TourmalineC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 98.5; }

template<typename T>
static inline T TourmalineBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 127.2; }

template<typename T>
static inline T TourmalineShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 81.5; }

static inline std::string TourmalineReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Beryl
static inline mpc::core::SymmetryGroupEnumeration BerylSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::HEXAGONAL; }

template<typename T>
static inline T BerylDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.724; }

template<typename T>
static inline T BerylC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 304.2; }

template<typename T>
static inline T BerylC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 123.8; }

template<typename T>
static inline T BerylC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 114.5; }

template<typename T>
static inline T BerylC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 304.2; }

template<typename T>
static inline T BerylC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 114.5; }

template<typename T>
static inline T BerylC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 277.6; }

template<typename T>
static inline T BerylC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 65.3; }

template<typename T>
static inline T BerylC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 65.3; }

template<typename T>
static inline T BerylC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T BerylC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 90.2; }

template<typename T>
static inline T BerylBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 176.0; }

template<typename T>
static inline T BerylShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 78.8; }

static inline std::string BerylReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Graphite
static inline mpc::core::SymmetryGroupEnumeration GraphiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::HEXAGONAL; }

template<typename T>
static inline T GraphiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.26; }

template<typename T>
static inline T GraphiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 1060.0; }

template<typename T>
static inline T GraphiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 180.0; }

template<typename T>
static inline T GraphiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 15.0; }

template<typename T>
static inline T GraphiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 1060.0; }

template<typename T>
static inline T GraphiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 15.0; }

template<typename T>
static inline T GraphiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 36.5; }

template<typename T>
static inline T GraphiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.3; }

template<typename T>
static inline T GraphiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.3; }

template<typename T>
static inline T GraphiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GraphiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 440.0; }

template<typename T>
static inline T GraphiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 161.0; }

template<typename T>
static inline T GraphiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 109.3; }

static inline std::string GraphiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Wusite
static inline mpc::core::SymmetryGroupEnumeration WusiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T WusiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 5.681; }

template<typename T>
static inline T WusiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 245.7; }

template<typename T>
static inline T WusiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 149.3; }

template<typename T>
static inline T WusiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 149.3; }

template<typename T>
static inline T WusiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 245.7; }

template<typename T>
static inline T WusiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 149.3; }

template<typename T>
static inline T WusiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 245.7; }

template<typename T>
static inline T WusiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.7; }

template<typename T>
static inline T WusiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.7; }

template<typename T>
static inline T WusiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T WusiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.7; }

template<typename T>
static inline T WusiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 181.4; }

template<typename T>
static inline T WusiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 46.1; }

static inline std::string WusiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Manganosite
static inline mpc::core::SymmetryGroupEnumeration ManganositeSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T ManganositeDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 5.365; }

template<typename T>
static inline T ManganositeC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 227.0; }

template<typename T>
static inline T ManganositeC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T ManganositeC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T ManganositeC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 227.0; }

template<typename T>
static inline T ManganositeC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 116.0; }

template<typename T>
static inline T ManganositeC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 227.0; }

template<typename T>
static inline T ManganositeC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 78.0; }

template<typename T>
static inline T ManganositeC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 78.0; }

template<typename T>
static inline T ManganositeC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ManganositeC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 78.0; }

template<typename T>
static inline T ManganositeBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 153.0; }

template<typename T>
static inline T ManganositeShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 68.1; }

static inline std::string ManganositeReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Periclase
static inline mpc::core::SymmetryGroupEnumeration PericlaseSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T PericlaseDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.584; }

template<typename T>
static inline T PericlaseC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 294.0; }

template<typename T>
static inline T PericlaseC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 93.0; }

template<typename T>
static inline T PericlaseC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 93.0; }

template<typename T>
static inline T PericlaseC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 294.0; }

template<typename T>
static inline T PericlaseC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 93.0; }

template<typename T>
static inline T PericlaseC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 294.0; }

template<typename T>
static inline T PericlaseC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 155.0; }

template<typename T>
static inline T PericlaseC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 155.0; }

template<typename T>
static inline T PericlaseC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PericlaseC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 155.0; }

template<typename T>
static inline T PericlaseBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 160.0; }

template<typename T>
static inline T PericlaseShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 130.3; }

static inline std::string PericlaseReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Magnetite
static inline mpc::core::SymmetryGroupEnumeration MagnetiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T MagnetiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 5.206; }

template<typename T>
static inline T MagnetiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 270.0; }

template<typename T>
static inline T MagnetiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 108.0; }

template<typename T>
static inline T MagnetiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 108.0; }

template<typename T>
static inline T MagnetiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 270.0; }

template<typename T>
static inline T MagnetiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 108.0; }

template<typename T>
static inline T MagnetiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 270.0; }

template<typename T>
static inline T MagnetiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 98.7; }

template<typename T>
static inline T MagnetiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 98.7; }

template<typename T>
static inline T MagnetiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T MagnetiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 98.7; }

template<typename T>
static inline T MagnetiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 162.0; }

template<typename T>
static inline T MagnetiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 91.2; }

static inline std::string MagnetiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Chromite
static inline mpc::core::SymmetryGroupEnumeration ChromiteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T ChromiteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 5.090; }

template<typename T>
static inline T ChromiteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 322.0; }

template<typename T>
static inline T ChromiteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 144.0; }

template<typename T>
static inline T ChromiteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 144.0; }

template<typename T>
static inline T ChromiteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 322.0; }

template<typename T>
static inline T ChromiteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 144.0; }

template<typename T>
static inline T ChromiteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 322.0; }

template<typename T>
static inline T ChromiteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 117.0; }

template<typename T>
static inline T ChromiteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 117.0; }

template<typename T>
static inline T ChromiteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T ChromiteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 117.0; }

template<typename T>
static inline T ChromiteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 203.3; }

template<typename T>
static inline T ChromiteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 104.9; }

static inline std::string ChromiteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Spinel
static inline mpc::core::SymmetryGroupEnumeration SpinelSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T SpinelDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.578; }

template<typename T>
static inline T SpinelC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 282.9; }

template<typename T>
static inline T SpinelC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 155.4; }

template<typename T>
static inline T SpinelC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 155.4; }

template<typename T>
static inline T SpinelC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 282.9; }

template<typename T>
static inline T SpinelC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 155.4; }

template<typename T>
static inline T SpinelC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 282.9; }

template<typename T>
static inline T SpinelC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 154.8; }

template<typename T>
static inline T SpinelC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 154.8; }

template<typename T>
static inline T SpinelC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SpinelC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 154.8; }

template<typename T>
static inline T SpinelBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 197.9; }

template<typename T>
static inline T SpinelShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 108.5; }

static inline std::string SpinelReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Pyrite
static inline mpc::core::SymmetryGroupEnumeration PyriteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T PyriteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 5.016; }

template<typename T>
static inline T PyriteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 361.0; }

template<typename T>
static inline T PyriteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.6; }

template<typename T>
static inline T PyriteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.6; }

template<typename T>
static inline T PyriteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 361.0; }

template<typename T>
static inline T PyriteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.6; }

template<typename T>
static inline T PyriteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 361.0; }

template<typename T>
static inline T PyriteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 105.2; }

template<typename T>
static inline T PyriteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 105.2; }

template<typename T>
static inline T PyriteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T PyriteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 105.2; }

template<typename T>
static inline T PyriteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 142.7; }

template<typename T>
static inline T PyriteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 125.7; }

static inline std::string PyriteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Galena
static inline mpc::core::SymmetryGroupEnumeration GalenaSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T GalenaDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 7.597; }

template<typename T>
static inline T GalenaC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 127.0; }

template<typename T>
static inline T GalenaC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 24.4; }

template<typename T>
static inline T GalenaC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 24.4; }

template<typename T>
static inline T GalenaC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 127.0; }

template<typename T>
static inline T GalenaC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 24.4; }

template<typename T>
static inline T GalenaC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 127.0; }

template<typename T>
static inline T GalenaC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.0; }

template<typename T>
static inline T GalenaC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.0; }

template<typename T>
static inline T GalenaC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T GalenaC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 23.0; }

template<typename T>
static inline T GalenaBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 58.6; }

template<typename T>
static inline T GalenaShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 31.9; }

static inline std::string GalenaReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Sphalerite
static inline mpc::core::SymmetryGroupEnumeration SphaleriteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T SphaleriteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 4.088; }

template<typename T>
static inline T SphaleriteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 102.0; }

template<typename T>
static inline T SphaleriteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 64.6; }

template<typename T>
static inline T SphaleriteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 64.6; }

template<typename T>
static inline T SphaleriteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 102.0; }

template<typename T>
static inline T SphaleriteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 64.6; }

template<typename T>
static inline T SphaleriteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 102.0; }

template<typename T>
static inline T SphaleriteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.6; }

template<typename T>
static inline T SphaleriteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.6; }

template<typename T>
static inline T SphaleriteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SphaleriteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 44.6; }

template<typename T>
static inline T SphaleriteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 77.1; }

template<typename T>
static inline T SphaleriteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 31.5; }

static inline std::string SphaleriteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Fluorite
static inline mpc::core::SymmetryGroupEnumeration FluoriteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T FluoriteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 3.181; }

template<typename T>
static inline T FluoriteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 165.0; }

template<typename T>
static inline T FluoriteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 47.0; }

template<typename T>
static inline T FluoriteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 47.0; }

template<typename T>
static inline T FluoriteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 165.0; }

template<typename T>
static inline T FluoriteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 47.0; }

template<typename T>
static inline T FluoriteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 165.0; }

template<typename T>
static inline T FluoriteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.9; }

template<typename T>
static inline T FluoriteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.9; }

template<typename T>
static inline T FluoriteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T FluoriteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 33.9; }

template<typename T>
static inline T FluoriteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 86.3; }

template<typename T>
static inline T FluoriteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 42.4; }

static inline std::string FluoriteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Halite
static inline mpc::core::SymmetryGroupEnumeration HaliteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T HaliteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 2.163; }

template<typename T>
static inline T HaliteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 49.1; }

template<typename T>
static inline T HaliteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.8; }

template<typename T>
static inline T HaliteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.8; }

template<typename T>
static inline T HaliteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 49.1; }

template<typename T>
static inline T HaliteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.8; }

template<typename T>
static inline T HaliteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 49.1; }

template<typename T>
static inline T HaliteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.8; }

template<typename T>
static inline T HaliteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.8; }

template<typename T>
static inline T HaliteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T HaliteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 12.8; }

template<typename T>
static inline T HaliteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 24.9; }

template<typename T>
static inline T HaliteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 14.7; }

static inline std::string HaliteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

// Sylvite
static inline mpc::core::SymmetryGroupEnumeration SylviteSymmetryClass() { return mpc::core::SymmetryGroupEnumeration::CUBIC; }

template<typename T>
static inline T SylviteDensity() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 1.987; }

template<typename T>
static inline T SylviteC11() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 40.5; }

template<typename T>
static inline T SylviteC12() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.9; }

template<typename T>
static inline T SylviteC13() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.9; }

template<typename T>
static inline T SylviteC14() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC15() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC16() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC22() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 40.5; }

template<typename T>
static inline T SylviteC23() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.9; }

template<typename T>
static inline T SylviteC24() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC25() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC26() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC33() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 40.5; }

template<typename T>
static inline T SylviteC34() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC35() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC36() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC44() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.27; }

template<typename T>
static inline T SylviteC45() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC46() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC55() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.27; }

template<typename T>
static inline T SylviteC56() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 0.0; }

template<typename T>
static inline T SylviteC66() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 6.27; }

template<typename T>
static inline T SylviteBulkModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 18.1; }

template<typename T>
static inline T SylviteShearModulus() {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    return 9.4; }

static inline std::string SylviteReferences() { return "Bass, J. D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63"; }

}  // END namespace data
}  // END namespace mpc




#endif // MINERALDATAPROPERTIES_H
