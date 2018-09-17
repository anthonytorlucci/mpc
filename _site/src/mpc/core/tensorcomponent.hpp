/**
 *    \file tensorcomponent.hpp
 *    \brief structure that defines a tensor component
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef MPC_TENSORCOMPONENT_H
#define MPC_TENSORCOMPONENT_H

// c++ standard
#include <vector>
#include <set>
#include <iostream>

// blitz
#include <blitz/tinyvec2.h>

// mpc
#include "tensorcomponentindex.hpp"
#include "../util/matrixnotation.hpp"

namespace mpc {
namespace core {

/**
* \class TensorRankNComponent
* \brief tensor component consisting of a component index and a value
*/
template <typename T, int N>
class TensorRankNComponent {
using type = T;

T value_;                                 // NOTE: the api has changed.  this is no longer const
TensorRankNComponentIndex<N> index_;      // NOTE: the api has changed.  this is no longer const

TensorRankNComponent() {
}                              // default constructor is private; cannot be instantiated.
public:
constexpr TensorRankNComponent(T val, TensorRankNComponentIndex<N> indx) : value_(val), index_(indx) {
        //
}
// accessor
constexpr T Value() const {
        return value_;
}
constexpr TensorRankNComponentIndex<N> Index() const {
        return index_;
}

// mutator
inline void Value(T val) {
        value_ = val;
}
inline void Index(mpc::core::TensorRank4ComponentIndex index) {
        index_ = index;
}

// NOTE that the less than and greater than operators are by index, NOT value
inline bool operator<(const TensorRankNComponent<T,N>& rhs) const {
        if(this->index_ < rhs.Index()) { return true; }
        return false;
}

inline bool operator>(const TensorRankNComponent<T,N>& rhs) const {
        if(this->index_ > rhs.Index()) { return true; }
        return false;
}

inline bool operator==(const TensorRankNComponent<T,N>& rhs) const {
        if (this->index_ == rhs.index_ && this->value_ == rhs.value_) { return true; }
        return false;
}

inline bool operator!=(const TensorRankNComponent<T,N>& rhs) const {
        if (this->index_ == rhs.index_ || this->value_ == rhs.value_) { return false; }
        return true;
}

inline bool operator<=(const TensorRankNComponent<T,N>& rhs) const {
        if(this->index_ <= rhs.Index()) { return true; }
        return false;
}

inline bool operator>=(const TensorRankNComponent<T,N>& rhs) const {
        if(this->index_ >= rhs.Index()) { return true; }
        return false;
}


friend std::ostream& operator<<( std::ostream& os, const TensorRankNComponent& t ) {
        // can access the enclosing Test. If T is int, it cannot access Test<double>
        os << std::to_string(t.Value()) << "," << t.Index();
        return os;
}
};

// using aliases
template <typename T>
using TensorRank2Component = TensorRankNComponent<T,2>;

template <typename T>
using TensorRank4Component = TensorRankNComponent<T,4>;




} // namespace core
} // namespace mpc

#endif // MPC_TENSORCOMPONENT_H
