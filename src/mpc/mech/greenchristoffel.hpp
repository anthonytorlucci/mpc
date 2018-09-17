/**
 *    @file greenchristoffel.hpp
 *    @brief class used for calculating the velocities using the
 * Green-Christoffel equation; currently only phase velocities are generated
 * and particle dispalcement is not yet implemented
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_GREENCHRISTOFFEL_H
#define MPC_GREENCHRISTOFFEL_H

#include <array>
#include <complex>
#include <cmath>
#include <algorithm>
#include <iostream>

// blitz
#include <blitz/array.h>

// mpc
#include "../core/symmetrygrouptypes.hpp"
#include "../util/exactpolynomialroots.hpp"
#include "../util/blitz2eigen.hpp"

namespace mpc {
namespace mech {

template <typename T>
struct GreenChristoffel {
        //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
        static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");

        // NOTE: cuurent implementation is strictly for the "velocity surface",
        //   that is the phase velocities as a function of the normal vector to
        //   the wavefront.
        //   TODO: another implementation for slowness vectors!!! and group velocity surface

        // NOTE: UNITS!!!
        //   cijkl are expected to be in GPa,
        //   density is expected to be in g/cm**3
        //   velocities are given in km/s**2

        // member data
        blitz::Array<T,2> tensor = blitz::Array<T,2>(3,3,blitz::ColumnMajorArray<2>());

        // default constructor
        GreenChristoffel() {
                tensor = T(0.0);
        }


        void SetComponents(const mpc::core::StiffnessTensor<T>& cijkl, blitz::Array<T,1>& n) {
                // gamma_ik = cijkl * nj * nl
                // TODO: assert shape(n)  = 3
                T tmp = 0;
                for (int i=0; i<3; ++i) {
                        for (int k=0; k<3; ++k) {
                                tmp = 0;
                                for (int j=0; j<3; ++j) {
                                        for (int l=0; l<3; ++l) {
                                                tmp += cijkl.tensor(i,j,k,l) * n(j) * n(l);
                                        }
                                }
                                tensor(i,k) = tmp;
                        }
                }
        }

        std::array<T,3> PhaseVelocities(T density) {
                // TODO: assert tensor is not all zero components

                Eigen::Matrix<T,3,3> gctensor = mpc::util::Blitz2Eigen<T,3,3,2>(tensor);
                //std::cout << gctensor << std::endl;
                //Eigen::SelfAdjointEigenSolver< Eigen::Matrix<T,3,3> > eigensolver(gctensor);
                Eigen::EigenSolver< Eigen::Matrix<T,3,3> > eigensolver(gctensor); // https://eigen.tuxfamily.org/dox/classEigen_1_1EigenSolver.html#adc446bcb60572758fa64515f2825db62
                auto rho_vel_squared = eigensolver.eigenvalues();
                //std::cout << vels << std::endl;
                T pvel0 = std::sqrt(rho_vel_squared(0).real()) / density;
                T pvel1 = std::sqrt(rho_vel_squared(1).real()) / density;
                T pvel2 = std::sqrt(rho_vel_squared(2).real()) / density;
                std::array<T,3> pvels{pvel0, pvel1, pvel2};
                return pvels;

        }

};



}  // END namespace mech
}  // END namespace mpc


#endif // MPC_GREENCHRISTOFFEL_H
