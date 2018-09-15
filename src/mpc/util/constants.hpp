/**
 *  mpc - mechanical properties of crystals
 *  Description ...
 */

#ifndef MPC_CONSTANTS_H
#define MPC_CONSTANTS_H

#include <cmath>

// blitz
//#include <blitz/array.h>
//#include <blitz/tinyvec2.h>

// TODO: This file provides common utilites that can be created at complile time
// Should this be all const or constexpr ???

namespace mpc {
namespace util {
    
// TODO: there must be a better compile-time way to do this for a generic floating point type T...

template<typename T>
T const PI = std::acos(-T(1));

}  // namespace util
}  // namespace mpc

#endif //MPC_CONSTANTS_H
