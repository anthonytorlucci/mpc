/**
 *    @file constants.hpp
 *    @brief functions for constant values used by mpc
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_CONSTANTS_H
#define MPC_CONSTANTS_H

#include <cmath>

// TODO: make constexpr to be evaluated by compiler at compile time

namespace mpc {
namespace util {

template<typename T>
T const PI = std::acos(-T(1));

}  // namespace util
}  // namespace mpc

#endif //MPC_CONSTANTS_H
