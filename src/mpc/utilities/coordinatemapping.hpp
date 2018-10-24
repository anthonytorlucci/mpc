/**
 *    \file coordinatemapping.hpp
 *    \brief maps coordinates from one system to another
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/24
 */

#ifndef MPC_COORDINATEMAPPING_H
#define MPC_COORDINATEMAPPING_H

// c++
#include <tuple>
#include <type_traits>
#include <cmath>

// blitz

//mpc


namespace mpc {
    namespace utilities {

        struct CoordinateBaseType {};
        struct CartesianCoordinateType : public CoordinateBaseType {};
        struct SphericalCoordinateType : public CoordinateBaseType {};
        struct CylindricalCoordinateType : public CoordinateBaseType {};

        template <typename T, typename U, typename V>
        struct CoordinateMapping {
            // function object for mapping between coordinate systems
            // U is the coordinate system being mapped to; V is the coordinate system being mapped from
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            static_assert(std::is_base_of<mpc::utilities::CoordinateBaseType,U>::value, "U must be derived from mpc::utilities::CoordinateBaseType.");
            static_assert(std::is_base_of<mpc::utilities::CoordinateBaseType,V>::value, "V must be derived from mpc::utilities::CoordinateBaseType.");

        };

        /* NOTES: (Arfken, George B., Weber, Hans J., 2001, Mathematical Methods for Physicists, fifth edition: Academic Press.)
         * p. 114 : Circular Cylindrical Coordinates
         *     ... The limits on rho, phi, and z are
         *         0 <= rho < infintity, 0 <= phi <= 2*pi, and -infinity < z < infinity
         *
         *     Note that we are using rho for the perpendicular distance from the z-axis and saving r for the distance from the origin...
         *
         * p. 121 : Spherical Polar Coordinates
         *     ... By our arbitrary choice of definitions of theta, the polar angle, and phi, the azimuth angle, the z-axis is singled out for spcial treatment...
         */


        // specialization
        template <typename  T>
        struct CoordinateMapping<T,CartesianCoordinateType,CylindricalCoordinateType> {
            //
            std::tuple<T,T,T> operator()(T rho, T phi, T z) {
                // assumes angles are given in radians
                T x = rho * cos(phi);
                T y = rho * sin(phi);
                return std::make_tuple(x,y,z);
            }
        };

        template <typename  T>
        struct CoordinateMapping<T,CartesianCoordinateType,SphericalCoordinateType> {
            //
            std::tuple<T,T,T> operator()(T rho, T theta, T phi) {
                // assumes angles are given in radians
                T x = rho * sin(theta) * cos(phi);
                T y = rho * sin(theta) * sin(phi);
                T z = rho * cos(theta);
                return std::make_tuple(x,y,z);
            }
        };


    } // namespace utilities
} // namespace mpc

#endif // MPC_COORDINATEMAPPING_H
