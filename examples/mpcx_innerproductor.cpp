#include "mpcx_innerproductor.hpp"
#include "arraysandtensors.hpp"

// c++
#include <iostream>
#include <cmath>

// blitz

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/innerproductor.hpp>

void mpcexamples::mpcInnerProductor() {
    /** innerproductor */

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

    // the products !!!
    blitz::Array<double,1> tensorR1D3b(tensorR1D3.shape());
    tensorR1D3b = tensorR1D3 * 10.0;

    blitz::Array<double,2> tensorR2D3b(tensorR2D3.shape());
    tensorR2D3b = tensorR2D3 * 10.0;

    blitz::Array<double,3> tensorR3D3b(tensorR3D3.shape());
    tensorR3D3b = tensorR3D3 * 10.0;

    blitz::Array<double,4> tensorR4D3b(tensorR4D3.shape());
    tensorR4D3b = tensorR4D3 * 10.0;

    // TEST: InnerProductor rank 1 tensor (i.e, math vector)
    mpc::utilities::InnerProductor<double,1> inner_productor_R1D3_fo;  // function object
    double ipR1D3 = inner_productor_R1D3_fo(tensorR1D3,tensorR1D3b);
    std::cout << "innerProductorR1D3 " << std::endl;
    std::cout << ipR1D3 << std::endl;
    //std::cout << "" << std::endl;

    // TEST: InnerProductor rank 2 tensor
    mpc::utilities::InnerProductor<double,2> inner_productor_R2D3_fo;
    blitz::Array<double,1> ipR2D3 = inner_productor_R2D3_fo(tensorR2D3,tensorR2D3b);
    std::cout << "innerProductorR2D3 " << std::endl;
    PrintTensorComponents1(ipR2D3);
    //std::cout << "" << std::endl;

    // TEST: InnerProductor rank 3 tensor
    mpc::utilities::InnerProductor<double,3> inner_productor_R3D3_fo;
    blitz::Array<double,2> ipR3D3 = inner_productor_R3D3_fo(tensorR3D3,tensorR3D3b);
    std::cout << "innerProductorR3D3 " << std::endl;
    PrintTensorComponents2(ipR3D3);
    //std::cout << "" << std::endl;


    // TEST: InnerProductor rank 4 tensor
    mpc::utilities::InnerProductor<double,4> inner_productor_R4D3_fo;
    blitz::Array<double,3> ipR4D3 = inner_productor_R4D3_fo(tensorR4D3,tensorR4D3b);
    std::cout << "innerProductorR4D3 " << std::endl;
    PrintTensorComponents3(ipR4D3);
    //std::cout << "" << std::endl;


}  // END FUNCTION
