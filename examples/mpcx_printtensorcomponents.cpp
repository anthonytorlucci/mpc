#include "mpcx_printtensorcomponents.hpp"
#include "arraysandtensors.hpp"

// c++
#include <iostream>
#include <cmath>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>

void mpcexamples::mpcPrintTensorComponents() {
    /** print tensor components */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    std::cout << "tensor Rank 1 Order 3\n" << std::endl;
    mpc::utilities::PrintTensorComponents<double,1> PrintTensorComponents1;
    // blitz::Array<double,1> tensorR1D3
    auto tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
    PrintTensorComponents1(tensorR1D3);

    std::cout << "tensor Rank 2 Order 3\n" << std::endl;
    mpc::utilities::PrintTensorComponents<double,2> PrintTensorComponents2;
    // blitz::Array<double,2> tensorR2D3
    auto tensorR2D3 = mpcexamples::GetRank02ExampleTensor<double>(3);
    PrintTensorComponents2(tensorR2D3);

//    std::cout << "array Rank 2 Order (5,2)\n" << std::endl;
//    // blitz::Array<double,2> arrayR2D5_2
//    auto arrayR2D5_2 = mpcexamples::GetRank02ExampleArray<double>(5,2);
//    std::cout << "(0,0) => " << arrayR2D5_2(0,0) << std::endl;
//    std::cout << "(0,1) => " << arrayR2D5_2(0,1) << std::endl;
//    std::cout << "(1,0) => " << arrayR2D5_2(1,0) << std::endl;
//    std::cout << "(1,1) => " << arrayR2D5_2(1,1) << std::endl;
//    std::cout << "(2,0) => " << arrayR2D5_2(2,0) << std::endl;
//    std::cout << "(2,1) => " << arrayR2D5_2(2,1) << std::endl;
//    std::cout << "(3,0) => " << arrayR2D5_2(3,0) << std::endl;
//    std::cout << "(3,1) => " << arrayR2D5_2(3,1) << std::endl;
//    std::cout << "(4,0) => " << arrayR2D5_2(4,0) << std::endl;
//    std::cout << "(4,1) => " << arrayR2D5_2(4,1) << std::endl;
//    std::cout << "" << std::endl;

    std::cout << "tensor Rank 3 Order 3\n" << std::endl;
    mpc::utilities::PrintTensorComponents<double,3> PrintTensorComponents3;
    // blitz::Array<double,3> tensorR3D3
    auto tensorR3D3 = mpcexamples::GetRank03ExampleTensor<double>(3);
    PrintTensorComponents3(tensorR3D3);

//    std::cout << "array Rank 3 Order (2,3,4)\n" << std::endl;
//    // blitz::Array<double,3> arrayR3D2_3_4
//    auto arrayR3D2_3_4 = mpcexamples::GetRank03ExampleArray<double>(2,3,4);
//    std::cout << "(0,0,0) => " << arrayR3D2_3_4(0,0,0) << std::endl;
//    std::cout << "(0,0,1) => " << arrayR3D2_3_4(0,0,1) << std::endl;
//    std::cout << "(0,0,2) => " << arrayR3D2_3_4(0,0,2) << std::endl;
//    std::cout << "(0,0,3) => " << arrayR3D2_3_4(0,0,3) << std::endl;
//    std::cout << "(0,1,0) => " << arrayR3D2_3_4(0,1,0) << std::endl;
//    std::cout << "(0,1,1) => " << arrayR3D2_3_4(0,1,1) << std::endl;
//    std::cout << "(0,1,2) => " << arrayR3D2_3_4(0,1,2) << std::endl;
//    std::cout << "(0,1,3) => " << arrayR3D2_3_4(0,1,3) << std::endl;
//    std::cout << "(0,2,0) => " << arrayR3D2_3_4(0,2,0) << std::endl;
//    std::cout << "(0,2,1) => " << arrayR3D2_3_4(0,2,1) << std::endl;
//    std::cout << "(0,2,2) => " << arrayR3D2_3_4(0,2,2) << std::endl;
//    std::cout << "(0,2,3) => " << arrayR3D2_3_4(0,2,3) << std::endl;
//    //
//    std::cout << "(1,0,0) => " << arrayR3D2_3_4(1,0,0) << std::endl;
//    std::cout << "(1,0,1) => " << arrayR3D2_3_4(1,0,1) << std::endl;
//    std::cout << "(1,0,2) => " << arrayR3D2_3_4(1,0,2) << std::endl;
//    std::cout << "(1,0,3) => " << arrayR3D2_3_4(1,0,3) << std::endl;
//    std::cout << "(1,1,0) => " << arrayR3D2_3_4(1,1,0) << std::endl;
//    std::cout << "(1,1,1) => " << arrayR3D2_3_4(1,1,1) << std::endl;
//    std::cout << "(1,1,2) => " << arrayR3D2_3_4(1,1,2) << std::endl;
//    std::cout << "(1,1,3) => " << arrayR3D2_3_4(1,1,3) << std::endl;
//    std::cout << "(1,2,0) => " << arrayR3D2_3_4(1,2,0) << std::endl;
//    std::cout << "(1,2,1) => " << arrayR3D2_3_4(1,2,1) << std::endl;
//    std::cout << "(1,2,2) => " << arrayR3D2_3_4(1,2,2) << std::endl;
//    std::cout << "(1,2,3) => " << arrayR3D2_3_4(1,2,3) << std::endl;
//    std::cout << "" << std::endl;

    std::cout << "tensor Rank 4 Order 3\n" << std::endl;
    mpc::utilities::PrintTensorComponents<double,4> PrintTensorComponents4;
    // blitz::Array<double,4> tensorR4D3
    auto tensorR4D3 = mpcexamples::GetRank04ExampleTensor<double>(3);
    PrintTensorComponents4(tensorR4D3);


}  // END FUNCTION
