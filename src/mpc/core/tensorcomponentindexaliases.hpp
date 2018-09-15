#ifndef MPC_TENSORCOMPONENTINDEXALIASES_H
#define MPC_TENSORCOMPONENTINDEXALIASES_H

#include <set>
#include <iterator>  // for std::advance<> : https://en.cppreference.com/w/cpp/iterator/advance

// mpc
#include "tensorcomponentindex.hpp"
#include "symmetrygrouptypes.hpp"


// NOTE: why the TensorRankNComponentIndex<N> form and not TensorRank2ComponentIndex?  Because the 
//     latter looks like a regular non-template class; we must remember that it is a specialized 
//     alias of the more general TensorRankNComponentIndex<N>()...

namespace mpc {
namespace core {
    
// =======================================================================================================
// =======================================================================================================
// ======================================================================================================= 

inline mpc::core::TensorRank2ComponentIndex ReducedTensorRank2ComponentIndex(const mpc::core::TensorRank2ComponentIndex& indexn) {
    const int i = indexn.FirstIndex();
    const int j = indexn.SecondIndex();
    return (i<j) ? mpc::core::TensorRank2ComponentIndex(i,j) : mpc::core::TensorRank2ComponentIndex(j,i);
}

// ==============================================================================================================================
// rank 4 are a bit different and we have to take into account the symmetry.  A component index can belong to a group of component index which extends the symmetry of triclinic sets...
template <typename S=NoneSymmetryGroupType>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex(const mpc::core::TensorRank4ComponentIndex& indexn) {
    static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
    // no reduction for none symmetry group type
    return mpc::core::TensorRank4ComponentIndex(indexn);
}

template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  03  04  05 |
     *  | 01  11  12  13  14  15 |
     *  | 02  12  22  23  24  25 |
     *  | 03  13  23  33  34  35 |
     *  | 04  14  24  34  44  45 |
     *  | 05  15  25  35  45  55 |
     */
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    //if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) { out = mpc::core::TensorRank4ComponentIndex(0,0,0,0); }
    
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] triclinic symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] triclinic symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] triclinic symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,1,0] triclinic symmetry reduced : [0,0,0,1]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] triclinic symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] triclinic symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,2,0] triclinic symmetry reduced : [0,0,0,2]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,2,1] triclinic symmetry reduced : [0,0,1,2]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] triclinic symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,1,0,0] triclinic symmetry reduced : [0,0,0,1]  
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] triclinic symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] triclinic symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] triclinic symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] triclinic symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] triclinic symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,2,0] triclinic symmetry reduced : [0,1,0,2]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,2,1] triclinic symmetry reduced : [0,1,1,2]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] triclinic symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,2,0,0] triclinic symmetry reduced : [0,0,0,2]  
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,2,0,1] triclinic symmetry reduced : [0,1,0,2]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] triclinic symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,2,1,0] triclinic symmetry reduced : [0,1,0,2]  
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] triclinic symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] triclinic symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] triclinic symmetry reduced : [0,2,0,2]  
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,2,1] triclinic symmetry reduced : [0,2,1,2]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] triclinic symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [1,0,0,0] triclinic symmetry reduced : [0,0,0,1]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] triclinic symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [1,0,0,2] triclinic symmetry reduced : [0,1,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] triclinic symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [1,0,1,1] triclinic symmetry reduced : [0,1,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,0,1,2] triclinic symmetry reduced : [0,1,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [1,0,2,0] triclinic symmetry reduced : [0,1,0,2]  
        case 1021: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,0,2,1] triclinic symmetry reduced : [0,1,1,2]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [1,0,2,2] triclinic symmetry reduced : [0,1,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] triclinic symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [1,1,0,1] triclinic symmetry reduced : [0,1,1,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [1,1,0,2] triclinic symmetry reduced : [0,2,1,1]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [1,1,1,0] triclinic symmetry reduced : [0,1,1,1]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(1,1,1,1);  }  // [1,1,1,1] triclinic symmetry reduced : [1,1,1,1]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] triclinic symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [1,1,2,0] triclinic symmetry reduced : [0,2,1,1]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,2,1] triclinic symmetry reduced : [1,1,1,2]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [1,1,2,2] triclinic symmetry reduced : [1,1,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,2,0,0] triclinic symmetry reduced : [0,0,1,2]  
        case 1201: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,2,0,1] triclinic symmetry reduced : [0,1,1,2]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [1,2,0,2] triclinic symmetry reduced : [0,2,1,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,2,1,0] triclinic symmetry reduced : [0,1,1,2]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,2,1,1] triclinic symmetry reduced : [1,1,1,2]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,1,2] triclinic symmetry reduced : [1,2,1,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [1,2,2,0] triclinic symmetry reduced : [0,2,1,2]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,2,1] triclinic symmetry reduced : [1,2,1,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] triclinic symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [2,0,0,0] triclinic symmetry reduced : [0,0,0,2]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [2,0,0,1] triclinic symmetry reduced : [0,1,0,2]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] triclinic symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [2,0,1,0] triclinic symmetry reduced : [0,1,0,2]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [2,0,1,1] triclinic symmetry reduced : [0,2,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,0,1,2] triclinic symmetry reduced : [0,2,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] triclinic symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,0,2,1] triclinic symmetry reduced : [0,2,1,2]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [2,0,2,2] triclinic symmetry reduced : [0,2,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,1,0,0] triclinic symmetry reduced : [0,0,1,2]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [2,1,0,1] triclinic symmetry reduced : [0,1,1,2]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,1,0,2] triclinic symmetry reduced : [0,2,1,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [2,1,1,0] triclinic symmetry reduced : [0,1,1,2]  
        case 2111: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [2,1,1,1] triclinic symmetry reduced : [1,1,1,2]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,1,2] triclinic symmetry reduced : [1,2,1,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,1,2,0] triclinic symmetry reduced : [0,2,1,2] 
        case 2121: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,2,1] triclinic symmetry reduced : [1,2,1,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [2,1,2,2] triclinic symmetry reduced : [1,2,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] triclinic symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [2,2,0,1] triclinic symmetry reduced : [0,1,2,2]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [2,2,0,2] triclinic symmetry reduced : [0,2,2,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [2,2,1,0] triclinic symmetry reduced : [0,1,2,2]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [2,2,1,1] triclinic symmetry reduced : [1,1,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [2,2,1,2] triclinic symmetry reduced : [1,2,2,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [2,2,2,0] triclinic symmetry reduced : [0,2,2,2]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [2,2,2,1] triclinic symmetry reduced : [1,2,2,2]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] triclinic symmetry reduced : [2,2,2,2]
    }
    
    return mpc::core::TensorRank4ComponentIndex(indexn);
}

template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    // NOTE: the algorithm is NOT optimized in the slightest; it was thrown together to get a working prototype... TODO: optimize later...
    /*
     *  | 00  01  02  --  04  -- |
     *  | 01  11  12  --  14  -- |
     *  | 02  12  22  --  24  -- |
     *  | --  --  --  33  --  35 |
     *  | 04  14  24  --  44  -- |
     *  | --  --  --  35  --  55 |
     */
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // no "groupings", e.g. no equivalent components beyond triclinic symmetry
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] monoclinicx2 symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] monoclinicx2 symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] monoclinicx2 symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] monoclinicx2 symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] monoclinicx2 symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] monoclinicx2 symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,2,0] monoclinicx2 symmetry reduced : [0,0,0,2]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] monoclinicx2 symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] monoclinicx2 symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] monoclinicx2 symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] monoclinicx2 symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] monoclinicx2 symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] monoclinicx2 symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] monoclinicx2 symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] monoclinicx2 symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,2,1] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] monoclinicx2 symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,2,0,0] monoclinicx2 symmetry reduced : [0,0,0,2]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] monoclinicx2 symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] monoclinicx2 symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] monoclinicx2 symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] monoclinicx2 symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] monoclinicx2 symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] monoclinicx2 symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] monoclinicx2 symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] monoclinicx2 symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] monoclinicx2 symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] monoclinicx2 symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] monoclinicx2 symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] monoclinicx2 symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] monoclinicx2 symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,0,1,2] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] monoclinicx2 symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,0,2,1] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] monoclinicx2 symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] monoclinicx2 symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] monoclinicx2 symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [1,1,0,2] monoclinicx2 symmetry reduced : [0,2,1,1]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] monoclinicx2 symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(1,1,1,1);  }  // [1,1,1,1] monoclinicx2 symmetry reduced : [1,1,1,1]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] monoclinicx2 symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [1,1,2,0] monoclinicx2 symmetry reduced : [0,2,1,1]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] monoclinicx2 symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [1,1,2,2] monoclinicx2 symmetry reduced : [1,1,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] monoclinicx2 symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,2,0,1] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] monoclinicx2 symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [1,2,1,0] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] monoclinicx2 symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,1,2] monoclinicx2 symmetry reduced : [1,2,1,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] monoclinicx2 symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,2,1] monoclinicx2 symmetry reduced : [1,2,1,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] monoclinicx2 symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [2,0,0,0] monoclinicx2 symmetry reduced : [0,0,0,2]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] monoclinicx2 symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] monoclinicx2 symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] monoclinicx2 symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [2,0,1,1] monoclinicx2 symmetry reduced : [0,2,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] monoclinicx2 symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] monoclinicx2 symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] monoclinicx2 symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [2,0,2,2] monoclinicx2 symmetry reduced : [0,2,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] monoclinicx2 symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [2,1,0,1] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] monoclinicx2 symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [2,1,1,0] monoclinicx2 symmetry reduced : [0,1,1,2]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] monoclinicx2 symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,1,2] monoclinicx2 symmetry reduced : [1,2,1,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] monoclinicx2 symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,2,1] monoclinicx2 symmetry reduced : [1,2,1,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] monoclinicx2 symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] monoclinicx2 symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] monoclinicx2 symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [2,2,0,2] monoclinicx2 symmetry reduced : [0,2,2,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] monoclinicx2 symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [2,2,1,1] monoclinicx2 symmetry reduced : [1,1,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] monoclinicx2 symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [2,2,2,0] monoclinicx2 symmetry reduced : [0,2,2,2]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] monoclinicx2 symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] monoclinicx2 symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}


template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  --  --  05 |
     *  | 01  11  12  --  --  15 |
     *  | 02  12  22  --  --  25 |
     *  | --  --  --  33  34  -- |
     *  | --  --  --  34  44  -- |
     *  | 05  15  25  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // no "groupings", e.g. no equivalent components beyond triclinic symmetry
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] monoclinicx3 symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] monoclinicx3 symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] monoclinicx3 symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,1,0] monoclinicx3 symmetry reduced : [0,0,0,1]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] monoclinicx3 symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] monoclinicx3 symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] monoclinicx3 symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] monoclinicx3 symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] monoclinicx3 symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,1,0,0] monoclinicx3 symmetry reduced : [0,0,0,1]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] monoclinicx3 symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] monoclinicx3 symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] monoclinicx3 symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] monoclinicx3 symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] monoclinicx3 symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] monoclinicx3 symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] monoclinicx3 symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] monoclinicx3 symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] monoclinicx3 symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] monoclinicx3 symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] monoclinicx3 symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] monoclinicx3 symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] monoclinicx3 symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] monoclinicx3 symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,2,1] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] monoclinicx3 symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [1,0,0,0] monoclinicx3 symmetry reduced : [0,0,0,1]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] monoclinicx3 symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] monoclinicx3 symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] monoclinicx3 symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [1,0,1,1] monoclinicx3 symmetry reduced : [0,1,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] monoclinicx3 symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] monoclinicx3 symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] monoclinicx3 symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [1,0,2,2] monoclinicx3 symmetry reduced : [0,1,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] monoclinicx3 symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [1,1,0,1] monoclinicx3 symmetry reduced : [0,1,1,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] monoclinicx3 symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [1,1,1,0] monoclinicx3 symmetry reduced : [0,1,1,1]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(1,1,1,1);  }  // [1,1,1,1] monoclinicx3 symmetry reduced : [1,1,1,1]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] monoclinicx3 symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] monoclinicx3 symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] monoclinicx3 symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [1,1,2,2] monoclinicx3 symmetry reduced : [1,1,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] monoclinicx3 symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] monoclinicx3 symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [1,2,0,2] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] monoclinicx3 symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] monoclinicx3 symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,1,2] monoclinicx3 symmetry reduced : [1,2,1,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [1,2,2,0] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,2,1] monoclinicx3 symmetry reduced : [1,2,1,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] monoclinicx3 symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] monoclinicx3 symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] monoclinicx3 symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] monoclinicx3 symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] monoclinicx3 symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] monoclinicx3 symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,0,1,2] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] monoclinicx3 symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,0,2,1] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] monoclinicx3 symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] monoclinicx3 symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] monoclinicx3 symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,1,0,2] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] monoclinicx3 symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] monoclinicx3 symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,1,2] monoclinicx3 symmetry reduced : [1,2,1,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [2,1,2,0] monoclinicx3 symmetry reduced : [0,2,1,2]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,2,1] monoclinicx3 symmetry reduced : [1,2,1,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] monoclinicx3 symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] monoclinicx3 symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [2,2,0,1] monoclinicx3 symmetry reduced : [0,1,2,2]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] monoclinicx3 symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [2,2,1,0] monoclinicx3 symmetry reduced : [0,1,2,2]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [2,2,1,1] monoclinicx3 symmetry reduced : [1,1,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] monoclinicx3 symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] monoclinicx3 symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] monoclinicx3 symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] monoclinicx3 symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}

template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  --  --  -- |
     *  | 01  11  12  --  --  -- |
     *  | 02  12  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  44  -- |
     *  | --  --  --  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // no "groupings", e.g. no equivalent components beyond triclinic symmetry
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] orthorhombic symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] orthorhombic symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] orthorhombic symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] orthorhombic symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] orthorhombic symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] orthorhombic symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] orthorhombic symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] orthorhombic symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] orthorhombic symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] orthorhombic symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] orthorhombic symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] orthorhombic symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] orthorhombic symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] orthorhombic symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] orthorhombic symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] orthorhombic symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] orthorhombic symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] orthorhombic symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] orthorhombic symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] orthorhombic symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] orthorhombic symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] orthorhombic symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] orthorhombic symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] orthorhombic symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] orthorhombic symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] orthorhombic symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] orthorhombic symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] orthorhombic symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] orthorhombic symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] orthorhombic symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] orthorhombic symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] orthorhombic symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] orthorhombic symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] orthorhombic symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] orthorhombic symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] orthorhombic symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] orthorhombic symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] orthorhombic symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] orthorhombic symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] orthorhombic symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(1,1,1,1);  }  // [1,1,1,1] orthorhombic symmetry reduced : [1,1,1,1]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] orthorhombic symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] orthorhombic symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] orthorhombic symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [1,1,2,2] orthorhombic symmetry reduced : [1,1,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] orthorhombic symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] orthorhombic symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] orthorhombic symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] orthorhombic symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] orthorhombic symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,1,2] orthorhombic symmetry reduced : [1,2,1,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] orthorhombic symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [1,2,2,1] orthorhombic symmetry reduced : [1,2,1,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] orthorhombic symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] orthorhombic symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] orthorhombic symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] orthorhombic symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] orthorhombic symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] orthorhombic symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] orthorhombic symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] orthorhombic symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] orthorhombic symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] orthorhombic symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] orthorhombic symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] orthorhombic symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] orthorhombic symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] orthorhombic symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] orthorhombic symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,1,2] orthorhombic symmetry reduced : [1,2,1,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] orthorhombic symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(1,2,1,2);  }  // [2,1,2,1] orthorhombic symmetry reduced : [1,2,1,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] orthorhombic symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] orthorhombic symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] orthorhombic symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] orthorhombic symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] orthorhombic symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(1,1,2,2);  }  // [2,2,1,1] orthorhombic symmetry reduced : [1,1,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] orthorhombic symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] orthorhombic symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] orthorhombic symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] orthorhombic symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  --  --  -- |
     *  | 01  00  02  --  --  -- |
     *  | 02  02  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | --  --  --  --  --  XX |
     * 
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // NOTE: Hexagonal reduced component indices are no different than that of VTI; the difference is in the values, specifically the relationship of the values among the indices
    // Groupings: {00,11}, {02,12}, {33,44}
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] hexagonal symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] hexagonal symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] hexagonal symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] hexagonal symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] hexagonal symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] hexagonal symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] hexagonal symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] hexagonal symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] hexagonal symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] hexagonal symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] hexagonal symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] hexagonal symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] hexagonal symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] hexagonal symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] hexagonal symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] hexagonal symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] hexagonal symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] hexagonal symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] hexagonal symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] hexagonal symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] hexagonal symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] hexagonal symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] hexagonal symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] hexagonal symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] hexagonal symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] hexagonal symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] hexagonal symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] hexagonal symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] hexagonal symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] hexagonal symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] hexagonal symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] hexagonal symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] hexagonal symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] hexagonal symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] hexagonal symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] hexagonal symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] hexagonal symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] hexagonal symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] hexagonal symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] hexagonal symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] hexagonal symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] hexagonal symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] hexagonal symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] hexagonal symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [1,1,2,2] hexagonal symmetry reduced : [0,0,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] hexagonal symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] hexagonal symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] hexagonal symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] hexagonal symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] hexagonal symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,1,2] hexagonal symmetry reduced : [0,2,0,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] hexagonal symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,2,1] hexagonal symmetry reduced : [0,2,0,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] hexagonal symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] hexagonal symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] hexagonal symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] hexagonal symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] hexagonal symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] hexagonal symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] hexagonal symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] hexagonal symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] hexagonal symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] hexagonal symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] hexagonal symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] hexagonal symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] hexagonal symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] hexagonal symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] hexagonal symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,1,2] hexagonal symmetry reduced : [0,2,0,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] hexagonal symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,2,1] hexagonal symmetry reduced : [0,2,0,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] hexagonal symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] hexagonal symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] hexagonal symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] hexagonal symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] hexagonal symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,1,1] hexagonal symmetry reduced : [0,0,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] hexagonal symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] hexagonal symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] hexagonal symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] hexagonal symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  --  --  05 |
     *  | 01  00  02  --  -- -05 |
     *  | 02  02  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | 05 -05  --  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // deterimine if the index belongs to the set of non-zero values,
    // Groupings: {00,11}, {02,12}, {33,44}, {05,15}
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] tetragonal7 symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] tetragonal7 symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] tetragonal7 symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,1,0] tetragonal7 symmetry reduced : [0,0,0,1]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] tetragonal7 symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] tetragonal7 symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] tetragonal7 symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] tetragonal7 symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] tetragonal7 symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,1,0,0] tetragonal7 symmetry reduced : [0,0,0,1]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] tetragonal7 symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] tetragonal7 symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] tetragonal7 symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,1,1,1] tetragonal7 symmetry reduced : [0,0,0,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] tetragonal7 symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] tetragonal7 symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] tetragonal7 symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] tetragonal7 symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] tetragonal7 symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] tetragonal7 symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] tetragonal7 symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] tetragonal7 symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] tetragonal7 symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] tetragonal7 symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] tetragonal7 symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] tetragonal7 symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] tetragonal7 symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [1,0,0,0] tetragonal7 symmetry reduced : [0,0,0,1]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] tetragonal7 symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] tetragonal7 symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] tetragonal7 symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [1,0,1,1] tetragonal7 symmetry reduced : [0,0,0,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] tetragonal7 symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] tetragonal7 symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] tetragonal7 symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] tetragonal7 symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] tetragonal7 symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [1,1,0,1] tetragonal7 symmetry reduced : [0,0,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] tetragonal7 symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [1,1,1,0] tetragonal7 symmetry reduced : [0,0,0,1]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] tetragonal7 symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] tetragonal7 symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] tetragonal7 symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] tetragonal7 symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [1,1,2,2] tetragonal7 symmetry reduced : [0,0,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] tetragonal7 symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] tetragonal7 symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] tetragonal7 symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] tetragonal7 symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] tetragonal7 symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,1,2] tetragonal7 symmetry reduced : [0,2,0,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] tetragonal7 symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,2,1] tetragonal7 symmetry reduced : [0,2,0,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] tetragonal7 symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] tetragonal7 symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] tetragonal7 symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] tetragonal7 symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] tetragonal7 symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] tetragonal7 symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] tetragonal7 symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] tetragonal7 symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] tetragonal7 symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] tetragonal7 symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] tetragonal7 symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] tetragonal7 symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] tetragonal7 symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] tetragonal7 symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] tetragonal7 symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,1,2] tetragonal7 symmetry reduced : [0,2,0,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] tetragonal7 symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,2,1] tetragonal7 symmetry reduced : [0,2,0,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] tetragonal7 symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] tetragonal7 symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] tetragonal7 symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] tetragonal7 symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] tetragonal7 symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,1,1] tetragonal7 symmetry reduced : [0,0,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] tetragonal7 symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] tetragonal7 symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] tetragonal7 symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] tetragonal7 symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  --  --  -- |
     *  | 01  00  02  --  --  -- |
     *  | 02  02  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | --  --  --  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // deterimine if the index belongs to the set of non-zero values,
    // Groupings: {00,11}, {02,12}, {33,44}
    // NOTE:  agian, identical to VTI or Hexagonal; the difference will be in the values... for tetragonal6 symmetry, no component can be derived from two or more other components
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] tetragonal6 symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] tetragonal6 symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] tetragonal6 symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] tetragonal6 symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] tetragonal6 symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] tetragonal6 symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] tetragonal6 symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] tetragonal6 symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] tetragonal6 symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] tetragonal6 symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] tetragonal6 symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] tetragonal6 symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] tetragonal6 symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] tetragonal6 symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] tetragonal6 symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] tetragonal6 symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] tetragonal6 symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] tetragonal6 symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] tetragonal6 symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] tetragonal6 symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] tetragonal6 symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] tetragonal6 symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] tetragonal6 symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] tetragonal6 symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] tetragonal6 symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] tetragonal6 symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] tetragonal6 symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] tetragonal6 symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] tetragonal6 symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] tetragonal6 symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] tetragonal6 symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] tetragonal6 symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] tetragonal6 symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] tetragonal6 symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] tetragonal6 symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] tetragonal6 symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] tetragonal6 symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] tetragonal6 symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] tetragonal6 symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] tetragonal6 symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] tetragonal6 symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] tetragonal6 symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] tetragonal6 symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] tetragonal6 symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [1,1,2,2] tetragonal6 symmetry reduced : [0,0,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] tetragonal6 symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] tetragonal6 symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] tetragonal6 symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] tetragonal6 symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] tetragonal6 symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,1,2] tetragonal6 symmetry reduced : [0,2,0,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] tetragonal6 symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,2,1] tetragonal6 symmetry reduced : [0,2,0,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] tetragonal6 symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] tetragonal6 symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] tetragonal6 symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] tetragonal6 symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] tetragonal6 symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] tetragonal6 symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] tetragonal6 symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] tetragonal6 symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] tetragonal6 symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] tetragonal6 symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] tetragonal6 symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] tetragonal6 symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] tetragonal6 symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] tetragonal6 symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] tetragonal6 symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,1,2] tetragonal6 symmetry reduced : [0,2,0,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] tetragonal6 symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,2,1] tetragonal6 symmetry reduced : [0,2,0,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] tetragonal6 symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] tetragonal6 symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] tetragonal6 symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] tetragonal6 symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] tetragonal6 symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,1,1] tetragonal6 symmetry reduced : [0,0,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] tetragonal6 symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] tetragonal6 symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] tetragonal6 symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] tetragonal6 symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  03 -04  -- |
     *  | 01  00  02 -03  04  -- |
     *  | 02  02  22  --  --  -- |
     *  | 03 -03  --  33  -- *04 |
     *  | 04  14  --  --  33 *03 |
     *  | --  --  -- *04 *03  XX |
     * 
     * where *NN is the numerical equal for C and twice the numerical equal for S; and
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     * 
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11}, {02,12}, {03,13,45}, {04,14,35}, {33,44}
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] trigonal7 symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] trigonal7 symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] trigonal7 symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] trigonal7 symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] trigonal7 symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] trigonal7 symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,2,0] trigonal7 symmetry reduced : [0,0,0,2]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,2,1] trigonal7 symmetry reduced : [0,0,1,2]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] trigonal7 symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] trigonal7 symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] trigonal7 symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,1,0,2] trigonal7 symmetry reduced : [0,0,1,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] trigonal7 symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] trigonal7 symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,1,1,2] trigonal7 symmetry reduced : [0,0,0,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,1,2,0] trigonal7 symmetry reduced : [0,0,1,2]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,1,2,1] trigonal7 symmetry reduced : [0,0,0,2]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] trigonal7 symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,2,0,0] trigonal7 symmetry reduced : [0,0,0,2]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,2,0,1] trigonal7 symmetry reduced : [0,0,1,2]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] trigonal7 symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,2,1,0] trigonal7 symmetry reduced : [0,0,1,2]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,2,1,1] trigonal7 symmetry reduced : [0,0,0,2]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] trigonal7 symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] trigonal7 symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] trigonal7 symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] trigonal7 symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] trigonal7 symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] trigonal7 symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,0,0,2] trigonal7 symmetry reduced : [0,0,1,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] trigonal7 symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] trigonal7 symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [1,0,1,2] trigonal7 symmetry reduced : [0,0,0,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,0,2,0] trigonal7 symmetry reduced : [0,0,1,2]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [1,0,2,1] trigonal7 symmetry reduced : [0,0,0,2]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] trigonal7 symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] trigonal7 symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] trigonal7 symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [1,1,0,2] trigonal7 symmetry reduced : [0,0,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] trigonal7 symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] trigonal7 symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,1,1,2] trigonal7 symmetry reduced : [0,0,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [1,1,2,0] trigonal7 symmetry reduced : [0,0,0,2]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,1,2,1] trigonal7 symmetry reduced : [0,0,1,2]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [1,1,2,2] trigonal7 symmetry reduced : [0,0,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,2,0,0] trigonal7 symmetry reduced : [0,0,1,2]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [1,2,0,1] trigonal7 symmetry reduced : [0,0,0,2]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] trigonal7 symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [1,2,1,0] trigonal7 symmetry reduced : [0,0,0,2]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,2,1,1] trigonal7 symmetry reduced : [0,0,1,2]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,1,2] trigonal7 symmetry reduced : [0,2,0,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] trigonal7 symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,2,1] trigonal7 symmetry reduced : [0,2,0,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] trigonal7 symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [2,0,0,0] trigonal7 symmetry reduced : [0,0,0,2]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,0,0,1] trigonal7 symmetry reduced : [0,0,1,2]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] trigonal7 symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,0,1,0] trigonal7 symmetry reduced : [0,0,1,2]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [2,0,1,1] trigonal7 symmetry reduced : [0,0,0,2]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] trigonal7 symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] trigonal7 symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] trigonal7 symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] trigonal7 symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,1,0,0] trigonal7 symmetry reduced : [0,0,1,2]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [2,1,0,1] trigonal7 symmetry reduced : [0,0,0,2]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] trigonal7 symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [2,1,1,0] trigonal7 symmetry reduced : [0,0,0,2]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,1,1,1] trigonal7 symmetry reduced : [0,0,1,2]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,1,2] trigonal7 symmetry reduced : [0,2,0,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] trigonal7 symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,2,1] trigonal7 symmetry reduced : [0,2,0,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] trigonal7 symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] trigonal7 symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] trigonal7 symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] trigonal7 symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] trigonal7 symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,1,1] trigonal7 symmetry reduced : [0,0,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] trigonal7 symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] trigonal7 symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] trigonal7 symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] trigonal7 symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  02  03  --  -- |
     *  | 01  00  02 -03  --  -- |
     *  | 02  02  22  --  --  -- |
     *  | 03 -03  --  33  --  -- |
     *  | --  --  --  --  33 *03 |
     *  | --  --  --  -- *03  XX |
     * 
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11}, {02,12}, {03,13,45}, {33,44}
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] trigonal6 symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] trigonal6 symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] trigonal6 symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] trigonal6 symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] trigonal6 symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] trigonal6 symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] trigonal6 symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,2,1] trigonal6 symmetry reduced : [0,0,1,2]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [0,0,2,2] trigonal6 symmetry reduced : [0,0,2,2]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] trigonal6 symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] trigonal6 symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,1,0,2] trigonal6 symmetry reduced : [0,0,1,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] trigonal6 symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] trigonal6 symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] trigonal6 symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,1,2,0] trigonal6 symmetry reduced : [0,0,1,2]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] trigonal6 symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] trigonal6 symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] trigonal6 symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,2,0,1] trigonal6 symmetry reduced : [0,0,1,2]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,0,2] trigonal6 symmetry reduced : [0,2,0,2]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,2,1,0] trigonal6 symmetry reduced : [0,0,1,2]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] trigonal6 symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] trigonal6 symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [0,2,2,0] trigonal6 symmetry reduced : [0,2,0,2]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] trigonal6 symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] trigonal6 symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] trigonal6 symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] trigonal6 symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,0,0,2] trigonal6 symmetry reduced : [0,0,1,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] trigonal6 symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] trigonal6 symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] trigonal6 symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,0,2,0] trigonal6 symmetry reduced : [0,0,1,2]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] trigonal6 symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] trigonal6 symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] trigonal6 symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] trigonal6 symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] trigonal6 symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] trigonal6 symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] trigonal6 symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,1,1,2] trigonal6 symmetry reduced : [0,0,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] trigonal6 symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,1,2,1] trigonal6 symmetry reduced : [0,0,1,2]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [1,1,2,2] trigonal6 symmetry reduced : [0,0,2,2]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,2,0,0] trigonal6 symmetry reduced : [0,0,1,2]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] trigonal6 symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] trigonal6 symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] trigonal6 symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [1,2,1,1] trigonal6 symmetry reduced : [0,0,1,2]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,1,2] trigonal6 symmetry reduced : [0,2,0,2]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] trigonal6 symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [1,2,2,1] trigonal6 symmetry reduced : [0,2,0,2]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] trigonal6 symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] trigonal6 symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,0,0,1] trigonal6 symmetry reduced : [0,0,1,2]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,0,2] trigonal6 symmetry reduced : [0,2,0,2]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,0,1,0] trigonal6 symmetry reduced : [0,0,1,2]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] trigonal6 symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] trigonal6 symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,0,2,0] trigonal6 symmetry reduced : [0,2,0,2]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] trigonal6 symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] trigonal6 symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,1,0,0] trigonal6 symmetry reduced : [0,0,1,2]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] trigonal6 symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] trigonal6 symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] trigonal6 symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [2,1,1,1] trigonal6 symmetry reduced : [0,0,1,2]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,1,2] trigonal6 symmetry reduced : [0,2,0,2]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] trigonal6 symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,2,0,2);  }  // [2,1,2,1] trigonal6 symmetry reduced : [0,2,0,2]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] trigonal6 symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,0,0] trigonal6 symmetry reduced : [0,0,2,2]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] trigonal6 symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] trigonal6 symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] trigonal6 symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,2,2);  }  // [2,2,1,1] trigonal6 symmetry reduced : [0,0,2,2]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] trigonal6 symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] trigonal6 symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] trigonal6 symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(2,2,2,2);  }  // [2,2,2,2] trigonal6 symmetry reduced : [2,2,2,2]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  01  --  --  -- |
     *  | 01  00  01  --  --  -- |
     *  | 01  01  00  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | --  --  --  --  --  33 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11,22}, {01,02,12}, {33,44,55}
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] cubic symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] cubic symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] cubic symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] cubic symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] cubic symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] cubic symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] cubic symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] cubic symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,2,2] cubic symmetry reduced : [0,0,1,1]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] cubic symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] cubic symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] cubic symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] cubic symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] cubic symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] cubic symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] cubic symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] cubic symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] cubic symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] cubic symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] cubic symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,2,0,2] cubic symmetry reduced : [0,1,0,1]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] cubic symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] cubic symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] cubic symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,2,2,0] cubic symmetry reduced : [0,1,0,1]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] cubic symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] cubic symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] cubic symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] cubic symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] cubic symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] cubic symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] cubic symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] cubic symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] cubic symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] cubic symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] cubic symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] cubic symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] cubic symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] cubic symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] cubic symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] cubic symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] cubic symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] cubic symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] cubic symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,2,2] cubic symmetry reduced : [0,0,1,1]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] cubic symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] cubic symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] cubic symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] cubic symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] cubic symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,2,1,2] cubic symmetry reduced : [0,1,0,1]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] cubic symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,2,2,1] cubic symmetry reduced : [0,1,0,1]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] cubic symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] cubic symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] cubic symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,0,0,2] cubic symmetry reduced : [0,1,0,1]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] cubic symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] cubic symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] cubic symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,0,2,0] cubic symmetry reduced : [0,1,0,1]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] cubic symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] cubic symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] cubic symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] cubic symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] cubic symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] cubic symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] cubic symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,1,1,2] cubic symmetry reduced : [0,1,0,1]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] cubic symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,1,2,1] cubic symmetry reduced : [0,1,0,1]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] cubic symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [2,2,0,0] cubic symmetry reduced : [0,0,1,1]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] cubic symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] cubic symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] cubic symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [2,2,1,1] cubic symmetry reduced : [0,0,1,1]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] cubic symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] cubic symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] cubic symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [2,2,2,2] cubic symmetry reduced : [0,0,0,0]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
template <>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(const mpc::core::TensorRank4ComponentIndex& indexn) {
    /*
     *  | 00  01  01  --  --  -- |
     *  | 01  00  01  --  --  -- |
     *  | 01  01  00  --  --  -- |
     *  | --  --  --  XX  --  -- |
     *  | --  --  --  --  XX  -- |
     *  | --  --  --  --  --  XX |
     * 
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // NOTE: isotropic is identical to cubic in terms of component groupings; the difference comes from the relationship of the values between component indices
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [0,0,0,0] isotropic symmetry reduced : [0,0,0,0]
        case 1: { return mpc::core::TensorRank4ComponentIndex(0,0,0,1);  }  // [0,0,0,1] isotropic symmetry reduced : [0,0,0,1]
        case 2: { return mpc::core::TensorRank4ComponentIndex(0,0,0,2);  }  // [0,0,0,2] isotropic symmetry reduced : [0,0,0,2]
        case 10: { return mpc::core::TensorRank4ComponentIndex(0,0,1,0);  }  // [0,0,1,0] isotropic symmetry reduced : [0,0,1,0]
        case 11: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,1,1] isotropic symmetry reduced : [0,0,1,1]
        case 12: { return mpc::core::TensorRank4ComponentIndex(0,0,1,2);  }  // [0,0,1,2] isotropic symmetry reduced : [0,0,1,2]
        case 20: { return mpc::core::TensorRank4ComponentIndex(0,0,2,0);  }  // [0,0,2,0] isotropic symmetry reduced : [0,0,2,0]
        case 21: { return mpc::core::TensorRank4ComponentIndex(0,0,2,1);  }  // [0,0,2,1] isotropic symmetry reduced : [0,0,2,1]
        case 22: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [0,0,2,2] isotropic symmetry reduced : [0,0,1,1]
        case 100: { return mpc::core::TensorRank4ComponentIndex(0,1,0,0);  }  // [0,1,0,0] isotropic symmetry reduced : [0,1,0,0]
        case 101: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,0,1] isotropic symmetry reduced : [0,1,0,1]
        case 102: { return mpc::core::TensorRank4ComponentIndex(0,1,0,2);  }  // [0,1,0,2] isotropic symmetry reduced : [0,1,0,2]
        case 110: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,1,1,0] isotropic symmetry reduced : [0,1,0,1]
        case 111: { return mpc::core::TensorRank4ComponentIndex(0,1,1,1);  }  // [0,1,1,1] isotropic symmetry reduced : [0,1,1,1]
        case 112: { return mpc::core::TensorRank4ComponentIndex(0,1,1,2);  }  // [0,1,1,2] isotropic symmetry reduced : [0,1,1,2]
        case 120: { return mpc::core::TensorRank4ComponentIndex(0,1,2,0);  }  // [0,1,2,0] isotropic symmetry reduced : [0,1,2,0]
        case 121: { return mpc::core::TensorRank4ComponentIndex(0,1,2,1);  }  // [0,1,2,1] isotropic symmetry reduced : [0,1,2,1]
        case 122: { return mpc::core::TensorRank4ComponentIndex(0,1,2,2);  }  // [0,1,2,2] isotropic symmetry reduced : [0,1,2,2]
        case 200: { return mpc::core::TensorRank4ComponentIndex(0,2,0,0);  }  // [0,2,0,0] isotropic symmetry reduced : [0,2,0,0]
        case 201: { return mpc::core::TensorRank4ComponentIndex(0,2,0,1);  }  // [0,2,0,1] isotropic symmetry reduced : [0,2,0,1]
        case 202: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,2,0,2] isotropic symmetry reduced : [0,1,0,1]
        case 210: { return mpc::core::TensorRank4ComponentIndex(0,2,1,0);  }  // [0,2,1,0] isotropic symmetry reduced : [0,2,1,0]
        case 211: { return mpc::core::TensorRank4ComponentIndex(0,2,1,1);  }  // [0,2,1,1] isotropic symmetry reduced : [0,2,1,1]
        case 212: { return mpc::core::TensorRank4ComponentIndex(0,2,1,2);  }  // [0,2,1,2] isotropic symmetry reduced : [0,2,1,2]
        case 220: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [0,2,2,0] isotropic symmetry reduced : [0,1,0,1]
        case 221: { return mpc::core::TensorRank4ComponentIndex(0,2,2,1);  }  // [0,2,2,1] isotropic symmetry reduced : [0,2,2,1]
        case 222: { return mpc::core::TensorRank4ComponentIndex(0,2,2,2);  }  // [0,2,2,2] isotropic symmetry reduced : [0,2,2,2]
        case 1000: { return mpc::core::TensorRank4ComponentIndex(1,0,0,0);  }  // [1,0,0,0] isotropic symmetry reduced : [1,0,0,0]
        case 1001: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,0,1] isotropic symmetry reduced : [0,1,0,1]
        case 1002: { return mpc::core::TensorRank4ComponentIndex(1,0,0,2);  }  // [1,0,0,2] isotropic symmetry reduced : [1,0,0,2]
        case 1010: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,0,1,0] isotropic symmetry reduced : [0,1,0,1]
        case 1011: { return mpc::core::TensorRank4ComponentIndex(1,0,1,1);  }  // [1,0,1,1] isotropic symmetry reduced : [1,0,1,1]
        case 1012: { return mpc::core::TensorRank4ComponentIndex(1,0,1,2);  }  // [1,0,1,2] isotropic symmetry reduced : [1,0,1,2]
        case 1020: { return mpc::core::TensorRank4ComponentIndex(1,0,2,0);  }  // [1,0,2,0] isotropic symmetry reduced : [1,0,2,0]
        case 1021: { return mpc::core::TensorRank4ComponentIndex(1,0,2,1);  }  // [1,0,2,1] isotropic symmetry reduced : [1,0,2,1]
        case 1022: { return mpc::core::TensorRank4ComponentIndex(1,0,2,2);  }  // [1,0,2,2] isotropic symmetry reduced : [1,0,2,2]
        case 1100: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,0,0] isotropic symmetry reduced : [0,0,1,1]
        case 1101: { return mpc::core::TensorRank4ComponentIndex(1,1,0,1);  }  // [1,1,0,1] isotropic symmetry reduced : [1,1,0,1]
        case 1102: { return mpc::core::TensorRank4ComponentIndex(1,1,0,2);  }  // [1,1,0,2] isotropic symmetry reduced : [1,1,0,2]
        case 1110: { return mpc::core::TensorRank4ComponentIndex(1,1,1,0);  }  // [1,1,1,0] isotropic symmetry reduced : [1,1,1,0]
        case 1111: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [1,1,1,1] isotropic symmetry reduced : [0,0,0,0]
        case 1112: { return mpc::core::TensorRank4ComponentIndex(1,1,1,2);  }  // [1,1,1,2] isotropic symmetry reduced : [1,1,1,2]
        case 1120: { return mpc::core::TensorRank4ComponentIndex(1,1,2,0);  }  // [1,1,2,0] isotropic symmetry reduced : [1,1,2,0]
        case 1121: { return mpc::core::TensorRank4ComponentIndex(1,1,2,1);  }  // [1,1,2,1] isotropic symmetry reduced : [1,1,2,1]
        case 1122: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [1,1,2,2] isotropic symmetry reduced : [0,0,1,1]
        case 1200: { return mpc::core::TensorRank4ComponentIndex(1,2,0,0);  }  // [1,2,0,0] isotropic symmetry reduced : [1,2,0,0]
        case 1201: { return mpc::core::TensorRank4ComponentIndex(1,2,0,1);  }  // [1,2,0,1] isotropic symmetry reduced : [1,2,0,1]
        case 1202: { return mpc::core::TensorRank4ComponentIndex(1,2,0,2);  }  // [1,2,0,2] isotropic symmetry reduced : [1,2,0,2]
        case 1210: { return mpc::core::TensorRank4ComponentIndex(1,2,1,0);  }  // [1,2,1,0] isotropic symmetry reduced : [1,2,1,0]
        case 1211: { return mpc::core::TensorRank4ComponentIndex(1,2,1,1);  }  // [1,2,1,1] isotropic symmetry reduced : [1,2,1,1]
        case 1212: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,2,1,2] isotropic symmetry reduced : [0,1,0,1]
        case 1220: { return mpc::core::TensorRank4ComponentIndex(1,2,2,0);  }  // [1,2,2,0] isotropic symmetry reduced : [1,2,2,0]
        case 1221: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [1,2,2,1] isotropic symmetry reduced : [0,1,0,1]
        case 1222: { return mpc::core::TensorRank4ComponentIndex(1,2,2,2);  }  // [1,2,2,2] isotropic symmetry reduced : [1,2,2,2]
        case 2000: { return mpc::core::TensorRank4ComponentIndex(2,0,0,0);  }  // [2,0,0,0] isotropic symmetry reduced : [2,0,0,0]
        case 2001: { return mpc::core::TensorRank4ComponentIndex(2,0,0,1);  }  // [2,0,0,1] isotropic symmetry reduced : [2,0,0,1]
        case 2002: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,0,0,2] isotropic symmetry reduced : [0,1,0,1]
        case 2010: { return mpc::core::TensorRank4ComponentIndex(2,0,1,0);  }  // [2,0,1,0] isotropic symmetry reduced : [2,0,1,0]
        case 2011: { return mpc::core::TensorRank4ComponentIndex(2,0,1,1);  }  // [2,0,1,1] isotropic symmetry reduced : [2,0,1,1]
        case 2012: { return mpc::core::TensorRank4ComponentIndex(2,0,1,2);  }  // [2,0,1,2] isotropic symmetry reduced : [2,0,1,2]
        case 2020: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,0,2,0] isotropic symmetry reduced : [0,1,0,1]
        case 2021: { return mpc::core::TensorRank4ComponentIndex(2,0,2,1);  }  // [2,0,2,1] isotropic symmetry reduced : [2,0,2,1]
        case 2022: { return mpc::core::TensorRank4ComponentIndex(2,0,2,2);  }  // [2,0,2,2] isotropic symmetry reduced : [2,0,2,2]
        case 2100: { return mpc::core::TensorRank4ComponentIndex(2,1,0,0);  }  // [2,1,0,0] isotropic symmetry reduced : [2,1,0,0]
        case 2101: { return mpc::core::TensorRank4ComponentIndex(2,1,0,1);  }  // [2,1,0,1] isotropic symmetry reduced : [2,1,0,1]
        case 2102: { return mpc::core::TensorRank4ComponentIndex(2,1,0,2);  }  // [2,1,0,2] isotropic symmetry reduced : [2,1,0,2]
        case 2110: { return mpc::core::TensorRank4ComponentIndex(2,1,1,0);  }  // [2,1,1,0] isotropic symmetry reduced : [2,1,1,0]
        case 2111: { return mpc::core::TensorRank4ComponentIndex(2,1,1,1);  }  // [2,1,1,1] isotropic symmetry reduced : [2,1,1,1]
        case 2112: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,1,1,2] isotropic symmetry reduced : [0,1,0,1]
        case 2120: { return mpc::core::TensorRank4ComponentIndex(2,1,2,0);  }  // [2,1,2,0] isotropic symmetry reduced : [2,1,2,0]
        case 2121: { return mpc::core::TensorRank4ComponentIndex(0,1,0,1);  }  // [2,1,2,1] isotropic symmetry reduced : [0,1,0,1]
        case 2122: { return mpc::core::TensorRank4ComponentIndex(2,1,2,2);  }  // [2,1,2,2] isotropic symmetry reduced : [2,1,2,2]
        case 2200: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [2,2,0,0] isotropic symmetry reduced : [0,0,1,1]
        case 2201: { return mpc::core::TensorRank4ComponentIndex(2,2,0,1);  }  // [2,2,0,1] isotropic symmetry reduced : [2,2,0,1]
        case 2202: { return mpc::core::TensorRank4ComponentIndex(2,2,0,2);  }  // [2,2,0,2] isotropic symmetry reduced : [2,2,0,2]
        case 2210: { return mpc::core::TensorRank4ComponentIndex(2,2,1,0);  }  // [2,2,1,0] isotropic symmetry reduced : [2,2,1,0]
        case 2211: { return mpc::core::TensorRank4ComponentIndex(0,0,1,1);  }  // [2,2,1,1] isotropic symmetry reduced : [0,0,1,1]
        case 2212: { return mpc::core::TensorRank4ComponentIndex(2,2,1,2);  }  // [2,2,1,2] isotropic symmetry reduced : [2,2,1,2]
        case 2220: { return mpc::core::TensorRank4ComponentIndex(2,2,2,0);  }  // [2,2,2,0] isotropic symmetry reduced : [2,2,2,0]
        case 2221: { return mpc::core::TensorRank4ComponentIndex(2,2,2,1);  }  // [2,2,2,1] isotropic symmetry reduced : [2,2,2,1]
        case 2222: { return mpc::core::TensorRank4ComponentIndex(0,0,0,0);  }  // [2,2,2,2] isotropic symmetry reduced : [0,0,0,0]
    }
    return mpc::core::TensorRank4ComponentIndex(indexn);
}
 
 
 
 
// poymorphic version for matrix notation
template <typename S=NoneSymmetryGroupType>
inline mpc::core::TensorRank4ComponentIndex ReducedTensorRank4ComponentIndex(const mpc::core::TensorRank2ComponentIndex& indexn) {
    static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
    // get the indices for the fourth rank tensor from the matrix notation; note this makes no sense if the tensor is of none symmetry group type; matrix notation implies symmetry
    const int index_p = indexn.FirstIndex();
    const int index_q = indexn.SecondIndex();
    
    std::pair<int,int> p_indices = mpc::util::GetIndexFromVoigtMatrix(index_p);
    std::pair<int,int> q_indices = mpc::util::GetIndexFromVoigtMatrix(index_q);
    
    // call the specialized ReducedTensorRank4ComponentIndex<S>(..) function for rank 4 component index; no need to repeat specialization for polymorhic function
    mpc::core::TensorRank4ComponentIndex tmp = ReducedTensorRank4ComponentIndex<S>(mpc::core::TensorRank4ComponentIndex(p_indices.first, p_indices.second, q_indices.first, q_indices.second));
    
    return tmp;
}



//================================================================================================================================
//================================================================================================================================
//================================================================================================================================

// where tensors of rank 2 here are assumed to be symmetric, i.e. A(i,j) = A(j,i).
constexpr inline int TensorRank2IndexNumberOfAliases(const mpc::core::TensorRankNComponentIndex<2>& indexn) {
    // returns the number of aliases for the index
    return (indexn.FirstIndex() == indexn.SecondIndex()) ? 1 : 2;
}



/* tensor rank 4 */
template <typename S=mpc::core::NoneSymmetryGroupType>
inline int TensorRank4IndexNumberOfAliases(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
    static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::TriclinicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    // returns the number of aliases for the index
    int p = mpc::util::GetVoigtMatrixIndex(indexn.FirstIndex(),indexn.SecondIndex());
    int q = mpc::util::GetVoigtMatrixIndex(indexn.ThirdIndex(),indexn.FourthIndex());

    assert(p>=0);
    assert(p<6);
    assert(q>=0);
    assert(q<6);

    std::set<int> set012{0,1,2};
    std::set<int> set345{3,4,5};
    const bool p_is_in_012 = set012.find(p) != set012.end();
    const bool q_is_in_012 = set012.find(q) != set012.end();
    const bool p_is_in_345 = set345.find(p) != set345.end();
    const bool q_is_in_345 = set345.find(q) != set345.end();

    if (p_is_in_012 && q_is_in_012 && p==q) { return 1; }                            // (0,0) (1,1) (2,2)
    if (p_is_in_345 && q_is_in_345 && p==q) { return 4; }                            // (3,3) (4,4) (5,5)
    if (p_is_in_012 && q_is_in_012) { return 2; }                              // p!=q  (0,1) (1,0) (0,2) (2,0) (1,2) (2,1)
    if ((p_is_in_345 && q_is_in_012) || (q_is_in_345 && p_is_in_012)) { return 4; }  // (3,0) (4,0) (5,0) (3,1) (4,1) (5,1) (3,2) (4,2) (5,2) 
    return 8; 
}


template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX2SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
    // === monoclinicx2 aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 1;  }  // [0,0,0,0] alias_counter : 1
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 4;  }  // [0,0,0,2] alias_counter : 4
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 4;  }  // [0,0,2,0] alias_counter : 4
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 2;  }  // [0,0,2,2] alias_counter : 2
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 8;  }  // [0,1,1,2] alias_counter : 8
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 8;  }  // [0,1,2,1] alias_counter : 8
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 4;  }  // [0,2,0,0] alias_counter : 4
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 4;  }  // [0,2,0,2] alias_counter : 4
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 4;  }  // [0,2,1,1] alias_counter : 4
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 4;  }  // [0,2,2,0] alias_counter : 4
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 4;  }  // [0,2,2,2] alias_counter : 4
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 8;  }  // [1,0,1,2] alias_counter : 8
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 8;  }  // [1,0,2,1] alias_counter : 8
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 4;  }  // [1,1,0,2] alias_counter : 4
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 1;  }  // [1,1,1,1] alias_counter : 1
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 4;  }  // [1,1,2,0] alias_counter : 4
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 2;  }  // [1,1,2,2] alias_counter : 2
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 8;  }  // [1,2,0,1] alias_counter : 8
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 8;  }  // [1,2,1,0] alias_counter : 8
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 4;  }  // [1,2,1,2] alias_counter : 4
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 4;  }  // [1,2,2,1] alias_counter : 4
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 4;  }  // [2,0,0,0] alias_counter : 4
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 4;  }  // [2,0,0,2] alias_counter : 4
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 4;  }  // [2,0,1,1] alias_counter : 4
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 4;  }  // [2,0,2,0] alias_counter : 4
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 4;  }  // [2,0,2,2] alias_counter : 4
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 8;  }  // [2,1,0,1] alias_counter : 8
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 8;  }  // [2,1,1,0] alias_counter : 8
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 4;  }  // [2,1,1,2] alias_counter : 4
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 4;  }  // [2,1,2,1] alias_counter : 4
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 2;  }  // [2,2,0,0] alias_counter : 2
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 4;  }  // [2,2,0,2] alias_counter : 4
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 2;  }  // [2,2,1,1] alias_counter : 2
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 4;  }  // [2,2,2,0] alias_counter : 4
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX3SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
    // === monoclinicx3 aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 1;  }  // [0,0,0,0] alias_counter : 1
        case 1: { return 4;  }  // [0,0,0,1] alias_counter : 4
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 4;  }  // [0,0,1,0] alias_counter : 4
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 2;  }  // [0,0,2,2] alias_counter : 2
        case 100: { return 4;  }  // [0,1,0,0] alias_counter : 4
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 4;  }  // [0,1,1,1] alias_counter : 4
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 4;  }  // [0,1,2,2] alias_counter : 4
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 4;  }  // [0,2,0,2] alias_counter : 4
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 8;  }  // [0,2,1,2] alias_counter : 8
        case 220: { return 4;  }  // [0,2,2,0] alias_counter : 4
        case 221: { return 8;  }  // [0,2,2,1] alias_counter : 8
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 4;  }  // [1,0,0,0] alias_counter : 4
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 4;  }  // [1,0,1,1] alias_counter : 4
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 4;  }  // [1,0,2,2] alias_counter : 4
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 4;  }  // [1,1,0,1] alias_counter : 4
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 4;  }  // [1,1,1,0] alias_counter : 4
        case 1111: { return 1;  }  // [1,1,1,1] alias_counter : 1
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 2;  }  // [1,1,2,2] alias_counter : 2
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 8;  }  // [1,2,0,2] alias_counter : 8
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 4;  }  // [1,2,1,2] alias_counter : 4
        case 1220: { return 8;  }  // [1,2,2,0] alias_counter : 8
        case 1221: { return 4;  }  // [1,2,2,1] alias_counter : 4
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 4;  }  // [2,0,0,2] alias_counter : 4
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 8;  }  // [2,0,1,2] alias_counter : 8
        case 2020: { return 4;  }  // [2,0,2,0] alias_counter : 4
        case 2021: { return 8;  }  // [2,0,2,1] alias_counter : 8
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 8;  }  // [2,1,0,2] alias_counter : 8
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 4;  }  // [2,1,1,2] alias_counter : 4
        case 2120: { return 8;  }  // [2,1,2,0] alias_counter : 8
        case 2121: { return 4;  }  // [2,1,2,1] alias_counter : 4
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 2;  }  // [2,2,0,0] alias_counter : 2
        case 2201: { return 4;  }  // [2,2,0,1] alias_counter : 4
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 4;  }  // [2,2,1,0] alias_counter : 4
        case 2211: { return 2;  }  // [2,2,1,1] alias_counter : 2
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::OrthorhombicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === orthorhombic aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 1;  }  // [0,0,0,0] alias_counter : 1
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 2;  }  // [0,0,2,2] alias_counter : 2
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 4;  }  // [0,2,0,2] alias_counter : 4
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 4;  }  // [0,2,2,0] alias_counter : 4
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 1;  }  // [1,1,1,1] alias_counter : 1
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 2;  }  // [1,1,2,2] alias_counter : 2
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 4;  }  // [1,2,1,2] alias_counter : 4
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 4;  }  // [1,2,2,1] alias_counter : 4
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 4;  }  // [2,0,0,2] alias_counter : 4
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 4;  }  // [2,0,2,0] alias_counter : 4
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 4;  }  // [2,1,1,2] alias_counter : 4
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 4;  }  // [2,1,2,1] alias_counter : 4
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 2;  }  // [2,2,0,0] alias_counter : 2
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 2;  }  // [2,2,1,1] alias_counter : 2
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::HexagonalSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === hexagonal aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 2;  }  // [0,0,0,0] alias_counter : 2
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 4;  }  // [0,0,2,2] alias_counter : 4
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 8;  }  // [0,2,0,2] alias_counter : 8
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 8;  }  // [0,2,2,0] alias_counter : 8
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 2;  }  // [1,1,1,1] alias_counter : 2
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 4;  }  // [1,1,2,2] alias_counter : 4
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 8;  }  // [1,2,1,2] alias_counter : 8
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 8;  }  // [1,2,2,1] alias_counter : 8
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 8;  }  // [2,0,0,2] alias_counter : 8
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 8;  }  // [2,0,2,0] alias_counter : 8
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 8;  }  // [2,1,1,2] alias_counter : 8
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 8;  }  // [2,1,2,1] alias_counter : 8
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 4;  }  // [2,2,0,0] alias_counter : 4
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 4;  }  // [2,2,1,1] alias_counter : 4
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal7SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === tetragonal7 aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 2;  }  // [0,0,0,0] alias_counter : 2
        case 1: { return 8;  }  // [0,0,0,1] alias_counter : 8
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 8;  }  // [0,0,1,0] alias_counter : 8
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 4;  }  // [0,0,2,2] alias_counter : 4
        case 100: { return 8;  }  // [0,1,0,0] alias_counter : 8
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 8;  }  // [0,1,1,1] alias_counter : 8
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 8;  }  // [0,2,0,2] alias_counter : 8
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 8;  }  // [0,2,2,0] alias_counter : 8
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 8;  }  // [1,0,0,0] alias_counter : 8
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 8;  }  // [1,0,1,1] alias_counter : 8
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 8;  }  // [1,1,0,1] alias_counter : 8
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 8;  }  // [1,1,1,0] alias_counter : 8
        case 1111: { return 2;  }  // [1,1,1,1] alias_counter : 2
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 4;  }  // [1,1,2,2] alias_counter : 4
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 8;  }  // [1,2,1,2] alias_counter : 8
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 8;  }  // [1,2,2,1] alias_counter : 8
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 8;  }  // [2,0,0,2] alias_counter : 8
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 8;  }  // [2,0,2,0] alias_counter : 8
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 8;  }  // [2,1,1,2] alias_counter : 8
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 8;  }  // [2,1,2,1] alias_counter : 8
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 4;  }  // [2,2,0,0] alias_counter : 4
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 4;  }  // [2,2,1,1] alias_counter : 4
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal6SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === tetragonal6 aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 2;  }  // [0,0,0,0] alias_counter : 2
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 4;  }  // [0,0,2,2] alias_counter : 4
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 8;  }  // [0,2,0,2] alias_counter : 8
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 8;  }  // [0,2,2,0] alias_counter : 8
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 2;  }  // [1,1,1,1] alias_counter : 2
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 4;  }  // [1,1,2,2] alias_counter : 4
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 8;  }  // [1,2,1,2] alias_counter : 8
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 8;  }  // [1,2,2,1] alias_counter : 8
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 8;  }  // [2,0,0,2] alias_counter : 8
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 8;  }  // [2,0,2,0] alias_counter : 8
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 8;  }  // [2,1,1,2] alias_counter : 8
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 8;  }  // [2,1,2,1] alias_counter : 8
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 4;  }  // [2,2,0,0] alias_counter : 4
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 4;  }  // [2,2,1,1] alias_counter : 4
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::Trigonal7SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === trigonal7 aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 2;  }  // [0,0,0,0] alias_counter : 2
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 16;  }  // [0,0,0,2] alias_counter : 16
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 16;  }  // [0,0,1,2] alias_counter : 16
        case 20: { return 16;  }  // [0,0,2,0] alias_counter : 16
        case 21: { return 16;  }  // [0,0,2,1] alias_counter : 16
        case 22: { return 4;  }  // [0,0,2,2] alias_counter : 4
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 16;  }  // [0,1,0,2] alias_counter : 16
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 16;  }  // [0,1,1,2] alias_counter : 16
        case 120: { return 16;  }  // [0,1,2,0] alias_counter : 16
        case 121: { return 16;  }  // [0,1,2,1] alias_counter : 16
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 16;  }  // [0,2,0,0] alias_counter : 16
        case 201: { return 16;  }  // [0,2,0,1] alias_counter : 16
        case 202: { return 8;  }  // [0,2,0,2] alias_counter : 8
        case 210: { return 16;  }  // [0,2,1,0] alias_counter : 16
        case 211: { return 16;  }  // [0,2,1,1] alias_counter : 16
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 8;  }  // [0,2,2,0] alias_counter : 8
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 16;  }  // [1,0,0,2] alias_counter : 16
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 16;  }  // [1,0,1,2] alias_counter : 16
        case 1020: { return 16;  }  // [1,0,2,0] alias_counter : 16
        case 1021: { return 16;  }  // [1,0,2,1] alias_counter : 16
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 16;  }  // [1,1,0,2] alias_counter : 16
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 2;  }  // [1,1,1,1] alias_counter : 2
        case 1112: { return 16;  }  // [1,1,1,2] alias_counter : 16
        case 1120: { return 16;  }  // [1,1,2,0] alias_counter : 16
        case 1121: { return 16;  }  // [1,1,2,1] alias_counter : 16
        case 1122: { return 4;  }  // [1,1,2,2] alias_counter : 4
        case 1200: { return 16;  }  // [1,2,0,0] alias_counter : 16
        case 1201: { return 16;  }  // [1,2,0,1] alias_counter : 16
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 16;  }  // [1,2,1,0] alias_counter : 16
        case 1211: { return 16;  }  // [1,2,1,1] alias_counter : 16
        case 1212: { return 8;  }  // [1,2,1,2] alias_counter : 8
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 8;  }  // [1,2,2,1] alias_counter : 8
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 16;  }  // [2,0,0,0] alias_counter : 16
        case 2001: { return 16;  }  // [2,0,0,1] alias_counter : 16
        case 2002: { return 8;  }  // [2,0,0,2] alias_counter : 8
        case 2010: { return 16;  }  // [2,0,1,0] alias_counter : 16
        case 2011: { return 16;  }  // [2,0,1,1] alias_counter : 16
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 8;  }  // [2,0,2,0] alias_counter : 8
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 16;  }  // [2,1,0,0] alias_counter : 16
        case 2101: { return 16;  }  // [2,1,0,1] alias_counter : 16
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 16;  }  // [2,1,1,0] alias_counter : 16
        case 2111: { return 16;  }  // [2,1,1,1] alias_counter : 16
        case 2112: { return 8;  }  // [2,1,1,2] alias_counter : 8
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 8;  }  // [2,1,2,1] alias_counter : 8
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 4;  }  // [2,2,0,0] alias_counter : 4
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 4;  }  // [2,2,1,1] alias_counter : 4
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::Trigonal6SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === trigonal6 aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 2;  }  // [0,0,0,0] alias_counter : 2
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 2;  }  // [0,0,1,1] alias_counter : 2
        case 12: { return 16;  }  // [0,0,1,2] alias_counter : 16
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 16;  }  // [0,0,2,1] alias_counter : 16
        case 22: { return 4;  }  // [0,0,2,2] alias_counter : 4
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 4;  }  // [0,1,0,1] alias_counter : 4
        case 102: { return 16;  }  // [0,1,0,2] alias_counter : 16
        case 110: { return 4;  }  // [0,1,1,0] alias_counter : 4
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 16;  }  // [0,1,2,0] alias_counter : 16
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 16;  }  // [0,2,0,1] alias_counter : 16
        case 202: { return 8;  }  // [0,2,0,2] alias_counter : 8
        case 210: { return 16;  }  // [0,2,1,0] alias_counter : 16
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 8;  }  // [0,2,2,0] alias_counter : 8
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 4;  }  // [1,0,0,1] alias_counter : 4
        case 1002: { return 16;  }  // [1,0,0,2] alias_counter : 16
        case 1010: { return 4;  }  // [1,0,1,0] alias_counter : 4
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 16;  }  // [1,0,2,0] alias_counter : 16
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 2;  }  // [1,1,0,0] alias_counter : 2
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 2;  }  // [1,1,1,1] alias_counter : 2
        case 1112: { return 16;  }  // [1,1,1,2] alias_counter : 16
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 16;  }  // [1,1,2,1] alias_counter : 16
        case 1122: { return 4;  }  // [1,1,2,2] alias_counter : 4
        case 1200: { return 16;  }  // [1,2,0,0] alias_counter : 16
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 16;  }  // [1,2,1,1] alias_counter : 16
        case 1212: { return 8;  }  // [1,2,1,2] alias_counter : 8
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 8;  }  // [1,2,2,1] alias_counter : 8
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 16;  }  // [2,0,0,1] alias_counter : 16
        case 2002: { return 8;  }  // [2,0,0,2] alias_counter : 8
        case 2010: { return 16;  }  // [2,0,1,0] alias_counter : 16
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 8;  }  // [2,0,2,0] alias_counter : 8
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 16;  }  // [2,1,0,0] alias_counter : 16
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 16;  }  // [2,1,1,1] alias_counter : 16
        case 2112: { return 8;  }  // [2,1,1,2] alias_counter : 8
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 8;  }  // [2,1,2,1] alias_counter : 8
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 4;  }  // [2,2,0,0] alias_counter : 4
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 4;  }  // [2,2,1,1] alias_counter : 4
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 1;  }  // [2,2,2,2] alias_counter : 1
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::CubicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === cubic aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 3;  }  // [0,0,0,0] alias_counter : 3
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 6;  }  // [0,0,1,1] alias_counter : 6
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 6;  }  // [0,0,2,2] alias_counter : 6
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 12;  }  // [0,1,0,1] alias_counter : 12
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 12;  }  // [0,1,1,0] alias_counter : 12
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 12;  }  // [0,2,0,2] alias_counter : 12
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 12;  }  // [0,2,2,0] alias_counter : 12
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 12;  }  // [1,0,0,1] alias_counter : 12
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 12;  }  // [1,0,1,0] alias_counter : 12
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 6;  }  // [1,1,0,0] alias_counter : 6
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 3;  }  // [1,1,1,1] alias_counter : 3
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 6;  }  // [1,1,2,2] alias_counter : 6
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 12;  }  // [1,2,1,2] alias_counter : 12
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 12;  }  // [1,2,2,1] alias_counter : 12
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 12;  }  // [2,0,0,2] alias_counter : 12
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 12;  }  // [2,0,2,0] alias_counter : 12
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 12;  }  // [2,1,1,2] alias_counter : 12
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 12;  }  // [2,1,2,1] alias_counter : 12
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 6;  }  // [2,2,0,0] alias_counter : 6
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 6;  }  // [2,2,1,1] alias_counter : 6
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 3;  }  // [2,2,2,2] alias_counter : 3
    }
    return 1; 
}

template <>
inline int TensorRank4IndexNumberOfAliases<mpc::core::IsotropicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) { 
// === isotropic aliases a.k.a. reduced set
    const int integer_representation = (indexn.FirstIndex()*1000) + (indexn.SecondIndex()*100) + (indexn.ThirdIndex()*10) + indexn.FourthIndex();
    //std::cout << "integer_representation : " << integer_representation << std::endl;
    switch (integer_representation) {
        case 0: { return 3;  }  // [0,0,0,0] alias_counter : 3
        case 1: { return 1;  }  // [0,0,0,1] alias_counter : 1
        case 2: { return 1;  }  // [0,0,0,2] alias_counter : 1
        case 10: { return 1;  }  // [0,0,1,0] alias_counter : 1
        case 11: { return 6;  }  // [0,0,1,1] alias_counter : 6
        case 12: { return 1;  }  // [0,0,1,2] alias_counter : 1
        case 20: { return 1;  }  // [0,0,2,0] alias_counter : 1
        case 21: { return 1;  }  // [0,0,2,1] alias_counter : 1
        case 22: { return 6;  }  // [0,0,2,2] alias_counter : 6
        case 100: { return 1;  }  // [0,1,0,0] alias_counter : 1
        case 101: { return 12;  }  // [0,1,0,1] alias_counter : 12
        case 102: { return 1;  }  // [0,1,0,2] alias_counter : 1
        case 110: { return 12;  }  // [0,1,1,0] alias_counter : 12
        case 111: { return 1;  }  // [0,1,1,1] alias_counter : 1
        case 112: { return 1;  }  // [0,1,1,2] alias_counter : 1
        case 120: { return 1;  }  // [0,1,2,0] alias_counter : 1
        case 121: { return 1;  }  // [0,1,2,1] alias_counter : 1
        case 122: { return 1;  }  // [0,1,2,2] alias_counter : 1
        case 200: { return 1;  }  // [0,2,0,0] alias_counter : 1
        case 201: { return 1;  }  // [0,2,0,1] alias_counter : 1
        case 202: { return 12;  }  // [0,2,0,2] alias_counter : 12
        case 210: { return 1;  }  // [0,2,1,0] alias_counter : 1
        case 211: { return 1;  }  // [0,2,1,1] alias_counter : 1
        case 212: { return 1;  }  // [0,2,1,2] alias_counter : 1
        case 220: { return 12;  }  // [0,2,2,0] alias_counter : 12
        case 221: { return 1;  }  // [0,2,2,1] alias_counter : 1
        case 222: { return 1;  }  // [0,2,2,2] alias_counter : 1
        case 1000: { return 1;  }  // [1,0,0,0] alias_counter : 1
        case 1001: { return 12;  }  // [1,0,0,1] alias_counter : 12
        case 1002: { return 1;  }  // [1,0,0,2] alias_counter : 1
        case 1010: { return 12;  }  // [1,0,1,0] alias_counter : 12
        case 1011: { return 1;  }  // [1,0,1,1] alias_counter : 1
        case 1012: { return 1;  }  // [1,0,1,2] alias_counter : 1
        case 1020: { return 1;  }  // [1,0,2,0] alias_counter : 1
        case 1021: { return 1;  }  // [1,0,2,1] alias_counter : 1
        case 1022: { return 1;  }  // [1,0,2,2] alias_counter : 1
        case 1100: { return 6;  }  // [1,1,0,0] alias_counter : 6
        case 1101: { return 1;  }  // [1,1,0,1] alias_counter : 1
        case 1102: { return 1;  }  // [1,1,0,2] alias_counter : 1
        case 1110: { return 1;  }  // [1,1,1,0] alias_counter : 1
        case 1111: { return 3;  }  // [1,1,1,1] alias_counter : 3
        case 1112: { return 1;  }  // [1,1,1,2] alias_counter : 1
        case 1120: { return 1;  }  // [1,1,2,0] alias_counter : 1
        case 1121: { return 1;  }  // [1,1,2,1] alias_counter : 1
        case 1122: { return 6;  }  // [1,1,2,2] alias_counter : 6
        case 1200: { return 1;  }  // [1,2,0,0] alias_counter : 1
        case 1201: { return 1;  }  // [1,2,0,1] alias_counter : 1
        case 1202: { return 1;  }  // [1,2,0,2] alias_counter : 1
        case 1210: { return 1;  }  // [1,2,1,0] alias_counter : 1
        case 1211: { return 1;  }  // [1,2,1,1] alias_counter : 1
        case 1212: { return 12;  }  // [1,2,1,2] alias_counter : 12
        case 1220: { return 1;  }  // [1,2,2,0] alias_counter : 1
        case 1221: { return 12;  }  // [1,2,2,1] alias_counter : 12
        case 1222: { return 1;  }  // [1,2,2,2] alias_counter : 1
        case 2000: { return 1;  }  // [2,0,0,0] alias_counter : 1
        case 2001: { return 1;  }  // [2,0,0,1] alias_counter : 1
        case 2002: { return 12;  }  // [2,0,0,2] alias_counter : 12
        case 2010: { return 1;  }  // [2,0,1,0] alias_counter : 1
        case 2011: { return 1;  }  // [2,0,1,1] alias_counter : 1
        case 2012: { return 1;  }  // [2,0,1,2] alias_counter : 1
        case 2020: { return 12;  }  // [2,0,2,0] alias_counter : 12
        case 2021: { return 1;  }  // [2,0,2,1] alias_counter : 1
        case 2022: { return 1;  }  // [2,0,2,2] alias_counter : 1
        case 2100: { return 1;  }  // [2,1,0,0] alias_counter : 1
        case 2101: { return 1;  }  // [2,1,0,1] alias_counter : 1
        case 2102: { return 1;  }  // [2,1,0,2] alias_counter : 1
        case 2110: { return 1;  }  // [2,1,1,0] alias_counter : 1
        case 2111: { return 1;  }  // [2,1,1,1] alias_counter : 1
        case 2112: { return 12;  }  // [2,1,1,2] alias_counter : 12
        case 2120: { return 1;  }  // [2,1,2,0] alias_counter : 1
        case 2121: { return 12;  }  // [2,1,2,1] alias_counter : 12
        case 2122: { return 1;  }  // [2,1,2,2] alias_counter : 1
        case 2200: { return 6;  }  // [2,2,0,0] alias_counter : 6
        case 2201: { return 1;  }  // [2,2,0,1] alias_counter : 1
        case 2202: { return 1;  }  // [2,2,0,2] alias_counter : 1
        case 2210: { return 1;  }  // [2,2,1,0] alias_counter : 1
        case 2211: { return 6;  }  // [2,2,1,1] alias_counter : 6
        case 2212: { return 1;  }  // [2,2,1,2] alias_counter : 1
        case 2220: { return 1;  }  // [2,2,2,0] alias_counter : 1
        case 2221: { return 1;  }  // [2,2,2,1] alias_counter : 1
        case 2222: { return 3;  }  // [2,2,2,2] alias_counter : 3
    }
    return 1; 
}
    





// polymorphic version for matrix notation
template <typename S>
inline int TensorRank4IndexNumberOfAliases(const mpc::core::TensorRankNComponentIndex<2>& indexn) {
    static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
    // returns the number of aliases for the index
    const int index_p = indexn.FirstIndex();
    const int index_q = indexn.SecondIndex();

    std::pair<int,int> p_indices = mpc::util::GetIndexFromVoigtMatrix(index_p);
    std::pair<int,int> q_indices = mpc::util::GetIndexFromVoigtMatrix(index_q);
    return TensorRank4IndexNumberOfAliases<S>(mpc::core::TensorRank4ComponentIndex(p_indices.first, p_indices.second, q_indices.first, q_indices.second));
}

// // TODO: compile-time equivalent
// // where tensors of rank 2 here are assumed to be symmetric, i.e. A(i,j) = A(j,i).
// template <int M, int N>
// constexpr inline int CTensorRank2IndexNumberOfAliases(const mpc::core::CTensorRank2ComponentIndex<M,N>& cindexn) {
//     // returns the number of aliases for the index
//     return (M == N) ? 1 : 2;
// }


// =============================================================================
// =============================================================================
// =============================================================================


inline std::set<mpc::core::TensorRank2ComponentIndex> TensorRank2IndexAliases(const mpc::core::TensorRankNComponentIndex<2>& indexn) {

    std::set<mpc::core::TensorRank2ComponentIndex> iset{
        mpc::core::TensorRank2ComponentIndex(indexn.FirstIndex(), indexn.SecondIndex())
    };
    iset.insert(mpc::core::TensorRank2ComponentIndex(indexn.SecondIndex(), indexn.FirstIndex()));
    return iset;
}


//===
template <typename S=mpc::core::NoneSymmetryGroupType>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
    // none type symmetry has no aliases...
    std::set<mpc::core::TensorRank4ComponentIndex> iset{ mpc::core::TensorRank4ComponentIndex(indexn) };
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    // use std::set<> to resolve non-unique values...
    const int index_i = indexn.FirstIndex();
    const int index_j = indexn.SecondIndex();
    const int index_k = indexn.ThirdIndex();
    const int index_l = indexn.FourthIndex();

    std::set<mpc::core::TensorRank4ComponentIndex> iset{
        mpc::core::TensorRank4ComponentIndex(index_i, index_j, index_k, index_l)}; // c(i,j,k,l)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_i, index_j, index_l, index_k)); // c(i,j,l,k)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_j, index_i, index_k, index_l)); // c(j,i,k,l)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_j, index_i, index_l, index_k)); // c(j,i,l,k)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_k, index_l, index_i, index_j)); // c(k,l,i,j)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_l, index_k, index_i, index_j)); // c(l,k,i,j)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_k, index_l, index_j, index_i)); // c(k,l,j,i)
    iset.insert(mpc::core::TensorRank4ComponentIndex(index_l, index_k, index_j, index_i)); // c(l,k,j,i)

    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::MonoclinicX2SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  --  04  -- |
     *  | 01  11  12  --  14  -- |
     *  | 02  12  22  --  24  -- |
     *  | --  --  --  33  --  35 |
     *  | 04  14  24  --  44  -- |
     *  | --  --  --  35  --  55 |
     */
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // no "groupings", e.g. no equivalent components beyond triclinic symmetry
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2));  // 04
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2));  // 14
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,0,2));  // 24
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1));  // 35
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::MonoclinicX3SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  --  --  05 |
     *  | 01  11  12  --  --  15 |
     *  | 02  12  22  --  --  25 |
     *  | --  --  --  33  34  -- |
     *  | --  --  --  34  44  -- |
     *  | 05  15  25  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // no "groupings", e.g. no equivalent components beyond triclinic symmetry
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1));  // 05
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,1));  // 15
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(2,2,0,1));  // 25
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,2));  // 34
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
    
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::OrthorhombicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  --  --  -- |
     *  | 01  11  12  --  --  -- |
     *  | 02  12  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  44  -- |
     *  | --  --  --  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // no "groupings", e.g. no equivalent components beyond triclinic symmetry
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::HexagonalSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  --  --  -- |
     *  | 01  00  02  --  --  -- |
     *  | 02  02  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | --  --  --  --  --  XX |
     * 
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // NOTE: Hexagonal reduced component indices are no different than that of VTI; the difference is in the values, specifically the relationship of the values among the indices
    // Groupings: {00,11}, {02,12}, {33,44}
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::Tetragonal7SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  --  --  05 |
     *  | 01  00  02  --  -- -05 |
     *  | 02  02  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | 05 -05  --  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11}, {02,12}, {33,44}, {05,15}
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1));  // 05
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 05 and 15
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,1));  // 15
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,1));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 05 and 15
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::Tetragonal6SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  --  --  -- |
     *  | 01  00  02  --  --  -- |
     *  | 02  02  22  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | --  --  --  --  --  55 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11}, {02,12}, {33,44}    
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::Trigonal7SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  03 -04  -- |
     *  | 01  00  02 -03  04  -- |
     *  | 02  02  22  --  --  -- |
     *  | 03 -03  --  33  -- *04 |
     *  | 04  14  --  --  33 *03 |
     *  | --  --  -- *04 *03  XX |
     * 
     * where *NN is the numerical equal for C and twice the numerical equal for S; and
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     * 
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11}, {02,12}, {03,13,45}, {04,14,35}, {33,44}    
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));  // 03
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {03,13,45}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));  // 13
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {03,13,45}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));  // 45
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {03,13,45}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2));  // 04
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {04,14,35}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2));  // 14
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {04,14,35}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1));  // 35
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,0,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {04,14,35}
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::Trigonal6SymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  02  03  --  -- |
     *  | 01  00  02 -03  --  -- |
     *  | 02  02  22  --  --  -- |
     *  | 03 -03  --  33  --  -- |
     *  | --  --  --  --  33 *03 |
     *  | --  --  --  -- *03  XX |
     * 
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11}, {02,12}, {03,13,45}, {33,44}    
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 02 and 12
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices 33 and 44
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(indexn);
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));  // 03
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {03,13,45}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));  // 13
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {03,13,45}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));  // 45
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,2));
        std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,1,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {03,13,45}
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::CubicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  01  --  --  -- |
     *  | 01  00  01  --  --  -- |
     *  | 01  01  00  --  --  -- |
     *  | --  --  --  33  --  -- |
     *  | --  --  --  --  33  -- |
     *  | --  --  --  --  --  33 |
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // Groupings: {00,11,22}, {01,02,12}, {33,44,55}    
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {01,02,12}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {01,02,12}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {01,02,12}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {33,44,55}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {33,44,55}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {33,44,55}
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}

template <>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases<mpc::core::IsotropicSymmetryGroupType>(const mpc::core::TensorRankNComponentIndex<4>& indexn) {
    /*
     *  | 00  01  01  --  --  -- |
     *  | 01  00  01  --  --  -- |
     *  | 01  01  00  --  --  -- |
     *  | --  --  --  XX  --  -- |
     *  | --  --  --  --  XX  -- |
     *  | --  --  --  --  --  XX |
     * 
     * For C, XX = 0.5 * [C(0,0) - C(0,1)]
     * For S, XX =   2 * [S(0,0) - S(0,1)]
     */
    //
    // "reduced" component index is always the "least valued" index, e.g. the first in a sorted container like set
    // NOTE: isotropic is identical to cubic in terms of component groupings; the difference comes from the relationship of the values between component indices
    // Groupings: {00,11,22}, {01,02,12}, {33,44,55}    
    mpc::core::TensorRank4ComponentIndex indexn_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(indexn);
    std::set<mpc::core::TensorRank4ComponentIndex> iset{};
    std::set<mpc::core::TensorRank4ComponentIndex> iset_tmp{};
    
    // deterimine if the index belongs to the set of non-zero values...
    // 00, 11, and 22 are easy because they do not have aliases
    if (indexn == mpc::core::TensorRank4ComponentIndex(0,0,0,0)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(1,1,1,1)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    if (indexn == mpc::core::TensorRank4ComponentIndex(2,2,2,2)) {
        iset.insert(mpc::core::TensorRank4ComponentIndex(0,0,0,0));
        iset.insert(mpc::core::TensorRank4ComponentIndex(1,1,1,1));
        iset.insert(mpc::core::TensorRank4ComponentIndex(2,2,2,2));
        return iset;
    }
    
    mpc::core::TensorRank4ComponentIndex indexXX_reduced = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));  // 01
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {01,02,12}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));  // 02
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {01,02,12}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));  // 12
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,1,1));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,0,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,1,2,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {01,02,12}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));  // 33
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {33,44,55}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));  // 44
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {33,44,55}
        return iset;
    }
    
    indexXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));  // 55
    if (indexn_reduced == indexXX_reduced) {
        iset = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(1,2,1,2));
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,2,0,2));
        iset.insert(iset_tmp.begin(), iset_tmp.end());
        iset_tmp = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(0,1,0,1));
        iset.insert(iset_tmp.begin(), iset_tmp.end());  // merge the set for indices {33,44,55}
        return iset;
    }
    
    // the index must be a zero-valued index; return a set with a copy of the index
    iset.insert(mpc::core::TensorRank4ComponentIndex(indexn));    
    return iset;
}





// polymorphic function for matrix notation to tensor indices
template <typename S>
inline std::set<mpc::core::TensorRank4ComponentIndex> TensorRank4IndexAliases(const mpc::core::TensorRankNComponentIndex<2>& indexn) {
    static_assert(std::is_base_of<mpc::core::SymmetryGroupBase,S>::value, "S must be derived from mpc::core::SymmetryGroupBase.");
    // creates a TensorRank4ComponentIndex from the TensorRank2ComponentIndex which assumed to be the ZERO BASED matrix notation of a symmetric stiffness or compliance tensor
    const int index_p = indexn.FirstIndex();
    const int index_q = indexn.SecondIndex();

    std::pair<int,int> p_indices = mpc::util::GetIndexFromVoigtMatrix(index_p);
    std::pair<int,int> q_indices = mpc::util::GetIndexFromVoigtMatrix(index_q);
    return TensorRank4IndexAliases<S>(mpc::core::TensorRank4ComponentIndex(p_indices.first, p_indices.second, q_indices.first, q_indices.second));
}





// ==============================================================================================================================
// ==============================================================================================================================
// ==============================================================================================================================




} // namespace core
} // namespace mpc

#endif // MPC_TENSORCOMPONENTINDEXALIASES_H
