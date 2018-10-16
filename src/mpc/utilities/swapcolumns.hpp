/**
 *    \file swapcolumns.hpp
 *    \brief utility function to swap columns of a two-dimensional blitz array
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_SWAPCOLUMNS_H
#define MPC_SWAPCOLUMNS_H

// blitz
#include <blitz/array.h>

namespace mpc {
    namespace utilities {

        template <typename T>
        void SwapColumns(blitz::Array<T,2>& a, int c1, int c2)
        {
            // swaps values in two columns
            blitz::TinyVector<int,2> shp = a.shape();
            int nrows = shp(0); // number of rows
            for (int r=0; r<nrows; ++r) { std::swap<T>(a(r,c1), a(r,c2)); }
        }

    } // namespace utilities
} // namespace mpc

#endif // MPC_SWAPCOLUMNS_H
