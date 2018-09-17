/**
 *    @file symmetrycomponents.hpp
 *    @brief functions and function objects for extracting components of the
 * stiffness or compliance tensor that are related in matrix notation form
 *
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_SYMMETRYCOMPONENTS_H
#define MPC_SYMMETRYCOMPONENTS_H

#include <set>
#include <tuple>
#include <utility>  // std::pair<>
#include <functional>
#include <iostream>
#include <iterator>  // for std::advance<> : https://en.cppreference.com/w/cpp/iterator/advance
#include <algorithm>  // std::set_difference
#include <cassert>

// mpc
#include "tensorcomponent.hpp"
#include "tensorcomponentindexaliases.hpp"
#include "tensorcomponentindexpredicates.hpp"
#include "symmetrygrouptypes.hpp"
#include "cstypes.hpp"
#include "symmetrypredicates.hpp"
#include "../util/matrixnotation.hpp"

namespace mpc {
namespace core {

// common functions for the relationship among symmetry elements
template <typename T>
void CequalsTwoTimesTheDifferenceOfAandB(mpc::core::TensorRank4Component<T>& c, mpc::core::TensorRank4Component<T>& a, mpc::core::TensorRank4Component<T>& b) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        // NOTE the order of the parameters!!! very important
        // commonly used function for compliance [matrix] where S55 = 2 * (S00 - S01)
        if (a.Value() != 0 && b.Value() != 0) {
                T c_value = 2 * (a.Value() - b.Value());
                c.Value(c_value); // set the value of the component
                //std::cout << "   c_value :   " << c_value << std::endl;
                //std::cout << "   c.Value() : " << c.Value() << std::endl;
        }
        if (b.Value() != 0 && c.Value() != 0) {
                T a_value = (0.5 * c.Value()) + b.Value();
                a.Value(a_value);
                //std::cout << "   a_value :   " << a_value << std::endl;
                //std::cout << "   a.Value() : " << a.Value() << std::endl;
        }
        if (a.Value() != 0 && c.Value() != 0) {
                T b_value = a.Value() - (0.5 * c.Value());
                b.Value(b_value);
                //std::cout << "   a.Value() : " << a.Value() << std::endl;
                //std::cout << "   b_value :   " << b_value << std::endl;
                //std::cout << "   b.Value() : " << b.Value() << std::endl;
                //std::cout << "   c.Value() : " << c.Value() << std::endl;
        }
}

template <typename T>
void CequalsOneHalfTheDifferenceOfAandB(mpc::core::TensorRank4Component<T>& c, mpc::core::TensorRank4Component<T>& a, mpc::core::TensorRank4Component<T>& b) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        // NOTE the order of the parameters!!! very important
        // commonly used function for compliance [matrix] where C55 = 0.5 * (C00 - C01)
        //std::cout << "  CequalsOneHalfTheDifferenceOfAandB function called!" << std::endl;
        if (a.Value() != 0 && b.Value() != 0) {
                T c_value = 0.5 * (a.Value() - b.Value());
                c.Value(c_value); // set the value of the component
                //std::cout << "   c_value :   " << c_value << std::endl;
                //std::cout << "   c.Value() : " << c.Value() << std::endl;
        }
        if (b.Value() != 0 && c.Value() != 0) {
                T a_value = (2 * c.Value()) + b.Value();
                a.Value(a_value);
                //std::cout << "   a_value :   " << a_value << std::endl;
                //std::cout << "   a.Value() : " << a.Value() << std::endl;
        }
        if (a.Value() != 0 && c.Value() != 0) {
                T b_value = a.Value() - (2 * c.Value());
                b.Value(b_value);
                //std::cout << "   b_value :   " << b_value << std::endl;
                //std::cout << "   b.Value() : " << b.Value() << std::endl;
        }
}



// SymmetryLink : template class to resolve components in the stiffness or compliance tensor that are related
template <typename T, int M, int N, int P, int Q>
struct SymmetryComponentLinkFunctionObject {
        // when working with matrix notation, use TriclinicSymmetryGroupType; aliased components will have identical indices for a given symmetry group type that has "linked" components
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        static_assert(M<6 && M>=0, "M must be less than or equal to 5 and greater than or equal to 0");
        static_assert(N<6 && N>=0, "N must be less than or equal to 5 and greater than or equal to 0");
        static_assert(P<6 && P>=0, "P must be less than or equal to 5 and greater than or equal to 0");
        static_assert(Q<6 && Q>=0, "Q must be less than or equal to 5 and greater than or equal to 0");

        // {M,N} is the component index in matrix notation for the first index
        // {P,Q} is the component index in matrix notation for the section index

        // assume the relationship {M,N} = scalar * {P,Q};  most often scalar will just be one, but it may be -1, 0.5, or 2 depending on the symmetry and the CS type

        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> >  operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components, T scalar=T(1.0)) {
                //
                std::pair<int,int> m_indices = mpc::util::GetIndexFromVoigtMatrix(M);
                std::pair<int,int> n_indices = mpc::util::GetIndexFromVoigtMatrix(N);
                mpc::core::TensorRank4ComponentIndex indexmn = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(m_indices.first, m_indices.second, n_indices.first, n_indices.second));

                std::pair<int,int> p_indices = mpc::util::GetIndexFromVoigtMatrix(P);
                std::pair<int,int> q_indices = mpc::util::GetIndexFromVoigtMatrix(Q);
                mpc::core::TensorRank4ComponentIndex indexpq = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(p_indices.first, p_indices.second, q_indices.first, q_indices.second));

                // find the component in the component set to get its value
                T valuemn = 0;
                T valuepq = 0;
                for ( auto cmpt : components) {
                        if (mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(cmpt.Index()) == indexpq) { valuepq = cmpt.Value(); }
                        if (mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(cmpt.Index()) == indexmn) { valuemn = cmpt.Value(); }
                }

//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, indexmn : " << M << "," << N << "," << P << "," << Q << ", " << indexmn << std::endl;
//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, valuemn : " << M << "," << N << "," << P << "," << Q << ", " << valuemn << std::endl;
//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, indexpq : " << M << "," << N << "," << P << "," << Q << ", " << indexpq << std::endl;
//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, valuepq : " << M << "," << N << "," << P << "," << Q << ", " << valuepq << std::endl;

                // apply symmetry constraint
                if (valuemn != valuepq && valuemn == 0) { valuemn = scalar * valuepq; }
                if (valuemn != valuepq && valuepq == 0) { valuepq = (1/scalar) * valuemn; }

//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, indexmn : " << M << "," << N << "," << P << "," << Q << ", " << indexmn << std::endl;
//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, valuemn : " << M << "," << N << "," << P << "," << Q << ", " << valuemn << std::endl;
//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, indexpq : " << M << "," << N << "," << P << "," << Q << ", " << indexpq << std::endl;
//         std::cout << "    SymmetryComponentLinkFunctionObject M,N,P,Q, valuepq : " << M << "," << N << "," << P << "," << Q << ", " << valuepq << std::endl;

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > tmp{
                        mpc::core::TensorRank4Component<T>(valuemn, indexmn),
                        mpc::core::TensorRank4Component<T>(valuepq, indexpq)
                };

                return tmp;
        }
};

// SymmetryDualLink : template class to resolve components in the stiffness or compliance tensor that are related to two other components
template <typename T, int M, int N, int P, int Q, int R, int S>
struct SymmetryComponentDualLinkFunctionObject {
        // NOTE: the order here is very important.  The assumption is the component [M,N] is related to the componetns [P,Q] and [R,S], that is C = f(A,B)

        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        static_assert(M<6 && M>=0, "M must be less than or equal to 5 and greater than or equal to 0");
        static_assert(N<6 && N>=0, "N must be less than or equal to 5 and greater than or equal to 0");
        static_assert(P<6 && P>=0, "P must be less than or equal to 5 and greater than or equal to 0");
        static_assert(Q<6 && Q>=0, "Q must be less than or equal to 5 and greater than or equal to 0");

        // {M,N} is the component index in matrix notation for the first index
        // {P,Q} is the component index in matrix notation for the second index
        // {R,s} is the component index in matrix notation for the thrid index

        std::tuple<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> >  operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components, std::function<void(mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&)> func_t) {
                // NOTE: func_t should be a function that tells the program what to do with the 3 components, i.e. how they are related...
                std::pair<int,int> m_indices = mpc::util::GetIndexFromVoigtMatrix(M);
                std::pair<int,int> n_indices = mpc::util::GetIndexFromVoigtMatrix(N);
                mpc::core::TensorRank4ComponentIndex indexmn = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(m_indices.first, m_indices.second, n_indices.first, n_indices.second));
                //std::cout << "    indexmn : " << indexmn << std::endl;

                std::pair<int,int> p_indices = mpc::util::GetIndexFromVoigtMatrix(P);
                std::pair<int,int> q_indices = mpc::util::GetIndexFromVoigtMatrix(Q);
                mpc::core::TensorRank4ComponentIndex indexpq = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(p_indices.first, p_indices.second, q_indices.first, q_indices.second));
                //std::cout << "    indexpq : " << indexpq << std::endl;

                std::pair<int,int> r_indices = mpc::util::GetIndexFromVoigtMatrix(R);
                std::pair<int,int> s_indices = mpc::util::GetIndexFromVoigtMatrix(S);
                mpc::core::TensorRank4ComponentIndex indexrs = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(r_indices.first, r_indices.second, s_indices.first, s_indices.second));
                //std::cout << "    indexrs : " << indexrs << std::endl;

                //T valuemn = 0;
                //T valuepq = 0;
                //T valuers = 0;
                // use the std::funtion wrapper to assign values to the missing component
                mpc::core::TensorRank4Component<T> compmn = mpc::core::TensorRank4Component<T>(0,indexmn);
                mpc::core::TensorRank4Component<T> comppq = mpc::core::TensorRank4Component<T>(0,indexpq);
                mpc::core::TensorRank4Component<T> comprs = mpc::core::TensorRank4Component<T>(0,indexrs);

                for ( auto cmpt : components) {
                        if (mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(cmpt.Index()) == indexmn) { compmn = cmpt; }
                        if (mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(cmpt.Index()) == indexpq) { comppq = cmpt; }
                        if (mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(cmpt.Index()) == indexrs) { comprs = cmpt; }
                }

                func_t(compmn, comppq, comprs);

                std::tuple<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > tmp{ compmn, comppq, comprs };

                return tmp;
        }
};




// =================================================================================================================================
// Symmetry components function and function objects modify the input
//     std::set<TensorRank4Component> and add the additional components depending
//     on the Symmetry of the tensor.  This function [object] creates missing nonzero components
//     that are "linked" to other components or derived from two other components.  For
//     symmetry groups where no links exist, this function (and corresponding function objects)
//     does not make sense and should not modify the input set, i.e. do nothing.
//
//     This funciton considers only the reduced component indices corresponding to the upper-right
//     portion of the Voigt matrix; therefore, use TriclinicSymmetryGroupType when reducing indices.
//
//     Precondition: assumes the input set is symmetry compliant;  test the set with
//         IsComponentSetSymmetryCompliant<>() before calling TensorRank4SymmetryComponents<>().

template <typename T, typename CS, typename S=mpc::core::NoneSymmetryGroupType>
struct TensorRank4SymmetryComponentsFunctionObject {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                // does nothing when symmetry is NONE
        }
};


// partial specialization : TRIGONAL7
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::Trigonal7SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,1,1> sym_link_fo_00_11;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,2,1,2> sym_link_fo_02_12;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,4,4> sym_link_fo_33_44;
                mpc::core::SymmetryComponentLinkFunctionObject<T,1,3,0,3> sym_link_fo_13_03;
                mpc::core::SymmetryComponentLinkFunctionObject<T,4,5,0,3> sym_link_fo_45_03;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,4,1,4> sym_link_fo_04_14;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,5,1,4> sym_link_fo_35_14;

                std::function<void(mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&)> f = CequalsOneHalfTheDifferenceOfAandB<T>;
                mpc::core::SymmetryComponentDualLinkFunctionObject<T,5,5,0,0,0,1> sym_dual_link_fo_55_00_01;

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11 = sym_link_fo_00_11(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c02_12 = sym_link_fo_02_12(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44 = sym_link_fo_33_44(components, 1.0);
                components.insert(c00_11.first);
                components.insert(c00_11.second);
                components.insert(c02_12.first);
                components.insert(c02_12.second);
                components.insert(c33_44.first);
                components.insert(c33_44.second);

                // Careful, when 2 links are present in the symmetry, only one of the 3 values must present in the set and this makes the order of the following important
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c13_03 = sym_link_fo_13_03(components, -1.0);
                if (c13_03.first.Value() != 0 && c13_03.second.Value() != 0) {
                        components.insert(c13_03.first);
                        components.insert(c13_03.second);
                }

                T sclr = static_cast<T>(1.0); // link to heavy dot component (see Nye)
                if (CS::CSEnum() == mpc::core::CSEnumeration::COMPLIANCE) {
                        sclr = static_cast<T>(2.0);
                }
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c45_03 = sym_link_fo_45_03(components, sclr);
                if (c45_03.first.Value() != 0 && c45_03.second.Value() != 0) {
                        components.insert(c45_03.first);
                        components.insert(c45_03.second);
                }

                if (c13_03.first.Value() == 0 || c13_03.second.Value() == 0) {
                        // call it again; 03 and 13 must have missing from the set previously
                        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c13_03b = sym_link_fo_13_03(components, -1.0);
                        components.insert(c13_03b.first);
                        components.insert(c13_03b.second);
                }

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c04_14 = sym_link_fo_04_14(components, -1.0);
                if (c04_14.first.Value() != 0 && c04_14.second.Value() != 0) {
                        components.insert(c04_14.first);
                        components.insert(c04_14.second);
                }

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c35_14 = sym_link_fo_35_14(components, sclr);
                if (c35_14.first.Value() != 0 && c35_14.second.Value() != 0) {
                        components.insert(c35_14.first);
                        components.insert(c35_14.second);
                }

                if (c04_14.first.Value() == 0 || c04_14.second.Value() == 0) {
                        // call it again; 03 and 13 must have missing from the set previously
                        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c04_14b = sym_link_fo_04_14(components, -1.0);
                        components.insert(c04_14b.first);
                        components.insert(c04_14b.second);
                }

                std::tuple<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > sym_dual_link_tuple = sym_dual_link_fo_55_00_01(components,f);

                // use tuple::get<> member function to get the output components and insert into the components set
                components.insert(std::get<0>(sym_dual_link_tuple));
                components.insert(std::get<1>(sym_dual_link_tuple));
                components.insert(std::get<2>(sym_dual_link_tuple));
        }
};


// partial specialization : TRIGONAL6
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::Trigonal6SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,1,1> sym_link_fo_00_11;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,2,1,2> sym_link_fo_02_12;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,4,4> sym_link_fo_33_44;
                mpc::core::SymmetryComponentLinkFunctionObject<T,1,3,0,3> sym_link_fo_13_03;
                mpc::core::SymmetryComponentLinkFunctionObject<T,4,5,0,3> sym_link_fo_45_03;

                std::function<void(mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&)> f = CequalsOneHalfTheDifferenceOfAandB<T>;
                mpc::core::SymmetryComponentDualLinkFunctionObject<T,5,5,0,0,0,1> sym_dual_link_fo_55_00_01;

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11 = sym_link_fo_00_11(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c02_12 = sym_link_fo_02_12(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44 = sym_link_fo_33_44(components, 1.0);
                components.insert(c00_11.first);
                components.insert(c00_11.second);
                components.insert(c02_12.first);
                components.insert(c02_12.second);
                components.insert(c33_44.first);
                components.insert(c33_44.second);

                // Careful, when 2 links are present in the symmetry, only one of the 3 values must present in the set and this makes the order of the following important
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c13_03 = sym_link_fo_13_03(components, -1.0);
                if (c13_03.first.Value() != 0 && c13_03.second.Value() != 0) {
                        components.insert(c13_03.first);
                        components.insert(c13_03.second);
                }

                T sclr = static_cast<T>(1.0); // link to heavy dot component (see Nye)
                if (CS::CSEnum() == mpc::core::CSEnumeration::COMPLIANCE) {
                        sclr = static_cast<T>(2.0);
                }
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c45_03 = sym_link_fo_45_03(components, sclr);
                if (c45_03.first.Value() != 0 && c45_03.second.Value() != 0) {
                        components.insert(c45_03.first);
                        components.insert(c45_03.second);
                }

                if (c13_03.first.Value() == 0 || c13_03.second.Value() == 0) {
                        // call it again; 03 and 13 must have missing from the set previously
                        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c13_03b = sym_link_fo_13_03(components, -1.0);
                        components.insert(c13_03b.first);
                        components.insert(c13_03b.second);
                }

                std::tuple<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > sym_dual_link_tuple = sym_dual_link_fo_55_00_01(components,f);

                // use tuple::get<> member function to get the output components and insert into the components set
                components.insert(std::get<0>(sym_dual_link_tuple));
                components.insert(std::get<1>(sym_dual_link_tuple));
                components.insert(std::get<2>(sym_dual_link_tuple));
        }
};



// partial specialization : TETRAGONAL7
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::Tetragonal7SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        // Tetragonal7 has 4 "linked" components
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                //
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,1,1> sym_link_fo_00_11;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,2,1,2> sym_link_fo_02_12;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,4,4> sym_link_fo_33_44;
                mpc::core::SymmetryComponentLinkFunctionObject<T,1,5,0,5> sym_link_fo_15_05;

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11 = sym_link_fo_00_11(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c02_12 = sym_link_fo_02_12(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44 = sym_link_fo_33_44(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c05_15 = sym_link_fo_15_05(components, -1.0);
                components.insert(c00_11.first);
                components.insert(c00_11.second);
                components.insert(c02_12.first);
                components.insert(c02_12.second);
                components.insert(c33_44.first);
                components.insert(c33_44.second);
                components.insert(c05_15.first);
                components.insert(c05_15.second);

        }
};


// partial specialization : TETRAGONAL6
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::Tetragonal6SymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        // Tetragonal6 has 3 "linked" components
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                //
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,1,1> sym_link_fo_00_11;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,2,1,2> sym_link_fo_02_12;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,4,4> sym_link_fo_33_44;

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11 = sym_link_fo_00_11(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c02_12 = sym_link_fo_02_12(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44 = sym_link_fo_33_44(components, 1.0);
                components.insert(c00_11.first);
                components.insert(c00_11.second);
                components.insert(c02_12.first);
                components.insert(c02_12.second);
                components.insert(c33_44.first);
                components.insert(c33_44.second);
        }
};


// partial specialization : HEXAGONAL
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::HexagonalSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        // Hexagonal symmetry [matrix] has 3 linked components and one dual link component
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                //
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,1,1> sym_link_fo_00_11;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,2,1,2> sym_link_fo_02_12;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,4,4> sym_link_fo_33_44;

                std::function<void(mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&)> f;
                if (CS::CSEnum() == mpc::core::CSEnumeration::STIFFNESS) {
                        f = CequalsOneHalfTheDifferenceOfAandB<T>;
                } else {
                        f = CequalsTwoTimesTheDifferenceOfAandB<T>;
                }
                mpc::core::SymmetryComponentDualLinkFunctionObject<T,5,5,0,0,0,1> sym_dual_link_fo_55_00_01;

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11 = sym_link_fo_00_11(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c02_12 = sym_link_fo_02_12(components, 1.0);
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44 = sym_link_fo_33_44(components, 1.0);
                components.insert(c00_11.first);
                components.insert(c00_11.second);
                components.insert(c02_12.first);
                components.insert(c02_12.second);
                components.insert(c33_44.first);
                components.insert(c33_44.second);

                std::tuple<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > sym_dual_link_tuple = sym_dual_link_fo_55_00_01(components,f);
                // use tuple::get<> member function to get the output components and insert into the components set
                components.insert(std::get<0>(sym_dual_link_tuple));
                components.insert(std::get<1>(sym_dual_link_tuple));
                components.insert(std::get<2>(sym_dual_link_tuple));
        }
};










// partial specialization : CUBIC
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::CubicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,1,1> sym_link_fo_00_11;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,0,2,2> sym_link_fo_00_22;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,1,0,2> sym_link_fo_01_02;
                mpc::core::SymmetryComponentLinkFunctionObject<T,0,1,1,2> sym_link_fo_01_12;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,4,4> sym_link_fo_33_44;
                mpc::core::SymmetryComponentLinkFunctionObject<T,3,3,5,5> sym_link_fo_33_55;

                // Careful, when 2 links are present in the symmetry, only one of the 3 values must present in the set and this makes the order of the following important
                // {00,11,22}
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11 = sym_link_fo_00_11(components, 1.0);
                if (c00_11.first.Value() != 0 && c00_11.second.Value() != 0) {
                        components.insert(c00_11.first);
                        components.insert(c00_11.second);
                }

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_22 = sym_link_fo_00_22(components, 1.0);
                if (c00_22.first.Value() != 0 && c00_22.second.Value() != 0) {
                        components.insert(c00_22.first);
                        components.insert(c00_22.second);
                }

                if (c00_11.first.Value() == 0 || c00_11.second.Value() == 0) {
                        // call it again; 00 and 11 must have missing from the set previously
                        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c00_11b = sym_link_fo_00_11(components, 1.0);
                        components.insert(c00_11b.first);
                        components.insert(c00_11b.second);
                }

                // {01,02,12}
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c01_02 = sym_link_fo_01_02(components, 1.0);
                if (c01_02.first.Value() != 0 && c01_02.second.Value() != 0) {
                        components.insert(c01_02.first);
                        components.insert(c01_02.second);
                }

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c01_12 = sym_link_fo_01_12(components, 1.0);
                if (c01_12.first.Value() != 0 && c01_12.second.Value() != 0) {
                        components.insert(c01_12.first);
                        components.insert(c01_12.second);
                }

                if (c01_02.first.Value() == 0 || c01_02.second.Value() == 0) {
                        // call it again; 01 and 02 must have missing from the set previously
                        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c01_02b = sym_link_fo_01_02(components, 1.0);
                        components.insert(c01_02b.first);
                        components.insert(c01_02b.second);
                }

                // {33,44,55}
                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44 = sym_link_fo_33_44(components, 1.0);
                if (c33_44.first.Value() != 0 && c33_44.second.Value() != 0) {
                        components.insert(c33_44.first);
                        components.insert(c33_44.second);
                }

                std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_55 = sym_link_fo_33_55(components, 1.0);
                if (c33_55.first.Value() != 0 && c33_55.second.Value() != 0) {
                        components.insert(c33_55.first);
                        components.insert(c33_55.second);
                }

                if (c33_44.first.Value() == 0 || c33_44.second.Value() == 0) {
                        // call it again; 33 and 44 must have missing from the set previously
                        std::pair<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > c33_44b = sym_link_fo_33_44(components, 1.0);
                        components.insert(c33_44b.first);
                        components.insert(c33_44b.second);
                }
        }
};


// partial specialization : ISOTROPIC
template <typename T, typename CS>
struct TensorRank4SymmetryComponentsFunctionObject<T, CS, mpc::core::IsotropicSymmetryGroupType> {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        void operator()(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
                std::function<void(mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&,mpc::core::TensorRank4Component<T>&)> f;
                if (CS::CSEnum() == mpc::core::CSEnumeration::STIFFNESS) {
                        f = CequalsOneHalfTheDifferenceOfAandB<T>;
                } else {
                        f = CequalsTwoTimesTheDifferenceOfAandB<T>;
                }

                mpc::core::SymmetryComponentDualLinkFunctionObject<T,5,5,0,0,0,1> sym_dual_link_fo_55_00_01;
                // generate the X33, X44, or X55 component
                std::tuple<mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4>,mpc::core::TensorRankNComponent<T,4> > sym_dual_link_tuple = sym_dual_link_fo_55_00_01(components,f);

                // use tuple::get<> member function to get the output components and insert into the components set
                components.insert(std::get<0>(sym_dual_link_tuple));
                components.insert(std::get<1>(sym_dual_link_tuple));
                components.insert(std::get<2>(sym_dual_link_tuple));

                mpc::core::TensorRank4SymmetryComponentsFunctionObject<T,CS,mpc::core::CubicSymmetryGroupType> symmetry_components_fo;
                symmetry_components_fo(components);
        }
};




// convenience function that creates the function object and calls it
template <typename T, typename CS, typename S>
void TensorRank4SymmetryComponents(std::set<mpc::core::TensorRankNComponent<T,4> >& components) {
        // create the specialized function object at compile time depending on the rank4 tensor type (either StiffnessType or ComplianceType) and the SymmetryGroupType, e.g. TRICLINIC, ORTHORHOMBIC, VTI, etc.  NOTE the default is NONE.
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        // create the function object...
        mpc::core::TensorRank4SymmetryComponentsFunctionObject<T,CS,S> symmetry_components_fo;
        symmetry_components_fo(components);

}



} // namespace core
} // namespace mpc

#endif // MPC_SYMMETRYCOMPONENTS_H
