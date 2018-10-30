#include "mpcx_harmonicaverage.hpp"
#include "arraysandtensors.hpp"

// c++
#include <iostream>
#include <cmath>
#include <vector>

// blitz

// mpc
#include <mpc/utilities/harmonicaverage.hpp>

void mpcexamples::mpcHarmonicAverage() {
    /** harmonic average */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    // weights for tests
    std::vector<double> vec_weights4 = {0.1, 0.2, 0.3, 0.4};
    std::cout << "weights[0] : " << vec_weights4[0] << std::endl;
    std::cout << "weights[1] : " << vec_weights4[1] << std::endl;
    std::cout << "weights[2] : " << vec_weights4[2] << std::endl;
    std::cout << "weights[3] : " << vec_weights4[3] << std::endl;
    std::cout << "" << std::endl;

    // output single values
    std::vector<double> vec_values4 = {1.0, 2.0, 3.0, 4.0};
    std::cout << "values[0] : " << vec_values4[0] << std::endl;
    std::cout << "values[1] : " << vec_values4[1] << std::endl;
    std::cout << "values[2] : " << vec_values4[2] << std::endl;
    std::cout << "values[3] : " << vec_values4[3] << std::endl;
    std::cout << "" << std::endl;

    mpc::utilities::WeightedHarmonicAverage<double,0> aavg0;
    double aavg0_value = aavg0(vec_values4, vec_weights4);
    std::cout << "average value 0 : " << aavg0_value << std::endl;
    std::cout << "" << std::endl;

    // compile data for example functions
    blitz::Array<double, 1> tensorR1D3_0 = mpcexamples::GetRank01ExampleTensor<double>(3);
    blitz::Array<double, 1> tensorR1D3_1 = blitz::Array<double,1>(tensorR1D3_0.shape());
    tensorR1D3_1 = tensorR1D3_0 * 5.0;
    blitz::Array<double, 1> tensorR1D3_2 = blitz::Array<double,1>(tensorR1D3_0.shape());
    tensorR1D3_2 = tensorR1D3_0 * 10.0;
    blitz::Array<double, 1> tensorR1D3_3 = blitz::Array<double,1>(tensorR1D3_0.shape());
    tensorR1D3_3 = tensorR1D3_0 * 15.0;

    std::vector<blitz::Array<double,1>> vec_R1D3;
    vec_R1D3.push_back(tensorR1D3_0);
    vec_R1D3.push_back(tensorR1D3_1);
    vec_R1D3.push_back(tensorR1D3_2);
    vec_R1D3.push_back(tensorR1D3_3);

    mpc::utilities::WeightedHarmonicAverage<double,1> aavg1;
    blitz::Array<double,1> aavg1_R1D3 = aavg1(vec_R1D3, vec_weights4);
    std::cout << "harmonic average R1D3 (1) : " << aavg1_R1D3(0) << std::endl;
    std::cout << "harmonic average R1D3 (2) : " << aavg1_R1D3(1) << std::endl;
    std::cout << "harmonic average R1D3 (3) : " << aavg1_R1D3(2) << std::endl;
    std::cout << "" << std::endl;


    blitz::Array<double, 2> tensorR2D3_0 = mpcexamples::GetRank02ExampleTensor<double>(3);
    blitz::Array<double, 2> tensorR2D3_1 = blitz::Array<double,2>(tensorR2D3_0.shape());
    tensorR2D3_1 = tensorR2D3_0 * 5.0;
    blitz::Array<double, 2> tensorR2D3_2 = blitz::Array<double,2>(tensorR2D3_0.shape());
    tensorR2D3_2 = tensorR2D3_0 * 10.0;
    blitz::Array<double, 2> tensorR2D3_3 = blitz::Array<double,2>(tensorR2D3_0.shape());
    tensorR2D3_3 = tensorR2D3_0 * 15.0;

    std::vector<blitz::Array<double,2>> vec_R2D3;
    vec_R2D3.push_back(tensorR2D3_0);
    vec_R2D3.push_back(tensorR2D3_1);
    vec_R2D3.push_back(tensorR2D3_2);
    vec_R2D3.push_back(tensorR2D3_3);

    mpc::utilities::WeightedHarmonicAverage<double,2> aavg2;
    blitz::Array<double,2> aavg2_R2D3 = aavg2(vec_R2D3, vec_weights4);
    std::cout << "harmonic average R2D3 (1,1) : " << aavg2_R2D3(0,0) << std::endl;
    std::cout << "harmonic average R2D3 (1,2) : " << aavg2_R2D3(0,1) << std::endl;
    std::cout << "harmonic average R2D3 (1,3) : " << aavg2_R2D3(0,2) << std::endl;
    std::cout << "harmonic average R2D3 (2,1) : " << aavg2_R2D3(1,0) << std::endl;
    std::cout << "harmonic average R2D3 (2,2) : " << aavg2_R2D3(1,1) << std::endl;
    std::cout << "harmonic average R2D3 (2,3) : " << aavg2_R2D3(1,2) << std::endl;
    std::cout << "harmonic average R2D3 (3,1) : " << aavg2_R2D3(2,0) << std::endl;
    std::cout << "harmonic average R2D3 (3,2) : " << aavg2_R2D3(2,1) << std::endl;
    std::cout << "harmonic average R2D3 (3,3) : " << aavg2_R2D3(2,2) << std::endl;
    std::cout << "" << std::endl;


}  // END FUNCTION
