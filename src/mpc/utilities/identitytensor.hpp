/**
 *    \file identitytensor.hpp
 *    \brief function for returning the fourth rank identity tensor in 3-dimensional space
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_IDENTITY43_H
#define MPC_IDENTITY43_H

// blitz
#include <blitz/array.h>

// mpc
#include "mpc/utilities/kroneckerdelta.hpp"

namespace mpc {
    namespace utilities {

        template <typename T, int Dim, int Rank>
        struct IdentityTensorFunctionObject {
            static_assert(Dim>1,"must be higher than one dimensional");
            static_assert(Rank>1, "rank must be greater than one");
//            blitz::Array<T,Rank> operator()() {
//                blitz::Array<T,Rank> id4 = blitz::Array<T,Rank>(Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<Rank>());
//                return id4;
//            }
        };

        // specializations
        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,2> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,2> operator()() {
                blitz::Array<T,2> idtensor = blitz::Array<T,2>(Dim,Dim,blitz::ColumnMajorArray<2>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,3> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,3> operator()() {
                blitz::Array<T,3> idtensor = blitz::Array<T,3>(Dim,Dim,Dim,blitz::ColumnMajorArray<3>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,4> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,4> operator()() {
                blitz::Array<T,4> idtensor = blitz::Array<T,4>(Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<4>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,5> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,5> operator()() {
                blitz::Array<T,5> idtensor = blitz::Array<T,4>(Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<5>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,6> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,6> operator()() {
                blitz::Array<T,6> idtensor = blitz::Array<T,6>(Dim,Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<6>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,7> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,7> operator()() {
                blitz::Array<T,7> idtensor = blitz::Array<T,7>(Dim,Dim,Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<7>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,8> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,8> operator()() {
                blitz::Array<T,8> idtensor = blitz::Array<T,7>(Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<8>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,9> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,9> operator()() {
                blitz::Array<T,9> idtensor = blitz::Array<T,7>(Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<9>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,10> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,10> operator()() {
                blitz::Array<T,10> idtensor = blitz::Array<T,7>(Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<10>());
                return idtensor;
            }
        };

        template <typename T, int Dim>
        struct IdentityTensorFunctionObject<T,Dim,11> {
            static_assert(Dim>1,"must be higher than one dimensional");
            blitz::Array<T,11> operator()() {
                blitz::Array<T,11> idtensor = blitz::Array<T,7>(Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,Dim,blitz::ColumnMajorArray<11>());
                return idtensor;
            }
        };

        // convenience function
        template <typename T, int Dim, int Rank>
        blitz::Array<T,Rank> IdentityTensor() {
            IdentityTensorFunctionObject<T,Dim,Rank> id_fo;
            return id_fo();
        }

        // convenience function (specialization; no if's)
        template <typename T>
        blitz::Array<T,4> IdentityTensor4_d3() {
                // returns the fourth rank identity tensor in 3 dimensional space
                // I(ijmn) = (1/2) * (d(i,m)d(j,n) + d(i,n)d(j,m))
                blitz::Array<T,2> kdel = mpc::utilities::KroneckerDelta<T,3>();
                blitz::Array<T,4> id4 = blitz::Array<T,4>(3,3,3,3,blitz::ColumnMajorArray<4>());
                for (int i=0; i<3; ++i) {
                        for (int j=0; j<3; ++j) {
                                for (int m=0; m<3; ++m) {
                                        for (int n=0; n<3; ++n) {
                                                id4(i,j,m,n) = 0.5 * ((kdel(i,m)*kdel(j,n)) + (kdel(i,n)*kdel(j,m)));
                                        }
                                }
                        }
                }
        }

    } // namespace utilities
} // namespace mpc

#endif // MPC_IDENTITY43_H
