#include "mpcx_moreeulerangles.hpp"

// c++
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/utilities/printtensorcomponents.hpp>
#include <mpc/utilities/constants.hpp>
#include <mpc/utilities/norm.hpp>
#include <mpc/transformation/eulerrotation.hpp>
#include <mpc/transformation/transformer.hpp>
#include <mpc/utilities/coordinatemapping.hpp>
#include <mpc/utilities/magnitude.hpp>

void mpcexamples::mpcMoreEulerAngles() {
    /** more euler angles */
    /*
     * are there any duplicate vectors?
     */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    mpc::utilities::PrintTensorComponents<double,1> print_tensor_components_double_1_fo;
    mpc::utilities::PrintTensorComponents<double,2> print_tensor_components_double_2_fo;
    mpc::utilities::PrintTensorComponents<double,4> print_tensor_components_double_4_fo;

    // euler rotation
    const double PI = mpc::utilities::PI<double>;
    const double TWO_PI = 2.0 * PI;
    const double PI_OVER_TWO = 0.5 * PI;
    const int DIVISOR = 8;
    const double DBL_DIVISOR = double(DIVISOR);
    // Euler transformation tensor
    double phi0 = 0.0;
    double phi1 = 0.0;
    double phi2 = 0.0;
    const int NUM_ROTATIONS = int(std::pow(DBL_DIVISOR,3));
    //std::cout << "NUM_ROTATIONS : " << NUM_ROTATIONS << std::endl;

    mpc::transformation::EulerRotationX3X1X3<double> euler_rotation_fo;

    blitz::Array<double,2> transformation_tensor = euler_rotation_fo(phi0, phi1, phi2);
    //std::cout << "transformation_tensor : " << transformation_tensor << std::endl;

    std::vector< std::tuple<double,double,double> >init_vec_x1(NUM_ROTATIONS);
    std::vector< std::tuple<double,double,double> >search_vec_x1(NUM_ROTATIONS);

    std::vector< std::tuple<double,double,double> >init_vec_x2(NUM_ROTATIONS);
    std::vector< std::tuple<double,double,double> >search_vec_x2(NUM_ROTATIONS);

    std::vector< std::tuple<double,double,double> >init_vec_x3(NUM_ROTATIONS);
    std::vector< std::tuple<double,double,double> >search_vec_x3(NUM_ROTATIONS);

    blitz::Array<double,1> normal_vector_x1 = blitz::Array<double,1>(3);
    normal_vector_x1 = 1.0, 0.0, 0.0;
    blitz::Array<double,1> normal_vector_x2 = blitz::Array<double,1>(3);
    normal_vector_x2 = 0.0, 1.0, 0.0;
    blitz::Array<double,1> normal_vector_x3 = blitz::Array<double,1>(3);
    normal_vector_x3 = 0.0, 0.0, 1.0;

    std::vector< std::tuple<double,double,double> > euler_angles(NUM_ROTATIONS);

    int cntr = 0;
    double tmp0 = 0;
    double tmp1 = 0;
    double tmp2 = 0;
    for (int i=0; i<DIVISOR; ++i) {
        phi0 = (i/DBL_DIVISOR) * TWO_PI;
        for (int j=0; j<DIVISOR; ++j) {
            phi1 = (j/DBL_DIVISOR) * TWO_PI;
            for (int k=0; k<DIVISOR; ++k) {
                phi2 = (k/DBL_DIVISOR) * TWO_PI;
                //std::cout << "i : " << i << ", j : " << j << ", k : " << k << std::endl;
                //std::cout << "    {" << phi0 << "," << phi1 << "," << phi2 << "}" << std::endl;

                blitz::Array<double,2> transformation_tensor = euler_rotation_fo(phi0, phi1, phi2);
                //std::cout << "transformation_tensor : " << transformation_tensor << std::endl;

                normal_vector_x1 = transformation_tensor(blitz::Range::all(),0);
                mpc::utilities::Normalize(normal_vector_x1);  // minimize rounding errors
                //std::cout << "rotated normal vector x1 : " << std::endl;
                //print_tensor_components_double_1_fo(normal_vector_x1);
                tmp0 = normal_vector_x1(0);
                tmp1 = normal_vector_x1(1);
                tmp2 = normal_vector_x1(2);
                init_vec_x1[cntr] = std::make_tuple(tmp0, tmp1, tmp2);
                search_vec_x1[cntr] = std::make_tuple(tmp0, tmp1, tmp2);

                normal_vector_x2 = transformation_tensor(blitz::Range::all(),1);
                mpc::utilities::Normalize(normal_vector_x2);  // minimize rounding errors
                //std::cout << "rotated normal vector x2 : " << std::endl;
                //print_tensor_components_double_1_fo(normal_vector_x2);
                tmp0 = normal_vector_x2(0);
                tmp1 = normal_vector_x2(1);
                tmp2 = normal_vector_x2(2);
                init_vec_x2[cntr] = std::make_tuple(tmp0, tmp1, tmp2);
                search_vec_x2[cntr] = std::make_tuple(tmp0, tmp1, tmp2);

                normal_vector_x3 = transformation_tensor(blitz::Range::all(),2);
                mpc::utilities::Normalize(normal_vector_x3);  // minimize rounding errors
                //std::cout << "rotated normal vector x1 : " << std::endl;
                //print_tensor_components_double_1_fo(normal_vector_x1);
                tmp0 = normal_vector_x3(0);
                tmp1 = normal_vector_x3(1);
                tmp2 = normal_vector_x3(2);
                init_vec_x3[cntr] = std::make_tuple(tmp0, tmp1, tmp2);
                search_vec_x3[cntr] = std::make_tuple(tmp0, tmp1, tmp2);

                euler_angles[cntr] = std::make_tuple(phi0, phi1, phi2);

                ++cntr;
            }
        }
    }
    //std::cout << "counter : " << cntr << std::endl;

    // search for duplicates by comparing init_vec and search_vec
    bool b0 = false;
    bool b1 = false;
    bool b2 = false;
    bool bdup = false;
    std::tuple<double,double,double> v{};
    std::tuple<double,double,double> vsearch{};
    double tmp0_search = 0;
    double tmp1_search = 0;
    double tmp2_search = 0;
    cntr = 0;  // reset cntr
    // x1 vec
    for (int m=0; m< NUM_ROTATIONS; ++m) {
        v = init_vec_x1[m];
        tmp0 = std::get<0>(v);
        tmp1 = std::get<1>(v);
        tmp2 = std::get<2>(v);
        for (int n=0; n<NUM_ROTATIONS; ++n) {
            vsearch = search_vec_x1[n];
            tmp0_search = std::get<0>(vsearch);
            tmp1_search = std::get<1>(vsearch);
            tmp2_search = std::get<2>(vsearch);

            b0 = (tmp0 == tmp0_search) ? true : false;
            b1 = (tmp1 == tmp1_search) ? true : false;
            b2 = (tmp2 == tmp2_search) ? true : false;

            if((b0 && b1) && b2) {
                bdup = true;
                //std::cout << "duplicate found!" << std::endl;
            }

            ++ cntr;
        }
    }




}  // END FUNCTION
