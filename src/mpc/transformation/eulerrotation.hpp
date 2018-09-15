/**
 *  mpc - mechanical properties of crystals
 *  Description ...
 */

#ifndef MPC_EULERROTATION_H
#define MPC_EULERROTATION_H

#include <cmath>

// blitz
#include <blitz/array.h>

// TODO: This file implements a template function object that outputs a rotation tensor
// TODO: based on 3 Euler angles (Bunge, 1982)

namespace mpc {
namespace transformation {



template <typename T>
struct EulerRotationX3X1X3 {
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    blitz::Array<T,2> operator()(T phi1, T PHI, T phi2) {

        blitz::Array<T,2> output_array = blitz::Array<T,2>(3,3);
        //
        output_array(0,0) = (cos(phi1) * cos(phi2)) - (sin(phi1) * cos(PHI) * sin(phi2));
        output_array(0,1) = (sin(phi1) * cos(phi2)) + (cos(phi1) * cos(PHI) * sin(phi2));
        output_array(0,2) = sin(PHI) * sin(phi2);

        output_array(1,0) = (-cos(phi1) * sin(phi2)) - (sin(phi1) * cos(PHI) * cos(phi2));
        output_array(1,1) = (-sin(phi1) * sin(phi2)) + (cos(phi1) * cos(PHI) * cos(phi2));
        output_array(1,2) = sin(PHI) * cos(phi2);

        output_array(2,0) = sin(phi1) * sin(PHI);
        output_array(2,1) = -cos(phi1) * sin(PHI);
        output_array(2,2) = cos(PHI);

        return output_array;

    }
};
}  // END namespace transformation
}  // END namespace mpc

#endif // MPC_EULERROTATION_H
