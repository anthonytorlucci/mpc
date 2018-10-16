/**
 *    \file ortho3drotation.hpp
 *    \brief functions that ouput a transformation tensor to rotate another
 * tensor about one of the 3 Cartesian axes given an argument in radians
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_ORTHO3DROTATION_H
#define MPC_ORTHO3DROTATION_H

// c++
#include <cmath>

// blitz
#include <blitz/array.h>

namespace mpc {
    namespace transformation {

        template <typename T>
        blitz::Array<T,2> Ortho3dRotationX1(T phi) {
            // convenience function to get rotation matrix about the x1 axis
            //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            blitz::Array<T,2> output_array = blitz::Array<T,2>(3,3, blitz::ColumnMajorArray<2>());
            output_array(0,0) = 1.0;
            output_array(0,1) = 0;
            output_array(0,2) = 0;
            output_array(1,0) = 0;
            output_array(1,1) = cos(phi);
            output_array(1,2) = sin(phi);
            output_array(2,0) = 0;
            output_array(2,1) = -sin(phi);
            output_array(2,2) = cos(phi);

            return output_array;
        }

        template <typename T>
        blitz::Array<T,2> Ortho3dRotationX2(T phi) {
            // convenience function to get rotation matrix about the x1 axis
            //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            blitz::Array<T,2> output_array = blitz::Array<T,2>(3,3, blitz::ColumnMajorArray<2>());
            output_array(0,0) = cos(phi);
            output_array(0,1) = 0;
            output_array(0,2) = -sin(phi);
            output_array(1,0) = 0;
            output_array(1,1) = 1;
            output_array(1,2) = 0;
            output_array(2,0) = sin(phi);
            output_array(2,1) = 0;
            output_array(2,2) = cos(phi);

            return output_array;
        }

        template <typename T>
        blitz::Array<T,2> Ortho3dRotationX3(T phi) {
            // convenience function to get rotation matrix about the x1 axis
            //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            blitz::Array<T,2> output_array = blitz::Array<T,2>(3,3, blitz::ColumnMajorArray<2>());
            output_array(0,0) = cos(phi);
            output_array(0,1) = sin(phi);
            output_array(0,2) = 0;
            output_array(1,0) = -sin(phi);
            output_array(1,1) = cos(phi);
            output_array(1,2) = 0;
            output_array(2,0) = 0;
            output_array(2,1) = 0;
            output_array(2,2) = 1;

            return output_array;
        }

    }  // END namespace transformation
}  // END namespace mpc

#endif //AFM_ORTHO3DROTATION_H
