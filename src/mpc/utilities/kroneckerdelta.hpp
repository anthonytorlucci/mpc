/**
 *    \file kroneckerdelta.hpp
 *    \brief function for getting the second-rank tensor Kronecker delta in N-dimenional space
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_KRONECKERDELTA_H
#define MPC_KRONECKERDELTA_H

// blitz
#include <blitz/array.h>

// mpc

namespace mpc {
    namespace utilities {

        // typedef??

        // make function object or constexpr?
        template <typename T, int N>
        blitz::Array<T,2> KroneckerDelta() {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            blitz::Array<T,2> kdelta = blitz::Array<T,2>(N, N, blitz::ColumnMajorArray<2>());
            kdelta = 0;
            for (int i=0; i<N; ++i) { kdelta(i,i) = T(1.0); }
            return kdelta;
        }


        // ===============================================================================================
        // specialized function objects for compile-time selection
        template <typename T, int M, int N>
        struct CKroneckerDelta3FunctionObject {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            static_assert(M>=0, "template parameter M must be greater than or equal to zero");
            static_assert(M<3, "template parameter M must be less than 3 for zero based indexing");
            static_assert(N>=0, "template parameter N must be greater than or equal to zero");
            static_assert(N<3, "template parameter N must be less than 3 for zero based indexing");
            constexpr T operator()() {
                return T();
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,0,0> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(1);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,0,1> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(0);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,0,2> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(0);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,1,0> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(0);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,1,1> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(1);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,1,2> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(0);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,2,0> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(0);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,2,1> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(0);
            }
        };

        template <typename T>
        struct CKroneckerDelta3FunctionObject<T,2,2> {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            constexpr T operator()() {
                return T(1);
            }
        };


        template <typename T, int M, int N>
        constexpr T CKroneckerDelta3() {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            static_assert(M>=0, "template parameter M must be greater than or equal to zero");
            static_assert(M<3, "template parameter M must be less than 3 for zero based indexing");
            static_assert(N>=0, "template parameter N must be greater than or equal to zero");
            static_assert(N<3, "template parameter N must be less than 3 for zero based indexing");
            return CKroneckerDelta3FunctionObject<T,M,N>(); // all specializations handled explicitly
        }



    } // namespace utilities
} // namespace mpc

#endif // MPC_KRONECKERDELTA_H
