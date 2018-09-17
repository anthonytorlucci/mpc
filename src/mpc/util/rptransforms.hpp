/**
 *    \file rptransforms.hpp
 *    \brief simple rock physics transform functions
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef RPTRANSFORMS_H
#define RPTRANSFORMS_H

#include <cmath>

// blitz
#include <blitz/array.h>

namespace mpc {
namespace util {
// Rock Property Transforms

template <typename T>
static inline T CalculateVpVsRatio(T vp, T vs) {
        /**
         *  Vp/Vs ratio for an array of velocity values
         *  @param vp: p-wave velocity
         *  @param vs: s-wave velocity
         *  @return: Vp/Vs ratio
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        return vp/vs;
}

template <typename T>
static inline T CalculatePoissonsRatio(T vp, T vs) {
        /**
         *  Poisson's ratio for given p-wave velocity and s-wave velocity
         *  @param vp: p-wave velocity
         *  @param vs: s-wave velocity
         *  @return: Poisson's ratio
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        // TODO: assert Vs !=0
        T pr; // pr is undefined.  Make sure to handle exceptions correctly!
        T zeta = std::pow<T>(vp,2) / std::pow<T>(vs,2);
        if (zeta != 1) {
                pr = 0.5 * ((zeta - 2) / (zeta - 1));
        } else {
                // TODO : raise exception or throw error > Poisson's ratio is infinite!
        }
        return pr;
}

template <typename T>
static inline T CalculateVsFromVpPR(T vp, T pr) {
        /**
         *  S-wave velocity from P-wave velocity and Poisson's ratio
         *  @param vp: p-wave velocity
         *  @param pr: Poisson's ratio
         *  @return: s-wave velocity
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        // assert(pr != 1)
        T z1 = 0.5 - pr;
        T z2 = 1 - pr;
        T zeta = sqrt(z1/z2);
        return vp * zeta;
}

template <typename T>
static inline T CalculateVpFromVsPR(T vs, T pr) {
        /**
         *  S-wave velocity from P-wave velocity and Poisson's ratio
         *  @param vs: s-wave velocity
         *  @param pr: Poisson's ratio
         *  @return: p-wave velocity
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        // assert(pr != 1)
        T z1 = 0.5 - pr;
        T z2 = 1 - pr;
        T zeta = sqrt(z1/z2);
        // assert zeta !=0; throw DiveideByZeroException???
        return vs / zeta;
}

template <typename T>
static inline T BulkModulusFromVpVsRho(T vp, T vs, T rho) {
        /**
         *  bulk modulus from P-wave velocity, S-wave velocity, and density
         *  @param vp: p-wave velocity
         *  @param vs: s-wave velocity
         *  @param rho: density
         *  @return: bulk modulus
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        return rho * (std::pow(vp,2) - ((4.0/3.0) * std::pow(vs,2)));
}

template <typename T>
static inline T ShearModulusFromVsRho(T vs, T rho) {
        /**
         *  Shear modulus from S-wave velocity and density
         *  @param vs: s-wave velocity
         *  @param rho: density
         *  @return: shear modulus
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        return rho * std::pow(vs,2);
}

template <typename T>
static inline T PvelFromBulkModulusShearModulusDensity(T K, T mu, T rho) {
        /**
         *  P-wave velocity from bulk modulus, shear modulus, and density
         *  @param K: bulk modulus
         *  @param mu: shear modulus
         *  @param rho: density
         *  @return: p-wave velocity
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        // assert rho !=0; DivideByZero Exception?
        return sqrt((K + (4.0 * mu / 3.0)) / rho);
}

template <typename T>
static inline T SvelFromShearModulusDensity(T mu, T rho) {
        /**
         *  S-wave velocity from shear modulus and density
         *  @param mu: shear modulus
         *  @param rho: density
         *  @return: s-wave velocity
         */
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        return sqrt(mu / rho);
}


// TODO: AVO stuff
//template <typename T>
//static inline T TransmissionAnglePP(T vp1, T vp2, T thetai) {
//    /**
//     *  Taken from Snell's law, this function returns the angle of the
//     *    transmitted ray relative to the normal based on the velocity above
//     *    and below the interface.
//     *  @param vp1: p-wave velocity of layer above interface
//     *  @param vp2: p-wave velocity of layer below interface
//     *  @param thetai: angle of incident ray relative to normal in radians
//     *  @return: angle of transmitted ray relative to normal in radians
//     */
//    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//    // TODO: be careful  of the domain of arcsin [-1,1]
//    return asin(vp2 * sin(thetai) / vp1);
//}

//template <typename T>
//static inline T TransmissionAnglePS(T vp1, T vs2, T thetai) {
//    /**
//     *  Taken from Snell's law, this function returns the angle of the
//     *    transmitted ray relative to the normal based on the velocity above
//     *    and below the interface.
//     *  @param Vp1: p-wave velocity of layer above interface
//     *  @param Vs2: s-wave velocity of layer below interface
//     *  @param thetai: angle of incident ray relative to normal in radians
//     *  @return: angle of transmitted ray relative to normal in radians
//     */
//    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//    // TODO: be careful  of the domain of arcsin [-1,1]
//    return asin(vs2 * sin(thetai) / vp1);
//}

//template <typename T>
//static inline T ReflectionAnglePS(T vp1, T vs1, T thetai) {
//    /**
//     *  Taken from Snell's law, this function returns the angle of the
//     *    reflected ray relative to the normal based on the velocities above
//     *    the interface.
//     *  @param vp1: p-wave velocity of layer above interface
//     *  @param vs1: s-wave velocity of layer above interface
//     *  @param thetai: angle of incident ray relative to normal in radians
//     *  @return: angle of reflected ray relative to normal in radians
//     */
//    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//    // TODO: be careful of the domain of arcsin [-1,1]
//    return asin(vs1 * sin(thetai) / vp1);
//}

//template <typename T>
//T calculateRp(T vp0, T vp1, T rho0, T rho1) {
//    /**
//    *  P-wave reflection coefficient at normal incidence
//    *  @param vp0: p-wave velocity above interface
//    *  @param vp1: p-wave velocity below interface
//    *  @param rho0: density above interface
//    *  @param rho1: density below interface
//    *  @return: reflection coefficient from interface
//    */
//    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//    T mean_vels = 0.5 * (vp0 + vp1);
//    T mean_rho = 0.5 * (rho0 + rho1);
//    return 0.5 * (((vp1 - vp0) / mean_vels) + ((rho1-rho0) / mean_rho));
//}

//template <typename T>
//T calculateSp(T vs0, T vs1, T rho0, T rho1) {
//    /**
//    *  S-wave reflection coefficient at normal incidence
//    *  @param vs0: p-wave velocity above interface
//    *  @param vs1: p-wave velocity below interface
//    *  @param rho0: density above interface
//    *  @param rho1: density below interface
//    *  @return: reflection coefficient from interface
//    */
//    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//    T mean_vels = 0.5 * (vs0 + vs1);
//    T mean_rho = 0.5 * (rho0 + rho1);
//    return 0.5 * (((vp1 - vp0) / mean_vels) + ((rho1-rho0) / mean_rho));
//}

}  // END NAMESPACE UTIL
}  // END NAMESPACE MPC

#endif // RPTRANSFORMS_H
