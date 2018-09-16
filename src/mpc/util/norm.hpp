/**
*    @file norm.hpp
*    @brief Lp norms
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MPC_NORMAL_H
#define MPC_NORMAL_H

// blitz
#include <blitz/array.h>

//mpc
#include "magnitude.hpp"

namespace mpc {
namespace util {

template <typename T>
static blitz::Array<T,1> Normal(blitz::Array<T,1>& input_array) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // calculate the normalized vector for the input one-dimensional array
    // TODO: make input_array const?
    // same as L2-norm
    blitz::Array<T,1> tmp(input_array.shape());  // use std::copy<>???
    T mag = mpc::linsys::Magnitude<T>(input_array);

//    blitz::TinyVector<T,1> ishp = input_array.shape();  // shape of the input array
//    int num_elems = ishp(0);  // number of elements
//    for (int i=0; i<num_elems; ++i) {
//        tmp(i) = input_array(i) / mag;  // divide each component by the magnitude of the vector
//    }
    tmp /= mag;
    return tmp;
}

template <typename T>
static void Normalize(blitz::Array<T,1>& input_array) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // normalize the vector in place
    // NOTE: this will change the components of the input array so it will not work if the input_array is const
    // same as L2-norm
    T mag = mpc::linsys::Magnitude<T>(input_array);
    input_array /= mag;
}

} // namespace util
} // namespace mpc

#endif // MPC_NORMAL_H
