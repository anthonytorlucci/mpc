#include "mpcx_fluidphase.hpp"

// c++
#include <iostream>
#include <vector>
#include <tuple>

// mpc
//#include <mpc/utilities/arithmeticaverage.hpp>
//#include <mpc/utilities/harmonicaverage.hpp>
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>

// vtk
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <vtkAxis.h>

void mpcexamples::mpcFluidPhase() {
    /** fluid phase */
    std::cout << "" << std::endl;

    double gas_K = 0.0435;  // GPa
    double gas_rho = 0.1770;  // g/cm**3

    double oil_K = 0.3922;  // GPa
    double oil_rho = 0.6359;  // g/cm**3

    double brine_K = 2.6819;  // GPa
    double brine_rho = 1.0194;  // g/cm**3

    auto fluid_mixture_gas_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(gas_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(gas_rho), mpc::rockphysics::VolumeFractionType<double>(0.2));

    auto fluid_mixture_oil_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(oil_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(oil_rho), mpc::rockphysics::VolumeFractionType<double>(0.3));

    auto fluid_mixture_brine_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(brine_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(brine_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

    //auto brine_K_type = std::get<0>(fluid_mixture_brine_tuple);

    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > fluid_mixture_vec{
        fluid_mixture_gas_tuple,
        fluid_mixture_oil_tuple,
        fluid_mixture_brine_tuple
    };

    mpc::rockphysics::FluidPhase<double> fluid_mixture = mpc::rockphysics::FluidPhase(fluid_mixture_vec);

    std::vector< mpc::rockphysics::BulkModulusType<double> > fluid_mixture_K_type_vec = fluid_mixture.BulkModulusTypeVector();
    std::vector< mpc::rockphysics::ShearModulusType<double> > fluid_mixture_mu_type_vec = fluid_mixture.ShearModulusTypeVector();
    std::vector< mpc::rockphysics::DensityType<double> > fluid_mixture_rho_type_vec = fluid_mixture.DensityTypeVector();
    std::vector< mpc::rockphysics::VolumeFractionType<double> > fluid_mixture_vf_type_vec = fluid_mixture.VolumeFractionTypeVector();

    for (int i=0; i<fluid_mixture_K_type_vec.size(); ++i) {
        std::cout << "component " << i << std::endl;
        std::cout << "fluid mixture K type : " << fluid_mixture_K_type_vec[i].value << std::endl;
        std::cout << "fluid mixture mu type : " << fluid_mixture_mu_type_vec[i].value << std::endl;
        std::cout << "fluid mixture rho type : " << fluid_mixture_rho_type_vec[i].value << std::endl;
        std::cout << "fluid mixture vf type : " << fluid_mixture_vf_type_vec[i].value << std::endl;
        std::cout << "" << std::endl;
    }

    mpc::rockphysics::BulkModulusType<double> fluid_mixture_effective_bulkmodulus = fluid_mixture.EffectiveBulkModulusType();
    std::cout << "fluid mixture effective bulkmodulus value: " << fluid_mixture_effective_bulkmodulus.value << std::endl;
    mpc::rockphysics::ShearModulusType<double> fluid_mixture_effective_shearmodulus = fluid_mixture.EffectiveShearModulusType();
    std::cout << "fluid mixture effective shearmodulus value: " << fluid_mixture_effective_shearmodulus.value << std::endl;
    mpc::rockphysics::DensityType<double> fluid_mixture_effective_density = fluid_mixture.EffectiveDensityType();
    std::cout << "fluid mixture effective density value: " << fluid_mixture_effective_density.value << std::endl;

    // change volume fraction values
    std::vector<double> vf_new{0.7,0.2,0.1};
    fluid_mixture.VolumeFractionTypeVector(vf_new);

    std::vector< mpc::rockphysics::VolumeFractionType<double> > fluid_mixture_vf_type_vec_new = fluid_mixture.VolumeFractionTypeVector();

    std::cout << "" << std::endl;
    for (int i=0; i<fluid_mixture_vf_type_vec_new.size(); ++i) {
        std::cout << "component " << i << std::endl;
        //std::cout << "fluid mixture K type : " << fluid_mixture_K_type_vec[i].value << std::endl;
        //std::cout << "fluid mixture mu type : " << fluid_mixture_mu_type_vec[i].value << std::endl;
        //std::cout << "fluid mixture rho type : " << fluid_mixture_rho_type_vec[i].value << std::endl;
        std::cout << "fluid mixture vf type new : " << fluid_mixture_vf_type_vec_new[i].value << std::endl;
        std::cout << "" << std::endl;
    }

    mpc::rockphysics::BulkModulusType<double> fluid_mixture_effective_bulkmodulus_new = fluid_mixture.EffectiveBulkModulusType();
    std::cout << "fluid mixture effective bulkmodulus value new: " << fluid_mixture_effective_bulkmodulus_new.value << std::endl;
    mpc::rockphysics::ShearModulusType<double> fluid_mixture_effective_shearmodulus_new = fluid_mixture.EffectiveShearModulusType();
    std::cout << "fluid mixture effective shearmodulus value new: " << fluid_mixture_effective_shearmodulus_new.value << std::endl;
    mpc::rockphysics::DensityType<double> fluid_mixture_effective_density_new = fluid_mixture.EffectiveDensityType();
    std::cout << "fluid mixture effective density value new: " << fluid_mixture_effective_density_new.value << std::endl;


    // =================================================================================================================
    // VTK brine saturation plot

//    auto fluid_mixture_gas_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(gas_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(gas_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));
//
//    auto fluid_mixture_oil_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(oil_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(oil_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));
//
//    auto fluid_mixture_brine_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(brine_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(brine_rho), mpc::rockphysics::VolumeFractionType<double>(0.0));

//    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > gas_brine_mixture_vec{
//            fluid_mixture_gas_tuple,
//            fluid_mixture_brine_tuple
//    };
//
//    mpc::rockphysics::FluidPhase<double> gas_brine_mixture = mpc::rockphysics::FluidPhase(gas_brine_mixture_vec);
//
//    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > oil_brine_mixture_vec{
//            fluid_mixture_oil_tuple,
//            fluid_mixture_brine_tuple
//    };
//
//    mpc::rockphysics::FluidPhase<double> oil_brine_mixture = mpc::rockphysics::FluidPhase(oil_brine_mixture_vec);
//
//    // Create a table with some points in it
//    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();
//
//    vtkSmartPointer<vtkFloatArray> arr_brine_saturation = vtkSmartPointer<vtkFloatArray>::New();
//    arr_brine_saturation->SetName("brine saturation");  // X-axis
//    table->AddColumn(arr_brine_saturation);  // column 0
//
//    vtkSmartPointer<vtkFloatArray> arr_gas_effective_K = vtkSmartPointer<vtkFloatArray>::New();
//    arr_gas_effective_K->SetName("gas effective bulk modulus");
//    table->AddColumn(arr_gas_effective_K);  // column 1
//
//    vtkSmartPointer<vtkFloatArray> arr_oil_effective_K = vtkSmartPointer<vtkFloatArray>::New();
//    arr_oil_effective_K->SetName("oil effective bulk modulus");
//    table->AddColumn(arr_oil_effective_K);  // column 2
//
//    vtkSmartPointer<vtkFloatArray> arr_gas_effective_mu = vtkSmartPointer<vtkFloatArray>::New();
//    arr_gas_effective_mu->SetName("gas effective shear modulus");
//    table->AddColumn(arr_gas_effective_mu);  // column 3
//
//    vtkSmartPointer<vtkFloatArray> arr_oil_effective_mu = vtkSmartPointer<vtkFloatArray>::New();
//    arr_oil_effective_mu->SetName("oil effective shear modulus");
//    table->AddColumn(arr_oil_effective_mu);  // column 4
//
//    vtkSmartPointer<vtkFloatArray> arr_gas_effective_rho = vtkSmartPointer<vtkFloatArray>::New();
//    arr_gas_effective_rho->SetName("gas effective density");
//    table->AddColumn(arr_gas_effective_rho);  // column 5
//
//    vtkSmartPointer<vtkFloatArray> arr_oil_effective_rho = vtkSmartPointer<vtkFloatArray>::New();
//    arr_oil_effective_rho->SetName("oil effective density");
//    table->AddColumn(arr_oil_effective_rho);  // column 6
//
//    // Fill in the table ...
//    int num_points = 51;  // number of points sampled along the brine saturation axis
//    float sample_interval = 1.0 / (num_points - 1);
//    table->SetNumberOfRows(num_points);
//
//    std::vector<double> vf_vec_values{1.0, 0.0};
//    double gas_brine_effective_bulkmodulus = 1.0;
//    double oil_brine_effective_bulkmodulus = 1.0;
//    double gas_brine_effective_shearmodulus = 1.0;
//    double oil_brine_effective_shearmodulus = 1.0;
//    double gas_brine_effective_density = 1.0;
//    double oil_brine_effective_density = 1.0;
//
//    for (int i=0; i<num_points; ++i) {
//        table->SetValue(i, 0, i*sample_interval);
//        vf_vec_values = std::vector<double>({ 1.0 - (i*sample_interval), i*sample_interval });
//
//        gas_brine_mixture.VolumeFractionTypeVector(vf_vec_values);
//        gas_brine_effective_bulkmodulus = gas_brine_mixture.EffectiveBulkModulusType().value;
//        table->SetValue(i, 1, gas_brine_effective_bulkmodulus);
//        gas_brine_effective_shearmodulus = gas_brine_mixture.EffectiveShearModulusType().value;
//        table->SetValue(i, 3, gas_brine_effective_shearmodulus);
//        gas_brine_effective_density = gas_brine_mixture.EffectiveDensityType().value;
//        table->SetValue(i, 5, gas_brine_effective_density);
//
//        oil_brine_mixture.VolumeFractionTypeVector(vf_vec_values);
//        oil_brine_effective_bulkmodulus = oil_brine_mixture.EffectiveBulkModulusType().value;
//        table->SetValue(i, 2, oil_brine_effective_bulkmodulus);
//        oil_brine_effective_shearmodulus = oil_brine_mixture.EffectiveShearModulusType().value;
//        table->SetValue(i, 4, oil_brine_effective_shearmodulus);
//        oil_brine_effective_density = oil_brine_mixture.EffectiveDensityType().value;
//        table->SetValue(i, 6, oil_brine_effective_density);
//
//    }
//
//    // Set up the view
//    vtkSmartPointer<vtkContextView> view =
//            vtkSmartPointer<vtkContextView>::New();
//    view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
//
//    // Add multiple line plots, setting the colors etc
//    vtkSmartPointer<vtkChartXY> chart =
//            vtkSmartPointer<vtkChartXY>::New();
//    view->GetScene()->AddItem(chart);
//    vtkPlot *line = chart->AddPlot(vtkChart::LINE);
//#if VTK_MAJOR_VERSION <= 5
//    line->SetInput(table, 0, 1);
//#else
//    line->SetInputData(table, 0, 1);  // 1 : gas effective bulk modulus; 5 : gas effective density
//#endif
//    line->SetColor(255, 0, 0, 255);
//    line->SetWidth(2.0);
//    line = chart->AddPlot(vtkChart::LINE);
//#if VTK_MAJOR_VERSION <= 5
//    line->SetInput(table, 0, 2);
//#else
//    line->SetInputData(table, 0, 2);  // 2 : oil effective bulk modulus; 6 : oil effective density
//#endif
//    line->SetColor(0, 255, 0, 255);
//    line->SetWidth(2.0);
//
//    // For dotted line, the line type can be from 2 to 5 for different dash/dot
//    // patterns (see enum in vtkPen containing DASH_LINE, value 2):
//#ifndef WIN32
//    //line->GetPen()->SetLineType(vtkPen::DASH_LINE);
//#endif
//    // (ifdef-ed out on Windows because DASH_LINE does not work on Windows
//    //  machines with built-in Intel HD graphics card...)
//
//    //view->GetRenderWindow()->SetMultiSamples(0);
//
//    chart->SetShowLegend(true);
//    chart->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
//    chart->GetAxis(vtkAxis::LEFT)->SetTitle("effective bulk modulus (GPa)");
//
//    // Start interactor
//    view->GetInteractor()->Initialize();
//    view->GetInteractor()->Start();


}


