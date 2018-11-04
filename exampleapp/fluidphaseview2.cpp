#include "fluidphaseview2.h"

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
#include <QTabWidget>

// VTK
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
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
#include <vtkChartLegend.h>

#include <QVTKOpenGLWidget.h>


// mpc
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>
#include <vtkAxis.h>


FluidPhaseView2::FluidPhaseView2(QWidget *parent) {
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
    // fluids box
    QGroupBox* fluids_groupbox = new QGroupBox("fluids", this);
    background_fluid_label = new QLabel(this);
    background_fluid_label->setText("background fluid");
    background_fluid_combobox = new QComboBox(this);
    background_fluid_combobox->addItem("brine");
    background_fluid_bulkmodulus_label = new QLabel(this);
    background_fluid_bulkmodulus_label->setText("bulk modulus");
    background_fluid_bulkmodulus_value_lineedit = new QLineEdit(this);
    background_fluid_bulkmodulus_value_lineedit->setText(QString::number(brine_K));
    background_fluid_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    background_fluid_bulkmodulus_value_lineedit->setReadOnly(true);
    background_fluid_shearmodulus_label = new QLabel(this);
    background_fluid_shearmodulus_label->setText("shear modulus");
    background_fluid_shearmodulus_value_lineedit = new QLineEdit(this);
    background_fluid_shearmodulus_value_lineedit->setText(QString::number(0.0));
    background_fluid_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    background_fluid_shearmodulus_value_lineedit->setReadOnly(true);
    background_fluid_density_label = new QLabel(this);
    background_fluid_density_label->setText("density");
    background_fluid_density_value_lineedit = new QLineEdit(this);
    background_fluid_density_value_lineedit->setText(QString::number(brine_rho));
    background_fluid_density_value_lineedit->setAlignment(Qt::AlignCenter);
    background_fluid_density_value_lineedit->setReadOnly(true);
    foreground_fluid1_label = new QLabel(this);
    foreground_fluid1_label->setText("foreground fluid (1)");
    foreground_fluid1_combobox = new QComboBox(this);
    foreground_fluid1_combobox->addItem("oil");
    foreground_fluid1_bulkmodulus_label = new QLabel(this);
    foreground_fluid1_bulkmodulus_label->setText("bulk modulus");
    foreground_fluid1_bulkmodulus_value_lineedit = new QLineEdit(this);
    foreground_fluid1_bulkmodulus_value_lineedit->setText(QString::number(oil_K));
    foreground_fluid1_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid1_bulkmodulus_value_lineedit->setReadOnly(true);
    foreground_fluid1_shearmodulus_label = new QLabel(this);
    foreground_fluid1_shearmodulus_label->setText("shear modulus");
    foreground_fluid1_shearmodulus_value_lineedit = new QLineEdit(this);
    foreground_fluid1_shearmodulus_value_lineedit->setText(QString::number(0.0));
    foreground_fluid1_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid1_shearmodulus_value_lineedit->setReadOnly(true);
    foreground_fluid1_density_label = new QLabel(this);
    foreground_fluid1_density_label->setText("density");
    foreground_fluid1_density_value_lineedit = new QLineEdit(this);
    foreground_fluid1_density_value_lineedit->setText(QString::number(oil_rho));
    foreground_fluid1_density_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid1_density_value_lineedit->setReadOnly(true);

    foreground_fluid2_label = new QLabel(this);
    foreground_fluid2_label->setText("foreground fluid (2)");
    foreground_fluid2_combobox = new QComboBox(this);
    foreground_fluid2_combobox->addItem("oil");
    foreground_fluid2_bulkmodulus_label = new QLabel(this);
    foreground_fluid2_bulkmodulus_label->setText("bulk modulus");
    foreground_fluid2_bulkmodulus_value_lineedit = new QLineEdit(this);
    foreground_fluid2_bulkmodulus_value_lineedit->setText(QString::number(gas_K));
    foreground_fluid2_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid2_bulkmodulus_value_lineedit->setReadOnly(true);
    foreground_fluid2_shearmodulus_label = new QLabel(this);
    foreground_fluid2_shearmodulus_label->setText("shear modulus");
    foreground_fluid2_shearmodulus_value_lineedit = new QLineEdit(this);
    foreground_fluid2_shearmodulus_value_lineedit->setText(QString::number(0.0));
    foreground_fluid2_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid2_shearmodulus_value_lineedit->setReadOnly(true);
    foreground_fluid2_density_label = new QLabel(this);
    foreground_fluid2_density_label->setText("density");
    foreground_fluid2_density_value_lineedit = new QLineEdit(this);
    foreground_fluid2_density_value_lineedit->setText(QString::number(gas_rho));
    foreground_fluid2_density_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid2_density_value_lineedit->setReadOnly(true);
    QGridLayout* fluids_groupbox_layout = new QGridLayout(this);
    fluids_groupbox_layout->addWidget(background_fluid_label, 0, 0);
    fluids_groupbox_layout->addWidget(background_fluid_combobox, 0, 1);
    fluids_groupbox_layout->addWidget(background_fluid_bulkmodulus_label, 0, 2);
    fluids_groupbox_layout->addWidget(background_fluid_bulkmodulus_value_lineedit, 0, 3);
    fluids_groupbox_layout->addWidget(background_fluid_shearmodulus_label, 0, 4);
    fluids_groupbox_layout->addWidget(background_fluid_shearmodulus_value_lineedit, 0, 5);
    fluids_groupbox_layout->addWidget(background_fluid_density_label, 0, 6);
    fluids_groupbox_layout->addWidget(background_fluid_density_value_lineedit, 0, 7);
    fluids_groupbox_layout->addWidget(foreground_fluid1_label, 1, 0);
    fluids_groupbox_layout->addWidget(foreground_fluid1_combobox, 1, 1);
    fluids_groupbox_layout->addWidget(foreground_fluid1_bulkmodulus_label, 1, 2);
    fluids_groupbox_layout->addWidget(foreground_fluid1_bulkmodulus_value_lineedit, 1, 3);
    fluids_groupbox_layout->addWidget(foreground_fluid1_shearmodulus_label, 1, 4);
    fluids_groupbox_layout->addWidget(foreground_fluid1_shearmodulus_value_lineedit, 1, 5);
    fluids_groupbox_layout->addWidget(foreground_fluid1_density_label, 1, 6);
    fluids_groupbox_layout->addWidget(foreground_fluid1_density_value_lineedit, 1, 7);
    fluids_groupbox_layout->addWidget(foreground_fluid2_label, 2, 0);
    fluids_groupbox_layout->addWidget(foreground_fluid2_combobox, 2, 1);
    fluids_groupbox_layout->addWidget(foreground_fluid2_bulkmodulus_label, 2, 2);
    fluids_groupbox_layout->addWidget(foreground_fluid2_bulkmodulus_value_lineedit, 2, 3);
    fluids_groupbox_layout->addWidget(foreground_fluid2_shearmodulus_label, 2, 4);
    fluids_groupbox_layout->addWidget(foreground_fluid2_shearmodulus_value_lineedit, 2, 5);
    fluids_groupbox_layout->addWidget(foreground_fluid2_density_label, 2, 6);
    fluids_groupbox_layout->addWidget(foreground_fluid2_density_value_lineedit, 2, 7);
    fluids_groupbox->setLayout(fluids_groupbox_layout);

    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(fluids_groupbox);
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

    qvtkopenglwidget_K = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_K = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_K->SetRenderWindow(vtkgenericopenglwindow_K);
    vtkrenderwindow_K = qvtkopenglwidget_K->GetRenderWindow();

    // You can continue to use 'vtkrenderwindow' as a regular vtkRenderWindow
    // including adding renderers, actors, etc.

    // set up the view
    vtkcontextview_effK = vtkSmartPointer<vtkContextView>::New();
    // ++ vtkcontextview_effK->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    vtkcontextview_effK->SetRenderWindow(vtkrenderwindow_K);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //--vtkcontextview_effK->GetRenderer()->SetViewport(0.0, 0.0, 0.333, 1.0);

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

    vtkSmartPointer<vtkChartLegend> vtkchartlegend_effK = vtkchart_effK->GetLegend();
    vtkchartlegend_effK->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effK->SetShowLegend(true);
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->GetTitleProperties()->SetFontSize(font_size);
    vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetTitle("effective bulk modulus (GPa)");
    vtkchart_effK->GetAxis(vtkAxis::LEFT)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effK->GetAxis(vtkAxis::LEFT)->GetTitleProperties()->SetFontSize(font_size);


    qvtkopenglwidget_mu = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_mu = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_mu->SetRenderWindow(vtkgenericopenglwindow_mu);
    vtkrenderwindow_mu = qvtkopenglwidget_mu->GetRenderWindow();

    vtkcontextview_effmu = vtkSmartPointer<vtkContextView>::New();
    // ++ vtkcontextview_effmu->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    vtkcontextview_effmu->SetRenderWindow(vtkrenderwindow_mu);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //--vtkcontextview_effmu->GetRenderer()->SetViewport(0.333, 0.0, 0.666, 1.0);

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

    vtkSmartPointer<vtkChartLegend> vtkchartlegend_effmu = vtkchart_effmu->GetLegend();
    vtkchartlegend_effmu->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effmu->SetShowLegend(true);
    vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->GetTitleProperties()->SetFontSize(font_size);
    vtkchart_effmu->GetAxis(vtkAxis::LEFT)->SetTitle("effective shear modulus (GPa)");
    vtkchart_effmu->GetAxis(vtkAxis::LEFT)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effmu->GetAxis(vtkAxis::LEFT)->GetTitleProperties()->SetFontSize(font_size);

    qvtkopenglwidget_rho = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_rho = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_rho->SetRenderWindow(vtkgenericopenglwindow_rho);
    vtkrenderwindow_rho = qvtkopenglwidget_rho->GetRenderWindow();

    vtkcontextview_effrho = vtkSmartPointer<vtkContextView>::New();
    // ++ vtkcontextview_effrho->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    vtkcontextview_effrho->SetRenderWindow(vtkrenderwindow_rho);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //--vtkcontextview_effrho->GetRenderer()->SetViewport(0.666, 0.0, 1.0, 1.0);

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

    vtkSmartPointer<vtkChartLegend> vtkchartlegend_effrho = vtkchart_effrho->GetLegend();
    vtkchartlegend_effrho->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effrho->SetShowLegend(true);
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetTitle("brine saturation");
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->GetTitleProperties()->SetFontSize(font_size);
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetTitle("effective density (g/cm**3)");
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->GetTitleProperties()->SetFontSize(font_size);

    // VTK views widget
//    QWidget* views_widget = new QWidget(this);
//    QHBoxLayout* views_widget_layout = new QHBoxLayout(this);
//    views_widget_layout->addWidget(qvtkopenglwidget_K);
//    views_widget_layout->addWidget(qvtkopenglwidget_mu);
//    views_widget_layout->addWidget(qvtkopenglwidget_rho);
//    views_widget->setLayout(views_widget_layout);
    QTabWidget* views_tabwidget = new QTabWidget(this);
    views_tabwidget->addTab(qvtkopenglwidget_K, "bulk modulus");
    views_tabwidget->addTab(qvtkopenglwidget_mu, "shear modulus");
    views_tabwidget->addTab(qvtkopenglwidget_rho, "density");

    // main splitter
    QSplitter* splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(controls_widget);
    //splitter->addWidget(qvtkopenglwidget);
    //splitter->addWidget(views_widget);
    splitter->addWidget(views_tabwidget);

    /* === signals/slots === */


    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);

}

FluidPhaseView2::~FluidPhaseView2() {
    // destructor
}

// slots


// member functions