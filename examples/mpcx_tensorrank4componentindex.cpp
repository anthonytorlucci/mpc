#include "mpcx_tensorrank4componentindex.hpp"

// c++
#include <iostream>

// mpc
#include <mpc/core/tensorcomponentindex.hpp>
#include <mpc/core/tensorcomponentindexaliases.hpp>
#include <mpc/core/tensorcomponentindexpredicates.hpp>

void mpcexamples::mpcTensorRank4ComponentIndex() {
    /** tensor rank 4 component index */
    std::cout << std::boolalpha;

    /*
     * A component index for a tensor of rank 4 is also defined in
     *     mpc/core/tensorcomponentindex.h and can be constructed in a similar
     *     manner to a tensor component of rank 2.  It also has a constexpr
     *     constructor and constexpr member functions to retrieve the index
     *     values...
     */

    std::cout << "" << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0000 = mpc::core::TensorRankNComponentIndex<4>(0,0,0,0);
    std::cout << "index(0,0,0,0) : " << index0000 << std::endl;
    std::cout << "FirstIndex() :   " << index0000.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0000.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0000.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0000.FourthIndex() << std::endl;
    std::cout << index0000 << " index using operator [0] : " << index0000[0] << std::endl;
    std::cout << index0000 << " index using operator [1] : " << index0000[1] << std::endl;
    std::cout << index0000 << " index using operator [2] : " << index0000[2] << std::endl;
    std::cout << index0000 << " index using operator [3] : " << index0000[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0001 = mpc::core::TensorRankNComponentIndex<4>(0,0,0,1);
    std::cout << "index(0,0,0,1) : " << index0001 << std::endl;
    std::cout << "FirstIndex() :   " << index0001.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0001.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0001.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0001.FourthIndex() << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0002 = mpc::core::TensorRankNComponentIndex<4>(0,0,0,2);
    std::cout << "index(0,0,0,2) : " << index0002 << std::endl;
    std::cout << "FirstIndex() :   " << index0002.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0002.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0002.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0002.FourthIndex() << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0010 = mpc::core::TensorRankNComponentIndex<4>(0,0,1,0);
    std::cout << "index(0,0,1,0) : " << index0010 << std::endl;
    std::cout << "FirstIndex() :   " << index0010.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0010.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0010.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0010.FourthIndex() << std::endl;
    std::cout << index0010 << " index using operator [0] : " << index0010[0] << std::endl;
    std::cout << index0010 << " index using operator [1] : " << index0010[1] << std::endl;
    std::cout << index0010 << " index using operator [2] : " << index0010[2] << std::endl;
    std::cout << index0010 << " index using operator [3] : " << index0010[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0011 = mpc::core::TensorRankNComponentIndex<4>(0,0,1,1);
    std::cout << "index(0,0,1,1) : " << index0011 << std::endl;
    std::cout << "FirstIndex() :   " << index0011.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0011.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0011.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0011.FourthIndex() << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0012 = mpc::core::TensorRankNComponentIndex<4>(0,0,1,2);
    std::cout << "index(0,0,1,2) : " << index0012 << std::endl;
    std::cout << "FirstIndex() :   " << index0012.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0012.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0012.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0012.FourthIndex() << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0020 = mpc::core::TensorRankNComponentIndex<4>(0,0,2,0);
    std::cout << "index(0,0,2,0) : " << index0020 << std::endl;
    std::cout << "FirstIndex() :   " << index0020.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0020.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0020.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0020.FourthIndex() << std::endl;
    std::cout << index0020 << " index using operator [0] : " << index0020[0] << std::endl;
    std::cout << index0020 << " index using operator [1] : " << index0020[1] << std::endl;
    std::cout << index0020 << " index using operator [2] : " << index0020[2] << std::endl;
    std::cout << index0020 << " index using operator [3] : " << index0020[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0021 = mpc::core::TensorRankNComponentIndex<4>(0,0,2,1);
    std::cout << "index(0,0,2,1) : " << index0021 << std::endl;
    std::cout << "FirstIndex() :   " << index0021.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0021.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0021.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0021.FourthIndex() << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0022 = mpc::core::TensorRankNComponentIndex<4>(0,0,2,2);
    std::cout << "index(0,0,2,2) : " << index0022 << std::endl;
    std::cout << "FirstIndex() :   " << index0022.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0022.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0022.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0022.FourthIndex() << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0100 = mpc::core::TensorRankNComponentIndex<4>(0,1,0,0);
    std::cout << "index(0,1,0,0) : " << index0100 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0101 = mpc::core::TensorRankNComponentIndex<4>(0,1,0,1);
    std::cout << "index(0,1,0,1) : " << index0101 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0102 = mpc::core::TensorRankNComponentIndex<4>(0,1,0,2);
    std::cout << "index(0,1,0,2) : " << index0102 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0110 = mpc::core::TensorRankNComponentIndex<4>(0,1,1,0);
    std::cout << "index(0,1,1,0) : " << index0110 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0111 = mpc::core::TensorRankNComponentIndex<4>(0,1,1,1);
    std::cout << "index(0,1,1,1) : " << index0111 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0112 = mpc::core::TensorRankNComponentIndex<4>(0,1,1,2);
    std::cout << "index(0,1,1,2) : " << index0112 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0120 = mpc::core::TensorRankNComponentIndex<4>(0,1,2,0);
    std::cout << "index(0,1,2,0) : " << index0120 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0121 = mpc::core::TensorRankNComponentIndex<4>(0,1,2,1);
    std::cout << "index(0,1,2,1) : " << index0121 << std::endl;
    std::cout << "FirstIndex() :   " << index0121.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0121.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0121.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0121.FourthIndex() << std::endl;
    std::cout << index0121 << " index using operator [0] : " << index0121[0] << std::endl;
    std::cout << index0121 << " index using operator [1] : " << index0121[1] << std::endl;
    std::cout << index0121 << " index using operator [2] : " << index0121[2] << std::endl;
    std::cout << index0121 << " index using operator [3] : " << index0121[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0122 = mpc::core::TensorRankNComponentIndex<4>(0,1,2,2);
    std::cout << "index(0,1,2,2) : " << index0122 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0200 = mpc::core::TensorRankNComponentIndex<4>(0,2,0,0);
    std::cout << "index(0,2,0,0) : " << index0200 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0201 = mpc::core::TensorRankNComponentIndex<4>(0,2,0,1);
    std::cout << "index(0,2,0,1) : " << index0201 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0202 = mpc::core::TensorRankNComponentIndex<4>(0,2,0,2);
    std::cout << "index(0,2,0,2) : " << index0202 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0210 = mpc::core::TensorRankNComponentIndex<4>(0,2,1,0);
    std::cout << "index(0,2,1,0) : " << index0210 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0211 = mpc::core::TensorRankNComponentIndex<4>(0,2,1,1);
    std::cout << "index(0,2,1,1) : " << index0211 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0212 = mpc::core::TensorRankNComponentIndex<4>(0,2,1,2);
    std::cout << "index(0,2,1,2) : " << index0212 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0220 = mpc::core::TensorRankNComponentIndex<4>(0,2,2,0);
    std::cout << "index(0,2,2,0) : " << index0220 << std::endl;
    std::cout << "FirstIndex() :   " << index0220.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index0220.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index0220.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index0220.FourthIndex() << std::endl;
    std::cout << index0220 << " index using operator [0] : " << index0220[0] << std::endl;
    std::cout << index0220 << " index using operator [1] : " << index0220[1] << std::endl;
    std::cout << index0220 << " index using operator [2] : " << index0220[2] << std::endl;
    std::cout << index0220 << " index using operator [3] : " << index0220[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0221 = mpc::core::TensorRankNComponentIndex<4>(0,2,2,1);
    std::cout << "index(0,2,2,1) : " << index0221 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index0222 = mpc::core::TensorRankNComponentIndex<4>(0,2,2,2);
    std::cout << "index(0,2,2,2) : " << index0222 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1000 = mpc::core::TensorRankNComponentIndex<4>(1,0,0,0);
    std::cout << "index(1,0,0,0) : " << index1000 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1001 = mpc::core::TensorRankNComponentIndex<4>(1,0,0,1);
    std::cout << "index(1,0,0,1) : " << index1001 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1002 = mpc::core::TensorRankNComponentIndex<4>(1,0,0,2);
    std::cout << "index(1,0,0,2) : " << index1002 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1010 = mpc::core::TensorRankNComponentIndex<4>(1,0,1,0);
    std::cout << "index(1,0,1,0) : " << index1010 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1011 = mpc::core::TensorRankNComponentIndex<4>(1,0,1,1);
    std::cout << "index(1,0,1,1) : " << index1011 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1012 = mpc::core::TensorRankNComponentIndex<4>(1,0,1,2);
    std::cout << "index(1,0,1,2) : " << index1012 << std::endl;
    std::cout << "FirstIndex() :   " << index1012.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index1012.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index1012.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index1012.FourthIndex() << std::endl;
    std::cout << index1012 << " index using operator [0] : " << index1012[0] << std::endl;
    std::cout << index1012 << " index using operator [1] : " << index1012[1] << std::endl;
    std::cout << index1012 << " index using operator [2] : " << index1012[2] << std::endl;
    std::cout << index1012 << " index using operator [3] : " << index1012[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1020 = mpc::core::TensorRankNComponentIndex<4>(1,0,2,0);
    std::cout << "index(1,0,2,0) : " << index1020 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1021 = mpc::core::TensorRankNComponentIndex<4>(1,0,2,1);
    std::cout << "index(1,0,2,1) : " << index1021 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1022 = mpc::core::TensorRankNComponentIndex<4>(1,0,2,2);
    std::cout << "index(1,0,2,2) : " << index1022 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1100 = mpc::core::TensorRankNComponentIndex<4>(1,1,0,0);
    std::cout << "index(1,1,0,0) : " << index1100 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1101 = mpc::core::TensorRankNComponentIndex<4>(1,1,0,1);
    std::cout << "index(1,1,0,1) : " << index1101 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1102 = mpc::core::TensorRankNComponentIndex<4>(1,1,0,2);
    std::cout << "index(1,1,0,2) : " << index1102 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1110 = mpc::core::TensorRankNComponentIndex<4>(1,1,1,0);
    std::cout << "index(1,1,1,0) : " << index1110 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1111 = mpc::core::TensorRankNComponentIndex<4>(1,1,1,1);
    std::cout << "index(1,1,1,1) : " << index1111 << std::endl;
    std::cout << "FirstIndex() :   " << index1111.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index1111.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index1111.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index1111.FourthIndex() << std::endl;
    std::cout << index1111 << " index using operator [0] : " << index1111[0] << std::endl;
    std::cout << index1111 << " index using operator [1] : " << index1111[1] << std::endl;
    std::cout << index1111 << " index using operator [2] : " << index1111[2] << std::endl;
    std::cout << index1111 << " index using operator [3] : " << index1111[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1112 = mpc::core::TensorRankNComponentIndex<4>(1,1,1,2);
    std::cout << "index(1,1,1,2) : " << index1112 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1120 = mpc::core::TensorRankNComponentIndex<4>(1,1,2,0);
    std::cout << "index(1,1,2,0) : " << index1120 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1121 = mpc::core::TensorRankNComponentIndex<4>(1,1,2,1);
    std::cout << "index(1,1,2,1) : " << index1121 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1122 = mpc::core::TensorRankNComponentIndex<4>(1,1,2,2);
    std::cout << "index(1,1,2,2) : " << index1122 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1200 = mpc::core::TensorRankNComponentIndex<4>(1,2,0,0);
    std::cout << "index(1,2,0,0) : " << index1200 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1201 = mpc::core::TensorRankNComponentIndex<4>(1,2,0,1);
    std::cout << "index(1,2,0,1) : " << index1201 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1202 = mpc::core::TensorRankNComponentIndex<4>(1,2,0,2);
    std::cout << "index(1,2,0,2) : " << index1202 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1210 = mpc::core::TensorRankNComponentIndex<4>(1,2,1,0);
    std::cout << "index(1,2,1,0) : " << index1210 << std::endl;
    std::cout << "FirstIndex() :   " << index1210.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index1210.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index1210.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index1210.FourthIndex() << std::endl;
    std::cout << index1210 << " index using operator [0] : " << index1210[0] << std::endl;
    std::cout << index1210 << " index using operator [1] : " << index1210[1] << std::endl;
    std::cout << index1210 << " index using operator [2] : " << index1210[2] << std::endl;
    std::cout << index1210 << " index using operator [3] : " << index1210[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1211 = mpc::core::TensorRankNComponentIndex<4>(1,2,1,1);
    std::cout << "index(1,2,1,1) : " << index1211 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1212 = mpc::core::TensorRankNComponentIndex<4>(1,2,1,2);
    std::cout << "index(1,2,1,2) : " << index1212 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1220 = mpc::core::TensorRankNComponentIndex<4>(1,2,2,0);
    std::cout << "index(1,2,2,0) : " << index1220 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1221 = mpc::core::TensorRankNComponentIndex<4>(1,2,2,1);
    std::cout << "index(1,2,2,1) : " << index1221 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index1222 = mpc::core::TensorRankNComponentIndex<4>(1,2,2,2);
    std::cout << "index(1,2,2,2) : " << index1222 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2000 = mpc::core::TensorRankNComponentIndex<4>(2,0,0,0);
    std::cout << "index(2,0,0,0) : " << index2000 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2001 = mpc::core::TensorRankNComponentIndex<4>(2,0,0,1);
    std::cout << "index(2,0,0,1) : " << index2001 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2002 = mpc::core::TensorRankNComponentIndex<4>(2,0,0,2);
    std::cout << "index(2,0,0,2) : " << index2002 << std::endl;
    std::cout << "FirstIndex() :   " << index2002.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index2002.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index2002.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index2002.FourthIndex() << std::endl;
    std::cout << index2002 << " index using operator [0] : " << index2002[0] << std::endl;
    std::cout << index2002 << " index using operator [1] : " << index2002[1] << std::endl;
    std::cout << index2002 << " index using operator [2] : " << index2002[2] << std::endl;
    std::cout << index2002 << " index using operator [3] : " << index2002[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2010 = mpc::core::TensorRankNComponentIndex<4>(2,0,1,0);
    std::cout << "index(2,0,1,0) : " << index2010 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2011 = mpc::core::TensorRankNComponentIndex<4>(2,0,1,1);
    std::cout << "index(2,0,1,1) : " << index2011 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2012 = mpc::core::TensorRankNComponentIndex<4>(2,0,1,2);
    std::cout << "index(2,0,1,2) : " << index2012 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2020 = mpc::core::TensorRankNComponentIndex<4>(2,0,2,0);
    std::cout << "index(2,0,2,0) : " << index2020 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2021 = mpc::core::TensorRankNComponentIndex<4>(2,0,2,1);
    std::cout << "index(2,0,2,1) : " << index2021 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2022 = mpc::core::TensorRankNComponentIndex<4>(2,0,2,2);
    std::cout << "index(2,0,2,2) : " << index2022 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2100 = mpc::core::TensorRankNComponentIndex<4>(2,1,0,0);
    std::cout << "index(2,1,0,0) : " << index2100 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2101 = mpc::core::TensorRankNComponentIndex<4>(2,1,0,1);
    std::cout << "index(2,1,0,1) : " << index2101 << std::endl;
    std::cout << "FirstIndex() :   " << index2101.FirstIndex() << std::endl;
    std::cout << "SecondIndex() :  " << index2101.SecondIndex() << std::endl;
    std::cout << "ThirdIndex() :   " << index2101.ThirdIndex() << std::endl;
    std::cout << "FourthIndex() :  " << index2101.FourthIndex() << std::endl;
    std::cout << index2101 << " index using operator [0] : " << index2101[0] << std::endl;
    std::cout << index2101 << " index using operator [1] : " << index2101[1] << std::endl;
    std::cout << index2101 << " index using operator [2] : " << index2101[2] << std::endl;
    std::cout << index2101 << " index using operator [3] : " << index2101[3] << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2102 = mpc::core::TensorRankNComponentIndex<4>(2,1,0,2);
    std::cout << "index(2,1,0,2) : " << index2102 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2110 = mpc::core::TensorRankNComponentIndex<4>(2,1,1,0);
    std::cout << "index(2,1,1,0) : " << index2110 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2111 = mpc::core::TensorRankNComponentIndex<4>(2,1,1,1);
    std::cout << "index(2,1,1,1) : " << index2111 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2112 = mpc::core::TensorRankNComponentIndex<4>(2,1,1,2);
    std::cout << "index(2,1,1,2) : " << index2112 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2120 = mpc::core::TensorRankNComponentIndex<4>(2,1,2,0);
    std::cout << "index(2,1,2,0) : " << index2120 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2121 = mpc::core::TensorRankNComponentIndex<4>(2,1,2,1);
    std::cout << "index(2,1,2,1) : " << index2121 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2122 = mpc::core::TensorRankNComponentIndex<4>(2,1,2,2);
    std::cout << "index(2,1,2,2) : " << index2122 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2200 = mpc::core::TensorRankNComponentIndex<4>(2,2,0,0);
    std::cout << "index(2,2,0,0) : " << index2200 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2201 = mpc::core::TensorRankNComponentIndex<4>(2,2,0,1);
    std::cout << "index(2,2,0,1) : " << index2201 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2202 = mpc::core::TensorRankNComponentIndex<4>(2,2,0,2);
    std::cout << "index(2,2,0,2) : " << index2202 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2210 = mpc::core::TensorRankNComponentIndex<4>(2,2,1,0);
    std::cout << "index(2,2,1,0) : " << index2210 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2211 = mpc::core::TensorRankNComponentIndex<4>(2,2,1,1);
    std::cout << "index(2,2,1,1) : " << index2211 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2212 = mpc::core::TensorRankNComponentIndex<4>(2,2,1,2);
    std::cout << "index(2,2,1,2) : " << index2212 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2220 = mpc::core::TensorRankNComponentIndex<4>(2,2,2,0);
    std::cout << "index(2,2,2,0) : " << index2220 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2221 = mpc::core::TensorRankNComponentIndex<4>(2,2,2,1);
    std::cout << "index(2,2,2,1) : " << index2221 << std::endl;
    mpc::core::TensorRankNComponentIndex<4> index2222 = mpc::core::TensorRankNComponentIndex<4>(2,2,2,2);
    std::cout << "index(2,2,2,2) : " << index2222 << std::endl;

    std::vector<mpc::core::TensorRank4ComponentIndex> vec_indexXXXX{
            index0000, index0001, index0002,
            index0010, index0011, index0012,
            index0020, index0021, index0022,
            index0100, index0101, index0102,
            index0110, index0111, index0112,
            index0120, index0121, index0122,
            index0200, index0201, index0202,
            index0210, index0211, index0212,
            index0220, index0221, index0222,
            index1000, index1001, index1002,
            index1010, index1011, index1012,
            index1020, index1021, index1022,
            index1100, index1101, index1102,
            index1110, index1111, index1112,
            index1120, index1121, index1122,
            index1200, index1201, index1202,
            index1210, index1211, index1212,
            index1220, index1221, index1222,
            index2000, index2001, index2002,
            index2010, index2011, index2012,
            index2020, index2021, index2022,
            index2100, index2101, index2102,
            index2110, index2111, index2112,
            index2120, index2121, index2122,
            index2200, index2201, index2202,
            index2210, index2211, index2212,
            index2220, index2221, index2222
    };

    /*
    * operators for fourth rank tensor indices...
    */
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    for (auto indexXXXX : vec_indexXXXX) {
        std::cout << indexXXXX << " == " << index1111 << " : " << (indexXXXX == index1111) << std::endl;
        std::cout << indexXXXX << " != " << index1111 << " : " << (indexXXXX != index1111) << std::endl;
        std::cout << indexXXXX << " <  " << index1111 << " : " << (indexXXXX < index1111) << std::endl;
        std::cout << indexXXXX << " >  " << index1111 << " : " << (indexXXXX > index1111) << std::endl;
        std::cout << indexXXXX << " <= " << index1111 << " : " << (indexXXXX <= index1111) << std::endl;
        std::cout << indexXXXX << " >= " << index1111 << " : " << (indexXXXX >= index1111) << std::endl;
    }

    /*
     * MPC provides an alias for the fourth rank tensor component index with
     *     the using directive:
     *
     *     using TensorRank4ComponentIndex = TensorRankNComponentIndex<4>;
     */

    // for later use, create the component indexes
    mpc::core::TensorRank4ComponentIndex index0022usingalias = mpc::core::TensorRank4ComponentIndex(0,0,2,2);
    std::cout << "index(0,0,2,2) : " << index0022usingalias << std::endl;

    /*
         * Since the underlying data structure for mpc is blitz, it is often
         *     convenient to insert a value into the tensor member variable using
         *     blitz::TinyVector<> to refer to the index from the
         *     mpc::core::TensorRankNComponent<>.  MPC provides convenience
         *     functions for this...
         */

    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    blitz::TinyVector<int,4> blitz_indexXXXX = blitz::TinyVector<int,4>(0,0,0,0);
    for (auto indexXXXX : vec_indexXXXX) {
        blitz_indexXXXX = mpc::core::TensorRankNComponentIndex<4>::ToBlitzTinyVector(indexXXXX);
        std::cout << "TinyVector blitz_index " << indexXXXX << " : " << blitz_indexXXXX << std::endl;
    }

    /*
         * Let's combine them in a
         *     std::set<> which itself is powerful tool and has some interesting
         *     properties and algorithms.  The next section illustrates useful
         *     functions that take advantage of these properties and algorithms.
         *     Why use std::set<> and not std::vector<>?  A set will automatically
         *     check if the value being inserted is already present.  We want all
         *     components in a set to be unique becauase they map to one and only
         *     one component in the actual tensor...
         *
         * Some useful algorithms in the STL library for std::set<> are:
         *     >> includes()
         *     >> set_union()
         *     >> set_intersection()
         *     >> set_difference()
         *     >> set_symmetrical_difference()
         *         (see Stroustrup, 2013, The C++ Programming Language, fourth ed.,  p. 947)
         *
         * Note that the values in a set are ordered. Set tests for equality
         *     with another element already in the set using std::less<Key>.  An
         *     index has no natrual order, but MPC defines it like this
         *
         *         ...for 4th rank tensor component indices:
         *
         *         0000 < 0001 < 0002 < 0010 < 0011 < ... < 2220 < 2221 < 2222
         *
         *     Containers of TensorRankNComponentIndex<N> can now be sorted or
         *         stored in ordered containers like std::set<>.
         */



    /*
     * For fourth rank tensors, symmetry is a bit more complicated.  We must define
     *     what we mean by symmetrical.
     *
     *     (triclinic symmetry; all other symmmetries are considered
     *         specializations of triclinic)
     *
     * c(i,j,k,l) = c(j,i,k,l) = c(i,j,l,k) = c(l,k,i,j)
     *
     * X11 >> (1111)
     * X12 >> (1122), (2211)
     * X13 >> (1133), (3311)
     * X14 >> (1123), (1132), (2311), (3211)
     * X15 >> (1113), (1131), (1311), (3111)
     * X16 >> (1112), (1121), (1211), (2111)
     * X22 >> (2222)
     * X23 >> (2233), (3322)
     * X24 >> (2223), (2232), (2322), (3222)
     * X25 >> (2213), (2231), (1322), (3122)
     * X26 >> (2212), (2221), (1222), (2122)
     * X33 >> (3333)
     * X34 >> (3323), (3332), (2333), (3233)
     * X35 >> (3313), (3331), (1333), (3133)
     * X36 >> (3312), (3321), (1233), (2133)
     * X44 >> (2323), (2332), (3223), (3232)
     * X45 >> (2313), (2331), (3213), (3231), (1323), (3123), (1332), (3132)
     * X46 >> (2312), (2321), (3212), (3221), (1223), (2123), (1232), (2132)
     * X55 >> (1313), (1331), (3113), (3131)
     * X56 >> (1312), (1321), (3112), (3121), (1213), (2113), (1231), (2131)
     * X66 >> (1212), (1221), (2112), (2121)
     *
     * //// NOTE that the above is in one-based index notation to match the
     *         literature.  MPC uses zero-based indexing for the rest of us
     *         who aren't exclusively MATLAB and/or fortran programmers:
     *
     * X00 >> (0000)
     * X01 >> (0011), (1100)
     * X02 >> (0022), (2200)
     * X03 >> (0012), (0021), (1200), (2100)
     * X04 >> (0002), (0020), (0200), (2000)
     * X05 >> (0001), (0010), (0100), (1000)
     * X11 >> (1111)
     * X12 >> (1122), (2211)
     * X13 >> (1112), (1121), (1211), (2111)
     * X14 >> (1102), (1120), (0211), (2011)
     * X15 >> (1101), (1110), (0111), (1011)
     * X22 >> (2222)
     * X23 >> (2212), (2221), (1222), (2122)
     * X24 >> (2202), (2220), (0222), (2022)
     * X25 >> (2201), (2210), (0122), (1022)
     * X33 >> (1212), (1221), (2112), (2121)
     * X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
     * X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
     * X44 >> (0202), (0220), (2002), (2020)
     * X45 >> (0201), (0210), (2001), (2010), (0102), (1002), (0120), (1020)
     * X55 >> (0101), (0110), (1001), (1010)
     *
     * A more detailed discussion of symmetry as it pertains to the mechanical
     *     properties of crystals, specifically elasticity, is postponed until
     *     later.  I assume the user has some knowledge of this concept as it
     *     is fundamental to any research in solid mechanics.  An entire section
     *     is devoted to this subject as it pertains to MPC, i.e., how MPC uses
     *     these properties and encapsulates them in their own classes...
     */


/*
 * When working only a set of components, it is sometimes easiest to work with the "reduced" indices...
 *
 * A "reduced" index depends on its symmetry.  The idea is extract the least index from a set of indices
 *     that should be equal or equal and opposite in sign.  These sets are referred to as groupings in MPC.
 *     IMPORTANT!!!  Indices that should be zero valued according to the symmetry rules are NOT reduced...
 *
 *
 * NOTE: reduced indices have values that either equal or equal and opposite in sign;  indices whose values are
 *           derived from 2 (or more) other indices are left alone and reduced according to triclinic symmetry rules.
 */

    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    mpc::core::TensorRank4ComponentIndex indexXXXX_reduced = mpc::core::TensorRank4ComponentIndex(index0000);
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex(indexXXXX);
        std::cout << indexXXXX << " reduced : " << indexXXXX_reduced << std::endl;
    }

    int p, q; // used to hold temporary values of the voigt indices
    std::cout << "" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        p = mpc::utilities::GetVoigtMatrixIndex(indexXXXX.FirstIndex(), indexXXXX.SecondIndex());
        q = mpc::utilities::GetVoigtMatrixIndex(indexXXXX.ThirdIndex(), indexXXXX.FourthIndex());
        //
        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " triclinic symmetry reduced : " << indexXXXX_reduced << std::endl;
        // polymorphic
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
        std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " monoclinicx2 symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " monoclinicx3 symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " orthorhombic symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }


        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " hexagonal symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " tetragonal7 symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " tetragonal6 symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " trigonal7 symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " trigonal6 symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " cubic symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }

        std::cout << "" << std::endl;
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " isotropic symmetry reduced : " << indexXXXX_reduced << std::endl;
        // TODO: illustrate zero values...
        indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
//     std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;
//     if( indexXXXX_reduced != mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(indexXXXX) ) {
//         std::cout << "   !!!   " << indexXXXX << " should have value zero !!! " << std::endl;
//     }
    }

// NOTE: the "should have value zero, does NOT always work.  If the (p,q) voigt index produces a tensor component index that is already a minimum value, it will not be flagged as "should have zero value...  TODO: predicate IndexShouldHaveZeroValue<S>(indexn)...

    /* script to determine number of aliases...  TODO: code in by hand */
    // use a counter to count the number of non-unique values
    std::cout << std::boolalpha;
    std::cout << "" << std::endl;
    //mpc::core::TensorRank4ComponentIndex indexXXXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    //int p, q; // used to hold temporary values of the voigt indices

    int alias_counter = 0;
    mpc::core::TensorRank4ComponentIndex indexXXXX_test = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    std::set<mpc::core::TensorRank4ComponentIndex> reduced_set{};



    std::cout << "\n=== none aliases a.k.a. reduced set" << std::endl;
    // none
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::NoneSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::NoneSymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << std::endl;
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::NoneSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== triclinic aliases a.k.a. reduced set" << std::endl;
    // triclinic
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    // just a check...
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== monoclinicx2 aliases a.k.a. reduced set" << std::endl;
    // monoclinicx2
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== monoclinicx3 aliases a.k.a. reduced set" << std::endl;
    // monoclinicx3
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== orthorhombic aliases a.k.a. reduced set" << std::endl;
    // orthorhombic
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter
                              << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))<< std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== hexagonal aliases a.k.a. reduced set" << std::endl;
    // hexagonal
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== tetragonal7 aliases a.k.a. reduced set" << std::endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== tetragonal6 aliases a.k.a. reduced set" << std::endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== trigonal7 aliases a.k.a. reduced set" << std::endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== trigonal6 aliases a.k.a. reduced set" << std::endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== cubic aliases a.k.a. reduced set" << std::endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== isotropic aliases a.k.a. reduced set" << std::endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    alias_counter = 0;
                    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto indexXXXX : vec_indexXXXX) {
                        indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(indexXXXX);
                        if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                    }
                    std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                    if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                        std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                    }
                    // print the matrix notation
                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                    if (p<q) {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                    } else {
                        std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                    }
                    reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                    for (auto ss : reduced_set) {
                        std::cout << "    " << ss << std::endl;
                    }
                }
            }
        }
    }

    /*
    * predicates for tensor rank4 index
    *
    * Currently, MPC provides two predicates (callable that returns a value
    *     testable as a bool; see
    *     https://en.cppreference.com/w/cpp/named_req/Predicate) for
    *     TensorRankNCompoentIndex<> where N is either 2 or 4: ...IsAlias(...)
    *     and ...HasAlias(...).  The definiton of aliases is defined by
    *     symmetry...
    */

    std::cout << std::boolalpha;
    std::cout << "" << std::endl;

    bool indexXXXX_predicate;
    mpc::core::TensorRank4ComponentIndex index_test = index0000;

    std::cout << "\n=== none symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::NoneSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::NoneSymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== triclinic symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::TriclinicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::TriclinicSymmetryGroupType>(indexXXXX, index_test);
                        std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== monoclinicx2 symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== monoclinicx3 symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== orthorhombic symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }


    std::cout << "\n=== hexagonal symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::HexagonalSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::HexagonalSymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== tetragonal7 symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== tetragonal6 symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== trigonal7 symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== trigonal6 symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== cubic symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::CubicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::CubicSymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "\n=== isotropic symmetry group type predicates" << std::endl;
    for (auto indexXXXX : vec_indexXXXX) {
        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::IsotropicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l) {
                        index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                        indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::IsotropicSymmetryGroupType>(indexXXXX, index_test);
                        //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                    }
                }
            }
        }
    }

    /*
    * Now for the fun stuff!  MPC relies heavily on template specializations
    *     and uses compile-time computations to achieve optimization and (in
    *     my opinion equally important) error handling using the c++ type
    *     system...
    * The preferred method for creating component indexes is to use the
    *     templated form prefixed by the letter C; the major difference is
    *     that the member functions that retieve the index values CAN be used
    *     as template parameter values and therefore can be used for
    *     compile-time computation or compile-time optimization via selection
    *     in the form of user-defined specialization...
    */

    /*
     * compile-time template functions and convenience functions for matrix
     *     notation...  Note that these are defined in tensorcomponentindex and
     *     NOT matrix notation because matrix notation is already included in
     *     the tensorcomponentindex.h file and putting in matrixnotation.h would
     *     have both headers including each other.  This is bad...
     */
    // std::cout << "" << std::endl;
    // int cvoigt_index00 = mpc::core::CGetVoigtMatrixIndex<0,0>();
    // std::cout << "cvoigt index00 : " << cvoigt_index00 << std::endl;
    // int cvoigt_index01 = mpc::core::CGetVoigtMatrixIndex<0,1>();
    // std::cout << "cvoigt index01 : " << cvoigt_index01 << std::endl;
    // int cvoigt_index02 = mpc::core::CGetVoigtMatrixIndex<0,2>();
    // std::cout << "cvoigt index02 : " << cvoigt_index02 << std::endl;
    // int cvoigt_index10 = mpc::core::CGetVoigtMatrixIndex<1,0>();
    // std::cout << "cvoigt index10 : " << cvoigt_index10 << std::endl;
    // int cvoigt_index11 = mpc::core::CGetVoigtMatrixIndex<1,1>();
    // std::cout << "cvoigt index11 : " << cvoigt_index11 << std::endl;
    // int cvoigt_index12 = mpc::core::CGetVoigtMatrixIndex<1,2>();
    // std::cout << "cvoigt index12 : " << cvoigt_index12 << std::endl;
    // int cvoigt_index20 = mpc::core::CGetVoigtMatrixIndex<2,0>();
    // std::cout << "cvoigt index20 : " << cvoigt_index20 << std::endl;
    // int cvoigt_index21 = mpc::core::CGetVoigtMatrixIndex<2,1>();
    // std::cout << "cvoigt index21 : " << cvoigt_index21 << std::endl;
    // int cvoigt_index22 = mpc::core::CGetVoigtMatrixIndex<2,2>();
    // std::cout << "cvoigt index22 : " << cvoigt_index22 << std::endl;
    //
    //     // as template parameter values
    // std::cout << "" << std::endl;
    // auto ctest_cvoigt_index00 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<0,0>()>();
    // std::cout << "ctest_cvoigt_index 0,0 : " << ctest_cvoigt_index00 << std::endl;
    // auto ctest_cvoigt_index01 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<0,1>()>();
    // std::cout << "ctest_cvoigt_index 0,1 : " << ctest_cvoigt_index01 << std::endl;
    // auto ctest_cvoigt_index02 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<0,2>()>();
    // std::cout << "ctest_cvoigt_index 0,2 : " << ctest_cvoigt_index02 << std::endl;
    // auto ctest_cvoigt_index10 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<1,0>()>();
    // std::cout << "ctest_cvoigt_index 1,0 : " << ctest_cvoigt_index10 << std::endl;
    // auto ctest_cvoigt_index11 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<1,1>()>();
    // std::cout << "ctest_cvoigt_index 1,1 : " << ctest_cvoigt_index11 << std::endl;
    // auto ctest_cvoigt_index12 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<1,2>()>();
    // std::cout << "ctest_cvoigt_index 1,2 : " << ctest_cvoigt_index12 << std::endl;
    // auto ctest_cvoigt_index20 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<2,0>()>();
    // std::cout << "ctest_cvoigt_index 2,0 : " << ctest_cvoigt_index20 << std::endl;
    // auto ctest_cvoigt_index21 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<2,1>()>();
    // std::cout << "ctest_cvoigt_index 2,1 : " << ctest_cvoigt_index21 << std::endl;
    // auto ctest_cvoigt_index22 = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetVoigtMatrixIndex<2,2>()>();
    // std::cout << "ctest_cvoigt_index 2,2 : " << ctest_cvoigt_index22 << std::endl;
    //

    /*
    * tensor from matrix notation at compile-time;
    * ignore the naming, for the examples I know what the tensor index should
    *     be and used that in the naming.  For example, matrix notation index 3
    *     (zero-based) should return the tensor index (1,2).  The non C*
    *     version returns this as an std::pair<>, however, the std::pair<>
    *     structure cannot be used as a template parameter value and thus the
    *     decision was made to break it up into two functions returning int's
    *     which could be used in template parameter values...
    *
    * For example, an overly verbose constructor for a rank4 component index could like:
    *     auto t = CTensorRank4ComponentIndex<
    *                  CGetFirstIndexFromVoigtMatrix<4>(),
    *                  CGetSecondIndexFromVoigtMatrix<4>(),
    *                  CGetFirstIndexFromVoigtMatrix<5>(),
    *                  CGetSecondIndexFromVoigtMatrix<5>()>();
    *
    *     for the index in matrix notation [4,5] to tensor notation (0,2,0,1).
    *     The template parameters I,J,K,L "map" to 0,2,0,1 respectively and are
    *     known to the compiler at compile time and used elsewhere for
    *     compile-time computations.
    */

    //std::cout << "" << std::endl;
    // int cvoigt_index00_first_index = mpc::core::CGetFirstIndexFromVoigtMatrix<0>();
    // auto ctest_cvoigt_index00_first_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetFirstIndexFromVoigtMatrix<0>()>();
    // std::cout << "ctest_cvoigt_index00_first_index : " << ctest_cvoigt_index00_first_index << std::endl;
    // int cvoigt_index00_second_index = mpc::core::CGetSecondIndexFromVoigtMatrix<0>();
    // auto ctest_cvoigt_index00_second_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetSecondIndexFromVoigtMatrix<0>()>();
    // std::cout << "ctest_cvoigt_index00_second_index : " << ctest_cvoigt_index00_second_index << std::endl;

    // int cvoigt_index11_first_index = mpc::core::CGetFirstIndexFromVoigtMatrix<1>();
    // auto ctest_cvoigt_index11_first_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetFirstIndexFromVoigtMatrix<1>()>();
    // std::cout << "ctest_cvoigt_index11_first_index : " << ctest_cvoigt_index11_first_index << std::endl;
    // int cvoigt_index11_second_index = mpc::core::CGetSecondIndexFromVoigtMatrix<1>();
    // auto ctest_cvoigt_index11_second_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetSecondIndexFromVoigtMatrix<1>()>();
    // std::cout << "ctest_cvoigt_index11_second_index : " << ctest_cvoigt_index11_second_index << std::endl;

    // int cvoigt_index22_first_index = mpc::core::CGetFirstIndexFromVoigtMatrix<2>();
    // auto ctest_cvoigt_index22_first_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetFirstIndexFromVoigtMatrix<2>()>();
    // std::cout << "ctest_cvoigt_index22_first_index : " << ctest_cvoigt_index22_first_index << std::endl;
    // int cvoigt_index22_second_index = mpc::core::CGetSecondIndexFromVoigtMatrix<2>();
    // auto ctest_cvoigt_index22_second_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetSecondIndexFromVoigtMatrix<2>()>();
    // std::cout << "ctest_cvoigt_index22_second_index : " << ctest_cvoigt_index22_second_index << std::endl;

    // int cvoigt_index12_first_index = mpc::core::CGetFirstIndexFromVoigtMatrix<3>();
    // auto ctest_cvoigt_index12_first_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetFirstIndexFromVoigtMatrix<3>()>();
    // std::cout << "ctest_cvoigt_index12_first_index : " << ctest_cvoigt_index12_first_index << std::endl;
    // int cvoigt_index12_second_index = mpc::core::CGetSecondIndexFromVoigtMatrix<3>();
    // auto ctest_cvoigt_index12_second_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetSecondIndexFromVoigtMatrix<3>()>();
    // std::cout << "ctest_cvoigt_index12_second_index : " << ctest_cvoigt_index12_second_index << std::endl;

    // int cvoigt_index02_first_index = mpc::core::CGetFirstIndexFromVoigtMatrix<4>();
    // auto ctest_cvoigt_index02_first_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetFirstIndexFromVoigtMatrix<4>()>();
    // std::cout << "ctest_cvoigt_index02_first_index : " << ctest_cvoigt_index02_first_index << std::endl;
    // int cvoigt_index02_second_index = mpc::core::CGetSecondIndexFromVoigtMatrix<4>();
    // auto ctest_cvoigt_index02_second_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetSecondIndexFromVoigtMatrix<4>()>();
    // std::cout << "ctest_cvoigt_index02_second_index : " << ctest_cvoigt_index02_second_index << std::endl;

    // int cvoigt_index01_first_index = mpc::core::CGetFirstIndexFromVoigtMatrix<5>();
    // auto ctest_cvoigt_index01_first_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetFirstIndexFromVoigtMatrix<5>()>();
    // std::cout << "ctest_cvoigt_index01_first_index : " << ctest_cvoigt_index01_first_index << std::endl;
    // int cvoigt_index01_second_index = mpc::core::CGetSecondIndexFromVoigtMatrix<5>();
    // auto ctest_cvoigt_index01_second_index = mpcuserguide::IntTypeParameterValueTest<mpc::core::CGetSecondIndexFromVoigtMatrix<5>()>();
    // std::cout << "ctest_cvoigt_index01_second_index : " << ctest_cvoigt_index01_second_index << std::endl;

    /*
    * Where compile-time computation is not needed and "plain"
    *     TensorRank2ComponentIndex or TensorRank4ComponentIndex will suffice,
    *     a static_cast<T> can be used to cast the CTensorRank2ComponentIndex
    *     or CTensorRank4ComponentIndex to a plain
    *     TensorRankNComponentIndex<N>.  For example ...
    */

    std::cout << "" << std::endl;
    mpc::core::TensorRank4ComponentIndex index0000cast = static_cast<mpc::core::TensorRank4ComponentIndex>(mpc::core::CTensorRank4ComponentIndex<0,0,0,0>());
    std::cout << "index0000cast : " << index0000cast << std::endl;

    /*
         * indices for 4th rank tensors in 3-dimensional Cartesian space using the CTensorRank4ComponentIndex
         */
    std::cout << "" << std::endl;
    mpc::core::CTensorRank4ComponentIndex<0,0,0,0> cindex0000 = mpc::core::CTensorRank4ComponentIndex<0,0,0,0>();
    mpc::core::CTensorRank4ComponentIndex<0,0,0,1> cindex0001 = mpc::core::CTensorRank4ComponentIndex<0,0,0,1>();
    mpc::core::CTensorRank4ComponentIndex<0,0,0,2> cindex0002 = mpc::core::CTensorRank4ComponentIndex<0,0,0,2>();
    mpc::core::CTensorRank4ComponentIndex<0,0,1,0> cindex0010 = mpc::core::CTensorRank4ComponentIndex<0,0,1,0>();
    mpc::core::CTensorRank4ComponentIndex<0,0,1,1> cindex0011 = mpc::core::CTensorRank4ComponentIndex<0,0,1,1>();
    mpc::core::CTensorRank4ComponentIndex<0,0,1,2> cindex0012 = mpc::core::CTensorRank4ComponentIndex<0,0,1,2>();
    mpc::core::CTensorRank4ComponentIndex<0,0,2,0> cindex0020 = mpc::core::CTensorRank4ComponentIndex<0,0,2,0>();
    mpc::core::CTensorRank4ComponentIndex<0,0,2,1> cindex0021 = mpc::core::CTensorRank4ComponentIndex<0,0,2,1>();
    mpc::core::CTensorRank4ComponentIndex<0,0,2,2> cindex0022 = mpc::core::CTensorRank4ComponentIndex<0,0,2,2>();
    mpc::core::CTensorRank4ComponentIndex<0,1,0,0> cindex0100 = mpc::core::CTensorRank4ComponentIndex<0,1,0,0>();
    mpc::core::CTensorRank4ComponentIndex<0,1,0,1> cindex0101 = mpc::core::CTensorRank4ComponentIndex<0,1,0,1>();
    mpc::core::CTensorRank4ComponentIndex<0,1,0,2> cindex0102 = mpc::core::CTensorRank4ComponentIndex<0,1,0,2>();
    mpc::core::CTensorRank4ComponentIndex<0,1,1,0> cindex0110 = mpc::core::CTensorRank4ComponentIndex<0,1,1,0>();
    mpc::core::CTensorRank4ComponentIndex<0,1,1,1> cindex0111 = mpc::core::CTensorRank4ComponentIndex<0,1,1,1>();
    mpc::core::CTensorRank4ComponentIndex<0,1,1,2> cindex0112 = mpc::core::CTensorRank4ComponentIndex<0,1,1,2>();
    mpc::core::CTensorRank4ComponentIndex<0,1,2,0> cindex0120 = mpc::core::CTensorRank4ComponentIndex<0,1,2,0>();
    mpc::core::CTensorRank4ComponentIndex<0,1,2,1> cindex0121 = mpc::core::CTensorRank4ComponentIndex<0,1,2,1>();
    mpc::core::CTensorRank4ComponentIndex<0,1,2,2> cindex0122 = mpc::core::CTensorRank4ComponentIndex<0,1,2,2>();
    mpc::core::CTensorRank4ComponentIndex<0,2,0,0> cindex0200 = mpc::core::CTensorRank4ComponentIndex<0,2,0,0>();
    mpc::core::CTensorRank4ComponentIndex<0,2,0,1> cindex0201 = mpc::core::CTensorRank4ComponentIndex<0,2,0,1>();
    mpc::core::CTensorRank4ComponentIndex<0,2,0,2> cindex0202 = mpc::core::CTensorRank4ComponentIndex<0,2,0,2>();
    mpc::core::CTensorRank4ComponentIndex<0,2,1,0> cindex0210 = mpc::core::CTensorRank4ComponentIndex<0,2,1,0>();
    mpc::core::CTensorRank4ComponentIndex<0,2,1,1> cindex0211 = mpc::core::CTensorRank4ComponentIndex<0,2,1,1>();
    mpc::core::CTensorRank4ComponentIndex<0,2,1,2> cindex0212 = mpc::core::CTensorRank4ComponentIndex<0,2,1,2>();
    mpc::core::CTensorRank4ComponentIndex<0,2,2,0> cindex0220 = mpc::core::CTensorRank4ComponentIndex<0,2,2,0>();
    mpc::core::CTensorRank4ComponentIndex<0,2,2,1> cindex0221 = mpc::core::CTensorRank4ComponentIndex<0,2,2,1>();
    mpc::core::CTensorRank4ComponentIndex<0,2,2,2> cindex0222 = mpc::core::CTensorRank4ComponentIndex<0,2,2,2>();
    mpc::core::CTensorRank4ComponentIndex<1,0,0,0> cindex1000 = mpc::core::CTensorRank4ComponentIndex<1,0,0,0>();
    mpc::core::CTensorRank4ComponentIndex<1,0,0,1> cindex1001 = mpc::core::CTensorRank4ComponentIndex<1,0,0,1>();
    mpc::core::CTensorRank4ComponentIndex<1,0,0,2> cindex1002 = mpc::core::CTensorRank4ComponentIndex<1,0,0,2>();
    mpc::core::CTensorRank4ComponentIndex<1,0,1,0> cindex1010 = mpc::core::CTensorRank4ComponentIndex<1,0,1,0>();
    mpc::core::CTensorRank4ComponentIndex<1,0,1,1> cindex1011 = mpc::core::CTensorRank4ComponentIndex<1,0,1,1>();
    mpc::core::CTensorRank4ComponentIndex<1,0,1,2> cindex1012 = mpc::core::CTensorRank4ComponentIndex<1,0,1,2>();
    mpc::core::CTensorRank4ComponentIndex<1,0,2,0> cindex1020 = mpc::core::CTensorRank4ComponentIndex<1,0,2,0>();
    mpc::core::CTensorRank4ComponentIndex<1,0,2,1> cindex1021 = mpc::core::CTensorRank4ComponentIndex<1,0,2,1>();
    mpc::core::CTensorRank4ComponentIndex<1,0,2,2> cindex1022 = mpc::core::CTensorRank4ComponentIndex<1,0,2,2>();
    mpc::core::CTensorRank4ComponentIndex<1,1,0,0> cindex1100 = mpc::core::CTensorRank4ComponentIndex<1,1,0,0>();
    mpc::core::CTensorRank4ComponentIndex<1,1,0,1> cindex1101 = mpc::core::CTensorRank4ComponentIndex<1,1,0,1>();
    mpc::core::CTensorRank4ComponentIndex<1,1,0,2> cindex1102 = mpc::core::CTensorRank4ComponentIndex<1,1,0,2>();
    mpc::core::CTensorRank4ComponentIndex<1,1,1,0> cindex1110 = mpc::core::CTensorRank4ComponentIndex<1,1,1,0>();
    mpc::core::CTensorRank4ComponentIndex<1,1,1,1> cindex1111 = mpc::core::CTensorRank4ComponentIndex<1,1,1,1>();
    mpc::core::CTensorRank4ComponentIndex<1,1,1,2> cindex1112 = mpc::core::CTensorRank4ComponentIndex<1,1,1,2>();
    mpc::core::CTensorRank4ComponentIndex<1,1,2,0> cindex1120 = mpc::core::CTensorRank4ComponentIndex<1,1,2,0>();
    mpc::core::CTensorRank4ComponentIndex<1,1,2,1> cindex1121 = mpc::core::CTensorRank4ComponentIndex<1,1,2,1>();
    mpc::core::CTensorRank4ComponentIndex<1,1,2,2> cindex1122 = mpc::core::CTensorRank4ComponentIndex<1,1,2,2>();
    mpc::core::CTensorRank4ComponentIndex<1,2,0,0> cindex1200 = mpc::core::CTensorRank4ComponentIndex<1,2,0,0>();
    mpc::core::CTensorRank4ComponentIndex<1,2,0,1> cindex1201 = mpc::core::CTensorRank4ComponentIndex<1,2,0,1>();
    mpc::core::CTensorRank4ComponentIndex<1,2,0,2> cindex1202 = mpc::core::CTensorRank4ComponentIndex<1,2,0,2>();
    mpc::core::CTensorRank4ComponentIndex<1,2,1,0> cindex1210 = mpc::core::CTensorRank4ComponentIndex<1,2,1,0>();
    mpc::core::CTensorRank4ComponentIndex<1,2,1,1> cindex1211 = mpc::core::CTensorRank4ComponentIndex<1,2,1,1>();
    mpc::core::CTensorRank4ComponentIndex<1,2,1,2> cindex1212 = mpc::core::CTensorRank4ComponentIndex<1,2,1,2>();
    mpc::core::CTensorRank4ComponentIndex<1,2,2,0> cindex1220 = mpc::core::CTensorRank4ComponentIndex<1,2,2,0>();
    mpc::core::CTensorRank4ComponentIndex<1,2,2,1> cindex1221 = mpc::core::CTensorRank4ComponentIndex<1,2,2,1>();
    mpc::core::CTensorRank4ComponentIndex<1,2,2,2> cindex1222 = mpc::core::CTensorRank4ComponentIndex<1,2,2,2>();
    mpc::core::CTensorRank4ComponentIndex<2,0,0,0> cindex2000 = mpc::core::CTensorRank4ComponentIndex<2,0,0,0>();
    mpc::core::CTensorRank4ComponentIndex<2,0,0,1> cindex2001 = mpc::core::CTensorRank4ComponentIndex<2,0,0,1>();
    mpc::core::CTensorRank4ComponentIndex<2,0,0,2> cindex2002 = mpc::core::CTensorRank4ComponentIndex<2,0,0,2>();
    mpc::core::CTensorRank4ComponentIndex<2,0,1,0> cindex2010 = mpc::core::CTensorRank4ComponentIndex<2,0,1,0>();
    mpc::core::CTensorRank4ComponentIndex<2,0,1,1> cindex2011 = mpc::core::CTensorRank4ComponentIndex<2,0,1,1>();
    mpc::core::CTensorRank4ComponentIndex<2,0,1,2> cindex2012 = mpc::core::CTensorRank4ComponentIndex<2,0,1,2>();
    mpc::core::CTensorRank4ComponentIndex<2,0,2,0> cindex2020 = mpc::core::CTensorRank4ComponentIndex<2,0,2,0>();
    mpc::core::CTensorRank4ComponentIndex<2,0,2,1> cindex2021 = mpc::core::CTensorRank4ComponentIndex<2,0,2,1>();
    mpc::core::CTensorRank4ComponentIndex<2,0,2,2> cindex2022 = mpc::core::CTensorRank4ComponentIndex<2,0,2,2>();
    mpc::core::CTensorRank4ComponentIndex<2,1,0,0> cindex2100 = mpc::core::CTensorRank4ComponentIndex<2,1,0,0>();
    mpc::core::CTensorRank4ComponentIndex<2,1,0,1> cindex2101 = mpc::core::CTensorRank4ComponentIndex<2,1,0,1>();
    mpc::core::CTensorRank4ComponentIndex<2,1,0,2> cindex2102 = mpc::core::CTensorRank4ComponentIndex<2,1,0,2>();
    mpc::core::CTensorRank4ComponentIndex<2,1,1,0> cindex2110 = mpc::core::CTensorRank4ComponentIndex<2,1,1,0>();
    mpc::core::CTensorRank4ComponentIndex<2,1,1,1> cindex2111 = mpc::core::CTensorRank4ComponentIndex<2,1,1,1>();
    mpc::core::CTensorRank4ComponentIndex<2,1,1,2> cindex2112 = mpc::core::CTensorRank4ComponentIndex<2,1,1,2>();
    mpc::core::CTensorRank4ComponentIndex<2,1,2,0> cindex2120 = mpc::core::CTensorRank4ComponentIndex<2,1,2,0>();
    mpc::core::CTensorRank4ComponentIndex<2,1,2,1> cindex2121 = mpc::core::CTensorRank4ComponentIndex<2,1,2,1>();
    mpc::core::CTensorRank4ComponentIndex<2,1,2,2> cindex2122 = mpc::core::CTensorRank4ComponentIndex<2,1,2,2>();
    mpc::core::CTensorRank4ComponentIndex<2,2,0,0> cindex2200 = mpc::core::CTensorRank4ComponentIndex<2,2,0,0>();
    mpc::core::CTensorRank4ComponentIndex<2,2,0,1> cindex2201 = mpc::core::CTensorRank4ComponentIndex<2,2,0,1>();
    mpc::core::CTensorRank4ComponentIndex<2,2,0,2> cindex2202 = mpc::core::CTensorRank4ComponentIndex<2,2,0,2>();
    mpc::core::CTensorRank4ComponentIndex<2,2,1,0> cindex2210 = mpc::core::CTensorRank4ComponentIndex<2,2,1,0>();
    mpc::core::CTensorRank4ComponentIndex<2,2,1,1> cindex2211 = mpc::core::CTensorRank4ComponentIndex<2,2,1,1>();
    mpc::core::CTensorRank4ComponentIndex<2,2,1,2> cindex2212 = mpc::core::CTensorRank4ComponentIndex<2,2,1,2>();
    mpc::core::CTensorRank4ComponentIndex<2,2,2,0> cindex2220 = mpc::core::CTensorRank4ComponentIndex<2,2,2,0>();
    mpc::core::CTensorRank4ComponentIndex<2,2,2,1> cindex2221 = mpc::core::CTensorRank4ComponentIndex<2,2,2,1>();
    mpc::core::CTensorRank4ComponentIndex<2,2,2,2> cindex2222 = mpc::core::CTensorRank4ComponentIndex<2,2,2,2>();

    /*
         * Wrapping up tensorcomponentindex.h, we have the compile-time functions
         *     for getting the number of aliases given the component indices
         *     (I,J,K,L) as template value parameters.
         */

//     // REMINDER: because the function
//     //    CTensorRank4IndexNumberOfAliases<I,J,K,L>() is constexpr and I,J,K,L
//     //    are parameter value arguments, they can also be constexpr functions...
//     //    For example:
//     //        int i = CTensorRank4IndexNumberOfAliases<CTensorRank4ComponentIndex<0,0,0,0>::FirstIndex(),
//     //                                                 CTensorRank4ComponentIndex<0,0,0,0>::SecondIndex(),
//     //                                                 CTensorRank4ComponentIndex<0,0,0,0>::ThirdIndex(),
//     //                                                 CTensorRank4ComponentIndex<0,0,0,0>::FourthIndex()>()
//     //        which is of course ridiculously verbose, but should be possible.
//
//     /*
//     * To get the aliases, use static_cast<>().  TensorRankIndexAliases() is a
//     *     great example of using set to resolve non-unique values...
//     */
//
// ////c0000
// int num_aliases_c0000 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,0,0>();
// auto ctest_num_aliases_c0000 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,0,0>()>();
// std::cout << "ctest_num_aliases_c0000 : " << ctest_num_aliases_c0000 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0000c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0000));
// for (auto s : set_aliases0000c) {
//     std::cout << "set_aliases0000c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0001
// int num_aliases_c0001 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,0,1>();
// auto ctest_num_aliases_c0001 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,0,1>()>();
// std::cout << "ctest_num_aliases_c0001 : " << ctest_num_aliases_c0001 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0001c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0001));
// for (auto s : set_aliases0001c) {
//     std::cout << "set_aliases0001c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0002
// int num_aliases_c0002 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,0,2>();
// auto ctest_num_aliases_c0002 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,0,2>()>();
// std::cout << "ctest_num_aliases_c0002 : " << ctest_num_aliases_c0002 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0002c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0002));
// for (auto s : set_aliases0002c) {
//     std::cout << "set_aliases0002c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0010
// int num_aliases_c0010 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,1,0>();
// auto ctest_num_aliases_c0010 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,1,0>()>();
// std::cout << "ctest_num_aliases_c0010 : " << ctest_num_aliases_c0010 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0010c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0010));
// for (auto s : set_aliases0010c) {
//     std::cout << "set_aliases0010c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0011
// int num_aliases_c0011 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,1,1>();
// auto ctest_num_aliases_c0011 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,1,1>()>();
// std::cout << "ctest_num_aliases_c0011 : " << ctest_num_aliases_c0011 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0011c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0011));
// for (auto s : set_aliases0011c) {
//     std::cout << "set_aliases0011c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0012
// int num_aliases_c0012 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,1,2>();
// auto ctest_num_aliases_c0012 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,1,2>()>();
// std::cout << "ctest_num_aliases_c0012 : " << ctest_num_aliases_c0012 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0012c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0012));
// for (auto s : set_aliases0012c) {
//     std::cout << "set_aliases0012c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0020
// int num_aliases_c0020 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,2,0>();
// auto ctest_num_aliases_c0020 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,2,0>()>();
// std::cout << "ctest_num_aliases_c0020 : " << ctest_num_aliases_c0020 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0020c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0020));
// for (auto s : set_aliases0020c) {
//     std::cout << "set_aliases0020c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0021
// int num_aliases_c0021 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,2,1>();
// auto ctest_num_aliases_c0021 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,2,1>()>();
// std::cout << "ctest_num_aliases_c0021 : " << ctest_num_aliases_c0021 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0021c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0021));
// for (auto s : set_aliases0021c) {
//     std::cout << "set_aliases0021c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0022
// int num_aliases_c0022 = mpc::core::CTensorRank4IndexNumberOfAliases<0,0,2,2>();
// auto ctest_num_aliases_c0022 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,0,2,2>()>();
// std::cout << "ctest_num_aliases_c0022 : " << ctest_num_aliases_c0022 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0022c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0022));
// for (auto s : set_aliases0022c) {
//     std::cout << "set_aliases0022c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0100
// int num_aliases_c0100 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,0,0>();
// auto ctest_num_aliases_c0100 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,0,0>()>();
// std::cout << "ctest_num_aliases_c0100 : " << ctest_num_aliases_c0100 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0100c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0100));
// for (auto s : set_aliases0100c) {
//     std::cout << "set_aliases0100c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0101
// int num_aliases_c0101 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,0,1>();
// auto ctest_num_aliases_c0101 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,0,1>()>();
// std::cout << "ctest_num_aliases_c0101 : " << ctest_num_aliases_c0101 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0101c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0101));
// for (auto s : set_aliases0101c) {
//     std::cout << "set_aliases0101c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0102
// int num_aliases_c0102 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,0,2>();
// auto ctest_num_aliases_c0102 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,0,2>()>();
// std::cout << "ctest_num_aliases_c0102 : " << ctest_num_aliases_c0102 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0102c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0102));
// for (auto s : set_aliases0102c) {
//     std::cout << "set_aliases0102c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0110
// int num_aliases_c0110 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,1,0>();
// auto ctest_num_aliases_c0110 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,1,0>()>();
// std::cout << "ctest_num_aliases_c0110 : " << ctest_num_aliases_c0110 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0110c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0110));
// for (auto s : set_aliases0110c) {
//     std::cout << "set_aliases0110c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0111
// int num_aliases_c0111 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,1,1>();
// auto ctest_num_aliases_c0111 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,1,1>()>();
// std::cout << "ctest_num_aliases_c0111 : " << ctest_num_aliases_c0111 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0111c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0111));
// for (auto s : set_aliases0111c) {
//     std::cout << "set_aliases0111c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0112
// int num_aliases_c0112 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,1,2>();
// auto ctest_num_aliases_c0112 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,1,2>()>();
// std::cout << "ctest_num_aliases_c0112 : " << ctest_num_aliases_c0112 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0112c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0112));
// for (auto s : set_aliases0112c) {
//     std::cout << "set_aliases0112c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0120
// int num_aliases_c0120 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,2,0>();
// auto ctest_num_aliases_c0120 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,2,0>()>();
// std::cout << "ctest_num_aliases_c0120 : " << ctest_num_aliases_c0120 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0120c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0120));
// for (auto s : set_aliases0120c) {
//     std::cout << "set_aliases0120c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0121
// int num_aliases_c0121 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,2,1>();
// auto ctest_num_aliases_c0121 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,2,1>()>();
// std::cout << "ctest_num_aliases_c0121 : " << ctest_num_aliases_c0121 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0121c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0121));
// for (auto s : set_aliases0121c) {
//     std::cout << "set_aliases0121c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0122
// int num_aliases_c0122 = mpc::core::CTensorRank4IndexNumberOfAliases<0,1,2,2>();
// auto ctest_num_aliases_c0122 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,1,2,2>()>();
// std::cout << "ctest_num_aliases_c0122 : " << ctest_num_aliases_c0122 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0122c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0122));
// for (auto s : set_aliases0122c) {
//     std::cout << "set_aliases0122c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0200
// int num_aliases_c0200 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,0,0>();
// auto ctest_num_aliases_c0200 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,0,0>()>();
// std::cout << "ctest_num_aliases_c0200 : " << ctest_num_aliases_c0200 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0200c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0200));
// for (auto s : set_aliases0200c) {
//     std::cout << "set_aliases0200c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0201
// int num_aliases_c0201 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,0,1>();
// auto ctest_num_aliases_c0201 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,0,1>()>();
// std::cout << "ctest_num_aliases_c0201 : " << ctest_num_aliases_c0201 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0201c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0201));
// for (auto s : set_aliases0201c) {
//     std::cout << "set_aliases0201c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0202
// int num_aliases_c0202 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,0,2>();
// auto ctest_num_aliases_c0202 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,0,2>()>();
// std::cout << "ctest_num_aliases_c0202 : " << ctest_num_aliases_c0202 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0202c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0202));
// for (auto s : set_aliases0202c) {
//     std::cout << "set_aliases0202c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0210
// int num_aliases_c0210 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,1,0>();
// auto ctest_num_aliases_c0210 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,1,0>()>();
// std::cout << "ctest_num_aliases_c0210 : " << ctest_num_aliases_c0210 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0210c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0210));
// for (auto s : set_aliases0210c) {
//     std::cout << "set_aliases0210c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0211
// int num_aliases_c0211 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,1,1>();
// auto ctest_num_aliases_c0211 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,1,1>()>();
// std::cout << "ctest_num_aliases_c0211 : " << ctest_num_aliases_c0211 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0211c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0211));
// for (auto s : set_aliases0211c) {
//     std::cout << "set_aliases0211c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0212
// int num_aliases_c0212 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,1,2>();
// auto ctest_num_aliases_c0212 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,1,2>()>();
// std::cout << "ctest_num_aliases_c0212 : " << ctest_num_aliases_c0212 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0212c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0212));
// for (auto s : set_aliases0212c) {
//     std::cout << "set_aliases0212c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0220
// int num_aliases_c0220 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,2,0>();
// auto ctest_num_aliases_c0220 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,2,0>()>();
// std::cout << "ctest_num_aliases_c0220 : " << ctest_num_aliases_c0220 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0220c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0220));
// for (auto s : set_aliases0220c) {
//     std::cout << "set_aliases0220c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0221
// int num_aliases_c0221 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,2,1>();
// auto ctest_num_aliases_c0221 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,2,1>()>();
// std::cout << "ctest_num_aliases_c0221 : " << ctest_num_aliases_c0221 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0221c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0221));
// for (auto s : set_aliases0221c) {
//     std::cout << "set_aliases0221c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c0222
// int num_aliases_c0222 = mpc::core::CTensorRank4IndexNumberOfAliases<0,2,2,2>();
// auto ctest_num_aliases_c0222 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<0,2,2,2>()>();
// std::cout << "ctest_num_aliases_c0222 : " << ctest_num_aliases_c0222 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases0222c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex0222));
// for (auto s : set_aliases0222c) {
//     std::cout << "set_aliases0222c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1000
// int num_aliases_c1000 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,0,0>();
// auto ctest_num_aliases_c1000 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,0,0>()>();
// std::cout << "ctest_num_aliases_c1000 : " << ctest_num_aliases_c1000 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1000c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1000));
// for (auto s : set_aliases1000c) {
//     std::cout << "set_aliases1000c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1001
// int num_aliases_c1001 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,0,1>();
// auto ctest_num_aliases_c1001 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,0,1>()>();
// std::cout << "ctest_num_aliases_c1001 : " << ctest_num_aliases_c1001 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1001c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1001));
// for (auto s : set_aliases1001c) {
//     std::cout << "set_aliases1001c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1002
// int num_aliases_c1002 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,0,2>();
// auto ctest_num_aliases_c1002 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,0,2>()>();
// std::cout << "ctest_num_aliases_c1002 : " << ctest_num_aliases_c1002 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1002c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1002));
// for (auto s : set_aliases1002c) {
//     std::cout << "set_aliases1002c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1010
// int num_aliases_c1010 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,1,0>();
// auto ctest_num_aliases_c1010 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,1,0>()>();
// std::cout << "ctest_num_aliases_c1010 : " << ctest_num_aliases_c1010 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1010c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1010));
// for (auto s : set_aliases1010c) {
//     std::cout << "set_aliases1010c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1011
// int num_aliases_c1011 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,1,1>();
// auto ctest_num_aliases_c1011 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,1,1>()>();
// std::cout << "ctest_num_aliases_c1011 : " << ctest_num_aliases_c1011 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1011c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1011));
// for (auto s : set_aliases1011c) {
//     std::cout << "set_aliases1011c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1012
// int num_aliases_c1012 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,1,2>();
// auto ctest_num_aliases_c1012 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,1,2>()>();
// std::cout << "ctest_num_aliases_c1012 : " << ctest_num_aliases_c1012 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1012c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1012));
// for (auto s : set_aliases1012c) {
//     std::cout << "set_aliases1012c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1020
// int num_aliases_c1020 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,2,0>();
// auto ctest_num_aliases_c1020 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,2,0>()>();
// std::cout << "ctest_num_aliases_c1020 : " << ctest_num_aliases_c1020 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1020c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1020));
// for (auto s : set_aliases1020c) {
//     std::cout << "set_aliases1020c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1021
// int num_aliases_c1021 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,2,1>();
// auto ctest_num_aliases_c1021 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,2,1>()>();
// std::cout << "ctest_num_aliases_c1021 : " << ctest_num_aliases_c1021 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1021c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1021));
// for (auto s : set_aliases1021c) {
//     std::cout << "set_aliases1021c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1022
// int num_aliases_c1022 = mpc::core::CTensorRank4IndexNumberOfAliases<1,0,2,2>();
// auto ctest_num_aliases_c1022 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,0,2,2>()>();
// std::cout << "ctest_num_aliases_c1022 : " << ctest_num_aliases_c1022 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1022c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1022));
// for (auto s : set_aliases1022c) {
//     std::cout << "set_aliases1022c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1100
// int num_aliases_c1100 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,0,0>();
// auto ctest_num_aliases_c1100 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,0,0>()>();
// std::cout << "ctest_num_aliases_c1100 : " << ctest_num_aliases_c1100 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1100c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1100));
// for (auto s : set_aliases1100c) {
//     std::cout << "set_aliases1100c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1101
// int num_aliases_c1101 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,0,1>();
// auto ctest_num_aliases_c1101 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,0,1>()>();
// std::cout << "ctest_num_aliases_c1101 : " << ctest_num_aliases_c1101 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1101c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1101));
// for (auto s : set_aliases1101c) {
//     std::cout << "set_aliases1101c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1102
// int num_aliases_c1102 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,0,2>();
// auto ctest_num_aliases_c1102 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,0,2>()>();
// std::cout << "ctest_num_aliases_c1102 : " << ctest_num_aliases_c1102 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1102c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1102));
// for (auto s : set_aliases1102c) {
//     std::cout << "set_aliases1102c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1110
// int num_aliases_c1110 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,1,0>();
// auto ctest_num_aliases_c1110 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,1,0>()>();
// std::cout << "ctest_num_aliases_c1110 : " << ctest_num_aliases_c1110 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1110c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1110));
// for (auto s : set_aliases1110c) {
//     std::cout << "set_aliases1110c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1111
// int num_aliases_c1111 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,1,1>();
// auto ctest_num_aliases_c1111 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,1,1>()>();
// std::cout << "ctest_num_aliases_c1111 : " << ctest_num_aliases_c1111 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1111c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1111));
// for (auto s : set_aliases1111c) {
//     std::cout << "set_aliases1111c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1112
// int num_aliases_c1112 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,1,2>();
// auto ctest_num_aliases_c1112 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,1,2>()>();
// std::cout << "ctest_num_aliases_c1112 : " << ctest_num_aliases_c1112 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1112c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1112));
// for (auto s : set_aliases1112c) {
//     std::cout << "set_aliases1112c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1120
// int num_aliases_c1120 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,2,0>();
// auto ctest_num_aliases_c1120 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,2,0>()>();
// std::cout << "ctest_num_aliases_c1120 : " << ctest_num_aliases_c1120 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1120c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1120));
// for (auto s : set_aliases1120c) {
//     std::cout << "set_aliases1120c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1121
// int num_aliases_c1121 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,2,1>();
// auto ctest_num_aliases_c1121 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,2,1>()>();
// std::cout << "ctest_num_aliases_c1121 : " << ctest_num_aliases_c1121 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1121c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1121));
// for (auto s : set_aliases1121c) {
//     std::cout << "set_aliases1121c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1122
// int num_aliases_c1122 = mpc::core::CTensorRank4IndexNumberOfAliases<1,1,2,2>();
// auto ctest_num_aliases_c1122 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,1,2,2>()>();
// std::cout << "ctest_num_aliases_c1122 : " << ctest_num_aliases_c1122 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1122c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1122));
// for (auto s : set_aliases1122c) {
//     std::cout << "set_aliases1122c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1200
// int num_aliases_c1200 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,0,0>();
// auto ctest_num_aliases_c1200 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,0,0>()>();
// std::cout << "ctest_num_aliases_c1200 : " << ctest_num_aliases_c1200 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1200c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1200));
// for (auto s : set_aliases1200c) {
//     std::cout << "set_aliases1200c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1201
// int num_aliases_c1201 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,0,1>();
// auto ctest_num_aliases_c1201 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,0,1>()>();
// std::cout << "ctest_num_aliases_c1201 : " << ctest_num_aliases_c1201 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1201c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1201));
// for (auto s : set_aliases1201c) {
//     std::cout << "set_aliases1201c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1202
// int num_aliases_c1202 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,0,2>();
// auto ctest_num_aliases_c1202 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,0,2>()>();
// std::cout << "ctest_num_aliases_c1202 : " << ctest_num_aliases_c1202 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1202c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1202));
// for (auto s : set_aliases1202c) {
//     std::cout << "set_aliases1202c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1210
// int num_aliases_c1210 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,1,0>();
// auto ctest_num_aliases_c1210 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,1,0>()>();
// std::cout << "ctest_num_aliases_c1210 : " << ctest_num_aliases_c1210 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1210c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1210));
// for (auto s : set_aliases1210c) {
//     std::cout << "set_aliases1210c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1211
// int num_aliases_c1211 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,1,1>();
// auto ctest_num_aliases_c1211 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,1,1>()>();
// std::cout << "ctest_num_aliases_c1211 : " << ctest_num_aliases_c1211 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1211c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1211));
// for (auto s : set_aliases1211c) {
//     std::cout << "set_aliases1211c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1212
// int num_aliases_c1212 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,1,2>();
// auto ctest_num_aliases_c1212 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,1,2>()>();
// std::cout << "ctest_num_aliases_c1212 : " << ctest_num_aliases_c1212 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1212c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1212));
// for (auto s : set_aliases1212c) {
//     std::cout << "set_aliases1212c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1220
// int num_aliases_c1220 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,2,0>();
// auto ctest_num_aliases_c1220 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,2,0>()>();
// std::cout << "ctest_num_aliases_c1220 : " << ctest_num_aliases_c1220 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1220c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1220));
// for (auto s : set_aliases1220c) {
//     std::cout << "set_aliases1220c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1221
// int num_aliases_c1221 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,2,1>();
// auto ctest_num_aliases_c1221 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,2,1>()>();
// std::cout << "ctest_num_aliases_c1221 : " << ctest_num_aliases_c1221 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1221c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1221));
// for (auto s : set_aliases1221c) {
//     std::cout << "set_aliases1221c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c1222
// int num_aliases_c1222 = mpc::core::CTensorRank4IndexNumberOfAliases<1,2,2,2>();
// auto ctest_num_aliases_c1222 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<1,2,2,2>()>();
// std::cout << "ctest_num_aliases_c1222 : " << ctest_num_aliases_c1222 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases1222c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex1222));
// for (auto s : set_aliases1222c) {
//     std::cout << "set_aliases1222c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2000
// int num_aliases_c2000 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,0,0>();
// auto ctest_num_aliases_c2000 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,0,0>()>();
// std::cout << "ctest_num_aliases_c2000 : " << ctest_num_aliases_c2000 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2000c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2000));
// for (auto s : set_aliases2000c) {
//     std::cout << "set_aliases2000c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2001
// int num_aliases_c2001 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,0,1>();
// auto ctest_num_aliases_c2001 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,0,1>()>();
// std::cout << "ctest_num_aliases_c2001 : " << ctest_num_aliases_c2001 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2001c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2001));
// for (auto s : set_aliases2001c) {
//     std::cout << "set_aliases2001c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2002
// int num_aliases_c2002 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,0,2>();
// auto ctest_num_aliases_c2002 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,0,2>()>();
// std::cout << "ctest_num_aliases_c2002 : " << ctest_num_aliases_c2002 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2002c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2002));
// for (auto s : set_aliases2002c) {
//     std::cout << "set_aliases2002c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2010
// int num_aliases_c2010 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,1,0>();
// auto ctest_num_aliases_c2010 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,1,0>()>();
// std::cout << "ctest_num_aliases_c2010 : " << ctest_num_aliases_c2010 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2010c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2010));
// for (auto s : set_aliases2010c) {
//     std::cout << "set_aliases2010c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2011
// int num_aliases_c2011 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,1,1>();
// auto ctest_num_aliases_c2011 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,1,1>()>();
// std::cout << "ctest_num_aliases_c2011 : " << ctest_num_aliases_c2011 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2011c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2011));
// for (auto s : set_aliases2011c) {
//     std::cout << "set_aliases2011c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2012
// int num_aliases_c2012 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,1,2>();
// auto ctest_num_aliases_c2012 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,1,2>()>();
// std::cout << "ctest_num_aliases_c2012 : " << ctest_num_aliases_c2012 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2012c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2012));
// for (auto s : set_aliases2012c) {
//     std::cout << "set_aliases2012c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2020
// int num_aliases_c2020 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,2,0>();
// auto ctest_num_aliases_c2020 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,2,0>()>();
// std::cout << "ctest_num_aliases_c2020 : " << ctest_num_aliases_c2020 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2020c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2020));
// for (auto s : set_aliases2020c) {
//     std::cout << "set_aliases2020c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2021
// int num_aliases_c2021 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,2,1>();
// auto ctest_num_aliases_c2021 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,2,1>()>();
// std::cout << "ctest_num_aliases_c2021 : " << ctest_num_aliases_c2021 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2021c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2021));
// for (auto s : set_aliases2021c) {
//     std::cout << "set_aliases2021c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2022
// int num_aliases_c2022 = mpc::core::CTensorRank4IndexNumberOfAliases<2,0,2,2>();
// auto ctest_num_aliases_c2022 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,0,2,2>()>();
// std::cout << "ctest_num_aliases_c2022 : " << ctest_num_aliases_c2022 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2022c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2022));
// for (auto s : set_aliases2022c) {
//     std::cout << "set_aliases2022c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2100
// int num_aliases_c2100 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,0,0>();
// auto ctest_num_aliases_c2100 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,0,0>()>();
// std::cout << "ctest_num_aliases_c2100 : " << ctest_num_aliases_c2100 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2100c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2100));
// for (auto s : set_aliases2100c) {
//     std::cout << "set_aliases2100c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2101
// int num_aliases_c2101 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,0,1>();
// auto ctest_num_aliases_c2101 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,0,1>()>();
// std::cout << "ctest_num_aliases_c2101 : " << ctest_num_aliases_c2101 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2101c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2101));
// for (auto s : set_aliases2101c) {
//     std::cout << "set_aliases2101c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2102
// int num_aliases_c2102 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,0,2>();
// auto ctest_num_aliases_c2102 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,0,2>()>();
// std::cout << "ctest_num_aliases_c2102 : " << ctest_num_aliases_c2102 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2102c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2102));
// for (auto s : set_aliases2102c) {
//     std::cout << "set_aliases2102c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2110
// int num_aliases_c2110 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,1,0>();
// auto ctest_num_aliases_c2110 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,1,0>()>();
// std::cout << "ctest_num_aliases_c2110 : " << ctest_num_aliases_c2110 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2110c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2110));
// for (auto s : set_aliases2110c) {
//     std::cout << "set_aliases2110c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2111
// int num_aliases_c2111 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,1,1>();
// auto ctest_num_aliases_c2111 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,1,1>()>();
// std::cout << "ctest_num_aliases_c2111 : " << ctest_num_aliases_c2111 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2111c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2111));
// for (auto s : set_aliases2111c) {
//     std::cout << "set_aliases2111c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2112
// int num_aliases_c2112 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,1,2>();
// auto ctest_num_aliases_c2112 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,1,2>()>();
// std::cout << "ctest_num_aliases_c2112 : " << ctest_num_aliases_c2112 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2112c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2112));
// for (auto s : set_aliases2112c) {
//     std::cout << "set_aliases2112c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2120
// int num_aliases_c2120 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,2,0>();
// auto ctest_num_aliases_c2120 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,2,0>()>();
// std::cout << "ctest_num_aliases_c2120 : " << ctest_num_aliases_c2120 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2120c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2120));
// for (auto s : set_aliases2120c) {
//     std::cout << "set_aliases2120c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2121
// int num_aliases_c2121 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,2,1>();
// auto ctest_num_aliases_c2121 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,2,1>()>();
// std::cout << "ctest_num_aliases_c2121 : " << ctest_num_aliases_c2121 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2121c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2121));
// for (auto s : set_aliases2121c) {
//     std::cout << "set_aliases2121c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2122
// int num_aliases_c2122 = mpc::core::CTensorRank4IndexNumberOfAliases<2,1,2,2>();
// auto ctest_num_aliases_c2122 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,1,2,2>()>();
// std::cout << "ctest_num_aliases_c2122 : " << ctest_num_aliases_c2122 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2122c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2122));
// for (auto s : set_aliases2122c) {
//     std::cout << "set_aliases2122c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2200
// int num_aliases_c2200 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,0,0>();
// auto ctest_num_aliases_c2200 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,0,0>()>();
// std::cout << "ctest_num_aliases_c2200 : " << ctest_num_aliases_c2200 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2200c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2200));
// for (auto s : set_aliases2200c) {
//     std::cout << "set_aliases2200c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2201
// int num_aliases_c2201 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,0,1>();
// auto ctest_num_aliases_c2201 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,0,1>()>();
// std::cout << "ctest_num_aliases_c2201 : " << ctest_num_aliases_c2201 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2201c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2201));
// for (auto s : set_aliases2201c) {
//     std::cout << "set_aliases2201c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2202
// int num_aliases_c2202 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,0,2>();
// auto ctest_num_aliases_c2202 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,0,2>()>();
// std::cout << "ctest_num_aliases_c2202 : " << ctest_num_aliases_c2002 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2202c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2202));
// for (auto s : set_aliases2202c) {
//     std::cout << "set_aliases2202c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2210
// int num_aliases_c2210 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,1,0>();
// auto ctest_num_aliases_c2210 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,1,0>()>();
// std::cout << "ctest_num_aliases_c2210 : " << ctest_num_aliases_c2210 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2210c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2210));
// for (auto s : set_aliases2210c) {
//     std::cout << "set_aliases2210c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2211
// int num_aliases_c2211 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,1,1>();
// auto ctest_num_aliases_c2211 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,1,1>()>();
// std::cout << "ctest_num_aliases_c2211 : " << ctest_num_aliases_c2211 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2211c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2211));
// for (auto s : set_aliases2211c) {
//     std::cout << "set_aliases2211c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2212
// int num_aliases_c2212 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,1,2>();
// auto ctest_num_aliases_c2212 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,1,2>()>();
// std::cout << "ctest_num_aliases_c2212 : " << ctest_num_aliases_c2212 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2212c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2212));
// for (auto s : set_aliases2212c) {
//     std::cout << "set_aliases2212c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2220
// int num_aliases_c2220 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,2,0>();
// auto ctest_num_aliases_c2220 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,2,0>()>();
// std::cout << "ctest_num_aliases_c2220 : " << ctest_num_aliases_c2220 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2220c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2220));
// for (auto s : set_aliases2220c) {
//     std::cout << "set_aliases2220c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2221
// int num_aliases_c2221 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,2,1>();
// auto ctest_num_aliases_c2221 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,2,1>()>();
// std::cout << "ctest_num_aliases_c2221 : " << ctest_num_aliases_c2221 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2221c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2221));
// for (auto s : set_aliases2221c) {
//     std::cout << "set_aliases2221c : " << s << std::endl;
// }
// std::cout << "" << std::endl;
//
// ////c2222
// int num_aliases_c2222 = mpc::core::CTensorRank4IndexNumberOfAliases<2,2,2,2>();
// auto ctest_num_aliases_c2222 = mpcuserguide::IntTypeParameterValueTest<
//         mpc::core::CTensorRank4IndexNumberOfAliases<2,2,2,2>()>();
// std::cout << "ctest_num_aliases_c2222 : " << ctest_num_aliases_c2222 << std::endl;
// std::set<mpc::core::TensorRank4ComponentIndex> set_aliases2222c =
//         mpc::core::TensorRank4IndexAliases(
//             static_cast<mpc::core::TensorRank4ComponentIndex>(cindex2222));
// for (auto s : set_aliases2222c) {
//     std::cout << "set_aliases2222c : " << s << std::endl;
// }
// std::cout << "" << std::endl;

    /*
  * predicates for tensor rank4 index
  *
  * Currently, MPC provides two predicates (callable that returns a value
  *     testable as a bool; see
  *     https://en.cppreference.com/w/cpp/named_req/Predicate) for
  *     TensorRankNCompoentIndex<> where N is either 2 or 4: ...IsAlias(...)
  *     and ...HasAlias(...).  The definiton of aliases is defined by
  *     symmetry...
  */

// std::cout << "\n repeat for compile-time functions" << std::endl;
// //// cindex0000
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0000);
// std::cout << cindex0000 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0000);
// std::cout << cindex0000 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0001);
// std::cout << cindex0000 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0002);
// std::cout << cindex0000 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0010);
// std::cout << cindex0000 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0011);
// std::cout << cindex0000 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0012);
// std::cout << cindex0000 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0020);
// std::cout << cindex0000 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0021);
// std::cout << cindex0000 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0022);
// std::cout << cindex0000 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0001
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0001);
// std::cout << cindex0001 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0000);
// std::cout << cindex0001 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0001);
// std::cout << cindex0001 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0002);
// std::cout << cindex0001 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0010);
// std::cout << cindex0001 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0011);
// std::cout << cindex0001 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0012);
// std::cout << cindex0001 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0020);
// std::cout << cindex0001 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0021);
// std::cout << cindex0001 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0001,cindex0022);
// std::cout << cindex0001 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0002
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0002);
// std::cout << cindex0002 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0000);
// std::cout << cindex0002 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0001);
// std::cout << cindex0002 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0002);
// std::cout << cindex0002 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0010);
// std::cout << cindex0002 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0011);
// std::cout << cindex0002 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0012);
// std::cout << cindex0002 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0020);
// std::cout << cindex0002 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0021);
// std::cout << cindex0002 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0022);
// std::cout << cindex0002 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0010
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0010);
// std::cout << cindex0010 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0000);
// std::cout << cindex0010 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0001);
// std::cout << cindex0010 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0002);
// std::cout << cindex0010 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0010);
// std::cout << cindex0010 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0011);
// std::cout << cindex0010 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0012);
// std::cout << cindex0010 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0020);
// std::cout << cindex0010 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0021);
// std::cout << cindex0010 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0010,cindex0022);
// std::cout << cindex0010 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0011
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0011);
// std::cout << cindex0011 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0000);
// std::cout << cindex0011 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0001);
// std::cout << cindex0011 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0002);
// std::cout << cindex0011 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0010);
// std::cout << cindex0011 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0011);
// std::cout << cindex0011 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0012);
// std::cout << cindex0011 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0020);
// std::cout << cindex0011 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0021);
// std::cout << cindex0011 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0011,cindex0022);
// std::cout << cindex0011 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0012
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0012);
// std::cout << cindex0012 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0000);
// std::cout << cindex0012 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0001);
// std::cout << cindex0012 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0002);
// std::cout << cindex0012 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0010);
// std::cout << cindex0012 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0011);
// std::cout << cindex0012 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0012);
// std::cout << cindex0012 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0020);
// std::cout << cindex0012 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0021);
// std::cout << cindex0012 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0022);
// std::cout << cindex0012 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0020
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0020);
// std::cout << cindex0020 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0000);
// std::cout << cindex0020 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0001);
// std::cout << cindex0020 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0002);
// std::cout << cindex0020 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0010);
// std::cout << cindex0020 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0011);
// std::cout << cindex0020 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0012);
// std::cout << cindex0020 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0020);
// std::cout << cindex0020 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0021);
// std::cout << cindex0020 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0020,cindex0022);
// std::cout << cindex0020 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0021
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0021);
// std::cout << cindex0021 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0000);
// std::cout << cindex0021 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0001);
// std::cout << cindex0021 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0002);
// std::cout << cindex0021 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0010);
// std::cout << cindex0021 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0011);
// std::cout << cindex0021 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0012);
// std::cout << cindex0021 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0020);
// std::cout << cindex0021 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0021);
// std::cout << cindex0021 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0021,cindex0022);
// std::cout << cindex0021 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0022
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0022);
// std::cout << cindex0022 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0000);
// std::cout << cindex0022 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0001);
// std::cout << cindex0022 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0002);
// std::cout << cindex0022 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0010);
// std::cout << cindex0022 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0011);
// std::cout << cindex0022 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0012);
// std::cout << cindex0022 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0020);
// std::cout << cindex0022 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0021);
// std::cout << cindex0022 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0022);
// std::cout << cindex0022 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0100
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0100);
// std::cout << cindex0100 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0000);
// std::cout << cindex0100 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0001);
// std::cout << cindex0100 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0002);
// std::cout << cindex0100 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0010);
// std::cout << cindex0100 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0011);
// std::cout << cindex0100 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0012);
// std::cout << cindex0100 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0020);
// std::cout << cindex0100 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0021);
// std::cout << cindex0100 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0100,cindex0022);
// std::cout << cindex0100 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0101
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0101);
// std::cout << cindex0101 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0000);
// std::cout << cindex0101 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0001);
// std::cout << cindex0101 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0002);
// std::cout << cindex0101 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0010);
// std::cout << cindex0101 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0011);
// std::cout << cindex0101 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0012);
// std::cout << cindex0101 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0020);
// std::cout << cindex0101 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0021);
// std::cout << cindex0101 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0101,cindex0022);
// std::cout << cindex0101 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0102
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0102);
// std::cout << cindex0102 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0000);
// std::cout << cindex0102 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0001);
// std::cout << cindex0102 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0002);
// std::cout << cindex0102 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0010);
// std::cout << cindex0102 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0011);
// std::cout << cindex0102 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0012);
// std::cout << cindex0102 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0020);
// std::cout << cindex0102 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0021);
// std::cout << cindex0102 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0102,cindex0022);
// std::cout << cindex0102 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0110
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0110);
// std::cout << cindex0110 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0000);
// std::cout << cindex0110 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0001);
// std::cout << cindex0110 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0002);
// std::cout << cindex0110 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0010);
// std::cout << cindex0110 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0011);
// std::cout << cindex0110 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0012);
// std::cout << cindex0110 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0020);
// std::cout << cindex0110 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0021);
// std::cout << cindex0110 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0110,cindex0022);
// std::cout << cindex0110 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0111
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0111);
// std::cout << cindex0111 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0000);
// std::cout << cindex0111 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0001);
// std::cout << cindex0111 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0002);
// std::cout << cindex0111 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0010);
// std::cout << cindex0111 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0011);
// std::cout << cindex0111 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0012);
// std::cout << cindex0111 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0020);
// std::cout << cindex0111 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0021);
// std::cout << cindex0111 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0111,cindex0022);
// std::cout << cindex0111 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0112
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0112);
// std::cout << cindex0112 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0000);
// std::cout << cindex0112 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0001);
// std::cout << cindex0112 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0002);
// std::cout << cindex0112 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0010);
// std::cout << cindex0112 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0011);
// std::cout << cindex0112 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0012);
// std::cout << cindex0112 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0020);
// std::cout << cindex0112 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0021);
// std::cout << cindex0112 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0112,cindex0022);
// std::cout << cindex0112 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0120
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0120);
// std::cout << cindex0120 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0000);
// std::cout << cindex0120 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0001);
// std::cout << cindex0120 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0002);
// std::cout << cindex0120 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0010);
// std::cout << cindex0120 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0011);
// std::cout << cindex0120 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0012);
// std::cout << cindex0120 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0020);
// std::cout << cindex0120 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0021);
// std::cout << cindex0120 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0120,cindex0022);
// std::cout << cindex0120 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0121
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0121);
// std::cout << cindex0121 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0000);
// std::cout << cindex0121 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0001);
// std::cout << cindex0121 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0002);
// std::cout << cindex0121 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0010);
// std::cout << cindex0121 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0011);
// std::cout << cindex0121 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0012);
// std::cout << cindex0121 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0020);
// std::cout << cindex0121 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0021);
// std::cout << cindex0121 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0121,cindex0022);
// std::cout << cindex0121 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0122
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0122);
// std::cout << cindex0122 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0000);
// std::cout << cindex0122 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0001);
// std::cout << cindex0122 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0002);
// std::cout << cindex0122 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0010);
// std::cout << cindex0122 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0011);
// std::cout << cindex0122 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0012);
// std::cout << cindex0122 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0020);
// std::cout << cindex0122 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0021);
// std::cout << cindex0122 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0122,cindex0022);
// std::cout << cindex0122 << " is_alias " << cindex0122 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0200
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0000);
// std::cout << cindex0000 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0000);
// std::cout << cindex0000 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0001);
// std::cout << cindex0000 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0002);
// std::cout << cindex0000 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0010);
// std::cout << cindex0000 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0011);
// std::cout << cindex0000 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0012);
// std::cout << cindex0000 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0020);
// std::cout << cindex0000 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0021);
// std::cout << cindex0000 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0022);
// std::cout << cindex0000 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0201
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0201);
// std::cout << cindex0201 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0000);
// std::cout << cindex0201 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0001);
// std::cout << cindex0201 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0002);
// std::cout << cindex0201 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0010);
// std::cout << cindex0201 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0011);
// std::cout << cindex0201 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0012);
// std::cout << cindex0201 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0020);
// std::cout << cindex0201 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0021);
// std::cout << cindex0201 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0201,cindex0022);
// std::cout << cindex0201 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0202
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0002);
// std::cout << cindex0002 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0000);
// std::cout << cindex0002 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0001);
// std::cout << cindex0002 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0002);
// std::cout << cindex0002 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0010);
// std::cout << cindex0002 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0011);
// std::cout << cindex0002 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0012);
// std::cout << cindex0002 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0020);
// std::cout << cindex0002 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0021);
// std::cout << cindex0002 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0002,cindex0022);
// std::cout << cindex0002 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0210
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0210);
// std::cout << cindex0210 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0000);
// std::cout << cindex0210 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0001);
// std::cout << cindex0210 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0002);
// std::cout << cindex0210 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0010);
// std::cout << cindex0210 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0011);
// std::cout << cindex0210 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0012);
// std::cout << cindex0210 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0020);
// std::cout << cindex0210 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0021);
// std::cout << cindex0210 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0210,cindex0022);
// std::cout << cindex0210 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0211
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0211);
// std::cout << cindex0211 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0000);
// std::cout << cindex0211 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0001);
// std::cout << cindex0211 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0002);
// std::cout << cindex0211 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0010);
// std::cout << cindex0211 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0011);
// std::cout << cindex0211 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0012);
// std::cout << cindex0211 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0020);
// std::cout << cindex0211 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0021);
// std::cout << cindex0211 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0211,cindex0022);
// std::cout << cindex0211 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0212
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0212);
// std::cout << cindex0212 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0000);
// std::cout << cindex0212 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0001);
// std::cout << cindex0212 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0002);
// std::cout << cindex0212 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0010);
// std::cout << cindex0212 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0011);
// std::cout << cindex0212 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0012);
// std::cout << cindex0212 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0020);
// std::cout << cindex0212 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0021);
// std::cout << cindex0212 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0212,cindex0022);
// std::cout << cindex0212 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0220
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0220);
// std::cout << cindex0220 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0000);
// std::cout << cindex0220 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0001);
// std::cout << cindex0220 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0002);
// std::cout << cindex0220 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0010);
// std::cout << cindex0220 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0011);
// std::cout << cindex0220 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0012);
// std::cout << cindex0220 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0020);
// std::cout << cindex0220 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0021);
// std::cout << cindex0220 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0220,cindex0022);
// std::cout << cindex0220 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0221
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0221);
// std::cout << cindex0221 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0000);
// std::cout << cindex0221 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0001);
// std::cout << cindex0221 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0002);
// std::cout << cindex0221 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0010);
// std::cout << cindex0221 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0011);
// std::cout << cindex0221 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0012);
// std::cout << cindex0221 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0020);
// std::cout << cindex0221 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0021);
// std::cout << cindex0221 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0221,cindex0022);
// std::cout << cindex0221 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex0222
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0222);
// std::cout << cindex0222 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0000);
// std::cout << cindex0222 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0001);
// std::cout << cindex0222 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0002);
// std::cout << cindex0222 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0010);
// std::cout << cindex0222 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0011);
// std::cout << cindex0222 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0012);
// std::cout << cindex0222 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0020);
// std::cout << cindex0222 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0021);
// std::cout << cindex0222 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0222,cindex0022);
// std::cout << cindex0222 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1000
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1000);
// std::cout << cindex1000 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0000);
// std::cout << cindex1000 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0001);
// std::cout << cindex1000 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0002);
// std::cout << cindex1000 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0010);
// std::cout << cindex1000 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0011);
// std::cout << cindex1000 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0012);
// std::cout << cindex1000 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0020);
// std::cout << cindex1000 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0021);
// std::cout << cindex1000 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1000,cindex0022);
// std::cout << cindex1000 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1001
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1001);
// std::cout << cindex1001 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0000);
// std::cout << cindex1001 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0001);
// std::cout << cindex1001 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0002);
// std::cout << cindex1001 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0010);
// std::cout << cindex1001 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0011);
// std::cout << cindex1001 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0012);
// std::cout << cindex1001 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0020);
// std::cout << cindex1001 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0021);
// std::cout << cindex1001 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1001,cindex0022);
// std::cout << cindex1001 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1002
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1002);
// std::cout << cindex1002 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0000);
// std::cout << cindex1002 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0001);
// std::cout << cindex1002 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0002);
// std::cout << cindex1002 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0010);
// std::cout << cindex1002 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0011);
// std::cout << cindex1002 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0012);
// std::cout << cindex1002 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0020);
// std::cout << cindex1002 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0021);
// std::cout << cindex1002 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1002,cindex0022);
// std::cout << cindex1002 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1010
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1010);
// std::cout << cindex1010 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0000);
// std::cout << cindex1010 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0001);
// std::cout << cindex1010 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0002);
// std::cout << cindex1010 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0010);
// std::cout << cindex1010 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0011);
// std::cout << cindex1010 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0012);
// std::cout << cindex1010 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0020);
// std::cout << cindex1010 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0021);
// std::cout << cindex1010 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1010,cindex0022);
// std::cout << cindex1010 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1011
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1011);
// std::cout << cindex1011 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0000);
// std::cout << cindex1011 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0001);
// std::cout << cindex1011 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0002);
// std::cout << cindex1011 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0010);
// std::cout << cindex1011 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0011);
// std::cout << cindex1011 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0012);
// std::cout << cindex1011 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0020);
// std::cout << cindex1011 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0021);
// std::cout << cindex1011 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1011,cindex0022);
// std::cout << cindex1011 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1012
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1012);
// std::cout << cindex1012 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0000);
// std::cout << cindex1012 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0001);
// std::cout << cindex1012 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0002);
// std::cout << cindex1012 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0010);
// std::cout << cindex1012 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0011);
// std::cout << cindex1012 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0012);
// std::cout << cindex1012 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0020);
// std::cout << cindex1012 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0021);
// std::cout << cindex1012 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1012,cindex0022);
// std::cout << cindex1012 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1020
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1020);
// std::cout << cindex1020 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0000);
// std::cout << cindex1020 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0001);
// std::cout << cindex1020 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0002);
// std::cout << cindex1020 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0010);
// std::cout << cindex1020 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0011);
// std::cout << cindex1020 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0012);
// std::cout << cindex1020 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0020);
// std::cout << cindex1020 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0021);
// std::cout << cindex1020 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1020,cindex0022);
// std::cout << cindex1020 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1021
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1021);
// std::cout << cindex1021 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0000);
// std::cout << cindex1021 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0001);
// std::cout << cindex1021 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0002);
// std::cout << cindex1021 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0010);
// std::cout << cindex1021 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0011);
// std::cout << cindex1021 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0012);
// std::cout << cindex1021 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0020);
// std::cout << cindex1021 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0021);
// std::cout << cindex1021 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1021,cindex0022);
// std::cout << cindex1021 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1022
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1022);
// std::cout << cindex1022 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0000);
// std::cout << cindex1022 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0001);
// std::cout << cindex1022 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0002);
// std::cout << cindex1022 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0010);
// std::cout << cindex1022 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0011);
// std::cout << cindex1022 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0012);
// std::cout << cindex1022 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0020);
// std::cout << cindex1022 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0021);
// std::cout << cindex1022 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1022,cindex0022);
// std::cout << cindex1022 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1100
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1100);
// std::cout << cindex1100 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0000);
// std::cout << cindex1100 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0001);
// std::cout << cindex1100 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0002);
// std::cout << cindex1100 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0010);
// std::cout << cindex1100 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0011);
// std::cout << cindex1100 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0012);
// std::cout << cindex1100 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0020);
// std::cout << cindex1100 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0021);
// std::cout << cindex1100 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1100,cindex0022);
// std::cout << cindex1100 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1101
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1101);
// std::cout << cindex1101 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0000);
// std::cout << cindex1101 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0001);
// std::cout << cindex1101 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0002);
// std::cout << cindex1101 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0010);
// std::cout << cindex1101 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0011);
// std::cout << cindex1101 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0012);
// std::cout << cindex1101 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0020);
// std::cout << cindex1101 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0021);
// std::cout << cindex1101 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1101,cindex0022);
// std::cout << cindex1101 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1102
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1102);
// std::cout << cindex1102 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0000);
// std::cout << cindex1102 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0001);
// std::cout << cindex1102 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0002);
// std::cout << cindex1102 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0010);
// std::cout << cindex1102 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0011);
// std::cout << cindex1102 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0012);
// std::cout << cindex1102 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0020);
// std::cout << cindex1102 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0021);
// std::cout << cindex1102 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1102,cindex0022);
// std::cout << cindex1102 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1110
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1110);
// std::cout << cindex1110 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0000);
// std::cout << cindex1110 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0001);
// std::cout << cindex1110 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0002);
// std::cout << cindex1110 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0010);
// std::cout << cindex1110 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0011);
// std::cout << cindex1110 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0012);
// std::cout << cindex1110 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0020);
// std::cout << cindex1110 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0021);
// std::cout << cindex1110 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1110,cindex0022);
// std::cout << cindex1110 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1111
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1111);
// std::cout << cindex1111 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0000);
// std::cout << cindex1111 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0001);
// std::cout << cindex1111 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0002);
// std::cout << cindex1111 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0010);
// std::cout << cindex1111 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0011);
// std::cout << cindex1111 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0012);
// std::cout << cindex1111 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0020);
// std::cout << cindex1111 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0021);
// std::cout << cindex1111 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1111,cindex0022);
// std::cout << cindex1111 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1112
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0012);
// std::cout << cindex0012 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0000);
// std::cout << cindex0012 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0001);
// std::cout << cindex0012 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0002);
// std::cout << cindex0012 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0010);
// std::cout << cindex0012 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0011);
// std::cout << cindex0012 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0012);
// std::cout << cindex0012 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0020);
// std::cout << cindex0012 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0021);
// std::cout << cindex0012 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0022);
// std::cout << cindex0012 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1120
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1120);
// std::cout << cindex1120 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0000);
// std::cout << cindex1120 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0001);
// std::cout << cindex1120 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0002);
// std::cout << cindex1120 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0010);
// std::cout << cindex1120 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0011);
// std::cout << cindex1120 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0012);
// std::cout << cindex1120 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0020);
// std::cout << cindex1120 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0021);
// std::cout << cindex1120 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1120,cindex0022);
// std::cout << cindex1120 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1121
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1121);
// std::cout << cindex1121 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0000);
// std::cout << cindex1121 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0001);
// std::cout << cindex1121 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0002);
// std::cout << cindex1121 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0010);
// std::cout << cindex1121 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0011);
// std::cout << cindex1121 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0012);
// std::cout << cindex1121 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0020);
// std::cout << cindex1121 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0021);
// std::cout << cindex1121 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1121,cindex0022);
// std::cout << cindex1121 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1122
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1122);
// std::cout << cindex1122 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0000);
// std::cout << cindex1122 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0001);
// std::cout << cindex1122 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0002);
// std::cout << cindex1122 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0010);
// std::cout << cindex1122 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0011);
// std::cout << cindex1122 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0012);
// std::cout << cindex1122 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0020);
// std::cout << cindex1122 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0021);
// std::cout << cindex1122 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1122,cindex0022);
// std::cout << cindex1122 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1200
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0000);
// std::cout << cindex0000 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0000);
// std::cout << cindex0000 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0001);
// std::cout << cindex0000 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0002);
// std::cout << cindex0000 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0010);
// std::cout << cindex0000 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0011);
// std::cout << cindex0000 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0012);
// std::cout << cindex0000 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0020);
// std::cout << cindex0000 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0021);
// std::cout << cindex0000 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0022);
// std::cout << cindex0000 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1201
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1201);
// std::cout << cindex1201 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0000);
// std::cout << cindex1201 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0001);
// std::cout << cindex1201 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0002);
// std::cout << cindex1201 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0010);
// std::cout << cindex1201 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0011);
// std::cout << cindex1201 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0012);
// std::cout << cindex1201 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0020);
// std::cout << cindex1201 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0021);
// std::cout << cindex1201 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1201,cindex0022);
// std::cout << cindex1201 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1202
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1202);
// std::cout << cindex1202 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0000);
// std::cout << cindex1202 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0001);
// std::cout << cindex1202 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0002);
// std::cout << cindex1202 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0010);
// std::cout << cindex1202 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0011);
// std::cout << cindex1202 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0012);
// std::cout << cindex1202 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0020);
// std::cout << cindex1202 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0021);
// std::cout << cindex1202 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1202,cindex0022);
// std::cout << cindex1202 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1210
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1210);
// std::cout << cindex1210 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0000);
// std::cout << cindex1210 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0001);
// std::cout << cindex1210 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0002);
// std::cout << cindex1210 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0010);
// std::cout << cindex1210 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0011);
// std::cout << cindex1210 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0012);
// std::cout << cindex1210 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0020);
// std::cout << cindex1210 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0021);
// std::cout << cindex1210 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1210,cindex0022);
// std::cout << cindex1210 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1211
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1211);
// std::cout << cindex1211 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0000);
// std::cout << cindex1211 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0001);
// std::cout << cindex1211 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0002);
// std::cout << cindex1211 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0010);
// std::cout << cindex1211 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0011);
// std::cout << cindex1211 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0012);
// std::cout << cindex1211 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0020);
// std::cout << cindex1211 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0021);
// std::cout << cindex1211 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1211,cindex0022);
// std::cout << cindex1211 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1212
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0012);
// std::cout << cindex0012 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0000);
// std::cout << cindex0012 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0001);
// std::cout << cindex0012 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0002);
// std::cout << cindex0012 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0010);
// std::cout << cindex0012 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0011);
// std::cout << cindex0012 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0012);
// std::cout << cindex0012 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0020);
// std::cout << cindex0012 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0021);
// std::cout << cindex0012 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0012,cindex0022);
// std::cout << cindex0012 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1220
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1220);
// std::cout << cindex1220 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0000);
// std::cout << cindex1220 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0001);
// std::cout << cindex1220 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0002);
// std::cout << cindex1220 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0010);
// std::cout << cindex1220 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0011);
// std::cout << cindex1220 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0012);
// std::cout << cindex1220 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0020);
// std::cout << cindex1220 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0021);
// std::cout << cindex1220 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1220,cindex0022);
// std::cout << cindex1220 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1221
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex1221);
// std::cout << cindex1221 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0000);
// std::cout << cindex1221 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0001);
// std::cout << cindex1221 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0002);
// std::cout << cindex1221 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0010);
// std::cout << cindex1221 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0011);
// std::cout << cindex1221 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0012);
// std::cout << cindex1221 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0020);
// std::cout << cindex1221 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0021);
// std::cout << cindex1221 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex1221,cindex0022);
// std::cout << cindex1221 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex1222
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0022);
// std::cout << cindex0022 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0000);
// std::cout << cindex0022 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0001);
// std::cout << cindex0022 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0002);
// std::cout << cindex0022 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0010);
// std::cout << cindex0022 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0011);
// std::cout << cindex0022 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0012);
// std::cout << cindex0022 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0020);
// std::cout << cindex0022 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0021);
// std::cout << cindex0022 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0022);
// std::cout << cindex0022 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2000
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2000);
// std::cout << cindex2000 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0000);
// std::cout << cindex2000 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0001);
// std::cout << cindex2000 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0002);
// std::cout << cindex2000 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0010);
// std::cout << cindex2000 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0011);
// std::cout << cindex2000 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0012);
// std::cout << cindex2000 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0020);
// std::cout << cindex2000 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0021);
// std::cout << cindex2000 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2000,cindex0022);
// std::cout << cindex2000 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2001
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2001);
// std::cout << cindex2001 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0000);
// std::cout << cindex2001 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0001);
// std::cout << cindex2001 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0002);
// std::cout << cindex2001 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0010);
// std::cout << cindex2001 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0011);
// std::cout << cindex2001 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0012);
// std::cout << cindex2001 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0020);
// std::cout << cindex2001 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0021);
// std::cout << cindex2001 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2001,cindex0022);
// std::cout << cindex2001 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2002
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2002);
// std::cout << cindex2002 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0000);
// std::cout << cindex2002 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0001);
// std::cout << cindex2002 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0002);
// std::cout << cindex2002 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0010);
// std::cout << cindex2002 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0011);
// std::cout << cindex2002 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0012);
// std::cout << cindex2002 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0020);
// std::cout << cindex2002 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0021);
// std::cout << cindex2002 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2002,cindex0022);
// std::cout << cindex2002 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2010
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2010);
// std::cout << cindex2010 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0000);
// std::cout << cindex2010 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0001);
// std::cout << cindex2010 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0002);
// std::cout << cindex2010 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0010);
// std::cout << cindex2010 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0011);
// std::cout << cindex2010 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0012);
// std::cout << cindex2010 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0020);
// std::cout << cindex2010 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0021);
// std::cout << cindex2010 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2010,cindex0022);
// std::cout << cindex2010 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2011
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2011);
// std::cout << cindex2011 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0000);
// std::cout << cindex2011 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0001);
// std::cout << cindex2011 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0002);
// std::cout << cindex2011 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0010);
// std::cout << cindex2011 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0011);
// std::cout << cindex2011 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0012);
// std::cout << cindex2011 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0020);
// std::cout << cindex2011 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0021);
// std::cout << cindex2011 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2011,cindex0022);
// std::cout << cindex2011 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2012
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2012);
// std::cout << cindex2012 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0000);
// std::cout << cindex2012 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0001);
// std::cout << cindex2012 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0002);
// std::cout << cindex2012 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0010);
// std::cout << cindex2012 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0011);
// std::cout << cindex2012 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0012);
// std::cout << cindex2012 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0020);
// std::cout << cindex2012 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0021);
// std::cout << cindex2012 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2012,cindex0022);
// std::cout << cindex2012 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2020
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2020);
// std::cout << cindex2020 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0000);
// std::cout << cindex2020 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0001);
// std::cout << cindex2020 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0002);
// std::cout << cindex2020 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0010);
// std::cout << cindex2020 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0011);
// std::cout << cindex2020 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0012);
// std::cout << cindex2020 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0020);
// std::cout << cindex2020 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0021);
// std::cout << cindex2020 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2020,cindex0022);
// std::cout << cindex2020 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2021
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2021);
// std::cout << cindex2021 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0000);
// std::cout << cindex2021 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0001);
// std::cout << cindex2021 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0002);
// std::cout << cindex2021 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0010);
// std::cout << cindex2021 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0011);
// std::cout << cindex2021 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0012);
// std::cout << cindex2021 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0020);
// std::cout << cindex2021 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0021);
// std::cout << cindex2021 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2021,cindex0022);
// std::cout << cindex2021 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2022
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0022);
// std::cout << cindex0022 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0000);
// std::cout << cindex0022 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0001);
// std::cout << cindex0022 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0002);
// std::cout << cindex0022 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0010);
// std::cout << cindex0022 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0011);
// std::cout << cindex0022 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0012);
// std::cout << cindex0022 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0020);
// std::cout << cindex0022 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0021);
// std::cout << cindex0022 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0022,cindex0022);
// std::cout << cindex0022 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2100
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2100);
// std::cout << cindex2100 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0000);
// std::cout << cindex2100 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0001);
// std::cout << cindex2100 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0002);
// std::cout << cindex2100 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0010);
// std::cout << cindex2100 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0011);
// std::cout << cindex2100 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0012);
// std::cout << cindex2100 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0020);
// std::cout << cindex2100 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0021);
// std::cout << cindex2100 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2100,cindex0022);
// std::cout << cindex2100 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2101
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2101);
// std::cout << cindex2101 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0000);
// std::cout << cindex2101 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0001);
// std::cout << cindex2101 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0002);
// std::cout << cindex2101 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0010);
// std::cout << cindex2101 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0011);
// std::cout << cindex2101 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0012);
// std::cout << cindex2101 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0020);
// std::cout << cindex2101 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0021);
// std::cout << cindex2101 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2101,cindex0022);
// std::cout << cindex2101 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2102
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2102);
// std::cout << cindex2102 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0000);
// std::cout << cindex2102 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0001);
// std::cout << cindex2102 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0002);
// std::cout << cindex2102 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0010);
// std::cout << cindex2102 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0011);
// std::cout << cindex2102 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0012);
// std::cout << cindex2102 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0020);
// std::cout << cindex2102 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0021);
// std::cout << cindex2102 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2102,cindex0022);
// std::cout << cindex2102 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2110
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2110);
// std::cout << cindex2110 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0000);
// std::cout << cindex2110 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0001);
// std::cout << cindex2110 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0002);
// std::cout << cindex2110 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0010);
// std::cout << cindex2110 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0011);
// std::cout << cindex2110 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0012);
// std::cout << cindex2110 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0020);
// std::cout << cindex2110 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0021);
// std::cout << cindex2110 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2110,cindex0022);
// std::cout << cindex2110 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2111
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2111);
// std::cout << cindex2111 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0000);
// std::cout << cindex2111 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0001);
// std::cout << cindex2111 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0002);
// std::cout << cindex2111 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0010);
// std::cout << cindex2111 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0011);
// std::cout << cindex2111 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0012);
// std::cout << cindex2111 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0020);
// std::cout << cindex2111 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0021);
// std::cout << cindex2111 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2111,cindex0022);
// std::cout << cindex2111 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2112
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2112);
// std::cout << cindex2112 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0000);
// std::cout << cindex2112 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0001);
// std::cout << cindex2112 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0002);
// std::cout << cindex2112 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0010);
// std::cout << cindex2112 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0011);
// std::cout << cindex2112 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0012);
// std::cout << cindex2112 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0020);
// std::cout << cindex2112 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0021);
// std::cout << cindex2112 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2112,cindex0022);
// std::cout << cindex2112 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2120
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2120);
// std::cout << cindex2120 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0000);
// std::cout << cindex2120 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0001);
// std::cout << cindex2120 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0002);
// std::cout << cindex2120 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0010);
// std::cout << cindex2120 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0011);
// std::cout << cindex2120 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0012);
// std::cout << cindex2120 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0020);
// std::cout << cindex2120 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0021);
// std::cout << cindex2120 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2120,cindex0022);
// std::cout << cindex2120 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2121
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2121);
// std::cout << cindex2121 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0000);
// std::cout << cindex2121 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0001);
// std::cout << cindex2121 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0002);
// std::cout << cindex2121 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0010);
// std::cout << cindex2121 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0011);
// std::cout << cindex2121 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0012);
// std::cout << cindex2121 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0020);
// std::cout << cindex2121 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0021);
// std::cout << cindex2121 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2121,cindex0022);
// std::cout << cindex2121 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2122
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2122);
// std::cout << cindex2122 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0000);
// std::cout << cindex2122 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0001);
// std::cout << cindex2122 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0002);
// std::cout << cindex2122 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0010);
// std::cout << cindex2122 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0011);
// std::cout << cindex2122 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0012);
// std::cout << cindex2122 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0020);
// std::cout << cindex2122 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0021);
// std::cout << cindex2122 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2122,cindex0022);
// std::cout << cindex2122 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2200
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex0000);
// std::cout << cindex0000 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0000);
// std::cout << cindex0000 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0001);
// std::cout << cindex0000 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0002);
// std::cout << cindex0000 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0010);
// std::cout << cindex0000 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0011);
// std::cout << cindex0000 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0012);
// std::cout << cindex0000 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0020);
// std::cout << cindex0000 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0021);
// std::cout << cindex0000 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex0000,cindex0022);
// std::cout << cindex0000 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2201
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2201);
// std::cout << cindex2201 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0000);
// std::cout << cindex2201 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0001);
// std::cout << cindex2201 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0002);
// std::cout << cindex2201 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0010);
// std::cout << cindex2201 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0011);
// std::cout << cindex2201 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0012);
// std::cout << cindex2201 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0020);
// std::cout << cindex2201 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0021);
// std::cout << cindex2201 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2201,cindex0022);
// std::cout << cindex2201 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2202
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2202);
// std::cout << cindex2202 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0000);
// std::cout << cindex2202 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0001);
// std::cout << cindex2202 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0002);
// std::cout << cindex2202 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0010);
// std::cout << cindex2202 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0011);
// std::cout << cindex2202 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0012);
// std::cout << cindex2202 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0020);
// std::cout << cindex2202 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0021);
// std::cout << cindex2202 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2202,cindex0022);
// std::cout << cindex2202 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2210
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2210);
// std::cout << cindex2210 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0000);
// std::cout << cindex2210 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0001);
// std::cout << cindex2210 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0002);
// std::cout << cindex2210 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0010);
// std::cout << cindex2210 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0011);
// std::cout << cindex2210 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0012);
// std::cout << cindex2210 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0020);
// std::cout << cindex2210 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0021);
// std::cout << cindex2210 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2210,cindex0022);
// std::cout << cindex2210 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2211
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2211);
// std::cout << cindex2211 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0000);
// std::cout << cindex2211 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0001);
// std::cout << cindex2211 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0002);
// std::cout << cindex2211 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0010);
// std::cout << cindex2211 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0011);
// std::cout << cindex2211 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0012);
// std::cout << cindex2211 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0020);
// std::cout << cindex2211 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0021);
// std::cout << cindex2211 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2211,cindex0022);
// std::cout << cindex2211 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2212
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2212);
// std::cout << cindex2212 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0000);
// std::cout << cindex2212 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0001);
// std::cout << cindex2212 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0002);
// std::cout << cindex2212 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0010);
// std::cout << cindex2212 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0011);
// std::cout << cindex2212 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0012);
// std::cout << cindex2212 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0020);
// std::cout << cindex2212 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0021);
// std::cout << cindex2212 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2212,cindex0022);
// std::cout << cindex2212 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2220
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2220);
// std::cout << cindex2220 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0000);
// std::cout << cindex2220 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0001);
// std::cout << cindex2220 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0002);
// std::cout << cindex2220 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0010);
// std::cout << cindex2220 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0011);
// std::cout << cindex2220 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0012);
// std::cout << cindex2220 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0020);
// std::cout << cindex2220 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0021);
// std::cout << cindex2220 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2220,cindex0022);
// std::cout << cindex2220 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2221
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2221);
// std::cout << cindex2221 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0000);
// std::cout << cindex2221 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0001);
// std::cout << cindex2221 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0002);
// std::cout << cindex2221 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0010);
// std::cout << cindex2221 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0011);
// std::cout << cindex2221 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0012);
// std::cout << cindex2221 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0020);
// std::cout << cindex2221 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0021);
// std::cout << cindex2221 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2221,cindex0022);
// std::cout << cindex2221 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//
// //// cindex2222
// indexXXXX_predicate = mpc::core::CComponentIndexHasAlias(cindex2222);
// std::cout << cindex2222 << " cindex has alias ? : " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0000);
// std::cout << cindex2222 << " is_alias " << cindex0000 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0001);
// std::cout << cindex2222 << " is_alias " << cindex0001 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0002);
// std::cout << cindex2222 << " is_alias " << cindex0002 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0010);
// std::cout << cindex2222 << " is_alias " << cindex0010 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0011);
// std::cout << cindex2222 << " is_alias " << cindex0011 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0012);
// std::cout << cindex2222 << " is_alias " << cindex0012 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0020);
// std::cout << cindex2222 << " is_alias " << cindex0020 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0021);
// std::cout << cindex2222 << " is_alias " << cindex0021 << " ? " << indexXXXX_predicate << std::endl;
// indexXXXX_predicate = mpc::core::CComponentIndexIsAlias(cindex2222,cindex0022);
// std::cout << cindex2222 << " is_alias " << cindex0022 << " ? " << indexXXXX_predicate << std::endl;
// // only first 9 tested
//



    // END


}
