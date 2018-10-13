/**
 *    \file kmurho.hpp
 *    \brief data structures for simple rock physics models
 *
 *    \author Anthony Torlucci
 *    \date 10/12/2018
 */

#ifndef MPC_KMURHO_H
#define MPC_KMURHO_H

#include "../util/rptransforms.hpp"

/**
 * \namespace mpc
 */
namespace mpc {
namespace core {

template <typename T>
class KMuRho {
static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
protected:
T bulkmodulus;     // GPa
T shearmodulus;    // GPa
T density;         // g/cm**3
T pwave_velocity;    // km/s
T swave_velocity;    // km/s
T poissons_ratio;    // dimensionless

void UpdateParameters() {
        //
        pwave_velocity = mpc::util::PvelFromBulkModulusShearModulusDensity(bulkmodulus, shearmodulus, density);
        swave_velocity = mpc::util::SvelFromShearModulusDensity(shearmodulus, density);
        if (swave_velocity != 0) {
                poissons_ratio = mpc::util::CalculatePoissonsRatio(pwave_velocity, swave_velocity);
        } else {
                poissons_ratio = 0;
        }

}
public:
KMuRho() {
        bulkmodulus = 1.0;
        shearmodulus = 1.0;
        density = 1.0;
        UpdateParameters();
}

KMuRho(T K, T mu, T rho) : bulkmodulus(K), shearmodulus(mu), density(rho) {
  UpdateParameters();
}

// accessors
T BulkModulus() {
        return bulkmodulus;
}

T ShearModulus() {
        return shearmodulus;
}

T Density() {
        return density;
}

T PWaveVelocity() {
        return pwave_velocity;
}

T SWaveVelocity() {
        return swave_velocity;
}

T PoissonsRatio() {
        return poissons_ratio;
}

// mutators
void BulkModulus(T K) {
        bulkmodulus = K;
}

void ShearModulus(T mu) {
        shearmodulus = mu;
}

void Density(T rho) {
        density = rho;
}

void PWaveVelocity(T pvel) {
        pwave_velocity = pvel;
}

void SWaveVelocity(T svel) {
        swave_velocity = svel;
}

void PoissonsRatio(T pr) {
        poissons_ratio = pr;
}

};

template <typename T>
class FluidMixture : public KMuRho<T> {
  using KMuRho<T>::bulkmodulus;
  using KMuRho<T>::shearmodulus;
  using KMuRho<T>::density;
  using KMuRho<T>::pwave_velocity;
  using KMuRho<T>::swave_velocity;
  using KMuRho<T>::poissons_ratio;
};

template <typename T>
class MineralMatrix : public KMuRho<T> {
  using KMuRho<T>::bulkmodulus;
  using KMuRho<T>::shearmodulus;
  using KMuRho<T>::density;
  using KMuRho<T>::pwave_velocity;
  using KMuRho<T>::swave_velocity;
  using KMuRho<T>::poissons_ratio;
};


}
}  // namespace mpc

#endif // MPC_KMURHO_H
