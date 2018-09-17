/**
 *    \file transformer.hpp
 *    \brief function object that transforms a tensor given an input tensor of
 * rank N and a transformation tensor of rank 2
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef MPC_TRANSFORMER_H
#define MPC_TRANSFORMER_H

#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

// blitz
#include <blitz/array.h>
#include <blitz/tinyvec2.h>

// mpc
#include "../util/innerproductor.hpp"
#include "../util/unwrapper.hpp"
#include "../transformation/transformerhelperpermutations.hpp"
#include "../transformation/transformerhelperproduct.hpp"


// TODO: This file provides a template function object for transforming tensor components
// TODO: given the tensor and a second rank transformation tensor.

namespace mpc {
namespace transformation {

// TODO: template <typename T, int Rank, int Order>
//struct Transformer {}

// template <typename T, int Rank>
// using Transformer1D<T,Rank,1>

// template <typename T, int Rank>
// using Transformer2D<T,Rank,2>

// template <typename T, int Rank>
// using Transformer3D<T,Rank,3>


/* ========================================================================   */
/* ========================================================================   */
/* ========================================================================   */

/* Transformer: */
template<typename T, int Rank>
struct Transformer {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,Rank> operator()(blitz::Array<T,Rank>& input_array, blitz::Array<T,2>& trans_tensor);
};

// partial specialization - first rank tensor
template <typename T>
struct Transformer<T,1> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,1> operator()(blitz::Array<T,1>& input_array, blitz::Array<T,2>& trans_tensor) {
                blitz::TinyVector<T,1> ishp = input_array.shape(); // shape of the input array
                blitz::Array<T,1> output_array = blitz::Array<T,1>(ishp);

                auto num_weights = (unsigned int)(std::pow(3, 1));
                std::vector<int> i_permutations =  std::vector<int>(num_weights);
                permutations_for_linear_transformations(i_permutations);
                blitz::Array<T,1> trans = blitz::Array<T,1>(num_weights); // transformation weights for each component
                mpc::util::InnerProductor<T,1> iprod;

                // start the rotation
                for (int i=0; i<3; ++i) {
                        trans = trans_tensor(i, blitz::Range::all());
                        output_array(i) = iprod(input_array, trans); // TODO: unwrap input_array to 1D
                }
                return output_array;
        }

};

// partial specialization - 2nd rank tensor
template <typename T>
struct Transformer<T,2> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,2> operator()(blitz::Array<T,2>& input_array, blitz::Array<T,2>& trans_tensor) {
                blitz::TinyVector<T,2> ishp = input_array.shape(); // shape of the input array
                blitz::Array<T,2> output_array = blitz::Array<T,2>(ishp);

                //auto num_weights = (unsigned int)(std::pow(Order, 2));  // same as number of elements in input_array
                auto num_elems = input_array.numElements();

                // reshape input array
                mpc::util::Unwrapper<T,2> Unwrapper2;
                blitz::Array<T,1> unwrapped = Unwrapper2(input_array);
                // for DEBUGing purposes
                //std::cout << "unwrapped: " << unwrapped << std::endl;

                // permutations
                std::vector<int> i_permutations = std::vector<int>(num_elems);
                std::vector<int> j_permutations = std::vector<int>(num_elems);
                permutations_for_linear_transformations(i_permutations, j_permutations);
                // transformation product
                TransformationProduct<T,2> TransformationProduct2;
                blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems); // the transformation product
                //
                mpc::util::InnerProductor<T,1> InnerProductor1;

                // start the rotation
                for (int num=0; num<num_elems; ++num) {
                        trans = TransformationProduct2(trans_tensor, i_permutations[num], j_permutations[num]);
                        T tmp = InnerProductor1(unwrapped, trans);
                        //std::cout << "inner product: " << num << " : " << tmp << std::endl;
                        output_array(i_permutations[num], j_permutations[num]) = tmp; // a transformation is a weighted average!
                }
                return output_array;
        }

};

// partial specialization - 3nd rank tensor
template <typename T>
struct Transformer<T,3> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,3> operator()(blitz::Array<T,3>& input_array, blitz::Array<T,2>& trans_tensor) {
                blitz::TinyVector<T,3> ishp = input_array.shape(); // shape of the input array
                blitz::Array<T,3> output_array = blitz::Array<T,3>(ishp);

                //auto num_weights = (unsigned int)(std::pow(Order, 3));  // same as number of elements in input_array
                auto num_elems = input_array.numElements();

                // reshape input array
                mpc::util::Unwrapper<T,3> Unwrapper3;
                blitz::Array<T,1> unwrapped = Unwrapper3(input_array);
                // for DEBUGing purposes
                //std::cout << "unwrapped: " << unwrapped << std::endl;

                // permutations
                std::vector<int> i_permutations = std::vector<int>(num_elems);
                std::vector<int> j_permutations = std::vector<int>(num_elems);
                std::vector<int> k_permutations = std::vector<int>(num_elems);
                permutations_for_linear_transformations(i_permutations, j_permutations, k_permutations);
                // transformation product
                TransformationProduct<T,3> TransformationProduct3;
                blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems); // the transformation product
                //
                mpc::util::InnerProductor<T,1> InnerProduct1;

                // start the rotation
                for (int num=0; num<num_elems; ++num) {
                        trans = TransformationProduct3(trans_tensor, i_permutations[num], j_permutations[num], k_permutations[num]);
                        T tmp = InnerProduct1(unwrapped, trans);
                        //std::cout << "inner product: " << num << " : " << tmp << std::endl;
                        output_array(i_permutations[num], j_permutations[num], k_permutations[num]) = tmp; // a transformation is a weighted average!
                }
                return output_array;
        }

};

// partial specialization - 4th rank tensor
template <typename T>
struct Transformer<T,4> {
        static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        blitz::Array<T,4> operator()(blitz::Array<T,4>& input_array, blitz::Array<T,2>& trans_tensor) {
                blitz::TinyVector<T,4> ishp = input_array.shape(); // shape of the input array
                blitz::Array<T,4> output_array = blitz::Array<T,4>(ishp);

                //auto num_weights = (unsigned int)(std::pow(Order, 3));  // same as number of elements in input_array
                auto num_elems = input_array.numElements();

                // reshape input array
                mpc::util::Unwrapper<T,4> Unwrapper4;
                blitz::Array<T,1> unwrapped = Unwrapper4(input_array);
                // for DEBUGing purposes
                //std::cout << "unwrapped: " << unwrapped << std::endl;

                // permutations
                std::vector<int> i_permutations = std::vector<int>(num_elems);
                std::vector<int> j_permutations = std::vector<int>(num_elems);
                std::vector<int> k_permutations = std::vector<int>(num_elems);
                std::vector<int> l_permutations = std::vector<int>(num_elems);
                permutations_for_linear_transformations(i_permutations, j_permutations, k_permutations, l_permutations);
                // transformation product
                TransformationProduct<T,4> TransformationProduct4;
                blitz::Array<T,1> trans = blitz::Array<T,1>(num_elems); // the transformation product
                //
                mpc::util::InnerProductor<T,1> InnerProductor1;

                // start the rotation
                for (int num=0; num<num_elems; ++num) {
                        trans = TransformationProduct4(trans_tensor, i_permutations[num], j_permutations[num], k_permutations[num], l_permutations[num]);
                        T tmp = InnerProductor1(unwrapped, trans);
                        //std::cout << "inner product: " << num << " : " << tmp << std::endl;
                        output_array(i_permutations[num], j_permutations[num], k_permutations[num], l_permutations[num]) = tmp; // a transformation is a weighted average!
                }
                return output_array;
        }

};

// TODO: partial specilization for ranks 5 through 11
}  // namespace transformation
}  // namespace mpc

#endif // MPC_TRANSFORMER_H
