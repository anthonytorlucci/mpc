#include "solidphaseview2.h"

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
//#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
//#include <vtkRenderWindow.h>
//#include <vtkSmartPointer.h>
//#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
//#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkColorTransferFunction.h>
//#include <vtkSphereSource.h>
//#include <vtkPolyDataMapper.h>
//#include <vtkActor.h>

#include <QVTKOpenGLWidget.h>


// mpc
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>
#include <vtkAxis.h>


SolidPhaseView2::SolidPhaseView2(QWidget *parent) {
    // constructor

    auto solid_mixture_sand_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(sand_K), mpc::rockphysics::ShearModulusType<double>(sand_mu), mpc::rockphysics::DensityType<double>(sand_rho), mpc::rockphysics::VolumeFractionType<double>(0.0));

    auto solid_mixture_mudrock_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(mudrock_K), mpc::rockphysics::ShearModulusType<double>(mudrock_mu), mpc::rockphysics::DensityType<double>(mudrock_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));


    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > sand_mudrock_mixture_vec{
            solid_mixture_sand_tuple,
            solid_mixture_mudrock_tuple
    };

    mpc::rockphysics::SolidPhase<double> sand_mudrock_mixture = mpc::rockphysics::SolidPhase(sand_mudrock_mixture_vec);

    // Qt Controls Widget
    QWidget* controls_widget = new QWidget(this);
    interactive_checkbox = new QCheckBox(this);
    interactive_checkbox->setText("initeractive");
    interactive_checkbox->setChecked(true);
    // sand widget
    QWidget* sand_widget = new QWidget(this);
    QComboBox* sand_combobox = new QComboBox(this);
    sand_combobox->addItem("sand");
    QLabel* sand_bulkmodulus_label = new QLabel(this);
    sand_bulkmodulus_label->setText("bulk modulus: " + QString::number(sand_K));
    QLabel* sand_shearmodulus_label = new QLabel(this);
    sand_shearmodulus_label->setText("shear modulus: " + QString::number(sand_mu));
    QLabel* sand_density_label = new QLabel(this);
    sand_density_label->setText("density: " + QString::number(sand_rho));
    QHBoxLayout* sand_widget_layout = new QHBoxLayout(this);
    sand_widget_layout->addWidget(sand_combobox);
    sand_widget_layout->addWidget(sand_bulkmodulus_label);
    sand_widget_layout->addWidget(sand_shearmodulus_label);
    sand_widget_layout->addWidget(sand_density_label);
    sand_widget_layout->addStretch(1);
    sand_widget->setLayout(sand_widget_layout);
    //  mudrock widget
    QWidget* mudrock_widget = new QWidget(this);
    QComboBox* mudrock_combobox = new QComboBox(this);
    mudrock_combobox->addItem("mudrock");
    QLabel* mudrock_bulkmodulus_label = new QLabel(this);
    mudrock_bulkmodulus_label->setText("bulk modulus: " + QString::number(mudrock_K));
    QLabel* mudrock_shearmodulus_label = new QLabel(this);
    mudrock_shearmodulus_label->setText("shear modulus: " + QString::number(mudrock_mu));
    QLabel* mudrock_density_label = new QLabel(this);
    mudrock_density_label->setText("density: " + QString::number(mudrock_rho));
    QHBoxLayout* mudrock_widget_layout = new QHBoxLayout(this);
    mudrock_widget_layout->addWidget(mudrock_combobox);
    mudrock_widget_layout->addWidget(mudrock_bulkmodulus_label);
    mudrock_widget_layout->addWidget(mudrock_shearmodulus_label);
    mudrock_widget_layout->addWidget(mudrock_density_label);
    mudrock_widget_layout->addStretch(1);
    mudrock_widget->setLayout(mudrock_widget_layout);


    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(interactive_checkbox);
    controls_widget_layout->addWidget(sand_widget);
    controls_widget_layout->addWidget(mudrock_widget);
    controls_widget->setLayout(controls_widget_layout);

    // VTK
    // colors : linear gradient for vrh lines
    vtkSmartPointer<vtkColorTransferFunction> color_transfer_function = vtkSmartPointer<vtkColorTransferFunction>::New();
    color_transfer_function->AddRGBPoint(0.0, 0.0/255.0, 212.0/255.0, 1.0);
    color_transfer_function->AddRGBPoint(0.65, 9.0/255.0, 9.0/255.0, 121.0/255.0);
    color_transfer_function->AddRGBPoint(1.0, 2.0/255.0, 0.0, 36.0/255.0);
    double color_00[3];  // VRH_00
    color_transfer_function->GetColor(0.0, color_00);
    double color_02[3];  // VRH_02
    color_transfer_function->GetColor(0.2, color_02);
    double color_04[3];  // VRH_04
    color_transfer_function->GetColor(0.4, color_04);
    double color_06[3];  // VRH_06
    color_transfer_function->GetColor(0.6, color_06);
    double color_08[3];  // VRH_08
    color_transfer_function->GetColor(0.8, color_08);
    double color_10[3];  // VRH_10
    color_transfer_function->GetColor(1.0, color_10);
//    std::cout << "color_00[0]: " << color_00[0] << std::endl;
//    std::cout << "color_00[1]: " << color_00[1] << std::endl;
//    std::cout << "color_00[2]: " << color_00[2] << std::endl;
//    std::cout << "color_02[0]: " << color_02[0] << std::endl;
//    std::cout << "color_02[1]: " << color_02[1] << std::endl;
//    std::cout << "color_02[2]: " << color_02[2] << std::endl;
//    std::cout << "color_04[0]: " << color_04[0] << std::endl;
//    std::cout << "color_04[1]: " << color_04[1] << std::endl;
//    std::cout << "color_04[2]: " << color_04[2] << std::endl;
//    std::cout << "color_06[0]: " << color_06[0] << std::endl;
//    std::cout << "color_06[1]: " << color_06[1] << std::endl;
//    std::cout << "color_06[2]: " << color_06[2] << std::endl;
//    std::cout << "color_08[0]: " << color_08[0] << std::endl;
//    std::cout << "color_08[1]: " << color_08[1] << std::endl;
//    std::cout << "color_08[2]: " << color_08[2] << std::endl;
//    std::cout << "color_10[0]: " << color_10[0] << std::endl;
//    std::cout << "color_10[1]: " << color_10[1] << std::endl;
//    std::cout << "color_10[2]: " << color_10[2] << std::endl;



    // Create a table with some points in it
    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

    vtkSmartPointer<vtkFloatArray> arr_sand_volumefraction = vtkSmartPointer<vtkFloatArray>::New();
    arr_sand_volumefraction->SetName("mudrock volume fraction");  // X-axis
    table->AddColumn(arr_sand_volumefraction);  // column 0

    vtkSmartPointer<vtkFloatArray> arr_effective_K = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K->SetName("effective bulk modulus");
    table->AddColumn(arr_effective_K);  // column 1

    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_10 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_10->SetName("effective bulk modulus (VRH 1.0)");
    table->AddColumn(arr_effective_K_VRH_10);  // column 2

    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_08 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_08->SetName("effective bulk modulus (VRH 0.8)");
    table->AddColumn(arr_effective_K_VRH_08);  // column 3

    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_06 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_06->SetName("effective bulk modulus (VRH 0.6)");
    table->AddColumn(arr_effective_K_VRH_06);  // column 4

    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_04 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_04->SetName("effective bulk modulus (VRH 0.4)");
    table->AddColumn(arr_effective_K_VRH_04);  // column 5

    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_02 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_02->SetName("effective bulk modulus (VRH 0.2)");
    table->AddColumn(arr_effective_K_VRH_02);  // column 6

    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_00 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_00->SetName("effective bulk modulus (VRH 0.0)");
    table->AddColumn(arr_effective_K_VRH_00);  // column 7

    // effective shear modulus
    vtkSmartPointer<vtkFloatArray> arr_effective_mu = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu->SetName("effective shear modulus");
    table->AddColumn(arr_effective_mu);  // column 8

    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_10 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_10->SetName("effective shear modulus (VRH 1.0)");
    table->AddColumn(arr_effective_mu_VRH_10);  // column 9

    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_08 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_08->SetName("effective shear modulus (VRH 0.8)");
    table->AddColumn(arr_effective_mu_VRH_08);  // column 10

    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_06 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_06->SetName("effective shear modulus (VRH 0.6)");
    table->AddColumn(arr_effective_mu_VRH_06);  // column 11

    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_04 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_04->SetName("effective shear modulus (VRH 0.4)");
    table->AddColumn(arr_effective_mu_VRH_04);  // column 12

    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_02 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_02->SetName("effective shear modulus (VRH 0.2)");
    table->AddColumn(arr_effective_mu_VRH_02);  // column 13

    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_00 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_00->SetName("effective shear modulus (VRH 0.0)");
    table->AddColumn(arr_effective_mu_VRH_00);  // column 14

    vtkSmartPointer<vtkFloatArray> arr_effective_rho = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_rho->SetName("effective density");
    table->AddColumn(arr_effective_rho);  // column 15

    // Fill in the table ...
    int num_points = 51;  // number of points sampled along the brine saturation axis
    float sample_interval = 1.0 / (num_points - 1);
    table->SetNumberOfRows(num_points);

    std::vector<double> vf_vec_values{1.0, 0.0};
    double effective_bulkmodulus = 1.0;
    double effective_bulkmodulus_vrh10 = 1.0;
    double effective_bulkmodulus_vrh08 = 1.0;
    double effective_bulkmodulus_vrh06 = 1.0;
    double effective_bulkmodulus_vrh04 = 1.0;
    double effective_bulkmodulus_vrh02 = 1.0;
    double effective_bulkmodulus_vrh00 = 1.0;

    double effective_shearmodulus = 1.0;
    double effective_shearmodulus_vrh10 = 1.0;
    double effective_shearmodulus_vrh08 = 1.0;
    double effective_shearmodulus_vrh06 = 1.0;
    double effective_shearmodulus_vrh04 = 1.0;
    double effective_shearmodulus_vrh02 = 1.0;
    double effective_shearmodulus_vrh00 = 1.0;

    double effective_density = 1.0;

    std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_upper = sand_mudrock_mixture.VoigtUpperBound();

    std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_lower = sand_mudrock_mixture.RuessLowerBound();

    for (int i=0; i<num_points; ++i) {
        table->SetValue(i, 0, i*sample_interval);
        vf_vec_values = std::vector<double>({ 1.0 - (i*sample_interval), i*sample_interval });

        sand_mudrock_mixture.VolumeFractionTypeVector(vf_vec_values);
        kmu_upper = sand_mudrock_mixture.VoigtUpperBound();
        kmu_lower = sand_mudrock_mixture.RuessLowerBound();

        effective_bulkmodulus = sand_mudrock_mixture.EffectiveBulkModulusType().value;
        table->SetValue(i, 1, effective_bulkmodulus);

        effective_bulkmodulus_vrh10 = (kmu_upper.first.value * 1.0) + (kmu_lower.first.value * 0.0);
        table->SetValue(i, 2, effective_bulkmodulus_vrh10);

        effective_bulkmodulus_vrh08 = (kmu_upper.first.value * 0.8) + (kmu_lower.first.value * 0.2);
        table->SetValue(i, 3, effective_bulkmodulus_vrh08);

        effective_bulkmodulus_vrh06 = (kmu_upper.first.value * 0.6) + (kmu_lower.first.value * 0.4);
        table->SetValue(i, 4, effective_bulkmodulus_vrh06);

        effective_bulkmodulus_vrh04 = (kmu_upper.first.value * 0.4) + (kmu_lower.first.value * 0.6);
        table->SetValue(i, 5, effective_bulkmodulus_vrh04);

        effective_bulkmodulus_vrh02 = (kmu_upper.first.value * 0.2) + (kmu_lower.first.value * 0.8);
        table->SetValue(i, 6, effective_bulkmodulus_vrh02);

        effective_bulkmodulus_vrh00 = (kmu_upper.first.value * 0.0) + (kmu_lower.first.value * 1.0);
        table->SetValue(i, 7, effective_bulkmodulus_vrh00);

        effective_shearmodulus = sand_mudrock_mixture.EffectiveShearModulusType().value;
        table->SetValue(i, 8, effective_shearmodulus);

        effective_shearmodulus_vrh10 = (kmu_upper.second.value * 1.0) + (kmu_lower.second.value * 0.0);
        table->SetValue(i, 9, effective_shearmodulus_vrh10);

        effective_shearmodulus_vrh08 = (kmu_upper.second.value * 0.8) + (kmu_lower.second.value * 0.2);
        table->SetValue(i, 10, effective_shearmodulus_vrh08);

        effective_shearmodulus_vrh06 = (kmu_upper.second.value * 0.6) + (kmu_lower.second.value * 0.4);
        table->SetValue(i, 11, effective_shearmodulus_vrh06);

        effective_shearmodulus_vrh04 = (kmu_upper.second.value * 0.4) + (kmu_lower.second.value * 0.6);
        table->SetValue(i, 12, effective_shearmodulus_vrh04);

        effective_shearmodulus_vrh02 = (kmu_upper.second.value * 0.2) + (kmu_lower.second.value * 0.8);
        table->SetValue(i, 13, effective_shearmodulus_vrh02);

        effective_shearmodulus_vrh00 = (kmu_upper.second.value * 0.0) + (kmu_lower.second.value * 1.0);
        table->SetValue(i, 14, effective_shearmodulus_vrh00);

        effective_density = sand_mudrock_mixture.EffectiveDensityType().value;
        table->SetValue(i, 15, effective_density);

    }

    qvtkopenglwidget_K = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_K = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_K->SetRenderWindow(vtkgenericopenglwindow_K);
    vtkrenderwindow_K = qvtkopenglwidget_K->GetRenderWindow();

    // You can continue to use 'vtkrenderwindow' as a regular vtkRenderWindow
    // including adding renderers, actors, etc.

    // set up the view
    vtkcontextview_effK = vtkSmartPointer<vtkContextView>::New();
    // ++ vtkcontextview_effK->SetRenderWindow(vtkgenericopenglwindow_K);  // NOTE: generic render window !!!
    vtkcontextview_effK->SetRenderWindow(vtkrenderwindow_K);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //--vtkcontextview_effK->GetRenderer()->SetViewport(0.0, 0.0, 0.333, 1.0);

    vtkchart_effK = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effK->GetScene()->AddItem(vtkchart_effK);

    vtkPlot* line_effK = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK->SetInputData(table, 0, 1);
    line_effK->SetColor(0, 0, 255, 255);
    line_effK->SetWidth(2.0);

    // vrh (K)
    vtkPlot* line_effK_10 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_10->SetInputData(table, 0, 2);
    //line_effK_10->SetColor(10, 10, 10, 255);
    line_effK_10->SetColor(color_10[0], color_10[1], color_10[2]);
    line_effK_10->SetWidth(1.0);
    line_effK_10->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effK_08 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_08->SetInputData(table, 0, 3);
    //line_effK_08->SetColor(10, 10, 10, 255);
    line_effK_08->SetColor(color_08[0], color_08[1], color_08[2]);
    line_effK_08->SetWidth(1.0);
    line_effK_08->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effK_06 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_06->SetInputData(table, 0, 4);
    //line_effK_06->SetColor(10, 10, 10, 255);
    line_effK_06->SetColor(color_06[0], color_06[1], color_06[2]);
    line_effK_06->SetWidth(1.0);
    line_effK_06->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effK_04 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_04->SetInputData(table, 0, 5);
    //line_effK_04->SetColor(10, 10, 10, 255);
    line_effK_04->SetColor(color_04[0], color_04[1], color_04[2]);
    line_effK_04->SetWidth(1.0);
    line_effK_04->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effK_02 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_02->SetInputData(table, 0, 6);
    //line_effK_02->SetColor(10, 10, 10, 255);
    line_effK_02->SetColor(color_02[0], color_02[1], color_02[2]);
    line_effK_02->SetWidth(1.0);
    line_effK_02->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effK_00 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_00->SetInputData(table, 0, 7);
    //line_effK_00->SetColor(10, 10, 10, 255);
    line_effK_00->SetColor(color_00[0], color_00[1], color_00[2]);
    line_effK_00->SetWidth(1.0);
    line_effK_00->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart_effK->SetShowLegend(true);
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetTitle("mudrock volume fraction");
    vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetTitle("effective bulk modulus (GPa)");

    qvtkopenglwidget_mu = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_mu = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_mu->SetRenderWindow(vtkgenericopenglwindow_mu);
    vtkrenderwindow_mu = qvtkopenglwidget_mu->GetRenderWindow();

    vtkcontextview_effmu = vtkSmartPointer<vtkContextView>::New();
    // ++ vtkcontextview_effmu->SetRenderWindow(vtkgenericopenglwindow_mu);  // NOTE: generic render window !!!
    vtkcontextview_effmu->SetRenderWindow(vtkrenderwindow_mu);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //--vtkcontextview_effmu->GetRenderer()->SetViewport(0.333, 0.0, 0.666, 1.0);

    vtkchart_effmu = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effmu->GetScene()->AddItem(vtkchart_effmu);

    vtkPlot* line_effmu = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu->SetInputData(table, 0, 8);
    line_effmu->SetColor(0, 0, 255, 255);
    line_effmu->SetWidth(2.0);

    // vrh (mu)
    vtkPlot* line_effmu_10 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_10->SetInputData(table, 0, 9);
    //line_effmu_10->SetColor(10, 10, 10, 255);
    line_effmu_10->SetColor(color_10[0], color_10[1], color_10[2]);
    line_effmu_10->SetWidth(1.0);
    line_effmu_10->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effmu_08 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_08->SetInputData(table, 0, 10);
    //line_effmu_08->SetColor(10, 10, 10, 255);
    line_effmu_08->SetColor(color_08[0], color_08[1], color_08[2]);
    line_effmu_08->SetWidth(1.0);
    line_effmu_08->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effmu_06 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_06->SetInputData(table, 0, 11);
    //line_effmu_06->SetColor(10, 10, 10, 255);
    line_effmu_06->SetColor(color_06[0], color_06[1], color_06[2]);
    line_effmu_06->SetWidth(1.0);
    line_effmu_06->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effmu_04 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_04->SetInputData(table, 0, 12);
    //line_effmu_04->SetColor(10, 10, 10, 255);
    line_effmu_04->SetColor(color_04[0], color_04[1], color_04[2]);
    line_effmu_04->SetWidth(1.0);
    line_effmu_04->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effmu_02 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_02->SetInputData(table, 0, 13);
    //line_effmu_02->SetColor(10, 10, 10, 255);
    line_effmu_02->SetColor(color_02[0], color_02[1], color_02[2]);
    line_effmu_02->SetWidth(1.0);
    line_effmu_02->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkPlot* line_effmu_00 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_00->SetInputData(table, 0, 14);
    //line_effmu_00->SetColor(10, 10, 10, 255);
    line_effmu_00->SetColor(color_00[0], color_00[1], color_00[2]);
    line_effmu_00->SetWidth(1.0);
    line_effmu_00->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart_effmu->SetShowLegend(true);
    vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetTitle("mudrock volume fraction");
    vtkchart_effmu->GetAxis(vtkAxis::LEFT)->SetTitle("effective shear modulus (GPa)");

    qvtkopenglwidget_rho = new QVTKOpenGLWidget(this);
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_rho = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_rho->SetRenderWindow(vtkgenericopenglwindow_rho);
    vtkrenderwindow_rho = qvtkopenglwidget_rho->GetRenderWindow();

    vtkcontextview_effrho = vtkSmartPointer<vtkContextView>::New();
    // ++ vtkcontextview_effrho->SetRenderWindow(vtkgenericopenglwindow_rho);  // NOTE: generic render window !!!
    vtkcontextview_effrho->SetRenderWindow(vtkrenderwindow_rho);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //vtkcontextview_effrho->GetRenderer()->SetViewport(0.666, 0.0, 1.0, 1.0);

    vtkchart_effrho = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effrho->GetScene()->AddItem(vtkchart_effrho);

    vtkPlot* line_gas_effrho = vtkchart_effrho->AddPlot(vtkChart::LINE);
    line_gas_effrho->SetInputData(table, 0, 15);
    line_gas_effrho->SetColor(0, 0, 255, 255);
    line_gas_effrho->SetWidth(2.0);


    vtkchart_effrho->SetShowLegend(true);
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetTitle("mudrock volume fraction");
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetTitle("effective density (g/cm**3)");


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
    connect(interactive_checkbox, SIGNAL(stateChanged(int)), this, SLOT(OnInteractiveCheckBoxStateChanged(int)));

    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);

}

SolidPhaseView2::~SolidPhaseView2() {
    // destructor
}

// slots
void SolidPhaseView2::OnInteractiveCheckBoxStateChanged(int) {
    //
    // if interactive unchecked, set the bounds of each plot manually
    // implemented mainly for taking consistent screen captures
    if (interactive_checkbox->isChecked()) {
        //
        //vtkchart_effK->SetDrawAxesAtOrigin(true);
        vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetRange(15.0, 16.5);
        vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetBehavior(vtkAxis::FIXED);
        vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetRange(0, 1.0);
        vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetBehavior(vtkAxis::FIXED);
        vtkchart_effK->RecalculateBounds();
        vtkchart_effK->Update();

        //vtkchart_effmu->SetDrawAxesAtOrigin(true);
        vtkchart_effmu->GetAxis(vtkAxis::LEFT)->SetRange(4.0, 7.0);
        vtkchart_effmu->GetAxis(vtkAxis::LEFT)->SetBehavior(vtkAxis::FIXED);
        vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetRange(0, 1.0);
        vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetBehavior(vtkAxis::FIXED);
        vtkchart_effmu->RecalculateBounds();
        vtkchart_effmu->Update();

        //vtkchart_effrho->SetDrawAxesAtOrigin(true);
        vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetRange(2.2, 2.5);
        vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetBehavior(vtkAxis::FIXED);
        vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetRange(0, 1.0);
        vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetBehavior(vtkAxis::FIXED);
        vtkchart_effrho->RecalculateBounds();
        vtkchart_effrho->Update();

    } else {
        //
        //vtkchart_effK->SetDrawAxesAtOrigin(true);
        vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetBehavior(vtkAxis::AUTO);
        vtkchart_effK->GetAxis(vtkAxis::LEFT)->AutoScale();
        vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetBehavior(vtkAxis::AUTO);
        vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->AutoScale();
        vtkchart_effK->RecalculateBounds();
        vtkchart_effK->Update();

        //vtkchart_effmu->SetDrawAxesAtOrigin(true);
        vtkchart_effmu->GetAxis(vtkAxis::LEFT)->SetBehavior(vtkAxis::AUTO);
        vtkchart_effmu->GetAxis(vtkAxis::LEFT)->AutoScale();
        vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetBehavior(vtkAxis::AUTO);
        vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->AutoScale();
        vtkchart_effmu->RecalculateBounds();
        vtkchart_effmu->Update();

        //vtkchart_effrho->SetDrawAxesAtOrigin(true);
        vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetBehavior(vtkAxis::AUTO);
        vtkchart_effrho->GetAxis(vtkAxis::LEFT)->AutoScale();
        vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetBehavior(vtkAxis::AUTO);
        vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->AutoScale();
        vtkchart_effrho->RecalculateBounds();
        vtkchart_effrho->Update();

    }
}

// member functions