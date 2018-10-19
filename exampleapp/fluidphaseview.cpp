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

    // Qt Controls Widget
    QWidget* controls_widget = new QWidget(this);
    interactive_checkbox = new QCheckBox(this);
    interactive_checkbox->setText("initeractive");
    interactive_checkbox->setChecked(true);
    // background fluid widget
    QWidget* background_fluid_widget = new QWidget(this);
    QComboBox* background_fluid_combobox = new QComboBox(this);
    background_fluid_combobox->addItem("brine");
    QLabel* background_fluid_bulkmodulus_label = new QLabel(this);
    background_fluid_bulkmodulus_label->setText("bulk modulus: " + QString::number(brine_K));
    QLabel* background_fluid_shearmodulus_label = new QLabel(this);
    background_fluid_shearmodulus_label->setText("shear modulus: " + QString::number(0.0));
    QLabel* background_fluid_density_label = new QLabel(this);
    background_fluid_density_label->setText("density: " + QString::number(brine_rho));
    QHBoxLayout* background_fluid_widget_layout = new QHBoxLayout(this);
    background_fluid_widget_layout->addWidget(background_fluid_combobox);
    background_fluid_widget_layout->addWidget(background_fluid_bulkmodulus_label);
    background_fluid_widget_layout->addWidget(background_fluid_shearmodulus_label);
    background_fluid_widget_layout->addWidget(background_fluid_density_label);
    background_fluid_widget_layout->addStretch(1);
    background_fluid_widget->setLayout(background_fluid_widget_layout);
    //  fluid0 widget
    QWidget* fluid0_widget = new QWidget(this);
    QComboBox* fluid0_combobox = new QComboBox(this);
    fluid0_combobox->addItem("oil");
    QLabel* fluid0_bulkmodulus_label = new QLabel(this);
    fluid0_bulkmodulus_label->setText("bulk modulus: " + QString::number(oil_K));
    QLabel* fluid0_shearmodulus_label = new QLabel(this);
    fluid0_shearmodulus_label->setText("shear modulus: " + QString::number(0.0));
    QLabel* fluid0_density_label = new QLabel(this);
    fluid0_density_label->setText("density: " + QString::number(oil_rho));
    QHBoxLayout* fluid0_widget_layout = new QHBoxLayout(this);
    fluid0_widget_layout->addWidget(fluid0_combobox);
    fluid0_widget_layout->addWidget(fluid0_bulkmodulus_label);
    fluid0_widget_layout->addWidget(fluid0_shearmodulus_label);
    fluid0_widget_layout->addWidget(fluid0_density_label);
    fluid0_widget_layout->addStretch(1);
    fluid0_widget->setLayout(fluid0_widget_layout);
    //  fluid1 widget
    QWidget* fluid1_widget = new QWidget(this);
    QComboBox* fluid1_combobox = new QComboBox(this);
    fluid1_combobox->addItem("gas");
    QLabel* fluid1_bulkmodulus_label = new QLabel(this);
    fluid1_bulkmodulus_label->setText("bulk modulus: " + QString::number(gas_K));
    QLabel* fluid1_shearmodulus_label = new QLabel(this);
    fluid1_shearmodulus_label->setText("shear modulus: " + QString::number(0.0));
    QLabel* fluid1_density_label = new QLabel(this);
    fluid1_density_label->setText("density: " + QString::number(gas_rho));
    QHBoxLayout* fluid1_widget_layout = new QHBoxLayout(this);
    fluid1_widget_layout->addWidget(fluid1_combobox);
    fluid1_widget_layout->addWidget(fluid1_bulkmodulus_label);
    fluid1_widget_layout->addWidget(fluid1_shearmodulus_label);
    fluid1_widget_layout->addWidget(fluid1_density_label);
    fluid1_widget_layout->addStretch(1);
    fluid1_widget->setLayout(fluid1_widget_layout);

    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(interactive_checkbox);
    controls_widget_layout->addWidget(background_fluid_widget);
    controls_widget_layout->addWidget(fluid0_widget);
    controls_widget_layout->addWidget(fluid1_widget);
    controls_widget->setLayout(controls_widget_layout);

    // VTK
    // Create a table with some points in it
    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

    vtkSmartPointer<vtkFloatArray> arr_brine_saturation = vtkSmartPointer<vtkFloatArray>::New();
    arr_brine_saturation->SetName("brine saturation");  // X-axis
    table->AddColumn(arr_brine_saturation);  // column 0

    vtkSmartPointer<vtkFloatArray> arr_gas_effective_K = vtkSmartPointer<vtkFloatArray>::New();
    arr_gas_effective_K->SetName("gas effective bulk modulus");
    table->AddColumn(arr_gas_effective_K);  // column 1

    vtkSmartPointer<vtkFloatArray> arr_oil_effective_K = vtkSmartPointer<vtkFloatArray>::New();
    arr_oil_effective_K->SetName("oil effective bulk modulus");
    table->AddColumn(arr_oil_effective_K);  // column 2

    vtkSmartPointer<vtkFloatArray> arr_gas_effective_mu = vtkSmartPointer<vtkFloatArray>::New();
    arr_gas_effective_mu->SetName("gas effective shear modulus");
    table->AddColumn(arr_gas_effective_mu);  // column 3

    vtkSmartPointer<vtkFloatArray> arr_oil_effective_mu = vtkSmartPointer<vtkFloatArray>::New();
    arr_oil_effective_mu->SetName("oil effective shear modulus");
    table->AddColumn(arr_oil_effective_mu);  // column 4

    vtkSmartPointer<vtkFloatArray> arr_gas_effective_rho = vtkSmartPointer<vtkFloatArray>::New();
    arr_gas_effective_rho->SetName("gas effective density");
    table->AddColumn(arr_gas_effective_rho);  // column 5

    vtkSmartPointer<vtkFloatArray> arr_oil_effective_rho = vtkSmartPointer<vtkFloatArray>::New();
    arr_oil_effective_rho->SetName("oil effective density");
    table->AddColumn(arr_oil_effective_rho);  // column 6

    // Fill in the table ...
    int num_points = 51;  // number of points sampled along the brine saturation axis
    float sample_interval = 1.0 / (num_points - 1);
    table->SetNumberOfRows(num_points);

    std::vector<double> vf_vec_values{1.0, 0.0};
    double gas_brine_effective_bulkmodulus = 1.0;
    double oil_brine_effective_bulkmodulus = 1.0;
    double gas_brine_effective_shearmodulus = 1.0;
    double oil_brine_effective_shearmodulus = 1.0;
    double gas_brine_effective_density = 1.0;
    double oil_brine_effective_density = 1.0;

    for (int i=0; i<num_points; ++i) {
        table->SetValue(i, 0, i*sample_interval);
        vf_vec_values = std::vector<double>({ 1.0 - (i*sample_interval), i*sample_interval });

        gas_brine_mixture.VolumeFractionTypeVector(vf_vec_values);
        gas_brine_effective_bulkmodulus = gas_brine_mixture.EffectiveBulkModulusType().value;
        table->SetValue(i, 1, gas_brine_effective_bulkmodulus);
        gas_brine_effective_shearmodulus = gas_brine_mixture.EffectiveShearModulusType().value;
        table->SetValue(i, 3, gas_brine_effective_shearmodulus);
        gas_brine_effective_density = gas_brine_mixture.EffectiveDensityType().value;
        table->SetValue(i, 5, gas_brine_effective_density);

        oil_brine_mixture.VolumeFractionTypeVector(vf_vec_values);
        oil_brine_effective_bulkmodulus = oil_brine_mixture.EffectiveBulkModulusType().value;
        table->SetValue(i, 2, oil_brine_effective_bulkmodulus);
        oil_brine_effective_shearmodulus = oil_brine_mixture.EffectiveShearModulusType().value;
        table->SetValue(i, 4, oil_brine_effective_shearmodulus);
        oil_brine_effective_density = oil_brine_mixture.EffectiveDensityType().value;
        table->SetValue(i, 6, oil_brine_effective_density);

    }

    qvtkopenglwidget = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget->SetRenderWindow(vtkgenericopenglwindow);
    vtkrenderwindow = qvtkopenglwidget->GetRenderWindow();

    // You can continue to use 'vtkrenderwindow' as a regular vtkRenderWindow
    // including adding renderers, actors, etc.

    // set up the view
    vtkcontextview_effK = vtkSmartPointer<vtkContextView>::New();
    vtkcontextview_effK->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    vtkcontextview_effK->GetRenderer()->SetViewport(0.0, 0.0, 0.333, 1.0);

    vtkchart_effK = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effK->GetScene()->AddItem(vtkchart_effK);

    vtkPlot* line_gas_effK = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_gas_effK->SetInputData(table, 0, 1);
    line_gas_effK->SetColor(0, 0, 255, 255);
    line_gas_effK->SetWidth(2.0);

    vtkPlot* line_oil_effK = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_oil_effK->SetInputData(table, 0, 2);
    line_oil_effK->SetColor(255, 0, 0, 255);
    line_oil_effK->SetWidth(2.0);
    // For dotted line, ...
    //line->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart_effK->SetShowLegend(true);
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetTitle("effective bulk modulus (GPa)");

    vtkcontextview_effmu = vtkSmartPointer<vtkContextView>::New();
    vtkcontextview_effmu->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    vtkcontextview_effmu->GetRenderer()->SetViewport(0.333, 0.0, 0.666, 1.0);

    vtkchart_effmu = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effmu->GetScene()->AddItem(vtkchart_effmu);

    vtkPlot* line_gas_effmu = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_gas_effmu->SetInputData(table, 0, 3);
    line_gas_effmu->SetColor(0, 0, 255, 255);
    line_gas_effmu->SetWidth(2.0);

    vtkPlot* line_oil_effmu = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_oil_effmu->SetInputData(table, 0, 4);
    line_oil_effmu->SetColor(255, 0, 0, 255);
    line_oil_effmu->SetWidth(2.0);
    // For dotted line, ...
    //line->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart_effmu->SetShowLegend(true);
    vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart_effmu->GetAxis(vtkAxis::LEFT)->SetTitle("effective shear modulus (GPa)");

    vtkcontextview_effrho = vtkSmartPointer<vtkContextView>::New();
    vtkcontextview_effrho->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    vtkcontextview_effrho->GetRenderer()->SetViewport(0.666, 0.0, 1.0, 1.0);

    vtkchart_effrho = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effrho->GetScene()->AddItem(vtkchart_effrho);

    vtkPlot* line_gas_effrho = vtkchart_effrho->AddPlot(vtkChart::LINE);
    line_gas_effrho->SetInputData(table, 0, 5);
    line_gas_effrho->SetColor(0, 0, 255, 255);
    line_gas_effrho->SetWidth(2.0);

    vtkPlot* line_oil_effrho = vtkchart_effrho->AddPlot(vtkChart::LINE);
    line_oil_effrho->SetInputData(table, 0, 6);
    line_oil_effrho->SetColor(255, 0, 0, 255);
    line_oil_effrho->SetWidth(2.0);
    // For dotted line, ...
    //line->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart_effrho->SetShowLegend(true);
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetTitle("effective density (g/cm**3)");


    // main splitter
    QSplitter* splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(controls_widget);
    splitter->addWidget(qvtkopenglwidget);

    /* === signals/slots === */
    //connect(fluid_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnFluidComboBoxChanged(int)));
    //connect(hill_average_slider, SIGNAL(sliderReleased()), this, SLOT(OnHillAverageSliderReleased()));

    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);

}

FluidPhaseView::~FluidPhaseView() {
    // destructor
}

// slots


// member functions