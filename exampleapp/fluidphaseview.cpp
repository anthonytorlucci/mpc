#include "fluidphaseview.h"

// c++
#include <iostream>
#include <vector>
#include <tuple>

// Qt
#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSurfaceFormat>
#include <QSplitter>

// VTK
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
//#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

#include <QVTKOpenGLWidget.h>


// mpc
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>
#include <vtkAxis.h>


FluidPhaseView::FluidPhaseView(QWidget *parent) {
    // constructor

    auto fluid_mixture_gas_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(gas_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(gas_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));

    auto fluid_mixture_oil_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(oil_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(oil_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));

    auto fluid_mixture_brine_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(brine_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(brine_rho), mpc::rockphysics::VolumeFractionType<double>(0.0));

    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > gas_brine_mixture_vec{
            fluid_mixture_gas_tuple,
            fluid_mixture_brine_tuple
    };

    mpc::rockphysics::FluidPhase<double> gas_brine_mixture = mpc::rockphysics::FluidPhase(gas_brine_mixture_vec);

    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > oil_brine_mixture_vec{
            fluid_mixture_oil_tuple,
            fluid_mixture_brine_tuple
    };

    mpc::rockphysics::FluidPhase<double> oil_brine_mixture = mpc::rockphysics::FluidPhase(oil_brine_mixture_vec);

//    mpc::rockphysics::BulkModulusType<double> fluid_mixture_effective_bulkmodulus = fluid_mixture.EffectiveBulkModulusType();
//    std::cout << "fluid mixture effective bulkmodulus value: " << fluid_mixture_effective_bulkmodulus.value << std::endl;
//    mpc::rockphysics::ShearModulusType<double> fluid_mixture_effective_shearmodulus = fluid_mixture.EffectiveShearModulusType();
//    std::cout << "fluid mixture effective shearmodulus value: " << fluid_mixture_effective_shearmodulus.value << std::endl;
//    mpc::rockphysics::DensityType<double> fluid_mixture_effective_density = fluid_mixture.EffectiveDensityType();
//    std::cout << "fluid mixture effective density value: " << fluid_mixture_effective_density.value << std::endl;
//
//    // change volume fraction values
//    std::vector<double> vf_new{0.7,0.2,0.1};
//    fluid_mixture.VolumeFractionTypeVector(vf_new);

    // VTK
    // Create a table with some points in it
    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

    vtkSmartPointer<vtkFloatArray> arr_brine_saturation = vtkSmartPointer<vtkFloatArray>::New();
    arr_brine_saturation->SetName("brine saturation");  // X-axis
    table->AddColumn(arr_brine_saturation);

    vtkSmartPointer<vtkFloatArray> arr_gas_effective_K = vtkSmartPointer<vtkFloatArray>::New();
    arr_gas_effective_K->SetName("gas effective bulk modulus");
    table->AddColumn(arr_gas_effective_K);

    vtkSmartPointer<vtkFloatArray> arr_oil_effective_K = vtkSmartPointer<vtkFloatArray>::New();
    arr_oil_effective_K->SetName("oil effective bulk modulus");
    table->AddColumn(arr_oil_effective_K);

    // Fill in the table ...
    int num_points = 51;  // number of points sampled along the brine saturation axis
    float sample_interval = 1.0 / (num_points - 1);
    table->SetNumberOfRows(num_points);

    std::vector<double> vf_vec_values{1.0, 0.0};
    double gas_brine_effective_bulkmodulus = 1.0;
    double oil_brine_effective_bulkmodulus = 1.0;
    for (int i=0; i<num_points; ++i) {
        table->SetValue(i, 0, i*sample_interval);
        vf_vec_values = std::vector<double>({ 1.0 - (i*sample_interval), i*sample_interval });

        gas_brine_mixture.VolumeFractionTypeVector(vf_vec_values);
        gas_brine_effective_bulkmodulus = gas_brine_mixture.EffectiveBulkModulusType().value;
        table->SetValue(i, 1, gas_brine_effective_bulkmodulus);

        oil_brine_mixture.VolumeFractionTypeVector(vf_vec_values);
        oil_brine_effective_bulkmodulus = oil_brine_mixture.EffectiveBulkModulusType().value;
        table->SetValue(i, 2, oil_brine_effective_bulkmodulus);
    }

    qvtkopenglwidget = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget->SetRenderWindow(vtkgenericopenglwindow);
    vtkrenderwindow = qvtkopenglwidget->GetRenderWindow();

    // You can continue to use 'vtkrenderwindow' as a regular vtkRenderWindow
    // including adding renderers, actors, etc.

    // set up the view
    vtkcontextview = vtkSmartPointer<vtkContextView>::New();
    vtkcontextview->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient

    vtkchart = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview->GetScene()->AddItem(vtkchart);

    vtkPlot *line = vtkchart->AddPlot(vtkChart::LINE);
    line->SetInputData(table, 0, 1);
    line->SetColor(0, 0, 255, 255);
    line->SetWidth(2.0);

    line = vtkchart->AddPlot(vtkChart::LINE);
    line->SetInputData(table, 0, 2);
    line->SetColor(255, 0, 0, 255);
    line->SetWidth(2.0);
    // For dotted line, ...
    //line->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart->SetShowLegend(true);
    vtkchart->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart->GetAxis(vtkAxis::LEFT)->SetTitle("effective bulk modulus (GPa)");


    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(qvtkopenglwidget);
    setLayout(layout);
}

FluidPhaseView::~FluidPhaseView() {
    // destructor
}

// slots


// member functions