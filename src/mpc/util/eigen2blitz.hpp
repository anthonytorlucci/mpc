#ifndef MPC_EIGEN2BLITZ_H
#define MPC_EIGEN2BLITZ_H

#include <iostream>

// eigen
#include <Eigen/Dense>

// blitz
#include <blitz/array.h>

namespace mpc {
namespace linsys {

template <typename T, int M, int N, int D>
struct Eigen2BlitzFunctionObject {
    //
    blitz::Array<T,D> operator()(Eigen::Matrix<T,M,N>& eigenmatrixX) {}
};

template <typename T, int M, int N>
struct Eigen2BlitzFunctionObject<T,M,N,1> {
    //
    blitz::Array<T,1> operator()(Eigen::Matrix<T,M,N>& eigenmatrixX) {
        std::cout << "Eigen2Blitz<T,M,N,1> called...\n" << std::endl;
        int x;
        if (M == 1 && N != 1) { x = N; }
        else if (M != 1 && N == 1) { x = M; }
        else { /* error */ }
        blitz::Array<T,1> blitz_arrayX = blitz::Array<T,1>(x);
        for (int i=0; i<x; ++i) {
            blitz_arrayX(i) = eigenmatrixX(i);
        }
        return blitz_arrayX;
    }
};

template <typename T, int M, int N>
struct Eigen2BlitzFunctionObject<T,M,N,2> {
    //
    blitz::Array<T,2> operator()(Eigen::Matrix<T,M,N>& eigenmatrixX) {
        std::cout << "Eigen2Blitz<T,M,N,2> called...\n" << std::endl;
        //std::cout << "M : " << M << std::endl;
        //std::cout << "N : " << N << std::endl;
        blitz::Array<T,2> blitz_arrayX = blitz::Array<T,2>(M, N, blitz::ColumnMajorArray<2>());
        for (int m=0; m<M; ++m) {
            for (int n=0; n<N; ++n) {
                // set the values
                blitz_arrayX(m,n) = eigenmatrixX(m,n);
            }
        }
        std::cout << "Eigen2Blitz<T,M,N,2> out : \n" << blitz_arrayX << std::endl;
        return blitz_arrayX;
    }
};



template <typename T, int D, int M, int N>
blitz::Array<T,D> Eigen2Blitz(Eigen::Matrix<T,M,N>& emat) {
    // TODO: convert an eigen matrix to a D-dimensional blitz array
    static_assert (D<3, "The maximum number of dims is 2.");
    static_assert (D>0, "The minimum number of dims is 1.");
    // TODO: if D==1, N or M must be 1
    std::cout << "Eigen2Blitz >> D = " << D << std::endl;
    std::cout << "Eigen2Blitz M : " << M << std::endl;
    std::cout << "Eigen2Blitz N : " << N << std::endl;

    Eigen2BlitzFunctionObject<T,M,N,D> e2bfo;
    blitz::Array<T,D> a = e2bfo(emat);
    return a;

}

} // namespace linsys
} // namespace mpc

#endif // MPC_EIGEN2BLITZ_H
