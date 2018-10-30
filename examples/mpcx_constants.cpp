#include "mpcx_constants.hpp"

// c++
#include <iostream>
#include <cmath>

// blitz

// mpc
#include <mpc/utilities/constants.hpp>


void mpcexamples::mpcConstants() {
    /** constants */

    std::cout << "" << std::endl;
    std::cout << std::boolalpha;

    const float fPI = mpc::utilities::PI<float>;
    const float fTWO_PI = 2.0 * fPI;
    const float fPI_OVER_TWO = 0.5 * fPI;

    std::cout << "PI /2  : " << fPI_OVER_TWO << std::endl;
    std::cout << "PI     : " << fPI << std::endl;
    std::cout << "TWO PI : " << fTWO_PI << std::endl;

    const double PI = mpc::utilities::PI<double>;
    const double TWO_PI = 2.0 * PI;
    const double PI_OVER_TWO = 0.5 * PI;

    std::cout << "PI /2  : " << PI_OVER_TWO << std::endl;
    std::cout << "PI     : " << PI << std::endl;
    std::cout << "TWO PI : " << TWO_PI << std::endl;

    const long double longPI = mpc::utilities::PI<long double>;
    const long double longTWO_PI = 2.0 * longPI;
    const long double longPI_OVER_TWO = 0.5 * longPI;

    std::cout << "PI /2  : " << longPI_OVER_TWO << std::endl;
    std::cout << "PI     : " << longPI << std::endl;
    std::cout << "TWO PI : " << longTWO_PI << std::endl;


}  // END FUNCTION
