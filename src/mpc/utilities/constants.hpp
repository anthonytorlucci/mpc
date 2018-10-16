/**
 *    \file constants.hpp
 *    \brief functions for constant values used by mpc
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_CONSTANTS_H
#define MPC_CONSTANTS_H

// c++
#include <cmath>

// TODO: make constexpr to be evaluated by compiler at compile time

namespace mpc {
    namespace utilities {

        template<typename T>
        T const PI = std::acos(-T(1));

    }  // namespace utilities
}  // namespace mpc

#endif //MPC_CONSTANTS_H
