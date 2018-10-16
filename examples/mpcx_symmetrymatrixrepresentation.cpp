#include "mpcx_symmetrymatrixrepresentation.hpp"

// c++
#include <iostream>
#include <iomanip>

// mpc
#include <mpc/core/stiffnesscompliance.hpp>
#include <mpc/data/mineraldatatensors.hpp>

void mpcexamples::mpcSymmetryMatrixRepresentation() {
    // component index
    std::cout << "" << std::endl;

    //mpc::core::StiffnessTensor<double> stiffness_tensor;
    //mpc::core::StiffnessTensor<double> stiffness_tensor2;

    // pointer to stiffness tensor test
    //mpc::core::StiffnessTensor<double>* p_stiffness_tensor = new mpc::core::StiffnessTensor<double>();

    std::cout << std::setw(6);
    // mineral data tensors
    // Augite
    mpc::core::StiffnessTensor<double> augite_stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();
    std::cout << "\nAugite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << augite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;


    // Albite
    mpc::core::StiffnessTensor<double> albite_stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();
    std::cout << "\nAlbite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << albite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Anorthite
    mpc::core::StiffnessTensor<double> anorthite_stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();
    std::cout << "\nAnorthite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anorthite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Labradorite
    mpc::core::StiffnessTensor<double> labradorite_stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();
    std::cout << "\nLabradorite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << labradorite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Microcline
    mpc::core::StiffnessTensor<double> microcline_stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();
    std::cout << "\nMicrocline Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << microcline_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Oligoclase
    mpc::core::StiffnessTensor<double> oligoclase_stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();
    std::cout << "\nOligoclase Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << oligoclase_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Coesite
    mpc::core::StiffnessTensor<double> coesite_stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();
    std::cout << "\nCoesite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << coesite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Epidote
    mpc::core::StiffnessTensor<double> epidote_stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();
    std::cout << "\nEpidote Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << epidote_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Hornblende
    mpc::core::StiffnessTensor<double> hornblende_stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();
    std::cout << "\nHornblende Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << hornblende_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Muscovite
    mpc::core::StiffnessTensor<double> muscovite_stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();
    std::cout << "\nMuscovite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << muscovite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Gypsum
    mpc::core::StiffnessTensor<double> gypsum_stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();
    std::cout << "\nGypsum Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << gypsum_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Enstatite
    mpc::core::StiffnessTensor<double> enstatite_stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();
    std::cout << "\nEnstatite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << enstatite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Forsterite
    mpc::core::StiffnessTensor<double> forsterite_stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();
    std::cout << "\nForsterite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << forsterite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Fayalite
    mpc::core::StiffnessTensor<double> fayalite_stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();
    std::cout << "\nFayalite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fayalite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Montecellite
    mpc::core::StiffnessTensor<double> montecellite_stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();
    std::cout << "\nMontecellite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << montecellite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Andalusite
    mpc::core::StiffnessTensor<double> andalusite_stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();
    std::cout << "\nAndalusite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << andalusite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Silimanite
    mpc::core::StiffnessTensor<double> silimanite_stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();
    std::cout << "\nSilimanite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << silimanite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Barite
    mpc::core::StiffnessTensor<double> barite_stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();
    std::cout << "\nBarite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << barite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Anhydrite
    mpc::core::StiffnessTensor<double> anhydrite_stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();
    std::cout << "\nAnhydrite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << anhydrite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Dolomite
    mpc::core::StiffnessTensor<double> dolomite_stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();
    std::cout << "\nDolomite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << dolomite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Rutile
    mpc::core::StiffnessTensor<double> rutile_stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();
    std::cout << "\nRutile Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << rutile_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Zircon
    mpc::core::StiffnessTensor<double> zircon_stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();
    std::cout << "\nZircon Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << zircon_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Corundum
    mpc::core::StiffnessTensor<double> corundum_stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();
    std::cout << "\nCorundum Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << corundum_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Calcite
    mpc::core::StiffnessTensor<double> calcite_stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();
    std::cout << "\nCalcite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << calcite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Quartz
    mpc::core::StiffnessTensor<double> quartz_stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
    std::cout << "\nQuartz Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << quartz_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Tourmaline
    mpc::core::StiffnessTensor<double> tourmaline_stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();
    std::cout << "\nTourmaline Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << tourmaline_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Beryl
    mpc::core::StiffnessTensor<double> beryl_stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();
    std::cout << "\nBeryl Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << beryl_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Graphite
    mpc::core::StiffnessTensor<double> graphite_stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();
    std::cout << "\nGraphite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << graphite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Wusite
    mpc::core::StiffnessTensor<double> wusite_stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();
    std::cout << "\nWusite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << wusite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Manganosite
    mpc::core::StiffnessTensor<double> manganosite_stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();
    std::cout << "\nManganosite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << manganosite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Periclase
    mpc::core::StiffnessTensor<double> periclase_stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();
    std::cout << "\nPericlase Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << periclase_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Magnetite
    mpc::core::StiffnessTensor<double> magnetite_stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();
    std::cout << "\nMagnetite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << magnetite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Chromite
    mpc::core::StiffnessTensor<double> chromite_stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();
    std::cout << "\nChromite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << chromite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Spinel
    mpc::core::StiffnessTensor<double> spinel_stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();
    std::cout << "\nSpinel Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << spinel_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Pyrite
    mpc::core::StiffnessTensor<double> pyrite_stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();
    std::cout << "\nPyrite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << pyrite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Galena
    mpc::core::StiffnessTensor<double> galena_stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();
    std::cout << "\nGalena Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << galena_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Sphalerite
    mpc::core::StiffnessTensor<double> sphalerite_stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();
    std::cout << "\nSphalerite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sphalerite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Fluorite
    mpc::core::StiffnessTensor<double> fluorite_stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();
    std::cout << "\nFluorite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << fluorite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Halite
    mpc::core::StiffnessTensor<double> halite_stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();
    std::cout << "\nHalite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << halite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

    // Sylvite
    mpc::core::StiffnessTensor<double> sylvite_stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();
    std::cout << "\nSylvite Stiffness Tensor in Voigt Matrix Notation" << std::endl;
    std::cout << "kl/ij   [0]    [1]    [2]    [3]    [4]    [5]" << std::endl;
    std::cout << " [0] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,0,0) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,0,0) << " "
              << std::endl;
    std::cout << " [1] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,1,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,1,1) << " "
              << std::endl;
    std::cout << " [2] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,2,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,2,2) << " "
              << std::endl;
    std::cout << " [3] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,1,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,1,2) << " "
              << std::endl;
    std::cout << " [4] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,0,2) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,0,2) << " "
              << std::endl;
    std::cout << " [5] "  << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,0,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,1,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(2,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(1,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,2,0,1) << " "
              << std::setw(6) << std::setprecision(6) << sylvite_stiffness_tensor.tensor(0,1,0,1) << " "
              << std::endl;

}
