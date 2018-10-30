#include "mpcx_stiffnesscompliance_csrelationship.hpp"

// c++
#include <iostream>
#include <set>

// mpc
#include <mpc/core/tensorcomponentindex.hpp>
#include <mpc/core/tensorcomponent.hpp>
#include <mpc/core/symmetrygrouptypes.hpp>
#include <mpc/core/stiffnesscompliance.hpp>
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/core/csrelationship.hpp>

void mpcexamples::mpcStiffnessComplianceCSRelationship() {
    // -------------------------------------------------------------- MPCTEST041
    /** Stiffness, Compliance, and C<->S Relationships */
    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::utilities::PrintTensorComponents<double,1> print_tensor_components_double_1_fo;
    mpc::utilities::PrintTensorComponents<double,2> print_tensor_components_double_2_fo;
    mpc::utilities::PrintTensorComponents<double,4> print_tensor_components_double_4_fo;

    /*
     * Now, for symmerty, specifically symmetry of 4th rank tensors
     *     corresponding to:
     *
     *     c(i,j,k,l) = c(j,i,k,l) = c(i,j,l,k) = c(l,k,i,j)
     *
     *     that is, triclinic symmetry.  Additional symmetry groups are
     *         specializations of triclinic symmetry...
     *
     * SymmetryGroupEnumeration and corresponding SymmetryGroupType class
     *     NONE             >> NoneSymmetryGroupType
     *     TRICLINIC        >> TriclinciSymmetryGroupType
     *     MONOCLINIC_X2    >> MonoclinicX2SymmetryGroupType
     *     MONOCLINIC_X3    >> MonoclinicX3SymmetryGroupType
     *     ORTHORHOMBIC     >> OrthorhombicSymemtryGroupType
     *     VTI              >> VTISymmetryGroupType
     *     HTI              >> HTISymmetryGroupType
     *     HEXAGONAL        >> HexagonalSymmetryType
     *     TETRAGONAL7      >> Tetragonal7SymmetryType
     *     TETRAGONAL6      >> Tetragonal6SymmetryType
     *     TRIGONAL7        >> Trigonal7SymmetryType
     *     TRIGONAL6        >> Trigonal6SymmetryType
     *     CUBIC            >> CubicSymmetryType
     *     ISOTROPIC        >> IsotropicSymmetryType
     *
     * Each symmetry type is a subclass of SymmetryGroupBase and has (currently)
     *     two data members:
     *         SymmetryGroupEnumeration symmetry_group_enumeration
     *         int number_of_independent_components
     */

    mpc::core::StiffnessTensor<double> stiffness_tensor;

    // TRICLINIC
    /*
    *  | 00  01  02  03  04  05 |
    *  | 01  11  12  13  14  15 |
    *  | 02  12  22  23  24  25 |
    *  | 03  13  23  33  34  35 |
    *  | 04  14  24  34  44  45 |
    *  | 05  15  25  35  45  55 |
    */

    std::set<mpc::core::TensorRank4Component<double> > triclinic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(2223.0, mpc::core::TensorRank4ComponentIndex(1,1,1,2)), // X13 >> (1112), (1121), (1211), (2111)
            mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
            mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(3323.0, mpc::core::TensorRank4ComponentIndex(2,2,1,2)), // X23 >> (2212), (2221), (1222), (2122)
            mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
            mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
            mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1312.0, mpc::core::TensorRank4ComponentIndex(0,2,0,1)), // X45 >> (0201), (0210), (2001), (2010), (0102), (1002), (0120), (1020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
    std::cout << "triclinic stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // MONOCLINIC_X2
    /*
    *  | 00  01  02  --  04  -- |
    *  | 01  11  12  --  14  -- |
    *  | 02  12  22  --  24  -- |
    *  | --  --  --  33  --  35 |
    *  | 04  14  24  --  44  -- |
    *  | --  --  --  35  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > monoclinicx2_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx2_symmetry_aliased_set_00);
    std::cout << "monoclinic(x2) stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // MONOCLINIC_X3
    /*
    *  | 00  01  02  --  --  05 |
    *  | 01  11  12  --  --  15 |
    *  | 02  12  22  --  --  25 |
    *  | --  --  --  33  34  -- |
    *  | --  --  --  34  44  -- |
    *  | 05  15  25  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > monoclinicx3_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::MonoclinicX3SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
    std::cout << "monoclinic(x3) stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // ORTHORHOMBIC
    /*
    *  | 00  01  02  --  --  -- |
    *  | 01  11  12  --  --  -- |
    *  | 02  12  22  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  44  -- |
    *  | --  --  --  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > orthorhombic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(orthorhombic_symmetry_aliased_set_00);
    std::cout << "orthorhombic stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // HEXAGONAL
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
    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00);
    std::cout << "hexagonal stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_01);
    std::cout << "hexagonal stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_02);
    std::cout << "hexagonal stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // TETRAGONAL7
    /*
    *  | 00  01  02  --  --  05 |
    *  | 01  00  02  --  -- -05 |
    *  | 02  02  22  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  33  -- |
    *  | 05 -05  --  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00);
    std::cout << "tetragonal7 stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // TETRAGONAL6
    /*
    *  | 00  01  02  --  --  -- |
    *  | 01  00  02  --  --  -- |
    *  | 02  02  22  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  33  -- |
    *  | --  --  --  --  --  55 |
    */
    std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
    std::cout << "tetragonal6 stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_01);
    std::cout << "tetragonal6 stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // TRIGONAL7
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

    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00);
    std::cout << "trigonal7 stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    // ==========================================================================================================================================================
    //  TRIGONAL6
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

    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
    std::cout << "trigonal6 stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
            mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
            mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    // ==========================================================================================================================================================
    // CUBIC
    /*
    *  | 00  01  01  --  --  -- |
    *  | 01  00  01  --  --  -- |
    *  | 01  01  00  --  --  -- |
    *  | --  --  --  33  --  -- |
    *  | --  --  --  --  33  -- |
    *  | --  --  --  --  --  33 |
    */
    std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
    std::cout << "cubic stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    stiffness_tensor.SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
    std::cout << "cubic stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor.tensor);

    // ==========================================================================================================================================================
    // ISOTROPIC
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
    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
    };

    mpc::core::StiffnessTensor<double> stiffness_tensor_isotropic_00;
    stiffness_tensor_isotropic_00.SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00);
    std::cout << "isotropic stiffness tensor" << std::endl;
    print_tensor_components_double_4_fo(stiffness_tensor_isotropic_00.tensor);

//    mpc::core::ComplianceTensor<double> compliance_tensor_isotropic_00;
//    compliance_tensor_isotropic_00.SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00);
//    std::cout << "isotropic compliance tensor" << std::endl;
//    print_tensor_components_double_4_fo(compliance_tensor_isotropic_00.tensor);

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01{
            mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
            mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    };

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_02{
            mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
            mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    };

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_03{
            mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(40.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    }; // NOTE: For C, XX = 0.5 * [C(0,0) - C(0,1)]; satisfies cubic as well

    std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_04{
            mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
            mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
            mpc::core::TensorRank4Component<double>(160.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    }; // NOTE: For S, XX =   2 * [S(0,0) - S(0,1)]; satisfies cubic as well


    /*
     * to verify the solutions, we will solve the compound equation sigma(i,j) = c(i,j,k,l) * epsilon(k,l) = c(i,j,k,l) * [s(k,l,m,n) * sigma(m,n)]
     *
     * so, given a starting stress tensor, we should get that same starting tensor back...
     * std::set< mpc::core::TensorRank2Component<double> > stress_components_000{
     *     mpc::core::TensorRank2Component<double>(11.0,mpc::core::TensorRank2ComponentIndex(0,0)),
     *     mpc::core::TensorRank2Component<double>(22.0,mpc::core::TensorRank2ComponentIndex(1,1)),
     *     mpc::core::TensorRank2Component<double>(33.0,mpc::core::TensorRank2ComponentIndex(2,2)),
     * };
     */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;


//    // circular solution - ISOTROPIC
//    mpc::core::StiffnessTensor<double> stiffness_tensor_000;
//    stiffness_tensor_000.SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01);
//    mpc::core::ComplianceTensor<double> compliance_tensor_from_stiffness_tensor_000 = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(stiffness_tensor_000);
//    mpc::core::StiffnessTensor<double> stiffness_tensor_from_compliance_tensor_from_stiffness_tensor_000 = mpc::core::CSRelationship<mpc::core::NoneSymmetryGroupType>(compliance_tensor_from_stiffness_tensor_000);
//
//    print_tensor_components_double_4_fo(stiffness_tensor_000.tensor);
//    //print_tensor_components_double_4_fo(compliance_tensor_from_stiffness_tensor_000.tensor);
//    print_tensor_components_double_4_fo(stiffness_tensor_from_compliance_tensor_from_stiffness_tensor_000.tensor);

//    // comparing the tensors by calculating the rms of the difference
//    int p = 0;
//    int q = 0;
//    double val = 0;
//    blitz::Array<double,1> rms_array = blitz::Array<double,1>(81);
//    int counter = 0;
//    for (int i=0; i<3; ++i) {
//        for (int j=0; j<3; ++j) {
//            for (int k=0; k<3; ++k) {
//                for (int l=0; l<3; ++l) {
//                    p = mpc::utilities::GetVoigtMatrixIndex(i, j);
//                    q = mpc::utilities::GetVoigtMatrixIndex(k, l);
//                    val = stiffness_tensor_000.tensor(i,j,k,l) - stiffness_tensor_from_compliance_tensor_from_stiffness_tensor_000.tensor(i,j,k,l);
//                    //std::cout << "val : " << val << std::endl;
//                    val = val*val; // the square
//                    rms_array(counter) = val;
//                    counter++;
//                    //std::cout << "[" << p << "," << q << "] : " << val << std::endl;
//                    //std::cout << "(" << i << "," << j << "," << k << "," << l << ") : " << val << std::endl;
//                }
//            }
//        }
//    }
//
//    double rms_val = blitz::sum(rms_array);
//    //std::cout << "rms-val : " << rms_val << std::endl;
//    rms_val = std::sqrt(rms_val);
//    std::cout << "rms_val : " << rms_val << std::endl;


// // circular solution - TRICLINIC
// mpc::core::StiffnessTensor<double> stiffness_tensor_001;
// stiffness_tensor_001.SetComponentsWithSymmetry<mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
// mpc::core::ComplianceTensor<double> compliance_tensor_from_stiffness_tensor_001 = mpc::core::CSRelationship<mpc::core::NoneSymmetryGroupType>(stiffness_tensor_001);
// mpc::core::StiffnessTensor<double> stiffness_tensor_from_compliance_tensor_from_stiffness_tensor_001 = mpc::core::CSRelationship<mpc::core::NoneSymmetryGroupType>(compliance_tensor_from_stiffness_tensor_001);
//
// //print_tensor_components_double_4_fo(stiffness_tensor_001.tensor);
// //print_tensor_components_double_4_fo(compliance_tensor_from_stiffness_tensor_001.tensor);
// //print_tensor_components_double_4_fo(stiffness_tensor_from_compliance_tensor_from_stiffness_tensor_001.tensor);
//
// // comparing the tensors by calculating the rms of the difference
// counter = 0;
// for (int i=0; i<3; ++i) {
//     for (int j=0; j<3; ++j) {
//         for (int k=0; k<3; ++k) {
//             for (int l=0; l<3; ++l) {
//                 p = mpc::util::GetVoigtMatrixIndex(i, j);
//                 q = mpc::util::GetVoigtMatrixIndex(k, l);
//                 val = stiffness_tensor_001.tensor(i,j,k,l) - stiffness_tensor_from_compliance_tensor_from_stiffness_tensor_001.tensor(i,j,k,l);
//                 val = val*val;  // the square
//                 rms_array(counter) = val;
//                 counter++;
//                 //std::cout << "[" << p << "," << q << "] : " << val << std::endl;
//                 //std::cout << "(" << i << "," << j << "," << k << "," << l << ") : " << val << std::endl;
//             }
//         }
//     }
// }
//
// rms_val = blitz::sum(rms_array);
// rms_val = std::sqrt(rms_val);
// std::cout << rms_val << std::endl;

// TODO: mpcexampleappqt - view of cs relationships

}
