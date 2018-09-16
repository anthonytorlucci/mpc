/**
*    @file magnitude.hpp
*    @brief simple function for claculating the magnitude, i.e. the
* square root of the sum of the squares, of a one-dimensional array
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MPC_MAGNITUDE_H
#define MPC_MAGNITUDE_H

// blitz
#include <blitz/array.h>

// mpc
#include "accumulator.hpp"

namespace mpc {
namespace util {

template <typename T>
static T Magnitude(blitz::Array<T,1>& input_array) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // calculates the square root of the sum of the squares, i.e. the magnitude of the vector
    // another method might be to calculate the square root of the dot product of the input vector with itself.  These two are equivalent.

    blitz::Array<T,1> tmp(input_array.shape());  // use std::copy<>???
    tmp = blitz::pow2(input_array);       //  Computes integer power.  They expand to a series of multiplications, so they can be used on any type for which multiplication is well-defined.

    mpc::util::AccumulatorSum<T,1> AccumulatorSum1;
    T asum1 = AccumulatorSum1(tmp);  // sums the components, i.e. sum of the squares

    return sqrt(asum1);

}

} // namespace util
} // namespace mpc

#endif // MPC_MAGNITUDE_H
