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
#include <vtkRenderWindowInteractor.h>
#include <vtkPlot.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkColorTransferFunction.h>
#include <vtkTextProperty.h>

#include <QVTKOpenGLWidget.h>
#include <vtkAxis.h>

// mpc
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>
#include <mpc/data/mineraldataproperties.hpp>


SolidPhaseView2::SolidPhaseView2(QWidget *parent) {
    // constructor

    background_K = mpc::data::QuartzBulkModulus<double>();
    background_mu = mpc::data::QuartzShearModulus<double>();
    background_rho = mpc::data::QuartzDensity<double>();

    foreground_K = mpc::data::MuscoviteBulkModulus<double>();
    foreground_mu = mpc::data::MuscoviteShearModulus<double>();
    foreground_rho = mpc::data::MuscoviteDensity<double>();

    num_points = 51;  // number of points sampled along the brine saturation axis
    sample_interval = 1.0 / (num_points - 1);

    // Qt Controls Widget
    QWidget* controls_widget = new QWidget(this);

    // solids box
    QGroupBox* solids_groupbox = new QGroupBox("solids", this);
    background_label = new QLabel(this);
    background_label->setText("background solid");
    background_combobox = new QComboBox(this);
    background_combobox->addItem(QStringLiteral("Augite"));
    background_combobox->addItem(QStringLiteral("Albite"));
    background_combobox->addItem(QStringLiteral("Anorthite"));
    background_combobox->addItem(QStringLiteral("Labradorite"));
    background_combobox->addItem(QStringLiteral("Microcline"));
    background_combobox->addItem(QStringLiteral("Oligoclase"));
    background_combobox->addItem(QStringLiteral("Coesite"));
    background_combobox->addItem(QStringLiteral("Epidote"));
    background_combobox->addItem(QStringLiteral("Hornblende"));
    background_combobox->addItem(QStringLiteral("Muscovite"));
    background_combobox->addItem(QStringLiteral("Gypsum"));
    background_combobox->addItem(QStringLiteral("Enstatite"));
    background_combobox->addItem(QStringLiteral("Forsterite"));
    background_combobox->addItem(QStringLiteral("Fayalite"));
    background_combobox->addItem(QStringLiteral("Montecellite"));
    background_combobox->addItem(QStringLiteral("Andalusite"));
    background_combobox->addItem(QStringLiteral("Silimanite"));
    background_combobox->addItem(QStringLiteral("Barite"));
    background_combobox->addItem(QStringLiteral("Anhydrite"));
    background_combobox->addItem(QStringLiteral("Dolomite"));
    background_combobox->addItem(QStringLiteral("Rutile"));
    background_combobox->addItem(QStringLiteral("Zircon"));
    background_combobox->addItem(QStringLiteral("Corundum"));
    background_combobox->addItem(QStringLiteral("Calcite"));
    background_combobox->addItem(QStringLiteral("Quartz"));
    background_combobox->addItem(QStringLiteral("Tourmaline"));
    background_combobox->addItem(QStringLiteral("Beryl"));
    background_combobox->addItem(QStringLiteral("Graphite"));
    background_combobox->addItem(QStringLiteral("Wusite"));
    background_combobox->addItem(QStringLiteral("Manganosite"));
    background_combobox->addItem(QStringLiteral("Periclase"));
    background_combobox->addItem(QStringLiteral("Magnetite"));
    background_combobox->addItem(QStringLiteral("Chromite"));
    background_combobox->addItem(QStringLiteral("Spinel"));
    background_combobox->addItem(QStringLiteral("Pyrite"));
    background_combobox->addItem(QStringLiteral("Galena"));
    background_combobox->addItem(QStringLiteral("Sphalerite"));
    background_combobox->addItem(QStringLiteral("Fluorite"));
    background_combobox->addItem(QStringLiteral("Halite"));
    background_combobox->addItem(QStringLiteral("Sylvite"));
    background_combobox->setCurrentIndex(24);
    background_bulkmodulus_label = new QLabel(this);
    background_bulkmodulus_label->setText("bulk modulus");
    background_bulkmodulus_value_lineedit = new QLineEdit(this);
    background_bulkmodulus_value_lineedit->setText(QString::number(background_K));
    background_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    background_bulkmodulus_value_lineedit->setReadOnly(true);
    background_shearmodulus_label = new QLabel(this);
    background_shearmodulus_label->setText("shear modulus");
    background_shearmodulus_value_lineedit = new QLineEdit(this);
    background_shearmodulus_value_lineedit->setText(QString::number(background_mu));
    background_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    background_shearmodulus_value_lineedit->setReadOnly(true);
    background_density_label = new QLabel(this);
    background_density_label->setText("density");
    background_density_value_lineedit = new QLineEdit(this);
    background_density_value_lineedit->setText(QString::number(background_rho));
    background_density_value_lineedit->setAlignment(Qt::AlignCenter);
    background_density_value_lineedit->setReadOnly(true);
    foreground_label = new QLabel(this);
    foreground_label->setText("foreground solid");
    foreground_combobox = new QComboBox(this);
    foreground_combobox->addItem(QStringLiteral("Augite"));
    foreground_combobox->addItem(QStringLiteral("Albite"));
    foreground_combobox->addItem(QStringLiteral("Anorthite"));
    foreground_combobox->addItem(QStringLiteral("Labradorite"));
    foreground_combobox->addItem(QStringLiteral("Microcline"));
    foreground_combobox->addItem(QStringLiteral("Oligoclase"));
    foreground_combobox->addItem(QStringLiteral("Coesite"));
    foreground_combobox->addItem(QStringLiteral("Epidote"));
    foreground_combobox->addItem(QStringLiteral("Hornblende"));
    foreground_combobox->addItem(QStringLiteral("Muscovite"));
    foreground_combobox->addItem(QStringLiteral("Gypsum"));
    foreground_combobox->addItem(QStringLiteral("Enstatite"));
    foreground_combobox->addItem(QStringLiteral("Forsterite"));
    foreground_combobox->addItem(QStringLiteral("Fayalite"));
    foreground_combobox->addItem(QStringLiteral("Montecellite"));
    foreground_combobox->addItem(QStringLiteral("Andalusite"));
    foreground_combobox->addItem(QStringLiteral("Silimanite"));
    foreground_combobox->addItem(QStringLiteral("Barite"));
    foreground_combobox->addItem(QStringLiteral("Anhydrite"));
    foreground_combobox->addItem(QStringLiteral("Dolomite"));
    foreground_combobox->addItem(QStringLiteral("Rutile"));
    foreground_combobox->addItem(QStringLiteral("Zircon"));
    foreground_combobox->addItem(QStringLiteral("Corundum"));
    foreground_combobox->addItem(QStringLiteral("Calcite"));
    foreground_combobox->addItem(QStringLiteral("Quartz"));
    foreground_combobox->addItem(QStringLiteral("Tourmaline"));
    foreground_combobox->addItem(QStringLiteral("Beryl"));
    foreground_combobox->addItem(QStringLiteral("Graphite"));
    foreground_combobox->addItem(QStringLiteral("Wusite"));
    foreground_combobox->addItem(QStringLiteral("Manganosite"));
    foreground_combobox->addItem(QStringLiteral("Periclase"));
    foreground_combobox->addItem(QStringLiteral("Magnetite"));
    foreground_combobox->addItem(QStringLiteral("Chromite"));
    foreground_combobox->addItem(QStringLiteral("Spinel"));
    foreground_combobox->addItem(QStringLiteral("Pyrite"));
    foreground_combobox->addItem(QStringLiteral("Galena"));
    foreground_combobox->addItem(QStringLiteral("Sphalerite"));
    foreground_combobox->addItem(QStringLiteral("Fluorite"));
    foreground_combobox->addItem(QStringLiteral("Halite"));
    foreground_combobox->addItem(QStringLiteral("Sylvite"));
    foreground_combobox->setCurrentIndex(9);
    foreground_bulkmodulus_label = new QLabel(this);
    foreground_bulkmodulus_label->setText("bulk modulus");
    foreground_bulkmodulus_value_lineedit = new QLineEdit(this);
    foreground_bulkmodulus_value_lineedit->setText(QString::number(foreground_K));  // default muscovite
    foreground_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_bulkmodulus_value_lineedit->setReadOnly(true);
    foreground_shearmodulus_label = new QLabel(this);
    foreground_shearmodulus_label->setText("shear modulus");
    foreground_shearmodulus_value_lineedit = new QLineEdit(this);
    foreground_shearmodulus_value_lineedit->setText(QString::number(foreground_mu));  // default muscovite
    foreground_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_shearmodulus_value_lineedit->setReadOnly(true);
    foreground_density_label = new QLabel(this);
    foreground_density_label->setText("density");
    foreground_density_value_lineedit = new QLineEdit(this);
    foreground_density_value_lineedit->setText(QString::number(foreground_rho));  // default muscovite
    foreground_density_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_density_value_lineedit->setReadOnly(true);
    QGridLayout* solids_groupbox_layout = new QGridLayout(this);
    solids_groupbox_layout->addWidget(background_label, 0, 0);
    solids_groupbox_layout->addWidget(background_combobox, 0, 1);
    solids_groupbox_layout->addWidget(background_bulkmodulus_label, 0, 2);
    solids_groupbox_layout->addWidget(background_bulkmodulus_value_lineedit, 0, 3);
    solids_groupbox_layout->addWidget(background_shearmodulus_label, 0, 4);
    solids_groupbox_layout->addWidget(background_shearmodulus_value_lineedit, 0, 5);
    solids_groupbox_layout->addWidget(background_density_label, 0, 6);
    solids_groupbox_layout->addWidget(background_density_value_lineedit, 0, 7);
    solids_groupbox_layout->addWidget(foreground_label, 1, 0);
    solids_groupbox_layout->addWidget(foreground_combobox, 1, 1);
    solids_groupbox_layout->addWidget(foreground_bulkmodulus_label, 1, 2);
    solids_groupbox_layout->addWidget(foreground_bulkmodulus_value_lineedit, 1, 3);
    solids_groupbox_layout->addWidget(foreground_shearmodulus_label, 1, 4);
    solids_groupbox_layout->addWidget(foreground_shearmodulus_value_lineedit, 1, 5);
    solids_groupbox_layout->addWidget(foreground_density_label, 1, 6);
    solids_groupbox_layout->addWidget(foreground_density_value_lineedit, 1, 7);
    solids_groupbox->setLayout(solids_groupbox_layout);


    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(solids_groupbox);
    controls_widget->setLayout(controls_widget_layout);

    // VTK
    // colors : linear gradient for vrh lines
    color_transfer_function = vtkSmartPointer<vtkColorTransferFunction>::New();
    color_transfer_function->AddRGBPoint(0.0, 0.0/255.0, 212.0/255.0, 1.0);
    color_transfer_function->AddRGBPoint(0.65, 9.0/255.0, 9.0/255.0, 121.0/255.0);
    color_transfer_function->AddRGBPoint(1.0, 2.0/255.0, 0.0, 36.0/255.0);
    color_transfer_function->GetColor(0.0, color_00);
    color_transfer_function->GetColor(0.2, color_02);
    color_transfer_function->GetColor(0.4, color_04);
    color_transfer_function->GetColor(0.6, color_06);
    color_transfer_function->GetColor(0.8, color_08);
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
    table = vtkSmartPointer<vtkTable>::New();
    //table->SetNumberOfRows(num_points);

    arr_sand_volumefraction = vtkSmartPointer<vtkFloatArray>::New();
    arr_sand_volumefraction->SetName("background volume fraction");  // X-axis
    table->AddColumn(arr_sand_volumefraction);  // column 0

    arr_effective_K = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K->SetName("effective bulk modulus");
    table->AddColumn(arr_effective_K);  // column 1

    arr_effective_K_VRH_10 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_10->SetName("effective bulk modulus (VRH 1.0)");
    table->AddColumn(arr_effective_K_VRH_10);  // column 2

    arr_effective_K_VRH_08 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_08->SetName("effective bulk modulus (VRH 0.8)");
    table->AddColumn(arr_effective_K_VRH_08);  // column 3

    arr_effective_K_VRH_06 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_06->SetName("effective bulk modulus (VRH 0.6)");
    table->AddColumn(arr_effective_K_VRH_06);  // column 4

    arr_effective_K_VRH_04 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_04->SetName("effective bulk modulus (VRH 0.4)");
    table->AddColumn(arr_effective_K_VRH_04);  // column 5

    arr_effective_K_VRH_02 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_02->SetName("effective bulk modulus (VRH 0.2)");
    table->AddColumn(arr_effective_K_VRH_02);  // column 6

    arr_effective_K_VRH_00 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_K_VRH_00->SetName("effective bulk modulus (VRH 0.0)");
    table->AddColumn(arr_effective_K_VRH_00);  // column 7

    // effective shear modulus
    arr_effective_mu = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu->SetName("effective shear modulus");
    table->AddColumn(arr_effective_mu);  // column 8

    arr_effective_mu_VRH_10 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_10->SetName("effective shear modulus (VRH 1.0)");
    table->AddColumn(arr_effective_mu_VRH_10);  // column 9

    arr_effective_mu_VRH_08 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_08->SetName("effective shear modulus (VRH 0.8)");
    table->AddColumn(arr_effective_mu_VRH_08);  // column 10

    arr_effective_mu_VRH_06 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_06->SetName("effective shear modulus (VRH 0.6)");
    table->AddColumn(arr_effective_mu_VRH_06);  // column 11

    arr_effective_mu_VRH_04 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_04->SetName("effective shear modulus (VRH 0.4)");
    table->AddColumn(arr_effective_mu_VRH_04);  // column 12

    arr_effective_mu_VRH_02 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_02->SetName("effective shear modulus (VRH 0.2)");
    table->AddColumn(arr_effective_mu_VRH_02);  // column 13

    arr_effective_mu_VRH_00 = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_mu_VRH_00->SetName("effective shear modulus (VRH 0.0)");
    table->AddColumn(arr_effective_mu_VRH_00);  // column 14

    arr_effective_rho = vtkSmartPointer<vtkFloatArray>::New();
    arr_effective_rho->SetName("effective density");
    table->AddColumn(arr_effective_rho);  // column 15

    table->SetNumberOfRows(num_points);

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

    vtkchart_effK = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effK->GetScene()->AddItem(vtkchart_effK);

    line_effK = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK->SetInputData(table, 0, 1);
    line_effK->SetColor(0, 0, 255, 255);
    line_effK->SetWidth(2.0);

    // vrh (K)
    line_effK_10 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_10->SetInputData(table, 0, 2);
    //line_effK_10->SetColor(10, 10, 10, 255);
    line_effK_10->SetColor(color_10[0], color_10[1], color_10[2]);
    line_effK_10->SetWidth(1.0);
    line_effK_10->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effK_08 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_08->SetInputData(table, 0, 3);
    //line_effK_08->SetColor(10, 10, 10, 255);
    line_effK_08->SetColor(color_08[0], color_08[1], color_08[2]);
    line_effK_08->SetWidth(1.0);
    line_effK_08->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effK_06 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_06->SetInputData(table, 0, 4);
    //line_effK_06->SetColor(10, 10, 10, 255);
    line_effK_06->SetColor(color_06[0], color_06[1], color_06[2]);
    line_effK_06->SetWidth(1.0);
    line_effK_06->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effK_04 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_04->SetInputData(table, 0, 5);
    //line_effK_04->SetColor(10, 10, 10, 255);
    line_effK_04->SetColor(color_04[0], color_04[1], color_04[2]);
    line_effK_04->SetWidth(1.0);
    line_effK_04->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effK_02 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_02->SetInputData(table, 0, 6);
    //line_effK_02->SetColor(10, 10, 10, 255);
    line_effK_02->SetColor(color_02[0], color_02[1], color_02[2]);
    line_effK_02->SetWidth(1.0);
    line_effK_02->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effK_00 = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK_00->SetInputData(table, 0, 7);
    //line_effK_00->SetColor(10, 10, 10, 255);
    line_effK_00->SetColor(color_00[0], color_00[1], color_00[2]);
    line_effK_00->SetWidth(1.0);
    line_effK_00->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchartlegend_effK = vtkchart_effK->GetLegend();
    vtkchartlegend_effK->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effK->SetShowLegend(true);
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetTitle("background volume fraction");
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
    // ++ vtkcontextview_effmu->SetRenderWindow(vtkgenericopenglwindow_mu);  // NOTE: generic render window !!!
    vtkcontextview_effmu->SetRenderWindow(vtkrenderwindow_mu);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //--vtkcontextview_effmu->GetRenderer()->SetViewport(0.333, 0.0, 0.666, 1.0);

    vtkchart_effmu = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effmu->GetScene()->AddItem(vtkchart_effmu);

    line_effmu = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu->SetInputData(table, 0, 8);
    line_effmu->SetColor(0, 0, 255, 255);
    line_effmu->SetWidth(2.0);

    // vrh (mu)
    line_effmu_10 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_10->SetInputData(table, 0, 9);
    //line_effmu_10->SetColor(10, 10, 10, 255);
    line_effmu_10->SetColor(color_10[0], color_10[1], color_10[2]);
    line_effmu_10->SetWidth(1.0);
    line_effmu_10->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effmu_08 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_08->SetInputData(table, 0, 10);
    //line_effmu_08->SetColor(10, 10, 10, 255);
    line_effmu_08->SetColor(color_08[0], color_08[1], color_08[2]);
    line_effmu_08->SetWidth(1.0);
    line_effmu_08->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effmu_06 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_06->SetInputData(table, 0, 11);
    //line_effmu_06->SetColor(10, 10, 10, 255);
    line_effmu_06->SetColor(color_06[0], color_06[1], color_06[2]);
    line_effmu_06->SetWidth(1.0);
    line_effmu_06->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effmu_04 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_04->SetInputData(table, 0, 12);
    //line_effmu_04->SetColor(10, 10, 10, 255);
    line_effmu_04->SetColor(color_04[0], color_04[1], color_04[2]);
    line_effmu_04->SetWidth(1.0);
    line_effmu_04->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effmu_02 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_02->SetInputData(table, 0, 13);
    //line_effmu_02->SetColor(10, 10, 10, 255);
    line_effmu_02->SetColor(color_02[0], color_02[1], color_02[2]);
    line_effmu_02->SetWidth(1.0);
    line_effmu_02->GetPen()->SetLineType(vtkPen::DASH_LINE);

    line_effmu_00 = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu_00->SetInputData(table, 0, 14);
    //line_effmu_00->SetColor(10, 10, 10, 255);
    line_effmu_00->SetColor(color_00[0], color_00[1], color_00[2]);
    line_effmu_00->SetWidth(1.0);
    line_effmu_00->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchartlegend_effmu = vtkchart_effmu->GetLegend();
    vtkchartlegend_effmu->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effmu->SetShowLegend(true);
    vtkchart_effmu->GetAxis(vtkAxis::BOTTOM)->SetTitle("background volume fraction");
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
    // ++ vtkcontextview_effrho->SetRenderWindow(vtkgenericopenglwindow_rho);  // NOTE: generic render window !!!
    vtkcontextview_effrho->SetRenderWindow(vtkrenderwindow_rho);
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    //vtkcontextview_effrho->GetRenderer()->SetViewport(0.666, 0.0, 1.0, 1.0);

    vtkchart_effrho = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effrho->GetScene()->AddItem(vtkchart_effrho);

    line_effrho = vtkchart_effrho->AddPlot(vtkChart::LINE);
    line_effrho->SetInputData(table, 0, 15);
    line_effrho->SetColor(0, 0, 255, 255);
    line_effrho->SetWidth(2.0);

    vtkchartlegend_effrho = vtkchart_effrho->GetLegend();
    vtkchartlegend_effrho->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effrho->SetShowLegend(true);
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->SetTitle("background volume fraction");
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effrho->GetAxis(vtkAxis::BOTTOM)->GetTitleProperties()->SetFontSize(font_size);
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->SetTitle("effective density (g/cm**3)");
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->GetLabelProperties()->SetFontSize(font_size);
    vtkchart_effrho->GetAxis(vtkAxis::LEFT)->GetTitleProperties()->SetFontSize(font_size);

    PrivateUpdatePlot();


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
    connect(background_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnBackgroundSolidComboBoxChanged(int)));
    connect(foreground_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnForegroundSolidComboBoxChanged(int)));

    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);

}

SolidPhaseView2::~SolidPhaseView2() {
    // destructor
}

// slots
void SolidPhaseView2::OnBackgroundSolidComboBoxChanged(int i) {
    //
    switch(i) {
        case 0: { // Augite
            background_K = mpc::data::AugiteBulkModulus<double>();
            background_mu = mpc::data::AugiteShearModulus<double>();
            background_rho = mpc::data::AugiteDensity<double>();
            break;
        }
        case 1: { // Albite
            background_K = mpc::data::AlbiteBulkModulus<double>();
            background_mu = mpc::data::AlbiteShearModulus<double>();
            background_rho = mpc::data::AlbiteDensity<double>();
            break;
        }
        case 2: { // Anorthite
            background_K = mpc::data::AnorthiteBulkModulus<double>();
            background_mu = mpc::data::AnorthiteShearModulus<double>();
            background_rho = mpc::data::AnorthiteDensity<double>();
            break;
        }
        case 3: { // Labradorite
            background_K = mpc::data::LabradoriteBulkModulus<double>();
            background_mu = mpc::data::LabradoriteShearModulus<double>();
            background_rho = mpc::data::LabradoriteDensity<double>();
            break;
        }
        case 4: { // Microcline
            background_K = mpc::data::MicroclineBulkModulus<double>();
            background_mu = mpc::data::MicroclineShearModulus<double>();
            background_rho = mpc::data::MicroclineDensity<double>();
            break;
        }
        case 5: { // Oligoclase
            background_K = mpc::data::OligoclaseBulkModulus<double>();
            background_mu = mpc::data::OligoclaseShearModulus<double>();
            background_rho = mpc::data::OligoclaseDensity<double>();
            break;
        }
        case 6: { // Coesite
            background_K = mpc::data::CoesiteBulkModulus<double>();
            background_mu = mpc::data::CoesiteShearModulus<double>();
            background_rho = mpc::data::CoesiteDensity<double>();
            break;
        }
        case 7: { // Epidote
            background_K = mpc::data::EpidoteBulkModulus<double>();
            background_mu = mpc::data::EpidoteShearModulus<double>();
            background_rho = mpc::data::EpidoteDensity<double>();
            break;
        }
        case 8: { // Hornblende
            background_K = mpc::data::HornblendeBulkModulus<double>();
            background_mu = mpc::data::HornblendeShearModulus<double>();
            background_rho = mpc::data::HornblendeDensity<double>();
            break;
        }
        case 9: { // Muscovite
            background_K = mpc::data::MuscoviteBulkModulus<double>();
            background_mu = mpc::data::MuscoviteShearModulus<double>();
            background_rho = mpc::data::MuscoviteDensity<double>();
            break;
        }
        case 10: { // Gypsum
            background_K = mpc::data::GypsumBulkModulus<double>();
            background_mu = mpc::data::GypsumShearModulus<double>();
            background_rho = mpc::data::GypsumDensity<double>();
            break;
        }
        case 11: { // Enstatite
            background_K = mpc::data::EnstatiteBulkModulus<double>();
            background_mu = mpc::data::EnstatiteShearModulus<double>();
            background_rho = mpc::data::EnstatiteDensity<double>();
            break;
        }
        case 12: { // Forsterite
            background_K = mpc::data::ForsteriteBulkModulus<double>();
            background_mu = mpc::data::ForsteriteShearModulus<double>();
            background_rho = mpc::data::ForsteriteDensity<double>();
            break;
        }
        case 13: { // Fayalite
            background_K = mpc::data::FayaliteBulkModulus<double>();
            background_mu = mpc::data::FayaliteShearModulus<double>();
            background_rho = mpc::data::FayaliteDensity<double>();
            break;
        }
        case 14: { // Montecellite
            background_K = mpc::data::MontecelliteBulkModulus<double>();
            background_mu = mpc::data::MontecelliteShearModulus<double>();
            background_rho = mpc::data::MontecelliteDensity<double>();
            break;
        }
        case 15: { // Andalusite
            background_K = mpc::data::AndalusiteBulkModulus<double>();
            background_mu = mpc::data::AndalusiteShearModulus<double>();
            background_rho = mpc::data::AndalusiteDensity<double>();
            break;
        }
        case 16: { // Silimanite
            background_K = mpc::data::SilimaniteBulkModulus<double>();
            background_mu = mpc::data::SilimaniteShearModulus<double>();
            background_rho = mpc::data::SilimaniteDensity<double>();
            break;
        }
        case 17: { // Barite
            background_K = mpc::data::BariteBulkModulus<double>();
            background_mu = mpc::data::BariteShearModulus<double>();
            background_rho = mpc::data::BariteDensity<double>();
            break;
        }
        case 18: { // Anhydrite
            background_K = mpc::data::AnhydriteBulkModulus<double>();
            background_mu = mpc::data::AnhydriteShearModulus<double>();
            background_rho = mpc::data::AnhydriteDensity<double>();
            break;
        }
        case 19: { // Dolomite
            background_K = mpc::data::DolomiteBulkModulus<double>();
            background_mu = mpc::data::DolomiteShearModulus<double>();
            background_rho = mpc::data::DolomiteDensity<double>();
            break;
        }
        case 20: { // Rutile
            background_K = mpc::data::RutileBulkModulus<double>();
            background_mu = mpc::data::RutileShearModulus<double>();
            background_rho = mpc::data::RutileDensity<double>();
            break;
        }
        case 21: { // Zircon
            background_K = mpc::data::ZirconBulkModulus<double>();
            background_mu = mpc::data::ZirconShearModulus<double>();
            background_rho = mpc::data::ZirconDensity<double>();
            break;
        }
        case 22: { // Corundum
            background_K = mpc::data::CorundumBulkModulus<double>();
            background_mu = mpc::data::CorundumShearModulus<double>();
            background_rho = mpc::data::CorundumDensity<double>();
            break;
        }
        case 23: { // Calcite
            background_K = mpc::data::CalciteBulkModulus<double>();
            background_mu = mpc::data::CalciteShearModulus<double>();
            background_rho = mpc::data::CalciteDensity<double>();
            break;
        }
        case 24: { // Quartz
            background_K = mpc::data::QuartzBulkModulus<double>();
            background_mu = mpc::data::QuartzShearModulus<double>();
            background_rho = mpc::data::QuartzDensity<double>();
            break;
        }
        case 25: { // Tourmaline
            background_K = mpc::data::TourmalineBulkModulus<double>();
            background_mu = mpc::data::TourmalineShearModulus<double>();
            background_rho = mpc::data::TourmalineDensity<double>();
            break;
        }
        case 26: { // Beryl
            background_K = mpc::data::BerylBulkModulus<double>();
            background_mu = mpc::data::BerylShearModulus<double>();
            background_rho = mpc::data::BerylDensity<double>();
            break;
        }
        case 27: { // Graphite
            background_K = mpc::data::GraphiteBulkModulus<double>();
            background_mu = mpc::data::GraphiteShearModulus<double>();
            background_rho = mpc::data::GraphiteDensity<double>();
            break;
        }
        case 28: { // Wusite
            background_K = mpc::data::WusiteBulkModulus<double>();
            background_mu = mpc::data::WusiteShearModulus<double>();
            background_rho = mpc::data::WusiteDensity<double>();
            break;
        }
        case 29: { // Manganosite
            background_K = mpc::data::ManganositeBulkModulus<double>();
            background_mu = mpc::data::ManganositeShearModulus<double>();
            background_rho = mpc::data::ManganositeDensity<double>();
            break;
        }
        case 30: { // Periclase
            background_K = mpc::data::PericlaseBulkModulus<double>();
            background_mu = mpc::data::PericlaseShearModulus<double>();
            background_rho = mpc::data::PericlaseDensity<double>();
            break;
        }
        case 31: { // Magnetite
            background_K = mpc::data::MagnetiteBulkModulus<double>();
            background_mu = mpc::data::MagnetiteShearModulus<double>();
            background_rho = mpc::data::MagnetiteDensity<double>();
            break;
        }
        case 32: { // Chromite
            background_K = mpc::data::ChromiteBulkModulus<double>();
            background_mu = mpc::data::ChromiteShearModulus<double>();
            background_rho = mpc::data::ChromiteDensity<double>();
            break;
        }
        case 33: { // Spinel
            background_K = mpc::data::SpinelBulkModulus<double>();
            background_mu = mpc::data::SpinelShearModulus<double>();
            background_rho = mpc::data::SpinelDensity<double>();
            break;
        }
        case 34: { // Pyrite
            background_K = mpc::data::PyriteBulkModulus<double>();
            background_mu = mpc::data::PyriteShearModulus<double>();
            background_rho = mpc::data::PyriteDensity<double>();
            break;
        }
        case 35: { // Galena
            background_K = mpc::data::GalenaBulkModulus<double>();
            background_mu = mpc::data::GalenaShearModulus<double>();
            background_rho = mpc::data::GalenaDensity<double>();
            break;
        }
        case 36: { // Sphalerite
            background_K = mpc::data::SphaleriteBulkModulus<double>();
            background_mu = mpc::data::SphaleriteShearModulus<double>();
            background_rho = mpc::data::SphaleriteDensity<double>();
            break;
        }
        case 37: { // Fluorite
            background_K = mpc::data::FluoriteBulkModulus<double>();
            background_mu = mpc::data::FluoriteShearModulus<double>();
            background_rho = mpc::data::FluoriteDensity<double>();
            break;
        }
        case 38: { // Halite
            background_K = mpc::data::HaliteBulkModulus<double>();
            background_mu = mpc::data::HaliteShearModulus<double>();
            background_rho = mpc::data::HaliteDensity<double>();
            break;
        }
        case 39: { // Sylvite
            background_K = mpc::data::SylviteBulkModulus<double>();
            background_mu = mpc::data::SylviteShearModulus<double>();
            background_rho = mpc::data::SylviteDensity<double>();
            break;
        }
        default: {}

    }  // end switch
    background_bulkmodulus_value_lineedit->setText(QString::number(background_K));
    background_shearmodulus_value_lineedit->setText(QString::number(background_mu));
    background_density_value_lineedit->setText(QString::number(background_rho));

    PrivateUpdatePlot();
}

void SolidPhaseView2::OnForegroundSolidComboBoxChanged(int i) {
    //
    switch(i) {
        case 0: { // Augite
            foreground_K = mpc::data::AugiteBulkModulus<double>();
            foreground_mu = mpc::data::AugiteShearModulus<double>();
            foreground_rho = mpc::data::AugiteDensity<double>();
            break;
        }
        case 1: { // Albite
            foreground_K = mpc::data::AlbiteBulkModulus<double>();
            foreground_mu = mpc::data::AlbiteShearModulus<double>();
            foreground_rho = mpc::data::AlbiteDensity<double>();
            break;
        }
        case 2: { // Anorthite
            foreground_K = mpc::data::AnorthiteBulkModulus<double>();
            foreground_mu = mpc::data::AnorthiteShearModulus<double>();
            foreground_rho = mpc::data::AnorthiteDensity<double>();
            break;
        }
        case 3: { // Labradorite
            foreground_K = mpc::data::LabradoriteBulkModulus<double>();
            foreground_mu = mpc::data::LabradoriteShearModulus<double>();
            foreground_rho = mpc::data::LabradoriteDensity<double>();
            break;
        }
        case 4: { // Microcline
            foreground_K = mpc::data::MicroclineBulkModulus<double>();
            foreground_mu = mpc::data::MicroclineShearModulus<double>();
            foreground_rho = mpc::data::MicroclineDensity<double>();
            break;
        }
        case 5: { // Oligoclase
            foreground_K = mpc::data::OligoclaseBulkModulus<double>();
            foreground_mu = mpc::data::OligoclaseShearModulus<double>();
            foreground_rho = mpc::data::OligoclaseDensity<double>();
            break;
        }
        case 6: { // Coesite
            foreground_K = mpc::data::CoesiteBulkModulus<double>();
            foreground_mu = mpc::data::CoesiteShearModulus<double>();
            foreground_rho = mpc::data::CoesiteDensity<double>();
            break;
        }
        case 7: { // Epidote
            foreground_K = mpc::data::EpidoteBulkModulus<double>();
            foreground_mu = mpc::data::EpidoteShearModulus<double>();
            foreground_rho = mpc::data::EpidoteDensity<double>();
            break;
        }
        case 8: { // Hornblende
            foreground_K = mpc::data::HornblendeBulkModulus<double>();
            foreground_mu = mpc::data::HornblendeShearModulus<double>();
            foreground_rho = mpc::data::HornblendeDensity<double>();
            break;
        }
        case 9: { // Muscovite
            foreground_K = mpc::data::MuscoviteBulkModulus<double>();
            foreground_mu = mpc::data::MuscoviteShearModulus<double>();
            foreground_rho = mpc::data::MuscoviteDensity<double>();
            break;
        }
        case 10: { // Gypsum
            foreground_K = mpc::data::GypsumBulkModulus<double>();
            foreground_mu = mpc::data::GypsumShearModulus<double>();
            foreground_rho = mpc::data::GypsumDensity<double>();
            break;
        }
        case 11: { // Enstatite
            foreground_K = mpc::data::EnstatiteBulkModulus<double>();
            foreground_mu = mpc::data::EnstatiteShearModulus<double>();
            foreground_rho = mpc::data::EnstatiteDensity<double>();
            break;
        }
        case 12: { // Forsterite
            foreground_K = mpc::data::ForsteriteBulkModulus<double>();
            foreground_mu = mpc::data::ForsteriteShearModulus<double>();
            foreground_rho = mpc::data::ForsteriteDensity<double>();
            break;
        }
        case 13: { // Fayalite
            foreground_K = mpc::data::FayaliteBulkModulus<double>();
            foreground_mu = mpc::data::FayaliteShearModulus<double>();
            foreground_rho = mpc::data::FayaliteDensity<double>();
            break;
        }
        case 14: { // Montecellite
            foreground_K = mpc::data::MontecelliteBulkModulus<double>();
            foreground_mu = mpc::data::MontecelliteShearModulus<double>();
            foreground_rho = mpc::data::MontecelliteDensity<double>();
            break;
        }
        case 15: { // Andalusite
            foreground_K = mpc::data::AndalusiteBulkModulus<double>();
            foreground_mu = mpc::data::AndalusiteShearModulus<double>();
            foreground_rho = mpc::data::AndalusiteDensity<double>();
            break;
        }
        case 16: { // Silimanite
            foreground_K = mpc::data::SilimaniteBulkModulus<double>();
            foreground_mu = mpc::data::SilimaniteShearModulus<double>();
            foreground_rho = mpc::data::SilimaniteDensity<double>();
            break;
        }
        case 17: { // Barite
            foreground_K = mpc::data::BariteBulkModulus<double>();
            foreground_mu = mpc::data::BariteShearModulus<double>();
            foreground_rho = mpc::data::BariteDensity<double>();
            break;
        }
        case 18: { // Anhydrite
            foreground_K = mpc::data::AnhydriteBulkModulus<double>();
            foreground_mu = mpc::data::AnhydriteShearModulus<double>();
            foreground_rho = mpc::data::AnhydriteDensity<double>();
            break;
        }
        case 19: { // Dolomite
            foreground_K = mpc::data::DolomiteBulkModulus<double>();
            foreground_mu = mpc::data::DolomiteShearModulus<double>();
            foreground_rho = mpc::data::DolomiteDensity<double>();
            break;
        }
        case 20: { // Rutile
            foreground_K = mpc::data::RutileBulkModulus<double>();
            foreground_mu = mpc::data::RutileShearModulus<double>();
            foreground_rho = mpc::data::RutileDensity<double>();
            break;
        }
        case 21: { // Zircon
            foreground_K = mpc::data::ZirconBulkModulus<double>();
            foreground_mu = mpc::data::ZirconShearModulus<double>();
            foreground_rho = mpc::data::ZirconDensity<double>();
            break;
        }
        case 22: { // Corundum
            foreground_K = mpc::data::CorundumBulkModulus<double>();
            foreground_mu = mpc::data::CorundumShearModulus<double>();
            foreground_rho = mpc::data::CorundumDensity<double>();
            break;
        }
        case 23: { // Calcite
            foreground_K = mpc::data::CalciteBulkModulus<double>();
            foreground_mu = mpc::data::CalciteShearModulus<double>();
            foreground_rho = mpc::data::CalciteDensity<double>();
            break;
        }
        case 24: { // Quartz
            foreground_K = mpc::data::QuartzBulkModulus<double>();
            foreground_mu = mpc::data::QuartzShearModulus<double>();
            foreground_rho = mpc::data::QuartzDensity<double>();
            break;
        }
        case 25: { // Tourmaline
            foreground_K = mpc::data::TourmalineBulkModulus<double>();
            foreground_mu = mpc::data::TourmalineShearModulus<double>();
            foreground_rho = mpc::data::TourmalineDensity<double>();
            break;
        }
        case 26: { // Beryl
            foreground_K = mpc::data::BerylBulkModulus<double>();
            foreground_mu = mpc::data::BerylShearModulus<double>();
            foreground_rho = mpc::data::BerylDensity<double>();
            break;
        }
        case 27: { // Graphite
            foreground_K = mpc::data::GraphiteBulkModulus<double>();
            foreground_mu = mpc::data::GraphiteShearModulus<double>();
            foreground_rho = mpc::data::GraphiteDensity<double>();
            break;
        }
        case 28: { // Wusite
            foreground_K = mpc::data::WusiteBulkModulus<double>();
            foreground_mu = mpc::data::WusiteShearModulus<double>();
            foreground_rho = mpc::data::WusiteDensity<double>();
            break;
        }
        case 29: { // Manganosite
            foreground_K = mpc::data::ManganositeBulkModulus<double>();
            foreground_mu = mpc::data::ManganositeShearModulus<double>();
            foreground_rho = mpc::data::ManganositeDensity<double>();
            break;
        }
        case 30: { // Periclase
            foreground_K = mpc::data::PericlaseBulkModulus<double>();
            foreground_mu = mpc::data::PericlaseShearModulus<double>();
            foreground_rho = mpc::data::PericlaseDensity<double>();
            break;
        }
        case 31: { // Magnetite
            foreground_K = mpc::data::MagnetiteBulkModulus<double>();
            foreground_mu = mpc::data::MagnetiteShearModulus<double>();
            foreground_rho = mpc::data::MagnetiteDensity<double>();
            break;
        }
        case 32: { // Chromite
            foreground_K = mpc::data::ChromiteBulkModulus<double>();
            foreground_mu = mpc::data::ChromiteShearModulus<double>();
            foreground_rho = mpc::data::ChromiteDensity<double>();
            break;
        }
        case 33: { // Spinel
            foreground_K = mpc::data::SpinelBulkModulus<double>();
            foreground_mu = mpc::data::SpinelShearModulus<double>();
            foreground_rho = mpc::data::SpinelDensity<double>();
            break;
        }
        case 34: { // Pyrite
            foreground_K = mpc::data::PyriteBulkModulus<double>();
            foreground_mu = mpc::data::PyriteShearModulus<double>();
            foreground_rho = mpc::data::PyriteDensity<double>();
            break;
        }
        case 35: { // Galena
            foreground_K = mpc::data::GalenaBulkModulus<double>();
            foreground_mu = mpc::data::GalenaShearModulus<double>();
            foreground_rho = mpc::data::GalenaDensity<double>();
            break;
        }
        case 36: { // Sphalerite
            foreground_K = mpc::data::SphaleriteBulkModulus<double>();
            foreground_mu = mpc::data::SphaleriteShearModulus<double>();
            foreground_rho = mpc::data::SphaleriteDensity<double>();
            break;
        }
        case 37: { // Fluorite
            foreground_K = mpc::data::FluoriteBulkModulus<double>();
            foreground_mu = mpc::data::FluoriteShearModulus<double>();
            foreground_rho = mpc::data::FluoriteDensity<double>();
            break;
        }
        case 38: { // Halite
            foreground_K = mpc::data::HaliteBulkModulus<double>();
            foreground_mu = mpc::data::HaliteShearModulus<double>();
            foreground_rho = mpc::data::HaliteDensity<double>();
            break;
        }
        case 39: { // Sylvite
            foreground_K = mpc::data::SylviteBulkModulus<double>();
            foreground_mu = mpc::data::SylviteShearModulus<double>();
            foreground_rho = mpc::data::SylviteDensity<double>();
            break;
        }
        default: {}

    }  // end switch
    foreground_bulkmodulus_value_lineedit->setText(QString::number(foreground_K));
    foreground_shearmodulus_value_lineedit->setText(QString::number(foreground_mu));
    foreground_density_value_lineedit->setText(QString::number(foreground_rho));

    PrivateUpdatePlot();
}

// member functions
void SolidPhaseView2::PrivateUpdatePlot() {
    //
    auto solid_mixture_background_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(background_K), mpc::rockphysics::ShearModulusType<double>(background_mu), mpc::rockphysics::DensityType<double>(background_rho), mpc::rockphysics::VolumeFractionType<double>(0.0));

    auto solid_mixture_foreground_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(foreground_K), mpc::rockphysics::ShearModulusType<double>(foreground_mu), mpc::rockphysics::DensityType<double>(foreground_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));


    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > sand_mudrock_mixture_vec{
            solid_mixture_background_tuple,
            solid_mixture_foreground_tuple
    };

    mpc::rockphysics::SolidPhase<double> sand_mudrock_mixture = mpc::rockphysics::SolidPhase(sand_mudrock_mixture_vec);

    // Fill in the table ...

    std::vector<double> vf_vec_values{0.0, 1.0};
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
        vf_vec_values = std::vector<double>({ i*sample_interval, 1.0 - (i*sample_interval) });

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

    // update all the plots with the new data
    line_effK->Modified();
    line_effK_00->Modified();
    line_effK_02->Modified();
    line_effK_04->Modified();
    line_effK_06->Modified();
    line_effK_08->Modified();
    line_effK_10->Modified();

    line_effmu->Modified();
    line_effmu_00->Modified();
    line_effmu_02->Modified();
    line_effmu_04->Modified();
    line_effmu_06->Modified();
    line_effmu_08->Modified();
    line_effmu_10->Modified();

    line_effrho->Modified();


    line_effK->Update();
    line_effK_00->Update();
    line_effK_02->Update();
    line_effK_04->Update();
    line_effK_06->Update();
    line_effK_08->Update();
    line_effK_10->Update();

    line_effmu->Update();
    line_effmu_00->Update();
    line_effmu_02->Update();
    line_effmu_04->Update();
    line_effmu_06->Update();
    line_effmu_08->Update();
    line_effmu_10->Update();

    line_effrho->Update();

//    vtkchart_effK->Update();
//    vtkchart_effmu->Update();
//    vtkchart_effrho->Update();

    vtkchart_effK->RecalculateBounds();
    vtkchart_effmu->RecalculateBounds();
    vtkchart_effrho->RecalculateBounds();

    vtkchart_effK->Update();
    vtkchart_effmu->Update();
    vtkchart_effrho->Update();
}