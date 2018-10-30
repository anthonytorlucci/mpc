#include "mpcx_magandnorm.hpp"
#include "arraysandtensors.hpp"

// c++
#include <iostream>
#include <cmath>

// blitz

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/magnitude.hpp>
#include <mpc/utilities/norm.hpp>

void mpcexamples::mpcMagnitudeAndNorms() {
    /** vector magnitude and norms */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::utilities::PrintTensorComponents<double,1> PrintTensorComponents1;
    // blitz::Array<double,1> tensorR1D3
    auto tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
    PrintTensorComponents1(tensorR1D3);

    double mag = mpc::utilities::Magnitude(tensorR1D3);  // template type deduced from input
    std::cout << "magnitude : " << mag << "\n" << std::endl;

    blitz::Array<double,1> normalized_tensorR1D3 = mpc::utilities::Normal(tensorR1D3);
    PrintTensorComponents1(normalized_tensorR1D3);

    // normalize in place;  WARNING!!! this will change the components of the input array
    mpc::utilities::Normalize(tensorR1D3);
    PrintTensorComponents1(tensorR1D3);

}  // END FUNCTION
