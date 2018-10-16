/**
 *    \file innerproductor.hpp
 *    \brief function object for calculating the inner product of two
 * blitz arrays
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_INNERPRODUCTOR_H
#define MPC_INNERPRODUCTOR_H

// c++
#include <cassert>

// blitz
#include <blitz/array.h>
#include <blitz/tinyvec2.h>

// mpc
#include "constants.hpp"

namespace mpc {
    namespace utilities {

        template <typename T, int N>
        struct InnerProductor {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            blitz::Array<T,N-1> operator()(blitz::Array<T,N>& input_array1, blitz::Array<T,N>& input_array2) {
                // loop through each "element" of the Nth dimensions and sum the N-1 "elements"
                blitz::TinyVector<T,N> ishp1 = input_array1.shape(); // shape of the input array 1
                blitz::TinyVector<T,N> ishp2 = input_array2.shape(); // shape of the input array 2
                // TODO: static_assert(ishp1 == ishp2);
                //assert(ishp2 == ishp1);
                //            std::cout << " ishp1: " << ishp1 << std::endl;
                //            std::cout << " ishp2: " << ishp2 << std::endl;

                blitz::TinyVector<T,N-1> oshp;              // shape of the output array (initialization)
                for (int n = 0; n<N-1; ++n) { oshp[n] = ishp1[n]; } // set oshp from the values of ishp

                blitz::Array<T,N-1> output_array = blitz::Array<T,N-1>(oshp);

                blitz::Array<T,N> output_array_prod = blitz::Array<T,N>(ishp1);
                output_array_prod = input_array1 * input_array2;
                //
                blitz::IndexPlaceholder<N-1> i;
                output_array = blitz::sum(output_array_prod, i);

                return output_array;
            }
        };

        // partial specialization for N=1
        template <typename T>
        struct InnerProductor<T,1> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            T operator()(blitz::Array<T,1>& input_array1, blitz::Array<T,1>& input_array2) {
                T output_value = 0;
                blitz::TinyVector<T,1> ishp1 = input_array1.shape(); // shape of the input array 1
                blitz::TinyVector<T,1> ishp2 = input_array2.shape(); // shape of the input array 2
                //static_assert(ishp1 == ishp2);
                //std::cout << " ishp1: " << ishp1 << std::endl;
                //std::cout << " ishp2: " << ishp2 << std::endl;
                assert(ishp1[0] == ishp2[0]);

                blitz::Array<T,1> output_array_prod = blitz::Array<T,1>(ishp1);
                output_array_prod = input_array1 * input_array2;
                //
                //blitz::IndexPlaceholder<0> i;
                output_value = blitz::sum(output_array_prod);

                return output_value;
            }
        };

    }  // namespace utilities
}  // namespace mpc

#endif //MPC_INNERPRODUCTOR_H
