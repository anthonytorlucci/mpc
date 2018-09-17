/**
 *    \file symmetrypredicates.hpp
 *    \brief boolean functions related to symmetry groups or sets of tensor components used for assertions or control flow
 *
 *    \author Anthony Torlucci
 *    \date 9/16/2018
 */

#ifndef MPC_SYMMETRYPREDICATES_H
#define MPC_SYMMETRYPREDICATES_H

#include <iostream>
#include <type_traits>
#include <set>
#include <iterator>  // for std::advance<> : https://en.cppreference.com/w/cpp/iterator/advance
#include <vector>
#include <algorithm>  // std::sort<>

// mpc
#include "cstypes.hpp"
#include "symmetrygrouptypes.hpp"
#include "tensorcomponentindex.hpp"
#include "tensorcomponentindexaliases.hpp"
#include "tensorcomponent.hpp"

namespace mpc {
namespace core {

/*
 * symmetry predicates :
 *
 * supported symmetry classes:
 *     NoneSymmetryGroupType
 *     TriclinicSymmetryGroupType
 *     MonoclinicX2SymmetryGroupType
 *     MonoclinicX3SymmetryGroupType
 *     OrthorhombicSymmetryType
 *     HexagonalSymmetryGroupType
 *     Tetragonal7SymmetryGroupType
 *     Tetragonal6SymmetryGroupType
 *     Trigonal7SymmetryGroupType
 *     Trigonal6SymmetryGroupType
 *     CubicSymmetryGroupType
 *     IsotropicSymmetryGroupType
 */

// type traits for symmetry classes
// good online article : https://akrzemi1.wordpress.com/2017/12/02/your-own-type-predicate/
/**
* \fn bool SymmetryGroupTypeHasNIndependentComponents()
*/
template <typename S, int N>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        // all true specializations are handled.  Anything else, return false
        return false;
}

// specialization : Triclinic 21 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::TriclinicSymmetryGroupType,21>() {
        return true;
}

// specialization : MonoclinicX2 13 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType,13>() {
        return true;
}

// specialization : MonoclinicX3 13 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType,13>() {
        return true;
}

// specialization : Orthorhombic 9 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::OrthorhombicSymmetryGroupType,9>() {
        return true;
}

// specialization : Tetragonal7 7 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::Tetragonal7SymmetryGroupType,7>() {
        return true;
}

// specialization : Trigonal 7 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::Trigonal7SymmetryGroupType,7>() {
        return true;
}

// spcialization : Tetragonal6 6 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::Tetragonal6SymmetryGroupType,6>() {
        return true;
}

// spcialization : Tetragonal6 6 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::Trigonal6SymmetryGroupType,6>() {
        return true;
}

// spcialization : Hexagonal 5 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::HexagonalSymmetryGroupType,5>() {
        return true;
}

// spcialization : Cubic 3 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::CubicSymmetryGroupType,3>() {
        return true;
}

// spcialization : Isotropic 2 components
template <>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents<mpc::core::IsotropicSymmetryGroupType,2>() {
        return true;
}



// convenience functions
// 21 components
/**
* bool SymmetryGroupTypeHas21IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas21IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,21>();
}

// 13 components
/**
* bool SymmetryGroupTypeHas13IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas13IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,13>();
}

// 9 components
/**
* bool SymmetryGroupTypeHas9IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas9IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,9>();
}

// 7 components
/**
* bool SymmetryGroupTypeHas7IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas7IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,7>();
}


// 6 components
/**
* bool SymmetryGroupTypeHas6IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas6IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,6>();
}

// 5 components
/**
* bool SymmetryGroupTypeHas5IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas5IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,5>();
}

// 3 components
/**
* bool SymmetryGroupTypeHas3IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas3IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,3>();
}

// 2 components
/**
* bool SymmetryGroupTypeHas2IndependentComponents()
*/
template <typename S>
constexpr inline bool SymmetryGroupTypeHas2IndependentComponents() {
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        return SymmetryGroupTypeHasNIndependentComponents<S,2>();
}

// provide a similar function for the symmetry group enum by mapping to symmetry group type
template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas21IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,21>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas13IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,13>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas9IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,9>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas7IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,7>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas6IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,6>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas5IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,5>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas3IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,3>();
}

template<mpc::core::SymmetryGroupEnumeration Sym>
constexpr inline bool SymmetryGroupEnumerationHas2IndependentComponents() {
        return SymmetryGroupTypeHasNIndependentComponents<typename SymmetryGroupType<Sym>::type,2>();
}

//==============================================================================
// is symmetry compliant determines a std::set<TensorRank4ComponentIndex> is symmetry compliant
//     Assumptions:
//         >> the indices represented in the set correspond to indices that
//                have non-zero values (this assumption has been relaxed; zero-valued components not in the set of expected non-zero valued components are discarded and ignored)
//         >> aliased components, i.e., components with aliased indexes and
//                equivalent values have been removed (unless they have the same value in which only one is kept)
//         >> the number of indices matches the number of independent
//                components in the symmetry class after all reductions mentioned above;
//
// Each specialization of the function  must determine if the given component
//     is found in the set of possible permutations of TensorRank4ComponentIndex
//     for the given symmetry...  Since the number of permutations is quite high, MPC has fabricated a concept not found in the literature : "Reduced" component index.
//     This concept simplifies the search (assertions) to a much smaller set of expected indices...
//
//     For example, cubic symmetry has 3 non-zero components.  The indices could be {0000, 0011, 1212}, {0000, 0011, 0202}, {0000, 0011, 0101}, {0000, 0022, 1212}, {0000, 0022, 0202}, etc.
//     The "reduced" set is simply {0000, 0011, 0101}; MPC compares the reduced components to these values to determine if the set is symmetry compliant...

/**
* \class IsComponentSetSymmetryCompliantFunctionObject
* \brief function object that determines if a set of tensor components complies the constraints of the given symmetry
*/
template <typename T, typename CS, typename S=mpc::core::NoneSymmetryGroupType>
struct IsComponentSetSymmetryCompliantFunctionObject {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");

        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                return true;
        }
        //NoneSyymetryGroupType has no symmetry and thus any set can have none symmetry
        // TODO: assertions such as size() <=81
};
// all symmetry group partial specializations handled...

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::TriclinicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  03  04  05 |
         *  | 01  11  12  13  14  15 |
         *  | 02  12  22  23  24  25 |
         *  | 03  13  23  33  34  35 |
         *  | 04  14  24  34  44  45 |
         *  | 05  15  25  35  45  55 |
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; for a vector use std::unique; better still, just use a set.  That set should have only 3 components
                //     corresponding to the nonzero_indices_set
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::MonoclinicX2SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  04  -- |
         *  | 01  11  12  --  14  -- |
         *  | 02  12  22  --  24  -- |
         *  | --  --  --  33  --  35 |
         *  | 04  14  24  --  44  -- |
         *  | --  --  --  35  --  55 |
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; for a vector use std::unique; better still, just use a set.  That set should have only 3 components
                //     corresponding to the nonzero_indices_set
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::MonoclinicX3SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  --  05 |
         *  | 01  11  12  --  --  15 |
         *  | 02  12  22  --  --  25 |
         *  | --  --  --  33  34  -- |
         *  | --  --  --  34  44  -- |
         *  | 05  15  25  --  --  55 |
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; for a vector use std::unique; better still, just use a set.  That set should have only 3 components
                //     corresponding to the nonzero_indices_set
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::OrthorhombicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  --  -- |
         *  | 01  11  12  --  --  -- |
         *  | 02  12  22  --  --  -- |
         *  | --  --  --  33  --  -- |
         *  | --  --  --  --  44  -- |
         *  | --  --  --  --  --  55 |
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; for a vector use std::unique; better still, just use a set.  That set should have only 3 components
                //     corresponding to the nonzero_indices_set
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::StiffnessType, mpc::core::HexagonalSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  --  -- |
         *  | 01  00  02  --  --  -- |
         *  | 02  02  22  --  --  -- |
         *  | --  --  --  33  --  -- |
         *  | --  --  --  --  33  -- |
         *  | --  --  --  --  --  XX |
         *
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be at most 6 components
                // the reduced container for size 6 will have component indices {0000, 0011, 0022, 0101, 0202, 2222};
                // if the component vector has 6 components, assert the values satisfy the constraint: For C, XX = 0.5 * [C(0,0) - C(0,1)]
                if (component_vector.size() > 5) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[3].Value() != 0.5 * (component_vector[0].Value() - component_vector[1].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::ComplianceType, mpc::core::HexagonalSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  --  -- |
         *  | 01  00  02  --  --  -- |
         *  | 02  02  22  --  --  -- |
         *  | --  --  --  33  --  -- |
         *  | --  --  --  --  33  -- |
         *  | --  --  --  --  --  XX |
         *
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be at most 6 components
                // the reduced container for size 6 will have component indices {0000, 0011, 0022, 0101, 0202, 2222};
                // if the component vector has 6 components, assert the values satisfy the constraint: For S, XX = 2 * [C(0,0) - C(0,1)]
                if (component_vector.size() > 5) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[3].Value() != 2 * (component_vector[0].Value() - component_vector[1].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::Tetragonal7SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  --  05 |
         *  | 01  00  02  --  -- -05 |
         *  | 02  02  22  --  --  -- |
         *  | --  --  --  33  --  -- |
         *  | --  --  --  --  33  -- |
         *  | 05 -05  --  --  --  55 |
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        // TODO: if both 05 and 15 are present, assert that the value of 05 == -15...
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be a maximum of 6 components
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::Tetragonal6SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  --  --  -- |
         *  | 01  00  02  --  --  -- |
         *  | 02  02  22  --  --  -- |
         *  | --  --  --  33  --  -- |
         *  | --  --  --  --  33  -- |
         *  | --  --  --  --  --  55 |
         */

        // To be compliant:
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be a maximum of 6 components
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::StiffnessType, mpc::core::Trigonal7SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  03 -04  -- |
         *  | 01  00  02 -03  04  -- |
         *  | 02  02  22  --  --  -- |
         *  | 03 -03  --  33  -- *04 |
         *  | 04  14  --  --  33 *03 |
         *  | --  --  -- *04 *03  XX |
         *
         * where *NN is the numerical equal for C and twice the numerical equal for S; and
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         *
         */

        // To be compliant
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        // TODO: if 03, 13, and 35 are present, assert that the value of 03 == -13 and 35 == 03 for C, 2*35 == 03 for S
                        // TODO: if 04, 14, and 45 are present, assert that the value of 04 == -14 and 45 == 04 for C, 2*45 == 04 for S
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be at most 8 components
                // the reduced container for size 8 will have component indices {0000, 0002, 0011, 0012, 0022, 0101, 0202, 2222};
                // if the component vector has 8 components, assert the values satisfy the constraint: For C, XX = 0.5 * [C(0,0) - C(0,1)]
                if (component_vector.size() > 7) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[5].Value() != 0.5 * (component_vector[0].Value() - component_vector[2].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::ComplianceType, mpc::core::Trigonal7SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  03 -04  -- |
         *  | 01  00  02 -03  04  -- |
         *  | 02  02  22  --  --  -- |
         *  | 03 -03  --  33  -- *04 |
         *  | 04  14  --  --  33 *03 |
         *  | --  --  -- *04 *03  XX |
         *
         * where *NN is the numerical equal for C and twice the numerical equal for S; and
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         *
         */

        // To be compliant
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        // TODO: if 03, 13, and 35 are present, assert that the value of 03 == -13 and 35 == 03 for C, 2*35 == 03 for S
                        // TODO: if 04, 14, and 45 are present, assert that the value of 04 == -14 and 45 == 04 for C, 2*45 == 04 for S
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be at most 8 components
                // the reduced container for size 8 will have component indices {0000, 0002, 0011, 0012, 0022, 0101, 0202, 2222};
                // if the component vector has 8 components, assert the values satisfy the constraint: For S, XX = 2 * [C(0,0) - C(0,1)]
                if (component_vector.size() > 7) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[5].Value() != 2 * (component_vector[0].Value() - component_vector[2].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::StiffnessType, mpc::core::Trigonal6SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  03  --  -- |
         *  | 01  00  02 -03  --  -- |
         *  | 02  02  22  --  --  -- |
         *  | 03 -03  --  33  --  -- |
         *  | --  --  --  --  33 *03 |
         *  | --  --  --  -- *03  XX |
         *
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         */

        // To be compliant
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        // TODO: if 03, 13, and 35 are present, assert that the value of 03 == -13 and 35 == 03 for C, 2*35 == 03 for S
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be at most 7 components
                // the reduced container for size 7 will have component indices {0000, 0011, 0012, 0022, 0101, 0202, 2222};
                // if the component vector has 7 components, assert the values satisfy the constraint: For C, XX = 0.5 * [C(0,0) - C(0,1)]
                if (component_vector.size() > 6) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[4].Value() != 0.5 * (component_vector[0].Value() - component_vector[1].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::ComplianceType, mpc::core::Trigonal6SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  02  03  --  -- |
         *  | 01  00  02 -03  --  -- |
         *  | 02  02  22  --  --  -- |
         *  | 03 -03  --  33  --  -- |
         *  | --  --  --  --  33 *03 |
         *  | --  --  --  -- *03  XX |
         *
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         */

        // To be compliant
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,2,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        // TODO: if 03, 13, and 35 are present, assert that the value of 03 == -13 and 35 == 03 for C, 2*35 == 03 for S
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; there should be at most 7 components
                // the reduced container for size 7 will have component indices {0000, 0011, 0012, 0022, 0101, 0202, 2222};
                // if the component vector has 7 components, assert the values satisfy the constraint: For S, XX =   2 * [S(0,0) - S(0,1)]
                if (component_vector.size() > 6) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[4].Value() != 2 * (component_vector[0].Value() - component_vector[1].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T, typename CS>
struct IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::CubicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  01  --  --  -- |
         *  | 01  00  01  --  --  -- |
         *  | 01  01  00  --  --  -- |
         *  | --  --  --  33  --  -- |
         *  | --  --  --  --  33  -- |
         *  | --  --  --  --  --  33 |
         */

        // To be compliant:
        //     >> the reduced set can have no more than 3 non-zero valued components and those components must belong to the set of non-zero values (in matrix notation) {00, 01, 33}
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {

                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the reduced container could be obtained here; for a vector use std::unique; better still, just use a set.  That set should have only 3 components
                //     corresponding to the nonzero_indices_set
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::StiffnessType, mpc::core::IsotropicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  01  --  --  -- |
         *  | 01  00  01  --  --  -- |
         *  | 01  01  00  --  --  -- |
         *  | --  --  --  XX  --  -- |
         *  | --  --  --  --  XX  -- |
         *  | --  --  --  --  --  XX |
         *
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         */

        // same as cubic with additional constraint that
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {

                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the vector should now have at maximum 3 components with their index reduced; the next step is assert that the values match the constraint: For C, XX = 0.5 * [C(0,0) - C(0,1)]
                //     if they do not, the set is not isotropic symmetry compliant and has cubic symmetry
                if (component_vector.size() > 2) {
                        //T value_check  = 0.5 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[2].Value() != 0.5 * (component_vector[0].Value() - component_vector[1].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};

template <typename T>
struct IsComponentSetSymmetryCompliantFunctionObject<T, mpc::core::ComplianceType, mpc::core::IsotropicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        /*
         *  | 00  01  01  --  --  -- |
         *  | 01  00  01  --  --  -- |
         *  | 01  01  00  --  --  -- |
         *  | --  --  --  XX  --  -- |
         *  | --  --  --  --  XX  -- |
         *  | --  --  --  --  --  XX |
         *
         * For C, XX = 0.5 * [C(0,0) - C(0,1)]
         * For S, XX =   2 * [S(0,0) - S(0,1)]
         */

        // same as cubic with additional constraint that
        bool operator()(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
                std::set<mpc::core::TensorRank4ComponentIndex> nonzero_indices_set{
                        //mpc::core::TensorRank4ComponentIndex(0,0,0,0)
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // a little verbose, but illustrates the point
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
                        mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2))
                };

                // if any reduced component index is not in the set of non-zero valued component indices AND the value is non-zero, the set is not symmetry compliant.
                //     If the value is zero and not in the set of non-zero indices, discard by not inserting it into the analysis set...
                std::vector<mpc::core::TensorRankNComponent<T,4> > component_vector{}; // ??? not sure, but have to be careful when using aliases like TensorRank4Component<T>

                mpc::core::TensorRank4ComponentIndex tmp_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0); // initialize a temporary variable of type...
                bool is_in_set_nonzero = false; // agian, just initializing before the loop
                for (auto s : component_set) {
                        tmp_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(s.Index());
                        is_in_set_nonzero = nonzero_indices_set.find(tmp_reduced) != nonzero_indices_set.end();
                        if (!is_in_set_nonzero && s.Value() != 0) { return false; }
                        if (is_in_set_nonzero && s.Value() !=0) {
                                component_vector.push_back(mpc::core::TensorRank4Component<T>(s.Value(), tmp_reduced)); // add component with same value but reduced index to the analysis vector
                        }
                }
                // all the components in component_vector belong to the set of non-zero valued indices and have a non-zero value...

                // sort the components (i.e. the component indices which are used of operators <,>)
                std::sort(component_vector.begin(), component_vector.end());

                // test if any two components that now have the same reduced indices also have the same value; if they do not, the set is not symmetry compliant
                //std::vector<mpc::core::TensorRank4Component<T>>::iterator it;
                //mpc::core::TensorRank4Component<T> tmp = mpc::core::TensorRank4Component<T>(0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
                mpc::core::TensorRank4Component<T> tmp = component_vector[0];
                mpc::core::TensorRank4Component<T> tmp2 = component_vector[1]; // just for initialization
                for (auto it = component_vector.begin()+1; it !=component_vector.end(); ++it) {
                        tmp2 = *it;
                        if (tmp.Index() == tmp2.Index() && tmp.Value() != tmp2.Value()) { return false; }
                        tmp = *it;
                }

                // the vector should now have at maximum 3 components with their index reduced; the next step is assert that the values match the constraint: For S, XX =   2 * [S(0,0) - S(0,1)]
                //     if they do not, the set is not isotropic symmetry compliant and has cubic symmetry
                if (component_vector.size() > 2) {
                        //T value_check  = 2 * (component_vector[0].Value() - component_vector[1].Value());
                        if (component_vector[2].Value() != 2 * (component_vector[0].Value() - component_vector[1].Value())) { return false; }
                }
//         for (auto v : component_vector) {
//             std::cout << "symmetry compliant v : " << v << std::endl;
//         }

                return true;
        }
};


// function template
/**
* \fn bool IsComponentSetSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief function that creates a specialized function object to determine if the given set of components compiles with the constraints of the symmetry argument
*/
template <typename T, typename CS, typename S = mpc::core::NoneSymmetryGroupType>
bool IsComponentSetSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, S> fo;
        return fo(component_set);
}


// ======
// convenience function
/**
* \fn bool IsComponentSetTriclinicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetTriclinicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::TriclinicSymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetMonoclinicX2SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetMonoclinicX2SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::MonoclinicX2SymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetMonoclinicX3SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetMonoclinicX3SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::MonoclinicX3SymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetOrthorhombicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetOrthorhombicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::OrthorhombicSymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetHexagonalSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetHexagonalSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::HexagonalSymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetTetragonal7SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetTetragonal7SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::Tetragonal7SymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetTetragonal6SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetTetragonal6SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::Tetragonal6SymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetTrigonal7SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetTrigonal7SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::Trigonal7SymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetTrigonal6SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetTrigonal6SymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::Trigonal6SymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetCubicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetCubicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::CubicSymmetryGroupType> fo;
        return fo(component_set);
}

/**
* \fn bool IsComponentSetIsotropicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >&)
* \brief convenience function for IsComponentSetSymmetryCompliant
*/
template <typename T, typename CS>
bool IsComponentSetIsotropicSymmetryCompliant(const std::set<mpc::core::TensorRank4Component<T> >& component_set) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        IsComponentSetSymmetryCompliantFunctionObject<T, CS, mpc::core::IsotropicSymmetryGroupType> fo;
        return fo(component_set);
}


} // namespace core
} // namespace mpc




#endif // MPC_SYMMETRYPREDICATES_H
