/**
 *  mpc - mechanical properties of crystals
 * Description ...
 */

#ifndef MPC_HARMONIC_AVERAGE_H
#define MPC_HARMONIC_AVERAGE_H

#include <cmath>
#include <vector>

// blitz++
#include <blitz/array.h>

// TODO: This file provides a template function object for calculating the weighted harmonic (non-linear)
// TODO: average of two std::vectors; the "values" can be blitz arrays or plain numeric values while
// TODO: the second argument "weights" is a vector of numeric values.

namespace mpc {
namespace util {

// HARMONIC AVERAGE
template <typename T, int N>
struct WeightedHarmonicAverage {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,N> operator()(std::vector<blitz::Array<T,N>>& values, std::vector<T>& weights)
    {
        blitz::Array<T,N> output_array = blitz::Array<T,N>(values[0].shape());  // initialize output array
        output_array = 0;
        for (int i=0; i<values.size(); ++i)
        {
            output_array += weights[i] / values[i];
        }
        output_array = 1/output_array;
        return output_array;
    }
};

// partial specialization
template <typename T>
struct WeightedHarmonicAverage<T,0> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    T operator()(std::vector<T>& values, std::vector<T>& weights){
        T output_value = 0;
        for (int i=0; i<values.size(); ++i)
        {
            output_value += weights[i] / values[i];
        }
        return 1/output_value;
    }
};


}  // END NAMESPACE UTIL
}  // END NAMESPACE MPC

#endif //MPC_HARMONIC_AVERAGE_H
