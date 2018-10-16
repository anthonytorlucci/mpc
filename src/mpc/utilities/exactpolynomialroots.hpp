/**
 *    \file exactpolynomialroots.hpp
 *    \brief funcions for determining the exact roots of quadratic and
 * cubic polynomials analytically
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_CUBICSOLVER_H
#define MPC_CUBICSOLVER_H

// c++
#include <array>
#include <complex>
#include <cmath>
#include <type_traits>
#include <iostream>  // for debugging

// mpc
#include "constants.hpp"

namespace mpc {
    namespace utilities {
        template <typename T>
        std::array<std::complex<T>,2> QuadraticSolver(T a2, T a1, T a0) {
                // solves the quadratic equation (a2)x**2 + (a1)x + (a0) = 0
                //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
                static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
                std::complex<T> root0;
                std::complex<T> root1;
                T recip2a2 = 1.0 / (2.0 * a2); // leading coefficient
                T sqrt_arg = (a1*a1) - (4.0 * a2 * a0); // the argument under the radical
                if (sqrt_arg == 0) {
                        // both roots are real and equivalent
                        //std::cout << "both roots are real and equivalent" << std::endl;
                        root0.real(recip2a2 * (-1.0 * a1));
                        root0.imag(0.0);
                        root1.real(recip2a2 * (-1.0 * a1));
                        root1.imag(0.0);
                }
                if (sqrt_arg > 0) {
                        // both roots are real and distinct
                        //std::cout << "both roots are real and distinct" << std::endl;
                        root0.real(recip2a2 * ((-1.0 * a1) + sqrt(sqrt_arg)));
                        root0.imag(0.0);
                        root1.real(recip2a2 * ((-1.0 * a1) - sqrt(sqrt_arg)));
                        root1.imag(0.0);
                }
                if (sqrt_arg < 0) {
                        // both roots are imaginary
                        //std::cout << "both roots are imaginary" << std::endl;
                        root0.real(recip2a2 * (-1.0 * a1));
                        root0.imag(recip2a2 * sqrt(-1.0 * sqrt_arg));
                        root1.real(recip2a2 * (-1.0 * a1));
                        root1.imag(-1.0 * recip2a2 * sqrt(-1.0 * sqrt_arg)); // the -1 makes the argument positive; otherwise the sqrt(sqrt_arg) would return a nan.
                }
                return std::array<std::complex<T>,2>{root0, root1};
        }

        template <typename T>
        std::array<std::complex<T>,3> CubicSolver(T a3, T a2, T a1, T a0) {
                // T must be of type float, double, or long double; unspecified otherwise;
                // see std::complex<T> cpp reference
                //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
                static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
                // based on:
                // 1) Cubic Formula : WolframMathworld >> http://mathworld.wolfram.com/CubicFormula.html
                // 2) Lebedev, V. I., 1991, On formulae for roots of cubic equation: Sov. J. Anal. Math. Modelling, Vol. 6, No. 4, pp. 315-324
                // http://mathforcollege.com/nm/mws/gen/03nle/mws_gen_nle_bck_exactcubic.pdf

                T pi_ = mpc::utilities::PI<T>;
                // init temporary solutions
                std::complex<T> w0, w1, z0, z1, z2, y0, y1, y2, x0, x1, x2;

                T e = (1.0/a3) * (a1 - (a2 * a2 / (3.0 * a3)));
                T f = (1.0/a3) * (a0 + (2.0*std::pow(a2,3)/(27.0*std::pow(a3,2))) - (a2 * a1 / (3.0 * a3)));
                T s = -e / 3.0;

                // solve the quadratic w**2 + fw - e**3/27 = 0
                T tmp = -1.0 * std::pow(e,3) / 27.0;
                std::array<std::complex<T>,2> wroots = QuadraticSolver(1.0,f,tmp);
                w0 = wroots[0]; // both roots should yiels same result in the end; here we use the first one
                T r = sqrt(std::pow(w0.real(),2) + std::pow(w0.imag(),2)); // magnitude of complex number
                T theta = atan2(w0.imag(),w0.real()); // argument of complex number

                // three roots for w=z**3
                z0.real(std::pow(r,1.0/3.0) * cos(theta/3.0));
                z0.imag(std::pow(r,1.0/3.0) * sin(theta/3.0));
                z1.real(std::pow(r,1.0/3.0) * cos((theta+(2.0*pi_))/3.0));
                z1.imag(std::pow(r,1.0/3.0) * sin((theta+(2.0*pi_))/3.0));
                z2.real(std::pow(r,1.0/3.0) * cos((theta+(4.0*pi_))/3.0));
                z2.imag(std::pow(r,1.0/3.0) * sin((theta+(4.0*pi_))/3.0));

                // since y = z + (s / z), there are three y values corresponding to the three z's
                y0 = z0 + (s/z0);
                y1 = z1 + (s/z1);
                y2 = z2 + (s/z2);

                // Finally, since x=y-(a2/3a3)
                tmp = a2 / (3.0 * a3);
                x0 = y0 - tmp;
                x1 = y1 - tmp;
                x2 = y2 - tmp;

                // repeat for w1 should yield same result...

                return std::array<std::complex<T>,3>{x0,x1,x2};

        }

    }  // namespace utilities
}  // namespace mpc

#endif // MPC_CUBICSOLVER_H
