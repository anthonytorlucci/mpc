/**
 *    \file kmurho.hpp
 *    \brief data structures for simple rock physics models
 *
 *    \author Anthony Torlucci
 *    \date 10/12/2018
 */

#ifndef MPC_KMURHO_H
#define MPC_KMURHO_H

/**
 * \namespace mpc
 */
namespace mpc {
namespace core {

template <typename T>
class KMuRho {
private:
  T bulkmodulus;   // GPa
  T shearmodulus;  // GPa
  T density;       // g/cm**3
};

template <typename T>
class FluidMixture : public KMuRho {};

template <typename T>
class MineralMatrix : public KMuRho {};


}
}  // namespace mpc

#endif // MPC_KMURHO_H
