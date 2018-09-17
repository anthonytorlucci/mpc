/**
 *    @file csrelationship.hpp
 *    @brief functions and function objects to calculate the stiffness tensor
 * components from the compliance tensor components or vice versa
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_CSRELATIONSHIP_H
#define MPC_CSRELATIONSHIP_H

#include <iostream>

// blitz

// eigen
#include <Eigen/Dense>
#include <Eigen/QR>

// mpc
#include "cstypes.hpp"
#include "symmetrygrouptypes.hpp"
#include "stiffnesscompliance.hpp"
#include "../util/matrixnotation.hpp"

namespace mpc {
namespace core {

// ===============================================================================================================================
template <typename T, typename S=mpc::core::NoneSymmetryGroupType>
struct StiffnessFromComplianceFunctionObject {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
                // given the compliance tensor, fill the stiffness tensor...
                // the solution requires 6 systems of equations involving a [9x9] matrix of the compliance tensor, a [9x1] solution vector
                //     which contains the stiffness tensor, and a [9x1] vector from the identity tensor

                mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
                T zero = static_cast<T>(0.0);
                Eigen::Matrix<T,9,9> s_mat_sys1 = Eigen::Matrix<T,9,9>::Zero();
                s_mat_sys1 <<
                        s_ijkl.tensor(0,0,0,0), s_ijkl.tensor(0,1,0,0), s_ijkl.tensor(0,2,0,0), s_ijkl.tensor(1,0,0,0), s_ijkl.tensor(1,1,0,0), s_ijkl.tensor(1,2,0,0), s_ijkl.tensor(2,0,0,0),
                        s_ijkl.tensor(2,1,0,0), s_ijkl.tensor(2,2,0,0),
                        s_ijkl.tensor(0,0,0,1), s_ijkl.tensor(0,1,0,1), s_ijkl.tensor(0,2,0,1), s_ijkl.tensor(1,0,0,1), s_ijkl.tensor(1,1,0,1), s_ijkl.tensor(1,2,0,1), s_ijkl.tensor(2,0,0,1),
                        s_ijkl.tensor(2,1,0,1), s_ijkl.tensor(2,2,0,1),
                        s_ijkl.tensor(0,0,0,2), s_ijkl.tensor(0,1,0,2), s_ijkl.tensor(0,2,0,2), s_ijkl.tensor(1,0,0,2), s_ijkl.tensor(1,1,0,2), s_ijkl.tensor(1,2,0,2), s_ijkl.tensor(2,0,0,2),
                        s_ijkl.tensor(2,1,0,2), s_ijkl.tensor(2,2,0,2),
                        s_ijkl.tensor(0,0,1,0), s_ijkl.tensor(0,1,1,0), s_ijkl.tensor(0,2,1,0), s_ijkl.tensor(1,0,1,0), s_ijkl.tensor(1,1,1,0), s_ijkl.tensor(1,2,1,0), s_ijkl.tensor(2,0,1,0),
                        s_ijkl.tensor(2,1,1,0), s_ijkl.tensor(2,2,1,0),
                        s_ijkl.tensor(0,0,1,1), s_ijkl.tensor(0,1,1,1), s_ijkl.tensor(0,2,1,1), s_ijkl.tensor(1,0,1,1), s_ijkl.tensor(1,1,1,1), s_ijkl.tensor(1,2,1,1), s_ijkl.tensor(2,0,1,1),
                        s_ijkl.tensor(2,1,1,1), s_ijkl.tensor(2,2,1,1),
                        s_ijkl.tensor(0,0,1,2), s_ijkl.tensor(0,1,1,2), s_ijkl.tensor(0,2,1,2), s_ijkl.tensor(1,0,1,2), s_ijkl.tensor(1,1,1,2), s_ijkl.tensor(1,2,1,2), s_ijkl.tensor(2,0,1,2),
                        s_ijkl.tensor(2,1,1,2), s_ijkl.tensor(2,2,1,2),
                        s_ijkl.tensor(0,0,2,0), s_ijkl.tensor(0,1,2,0), s_ijkl.tensor(0,2,2,0), s_ijkl.tensor(1,0,2,0), s_ijkl.tensor(1,1,2,0), s_ijkl.tensor(1,2,2,0), s_ijkl.tensor(2,0,2,0),
                        s_ijkl.tensor(2,1,2,0), s_ijkl.tensor(2,2,2,0),
                        s_ijkl.tensor(0,0,2,1), s_ijkl.tensor(0,1,2,1), s_ijkl.tensor(0,2,2,1), s_ijkl.tensor(1,0,2,1), s_ijkl.tensor(1,1,2,1), s_ijkl.tensor(1,2,2,1), s_ijkl.tensor(2,0,2,1),
                        s_ijkl.tensor(2,1,2,1), s_ijkl.tensor(2,2,2,1),
                        s_ijkl.tensor(0,0,2,2), s_ijkl.tensor(0,1,2,2), s_ijkl.tensor(0,2,2,2), s_ijkl.tensor(1,0,2,2), s_ijkl.tensor(1,1,2,2), s_ijkl.tensor(1,2,2,2), s_ijkl.tensor(2,0,2,2),
                        s_ijkl.tensor(2,1,2,2), s_ijkl.tensor(2,2,2,2);

                Eigen::Matrix<T,9,9> s_mat_sys2 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys3 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys4 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys5 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys6 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys7 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys8 = s_mat_sys1;
                Eigen::Matrix<T,9,9> s_mat_sys9 = s_mat_sys1;


                Eigen::Matrix<T,9,1> c_vec = Eigen::Matrix<T,9,1>::Zero();
                Eigen::Matrix<T,9,1> i_vec = Eigen::Matrix<T,9,1>::Zero();

                // system 1
                i_vec << 1, 0, 0, 0, 0, 0, 0, 0, 0;
                c_vec = s_mat_sys1.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(0,0,0,0) = c_vec(0);
                c_ijkl.tensor(0,0,0,1) = c_vec(1);
                c_ijkl.tensor(0,0,0,2) = c_vec(2);
                c_ijkl.tensor(0,0,1,0) = c_vec(3);
                c_ijkl.tensor(0,0,1,1) = c_vec(4);
                c_ijkl.tensor(0,0,1,2) = c_vec(5);
                c_ijkl.tensor(0,0,2,0) = c_vec(6);
                c_ijkl.tensor(0,0,2,1) = c_vec(7);
                c_ijkl.tensor(0,0,2,2) = c_vec(8);

                // system 2
                i_vec <<  0, 0.5, 0, 0.5, 0, 0, 0, 0, 0;
                c_vec = s_mat_sys2.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(0,1,0,0) = c_vec(0);
                c_ijkl.tensor(0,1,0,1) = c_vec(1);
                c_ijkl.tensor(0,1,0,2) = c_vec(2);
                c_ijkl.tensor(0,1,1,0) = c_vec(3);
                c_ijkl.tensor(0,1,1,1) = c_vec(4);
                c_ijkl.tensor(0,1,1,2) = c_vec(5);
                c_ijkl.tensor(0,1,2,0) = c_vec(6);
                c_ijkl.tensor(0,1,2,1) = c_vec(7);
                c_ijkl.tensor(0,1,2,2) = c_vec(8);

                // system 3
                i_vec << 0, 0, 0.5, 0, 0, 0, 0.5, 0, 0;
                c_vec = s_mat_sys3.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(0,2,0,0) = c_vec(0);
                c_ijkl.tensor(0,2,0,1) = c_vec(1);
                c_ijkl.tensor(0,2,0,2) = c_vec(2);
                c_ijkl.tensor(0,2,1,0) = c_vec(3);
                c_ijkl.tensor(0,2,1,1) = c_vec(4);
                c_ijkl.tensor(0,2,1,2) = c_vec(5);
                c_ijkl.tensor(0,2,2,0) = c_vec(6);
                c_ijkl.tensor(0,2,2,1) = c_vec(7);
                c_ijkl.tensor(0,2,2,2) = c_vec(8);

                // system 4
                i_vec << 0, 0.5, 0, 0.5, 0, 0, 0, 0, 0;
                c_vec = s_mat_sys4.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(1,0,0,0) = c_vec(0);
                c_ijkl.tensor(1,0,0,1) = c_vec(1);
                c_ijkl.tensor(1,0,0,2) = c_vec(2);
                c_ijkl.tensor(1,0,1,0) = c_vec(3);
                c_ijkl.tensor(1,0,1,1) = c_vec(4);
                c_ijkl.tensor(1,0,1,2) = c_vec(5);
                c_ijkl.tensor(1,0,2,0) = c_vec(6);
                c_ijkl.tensor(1,0,2,1) = c_vec(7);
                c_ijkl.tensor(1,0,2,2) = c_vec(8);

                // system 5
                i_vec << 0, 0, 0, 0, 1, 0, 0, 0, 0;
                c_vec = s_mat_sys5.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(1,1,0,0) = c_vec(0);
                c_ijkl.tensor(1,1,0,1) = c_vec(1);
                c_ijkl.tensor(1,1,0,2) = c_vec(2);
                c_ijkl.tensor(1,1,1,0) = c_vec(3);
                c_ijkl.tensor(1,1,1,1) = c_vec(4);
                c_ijkl.tensor(1,1,1,2) = c_vec(5);
                c_ijkl.tensor(1,1,2,0) = c_vec(6);
                c_ijkl.tensor(1,1,2,1) = c_vec(7);
                c_ijkl.tensor(1,1,2,2) = c_vec(8);

                // system 6
                i_vec << 0, 0, 0, 0, 0, 0.5, 0, 0.5, 0;
                c_vec = s_mat_sys6.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(1,2,0,0) = c_vec(0);
                c_ijkl.tensor(1,2,0,1) = c_vec(1);
                c_ijkl.tensor(1,2,0,2) = c_vec(2);
                c_ijkl.tensor(1,2,1,0) = c_vec(3);
                c_ijkl.tensor(1,2,1,1) = c_vec(4);
                c_ijkl.tensor(1,2,1,2) = c_vec(5);
                c_ijkl.tensor(1,2,2,0) = c_vec(6);
                c_ijkl.tensor(1,2,2,1) = c_vec(7);
                c_ijkl.tensor(1,2,2,2) = c_vec(8);

                // system 7
                i_vec<< 0, 0, 0.5, 0, 0, 0, 0.5, 0, 0;
                c_vec = s_mat_sys7.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(2,0,0,0) = c_vec(0);
                c_ijkl.tensor(2,0,0,1) = c_vec(1);
                c_ijkl.tensor(2,0,0,2) = c_vec(2);
                c_ijkl.tensor(2,0,1,0) = c_vec(3);
                c_ijkl.tensor(2,0,1,1) = c_vec(4);
                c_ijkl.tensor(2,0,1,2) = c_vec(5);
                c_ijkl.tensor(2,0,2,0) = c_vec(6);
                c_ijkl.tensor(2,0,2,1) = c_vec(7);
                c_ijkl.tensor(2,0,2,2) = c_vec(8);

                // system 8
                i_vec << 0, 0, 0, 0, 0, 0.5, 0, 0.5, 0;
                c_vec = s_mat_sys8.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(2,1,0,0) = c_vec(0);
                c_ijkl.tensor(2,1,0,1) = c_vec(1);
                c_ijkl.tensor(2,1,0,2) = c_vec(2);
                c_ijkl.tensor(2,1,1,0) = c_vec(3);
                c_ijkl.tensor(2,1,1,1) = c_vec(4);
                c_ijkl.tensor(2,1,1,2) = c_vec(5);
                c_ijkl.tensor(2,1,2,0) = c_vec(6);
                c_ijkl.tensor(2,1,2,1) = c_vec(7);
                c_ijkl.tensor(2,1,2,2) = c_vec(8);

                // system 9
                i_vec << 0, 0, 0, 0, 0, 0, 0, 0, 1;
                c_vec = s_mat_sys9.colPivHouseholderQr().solve(i_vec);
                c_ijkl.tensor(2,2,0,0) = c_vec(0);
                c_ijkl.tensor(2,2,0,1) = c_vec(1);
                c_ijkl.tensor(2,2,0,2) = c_vec(2);
                c_ijkl.tensor(2,2,1,0) = c_vec(3);
                c_ijkl.tensor(2,2,1,1) = c_vec(4);
                c_ijkl.tensor(2,2,1,2) = c_vec(5);
                c_ijkl.tensor(2,2,2,0) = c_vec(6);
                c_ijkl.tensor(2,2,2,1) = c_vec(7);
                c_ijkl.tensor(2,2,2,2) = c_vec(8);

                return c_ijkl;
        }
};


// TRICLINIC
/*
 *  | 00  01  02  03  04  05 |
 *  | 01  11  12  13  14  15 |
 *  | 02  12  22  23  24  25 |
 *  | 03  13  23  33  34  35 |
 *  | 04  14  24  34  44  45 |
 *  | 05  15  25  35  45  55 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::TriclinicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };


// MONOCLINIC_X2
/*
 *  | 00  01  02  --  04  -- |
 *  | 01  11  12  --  14  -- |
 *  | 02  12  22  --  24  -- |
 *  | --  --  --  33  --  35 |
 *  | 04  14  24  --  44  -- |
 *  | --  --  --  35  --  55 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::MonoclinicX2SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };

// MONOCLINIC_X3
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  11  12  --  --  15 |
 *  | 02  12  22  --  --  25 |
 *  | --  --  --  33  34  -- |
 *  | --  --  --  34  44  -- |
 *  | 05  15  25  --  --  55 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::MonoclinicX3SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };

// ORTHORHOMBIC
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  11  12  --  --  -- |
 *  | 02  12  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  44  -- |
 *  | --  --  --  --  --  55 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::OrthorhombicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };

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
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::HexagonalSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };

// TETRAGONAL7
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  00  02  --  -- -05 |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | 05 -05  --  --  --  55 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::Tetragonal7SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };

// TETRAGONAL6
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  00  02  --  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  55 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::Tetragonal6SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };


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
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::Trigonal7SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };


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
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::Trigonal6SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };


// CUBIC
/*
 *  | 00  01  01  --  --  -- |
 *  | 01  00  01  --  --  -- |
 *  | 01  01  00  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  33 |
 */
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::CubicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> s_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> c_vec = Eigen::Matrix<T,21,1>::Zero();  // the vector which we seek to find form the system of equations
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: complete system of equaitons
//
//         return c_ijkl;
//     }
// };


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
// template <typename T>
// struct StiffnessFromComplianceFunctionObject<T, mpc::core::IsotropicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::StiffnessTensor<T> operator() (const mpc::core::ComplianceTensor<T>& s_ijkl) {
//         // given the compliance tensor, fill the stiffness tensor...
//
//         mpc::core::StiffnessTensor<T> c_ijkl = mpc::core::StiffnessTensor<T>();
//         T zero = static_cast<T>(0.0);
//         T s0000 = s_ijkl.tensor(0,0,0,0);
//         T s0011 = s_ijkl.tensor(0,0,1,1);
//         Eigen::Matrix<T,3,2> s_mat_sys = Eigen::Matrix<T,3,2>::Zero();
//         s_mat_sys << s0011, s0000+s0011,
//                      s0000, 2*s0011,
//                      2*s0000 - 2*s0011, 2*s0011 - 2*s0000;
//
//         Eigen::Matrix<T,2,1> c_vec = Eigen::Matrix<T,2,1>::Zero();  // the solution vector which we seek to find form the system of equations
//         Eigen::Matrix<T,3,1> i_vec = Eigen::Matrix<T,3,1>::Zero();
//         i_vec << 0, 1, 0.5;
//
//         c_vec = s_mat_sys.bdcSvd(Eigen::ComputeFullU | Eigen::ComputeFullV).solve(i_vec);
//
//         std::set< mpc::core::TensorRank4Component<T> > tmp{
//             mpc::core::TensorRank4Component<T>(c_vec(0), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
//             mpc::core::TensorRank4Component<T>(c_vec(1), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
//         };
//
//         c_ijkl.template SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(tmp);
//
//         return c_ijkl;
//     }
// };



// ===============================================================================================================================
template <typename T, typename S=mpc::core::NoneSymmetryGroupType>
struct ComplianceFromStiffnessFunctionObject {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
        //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
        mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
                // given the stiffness tensor, fill the compliance tensor
                // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
                //     which contains the compliance tensor, and a [9x1] vector from the identity tensor

                mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();

                Eigen::Matrix<T,9,9> c_mat_sys1 = Eigen::Matrix<T,9,9>::Zero();
                c_mat_sys1 <<
                        c_ijkl.tensor(0,0,0,0), c_ijkl.tensor(0,0,0,1), c_ijkl.tensor(0,0,0,2), c_ijkl.tensor(0,0,1,0), c_ijkl.tensor(0,0,1,1), c_ijkl.tensor(0,0,1,2), c_ijkl.tensor(0,0,2,0),
                        c_ijkl.tensor(0,0,2,1), c_ijkl.tensor(0,0,2,2),
                        c_ijkl.tensor(0,1,0,0), c_ijkl.tensor(0,1,0,1), c_ijkl.tensor(0,1,0,2), c_ijkl.tensor(0,1,1,0), c_ijkl.tensor(0,1,1,1), c_ijkl.tensor(0,1,1,2), c_ijkl.tensor(0,1,2,0),
                        c_ijkl.tensor(0,1,2,1), c_ijkl.tensor(0,1,2,2),
                        c_ijkl.tensor(0,2,0,0), c_ijkl.tensor(0,2,0,1), c_ijkl.tensor(0,2,0,2), c_ijkl.tensor(0,2,1,0), c_ijkl.tensor(0,2,1,1), c_ijkl.tensor(0,2,1,2), c_ijkl.tensor(0,2,2,0),
                        c_ijkl.tensor(0,2,2,1), c_ijkl.tensor(0,2,2,2),
                        c_ijkl.tensor(1,0,0,0), c_ijkl.tensor(1,0,0,1), c_ijkl.tensor(1,0,0,2), c_ijkl.tensor(1,0,1,0), c_ijkl.tensor(1,0,1,1), c_ijkl.tensor(1,0,1,2), c_ijkl.tensor(1,0,2,0),
                        c_ijkl.tensor(1,0,2,1), c_ijkl.tensor(1,0,2,2),
                        c_ijkl.tensor(1,1,0,0), c_ijkl.tensor(1,1,0,1), c_ijkl.tensor(1,1,0,2), c_ijkl.tensor(1,1,1,0), c_ijkl.tensor(1,1,1,1), c_ijkl.tensor(1,1,1,2), c_ijkl.tensor(1,1,2,0),
                        c_ijkl.tensor(1,1,2,1), c_ijkl.tensor(1,1,2,2),
                        c_ijkl.tensor(1,2,0,0), c_ijkl.tensor(1,2,0,1), c_ijkl.tensor(1,2,0,2), c_ijkl.tensor(1,2,1,0), c_ijkl.tensor(1,2,1,1), c_ijkl.tensor(1,2,1,2), c_ijkl.tensor(1,2,2,0),
                        c_ijkl.tensor(1,2,2,1), c_ijkl.tensor(1,2,2,2),
                        c_ijkl.tensor(2,0,0,0), c_ijkl.tensor(2,0,0,1), c_ijkl.tensor(2,0,0,2), c_ijkl.tensor(2,0,1,0), c_ijkl.tensor(2,0,1,1), c_ijkl.tensor(2,0,1,2), c_ijkl.tensor(2,0,2,0),
                        c_ijkl.tensor(2,0,2,1), c_ijkl.tensor(2,0,2,2),
                        c_ijkl.tensor(2,1,0,0), c_ijkl.tensor(2,1,0,1), c_ijkl.tensor(2,1,0,2), c_ijkl.tensor(2,1,1,0), c_ijkl.tensor(2,1,1,1), c_ijkl.tensor(2,1,1,2), c_ijkl.tensor(2,1,2,0),
                        c_ijkl.tensor(2,1,2,1), c_ijkl.tensor(2,1,2,2),
                        c_ijkl.tensor(2,2,0,0), c_ijkl.tensor(2,2,0,1), c_ijkl.tensor(2,2,0,2), c_ijkl.tensor(2,2,1,0), c_ijkl.tensor(2,2,1,1), c_ijkl.tensor(2,2,1,2), c_ijkl.tensor(2,2,2,0),
                        c_ijkl.tensor(2,2,2,1), c_ijkl.tensor(2,2,2,2);

                //std::cout << c_mat_sys1 << std::endl;

                Eigen::Matrix<T,9,9> c_mat_sys2 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys3 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys4 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys5 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys6 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys7 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys8 = c_mat_sys1;
                Eigen::Matrix<T,9,9> c_mat_sys9 = c_mat_sys1;

                Eigen::Matrix<T,9,1> s_vec = Eigen::Matrix<T,9,1>::Zero();
                Eigen::Matrix<T,9,1> i_vec = Eigen::Matrix<T,9,1>::Zero();

                //T relative_error = 0;  // for testing

                // system 1
                i_vec << 1, 0, 0, 0, 0, 0, 0, 0, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys1.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys1.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,0,0) = s_vec(0);
                s_ijkl.tensor(0,1,0,0) = s_vec(1);
                s_ijkl.tensor(0,2,0,0) = s_vec(2);
                s_ijkl.tensor(1,0,0,0) = s_vec(3);
                s_ijkl.tensor(1,1,0,0) = s_vec(4);
                s_ijkl.tensor(1,2,0,0) = s_vec(5);
                s_ijkl.tensor(2,0,0,0) = s_vec(6);
                s_ijkl.tensor(2,1,0,0) = s_vec(7);
                s_ijkl.tensor(2,2,0,0) = s_vec(8);
//         relative_error = (c_mat_sys1*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys1 is:\n" << relative_error << std::endl;

                // system 2
                i_vec << 0, 0.5, 0, 0.5, 0, 0, 0, 0, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys2.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys2.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,0,1) = s_vec(0);
                s_ijkl.tensor(0,1,0,1) = s_vec(1);
                s_ijkl.tensor(0,2,0,1) = s_vec(2);
                s_ijkl.tensor(1,0,0,1) = s_vec(3);
                s_ijkl.tensor(1,1,0,1) = s_vec(4);
                s_ijkl.tensor(1,2,0,1) = s_vec(5);
                s_ijkl.tensor(2,0,0,1) = s_vec(6);
                s_ijkl.tensor(2,1,0,1) = s_vec(7);
                s_ijkl.tensor(2,2,0,1) = s_vec(8);
//         relative_error = (c_mat_sys2*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys2 is:\n" << relative_error << std::endl;

                // system 3
                i_vec << 0, 0, 0.5, 0, 0, 0, 0.5, 0, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys3.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys3.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,0,2) = s_vec(0);
                s_ijkl.tensor(0,1,0,2) = s_vec(1);
                s_ijkl.tensor(0,2,0,2) = s_vec(2);
                s_ijkl.tensor(1,0,0,2) = s_vec(3);
                s_ijkl.tensor(1,1,0,2) = s_vec(4);
                s_ijkl.tensor(1,2,0,2) = s_vec(5);
                s_ijkl.tensor(2,0,0,2) = s_vec(6);
                s_ijkl.tensor(2,1,0,2) = s_vec(7);
                s_ijkl.tensor(2,2,0,2) = s_vec(8);
//         relative_error = (c_mat_sys3*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys3 is:\n" << relative_error << std::endl;

                // system 4
                i_vec << 0, 0.5, 0, 0.5, 0, 0, 0, 0, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys4.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys4.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,1,0) = s_vec(0);
                s_ijkl.tensor(0,1,1,0) = s_vec(1);
                s_ijkl.tensor(0,2,1,0) = s_vec(2);
                s_ijkl.tensor(1,0,1,0) = s_vec(3);
                s_ijkl.tensor(1,1,1,0) = s_vec(4);
                s_ijkl.tensor(1,2,1,0) = s_vec(5);
                s_ijkl.tensor(2,0,1,0) = s_vec(6);
                s_ijkl.tensor(2,1,1,0) = s_vec(7);
                s_ijkl.tensor(2,2,1,0) = s_vec(8);
//         relative_error = (c_mat_sys4*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys4 is:\n" << relative_error << std::endl;

                // system 5
                i_vec << 0, 0, 0, 0, 1, 0, 0, 0, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys5.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys5.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,1,1) = s_vec(0);
                s_ijkl.tensor(0,1,1,1) = s_vec(1);
                s_ijkl.tensor(0,2,1,1) = s_vec(2);
                s_ijkl.tensor(1,0,1,1) = s_vec(3);
                s_ijkl.tensor(1,1,1,1) = s_vec(4);
                s_ijkl.tensor(1,2,1,1) = s_vec(5);
                s_ijkl.tensor(2,0,1,1) = s_vec(6);
                s_ijkl.tensor(2,1,1,1) = s_vec(7);
                s_ijkl.tensor(2,2,1,1) = s_vec(8);
//         relative_error = (c_mat_sys5*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys5 is:\n" << relative_error << std::endl;

                // system 6
                i_vec << 0, 0, 0, 0, 0, 0.5, 0, 0.5, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys6.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys6.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,1,2) = s_vec(0);
                s_ijkl.tensor(0,1,1,2) = s_vec(1);
                s_ijkl.tensor(0,2,1,2) = s_vec(2);
                s_ijkl.tensor(1,0,1,2) = s_vec(3);
                s_ijkl.tensor(1,1,1,2) = s_vec(4);
                s_ijkl.tensor(1,2,1,2) = s_vec(5);
                s_ijkl.tensor(2,0,1,2) = s_vec(6);
                s_ijkl.tensor(2,1,1,2) = s_vec(7);
                s_ijkl.tensor(2,2,1,2) = s_vec(8);
//         relative_error = (c_mat_sys6*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys6 is:\n" << relative_error << std::endl;

                // system 7
                i_vec << 0, 0, 0.5, 0, 0, 0, 0.5, 0, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys7.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys7.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,2,0) = s_vec(0);
                s_ijkl.tensor(0,1,2,0) = s_vec(1);
                s_ijkl.tensor(0,2,2,0) = s_vec(2);
                s_ijkl.tensor(1,0,2,0) = s_vec(3);
                s_ijkl.tensor(1,1,2,0) = s_vec(4);
                s_ijkl.tensor(1,2,2,0) = s_vec(5);
                s_ijkl.tensor(2,0,2,0) = s_vec(6);
                s_ijkl.tensor(2,1,2,0) = s_vec(7);
                s_ijkl.tensor(2,2,2,0) = s_vec(8);
//         relative_error = (c_mat_sys7*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys7 is:\n" << relative_error << std::endl;

                // system 8
                i_vec << 0, 0, 0, 0, 0, 0.5, 0, 0.5, 0;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys8.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys8.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,2,1) = s_vec(0);
                s_ijkl.tensor(0,1,2,1) = s_vec(1);
                s_ijkl.tensor(0,2,2,1) = s_vec(2);
                s_ijkl.tensor(1,0,2,1) = s_vec(3);
                s_ijkl.tensor(1,1,2,1) = s_vec(4);
                s_ijkl.tensor(1,2,2,1) = s_vec(5);
                s_ijkl.tensor(2,0,2,1) = s_vec(6);
                s_ijkl.tensor(2,1,2,1) = s_vec(7);
                s_ijkl.tensor(2,2,2,1) = s_vec(8);
//         relative_error = (c_mat_sys8*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys8 is:\n" << relative_error << std::endl;

                // system 9
                i_vec << 0, 0, 0, 0, 0, 0, 0, 0, 1;
                //std::cout << i_vec << std::endl;
                //s_vec = c_mat_sys9.colPivHouseholderQr().solve(i_vec);
                s_vec = c_mat_sys9.fullPivLu().solve(i_vec);
                s_ijkl.tensor(0,0,2,2) = s_vec(0);
                s_ijkl.tensor(0,1,2,2) = s_vec(1);
                s_ijkl.tensor(0,2,2,2) = s_vec(2);
                s_ijkl.tensor(1,0,2,2) = s_vec(3);
                s_ijkl.tensor(1,1,2,2) = s_vec(4);
                s_ijkl.tensor(1,2,2,2) = s_vec(5);
                s_ijkl.tensor(2,0,2,2) = s_vec(6);
                s_ijkl.tensor(2,1,2,2) = s_vec(7);
                s_ijkl.tensor(2,2,2,2) = s_vec(8);
//         relative_error = (c_mat_sys9*s_vec - i_vec).norm() / i_vec.norm(); // norm() is L2 norm
//         std::cout << "The relative error for sys9 is:\n" << relative_error << std::endl;

                return s_ijkl;
        }
};



// TRICLINIC
/*
 *  | 00  01  02  03  04  05 |
 *  | 01  11  12  13  14  15 |
 *  | 02  12  22  23  24  25 |
 *  | 03  13  23  33  34  35 |
 *  | 04  14  24  34  44  45 |
 *  | 05  15  25  35  45  55 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::TriclinicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };


// MONOCLINIC_X2
/*
 *  | 00  01  02  --  04  -- |
 *  | 01  11  12  --  14  -- |
 *  | 02  12  22  --  24  -- |
 *  | --  --  --  33  --  35 |
 *  | 04  14  24  --  44  -- |
 *  | --  --  --  35  --  55 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::MonoclinicX2SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };

// MONOCLINIC_X3
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  11  12  --  --  15 |
 *  | 02  12  22  --  --  25 |
 *  | --  --  --  33  34  -- |
 *  | --  --  --  34  44  -- |
 *  | 05  15  25  --  --  55 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::MonoclinicX3SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };

// ORTHORHOMBIC
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  11  12  --  --  -- |
 *  | 02  12  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  44  -- |
 *  | --  --  --  --  --  55 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::OrthorhombicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };

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
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::HexagonalSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };

// TETRAGONAL7
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  00  02  --  -- -05 |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | 05 -05  --  --  --  55 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::Tetragonal7SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };

// TETRAGONAL6
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  00  02  --  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  55 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::Tetragonal6SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };


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
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::Trigonal7SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };


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
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::Trigonal6SymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };


// CUBIC
/*
 *  | 00  01  01  --  --  -- |
 *  | 01  00  01  --  --  -- |
 *  | 01  01  00  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  33 |
 */
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::CubicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // the solution requires 6 systems of equations involving a [9x9] matrix of the stiffness tensor, a [9x1] solution vector
//         //     which contains the compliance tensor, and a [9x1] vector from the identity tensor
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         Eigen::Matrix<T,36,21> c_mat_sys = Eigen::Matrix<T,36,21>::Zero();
//
//         Eigen::Matrix<T,21,1> s_vec = Eigen::Matrix<T,21,1>::Zero();
//         Eigen::Matrix<T,36,1> i_vec = Eigen::Matrix<T,36,1>::Zero();
//
//         // TODO: system of equations
//
//         return s_ijkl;
//     }
// };


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
// template <typename T>
// struct ComplianceFromStiffnessFunctionObject<T, mpc::core::IsotropicSymmetryGroupType> {
//     static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
//     //static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
//     //static_assert(std::is_base_of<mpc::core::CSBase,CS>::value, "CS must be derived from mpc::core::CSBase.");
//     mpc::core::ComplianceTensor<T> operator() (const mpc::core::StiffnessTensor<T>& c_ijkl) {
//         // given the stiffness tensor, fill the compliance tensor
//         // precondition: the tensor is symmetry compliant, i.e. c_ijkl is in fact isotropic
//
//         mpc::core::ComplianceTensor<T> s_ijkl = mpc::core::ComplianceTensor<T>();
//         T zero = static_cast<T>(0.0);
//         T c0000 = c_ijkl.tensor(0,0,0,0);
//         T c0011 = c_ijkl.tensor(0,0,1,1);
//         Eigen::Matrix<T,3,2> c_mat_sys = Eigen::Matrix<T,3,2>::Zero();
//         c_mat_sys << c0011, c0000+c0011,
//                      c0000, 2*c0011,
//                      (2*c0000 - 2*c0011), (2*c0011 - 2*c0000);
//
//         Eigen::Matrix<T,2,1> s_vec = Eigen::Matrix<T,2,1>::Zero();  // the solution vector we seek to find
//         Eigen::Matrix<T,3,1> i_vec = Eigen::Matrix<T,3,1>::Zero();
//         i_vec << 0, 1, 0.5;
//
//         s_vec = c_mat_sys.bdcSvd(Eigen::ComputeFullU | Eigen::ComputeFullV).solve(i_vec);
//
//         std::set< mpc::core::TensorRank4Component<T> > tmp{
//             mpc::core::TensorRank4Component<T>(s_vec(0), mpc::core::TensorRank4ComponentIndex(0,0,0,0)),
//             mpc::core::TensorRank4Component<T>(s_vec(1), mpc::core::TensorRank4ComponentIndex(0,0,1,1)),
//         };
//
//         s_ijkl.template SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(tmp);
//
//         return s_ijkl;
//     }
// };



// === polymorphic functions =====================================================================================================
template <typename S, typename T>
mpc::core::ComplianceTensor<T> CSRelationship(mpc::core::StiffnessTensor<T>& c_ijkl) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");

        mpc::core::ComplianceFromStiffnessFunctionObject<T,S> fo;
        return fo(c_ijkl);
}

template <typename S, typename T>
mpc::core::StiffnessTensor<T> CSRelationship(mpc::core::ComplianceTensor<T>& s_ijkl) {
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
        static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");

        mpc::core::StiffnessFromComplianceFunctionObject<T,S> fo;
        return fo(s_ijkl);
}

} // namespace core
} // namespace mpc

#endif //MPC_CSRELATIONSHIP_H
