#include "mpcx_tensorrank4component.hpp"

// c++
#include <iostream>

// mpc
#include <mpc/core/tensorcomponentindex.hpp>
#include <mpc/core/tensorcomponent.hpp>

void mpcexamples::mpcTensorRank4Component() {

    /** tensor rank 4 component */

    std::cout << std::boolalpha;

    /*
    * The next step is to build the tensor compoents using the tensor
    *     component index and assigning a value.  The class
    *     TensorRank2Component<T> is a template class that takes an argument
    *     that must be a floating point type, that is float, double, or long
    *     double.
    *
    *  Also, creating blitz arrays is discussed briefly...
    */

    /*
     * tensor component rank 4
     */

    // mpc::core::TensorRankNComponent<double,4> component0000 = mpc::core::TensorRankNComponent<double,4>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
    std::cout << "" << std::endl;
    mpc::core::TensorRank4Component<double> component0000 = mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
    std::cout << "component0000 : " << component0000 << std::endl;
    mpc::core::TensorRank4Component<double> component0001 = mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1));
    std::cout << "component0001 : " << component0001 << std::endl;
    mpc::core::TensorRank4Component<double> component0002 = mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2));
    std::cout << "component0002 : " << component0002 << std::endl;
    mpc::core::TensorRank4Component<double> component0010 = mpc::core::TensorRank4Component<double>(1121.0, mpc::core::TensorRank4ComponentIndex(0,0,1,0));
    std::cout << "component0010 : " << component0010 << std::endl;
    mpc::core::TensorRank4Component<double> component0011 = mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1));
    std::cout << "component0011 : " << component0011 << std::endl;
    mpc::core::TensorRank4Component<double> component0012 = mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2));
    std::cout << "component0012 : " << component0012 << std::endl;
    mpc::core::TensorRank4Component<double> component0020 = mpc::core::TensorRank4Component<double>(1131.0, mpc::core::TensorRank4ComponentIndex(0,0,2,0));
    std::cout << "component0020 : " << component0020 << std::endl;
    mpc::core::TensorRank4Component<double> component0021 = mpc::core::TensorRank4Component<double>(1132.0, mpc::core::TensorRank4ComponentIndex(0,0,2,1));
    std::cout << "component0021 : " << component0021 << std::endl;
    mpc::core::TensorRank4Component<double> component0022 = mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2));
    std::cout << "component0022 : " << component0022 << std::endl;
    mpc::core::TensorRank4Component<double> component0100 = mpc::core::TensorRank4Component<double>(1211.0, mpc::core::TensorRank4ComponentIndex(0,1,0,0));
    std::cout << "component0100 : " << component0100 << std::endl;
    mpc::core::TensorRank4Component<double> component0101 = mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1));
    std::cout << "component0101 : " << component0101 << std::endl;
    mpc::core::TensorRank4Component<double> component0102 = mpc::core::TensorRank4Component<double>(1213.0, mpc::core::TensorRank4ComponentIndex(0,1,0,2));
    std::cout << "component0102 : " << component0102 << std::endl;
    mpc::core::TensorRank4Component<double> component0110 = mpc::core::TensorRank4Component<double>(1221.0, mpc::core::TensorRank4ComponentIndex(0,1,1,0));
    std::cout << "component0110 : " << component0110 << std::endl;
    mpc::core::TensorRank4Component<double> component0111 = mpc::core::TensorRank4Component<double>(1222.0, mpc::core::TensorRank4ComponentIndex(0,1,1,1));
    std::cout << "component0111 : " << component0111 << std::endl;
    mpc::core::TensorRank4Component<double> component0112 = mpc::core::TensorRank4Component<double>(1223.0, mpc::core::TensorRank4ComponentIndex(0,1,1,2));
    std::cout << "component0112 : " << component0112 << std::endl;
    mpc::core::TensorRank4Component<double> component0120 = mpc::core::TensorRank4Component<double>(1231.0, mpc::core::TensorRank4ComponentIndex(0,1,2,0));
    std::cout << "component0120 : " << component0120 << std::endl;
    mpc::core::TensorRank4Component<double> component0121 = mpc::core::TensorRank4Component<double>(1232.0, mpc::core::TensorRank4ComponentIndex(0,1,2,1));
    std::cout << "component0121 : " << component0121 << std::endl;
    mpc::core::TensorRank4Component<double> component0122 = mpc::core::TensorRank4Component<double>(1233.0, mpc::core::TensorRank4ComponentIndex(0,1,2,2));
    std::cout << "component0122 : " << component0122 << std::endl;
    mpc::core::TensorRank4Component<double> component0200 = mpc::core::TensorRank4Component<double>(1311.0, mpc::core::TensorRank4ComponentIndex(0,2,0,0));
    std::cout << "component0200 : " << component0200 << std::endl;
    mpc::core::TensorRank4Component<double> component0201 = mpc::core::TensorRank4Component<double>(1312.0, mpc::core::TensorRank4ComponentIndex(0,2,0,1));
    std::cout << "component0201 : " << component0201 << std::endl;
    mpc::core::TensorRank4Component<double> component0202 = mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2));
    std::cout << "component0202 : " << component0202 << std::endl;
    mpc::core::TensorRank4Component<double> component0210 = mpc::core::TensorRank4Component<double>(1321.0, mpc::core::TensorRank4ComponentIndex(0,2,1,0));
    std::cout << "component0210 : " << component0210 << std::endl;
    mpc::core::TensorRank4Component<double> component0211 = mpc::core::TensorRank4Component<double>(1322.0, mpc::core::TensorRank4ComponentIndex(0,2,1,1));
    std::cout << "component0211 : " << component0211 << std::endl;
    mpc::core::TensorRank4Component<double> component0212 = mpc::core::TensorRank4Component<double>(1323.0, mpc::core::TensorRank4ComponentIndex(0,2,1,2));
    std::cout << "component0212 : " << component0212 << std::endl;
    mpc::core::TensorRank4Component<double> component0220 = mpc::core::TensorRank4Component<double>(1331.0, mpc::core::TensorRank4ComponentIndex(0,2,2,0));
    std::cout << "component0220 : " << component0220 << std::endl;
    mpc::core::TensorRank4Component<double> component0221 = mpc::core::TensorRank4Component<double>(1332.0, mpc::core::TensorRank4ComponentIndex(0,2,2,1));
    std::cout << "component0221 : " << component0221 << std::endl;
    mpc::core::TensorRank4Component<double> component0222 = mpc::core::TensorRank4Component<double>(1333.0, mpc::core::TensorRank4ComponentIndex(0,2,2,2));
    std::cout << "component0222 : " << component0222 << std::endl;
    mpc::core::TensorRank4Component<double> component1000 = mpc::core::TensorRank4Component<double>(2111.0, mpc::core::TensorRank4ComponentIndex(1,0,0,0));
    std::cout << "component1000 : " << component1000 << std::endl;
    mpc::core::TensorRank4Component<double> component1001 = mpc::core::TensorRank4Component<double>(2112.0, mpc::core::TensorRank4ComponentIndex(1,0,0,1));
    std::cout << "component1001 : " << component1001 << std::endl;
    mpc::core::TensorRank4Component<double> component1002 = mpc::core::TensorRank4Component<double>(2113.0, mpc::core::TensorRank4ComponentIndex(1,0,0,2));
    std::cout << "component1002 : " << component1002 << std::endl;
    mpc::core::TensorRank4Component<double> component1010 = mpc::core::TensorRank4Component<double>(2121.0, mpc::core::TensorRank4ComponentIndex(1,0,1,0));
    std::cout << "component1010 : " << component1010 << std::endl;
    mpc::core::TensorRank4Component<double> component1011 = mpc::core::TensorRank4Component<double>(2122.0, mpc::core::TensorRank4ComponentIndex(1,0,1,1));
    std::cout << "component1011 : " << component1011 << std::endl;
    mpc::core::TensorRank4Component<double> component1012 = mpc::core::TensorRank4Component<double>(2123.0, mpc::core::TensorRank4ComponentIndex(1,0,1,2));
    std::cout << "component1012 : " << component1012 << std::endl;
    mpc::core::TensorRank4Component<double> component1020 = mpc::core::TensorRank4Component<double>(2131.0, mpc::core::TensorRank4ComponentIndex(1,0,2,0));
    std::cout << "component1020 : " << component1020 << std::endl;
    mpc::core::TensorRank4Component<double> component1021 = mpc::core::TensorRank4Component<double>(2132.0, mpc::core::TensorRank4ComponentIndex(1,0,2,1));
    std::cout << "component1021 : " << component1021 << std::endl;
    mpc::core::TensorRank4Component<double> component1022 = mpc::core::TensorRank4Component<double>(2133.0, mpc::core::TensorRank4ComponentIndex(1,0,2,2));
    std::cout << "component1022 : " << component1022 << std::endl;
    mpc::core::TensorRank4Component<double> component1100 = mpc::core::TensorRank4Component<double>(2211.0, mpc::core::TensorRank4ComponentIndex(1,1,0,0));
    std::cout << "component1100 : " << component1100 << std::endl;
    mpc::core::TensorRank4Component<double> component1101 = mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1));
    std::cout << "component1101 : " << component1101 << std::endl;
    mpc::core::TensorRank4Component<double> component1102 = mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2));
    std::cout << "component1102 : " << component1102 << std::endl;
    mpc::core::TensorRank4Component<double> component1110 = mpc::core::TensorRank4Component<double>(2221.0, mpc::core::TensorRank4ComponentIndex(1,1,1,0));
    std::cout << "component1110 : " << component1110 << std::endl;
    mpc::core::TensorRank4Component<double> component1111 = mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1));
    std::cout << "component1111 : " << component1111 << std::endl;
    mpc::core::TensorRank4Component<double> component1112 = mpc::core::TensorRank4Component<double>(2223.0, mpc::core::TensorRank4ComponentIndex(1,1,1,2));
    std::cout << "component1112 : " << component1112 << std::endl;
    mpc::core::TensorRank4Component<double> component1120 = mpc::core::TensorRank4Component<double>(2231.0, mpc::core::TensorRank4ComponentIndex(1,1,2,0));
    std::cout << "component1120 : " << component1120 << std::endl;
    mpc::core::TensorRank4Component<double> component1121 = mpc::core::TensorRank4Component<double>(2232.0, mpc::core::TensorRank4ComponentIndex(1,1,2,1));
    std::cout << "component1121 : " << component1121 << std::endl;
    mpc::core::TensorRank4Component<double> component1122 = mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2));
    std::cout << "component1122 : " << component1122 << std::endl;
    mpc::core::TensorRank4Component<double> component1200 = mpc::core::TensorRank4Component<double>(2311.0, mpc::core::TensorRank4ComponentIndex(1,2,0,0));
    std::cout << "component1200 : " << component1200 << std::endl;
    mpc::core::TensorRank4Component<double> component1201 = mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1));
    std::cout << "component1201 : " << component1201 << std::endl;
    mpc::core::TensorRank4Component<double> component1202 = mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2));
    std::cout << "component1202 : " << component1202 << std::endl;
    mpc::core::TensorRank4Component<double> component1210 = mpc::core::TensorRank4Component<double>(2321.0, mpc::core::TensorRank4ComponentIndex(1,2,1,0));
    std::cout << "component1210 : " << component1210 << std::endl;
    mpc::core::TensorRank4Component<double> component1211 = mpc::core::TensorRank4Component<double>(2322.0, mpc::core::TensorRank4ComponentIndex(1,2,1,1));
    std::cout << "component1211 : " << component1211 << std::endl;
    mpc::core::TensorRank4Component<double> component1212 = mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2));
    std::cout << "component1212 : " << component1212 << std::endl;
    mpc::core::TensorRank4Component<double> component1220 = mpc::core::TensorRank4Component<double>(2331.0, mpc::core::TensorRank4ComponentIndex(1,2,2,0));
    std::cout << "component1220 : " << component1220 << std::endl;
    mpc::core::TensorRank4Component<double> component1221 = mpc::core::TensorRank4Component<double>(2332.0, mpc::core::TensorRank4ComponentIndex(1,2,2,1));
    std::cout << "component1221 : " << component1221 << std::endl;
    mpc::core::TensorRank4Component<double> component1222 = mpc::core::TensorRank4Component<double>(2333.0, mpc::core::TensorRank4ComponentIndex(1,2,2,2));
    std::cout << "component1222 : " << component1222 << std::endl;
    mpc::core::TensorRank4Component<double> component2000 = mpc::core::TensorRank4Component<double>(3111.0, mpc::core::TensorRank4ComponentIndex(2,0,0,0));
    std::cout << "component2000 : " << component2000 << std::endl;
    mpc::core::TensorRank4Component<double> component2001 = mpc::core::TensorRank4Component<double>(3112.0, mpc::core::TensorRank4ComponentIndex(2,0,0,1));
    std::cout << "component2001 : " << component2001 << std::endl;
    mpc::core::TensorRank4Component<double> component2002 = mpc::core::TensorRank4Component<double>(3113.0, mpc::core::TensorRank4ComponentIndex(2,0,0,2));
    std::cout << "component2002 : " << component2002 << std::endl;
    mpc::core::TensorRank4Component<double> component2010 = mpc::core::TensorRank4Component<double>(3121.0, mpc::core::TensorRank4ComponentIndex(2,0,1,0));
    std::cout << "component2010 : " << component2010 << std::endl;
    mpc::core::TensorRank4Component<double> component2011 = mpc::core::TensorRank4Component<double>(3122.0, mpc::core::TensorRank4ComponentIndex(2,0,1,1));
    std::cout << "component2011 : " << component2011 << std::endl;
    mpc::core::TensorRank4Component<double> component2012 = mpc::core::TensorRank4Component<double>(3123.0, mpc::core::TensorRank4ComponentIndex(2,0,1,2));
    std::cout << "component2012 : " << component2012 << std::endl;
    mpc::core::TensorRank4Component<double> component2020 = mpc::core::TensorRank4Component<double>(3131.0, mpc::core::TensorRank4ComponentIndex(2,0,2,0));
    std::cout << "component2020 : " << component2020 << std::endl;
    mpc::core::TensorRank4Component<double> component2021 = mpc::core::TensorRank4Component<double>(3132.0, mpc::core::TensorRank4ComponentIndex(2,0,2,1));
    std::cout << "component2021 : " << component2021 << std::endl;
    mpc::core::TensorRank4Component<double> component2022 = mpc::core::TensorRank4Component<double>(3133.0, mpc::core::TensorRank4ComponentIndex(2,0,2,2));
    std::cout << "component2022 : " << component2022 << std::endl;
    mpc::core::TensorRank4Component<double> component2100 = mpc::core::TensorRank4Component<double>(3211.0, mpc::core::TensorRank4ComponentIndex(2,1,0,0));
    std::cout << "component2100 : " << component2100 << std::endl;
    mpc::core::TensorRank4Component<double> component2101 = mpc::core::TensorRank4Component<double>(3212.0, mpc::core::TensorRank4ComponentIndex(2,1,0,1));
    std::cout << "component2101 : " << component2101 << std::endl;
    mpc::core::TensorRank4Component<double> component2102 = mpc::core::TensorRank4Component<double>(3213.0, mpc::core::TensorRank4ComponentIndex(2,1,0,2));
    std::cout << "component2102 : " << component2102 << std::endl;
    mpc::core::TensorRank4Component<double> component2110 = mpc::core::TensorRank4Component<double>(3221.0, mpc::core::TensorRank4ComponentIndex(2,1,1,0));
    std::cout << "component2110 : " << component2110 << std::endl;
    mpc::core::TensorRank4Component<double> component2111 = mpc::core::TensorRank4Component<double>(3222.0, mpc::core::TensorRank4ComponentIndex(2,1,1,1));
    std::cout << "component2111 : " << component2111 << std::endl;
    mpc::core::TensorRank4Component<double> component2112 = mpc::core::TensorRank4Component<double>(3223.0, mpc::core::TensorRank4ComponentIndex(2,1,1,2));
    std::cout << "component2112 : " << component2112 << std::endl;
    mpc::core::TensorRank4Component<double> component2120 = mpc::core::TensorRank4Component<double>(3231.0, mpc::core::TensorRank4ComponentIndex(2,1,2,0));
    std::cout << "component2120 : " << component2120 << std::endl;
    mpc::core::TensorRank4Component<double> component2121 = mpc::core::TensorRank4Component<double>(3232.0, mpc::core::TensorRank4ComponentIndex(2,1,2,1));
    std::cout << "component2121 : " << component2121 << std::endl;
    mpc::core::TensorRank4Component<double> component2122 = mpc::core::TensorRank4Component<double>(3233.0, mpc::core::TensorRank4ComponentIndex(2,1,2,2));
    std::cout << "component2122 : " << component2122 << std::endl;
    mpc::core::TensorRank4Component<double> component2200 = mpc::core::TensorRank4Component<double>(3311.0, mpc::core::TensorRank4ComponentIndex(2,2,0,0));
    std::cout << "component2200 : " << component2200 << std::endl;
    mpc::core::TensorRank4Component<double> component2201 = mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1));
    std::cout << "component2201 : " << component2201 << std::endl;
    mpc::core::TensorRank4Component<double> component2202 = mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2));
    std::cout << "component2202 : " << component2202 << std::endl;
    mpc::core::TensorRank4Component<double> component2210 = mpc::core::TensorRank4Component<double>(3321.0, mpc::core::TensorRank4ComponentIndex(2,2,1,0));
    std::cout << "component2210 : " << component2210 << std::endl;
    mpc::core::TensorRank4Component<double> component2211 = mpc::core::TensorRank4Component<double>(3322.0, mpc::core::TensorRank4ComponentIndex(2,2,1,1));
    std::cout << "component2211 : " << component2211 << std::endl;
    mpc::core::TensorRank4Component<double> component2212 = mpc::core::TensorRank4Component<double>(3323.0, mpc::core::TensorRank4ComponentIndex(2,2,1,2));
    std::cout << "component2212 : " << component2212 << std::endl;
    mpc::core::TensorRank4Component<double> component2220 = mpc::core::TensorRank4Component<double>(3331.0, mpc::core::TensorRank4ComponentIndex(2,2,2,0));
    std::cout << "component2220 : " << component2220 << std::endl;
    mpc::core::TensorRank4Component<double> component2221 = mpc::core::TensorRank4Component<double>(3332.0, mpc::core::TensorRank4ComponentIndex(2,2,2,1));
    std::cout << "component2221 : " << component2221 << std::endl;
    mpc::core::TensorRank4Component<double> component2222 = mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2));
    std::cout << "component2222 : " << component2222 << std::endl;

    //  One example of creating a blitz multidimensional array as a fourth rank
    //     tensor in 3D Cartesian space:
    std::cout << "" << std::endl;

    const int ND3 = 3; // 3-dimensional space
    const int RANK4 = 4;
    blitz::Array<float,RANK4> tensor4_in_3d =
            blitz::Array<float,RANK4>(ND3, ND3, ND3, ND3, blitz::ColumnMajorArray<4>());
    int counter = 0;
    for (int i=0; i<ND3; ++i) {
        for (int j=0; j<ND3; ++j) {
            for (int k=0; k<ND3; ++k) {
                for (int l=0; l<ND3; ++l) {
                    tensor4_in_3d(i,j,k,l) = mpc::core::TensorRank4Component<float>(
                            counter, mpc::core::TensorRank4ComponentIndex(i,j,k,l)).Value();
                    ++counter;
                }
            }
        }
    }

    /*
     * TensorComponent comparison operators < and > use the index member
     *     variable, not the value.  Therefore, we can store
     *     TensorRank2Components in a std::set<> and be guaranteed uniqueness...
     */
    std::cout << "" << std::endl;

    std::set<mpc::core::TensorRank4Component<double> > rank4_component_set {};
    rank4_component_set.insert(component0000);
    rank4_component_set.insert(component0001);
    rank4_component_set.insert(component0002);
    rank4_component_set.insert(component0010);
    rank4_component_set.insert(component0011);
    rank4_component_set.insert(component0012);
    rank4_component_set.insert(component0020);
    rank4_component_set.insert(component0021);
    rank4_component_set.insert(component0022);
    std::cout << "rank4_component_set.size() : " << rank4_component_set.size() << std::endl;
    // will not insert because index already exitsts
    rank4_component_set.insert(mpc::core::TensorRank4Component<double>(99.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)));
    std::cout << "rank4_component_set.size() after attempt to insert duplicate index : " << rank4_component_set.size() << std::endl;

    // END

}
