/**
*    @file swaprows.hpp
*    @brief utility function to swap rows of a two-dimensional blitz array
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MPC_SWAPROWS_H
#define MPC_SWAPROWS_H

// blitz
#include <blitz/array.h>

namespace mpc {
namespace util {

template <typename T>
void SwapRows(blitz::Array<T,2>& a, int r1, int r2)
{
    // swaps values in two rows
    blitz::TinyVector<int,2> shp = a.shape();
    int ncols = shp(1);  // number of columns
    T tmp;
    for (int c=0; c<ncols; ++c) { std::swap<T>(a(r1,c), a(r2,c)); }
}

} // namespace util
} // namespace mpc

#endif // MPC_SWAPROWS_H
