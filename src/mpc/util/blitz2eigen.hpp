#ifndef MPC_BLITZ2EIGEN_H
#define MPC_BLITZ2EIGEN_H

// eigen
#include <eigen3/Eigen/Dense>

// blitz
#include <blitz/array.h>

namespace mpc {
namespace util {

template <typename T, int M, int N, int D>
Eigen::Matrix<T,M,N> Blitz2Eigen(blitz::Array<T,D>& a) {
    // TODO: convert a D-dimensional blitz array to eigen matrix
    static_assert (D<3, "The input blitz array can be of maximum dims 2.");
    // TODO: if D==1, N or M must be 1
    Eigen::Matrix<T,M,N> emat;
    for (int m=0; m<M; ++m) {
        for (int n=0; n<N; ++n) {
            // set the values
            emat(m,n) = a(m,n);
        }
    }
    return emat;
}

} // namespace util
} // namespace mpc

#endif // MPC_BLITZ2EIGEN_H
