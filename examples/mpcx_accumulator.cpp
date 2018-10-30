#include "mpcx_accumulator.hpp"
#include "arraysandtensors.hpp"

// c++
#include <iostream>
#include <cmath>

// blitz

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/accumulator.hpp>


void mpcexamples::mpcAccumulator() {
    /** accumulator */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    // compile data for example functions
    blitz::Array<double,1> tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
    blitz::Array<double,2> tensorR2D3 = mpcexamples::GetRank02ExampleTensor<double>(3);
    blitz::Array<double,3> tensorR3D3 = mpcexamples::GetRank03ExampleTensor<double>(3);
    blitz::Array<double,4> tensorR4D3 = mpcexamples::GetRank04ExampleTensor<double>(3);

    mpc::utilities::PrintTensorComponents<double,1> PrintTensorComponents1;
    mpc::utilities::PrintTensorComponents<double,2> PrintTensorComponents2;
    mpc::utilities::PrintTensorComponents<double,3> PrintTensorComponents3;

    // TEST: AccumulatorSum rank 1 tensor (i.e, math vector)
    std::cout << "extents: " << tensorR1D3.extent(0) << std::endl;
    mpc::utilities::AccumulatorSum<double,1> accumulator_sum_R1D3_fo;  // function object
    double asumR1D3 = accumulator_sum_R1D3_fo(tensorR1D3);
    std::cout << "accumulator sum R1D3 " << std::endl;
    std::cout << asumR1D3 << std::endl;
    //std::cout << "" << std::endl;

    // TEST: AccumulatorSum rank 2 tensor
    std::cout << "extent 0: " << tensorR2D3.extent(0) << std::endl;
    std::cout << "extent 1: " << tensorR2D3.extent(1) << std::endl;
    mpc::utilities::AccumulatorSum<double,2> accumulator_sum_R2D3_fo;  // function object
    blitz::Array<double,1> asumR2D3 = accumulator_sum_R2D3_fo(tensorR2D3);
    std::cout << "accumulator sum R2D3 " << std::endl;
    PrintTensorComponents1(asumR2D3);
    //std::cout << "" << std::endl;

    // TEST: AccumulatorSum rank 3 tensor
    std::cout << "extent 0: " << tensorR3D3.extent(0) << std::endl;
    std::cout << "extent 1: " << tensorR3D3.extent(1) << std::endl;
    std::cout << "extent 2: " << tensorR3D3.extent(2) << std::endl;
    mpc::utilities::AccumulatorSum<double,3> accumulator_sum_R3D3_fo;
    blitz::Array<double,2> asumR3D3 = accumulator_sum_R3D3_fo(tensorR3D3);
    std::cout << "accumulator sum R3D3 " << std::endl;
    PrintTensorComponents2(asumR3D3);
    //std::cout << "" << std::endl;

    // TEST: AccumulatorSum rank 4 tensor
    std::cout << "extent 0: " << tensorR4D3.extent(0) << std::endl;
    std::cout << "extent 1: " << tensorR4D3.extent(1) << std::endl;
    std::cout << "extent 2: " << tensorR4D3.extent(2) << std::endl;
    std::cout << "extent 2: " << tensorR4D3.extent(3) << std::endl;
    mpc::utilities::AccumulatorSum<double,4> accumulator_sum_R4D3_fo;
    blitz::Array<double,3> asumR4D3 = accumulator_sum_R4D3_fo(tensorR4D3);
    std::cout << "accumulator sum R4D3: " << std::endl;
    PrintTensorComponents3(asumR4D3);
    //std::cout << "" << std::endl;

    //--------------------------------------------------------------------------------------------------
    // TEST: AccumulatorProduct rank 1 tensor
    std::cout << "extents: " << tensorR1D3.extent(0) << std::endl;
    mpc::utilities::AccumulatorProduct<double,1> accumulator_product_R1D3_fo;
    double aprodR1D3 = accumulator_product_R1D3_fo(tensorR1D3);
    std::cout << "accumulator product R1D3 " << std::endl;
    std::cout << aprodR1D3 << std::endl;
    //std::cout << "" << std::endl;

    // TEST: AccumulatorProduct rank 2 tensor
    std::cout << "extent 0: " << tensorR2D3.extent(0) << std::endl;
    std::cout << "extent 1: " << tensorR2D3.extent(1) << std::endl;
    mpc::utilities::AccumulatorProduct<double,2> accumulator_product_R2D3_fo;
    blitz::Array<double,1> aprodR2D3 = accumulator_product_R2D3_fo(tensorR2D3);
    std::cout << "accumulator product R2D3 " << std::endl;
    PrintTensorComponents1(aprodR2D3);
    //std::cout << "" << std::endl;

    // TEST: AccumulatorProduct rank 3 tensor
    std::cout << "extent 0: " << tensorR3D3.extent(0) << std::endl;
    std::cout << "extent 1: " << tensorR3D3.extent(1) << std::endl;
    std::cout << "extent 2: " << tensorR3D3.extent(2) << std::endl;
    mpc::utilities::AccumulatorProduct<double,3> accumulator_product_R3D3_fo;
    blitz::Array<double,2> aprodR3D3 = accumulator_product_R3D3_fo(tensorR3D3);
    std::cout << "accumulator product R3D3 " << std::endl;
    PrintTensorComponents2(aprodR3D3);
    //std::cout << "" << std::endl;

    // TEST: AccumulatorProduct rank 4 tensor
    std::cout << "extent 0: " << tensorR4D3.extent(0) << std::endl;
    std::cout << "extent 1: " << tensorR4D3.extent(1) << std::endl;
    std::cout << "extent 2: " << tensorR4D3.extent(2) << std::endl;
    std::cout << "extent 3: " << tensorR4D3.extent(3) << std::endl;
    mpc::utilities::AccumulatorProduct<double,4> accumulator_product_R4D3_fo;
    blitz::Array<double,3> aprodR4D3 = accumulator_product_R4D3_fo(tensorR4D3);
    std::cout << "accumulator product R4D3 " << std::endl;
    PrintTensorComponents3(aprodR4D3);
    //std::cout << "" << std::endl;

    


}  // END FUNCTION
