/**
*    @file identitytensor.hpp
*    @brief function for returning the fourth rank identity tensor
* in 3-dimensional space 
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MPC_IDENTITY43_H
#define MPC_IDENTITY43_H

// blitz
#include <blitz/array.h>

#include "kroneckerdelta.hpp"

namespace mpc {
namespace util {

//template <typename T, int Rank, int Order>
//struct IdentityTensor {
//    blitz::Array<T,Rank>
//}

template <typename T>
blitz::Array<T,4> Identity43() {
    // returns the fourth rank identity tensor in 3 dimensional space
    // I(ijmn) = (1/2) * (d(i,m)d(j,n) + d(i,n)d(j,m))
    blitz::Array<T,2> kdel = mpc::util::KroneckerDelta3<T>();
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

} // namespace util
} // namespace mpc

#endif // MPC_IDENTITY43_H
