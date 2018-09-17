/**
 *    @file tensorcomponentindexpredicates.hpp
 *    @brief boolean functions that take a TensorRankNComponentIndex<N> that
 * can be used in assertions or control program flow
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_TENSORCOMPONENTINDEXPREDICATES_H
#define MPC_TENSORCOMPONENTINDEXPREDICATES_H

#include <iostream>

#include "tensorcomponentindex.hpp"
#include "tensorcomponentindexaliases.hpp"

namespace mpc {
namespace core {

//==============================================================================
// COMPILE TIME EQUIVALENTS
// tensor rank 2
template <int M,int N>
constexpr inline bool CComponentIndexHasAlias(const mpc::core::CTensorRank2ComponentIndex<M,N>& indexn) {
        return (M==N) ? false : true;
}

// polymorphic no argument
template <int M,int N>
constexpr inline bool CComponentIndexHasAlias() {
        return (M==N) ? false : true;
}

template <int M, int N, int P, int Q>
constexpr inline bool CComponentIndexIsAlias(const mpc::core::CTensorRank2ComponentIndex<M,N>& indexa,
                                             const mpc::core::CTensorRank2ComponentIndex<P,Q>& indexb) {
        return ((M==P && N==Q) || (M==Q && N==P)) ? true : false;
}

// polymorphic no argument
template <int M, int N, int P, int Q>
constexpr inline bool CComponentIndexIsAlias() {
        return ((M==P && N==Q) || (M==Q && N==P)) ? true : false;
}

//==============================================================================
// tensor rank 4 : TRICLINIC ONLY, not very useful really...
template <int I, int J, int K, int L>
constexpr inline bool CComponentIndexHasAlias(const mpc::core::CTensorRank4ComponentIndex<I,J,K,L>& indexn) {
        //return (mpc::core::CTensorRank4IndexNumberOfAliases<I,J,K,L>() > 1) ? true : false;
        //return (((I==J)==K==L)) ? false : true;
        return ((I==J) && (J==K) && (K==L)) ? false : true;
}

// polymorphic no argument
template <int I, int J, int K, int L>
constexpr inline bool CComponentIndexHasAlias() {
        //return (mpc::core::CTensorRank4IndexNumberOfAliases<I,J,K,L>() > 1) ? true : false;
        return ((I==J) && (J==K) && (K==L)) ? false : true;
}

template <int I, int J, int K, int L, int P, int Q, int R, int S>
constexpr inline bool CComponentIndexIsAlias(const mpc::core::CTensorRank4ComponentIndex<I,J,K,L>& indexa, const mpc::core::CTensorRank4ComponentIndex<P,Q,R,S>& indexb) {
        // IJKL  IJLK  JIKL  JILK  KLIJ  LKIJ  KLJI  LKJI
        // PQRS  PQSR  QPRS  QPSR  RSPQ  SRPQ  RSQP  SRQP

        bool b0 = (I==P && J==Q && K==R && L==S) ? true : false;
        bool b1 = (I==P && J==Q && K==S && L==R) ? true : false;
        bool b2 = (I==Q && J==P && K==R && L==S) ? true : false;
        bool b3 = (I==Q && J==P && K==S && L==R) ? true : false;
        bool b4 = (I==R && J==S && K==P && L==Q) ? true : false;
        bool b5 = (I==S && J==R && K==P && L==Q) ? true : false;
        bool b6 = (I==R && J==S && K==Q && L==P) ? true : false;
        bool b7 = (I==S && J==R && K==Q && L==P) ? true : false;

        return (b0 || b1 || b2 || b3 || b4 || b5 || b6 || b7) ? true : false;

}

// polymorphic no argument
template <int I, int J, int K, int L, int P, int Q, int R, int S>
constexpr inline bool CComponentIndexIsAlias() {
        // IJKL  IJLK  JIKL  JILK  KLIJ  LKIJ  KLJI  LKJI
        // PQRS  PQSR  QPRS  QPSR  RSPQ  SRPQ  RSQP  SRQP

        bool b0 = (I==P && J==Q && K==R && L==S) ? true : false;
        bool b1 = (I==P && J==Q && K==S && L==R) ? true : false;
        bool b2 = (I==Q && J==P && K==R && L==S) ? true : false;
        bool b3 = (I==Q && J==P && K==S && L==R) ? true : false;
        bool b4 = (I==R && J==S && K==P && L==Q) ? true : false;
        bool b5 = (I==S && J==R && K==P && L==Q) ? true : false;
        bool b6 = (I==R && J==S && K==Q && L==P) ? true : false;
        bool b7 = (I==S && J==R && K==Q && L==P) ? true : false;

        return (b0 || b1 || b2 || b3 || b4 || b5 || b6 || b7) ? true : false;

        // this is dumb.  only (0,0,0,0), (1,1,1,1), and (2,2,2,2) do not have an alias. Do we really need to test this?
}

// ====================================================================================
// ====================================================================================
// ====================================================================================


// tensor rank 2
constexpr inline bool TensorRank2ComponentIndexHasAlias(const mpc::core::TensorRank2ComponentIndex& indexn) {
        //
        return (indexn.FirstIndex() == indexn.SecondIndex()) ? false : true;
}

constexpr inline bool TensorRank2ComponentIndexIsAlias(const mpc::core::TensorRank2ComponentIndex& indexa,
                                                       const mpc::core::TensorRank2ComponentIndex& indexb) {
        // determines if indexa is an alias of indexb
        return ((indexa.FirstIndex()==indexb.FirstIndex() && indexa.SecondIndex()==indexb.SecondIndex()) || (indexa.FirstIndex()==indexb.SecondIndex() && indexa.SecondIndex()==indexb.FirstIndex())) ? true : false;
}

// ====================================================================================
// tensor rank 4
//     unlike the C* version above that is really pretty useless, these predicates take symmetry into account

template <typename S=mpc::core::NoneSymmetryGroupType>
inline bool TensorRank4ComponentIndexHasAlias(const mpc::core::TensorRank4ComponentIndex& indexn) {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        // if there is no symmetry, there are no aliased components
        return false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::TriclinicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        //return ((indexn.FirstIndex()==indexn.SecondIndex()) && (indexn.SecondIndex()==indexn.ThirdIndex()) && (indexn.ThirdIndex()==indexn.FourthIndex())) ? false : true;
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::MonoclinicX2SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX2SymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::MonoclinicX3SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX3SymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::OrthorhombicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::OrthorhombicSymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::HexagonalSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::HexagonalSymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::Tetragonal7SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal7SymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::Tetragonal6SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal6SymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::Trigonal7SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal7SymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::Trigonal6SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal6SymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::CubicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::CubicSymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexHasAlias<mpc::core::IsotropicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
        const int N = mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::IsotropicSymmetryGroupType>(indexn);
        return (N>1) ? true : false;
}


// ===
template <typename S>
inline bool TensorRank4ComponentIndexIsAlias(const mpc::core::TensorRank4ComponentIndex& indexa,
                                             const mpc::core::TensorRank4ComponentIndex& indexb) {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        // determines if indexa is an alias of indexb

        // by convention, mpc chooses to label an two indices that are equivalent as NOT being aliases.  This follows the convention of "HasAlias"; if a
        //     component index of a tensor is only represented once, it does not have an alias.  For example
        //     TensorRank4ComponentIndex(0,0,0,0) for TriclinicSymmetryGroupType does not have an alias and therefore it cannot be an alias of itself.
        if (indexa == indexb) { return false; }

        // if neither index has an alias, they cannot be aliases of each other.
        const bool indexa_has_alias = mpc::core::TensorRank4ComponentIndexHasAlias<S>(indexa);
        const bool indexb_has_alias = mpc::core::TensorRank4ComponentIndexHasAlias<S>(indexb);
        if (!indexa_has_alias || !indexb_has_alias) { return false; }


        mpc::core::TensorRank4ComponentIndex a_reduced = mpc::core::ReducedTensorRank4ComponentIndex<S>(indexa);
        mpc::core::TensorRank4ComponentIndex b_reduced = mpc::core::ReducedTensorRank4ComponentIndex<S>(indexb);
        // FOR DEBUG std::cout << "    a_reduced : " << a_reduced << ", b_reduced : " << b_reduced << std::endl;
        return (a_reduced == b_reduced) ? true : false;
}

template <>
inline bool TensorRank4ComponentIndexIsAlias<mpc::core::NoneSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexa,
                                                                               const mpc::core::TensorRank4ComponentIndex& indexb) {
        return false;
}



} // namespace core
} // namespace mpc

#endif // MPC_TENSORCOMPONENTINDEXPREDICATES_H
