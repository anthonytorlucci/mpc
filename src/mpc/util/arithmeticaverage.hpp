/**
 *    @file mpc.hpp
 *    @brief function object for calculating the weighted arithmetic
 * (linear) average of two std::vector's; the "values" can be blitz arrays or
 * plain numeric values while the second argument "weights" is a vector of
 * numeric values
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_ARITHMETIC_AVERAGE_H
#define MPC_ARITHMETIC_AVERAGE_H

#include <cmath>
#include <vector>
#include <type_traits>

// blitz++
#include <blitz/array.h>

namespace mpc {
namespace util {

// TODO: replace with recursion

// ARITHMETIC AVERAGE
template <typename T, int N>
struct WeightedArithmeticAverage {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,N> operator()(std::vector<blitz::Array<T,N> >& values, std::vector<T>& weights)
        {
                blitz::Array<T,N> output_array = blitz::Array<T,N>(values[0].shape()); // initialize output array
                output_array = 0;
                for (int i=0; i<values.size(); ++i)
                {
                        output_array += values[i] * weights[i];
                }
                return output_array;
        }
};

// partial specialization
template <typename T>
struct WeightedArithmeticAverage<T,0> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        T operator()(std::vector<T>& values, std::vector<T>& weights){
                T output_value = 0;
                for (int i=0; i<values.size(); ++i)
                {
                        output_value += values[i] * weights[i];
                }
                return output_value;
        }
};

}  // namespace util
}  // namespace mpc

#endif //MPC_ARITHMETIC_AVERAGE_H
