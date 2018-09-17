/**
 *    @file tensorcomponentindex.hpp
 *    @brief structure that defines a tensor component index, i.e. the
 * indices (i,j) or (i,j,k,l) of a tensor
 *
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_TENSORCOMPONENTINDEX_H
#define MPC_TENSORCOMPONENTINDEX_H

#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <stdexcept>

// blitz
#include <blitz/array.h>

// mpc
#include "../util/matrixnotation.hpp"


namespace mpc {
namespace core {

//==============================================================================
// COMPILE-TIME COMPUTATION AND SPCIALIZATION AS TEMPLATE PARAMETER VALUE ARGUMENTS
/**
 * @brief The CTensorRank2ComponentIndex class
 *     An index class with constexpr member functions that can be used as
 *     template parameter values...
 */
template<int M, int N>
class CTensorRank2ComponentIndex {

public:
constexpr CTensorRank2ComponentIndex() {
}
constexpr inline int FirstIndex() const {
        return M;
}                                                          // no implicit this*
constexpr inline int SecondIndex() const {
        return N;
}                                                           // no implicit this*


template <int P, int Q>
constexpr CTensorRank2ComponentIndex(const CTensorRank2ComponentIndex<P,Q>& rhs) {
}                                                                                        // copy constructor

// no assignment, M,N are fixed
//template <int P, int Q>
//inline CTensorRank2ComponentIndex& operator= (const CTensorRank2ComponentIndex& rhs) {
//    return CTensorRank2ComponentIndex<P,Q>();  // return new CTensorRank2ComponentIndex<P,Q>(); ????
//}

inline int operator[](int i) {
        if(i==0) { return M; }
        if(i==1) { return N; }
        if(i>1 || i<0) { throw std::range_error("i must be less than or equal to one and greater than zero"); }
        return int();  // should never be called
}

template <int P, int Q>
inline bool operator<(const CTensorRank2ComponentIndex<P,Q>& rhs) {
        // the convention mpc uses:
        return ((M*10 + N) < (P*10 + Q)) ? true : false;
}

template <int P, int Q>
inline bool operator>(const CTensorRank2ComponentIndex<P,Q>& rhs) {
        // the convention mpc uses:
        return ((M*10 + N) > (P*10 + Q)) ? true : false;
}

template <int P, int Q>
inline bool operator==(const CTensorRank2ComponentIndex<P,Q>& rhs) {
        return (M==P && N==Q) ? true : false;
}

template <int P, int Q>
inline bool operator!=(const CTensorRank2ComponentIndex<P,Q>& rhs) {
        return (M==P && N==Q) ? false : true;
}

template <int P, int Q>
inline bool operator<=( const CTensorRank2ComponentIndex<P,Q>& rhs ) const
{
        // the convention mpc uses:
        return ((M*10 + N) <= (P*10 + Q)) ? true : false;
}

template <int P, int Q>
inline bool operator>=( const CTensorRank2ComponentIndex<P,Q>& rhs ) const
{
        // the convention mpc uses:
        return ((M*10 + N) >= (P*10 + Q)) ? true : false;
}

friend std::ostream& operator<<( std::ostream& os, const CTensorRank2ComponentIndex& t ) {
        os << "[" <<
                std::to_string(t.FirstIndex()) << "," <<
                std::to_string(t.SecondIndex()) << "]";
        return os;
}

template <int P, int Q>
static blitz::TinyVector<int,2> ToBlitzTinyVector(const CTensorRank2ComponentIndex<P,Q>& indexn) {
        return blitz::TinyVector<int,2>(P,Q);
}
};

//template <int M, int N, int P, int Q>
//inline bool operator<( const CTensorRank2ComponentIndex<M,N>& lhs, const CTensorRank2ComponentIndex<P,Q>& rhs ) {
//    if (lhs.FirstIndex() < rhs.FirstIndex()) { return true; }
//    if (lhs.FirstIndex() > rhs.FirstIndex()) { return false; }
//    // case m_ == indext.FirstIndex(), move to next index value
//    if (lhs.SecondIndex() < rhs.SecondIndex()) { return true; }
//    return false;
//}

//template <int M, int N, int P, int Q>
//inline bool operator>( const CTensorRank2ComponentIndex<M,N>& lhs, const CTensorRank2ComponentIndex<P,Q>& rhs ) {
//    if (lhs.FirstIndex() > rhs.FirstIndex()) { return true; }
//    if (lhs.FirstIndex() < rhs.FirstIndex()) { return false; }
//    // case m_ == indext.FirstIndex(), move to next index value
//    if (lhs.SecondIndex() > rhs.SecondIndex()) { return true; }
//    return false;
//}

//template <int M, int N, int P, int Q>
//inline bool operator== (const CTensorRank2ComponentIndex<M,N>& lhs, const CTensorRank2ComponentIndex<P,Q>& rhs ) {
//    if (lhs.FirstIndex() == rhs.FirstIndex() && lhs.SecondIndex() == rhs.SecondIndex()) { return true; }
//    return false;
//}

//template <int M, int N, int P, int Q>
//inline bool operator!= (const CTensorRank2ComponentIndex<M,N>& lhs, const CTensorRank2ComponentIndex<P,Q>& rhs ) {
//    if (lhs.FirstIndex() == rhs.FirstIndex() && lhs.SecondIndex() == rhs.SecondIndex()) { return false; }
//    return true;
//}

// TODO: define the comparison operators outside the class, make friend, and constexpr; if constexpr, can they be used as a predicate in another template paramter value or static_assert()


//==============================================================================
// COMPILE-TIME COMPUTATION AND SPCIALIZATION AS TEMPLATE PARAMETER VALUE ARGUMENTS
/**
 * @brief The CTensorRank4ComponentIndex class
 *     An index class with constexpr member functions that can be used as
 *     template parameter values...
 */
template<int I, int J, int K, int L>
class CTensorRank4ComponentIndex {

public:
constexpr CTensorRank4ComponentIndex() {
}
// the following functions can be used as template parameter values for
//     compile-time computation
constexpr inline int FirstIndex() const {
        return I;
}                                                          // no implicit this*
constexpr inline int SecondIndex() const {
        return J;
}                                                           // no implicit this*
constexpr inline int ThirdIndex() const {
        return K;
}                                                         // no implicit this*
constexpr inline int FourthIndex() const {
        return L;
}                                                          // no implicit this*


template <int P, int Q, int R, int S>
constexpr CTensorRank4ComponentIndex(const CTensorRank4ComponentIndex<P,Q,R,S>& rhs) {
}                                                                                            // copy constructor

// no assignment operator; I,J,K,L are fixed????
//     template <int P, int Q, int R, int S>
//     inline CTensorRank4ComponentIndex<I,J,K,L>& operator=(CTensorRank4ComponentIndex<P,Q,R,S>& c) {
//
//
//         return *this;
//     }

inline int operator[](int i) {
        switch (i) {
        case 0: return I;
        case 1: return J;
        case 2: return K;
        case 3: return L;
        default: int();
                if (i<0 || i>3) { throw std::range_error("i must be less than or equal to three and greater than zero"); }
                return int(); // should never be called
        }
}

// =======
template <int P, int Q, int R, int S>
inline bool operator<(const CTensorRank4ComponentIndex<P,Q,R,S>& rhs) {
//         if (i_ < rhs.FirstIndex()) { return true; }
//         if (i_ > rhs.FirstIndex()) { return false; }
//         // case i_ == indext.FirstIndex(), move to next index value
//         if (j_ < rhs.SecondIndex()) { return true; }
//         if (j_ > rhs.SecondIndex()) { return false; }
//         // case j_ == indext.SecondIndex(), move to next index value
//         if (k_ < rhs.ThirdIndex()) { return true; }
//         if (k_ > rhs.ThirdIndex()) { return false; }
//         // case k_ == indext.ThirdIndex(), move to next index value
//         if (l_ < rhs.FourthIndex()) { return true; }
//         return false;
        // the convention mpc uses:
        return ((I*1000 + J*100 + K*10 + L) < (P*1000 + Q*100 + R*10 + S)) ? true : false;
}

template <int P, int Q, int R, int S>
inline bool operator>(const CTensorRank4ComponentIndex<P,Q,R,S>& rhs) {
//         if (i_ > rhs.FirstIndex()) { return true; }
//         if (i_ < rhs.FirstIndex()) { return false; }
//         // case i_ == indext.FirstIndex(), move to next index value
//         if (j_ > rhs.SecondIndex()) { return true; }
//         if (j_ < rhs.SecondIndex()) { return false; }
//         // case j_ == indext.SecondIndex(), move to next index value
//         if (k_ > rhs.ThirdIndex()) { return true; }
//         if (k_ < rhs.ThirdIndex()) { return false; }
//         // case k_ == indext.ThirdIndex(), move to next index value
//         if (l_ > rhs.FourthIndex()) { return true; }
//         return false;
        // the convention mpc uses:
        return ((I*1000 + J*100 + K*10 + L) > (P*1000 + Q*100 + R*10 + S)) ? true : false;
}

inline bool operator==(const CTensorRank4ComponentIndex<I,J,K,L>& rhs) {
        if (I == rhs.FirstIndex() && J == rhs.SecondIndex() && K == rhs.ThirdIndex() && L == rhs.FourthIndex()) { return true; }
        return false;
}

template <int P, int Q, int R, int S>
inline bool operator!=(const CTensorRank4ComponentIndex<P,Q,R,S>& rhs) {
        if (I == rhs.FirstIndex() && J == rhs.SecondIndex() && K == rhs.ThirdIndex() && L == rhs.FourthIndex()) { return false; }
        return true;
}

template <int P, int Q, int R, int S>
inline bool operator<=( const CTensorRank4ComponentIndex<P,Q,R,S>& rhs ) const
{
        // the convention mpc uses:
        return ((I*1000 + J*100 + K*10 + L) <= (P*1000 + Q*100 + R*10 + S)) ? true : false;
}

template <int P, int Q, int R, int S>
inline bool operator>=( const CTensorRank4ComponentIndex<P,Q,R,S>& rhs ) const
{
        // the convention mpc uses:
        return ((I*1000 + J*100 + K*10 + L) >= (P*1000 + Q*100 + R*10 + S)) ? true : false;
}
// =======

friend inline std::ostream& operator<<( std::ostream& os, const CTensorRank4ComponentIndex& t ) {
        os << "[" <<
                std::to_string(t.FirstIndex()) << "," <<
                std::to_string(t.SecondIndex()) << "," <<
                std::to_string(t.ThirdIndex()) << "," <<
                std::to_string(t.FourthIndex()) << "]";
        return os;
}

template <int P, int Q, int R, int S>
static blitz::TinyVector<int,4> ToBlitzTinyVector(const CTensorRank4ComponentIndex<P,Q,R,S>& indexn) {
        return blitz::TinyVector<int,4>(P,Q,R,S);
}
};

// TODO: define the comparison operators outside the class, make friend, and constexpr; if constexpr, can they be used as a predicate in another template paramter value or static_assert()



// =============================================================================
// =============================================================================
// =============================================================================
// "Plain" Tensor index; member functions cannot be used as a template
//     parameter values;

// https://stackoverflow.com/questions/12453623/can-i-get-a-c-compiler-to-instantiate-objects-at-compile-time

// Stroustrup, B., 2013, The C++ Programming Language, fourth edition... see p.265 Literal types
template<int N>
class TensorRankNComponentIndex {};

template <>
class TensorRankNComponentIndex<2> {
int m_;
int n_;

public:
constexpr TensorRankNComponentIndex(int m, int n) : m_(m), n_(n) {
}

constexpr inline int FirstIndex() const /* implicit */ {
        return m_;
}
constexpr inline int SecondIndex() const /* implicit */ {
        return n_;
}

// constructor used for casting; note the use of explicit to avoid any implicit casts
template<int M, int N>
explicit TensorRankNComponentIndex(const CTensorRank2ComponentIndex<M,N>& cindex) : m_(M), n_(N) {
}

inline int operator[](int i) {

        if(i==0) { return m_; }
        if(i==1) { return n_; }
        if(i>1 || i<0) { throw std::range_error("i must be less than or equal to one and greater than zero"); }
        return int();  // should never be called
}

// needed for set, although one index is not really greater than or less than another...
inline bool operator<( const TensorRankNComponentIndex& rhs ) const
{
        return ((m_*10 + n_) < (rhs.FirstIndex()*10 + rhs.SecondIndex())) ? true : false;
}
inline bool operator>( const TensorRankNComponentIndex& rhs ) const
{
        return ((m_*10 + n_) > (rhs.FirstIndex()*10 + rhs.SecondIndex())) ? true : false;
}

inline bool operator== (const TensorRankNComponentIndex& rhs) const
{
        return ((m_*10 + n_) == (rhs.FirstIndex()*10 + rhs.SecondIndex())) ? true : false;
}

inline bool operator!= (const TensorRankNComponentIndex& rhs) const
{
        return ((m_*10 + n_) != (rhs.FirstIndex()*10 + rhs.SecondIndex())) ? true : false;
}

inline bool operator<=( const TensorRankNComponentIndex& rhs ) const
{
        return ((m_*10 + n_) <= (rhs.FirstIndex()*10 + rhs.SecondIndex())) ? true : false;
}
inline bool operator>=( const TensorRankNComponentIndex& rhs ) const
{
        return ((m_*10 + n_) >= (rhs.FirstIndex()*10 + rhs.SecondIndex())) ? true : false;
}

static inline blitz::TinyVector<int,2> ToBlitzTinyVector( const
                                                          mpc::core::TensorRankNComponentIndex<2>& indexn) {
        return blitz::TinyVector<int,2>(indexn.FirstIndex(), indexn.SecondIndex());
}
};

//inline bool operator<(TensorRankNComponentIndex<2>& lhs, TensorRankNComponentIndex<2>& rhs) {
//    if (lhs.FirstIndex() < rhs.FirstIndex() && lhs.SecondIndex() < rhs.SecondIndex()) { return true; }
//    return false;
//}

//inline bool operator>(TensorRankNComponentIndex<2>& lhs, TensorRankNComponentIndex<2>& rhs) {
//    if (lhs.FirstIndex() > rhs.FirstIndex() && lhs.SecondIndex() > rhs.SecondIndex()) { return true; }
//    return false;
//}

//inline bool operator==(TensorRankNComponentIndex<2>& lhs, TensorRankNComponentIndex<2>& rhs) {
//    if (lhs.FirstIndex() == rhs.FirstIndex() && lhs.SecondIndex() == rhs.SecondIndex()) { return true; }
//    return false;
//}

//inline bool operator!=(TensorRankNComponentIndex<2>& lhs, TensorRankNComponentIndex<2>& rhs) {
//    if (lhs.FirstIndex() == rhs.FirstIndex() && lhs.SecondIndex() == rhs.SecondIndex()) { return false; }
//    return true;
//}



inline std::ostream& operator<<(std::ostream& os, TensorRankNComponentIndex<2> indexR2) {
        os << "[" <<
                std::to_string(indexR2.FirstIndex()) << "," <<
                std::to_string(indexR2.SecondIndex()) << "]";
        return os;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// https://stackoverflow.com/questions/12453623/can-i-get-a-c-compiler-to-instantiate-objects-at-compile-time
template <>
class TensorRankNComponentIndex<4> {
int i_;
int j_;
int k_;
int l_;
public:
constexpr TensorRankNComponentIndex(int i, int j, int k, int l) : i_(i), j_(j), k_(k), l_(l) {
}
constexpr inline int FirstIndex() const /* implicit */ {
        return i_;
}
constexpr inline int SecondIndex() const /* implicit */ {
        return j_;
}
constexpr inline int ThirdIndex() const /* implicit */ {
        return k_;
}
constexpr inline int FourthIndex() const /* implicit */ {
        return l_;
}

template<int I, int J, int K, int L>
explicit TensorRankNComponentIndex(const CTensorRank4ComponentIndex<I,J,K,L>& cindex) :
        i_(I), j_(J), k_(K), l_(L) {
}

inline int operator[](int i) {

        switch (i) {
        case 0: return i_;
        case 1: return j_;
        case 2: return k_;
        case 3: return l_;
        default: throw std::range_error("i must be less than or equal to three");
        }

}

// needed for set, although one index is not really greater than or less than another...
inline bool operator<( const TensorRankNComponentIndex& rhs ) const
{
        return ((i_*1000 + j_*100 + k_*10 + l_) < (rhs.FirstIndex()*1000 + rhs.SecondIndex()*100 + rhs.ThirdIndex()*10 + rhs.FourthIndex())) ? true : false;
}
inline bool operator>( const TensorRankNComponentIndex& rhs ) const
{
        return ((i_*1000 + j_*100 + k_*10 + l_) > (rhs.FirstIndex()*1000 + rhs.SecondIndex()*100 + rhs.ThirdIndex()*10 + rhs.FourthIndex())) ? true : false;
}

inline bool operator== (const TensorRankNComponentIndex& rhs) const
{
        return ((i_*1000 + j_*100 + k_*10 + l_) == (rhs.FirstIndex()*1000 + rhs.SecondIndex()*100 + rhs.ThirdIndex()*10 + rhs.FourthIndex())) ? true : false;
}

inline bool operator!= (const TensorRankNComponentIndex& rhs) const
{
        return ((i_*1000 + j_*100 + k_*10 + l_) != (rhs.FirstIndex()*1000 + rhs.SecondIndex()*100 + rhs.ThirdIndex()*10 + rhs.FourthIndex())) ? true : false;
}

inline bool operator<=( const TensorRankNComponentIndex& rhs ) const
{
        return ((i_*1000 + j_*100 + k_*10 + l_) <= (rhs.FirstIndex()*1000 + rhs.SecondIndex()*100 + rhs.ThirdIndex()*10 + rhs.FourthIndex())) ? true : false;
}
inline bool operator>=( const TensorRankNComponentIndex& rhs ) const
{
        return ((i_*1000 + j_*100 + k_*10 + l_) >= (rhs.FirstIndex()*1000 + rhs.SecondIndex()*100 + rhs.ThirdIndex()*10 + rhs.FourthIndex())) ? true : false;
}

static inline blitz::TinyVector<int,4> ToBlitzTinyVector(const
                                                         mpc::core::TensorRankNComponentIndex<4>& indexn) {
        return blitz::TinyVector<int,4>(
                indexn.FirstIndex(), indexn.SecondIndex(),
                indexn.ThirdIndex(), indexn.FourthIndex());
}
};

// TODO: comparison operator overloading is recommended OUTSIDE the class... move the comparison operator overloading here..
//inline bool operator==(TensorRankNComponentIndex<4>& lhs, TensorRankNComponentIndex<4>& rhs) {
//    if (lhs.FirstIndex() == rhs.FirstIndex() && lhs.SecondIndex() == rhs.SecondIndex() && lhs.ThirdIndex() == rhs.ThirdIndex() && lhs.FourthIndex() == rhs.FourthIndex()) { return true; }
//    return false;
//}

//inline bool operator!=(TensorRankNComponentIndex<4>& lhs, TensorRankNComponentIndex<4>& rhs) {
//    if (lhs.FirstIndex() == rhs.FirstIndex() && lhs.SecondIndex() == rhs.SecondIndex() && lhs.ThirdIndex() == rhs.ThirdIndex() && lhs.FourthIndex() == rhs.FourthIndex()) { return false; }
//    return true;
//}

inline std::ostream& operator<<(std::ostream& os, TensorRankNComponentIndex<4> indexR4) {
        os << "[" <<
                std::to_string(indexR4.FirstIndex()) << "," <<
                std::to_string(indexR4.SecondIndex()) << "," <<
                std::to_string(indexR4.ThirdIndex()) << "," <<
                std::to_string(indexR4.FourthIndex()) << "]";
        return os;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// aliases provided
using TensorRank2ComponentIndex = TensorRankNComponentIndex<2>;
using TensorRank4ComponentIndex = TensorRankNComponentIndex<4>;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//

} // namespace core
} // namespace mpc

#endif // MPC_TENSORCOMPONENTINDEX_H
