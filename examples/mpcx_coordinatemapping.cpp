#include "mpcx_coordinatemapping.hpp"

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
#include <mpc/utilities/functionsbase.hpp>

void mpcexamples::mpcCoordinateMapping() {
    /** coordinate mapping */
    /*
     * are there any duplicate vectors?
     */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

//    const int DIVISOR = 8;
//    const double DBL_DIVISOR = double(DIVISOR);
//    const int NUM_ROTATIONS = int(std::pow(DBL_DIVISOR,3));

    const int NUM_ELEMS = 4;

    const double PI = mpc::utilities::PI<double>;
    const double TWO_PI = 2.0 * PI;
    const double PI_OVER_TWO = 0.5 * PI;

    double colattitude = 0;  // relative to x3 axis
    double azimuth = 0;      // in 2d plane
    double smallradius = 0;  // in 2d plane
    double x = 0;
    double y = 0;
    double z = 0;
    double xyarg = 0;
    double mag = 0;
    int cntr = 0;

    blitz::Array<double,1> normal_vector = blitz::Array<double,1>(3);
    normal_vector = 1,0,0;

    mpc::utilities::CoordinateMapping<double,mpc::utilities::CartesianCoordinateType,mpc::utilities::CylindricalCoordinateType> coordinate_mapping_fo;

    std::tuple<double,double,double> coords{};


//    coords = coordinate_mapping_fo(smallradius,azimuth,0);  // set z to zero for the x-y plane
//    x = std::get<0>(coords);
//    y = std::get<1>(coords);
//    z = 1.0 * cos(colattitude);  //  here, 1.0 is the radius of the hemisphere, i.e. the desired length of the vector
//
//    // display the coords
//    std::cout << "x : " << x << ", y : " << y << ", z :" << z << std::endl;
//    normal_vector = x, y, z;
//    mag = mpc::utilities::Magnitude(normal_vector);
//    std::cout << "magnitude : " << mag << std::endl;  // obviously, this should be one

    // =================================================================================================================
    /* (x,y) on a disk */
    std::cout << "mapping on a disk" << std::endl;
    std::vector<double> small_radius_linspace = mpc::utilities::Linspace(0.0 + (1.0 / NUM_ELEMS), 1.0, NUM_ELEMS);  // (0,1]
//    for (auto v : small_radius_linspace) {
//        std::cout << v << std::endl;
//    }
    std::vector<double> azimuth_linspace = mpc::utilities::Linspace(0.0, TWO_PI - (TWO_PI/double(NUM_ELEMS)), NUM_ELEMS);  // [0,2pi)
//    for (auto v : azimuth_linspace) {
//        std::cout << v << std::endl;
//    }

    for (auto rho : small_radius_linspace) {
        //
        for (auto theta : azimuth_linspace) {
            //
            coords = coordinate_mapping_fo(rho,theta,0);  // set z to zero for the x-y plane
            x = std::get<0>(coords);
            y = std::get<1>(coords);
            //z = std::get<2>(coords);
            xyarg = std::abs(1.0 - std::pow(x,2) - std::pow(y,2));
            z = sqrt(xyarg);
            normal_vector = x, y, z;
            std::cout << rho << ", " << theta << std::endl;
            std::cout << xyarg << std::endl;
            std::cout << normal_vector << std::endl;
            mag = mpc::utilities::Magnitude(normal_vector);
            //std::cout << "magnitude : " << mag << std::endl;  // obviously, this should be one

            // corresponding negative
            z *= -1.0;
            normal_vector = x, y, z;
            std::cout << normal_vector << std::endl;
            mag = mpc::utilities::Magnitude(normal_vector);
            //std::cout << "magnitude : " << mag << std::endl;  // obviously, this should be one
        }
    }




}  // END FUNCTION
