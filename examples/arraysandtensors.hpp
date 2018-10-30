#ifndef ARRAYSANDTENSORS_H
#define ARRAYSANDTENSORS_H

#include <blitz/array.h>

namespace mpcexamples {

template <typename T>
blitz::Array<T,1> GetRank01ExampleTensor(int order) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    blitz::Array<T,1> a = blitz::Array<T,1>(order, blitz::ColumnMajorArray<1>());

    for (int i=0; i<order; ++i) {
        a(i) = 1.0 * (i+1);
    }
    return a;
}

template <typename T>
blitz::Array<T,2> GetRank02ExampleTensor(int order) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    blitz::Array<T,2> a = blitz::Array<T,2>(order, order, blitz::ColumnMajorArray<2>());

    T ival;
    T jval;

    for (int i=0; i<order; ++i) {
        ival = 1.0 * (i+1);
        for (int j=0; j<order; ++j) {
            jval = 0.1 * (j+1);
            a(i,j) = ival + jval;
        }
    }
    return a;
}

template <typename T>
blitz::Array<T,2> GetRank02ExampleArray(int order_dim1, int order_dim2) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // order_dim1 is the number of rows or number of elements in the first dimension
    // order_dim2 is the number of columns or number of elements in the second dimension
    blitz::Array<T,2> a = blitz::Array<T,2>(order_dim1, order_dim2, blitz::ColumnMajorArray<2>());

    for (int i=0; i<order_dim1; ++i) {
        for (int j=0; j<order_dim2; ++j) {
            a(i,j) = (1.0 * (i+1)) + (0.1 * (j+1));
        }
    }
    return a;
}

template <typename T>
blitz::Array<T,3> GetRank03ExampleTensor(int order) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // order is the number of elements in each dimension;
    // for 3D Euclidean space, order = 3, which is the most common
    blitz::Array<T,3> a = blitz::Array<T,3>(order, order, order, blitz::ColumnMajorArray<3>());

    T ival;
    T jval;
    T kval;

    for (int i=0; i<order; ++i) {
        ival = 1.0 * (i+1);
        for (int j=0; j<order; ++j) {
            jval = 0.1 * (j+1);
            for (int k=0; k<order; ++k) {
                kval = 0.01 * (k+1);
                a(i,j,k) = ival + jval + kval;
            }
        }
    }
    return a;
}

template <typename T>
blitz::Array<T,3> GetRank03ExampleArray(int order_dim1, int order_dim2, int order_dim3) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // order is the number of elements in each dimension;
    // order_dim1 corresponds to the first index, usually denoted i
    // order_dim2 corresponds to the second index, usually denoted j
    // order_dim3 corresponds to the third index, usually denoted k
    blitz::Array<T,3> a = blitz::Array<T,3>(order_dim1, order_dim2, order_dim3, blitz::ColumnMajorArray<3>());

    for (int i=0; i<order_dim1; ++i) {
        for (int j=0; j<order_dim2; ++j) {
            for (int k=0; k<order_dim3; ++k) {
                a(i,j,k) = (1.0 * (i+1)) + (0.1 * (j+1)) + (0.01 * (k+1));
            }
        }
    }
    return a;
}

template <typename T>
blitz::Array<T,4> GetRank04ExampleTensor(int order) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // order is the number of elements in each dimension;
    // for 3D Euclidean space, order = 3, which is the most common
    blitz::Array<T,4> a = blitz::Array<T,4>(order, order, order, order, blitz::ColumnMajorArray<4>());

    T ival;
    T jval;
    T kval;
    T lval;

    for (int i=0; i<order; ++i) {
        ival = 1.0 * (i+1);
        for (int j=0; j<order; ++j) {
            jval = 0.1 * (j+1);
            for (int k=0; k<order; ++k) {
                kval = 0.01 * (k+1);
                for (int l=0; l<order; ++l) {
                    lval = 0.001 * (l+1);
                    a(i,j,k,l) = ival + jval + kval + lval;
                }
            }
        }
    }
    return a;
}

template <typename T>
blitz::Array<T,5> GetRank05ExampleTensor(int order) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // order is the number of elements in each dimension;
    // for 3D Euclidean space, order = 3, which is the most common
    blitz::Array<T,5> a = blitz::Array<T,5>(order, order, order, order, blitz::ColumnMajorArray<5>());

    T ival;
    T jval;
    T kval;
    T lval;
    T mval;

    for (int i=0; i<order; ++i) {
        ival = 1.0 * (i+1);
        for (int j=0; j<order; ++j) {
            jval = 0.1 * (j+1);
            for (int k=0; k<order; ++k) {
                kval = 0.01 * (k+1);
                for (int l=0; l<order; ++l) {
                    lval = 0.001 * (l+1);
                    for (int m=0; m<order; ++m) {
                        mval = 0.0001 * (m+1);
                        a(i,j,k,l,m) = ival + jval + kval + lval + mval;
                    }
                }
            }
        }
    }
    return a;
}

template <typename T>
blitz::Array<T,6> GetRank06ExampleTensor(int order) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // order is the number of elements in each dimension;
    // for 3D Euclidean space, order = 3, which is the most common
    blitz::Array<T,6> a = blitz::Array<T,6>(order, order, order, order, blitz::ColumnMajorArray<6>());

    T ival;
    T jval;
    T kval;
    T lval;
    T mval;
    T nval;

    for (int i=0; i<order; ++i) {
        ival = 1.0 * (i+1);
        for (int j=0; j<order; ++j) {
            jval = 0.1 * (j+1);
            for (int k=0; k<order; ++k) {
                kval = 0.01 * (k+1);
                for (int l=0; l<order; ++l) {
                    lval = 0.001 * (l+1);
                    for (int m=0; m<order; ++m) {
                        mval = 0.0001 * (m+1);
                        for (int n=0; n<order; ++n) {
                            nval = 0.00001 * (n+1);
                            a(i,j,k,l,m,n) = ival + jval + kval + lval + mval + nval;
                        }
                    }
                }
            }
        }
    }
    return a;
}

// TODO: higher rank example tensors?  follow the same pattern.

}

#endif // ARRAYSANDTENSORS_H
