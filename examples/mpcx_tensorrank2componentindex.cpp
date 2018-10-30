#include "mpcx_tensorrank2componentindex.hpp"

// c++
#include <iostream>
#include <iomanip>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/core/tensorcomponentindex.hpp>
#include <mpc/core/tensorcomponentindexaliases.hpp>
#include <mpc/core/tensorcomponentindexpredicates.hpp>

// mpcexamples
#include "parametervaluetest.hpp"

void mpcexamples::mpcTensorRank2ComponentIndex() {
    // --------------------------------------------------------------

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::core::TensorRankNComponentIndex<2> index00 = mpc::core::TensorRankNComponentIndex<2>(0,0);
    std::cout << "index(0,0) : " << index00 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index01 = mpc::core::TensorRankNComponentIndex<2>(0,1);
    std::cout << "index(0,1) : " << index01 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index02 = mpc::core::TensorRankNComponentIndex<2>(0,2);
    std::cout << "index(0,2) : " << index02 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index10 = mpc::core::TensorRankNComponentIndex<2>(1,0);
    std::cout << "index(1,0) : " << index10 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index11 = mpc::core::TensorRankNComponentIndex<2>(1,1);
    std::cout << "index(1,1) : " << index11 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index12 = mpc::core::TensorRankNComponentIndex<2>(1,2);
    std::cout << "index(1,2) : " << index12 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index20 = mpc::core::TensorRankNComponentIndex<2>(2,0);
    std::cout << "index(2,0) : " << index20 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index21 = mpc::core::TensorRankNComponentIndex<2>(2,1);
    std::cout << "index(2,1) : " << index21 << std::endl;
    mpc::core::TensorRankNComponentIndex<2> index22 = mpc::core::TensorRankNComponentIndex<2>(2,2);
    std::cout << "index(2,2) : " << index22 << std::endl;

    std::vector<mpc::core::TensorRank2ComponentIndex> vec_indexXX{
            index00,
            index01,
            index02,
            index10,
            index11,
            index12,
            index20,
            index21,
            index22
    };

    /*
    * A tensor component index of rank 2 has two member functions defined in
    *     the class: FirstIndex() and SecondIndex() which retrieve the index
    *     values from the first index and the second index, respectively.
    *     These are also constexpr functions and can be called at compile time
    *     and therefore known to the compiler and can be used in other
    *     constexpr functions, but NOT as template parameter values.
    */
    int first_indexXX;
    int second_indexXX;
    for (auto indexXX : vec_indexXX) {
        first_indexXX = indexXX.FirstIndex();
        std::cout << indexXX << " FirstIndex() :  " << first_indexXX << std::endl;
        second_indexXX = indexXX.SecondIndex();
        std::cout << indexXX << " SecondIndex() : " << second_indexXX << std::endl;
    }

    /*
    * NOTE: constexpr can be used like any other function at runtime...
    *
    * In addition, there are four non-member functions that overload the
    *     operators "==", "!=", "<", and ">" for comparison.  The less than
    *     and greater than operators don't really make sense for an index, but
    *     are necessary because std::less<Key> is the default comparson
    *     operator used in std::set<>, an STL container used ubiquitously
    *     throughout the MPC library.  Therefore, MPC defines index ordering
    *     as:
    *
    *     00 < 01 < 02 < 10 < 11 < 12 < 20 < 21 < 22
    */

    std::cout << "" << std::endl;
    for (auto indexXX : vec_indexXX) {
        std::cout << indexXX << " == " << index11 << " : " << (indexXX == index11) << std::endl;
        std::cout << indexXX << " != " << index11 << " : " << (indexXX != index11) << std::endl;
        std::cout << indexXX << " <  " << index11 << " : " << (indexXX < index11) << std::endl;
        std::cout << indexXX << " >  " << index11 << " : " << (indexXX > index11) << std::endl;
        std::cout << indexXX << " <= " << index11 << " : " << (indexXX <= index11) << std::endl;
        std::cout << indexXX << " >= " << index11 << " : " << (indexXX >= index11) << std::endl;
    }

    /*
    * TensorRankNComponentIndex<2> also provides an inline function to return
    *     the index value using the subscript operator.
    */

    std::cout << "" << std::endl;
    std::cout << index00 << " index using operator [0] : " << index00[0] << std::endl;
    std::cout << index00 << " index using operator [1] : " << index00[1] << std::endl;
    std::cout << index01 << " index using operator [0] : " << index01[0] << std::endl;
    std::cout << index01 << " index using operator [1] : " << index01[1] << std::endl;
    std::cout << index02 << " index using operator [0] : " << index02[0] << std::endl;
    std::cout << index02 << " index using operator [1] : " << index02[1] << std::endl;
    std::cout << index10 << " index using operator [0] : " << index10[0] << std::endl;
    std::cout << index10 << " index using operator [1] : " << index10[1] << std::endl;
    std::cout << index11 << " index using operator [0] : " << index11[0] << std::endl;
    std::cout << index11 << " index using operator [1] : " << index11[1] << std::endl;
    std::cout << index12 << " index using operator [0] : " << index12[0] << std::endl;
    std::cout << index12 << " index using operator [1] : " << index12[1] << std::endl;
    std::cout << index20 << " index using operator [0] : " << index20[0] << std::endl;
    std::cout << index20 << " index using operator [1] : " << index20[1] << std::endl;
    std::cout << index21 << " index using operator [0] : " << index21[0] << std::endl;
    std::cout << index21 << " index using operator [1] : " << index21[1] << std::endl;
    std::cout << index22 << " index using operator [0] : " << index22[0] << std::endl;
    std::cout << index22 << " index using operator [1] : " << index22[1] << std::endl;

    /*
    * MPC provides an alias for the second rank tensor component index with
    *     the using directive:
    *
    *     using TensorRank2ComponentIndex = TensorRankNComponentIndex<2>;
    */

    std::cout << "" << std::endl;
    std::cout << "index(0,0) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(0,0) << std::endl;
    std::cout << "index(0,1) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(0,1) << std::endl;
    std::cout << "index(0,2) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(0,2) << std::endl;
    std::cout << "index(1,0) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(1,0) << std::endl;
    std::cout << "index(1,1) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(1,1) << std::endl;
    std::cout << "index(1,2) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(1,2) << std::endl;
    std::cout << "index(2,0) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(2,0) << std::endl;
    std::cout << "index(2,1) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(2,1) << std::endl;
    std::cout << "index(2,2) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(2,2) << std::endl;

    /*
         * Since the underlying data structure for mpc is blitz, it is often
         *     convenient to insert a value into the tensor member variable using
         *     blitz::TinyVector<> to refer to the index from the
         *     mpc::core::TensorRankNComponent<>.  The TensorRankNComponentIndex<N>
         *     class provides a static member function to do just this...
         */

    std::cout << "" << std::endl;
    blitz::TinyVector<int,2> blitz_index00 = mpc::core::TensorRankNComponentIndex<2>::ToBlitzTinyVector(index00);
    std::cout << "TinyVector blitz_index00 : " << blitz_index00 << std::endl;

    blitz::TinyVector<int,2> blitz_index01 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index01);
    std::cout << "TinyVector blitz_index01 : " << blitz_index01 << std::endl;

    blitz::TinyVector<int,2> blitz_index02 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index02);
    std::cout << "TinyVector blitz_index02 : " << blitz_index02 << std::endl;

    blitz::TinyVector<int,2> blitz_index10 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index10);
    std::cout << "TinyVector blitz_index10 : " << blitz_index10 << std::endl;

    blitz::TinyVector<int,2> blitz_index11 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index11);
    std::cout << "TinyVector blitz_index11 : " << blitz_index11 << std::endl;

    blitz::TinyVector<int,2> blitz_index12 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index12);
    std::cout << "TinyVector blitz_index12 : " << blitz_index12 << std::endl;

    blitz::TinyVector<int,2> blitz_index20 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index20);
    std::cout << "TinyVector blitz_index20 : " << blitz_index20 << std::endl;

    blitz::TinyVector<int,2> blitz_index21 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index21);
    std::cout << "TinyVector blitz_index21 : " << blitz_index21 << std::endl;

    blitz::TinyVector<int,2> blitz_index22 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index22);
    std::cout << "TinyVector blitz_index22 : " << blitz_index22 << std::endl;

    /*
    * The index itself is very powerful.  Two additional functions are defined
    *     to get the number of aliases and the aliases themselves.  For a
    *     second rank tensor aliases are defined as the symmetrical components.
    *     That is to say, A(i,j) = A(j,i), and thus the nine components of a
    *     second rank tensor in 3 dimensional space reduces to just 6...
    *
    * Definition of aliases in mpc for a second rank symmetrical tensor
    *     a(i,j) = a(j,i)
    *     X00 >> (11)
    *     X01 >> (01), (10)
    *     X02 >> (02), (20)
    *     X10 >> (01), (10)
    *     X11 >> (22)
    *     X12 >> (12), (21)
    *     X20 >> (02), (20)
    *     X21 >> (12), (21)
    *     X22 >> (22)
    *
    * The index themselves are very useful.  Let's combine them in a
    *     std::set<> which itself is powerful tool and has some interesting
    *     properties and algorithms.  The next section illustrates useful
    *     functions that take advantage of these properties and algorithms.
    *     Why use std::set<> and not std::vector<>?  A set will automatically
    *     check if the value being inserted is already present.  We want all
    *     components in a set to be unique becauase they map to one and only
    *     one component in the actual tensor...
    *
    * Some useful algorithms in the STL library for std::set<> are:
    *     >> includes()
    *     >> set_union()
    *     >> set_intersection()
    *     >> set_difference()
    *     >> set_symmetrical_difference()
    *         (see Stroustrup, 2013, The C++ Programming Language, fourth ed.,  p. 947)
    *
    * Note that the values in a set are ordered. Set tests for equality
    *     with another element already in the set using std::less<Key>.  An
    *     index has no natrual order, but MPC defines it like this
    *
    *         00 < 01 < 02 < 10 < 11 < 12 < 20 < 21 < 22
    *
    *     Containers of TensorRankNComponentIndex<N> can now be sorted or
    *         stored in ordered containers like std::set<>.
    */

    std::cout << "" << std::endl;

    int num_aliases00 = mpc::core::TensorRank2IndexNumberOfAliases(index00);
    std::cout << "number of aliases for index00 : " << num_aliases00 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases00 = mpc::core::TensorRank2IndexAliases(index00); // no aliases
    for (auto alias : set_aliases00) {
        std::cout << "rank2 alias of 00 : " << alias << std::endl;
    }

    int num_aliases01 = mpc::core::TensorRank2IndexNumberOfAliases(index01);
    std::cout << "number of aliases for index01 : " << num_aliases01 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases01 = mpc::core::TensorRank2IndexAliases(index01);
    for (auto alias : set_aliases01) {
        std::cout << "rank2 alias of 01 : " << alias << std::endl;
    }

    int num_aliases02 = mpc::core::TensorRank2IndexNumberOfAliases(index02);
    std::cout << "number of aliases for index02 : " << num_aliases02 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases02 = mpc::core::TensorRank2IndexAliases(index02);
    for (auto alias : set_aliases02) {
        std::cout << "rank2 alias of 02 : " << alias << std::endl;
    }

    int num_aliases10 = mpc::core::TensorRank2IndexNumberOfAliases(index10);
    std::cout << "number of aliases for index10 : " << num_aliases10 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases10 = mpc::core::TensorRank2IndexAliases(index10);
    for (auto alias : set_aliases10) {
        std::cout << "rank2 alias of 10 : " << alias << std::endl;
    }

    int num_aliases11 = mpc::core::TensorRank2IndexNumberOfAliases(index11);
    std::cout << "number of aliases for index11 : " << num_aliases11 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases11 = mpc::core::TensorRank2IndexAliases(index11);
    for (auto alias : set_aliases11) {
        std::cout << "rank2 alias of 11 : " << alias << std::endl;
    }

    int num_aliases12 = mpc::core::TensorRank2IndexNumberOfAliases(index12);
    std::cout << "number of aliases for index12 : " << num_aliases12 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases12 = mpc::core::TensorRank2IndexAliases(index12);
    for (auto alias : set_aliases12) {
        std::cout << "rank2 alias of 12 : " << alias << std::endl;
    }

    int num_aliases20 = mpc::core::TensorRank2IndexNumberOfAliases(index20);
    std::cout << "number of aliases for index20 : " << num_aliases20 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases20 = mpc::core::TensorRank2IndexAliases(index20);
    for (auto alias : set_aliases20) {
        std::cout << "rank2 alias of 20 : " << alias << std::endl;
    }

    int num_aliases21 = mpc::core::TensorRank2IndexNumberOfAliases(index21);
    std::cout << "number of aliases for index21 : " << num_aliases21 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases21 = mpc::core::TensorRank2IndexAliases(index21);
    for (auto alias : set_aliases21) {
        std::cout << "rank2 alias of 21 : " << alias << std::endl;
    }

    int num_aliases22 = mpc::core::TensorRank2IndexNumberOfAliases(index22);
    std::cout << "number of aliases for index22 : " << num_aliases22 << std::endl;
    std::set<mpc::core::TensorRank2ComponentIndex> set_aliases22 = mpc::core::TensorRank2IndexAliases(index22);
    for (auto alias : set_aliases22) {
        std::cout << "rank2 alias of 22 : " << alias << std::endl;
    }

    /*
    * predicates for tensor rank2 index
    *
    * Currently, MPC provides two predicates (callable that returns a value
    *     testable as a bool; see
    *     https://en.cppreference.com/w/cpp/named_req/Predicate) for
    *     TensorRankNCompoentIndex<> where N is either 2 or 4: ...IsAlias(...)
    *     and ...HasAlias(...).  The definiton of aliases is defined by
    *     symmetry...
    */

    std::cout << "" << std::endl;

    bool indexXX_has_alias;
    bool indexXX_is_alias_indexXX;

    for (auto indexXX : vec_indexXX) {
        indexXX_has_alias = mpc::core::TensorRank2ComponentIndexHasAlias(indexXX);
        std::cout << indexXX << " index has alias ? : " << indexXX_has_alias << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index00);
        std::cout << indexXX << " is_alias " << index00 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index01);
        std::cout << indexXX << " is_alias " << index01 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index02);
        std::cout << indexXX << " is_alias " << index02 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index10);
        std::cout << indexXX << " is_alias " << index10 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index12);
        std::cout << indexXX << " is_alias " << index12 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index20);
        std::cout << indexXX << " is_alias " << index20 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index21);
        std::cout << indexXX << " is_alias " << index21 << " ? " << indexXX_is_alias_indexXX << std::endl;
        indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index22);
        std::cout << indexXX << " is_alias " << index22 << " ? " << indexXX_is_alias_indexXX << std::endl;
    }

    std::cout << "" << std::endl;
    mpc::core::TensorRank2ComponentIndex index00_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index00);
    std::cout << "index00 reduced : " << index00_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index01_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index01);
    std::cout << "index01 reduced : " << index01_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index02_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index02);
    std::cout << "index02 reduced : " << index02_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index10_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index10);
    std::cout << "index10 reduced : " << index10_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index11_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index11);
    std::cout << "index11 reduced : " << index11_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index12_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index12);
    std::cout << "index12 reduced : " << index12_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index20_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index20);
    std::cout << "index20 reduced : " << index20_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index21_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index21);
    std::cout << "index21 reduced : " << index21_reduced << std::endl;
    mpc::core::TensorRank2ComponentIndex index22_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index22);
    std::cout << "index22 reduced : " << index22_reduced << std::endl;

    /*
         * Now for the fun stuff!  MPC relies heavily on template specializations
         *     and uses compile-time computations to achieve optimization and (in
         *     my opinion equally important) error handling using the c++ type
         *     system...
         * The preferred method for creating component indexes is to use the
         *     templated form prefixed by the letter C; the major difference is
         *     that the member functions that retieve the index values CAN be used
         *     as template parameter values and therefore can be used for
         *     compile-time computation or compile-time optimization via selection
         *     in the form of user-defined specialization...
         */

    std::cout << "" << std::endl;
    mpc::core::CTensorRank2ComponentIndex<0,0> cindex00 = mpc::core::CTensorRank2ComponentIndex<0,0>();
    auto ctest00 = mpcexamples::IntTypeParameterValueTest<cindex00.FirstIndex()>();
    std::cout << "ctest00 FirstIndex() : " << ctest00 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<0,1> cindex01 = mpc::core::CTensorRank2ComponentIndex<0,1>();
    auto ctest01 = mpcexamples::IntTypeParameterValueTest<cindex01.FirstIndex()>();
    std::cout << "ctest01 FirstIndex() : " << ctest01 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<0,2> cindex02 = mpc::core::CTensorRank2ComponentIndex<0,2>();
    auto ctest02 = mpcexamples::IntTypeParameterValueTest<cindex02.FirstIndex()>();
    std::cout << "ctest02 FirstIndex() : " << ctest02 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<1,0> cindex10 = mpc::core::CTensorRank2ComponentIndex<1,0>();
    auto ctest10 = mpcexamples::IntTypeParameterValueTest<cindex10.FirstIndex()>();
    std::cout << "ctest10 FirstIndex() : " << ctest10 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<1,1> cindex11 = mpc::core::CTensorRank2ComponentIndex<1,1>();
    auto ctest11 = mpcexamples::IntTypeParameterValueTest<cindex11.FirstIndex()>();
    std::cout << "ctest11 FirstIndex() : " << ctest11 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<1,2> cindex12 = mpc::core::CTensorRank2ComponentIndex<1,2>();
    auto ctest12 = mpcexamples::IntTypeParameterValueTest<cindex12.FirstIndex()>();
    std::cout << "ctest12 FirstIndex() : " << ctest12 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<2,0> cindex20 = mpc::core::CTensorRank2ComponentIndex<2,0>();
    auto ctest20 = mpcexamples::IntTypeParameterValueTest<cindex20.FirstIndex()>();
    std::cout << "ctest20 FirstIndex() : " << ctest20 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<2,1> cindex21 = mpc::core::CTensorRank2ComponentIndex<2,1>();
    auto ctest21 = mpcexamples::IntTypeParameterValueTest<cindex21.FirstIndex()>();
    std::cout << "ctest21 FirstIndex() : " << ctest21 << std::endl;

    mpc::core::CTensorRank2ComponentIndex<2,2> cindex22 = mpc::core::CTensorRank2ComponentIndex<2,2>();
    auto ctest22 = mpcexamples::IntTypeParameterValueTest<cindex22.FirstIndex()>();
    std::cout << "ctest22 FirstIndex() : " << ctest22 << std::endl;

    /*
    * overloaded operators
    */
    std::cout << "" << std::endl;

    // I=0, J=0
    std::cout << "cindex : " << cindex00 << " == " << cindex11 << " : " << (cindex00 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex00 << " != " << cindex11 << " : " << (cindex00 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex00 << " <  " << cindex11 << " : " << (cindex00 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex00 << " >  " << cindex11 << " : " << (cindex00 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex00 << " <= " << cindex11 << " : " << (cindex00 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex00 << " >= " << cindex11 << " : " << (cindex00 >= cindex11) << std::endl;

    // I=0, J=1
    std::cout << "cindex : " << cindex01 << " == " << cindex11 << " : " << (cindex01 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex01 << " != " << cindex11 << " : " << (cindex01 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex01 << " <  " << cindex11 << " : " << (cindex01 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex01 << " >  " << cindex11 << " : " << (cindex01 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex01 << " <= " << cindex11 << " : " << (cindex01 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex01 << " >= " << cindex11 << " : " << (cindex01 >= cindex11) << std::endl;

    // I=0, J=2
    std::cout << "cindex : " << cindex02 << " == " << cindex11 << " : " << (cindex02 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex02 << " != " << cindex11 << " : " << (cindex02 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex02 << " <  " << cindex11 << " : " << (cindex02 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex02 << " >  " << cindex11 << " : " << (cindex02 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex02 << " <= " << cindex11 << " : " << (cindex02 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex02 << " >= " << cindex11 << " : " << (cindex02 >= cindex11) << std::endl;

    // I=1, J=0
    std::cout << "cindex : " << cindex10 << " == " << cindex11 << " : " << (cindex10 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex10 << " != " << cindex11 << " : " << (cindex10 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex10 << " <  " << cindex11 << " : " << (cindex10 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex10 << " >  " << cindex11 << " : " << (cindex10 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex10 << " <= " << cindex11 << " : " << (cindex10 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex10 << " >= " << cindex11 << " : " << (cindex10 >= cindex11) << std::endl;

    // I=1, J=1
    std::cout << "cindex : " << cindex11 << " == " << cindex11 << " : " << (cindex11 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex11 << " != " << cindex11 << " : " << (cindex11 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex11 << " <  " << cindex11 << " : " << (cindex11 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex11 << " >  " << cindex11 << " : " << (cindex11 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex11 << " <= " << cindex11 << " : " << (cindex11 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex11 << " >= " << cindex11 << " : " << (cindex11 >= cindex11) << std::endl;

    // I=1, J=2
    std::cout << "cindex : " << cindex12 << " == " << cindex11 << " : " << (cindex12 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex12 << " != " << cindex11 << " : " << (cindex12 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex12 << " <  " << cindex11 << " : " << (cindex12 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex12 << " >  " << cindex11 << " : " << (cindex12 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex12 << " <= " << cindex11 << " : " << (cindex12 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex12 << " >= " << cindex11 << " : " << (cindex12 >= cindex11) << std::endl;

    // I=2, J=0
    std::cout << "cindex : " << cindex20 << " == " << cindex11 << " : " << (cindex20 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex20 << " != " << cindex11 << " : " << (cindex20 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex20 << " <  " << cindex11 << " : " << (cindex20 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex20 << " >  " << cindex11 << " : " << (cindex20 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex20 << " <= " << cindex11 << " : " << (cindex20 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex20 << " >= " << cindex11 << " : " << (cindex20 >= cindex11) << std::endl;

    // I=2, J=1
    std::cout << "cindex : " << cindex21 << " == " << cindex11 << " : " << (cindex21 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex21 << " != " << cindex11 << " : " << (cindex21 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex21 << " <  " << cindex11 << " : " << (cindex21 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex21 << " >  " << cindex11 << " : " << (cindex21 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex21 << " <= " << cindex11 << " : " << (cindex21 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex21 << " >= " << cindex11 << " : " << (cindex21 >= cindex11) << std::endl;

    // I=2, J=2
    std::cout << "cindex : " << cindex22 << " == " << cindex11 << " : " << (cindex22 == cindex11) << std::endl;
    std::cout << "cindex : " << cindex22 << " != " << cindex11 << " : " << (cindex22 != cindex11) << std::endl;
    std::cout << "cindex : " << cindex22 << " <  " << cindex11 << " : " << (cindex22 < cindex11) << std::endl;
    std::cout << "cindex : " << cindex22 << " >  " << cindex11 << " : " << (cindex22 > cindex11) << std::endl;
    std::cout << "cindex : " << cindex22 << " <= " << cindex11 << " : " << (cindex22 <= cindex11) << std::endl;
    std::cout << "cindex : " << cindex22 << " >= " << cindex11 << " : " << (cindex22 >= cindex11) << std::endl;

    /*
    * Below are expressions that are constexpr and can be used as template
    *     value parameters as shown.  TODO: these have been temporarily removed
    *     until the 4th rank tensor equivalents are completed and tested...
    */
//    std::cout << "" << std::endl;
//    //                 CTensorRank2IndexNumberOfAliases<2,2>()
//    const int cnum_aliases_c00 = mpc::core::CTensorRank2IndexNumberOfAliases<cindex00.FirstIndex(),cindex00.SecondIndex()>();
//    std::cout << "cnum_aliases_c00 : " << cnum_aliases_c00 << std::endl;
//    auto ctest_num_aliases_c00 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<0,0>()>();
//    const int cnum_aliases_c01 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex01.FirstIndex(),cindex01.SecondIndex()>();
//    std::cout << "cnum_aliases_c01 : " << cnum_aliases_c01 << std::endl;
//    auto ctest_num_aliases_c01 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<0,1>()>();
//    const int cnum_aliases_c02 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex02.FirstIndex(),cindex02.SecondIndex()>();
//    std::cout << "cnum_aliases_c02 : " << cnum_aliases_c02 << std::endl;
//    auto ctest_num_aliases_c02 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<0,2>()>();
//
//    const int cnum_aliases_c10 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex10.FirstIndex(),cindex10.SecondIndex()>();
//    std::cout << "cnum_aliases_c10 : " << cnum_aliases_c10 << std::endl;
//    auto ctest_num_aliases_c10 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<1,0>()>();
//    const int cnum_aliases_c11 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex11.FirstIndex(),cindex11.SecondIndex()>();
//    std::cout << "cnum_aliases_c11 : " << cnum_aliases_c11 << std::endl;
//    auto ctest_num_aliases_c11 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<1,1>()>();
//    const int cnum_aliases_c12 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex12.FirstIndex(),cindex12.SecondIndex()>();
//    std::cout << "cnum_aliases_c12 : " << cnum_aliases_c12 << std::endl;
//    auto ctest_num_aliases_c12 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<1,2>()>();
//
//    const int cnum_aliases_c20 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex20.FirstIndex(),cindex20.SecondIndex()>();
//    std::cout << "cnum_aliases_c20 : " << cnum_aliases_c20 << std::endl;
//    auto ctest_num_aliases_c20 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<2,0>()>();
//    const int cnum_aliases_c21 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex21.FirstIndex(),cindex21.SecondIndex()>();
//    std::cout << "cnum_aliases_c21 : " << cnum_aliases_c21 << std::endl;
//    auto ctest_num_aliases_c21 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<2,1>()>();
//    const int cnum_aliases_c22 =
//            mpc::core::CTensorRank2IndexNumberOfAliases<cindex22.FirstIndex(),cindex22.SecondIndex()>();
//    std::cout << "cnum_aliases_c22 : " << cnum_aliases_c22 << std::endl;
//    auto ctest_num_aliases_c22 =
//            mpcuserguide::IntTypeParameterValueTest<mpc::core::CTensorRank2IndexNumberOfAliases<2,2>()>();

    /*
    * Where compile-time computation is not needed and "plain"
    *     TensorRank2ComponentIndex or TensorRank4ComponentIndex will suffice,
    *     a static_cast<T> can be used to cast the CTensorRank2ComponentIndex
    *     or CTensorRank4ComponentIndex to a plain
    *     TensorRankNComponentIndex<N>.  For example ...
    */

    std::cout << "" << std::endl;
    std::cout << "casting to normal index for rank 2..." << std::endl;
    mpc::core::TensorRank2ComponentIndex index00cast = static_cast<mpc::core::TensorRank2ComponentIndex>(mpc::core::CTensorRank2ComponentIndex<0,0>());
    std::cout << "index00cast : " << index00cast << std::endl;

    mpc::core::TensorRank2ComponentIndex index00castagain = static_cast<mpc::core::TensorRank2ComponentIndex>(cindex00);
    std::cout << "index00 cast from cindex00 : " << index00castagain << std::endl;

    mpc::core::TensorRank2ComponentIndex index01cast = static_cast<mpc::core::TensorRank2ComponentIndex>(mpc::core::CTensorRank2ComponentIndex<0,1>());
    std::cout << "index01cast : " << index01cast << std::endl;

    mpc::core::TensorRank2ComponentIndex index01castagain = static_cast<mpc::core::TensorRank2ComponentIndex>(cindex01);
    std::cout << "index01 cast from cindex01 : " << index01castagain << std::endl;

    mpc::core::TensorRank2ComponentIndex index02cast = static_cast<mpc::core::TensorRank2ComponentIndex>(mpc::core::CTensorRank2ComponentIndex<0,2>());
    std::cout << "index02cast : " << index02cast << std::endl;

    mpc::core::TensorRank2ComponentIndex index02castagain = static_cast<mpc::core::TensorRank2ComponentIndex>(cindex02);
    std::cout << "index02 cast from cindex02 : " << index02castagain << std::endl;

    /*
    * predicates for ctensor rank2 and index
    *
    * Currently, MPC provides two predicates (callable that returns a value
    *     testable as a bool; see
    *     https://en.cppreference.com/w/cpp/named_req/Predicate) for
    *     TensorRankNCompoentIndex<> where N is either 2 or 4: ...IsAlias(...)
    *     and ...HasAlias(...).  The definiton of aliases is defined by
    *     symmetry...
    */

    bool cindexXX_has_alias;
    bool cindexXX_is_alias_cindexXX;
    std::cout << "\n compile-time predicates" << std::endl;

    // cindex00
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex00);
    std::cout << cindex00 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex00);
    std::cout << cindex00 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex01);
    std::cout << cindex00 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex02);
    std::cout << cindex00 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex10);
    std::cout << cindex00 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex11);
    std::cout << cindex00 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex12);
    std::cout << cindex00 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex20);
    std::cout << cindex00 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex21);
    std::cout << cindex00 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex22);
    std::cout << cindex00 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex01
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex01);
    std::cout << cindex01 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex00);
    std::cout << cindex01 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex01);
    std::cout << cindex01 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex02);
    std::cout << cindex01 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex10);
    std::cout << cindex01 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex11);
    std::cout << cindex01 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex12);
    std::cout << cindex01 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex20);
    std::cout << cindex01 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex21);
    std::cout << cindex01 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex22);
    std::cout << cindex01 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex02
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex02);
    std::cout << cindex02 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex00);
    std::cout << cindex02 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex01);
    std::cout << cindex02 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex02);
    std::cout << cindex02 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex10);
    std::cout << cindex02 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex11);
    std::cout << cindex02 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex12);
    std::cout << cindex02 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex20);
    std::cout << cindex02 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex21);
    std::cout << cindex02 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex22);
    std::cout << cindex02 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex10
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex10);
    std::cout << cindex10 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex00);
    std::cout << cindex10 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex01);
    std::cout << cindex10 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex02);
    std::cout << cindex10 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex10);
    std::cout << cindex10 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex11);
    std::cout << cindex10 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex12);
    std::cout << cindex10 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex20);
    std::cout << cindex10 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex21);
    std::cout << cindex10 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex22);
    std::cout << cindex10 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex11
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex11);
    std::cout << cindex11 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex00);
    std::cout << cindex11 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex01);
    std::cout << cindex11 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex02);
    std::cout << cindex11 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex10);
    std::cout << cindex11 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex11);
    std::cout << cindex11 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex12);
    std::cout << cindex11 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex20);
    std::cout << cindex11 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex21);
    std::cout << cindex11 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex22);
    std::cout << cindex11 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex12
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex12);
    std::cout << cindex12 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex00);
    std::cout << cindex12 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex01);
    std::cout << cindex12 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex02);
    std::cout << cindex12 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex10);
    std::cout << cindex12 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex11);
    std::cout << cindex12 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex12);
    std::cout << cindex12 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex20);
    std::cout << cindex12 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex21);
    std::cout << cindex12 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex22);
    std::cout << cindex12 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex20
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex20);
    std::cout << cindex20 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex00);
    std::cout << cindex20 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex01);
    std::cout << cindex20 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex02);
    std::cout << cindex20 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex10);
    std::cout << cindex20 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex11);
    std::cout << cindex20 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex12);
    std::cout << cindex20 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex20);
    std::cout << cindex20 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex21);
    std::cout << cindex20 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex22);
    std::cout << cindex20 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex21
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex21);
    std::cout << cindex21 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex00);
    std::cout << cindex21 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex01);
    std::cout << cindex21 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex02);
    std::cout << cindex21 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex10);
    std::cout << cindex21 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex11);
    std::cout << cindex21 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex12);
    std::cout << cindex21 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex20);
    std::cout << cindex21 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex21);
    std::cout << cindex21 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex22);
    std::cout << cindex21 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // cindex22
    cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex22);
    std::cout << cindex22 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex00);
    std::cout << cindex22 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex01);
    std::cout << cindex22 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex02);
    std::cout << cindex22 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex10);
    std::cout << cindex22 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex11);
    std::cout << cindex22 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex12);
    std::cout << cindex22 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex20);
    std::cout << cindex22 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex21);
    std::cout << cindex22 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
    cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex22);
    std::cout << cindex22 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

    // END
}


