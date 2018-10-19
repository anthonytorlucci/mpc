#include "solidphaseview.h"

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


SolidPhaseView::SolidPhaseView(QWidget *parent) {
    // constructor

    auto solid_mixture_sand_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(sand_K), mpc::rockphysics::ShearModulusType<double>(sand_mu), mpc::rockphysics::DensityType<double>(sand_rho), mpc::rockphysics::VolumeFractionType<double>(0.0));

    auto solid_mixture_mudrock_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(mudrock_K), mpc::rockphysics::ShearModulusType<double>(mudrock_mu), mpc::rockphysics::DensityType<double>(mudrock_rho), mpc::rockphysics::VolumeFractionType<double>(1.0));


    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > mudrock_sand_mixture_vec{
            solid_mixture_mudrock_tuple,
            solid_mixture_sand_tuple
    };

    mpc::rockphysics::SolidPhase<double> mudrock_sand_mixture = mpc::rockphysics::SolidPhase(mudrock_sand_mixture_vec);

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
    // Create a table with some points in it
    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

    vtkSmartPointer<vtkFloatArray> arr_sand_volumefraction = vtkSmartPointer<vtkFloatArray>::New();
    arr_sand_volumefraction->SetName("sand volume fraction");  // X-axis
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
    arr_effective_mu->SetName("effective shear modulus (VRH 0.0)");
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

    for (int i=0; i<num_points; ++i) {
        table->SetValue(i, 0, i*sample_interval);
        vf_vec_values = std::vector<double>({ 1.0 - (i*sample_interval), i*sample_interval });

        mudrock_sand_mixture.VolumeFractionTypeVector(vf_vec_values);
        effective_bulkmodulus = mudrock_sand_mixture.EffectiveBulkModulusType().value;
        table->SetValue(i, 1, effective_bulkmodulus);
        // TODO: vrh10

        effective_shearmodulus = mudrock_sand_mixture.EffectiveShearModulusType().value;
        table->SetValue(i, 8, effective_shearmodulus);
        // TODO: vrh10

        effective_density = mudrock_sand_mixture.EffectiveDensityType().value;
        table->SetValue(i, 15, effective_density);

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

    vtkPlot* line_effK = vtkchart_effK->AddPlot(vtkChart::LINE);
    line_effK->SetInputData(table, 0, 1);
    line_effK->SetColor(0, 0, 255, 255);
    line_effK->SetWidth(2.0);

    // TODO: vrh
    // For dotted line, ...
    //line->GetPen()->SetLineType(vtkPen::DASH_LINE);

    vtkchart_effK->SetShowLegend(true);
    vtkchart_effK->GetAxis(vtkAxis::BOTTOM)->SetTitle("sand volume fraction");
    vtkchart_effK->GetAxis(vtkAxis::LEFT)->SetTitle("effective bulk modulus (GPa)");

    vtkcontextview_effmu = vtkSmartPointer<vtkContextView>::New();
    vtkcontextview_effmu->SetRenderWindow(vtkgenericopenglwindow);  // NOTE: generic render window !!!
    //vtkcontextview->GetRenderer()->SetBackground(0.8, 0.8, 0.8);  // TODO: replace with background gradient
    vtkcontextview_effmu->GetRenderer()->SetViewport(0.333, 0.0, 0.666, 1.0);

    vtkchart_effmu = vtkSmartPointer<vtkChartXY>::New();
    vtkcontextview_effmu->GetScene()->AddItem(vtkchart_effmu);

    vtkPlot* line_effmu = vtkchart_effmu->AddPlot(vtkChart::LINE);
    line_effmu->SetInputData(table, 0, 8);
    line_effmu->SetColor(0, 0, 255, 255);
    line_effmu->SetWidth(2.0);

    // TODO: vrh
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

SolidPhaseView::~SolidPhaseView() {
    // destructor
}

// slots


// member functions