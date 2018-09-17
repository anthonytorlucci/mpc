/**
 *    @file unwrapper.hpp
 *    @brief function object that "unwraps" a multi-dimenional array into
 * a single one-dimensional array; used by transformer function object
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_UNWRAPPER_H
#define MPC_UNWRAPPER_H

#include <iostream>
#include <vector>
#include <list>

//blitz
#include <blitz/array.h>

namespace mpc {
namespace util {

// NOTE: this function object assumes the indices of the arrays start at zero!!!
// TODO: add assert index for each dim starts at zero; if not modify start value in for loop

template<typename T, int N>
struct Unwrapper {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,N>& input_array);
};

// partial specialization - rank 2
template<typename T>
struct Unwrapper<T,2> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,2>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,2> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                output_array(counter) = input_array(i,j);
                                ++counter;
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 3
template<typename T>
struct Unwrapper<T,3> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,3>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,3> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        output_array(counter) = input_array(i,j,k);
                                        ++counter;
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 4
template<typename T>
struct Unwrapper<T,4> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,4>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,4> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                output_array(counter) = input_array(i,j,k,l);
                                                ++counter;
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 5
template<typename T>
struct Unwrapper<T,5> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,5>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,5> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        output_array(counter) = input_array(i,j,k,l,m);
                                                        ++counter;
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 6
template<typename T>
struct Unwrapper<T,6> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,6>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,6> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        for (int n=0; n<shp(5); ++n) {
                                                                output_array(counter) = input_array(i,j,k,l,m,n);
                                                                ++counter;
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 7
template<typename T>
struct Unwrapper<T,7> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,7>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,7> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        for (int n=0; n<shp(5); ++n) {
                                                                for (int p=0; p<shp(6); ++p) {
                                                                        output_array(counter) = input_array(i,j,k,l,m,n,p);
                                                                        ++counter;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 8
template<typename T>
struct Unwrapper<T,8> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,8>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,8> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        for (int n=0; n<shp(5); ++n) {
                                                                for (int p=0; p<shp(6); ++p) {
                                                                        for (int q=0; q<shp(7); ++q) {
                                                                                output_array(counter) = input_array(i,j,k,l,m,n,p,q);
                                                                                ++counter;
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 9
template<typename T>
struct Unwrapper<T,9> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,9>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,9> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        for (int n=0; n<shp(5); ++n) {
                                                                for (int p=0; p<shp(6); ++p) {
                                                                        for (int q=0; q<shp(7); ++q) {
                                                                                for (int r=0; r<shp(8); ++r) {
                                                                                        output_array(counter) = input_array(i,j,k,l,m,n,p,q,r);
                                                                                        ++counter;
                                                                                }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 10
template<typename T>
struct Unwrapper<T,10> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,10>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,10> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        for (int n=0; n<shp(5); ++n) {
                                                                for (int p=0; p<shp(6); ++p) {
                                                                        for (int q=0; q<shp(7); ++q) {
                                                                                for (int r=0; r<shp(8); ++r) {
                                                                                        for (int s=0; s<shp(9); ++s) {
                                                                                                output_array(counter) = input_array(i,j,k,l,m,n,p,q,r,s);
                                                                                                ++counter;
                                                                                        }
                                                                                }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

// partial specialization - rank 11
template<typename T>
struct Unwrapper<T,11> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,11>& input_array) {
                auto num_elems = input_array.numElements();
                blitz::TinyVector<int,11> shp = input_array.shape();
                blitz::Array<T,1> output_array = blitz::Array<T,1>(num_elems);

                int counter = 0;
                for (int i=0; i<shp(0); ++i) {
                        for (int j=0; j<shp(1); ++j) {
                                for (int k=0; k<shp(2); ++k) {
                                        for (int l=0; l<shp(3); ++l) {
                                                for (int m=0; m<shp(4); ++m) {
                                                        for (int n=0; n<shp(5); ++n) {
                                                                for (int p=0; p<shp(6); ++p) {
                                                                        for (int q=0; q<shp(7); ++q) {
                                                                                for (int r=0; r<shp(8); ++r) {
                                                                                        for (int s=0; s<shp(9); ++s) {
                                                                                                for (int t=0; t<shp(10); ++t) {
                                                                                                        output_array(counter) = input_array(i,j,k,l,m,n,p,q,r,s,t);
                                                                                                        ++counter;
                                                                                                }
                                                                                        }
                                                                                }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return output_array;
        }
};

}  // END NAMESPACE ROTATION
}  // END NAMESPACE MPC

#endif // MPC_UNWRAPPER_H
