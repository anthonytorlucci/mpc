//
// Created by Anthony Torlucci on 2/13/18.
//

#ifndef AFM_BULK_AND_SHEAR_MODULUS_H
#define AFM_BULK_AND_SHEAR_MODULUS_H

#include <vector>

// blitz
#include <blitz/array.h>

// afm
#include "../core/symmetrygrouptypes.hpp"
#include "../core/stiffnesscompliance.hpp"

// TODO: calculate the bulk and shear modulus from the 4th rank stiffness
// TODO: or compliance tensor based on the two linear invariants of the
// TODO: isotropic stiffness or compliance tensor (DeWit, 2008)

namespace mpc {
namespace util {
template <typename T, mpc::core::SYMMETRY Sym>
std::vector<T> GetVoigtBulkAndShearModulusFromStiffnessTensor(mpc::core::StiffnessTensor<T>& c) {
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    T k = 0;
    T mu = 0;
    T one_third = T(1.0/3.0);
    T one_ninth = T(1.0/9.0);
    T one_tenth = T(0.1);
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            k += one_ninth * c.tensor(i,i,j,j);
            mu += one_tenth * (c.tensor(i,j,i,j) - (one_third * c.tensor(i,i,j,j)));
        }
    }

    std::vector<T> out(2);
    out[0] = k;
    out[1] = mu;

    return out;
}

template <typename T, mpc::core::SYMMETRY Sym>
std::vector<T> GetRuessBulkAndShearModulusFromCompliance(mpc::core::ComplianceTensor<T>& s)
{
    static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
    //static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
    T k_r = 0;   // reciprocal of bulk modulus
    T mu_r = 0;  // reciprocal of shear modulus
    T two_fifths = T(2.0/5.0);
    T one_third = T(1.0/3.0);
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            k_r += s.tensor(i,i,j,j);
            mu_r += two_fifths * (s.tensor(i,j,i,j) - (one_third * s.tensor(i,i,j,j)));
        }
    }
    std::vector<T> out(2);
    out[0] = T(1.0 / k_r);
    out[1] = T(1.0 / mu_r);

    return out;
}

} // namespace util
} // namespace mpc

#endif //AFM_BULK_AND_SHEAR_MODULUS_H
