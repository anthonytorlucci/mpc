/**
 *    \file linspace.hpp
 *    \brief c++ implemenation of linspace in numpy
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/25
 */

#ifndef MPC_LINSPACE_H
#define MPC_LINSPACE_H

// reference: https://gist.github.com/lorenzoriano/5414671
// based on numpy ... functions_base.py

// blitz
#include <blitz/array.h>

//mpc

namespace mpc {
    namespace utilities {

        template <typename T>
        std::vector<T> Linspace(T a, T b, size_t N) {
            T h = (b - a) / static_cast<T>(N-1);
            std::vector<T> xs(N);
            typename std::vector<T>::iterator x;
            T val;
            for (x = xs.begin(), val = a; x != xs.end(); ++x, val += h)
                *x = val;
            return xs;
        }

        // TODO: logspace

        // TODO: geomspace

    } // namespace utilities
} // namespace mpc

#endif // MPC_LINSPACE_H
