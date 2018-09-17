/**
 *    @file accumulator.hpp
 *    @brief function object for accumulating blitz arrays; two methods
 * are summation and multiplication
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_ACCUMULATOR_H
#define MPC_ACCUMULATOR_H

#include <functional>

// blitz
#include <blitz/array.h>
#include <blitz/tinyvec2.h>
#include <blitz/indexexpr.h>

namespace mpc {
namespace util {

template<typename T, int N>
struct AccumulatorSum {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,N-1> operator()(blitz::Array<T,N>& input_array) {
                // loop through each "element" of the Nth dimensions and sum the N-1 "elements"
                blitz::TinyVector<T,N> ishp = input_array.shape(); // shape of the input array
                blitz::TinyVector<T,N-1> oshp;              // shape of the output array (initialization)
                for (int n = 0; n<N-1; ++n) { oshp[n] = ishp[n]; } // set oshp from the values of ishp
                blitz::Array<T,N-1> output_array = blitz::Array<T,N-1>(oshp);
                //
                blitz::IndexPlaceholder<N-1> i;
                output_array = blitz::sum(input_array, i);

                return output_array;

        }
};

//partial spectialization for N=1
template<typename T>
struct AccumulatorSum<T,1> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        T operator()(blitz::Array<T,1>& input_array) {
                T output_value = 0;
                // see Blitz++ User Guide 3.13 Complete Reductions
                output_value = blitz::sum(input_array);
                return output_value;
        }
};

//
template<typename T, int N>
struct AccumulatorProduct {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,N-1> operator()(blitz::Array<T,N>& input_array) {
                // loop through each "element" of the Nth dimensions and sum the N-1 "elements"
                blitz::TinyVector<T,N> ishp = input_array.shape(); // shape of the input array
                blitz::TinyVector<T,N-1> oshp;              // shape of the output array (initialization)
                for (int n = 0; n<N-1; ++n) { oshp[n] = ishp[n]; } // set oshp from the values of ishp
                blitz::Array<T,N-1> output_array = blitz::Array<T,N-1>(oshp);
                //
                blitz::IndexPlaceholder<N-1> i;
                output_array = blitz::product(input_array, i);

                return output_array;

        }
};

//partial spectialization for N=1
template<typename T>
struct AccumulatorProduct<T,1> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        T operator()(blitz::Array<T,1>& input_array) {
                T output_value = 0;
                // see Blitz++ User Guide 3.13 Complete Reductions
                output_value = blitz::product(input_array);
                return output_value;
        }
};

}  // END NAMESPACE UTIL
}  // END NAMESPACE MPC

#endif //MPC_ACCUMULATOR_H
