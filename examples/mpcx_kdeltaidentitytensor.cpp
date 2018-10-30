#include "mpcx_kdeltaidentitytensor.hpp"

// c++
#include <iostream>
#include <cmath>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/kroneckerdelta.hpp>
#include <mpc/utilities/identitytensor.hpp>

void mpcexamples::mpcKroneckerDeltaAndIdentityTensor() {
    /** kronecker delta and 4th rank identity tensor */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::utilities::PrintTensorComponents<double,2> PrintTensorComponents2;
    mpc::utilities::PrintTensorComponents<double,4> PrintTensorComponents4;

    // Kronecker delta template function
    blitz::Array<double,2> kdelta = mpc::utilities::KroneckerDelta<double,3>();
    PrintTensorComponents2(kdelta);

    // TODO: exit code 4 ???
    // identity tensor of rank 4 in three dimensional space
    //blitz::Array<double,4> id4 = mpc::utilities::IdentityTensor4_d3<double>();
    //PrintTensorComponents4(id4);

    // another fourth rank identity tensor < float_type, dimensions, rank >
    //id4 = mpc::utilities::IdentityTensor<double,3,4>();
    //PrintTensorComponents4(id4);


}  // END FUNCTION
