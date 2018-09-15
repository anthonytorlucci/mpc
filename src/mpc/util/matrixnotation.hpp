#ifndef MPC_MATRIXNOTATION_H
#define MPC_MATRIXNOTATION_H

// c++ standard
#include <vector>
#include <set>
#include <iostream>
#include <utility>

// blitz
#include <blitz/array.h>

// mpc
#include "mpc/util/constants.hpp"
#include "mpc/util/kroneckerdelta.hpp"

namespace mpc {
namespace util {

//==============================================================================
// REMEMBER... ZERO BASED INDEXING!!!

//// 0,0
template <int P=0, int Q=0>
constexpr inline int CGetVoigtMatrixIndex() { return 0; }

//// 0,1
template <>
constexpr inline int CGetVoigtMatrixIndex<0,1>() { return 5; }

//// 0,2
template <>
constexpr inline int CGetVoigtMatrixIndex<0,2>() { return 4; }

//// 1,0
template <>
constexpr inline int CGetVoigtMatrixIndex<1,0>() { return 5; }

//// 1,1
template <>
constexpr inline int CGetVoigtMatrixIndex<1,1>() { return 1; }

//// 1,2
template <>
constexpr inline int CGetVoigtMatrixIndex<1,2>() { return 3; }

//// 2,0
template <>
constexpr inline int CGetVoigtMatrixIndex<2,0>() { return 4; }

//// 2,1
template <>
constexpr inline int CGetVoigtMatrixIndex<2,1>() { return 3; }

//// 2,2
template <>
constexpr inline int CGetVoigtMatrixIndex<2,2>() { return 2; }

// // as a constexpr value known to the compiler at compile time
// //// 0,0
// template <int P=0, int Q=0>
// static constexpr int CVoigtMatrixIndex = 0;
// 
// //// 0,1
// template <>
// static constexpr int CVoigtMatrixIndex<0,1> = 5;
// 
// //// 0,2
// template <>
// static constexpr int CVoigtMatrixIndex<0,2> = 4;
// 
// //// 1,0
// template <>
// static constexpr int CVoigtMatrixIndex<1,0> = 5;
// 
// //// 1,1
// template <>
// static constexpr int CVoigtMatrixIndex<1,1> = 1;
// 
// //// 1,2
// template <>
// static constexpr int CVoigtMatrixIndex<1,2> = 3;
// 
// //// 2,0
// template <>
// static constexpr int CVoigtMatrixIndex<2,0>= 4;
// 
// //// 2,1
// template <>
// static constexpr int CVoigtMatrixIndex<2,1> = 3;
// 
// //// 2,2
// template <>
// static constexpr int CVoigtMatrixIndex<2,2> = 2;



// =============================================================================
// =============================================================================
// =============================================================================

//// 0
template <int P=0>
constexpr inline int CGetFirstIndexFromVoigtMatrix() { return 0; }

template <int P=0>
constexpr inline int CGetSecondIndexFromVoigtMatrix() { return 0; }


//// 1
template <>
constexpr inline int CGetFirstIndexFromVoigtMatrix<1>() { return 1; }

template <>
constexpr inline int CGetSecondIndexFromVoigtMatrix<1>() { return 1; }


//// 2
template <>
constexpr inline int CGetFirstIndexFromVoigtMatrix<2>() { return 2; }

template <>
constexpr inline int CGetSecondIndexFromVoigtMatrix<2>() { return 2; }


//// 3
template <>
constexpr inline int CGetFirstIndexFromVoigtMatrix<3>() { return 1; }

template <>
constexpr inline int CGetSecondIndexFromVoigtMatrix<3>() { return 2; }


//// 4
template <>
constexpr inline int CGetFirstIndexFromVoigtMatrix<4>() { return 0; }

template <>
constexpr inline int CGetSecondIndexFromVoigtMatrix<4>() { return 2; }


//// 5
template <>
constexpr inline int CGetFirstIndexFromVoigtMatrix<5>() { return 0; }

template <>
constexpr inline int CGetSecondIndexFromVoigtMatrix<5>() { return 1; }

// as a constexpr value

    
// =============================================================================
// =============================================================================
// =============================================================================
    
// Tsvankin, 2001
inline
int GetVoigtMatrixIndex(int ibase0, int jbase0) {
    // NOTE:
    // TODO: assert ibase1 and jbase1 belong to the set {1,2,3}
    blitz::Array<int,2> kdelta = mpc::util::KroneckerDelta<int,3>();
    int ibase1 = ibase0 + 1;
    int jbase1 = jbase0 + 1;
    int p = (ibase1 * kdelta(ibase0,jbase0)) + (9-ibase1-jbase1) * (1 - kdelta(ibase0,jbase0));
    return p-1;

}

inline
std::pair<int,int> GetIndexFromVoigtMatrix(int pbase0){
    // NOTE:
    // assert p belongs to the set {0,1,2,3,4,5}
    assert(pbase0 >= 0);
    assert(pbase0 < 6);

    switch (pbase0) {
    case 0 :
        //index_ij[0] = 0;
        //index_ij[1] = 0;
        return std::pair<int,int>(0,0);
    case 1 :
        //index_ij[0] = 1;
        //index_ij[1] = 1;
        return std::pair<int,int>(1,1);
    case 2 :
        //index_ij[0] = 2;
        //index_ij[1] = 2;
        return std::pair<int,int>(2,2);
    case 3 :
        //index_ij[0] = 1;
        //index_ij[1] = 2;
        return std::pair<int,int>(1,2);
    case 4 :
        //index_ij[0] = 0;
        //index_ij[1] = 2;
        return std::pair<int,int>(0,2);
    case 5 :
        //index_ij[0] = 0;
        //index_ij[1] = 1;
        return std::pair<int,int>(0,1);
    default:
        // should never reach this...
        return std::pair<int,int>(int(),int());
    }
}

template <typename T>
void VoigtMatrixToStiffnessTensor(blitz::Array<T,2>& c_voigt, blitz::Array<T,4>& c)
{
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    int p;
    int q;

    // convert from Voigt to full tensor
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    p = GetVoigtMatrixIndex(i,j);
                    q = GetVoigtMatrixIndex(k,l);
                    //std::cout << "c_voigt(" << p << "," << q << ") = " << c_voigt(p,q) << std::endl;
                    c(i,j,k,l) = c_voigt(p,q);
                }
            }
        }
    }
}

template <typename T>
T VoigtMatrixToComplianceTensorScaleFactor(int p, int q)
{
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    // determines the scaling factor 1,2, or 4 depending on the values of indices m,n
    std::set<int> set123{0,1,2};
    std::set<int> set456{3,4,5};
    // for debug; better to use range-based for loop!!!
    //        for (std::set<int>::iterator it=set123.begin(); it!=set123.end(); ++it) {
    //            std::cout << " " << *it << std::endl;
    //        }
    const bool p_is_in_123 = set123.find(p) != set123.end();
    const bool q_is_in_123 = set123.find(q) != set123.end();
    const bool p_is_in_456 = set456.find(p) != set456.end();
    const bool q_is_in_456 = set456.find(q) != set456.end();

    if (p_is_in_123 && q_is_in_123) { return T(1.0); }
    else if (p_is_in_456 && q_is_in_456) { return  T(4.0); }
    else { return T(2.0); }
}

template <typename T>
void VoigtMatrixToComplianceTensor(blitz::Array<T,2>& s_voigt, blitz::Array<T,4>& s)
{
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

    int p;
    int q;
    T factor;
    // convert from Voigt to full tensor
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    p = GetVoigtMatrixIndex(i,j);
                    q = GetVoigtMatrixIndex(k,l);
                    factor = VoigtMatrixToComplianceTensorScaleFactor<T>(p,q);
                    s(i,j,k,l) = T(1.0 / factor) * s_voigt(p,q);
                }
            }
        }
    }
}

template <typename T>
void VoigtMatrixToComplianceTensorNoFactor(blitz::Array<T,2>& s_voigt, blitz::Array<T,4>& s)
{
    // same as VoigtToComplianceTensor without applying the scale factor; use this function when using the matrix simply as a place holder as in the construction of ComplianceTensor<>
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

    int p;
    int q;
    // convert from Voigt to full tensor
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    p = GetVoigtMatrixIndex(i,j);
                    q = GetVoigtMatrixIndex(k,l);
                    s(i,j,k,l) = s_voigt(p,q);
                }
            }
        }
    }
}

}  // namespace core
}  // namespace mpc

#endif //MPC_MATRIXNOTATION_H
