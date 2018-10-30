#include "mpcx_transformation.hpp"

// c++
#include <iostream>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/constants.hpp>
#include <mpc/utilities/norm.hpp>
#include <mpc/transformation/eulerrotation.hpp>
#include <mpc/transformation/transformer.hpp>

void mpcexamples::mpcTransformation() {
    /** transformations */
    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::utilities::PrintTensorComponents<double,1> print_tensor_components_double_1_fo;
    mpc::utilities::PrintTensorComponents<double,2> print_tensor_components_double_2_fo;
    mpc::utilities::PrintTensorComponents<double,4> print_tensor_components_double_4_fo;

    // euler rotation
    const double PI = mpc::utilities::PI<double>;
    const double TWO_PI = 2.0 * PI;
    const int DIVISOR = 8;
    const double DBL_DIVISOR = double(DIVISOR);
    // Euler transformation tensor
    double phi0 = 0.0;
    double phi1 = 0.0;
    double phi2 = 0.0;

    mpc::transformation::EulerRotationX3X1X3<double> eulerRotation;

    blitz::Array<double,2> rot0_0_0 = eulerRotation(phi0, phi1, phi2);
    std::cout << "rot 0 0 0: " << rot0_0_0 << std::endl;

    phi0 = mpc::utilities::PI<double> * 0.5;
    phi1 = mpc::utilities::PI<double> * 0.5;
    phi2 = mpc::utilities::PI<double> * 0.5;

    blitz::Array<double,2> rotPIdiv2_PIdiv2_PIdiv2 = eulerRotation(phi0, phi1, phi2);
    std::cout << "rot PI/2 PI/2 PI/2: " << rotPIdiv2_PIdiv2_PIdiv2 << std::endl;

    phi0 = mpc::utilities::PI<double>;
    phi1 = mpc::utilities::PI<double>;
    phi2 = mpc::utilities::PI<double>;

    blitz::Array<double,2> rotPI_PI_PI = eulerRotation(phi0, phi1, phi2);
    std::cout << "rot PI PI PI: " << rotPI_PI_PI << std::endl;

    // transformation for tensors of rank1
    blitz::Array<double,1> rank1tensor = blitz::Array<double,1>(3);
    rank1tensor = 1, 2, 3;

    mpc::transformation::Transformer<double,1> trans_fo;
    blitz::Array<double,1> rotated_rank1tensor = trans_fo(rank1tensor, rot0_0_0);
    std::cout << "rotated rank1tensor {0,0,0} : " << std::endl;
    print_tensor_components_double_1_fo(rotated_rank1tensor);

    rotated_rank1tensor = trans_fo(rank1tensor, rotPIdiv2_PIdiv2_PIdiv2);
    std::cout << "rotated rank1tensor {pi/2,pi/2,pi/2} : " << std::endl;
    print_tensor_components_double_1_fo(rotated_rank1tensor);

    rotated_rank1tensor = trans_fo(rank1tensor, rotPI_PI_PI);
    std::cout << "rotated rank1tensor {pi,pi,pi} : " << std::endl;
    print_tensor_components_double_1_fo(rotated_rank1tensor);

    // transformation for tensors of rank2
    blitz::Array<double,2> rank2tensor = blitz::Array<double,2>(3, 3, blitz::ColumnMajorArray<2>());
    rank2tensor = 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "rank2tensor : " << std::endl;
    print_tensor_components_double_2_fo(rank2tensor);

    mpc::transformation::Transformer<double,2> trans2_fo;
    blitz::Array<double,2> rotated_rank2tensor = trans2_fo(rank2tensor, rot0_0_0);
    std::cout << "rotated rank2tensor {0,0,0} : " << std::endl;
    print_tensor_components_double_2_fo(rotated_rank2tensor);

    rotated_rank2tensor = trans2_fo(rank2tensor, rotPIdiv2_PIdiv2_PIdiv2);
    std::cout << "rotated rank2tensor {pi/2,pi/2,pi/2} : " << std::endl;
    print_tensor_components_double_2_fo(rotated_rank2tensor);

    rotated_rank2tensor = trans2_fo(rank2tensor, rotPI_PI_PI);
    std::cout << "rotated rank2tensor {pi,pi,pi} : " << std::endl;
    print_tensor_components_double_2_fo(rotated_rank2tensor);

    // transformation for tensors of rank4
    blitz::Array<double,4> rank4tensor = blitz::Array<double,4>(3, 3, 3, 3, blitz::ColumnMajorArray<4>());
    rank4tensor = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81;
    std::cout << "rank4tensor : " << std::endl;
    print_tensor_components_double_4_fo(rank4tensor);

    mpc::transformation::Transformer<double,4> trans4_fo;
    blitz::Array<double,4> rotated_rank4tensor = trans4_fo(rank4tensor, rot0_0_0);
    std::cout << "rotated rank4tensor {0,0,0} : " << std::endl;
    print_tensor_components_double_4_fo(rotated_rank4tensor);

    rotated_rank4tensor = trans4_fo(rank4tensor, rotPIdiv2_PIdiv2_PIdiv2);
    std::cout << "rotated rank4tensor {pi/2,pi/2,pi/2} : " << std::endl;
    print_tensor_components_double_4_fo(rotated_rank4tensor);

    rotated_rank4tensor = trans4_fo(rank4tensor, rotPI_PI_PI);
    std::cout << "rotated rank4tensor {pi,pi,pi} : " << std::endl;
    print_tensor_components_double_4_fo(rotated_rank4tensor);

    // normal vector as a function of euler angles
    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    // TODO: normal vector as a function of euler angles
    blitz::Array<double,1> normal_vector = blitz::Array<double,1>(3);
    normal_vector = 1, 0, 0;

    //mpc::transformation::EulerRotationX3X1X3<double> eulerRotation;
    //mpc::transformation::Transformer<double,1> trans_fo;
    blitz::Array<double,2> rot = eulerRotation(phi0, phi1, phi2);
    blitz::Array<double,1> rotated_vector = trans_fo(normal_vector, rot);

    for (int i=0; i<DIVISOR; ++i) {
        phi0 = (i/DBL_DIVISOR) * TWO_PI;
        for (int j=0; j<DIVISOR; ++j) {
            phi1 = (j/DBL_DIVISOR) * TWO_PI;
            for (int k=0; k<DIVISOR; ++k) {
                phi2 = (k/DBL_DIVISOR) * TWO_PI;
                //std::cout << "i : " << i << ", j : " << j << ", k : " << k << std::endl;
                //std::cout << "    {" << phi0 << "," << phi1 << "," << phi2 << "}" << std::endl;

                rot = eulerRotation(phi0, phi1, phi2);
                //std::cout << "rot : " << rot << std::endl;
                rotated_vector = trans_fo(normal_vector, rot);
                mpc::utilities::Normalize(rotated_vector);
                //std::cout << "rotated vector {0,0,0} : " << std::endl;
                print_tensor_components_double_1_fo(rotated_vector);
            }
        }
    }

}
