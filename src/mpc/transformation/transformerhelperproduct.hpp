/**
*    @file transformerhelperproduct.hpp
*    @brief specialized function objects that calculate the product
* of the transformation tensors in the transformer function object
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MPC_TRANSFORMER_HELPER_PRODUCT_H
#define MPC_TRANSFORMER_HELPER_PRODUCT_H

#include <vector>

// blitz
#include <blitz/array.h>
#include <blitz/tinyvec2.h>

// mpc

// TODO: The transformation of a tensor is a linear weighted average;  This file calculates the "weights"
// TODO: which are a product of the transformation tensor components based on the indices provided.

// NOTE: Order template parameter has been removed.  All tensors are assumed to be in 3-dimensional space.

namespace mpc {
namespace transformation {

//

/* Transformer: */
template<typename T, int Rank>
struct TransformationProduct {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,Rank> operator()(blitz::Array<T,Rank>& input_array, blitz::Array<T,2>& trans_tensor);
};

// partial specialization - 1st rank tensor

// partial specialization - 2nd rank tensor
template <typename T>
struct TransformationProduct<T,2> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j) {

        //auto num_elems = (unsigned int)(std::pow(Order, 2));  // same as number of elements in input_array
        unsigned int num_elems = 9;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                trans(counter) = trans_tensor(index_i,i) * trans_tensor(index_j, j);
                ++counter;
            }
        }
        return trans;
    }
};

// partial specialization - 3rd rank tensor
template <typename T>
struct TransformationProduct<T,3> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k) {

        //auto num_elems = (unsigned int)(std::pow(Order, 3));  // same as number of elements in input_array
        unsigned int num_elems = 27;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    trans(counter) = trans_tensor(index_i,i) * trans_tensor(index_j, j) * trans_tensor(index_k, k);
                    ++counter;
                }
            }
        }
        return trans;
    }
};

// partial specialization - 4th rank tensor
template <typename T>
struct TransformationProduct<T,4> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l) {

        //auto num_elems = (unsigned int)(std::pow(Order, 4));  // same as number of elements in input_array
        unsigned int num_elems = 81;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        trans(counter) = trans_tensor(index_i,i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l);
                        ++counter;
                    }
                }
            }
        }
        return trans;
    }
};

// partial specialization - 5th rank tensor
template <typename T>
struct TransformationProduct<T,5> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m) {

        //auto num_elems = (unsigned int)(std::pow(Order, 5));  // same as number of elements in input_array
        unsigned int num_elems = 243;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m);
                            ++counter;
                        }
                    }
                }
            }
        }
        return trans;
    }
};

// partial specialization - 6th rank tensor
template <typename T>
struct TransformationProduct<T,6> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m, int index_n) {

        //auto num_elems = (unsigned int)(std::pow(Order, 6));  // same as number of elements in input_array
        unsigned int num_elems = 729;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m) * trans_tensor(index_n, n);
                                ++counter;
                            }
                        }
                    }
                }
            }
        }
        return trans;
    }
};

// partial specialization - 7th rank tensor
template <typename T>
struct TransformationProduct<T,7> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m, int index_n, int index_p) {

        //auto num_elems = (unsigned int)(std::pow(Order, 7));  // same as number of elements in input_array
        unsigned int num_elems = 2187;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m) * trans_tensor(index_n, n) * trans_tensor(index_p, p);
                                    ++counter;
                                }
                            }
                        }
                    }
                }
            }
        }
        return trans;
    }
};

// partial specialization - 8th rank tensor
template <typename T>
struct TransformationProduct<T,8> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m, int index_n, int index_p, int index_q) {

        //auto num_elems = (unsigned int)(std::pow(Order, 8));  // same as number of elements in input_array
        unsigned int num_elems = 6561;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m) * trans_tensor(index_n, n) * trans_tensor(index_p, p) * trans_tensor(index_q, q);
                                        ++counter;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return trans;
    }
};

// partial specialization - 9th rank tensor
template <typename T>
struct TransformationProduct<T,9> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m, int index_n, int index_p, int index_q, int index_r) {

        //auto num_elems = (unsigned int)(std::pow(Order, 9));  // same as number of elements in input_array
        unsigned int num_elems = 19683;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        for (int r=0; r<3; ++r) {
                                            trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m) * trans_tensor(index_n, n) * trans_tensor(index_p, p) * trans_tensor(index_q, q) * trans_tensor(index_r, r);
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
        return trans;
    }
};

// partial specialization - 10th rank tensor
template <typename T>
struct TransformationProduct<T,10> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m, int index_n, int index_p, int index_q, int index_r, int index_s) {

        //auto num_elems = (unsigned int)(std::pow(Order, 10));  // same as number of elements in input_array
        unsigned int num_elems = 59049;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        for (int r=0; r<3; ++r) {
                                            for (int s=0; s<3; ++s) {
                                                trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m) * trans_tensor(index_n, n) * trans_tensor(index_p, p) * trans_tensor(index_q, q) * trans_tensor(index_r, r) * trans_tensor(index_s, s);
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
        return trans;
    }
};

// partial specialization - 11th rank tensor
template <typename T>
struct TransformationProduct<T,11> {
    static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    blitz::Array<T,1> operator()(blitz::Array<T,2>& trans_tensor, int index_i, int index_j, int index_k, int index_l, int index_m, int index_n, int index_p, int index_q, int index_r, int index_s, int index_t) {

        //auto num_elems = (unsigned int)(std::pow(Order, 11));  // same as number of elements in input_array
        unsigned int num_elems = 177147;
        blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems);  // the transformation product

        // the output transformation operator L is the product of the transformation tensor corresponding to the components
        int counter = 0;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        for (int r=0; r<3; ++r) {
                                            for (int s=0; s<3; ++s) {
                                                for (int t=0; t<3; ++t) {
                                                    trans(counter) = trans_tensor(index_i, i) * trans_tensor(index_j, j) * trans_tensor(index_k, k) * trans_tensor(index_l, l) * trans_tensor(index_m, m) * trans_tensor(index_n, n) * trans_tensor(index_p, p) * trans_tensor(index_q, q) * trans_tensor(index_r, r) * trans_tensor(index_s, s) * trans_tensor(index_t, t);
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
        return trans;
    }
};

// TODO: convienince functions/functors for passing in an array of indeices
// TODO: like operator()(blitz::Array<T,2>& trans_tensor, std::vector<int> indices)
// TODO: then,
// TODO:     index_i = indices[0];
// TODO:     index_j = indices[1];
// TODO:     ... etc. ...

}  // END namespace transformation
}  // END namespace mpc

#endif // MPC_TRANSFORMER_HELPER_PRODUCT_H
