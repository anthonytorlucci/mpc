#include "mpcx_symmetrytypes.hpp"

// c++
#include <iostream>

// mpc
#include <mpc/core/symmetrygrouptypes.hpp>
#include <mpc/core/symmetrypredicates.hpp>
#include <mpc/core/symmetrycomponents.hpp>

#include "parametervaluetest.hpp"

void mpcexamples::mpcSymmetryTypes() {
    /** symmetry */

    /*
    * Now, for symmerty, specifically symmetry of 4th rank tensors
    *     corresponding to:
    *
    *     c(i,j,k,l) = c(j,i,k,l) = c(i,j,l,k) = c(l,k,i,j)
    *
    *     that is, triclinic symmetry.  Additional symmetry groups are
    *         specializations of triclinic symmetry...
    *
    * SymmetryGroupEnumeration and corresponding SymmetryGroupType class
    *     NONE             >> NoneSymmetryGroupType
    *     TRICLINIC        >> TriclinciSymmetryGroupType
    *     MONOCLINIC_X2    >> MonoclinicX2SymmetryGroupType
    *     MONOCLINIC_X3    >> MonoclinicX3SymmetryGroupType
    *     ORTHORHOMBIC     >> OrthorhombicSymemtryGroupType
    *     HEXAGONAL        >> HexagonalSymmetryType
    *     TETRAGONAL7      >> Tetragonal7SymmetryType
    *     TETRAGONAL6      >> Tetragonal6SymmetryType
    *     TRIGONAL7        >> Trigonal7SymmetryType
    *     TRIGONAL6        >> Trigonal6SymmetryType
    *     CUBIC            >> CubicSymmetryType
    *     ISOTROPIC        >> IsotropicSymmetryType
    *
    * Each symmetry type is a subclass of SymmetryGroupBase and has (currently)
    *     two data members:
    *         SymmetryGroupEnumeration symmetry_group_enumeration
    *         int number_of_independent_components
    */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    mpc::core::NoneSymmetryGroupType none_symmetry_type =
            mpc::core::NoneSymmetryGroupType();
    std::cout << "NoneSymmetryGroupType symmetry : "
              << none_symmetry_type.symmetry_group_enumeration << std::endl; // SymmetryGroupEnumeration::NONE
    std::cout << "NoneSymmetryGroupType number of independent components : "
              << none_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::TriclinicSymmetryGroupType triclinic_symmetry_type =
            mpc::core::TriclinicSymmetryGroupType();
    std::cout << "TriclinicSymmetryGroupType symmetry : "
              << triclinic_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "TriclinicSymmetryGroupType number of independent components : "
              << triclinic_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::MonoclinicX2SymmetryGroupType monoclinicX2_symmetry_type =
            mpc::core::MonoclinicX2SymmetryGroupType();
    std::cout << "MonoclinicX2SymmetryGroupType symmetry : "
              << monoclinicX2_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType number of independent components : "
              << monoclinicX2_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::MonoclinicX3SymmetryGroupType monoclinicX3_symmetry_type =
            mpc::core::MonoclinicX3SymmetryGroupType();
    std::cout << "MonoclinicX3SymmetryGroupType symmetry : "
              << monoclinicX3_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType number of independent components : "
              << monoclinicX3_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::OrthorhombicSymmetryGroupType orthorhombic_symmetry_type =
            mpc::core::OrthorhombicSymmetryGroupType();
    std::cout << "OrthorhombicSymmetryGroupType symmetry : "
              << orthorhombic_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType number of independent components : "
              << orthorhombic_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::HexagonalSymmetryGroupType hexagonal_symmetry_type =
            mpc::core::HexagonalSymmetryGroupType();
    std::cout << "HexagonalSymmetryGroupType symmetry : "
              << hexagonal_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "HexagonalSymmetryGroupType number of independent components : "
              << hexagonal_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::Tetragonal7SymmetryGroupType tetragonal7_symmetry_type =
            mpc::core::Tetragonal7SymmetryGroupType();
    std::cout << "Tetragonal7SymmetryGroupType symmetry : "
              << tetragonal7_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType number of independent components : "
              << tetragonal7_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::Tetragonal6SymmetryGroupType tetragonal6_symmetry_type =
            mpc::core::Tetragonal6SymmetryGroupType();
    std::cout << "Tetragonal6SymmetryGroupType symmetry : "
              << tetragonal6_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType number of independent components : "
              << tetragonal6_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::Trigonal7SymmetryGroupType trigonal7_symmetry_type =
            mpc::core::Trigonal7SymmetryGroupType();
    std::cout << "Trigonal7SymmetryGroupType symmetry : "
              << trigonal7_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "Trigonal7SymmetryGroupType number of independent components : "
              << trigonal7_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::Trigonal6SymmetryGroupType trigonal6_symmetry_type =
            mpc::core::Trigonal6SymmetryGroupType();
    std::cout << "Trigonal6SymmetryGroupType symmetry : "
              << trigonal6_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "Trigonal6SymmetryGroupType number of independent components : "
              << trigonal6_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::CubicSymmetryGroupType cubic_symmetry_type =
            mpc::core::CubicSymmetryGroupType();
    std::cout << "CubicSymmetryGroupType symmetry : "
              << cubic_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "CubicSymmetryGroupType number of independent components : "
              << cubic_symmetry_type.number_of_independent_components << std::endl;

    mpc::core::IsotropicSymmetryGroupType isotropic_symmetry_type =
            mpc::core::IsotropicSymmetryGroupType();
    std::cout << "IsotropicSymmetryGroupType symmetry : "
              << isotropic_symmetry_type.symmetry_group_enumeration << std::endl;
    std::cout << "IsotropicSymmetryGroupType number of independent components : "
              << isotropic_symmetry_type.number_of_independent_components << std::endl;

    /*
    * Symmetry type predicates...
    *
    * Type predicates or type traits are boolean functions on types [ref]...
    *
    * Note that these predicates are convenience functions derived from the
    *     more general
    *
    *     template <typename S, int N>
    *     constexpr inline bool SymmetryGroupTypeHasNIndependentComponents();
    *     (see symmetrypredicates.h for implementation details)
    */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    // has 21 components
    std::cout << "NoneSymmetryGroupType has 21 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 21 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 21 independent components ? "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 21 independent components ? "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 21 independent components ? "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 21 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 21 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 21 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 21 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 21 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 21 independent components ?        "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 21 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 13 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 13 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 13 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 13 independent components ? "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 13 independent components ? "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 13 independent components ? "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 13 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 13 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 13 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 13 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 13 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 13 independent components ?        "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 13 independent components ?    "
              << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 9 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 9 independent components ?          "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 9 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 9 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 9 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 9 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 9 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 9 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 9 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 9 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 9 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 9 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 9 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 7 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 7 independent components ?          "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 7 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 7 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 7 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 7 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 7 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 7 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 7 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 7 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 7 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 7 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 7 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 6 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 6 independent components ?          "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 6 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 6 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 6 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 6 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 6 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 6 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 6 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 6 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 6 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 6 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 6 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 5 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 5 independent components ?          "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 5 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 5 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 5 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>()<< std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 5 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 5 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::HexagonalSymmetryGroupType>()<< std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 5 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 5 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 5 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 5 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 5 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 5 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 3 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 3 independent components ?          "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 3 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 3 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 3 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 3 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 3 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 3 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 3 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 3 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 3 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 3 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 3 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    // has 2 components
    std::cout << "" << std::endl;
    std::cout << "NoneSymmetryGroupType has 2 independent components ?          "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
    std::cout << "TriclinicSymmetryGroupType has 2 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX3SymmetryGroupType has 2 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
    std::cout << "MonoclinicX2SymmetryGroupType has 2 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
    std::cout << "OrthorhombicSymmetryGroupType has 2 independent components ?  "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
    std::cout << "HexagonalSymmetryGroupType has 2 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal7SymmetryGroupType has 2 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
    std::cout << "Tetragonal6SymmetryGroupType has 2 independent components ?   "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal7SymmetryGroupType has 2 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
    std::cout << "Trigonal6SymmetryGroupType has 2 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
    std::cout << "CubicSymmetryGroupType has 2 independent components ?         "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
    std::cout << "IsotropicSymmetryGroupType has 2 independent components ?     "
              << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

    /*
     * It is also possible to call the above predicate function using the SymmetryGroupType using alias
     *
     *    SymmetryGroupTypeHas21IndependentComponents<typename SymmetryGroupType<mpc::core::SymmetryGroupEnumeration::TRICLINIC>::type>()
     *
     * MPC provides another predicate funciton for the SymmetryGroupEnumeration does exactly that:
     * template<mpc::core::SymmetryGroupEnumeration Sym>
     * constexpr inline bool SymmetryGroupEnumerationHas21IndependentComponents() {
             return SymmetryGroupTypeHas21IndependentComponents<typename SymmetryGroupType<Sym>::type>();
           }
    */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    // 21 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 21 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 21 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 21 independent components ? "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 21 independent components ? "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 21 independent components ? "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 21 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 21 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 21 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 21 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 21 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 21 independent components ?        "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 21 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 13 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 13 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 13 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 13 independent components ? "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 13 independent components ? "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 13 independent components ? "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 13 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 13 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 13 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 13 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 13 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 13 independent components ?        "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 13 independent components ?    "
              << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 9 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 9 independent components ?          "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 9 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 9 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 9 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 9 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 9 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 9 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 9 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 9 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 9 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 9 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 9 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 7 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 7 independent components ?          "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 7 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 7 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 7 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 7 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 7 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 7 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 7 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 7 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 7 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 7 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 7 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 6 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 6 independent components ?          "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 6 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 6 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 6 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 6 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 6 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 6 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 6 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 6 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 6 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 6 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 6 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 5 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 5 independent components ?          "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 5 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 5 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 5 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 5 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 5 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 5 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 5 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 5 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 5 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 5 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 5 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 3 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 3 independent components ?          "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 3 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 3 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 3 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 3 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 3 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 3 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 3 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 3 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 3 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 3 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 3 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    // 2 components
    std::cout << "" << std::endl;
    std::cout << "SymmetryGroupEnumeration::NONE has 2 independent components ?          "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRICLINIC has 2 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 2 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 2 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 2 independent components ?  "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 2 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 2 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 2 independent components ?   "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 2 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 2 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::CUBIC has 2 independent components ?         "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
    std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 2 independent components ?     "
              << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

    /*
     * the **HasNNIndependentComponents<> functions are constexpr, return a
     *     bool (Literal Type), and can be used as template parameter values.
     *     For example:
     */
    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    auto ctest_none_has_21_components = mpcexamples::BooleanTypeParameterValueTest<mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::NoneSymmetryGroupType>()>();
    std::cout << "ctest_none_has_21_components : " << ctest_none_has_21_components << std::endl;

    auto ctest_triclinic_has_21_components = mpcexamples::BooleanTypeParameterValueTest<mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::TriclinicSymmetryGroupType>()>();
    std::cout << "ctest_triclinic_has_21_components : " << ctest_triclinic_has_21_components << std::endl;

    /*
     * In addition to the symmetry types (subclasses of SymmetryGroupBase),
     *     there are typedefs for each symmetry group enumeration defined in
     *     the symmetryenumeration.h file.  For example...
     *
     *     typedef std::integral_constant<SymmetryGroupEnumeration, SymmetryGroupEnumeration::NONE> symmetry_none_t;
     */
    //// traits...???

    /*
         * Because symmetry is important in understanding the mechanical properties
         *     of crystals,  MPC provides a convenient function to determine the
         *     symmetry from a set of components.
         *
         * Below are function predicates that take a
         *     std::set<TensorRank4Component<T>> as an argument...
         *     (see mpc/core/symmetrypredicates.h)
         *
         *
         * NOTE: component0011 and compoent1100 are aliases of each other if the
         *     symmetry of the stiffness or compliance tensor is not ::NONE.  That
         *     is to say, if the tensor has symmetry, triclinic or otherwise, these
         *     two components should be equivalent in value.  If they are not, the
         *     tensor symmetry will be of NoneSymmetryGroupType.
         */

    // since std::set<> uses operators < and >, and TensorRank4Component
    //      overloads those operators by comparing index only, attempting to
    //      insert two TensorRank4Components into the same set will not work.
    //      The second one will fail because it has the same index regardless
    //      of the value.  This important fact gaurantees uniqueness among a
    //      set of components.

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;
    bool is_symmetry_aliased_set_symmetry_compliant = false;

    // let's create some sets that we can use to test the predicates...
    // ISOTROPIC
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

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    };

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_03{
            mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(40.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    }; // NOTE: For C, XX = 0.5 * [C(0,0) - C(0,1)]; satisfies cubic as well

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_04{
            mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(160.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    }; // NOTE: For S, XX =   2 * [S(0,0) - S(0,1)]; satisfies cubic as well

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00);
    std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01);
    std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_02);
    std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_03);
    std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_04);
    std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_04);
    std::cout << "is isotropic symmetry aliased index set isotropic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    // CUBIC
    /*
    *  | 00  01  01  --  --  -- |
    *  | 01  00  01  --  --  -- |
    *  | 01  01  00  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  33  -- |
    *  | --  --  --  --  --  33 |
    */

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::CubicSymmetryGroupType>(isotropic_symmetry_aliased_set_03);
    std::cout << "is isotropic symmetry aliased index set cubic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::CubicSymmetryGroupType>(isotropic_symmetry_aliased_set_03);
    std::cout << "is isotropic symmetry aliased index set cubic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)) // X33 >> (1212), (1221), (2112), (2121)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
    std::cout << "is cubic symmetry aliased index set cubic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
    std::cout << "is cubic symmetry aliased index set cubic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_01);
    std::cout << "is cubic symmetry aliased index set cubic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_01);
    std::cout << "is cubic symmetry aliased index set cubic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(cubic_symmetry_aliased_set_01);
    std::cout << "is cubic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::IsotropicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
    std::cout << "is cubic symmetry aliased index set isotropic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;


    //  TRIGONAL6
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

    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
    std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
    std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
    std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
    std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
    std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
    std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    // TRIGONAL7
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

    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00);
    std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_01);
    std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_02);
    std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00);
    std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_01);
    std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_02);
    std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    // NOTE: REMEMBER, trigonal6 is a specialization of trigonal7; the additional 04 component in trigonal7 could be zero valued and thus would be symmetry compliant, but
    //     not the least symmetry.  You must test for trigonal6 before testing for trigonal7
    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
    std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
    std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
    std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
    std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
    std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
    std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;


    // TETRAGONAL6
    /*
    *  | 00  01  02  --  --  -- |
    *  | 01  00  02  --  --  -- |
    *  | 02  02  22  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  33  -- |
    *  | --  --  --  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
    std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_01);
    std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
    std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [complaince] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_01);
    std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    // TETRAGONAL7
    /*
    *  | 00  01  02  --  --  05 |
    *  | 01  00  02  --  -- -05 |
    *  | 02  02  22  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  33  -- |
    *  | 05 -05  --  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00);
    std::cout << "is tetragonal7 symmetry aliased index set tetragonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00);
    std::cout << "is tetragonal7 symmetry aliased index set tetragonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    // HEXAGONAL
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
    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00);
    std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_01);
    std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_02);
    std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00);
    std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_01);
    std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_02);
    std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;



    // ORTHORHOMBIC
    /*
    *  | 00  01  02  --  --  -- |
    *  | 01  11  12  --  --  -- |
    *  | 02  12  22  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  44  -- |
    *  | --  --  --  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > orthorhombic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::OrthorhombicSymmetryGroupType>(orthorhombic_symmetry_aliased_set_00);
    std::cout << "is orthorhombic symmetry aliased index set orthorhombic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::OrthorhombicSymmetryGroupType>(orthorhombic_symmetry_aliased_set_00);
    std::cout << "is orthorhombic symmetry aliased index set orthorhombic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    // NOTE: tetragonal6 is a specialization of orthorhombic with additional constraints, so these are true
    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::OrthorhombicSymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
    std::cout << "is tetragonal6 symmetry aliased index set orthorhombic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::OrthorhombicSymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
    std::cout << "is tetragonal6 symmetry aliased index set orthorhombic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;


    // MONOCLINIC_X3
    /*
    *  | 00  01  02  --  --  05 |
    *  | 01  11  12  --  --  15 |
    *  | 02  12  22  --  --  25 |
    *  | --  --  --  33  34  -- |
    *  | --  --  --  34  44  -- |
    *  | 05  15  25  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > monoclinicx3_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::MonoclinicX3SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
    std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx3 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::MonoclinicX3SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
    std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx3 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;


    // MONOCLINIC_X2
    /*
    *  | 00  01  02  --  04  -- |
    *  | 01  11  12  --  14  -- |
    *  | 02  12  22  --  24  -- |
    *  | --  --  --  33  --  35 |
    *  | 04  14  24  --  44  -- |
    *  | --  --  --  35  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > monoclinicx2_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx2_symmetry_aliased_set_00);
    std::cout << "is monoclinicx2 symmetry aliased index set monoclinicx2 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx2_symmetry_aliased_set_00);
    std::cout << "is monoclinicx2 symmetry aliased index set monoclinicx2 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
    std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx2 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
    std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx2 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;


    // TRICLINIC
    /*
    *  | 00  01  02  03  04  05 |
    *  | 01  11  12  13  14  15 |
    *  | 02  12  22  23  24  25 |
    *  | 03  13  23  33  34  35 |
    *  | 04  14  24  34  44  45 |
    *  | 05  15  25  35  45  55 |
    */

    std::set<mpc::core::TensorRank4Component<double> > triclinic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(2223.0, mpc::core::TensorRank4ComponentIndex(1,1,1,2)), // X13 >> (1112), (1121), (1211), (2111)
            mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
            mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(3323.0, mpc::core::TensorRank4ComponentIndex(2,2,1,2)), // X23 >> (2212), (2221), (1222), (2122)
            mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
            mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
            mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1312.0, mpc::core::TensorRank4ComponentIndex(0,2,0,1)), // X45 >> (0201), (0210), (2001), (2010), (0102), (1002), (0120), (1020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
    std::cout << "is triclinic symmetry aliased index set triclinic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
    std::cout << "is triclinic symmetry aliased index set triclinic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
    std::cout << "" << std::endl;

    /*
     * SYMMETRY COMPONENTS
     *     the TensorRank4SymmetryComponents template function modifies the input set and adds the missing components given the symmetry and the stiffness or
     *     compliance type; this template function is specialized for each symmetry, stiffness/compliance pair in a function object which is created at compile time...
     */

    // NOTE: there are no "links" in the triclinic symmetry group;  only the typical aliases when going from matrix notation to tensor notation
    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    /*  symmetry components   */
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
    for (auto comp : triclinic_symmetry_aliased_set_00) {
        std::cout << "triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    std::cout << "" << std::endl;
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
    for (auto comp : triclinic_symmetry_aliased_set_00) {
        std::cout << "triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(hexagonal_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00_copy);
    for (auto comp : hexagonal_symmetry_aliased_set_00_copy) {
        std::cout << "hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(hexagonal_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00_copy2);
    for (auto comp : hexagonal_symmetry_aliased_set_00_copy2) {
        std::cout << "hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(tetragonal6_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00_copy);
    for (auto comp : tetragonal6_symmetry_aliased_set_00_copy) {
        std::cout << "tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }
    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(tetragonal6_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00_copy2);
    for (auto comp : tetragonal6_symmetry_aliased_set_00_copy2) {
        std::cout << "tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(tetragonal7_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00_copy);
    for (auto comp : tetragonal7_symmetry_aliased_set_00_copy) {
        std::cout << "tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(tetragonal7_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00_copy2);
    for (auto comp : tetragonal7_symmetry_aliased_set_00_copy2) {
        std::cout << "tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(trigonal6_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00_copy);
    for (auto comp : trigonal6_symmetry_aliased_set_00_copy) {
        std::cout << "trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(trigonal6_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00_copy2);
    for (auto comp : trigonal6_symmetry_aliased_set_00_copy2) {
        std::cout << "trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(trigonal7_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00_copy);
    for (auto comp : trigonal7_symmetry_aliased_set_00_copy) {
        std::cout << "trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(trigonal7_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00_copy2);
    for (auto comp : trigonal7_symmetry_aliased_set_00_copy2) {
        std::cout << "trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }


    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(cubic_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00_copy);
    for (auto comp : cubic_symmetry_aliased_set_00_copy) {
        std::cout << "cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(cubic_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00_copy2);
    for (auto comp : cubic_symmetry_aliased_set_00_copy2) {
        std::cout << "cubic_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00_copy);
    for (auto comp : isotropic_symmetry_aliased_set_00_copy) {
        std::cout << "isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_00);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00_copy2);
    for (auto comp : isotropic_symmetry_aliased_set_00_copy2) {
        std::cout << "isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01_copy = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_01);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01_copy);
    for (auto comp : isotropic_symmetry_aliased_set_01_copy) {
        std::cout << "isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : " << comp << std::endl;
    }

    // NOTE: this function WILL modify the set by adding missing components!  Create a copy...
    std::cout << "" << std::endl;
    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01_copy2 = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_01);
    mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01_copy2);
    for (auto comp : isotropic_symmetry_aliased_set_01_copy2) {
        std::cout << "isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : " << comp << std::endl;
    }

}
