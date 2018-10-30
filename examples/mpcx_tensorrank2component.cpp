#include "mpcx_tensorrank2component.hpp"

// c++
#include <iostream>

// blitz
#include <blitz/array.h>

// eigen
#include <Eigen/Dense>

// mpc
#include <mpc/core/tensorcomponentindex.hpp>
#include <mpc/core/tensorcomponent.hpp>

void mpcexamples::mpcTensorRank2Component() {

    /** tensor rank 2 component */

    std::cout << std::boolalpha;

    /*
     * The next step is to build the tensor compoents using the tensor
     *     component index and assigning a value.  The class
     *     TensorRank2Component<T> is a template class that takes an argument
     *     that must be a floating point type, that is float, double, or long
     *     double.
     *
     *  Also, creating blitz arrays and eigen matrices is discussed briefly...
     */

    /*
     * tensorcomponent rank 2
     */

    std::cout << "" << std::endl;
    mpc::core::TensorRankNComponent<double,2> component00 = mpc::core::TensorRankNComponent<double,2>(11.0, mpc::core::TensorRank2ComponentIndex(0,0));
    std::cout << "component00 : " << component00 << std::endl;
    mpc::core::TensorRank2Component<double> component01 = mpc::core::TensorRank2Component<double>(12.0, mpc::core::TensorRank2ComponentIndex(0,1));
    std::cout << "component01 : " << component01 << std::endl;
    mpc::core::TensorRank2Component<double> component02 = mpc::core::TensorRank2Component<double>(13.0, mpc::core::TensorRank2ComponentIndex(0,2));
    std::cout << "component01 : " << component02 << std::endl;
    mpc::core::TensorRank2Component<double> component10 = mpc::core::TensorRank2Component<double>(21.0, mpc::core::TensorRank2ComponentIndex(1,0));
    std::cout << "component01 : " << component10 << std::endl;
    mpc::core::TensorRank2Component<double> component11 = mpc::core::TensorRank2Component<double>(22.0, mpc::core::TensorRank2ComponentIndex(1,1));
    std::cout << "component01 : " << component11 << std::endl;
    mpc::core::TensorRank2Component<double> component12 = mpc::core::TensorRank2Component<double>(23.0, mpc::core::TensorRank2ComponentIndex(1,2));
    std::cout << "component01 : " << component12 << std::endl;
    mpc::core::TensorRank2Component<double> component20 = mpc::core::TensorRank2Component<double>(31.0, mpc::core::TensorRank2ComponentIndex(2,0));
    std::cout << "component01 : " << component20 << std::endl;
    mpc::core::TensorRank2Component<double> component21 = mpc::core::TensorRank2Component<double>(32.0, mpc::core::TensorRank2ComponentIndex(2,1));
    std::cout << "component01 : " << component21 << std::endl;
    mpc::core::TensorRank2Component<double> component22 = mpc::core::TensorRank2Component<double>(33.0, mpc::core::TensorRank2ComponentIndex(2,2));
    std::cout << "component01 : " << component22 << std::endl;

    /*
     * MPC uses two additional libraries: blitz and eigen.  Below are a few
     *     examples of creating arrays in blitz and matrices in eigen...
     */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    blitz::Array<double,1> barray1d(3);
    barray1d = component00.Value(), component01.Value(), component02.Value();
    std::cout << "blitz array 1d : " << barray1d << std::endl;

    // NOTE the order in assignment!!! Its the transpose of the actual matrix;
    //     this is becuase we used ColumnMajorArray for storage ordering.
    blitz::Array<double,2> barray2d = blitz::Array<double,2>(3,3,blitz::ColumnMajorArray<2>());
    barray2d = component00.Value(), component10.Value(), component20.Value(),
            component01.Value(), component11.Value(), component21.Value(),
            component02.Value(), component12.Value(), component22.Value();
    std::cout << "blitz array 2d : " << barray2d << std::endl;

    Eigen::Matrix<double,3,3> earray2d;
    earray2d(0,0) = component00.Value();
    earray2d(0,1) = component01.Value();
    earray2d(0,2) = component02.Value();
    earray2d(1,0) = component10.Value();
    earray2d(1,1) = component11.Value();
    earray2d(1,2) = component12.Value();
    earray2d(2,0) = component20.Value();
    earray2d(2,1) = component21.Value();
    earray2d(2,2) = component22.Value();
    std::cout << "Eigen array 2d : \n" << earray2d << std::endl;

    /*
     * comparison operators
     * "==" : two components are equal if the index AND the value are equal
     * "!=" : two components are not equal if the index OR the value are not equal
     * "<"  : lhs component is less than rhs component if lhs component index is less than rhs component index
     * ">"  : lhs component is greater than rhs component if lhs component index is greater than rhs component index
     * "<=" : lhs component is less or equal to rhs component if lhs component index is less than or equal to rhs component index
     * ">=" : lhs component is greater than or equal to rhs component if lhs component index is greater than or equal to rhs component index
     */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    std::vector<mpc::core::TensorRank2Component<double> > vec_componentXX{
            component00,
            component01,
            component02,
            component10,
            component11,
            component12,
            component20,
            component21,
            component22
    };

    for (auto componentXX : vec_componentXX) {
        std::cout << componentXX << " == " << component11 << " : " << (componentXX == component11) << std::endl;
        std::cout << componentXX << " != " << component11 << " : " << (componentXX != component11) << std::endl;
        std::cout << componentXX << " <  " << component11 << " : " << (componentXX < component11) << std::endl;
        std::cout << componentXX << " >  " << component11 << " : " << (componentXX > component11) << std::endl;
        std::cout << componentXX << " <= " << component11 << " : " << (componentXX <= component11) << std::endl;
        std::cout << componentXX << " >= " << component11 << " : " << (componentXX >= component11) << std::endl;
    }

    /*
    * TensorComponent comparison operators < and > use the index member
    *     variable, not the value.  Therefore, we can store
    *     TensorRank2Components in a std::set<> and be guaranteed uniqueness...
    */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    std::set<mpc::core::TensorRankNComponent<double,2> > rank2_component_set {};
    rank2_component_set.insert(component00);
    rank2_component_set.insert(component01);
    rank2_component_set.insert(component02);
    rank2_component_set.insert(component10);
    rank2_component_set.insert(component11);
    rank2_component_set.insert(component12);
    rank2_component_set.insert(component20);
    rank2_component_set.insert(component21);
    rank2_component_set.insert(component22);
    std::cout << "rank2_component_set.size() : " << rank2_component_set.size() << std::endl;
    // will not insert because index already exitsts
    rank2_component_set.insert(mpc::core::TensorRank2Component<double>(99.0, mpc::core::TensorRank2ComponentIndex(0,0)));
    std::cout << "rank2_component_set.size() after attempt to insert duplicate index : " << rank2_component_set.size() << std::endl;

    // compile-time version doesnt' make sense here; the value is a floating-point
    //      and thus cannot be used as a template parameter value, neither can
    //      index because it is a user defined type.


}
