#include "mixinglawsview.h"

// c++
#include <iostream>
#include <cmath>

// Qt
#include <QDebug>
#include <QString>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSurfaceFormat>
#include <QSplitter>
#include <QTabWidget>


// VTK
#include <vtkMath.h>
#include <vtkPointData.h>
#include <vtkTransform.h>
#include <vtkAxesActor.h>
#include <vtkProperty.h>


// mpc
#include <mpc/utilities/arithmeticaverage.hpp>
#include <mpc/utilities/harmonicaverage.hpp>
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/rockphysics/rockphysicstransformstypes.hpp>
#include <mpc/rockphysics/rockphysicstransforms.hpp>
#include <mpc/rockphysics/scalarcomposites.hpp>


MixingLawsView::MixingLawsView(QWidget *parent) {
    // constructor

    // initialize variables
    background_fluid_K = brine_K;
    background_fluid_rho = brine_rho;
    foreground_fluid_K = oil_K;
    foreground_fluid_rho = oil_rho;

    background_solid_K = mpc::data::QuartzBulkModulus<double>();
    background_solid_mu = mpc::data::QuartzShearModulus<double>();
    background_solid_rho = mpc::data::QuartzDensity<double>();
    foreground_solid_K = mpc::data::MuscoviteBulkModulus<double>();
    foreground_solid_mu = mpc::data::MuscoviteShearModulus<double>();
    foreground_solid_rho = mpc::data::MuscoviteDensity<double>();

    fluid_volume_fraction = 0.25;  // default porosity
    solid_volume_fraction = 0.75;
    hill_weighting_coefficient = 0.5;  // default (1/2)

    zscale_K = 0.05;     // 0 : "saturated bulk modulus"
    zscale_mu = 0.05;    // 1 : "effective shear modulus"
    zscale_rho = 1.0;   // 2 : "effective density"
    zscale_pvel = 1.0;  // 3 : "effective p-wave velocity"
    zscale_svel = 1.0;  // 4 : "effective s-wave velocity"
    zscale_vpvs = 10.0;  // 5 : "effective Vp/Vs ratio"
    zscale_vsvp = 10.0;  // 6 : "effective Vs/Vp ratio"
    zscale_nu = 10.0;    // 7 : "effective Poisson's ratio"

    cubeaxesactor2d_str = "saturated bulk modulus (GPa x" + std::to_string(zscale_K) + ")";
    scalarbaractor_str = "K (GPa x" + std::to_string(zscale_K) + ")";

    // controls widget
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
    background_fluid_bulkmodulus_value_lineedit->setText(QString::number(background_fluid_K));
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
    background_fluid_density_value_lineedit->setText(QString::number(background_fluid_rho));
    background_fluid_density_value_lineedit->setAlignment(Qt::AlignCenter);
    background_fluid_density_value_lineedit->setReadOnly(true);
    foreground_fluid_label = new QLabel(this);
    foreground_fluid_label->setText("foreground fluid");
    foreground_fluid_combobox = new QComboBox(this);
    foreground_fluid_combobox->addItem("oil");
    foreground_fluid_combobox->addItem("gas");
    foreground_fluid_bulkmodulus_label = new QLabel(this);
    foreground_fluid_bulkmodulus_label->setText("bulk modulus");
    foreground_fluid_bulkmodulus_value_lineedit = new QLineEdit(this);
    foreground_fluid_bulkmodulus_value_lineedit->setText(QString::number(oil_K));  // default oil
    foreground_fluid_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid_bulkmodulus_value_lineedit->setReadOnly(true);
    foreground_fluid_shearmodulus_label = new QLabel(this);
    foreground_fluid_shearmodulus_label->setText("shear modulus");
    foreground_fluid_shearmodulus_value_lineedit = new QLineEdit(this);
    foreground_fluid_shearmodulus_value_lineedit->setText(QString::number(0.0));
    foreground_fluid_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid_shearmodulus_value_lineedit->setReadOnly(true);
    foreground_fluid_density_label = new QLabel(this);
    foreground_fluid_density_label->setText("density");
    foreground_fluid_density_value_lineedit = new QLineEdit(this);
    foreground_fluid_density_value_lineedit->setText(QString::number(oil_rho));  // default oil
    foreground_fluid_density_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_fluid_density_value_lineedit->setReadOnly(true);
    QGridLayout* fluids_groupbox_layout = new QGridLayout(this);
    fluids_groupbox_layout->addWidget(background_fluid_label, 0, 0);
    fluids_groupbox_layout->addWidget(background_fluid_combobox, 0, 1);
    fluids_groupbox_layout->addWidget(background_fluid_bulkmodulus_label, 0, 2);
    fluids_groupbox_layout->addWidget(background_fluid_bulkmodulus_value_lineedit, 0, 3);
    fluids_groupbox_layout->addWidget(background_fluid_shearmodulus_label, 0, 4);
    fluids_groupbox_layout->addWidget(background_fluid_shearmodulus_value_lineedit, 0, 5);
    fluids_groupbox_layout->addWidget(background_fluid_density_label, 0, 6);
    fluids_groupbox_layout->addWidget(background_fluid_density_value_lineedit, 0, 7);
    fluids_groupbox_layout->addWidget(foreground_fluid_label, 1, 0);
    fluids_groupbox_layout->addWidget(foreground_fluid_combobox, 1, 1);
    fluids_groupbox_layout->addWidget(foreground_fluid_bulkmodulus_label, 1, 2);
    fluids_groupbox_layout->addWidget(foreground_fluid_bulkmodulus_value_lineedit, 1, 3);
    fluids_groupbox_layout->addWidget(foreground_fluid_shearmodulus_label, 1, 4);
    fluids_groupbox_layout->addWidget(foreground_fluid_shearmodulus_value_lineedit, 1, 5);
    fluids_groupbox_layout->addWidget(foreground_fluid_density_label, 1, 6);
    fluids_groupbox_layout->addWidget(foreground_fluid_density_value_lineedit, 1, 7);
    fluids_groupbox->setLayout(fluids_groupbox_layout);

    // solids box
    QGroupBox* solids_groupbox = new QGroupBox("solids", this);
    background_solid_label = new QLabel(this);
    background_solid_label->setText("background fluid");
    background_solid_combobox = new QComboBox(this);
    background_solid_combobox->addItem(QStringLiteral("Augite"));
    background_solid_combobox->addItem(QStringLiteral("Albite"));
    background_solid_combobox->addItem(QStringLiteral("Anorthite"));
    background_solid_combobox->addItem(QStringLiteral("Labradorite"));
    background_solid_combobox->addItem(QStringLiteral("Microcline"));
    background_solid_combobox->addItem(QStringLiteral("Oligoclase"));
    background_solid_combobox->addItem(QStringLiteral("Coesite"));
    background_solid_combobox->addItem(QStringLiteral("Epidote"));
    background_solid_combobox->addItem(QStringLiteral("Hornblende"));
    background_solid_combobox->addItem(QStringLiteral("Muscovite"));
    background_solid_combobox->addItem(QStringLiteral("Gypsum"));
    background_solid_combobox->addItem(QStringLiteral("Enstatite"));
    background_solid_combobox->addItem(QStringLiteral("Forsterite"));
    background_solid_combobox->addItem(QStringLiteral("Fayalite"));
    background_solid_combobox->addItem(QStringLiteral("Montecellite"));
    background_solid_combobox->addItem(QStringLiteral("Andalusite"));
    background_solid_combobox->addItem(QStringLiteral("Silimanite"));
    background_solid_combobox->addItem(QStringLiteral("Barite"));
    background_solid_combobox->addItem(QStringLiteral("Anhydrite"));
    background_solid_combobox->addItem(QStringLiteral("Dolomite"));
    background_solid_combobox->addItem(QStringLiteral("Rutile"));
    background_solid_combobox->addItem(QStringLiteral("Zircon"));
    background_solid_combobox->addItem(QStringLiteral("Corundum"));
    background_solid_combobox->addItem(QStringLiteral("Calcite"));
    background_solid_combobox->addItem(QStringLiteral("Quartz"));
    background_solid_combobox->addItem(QStringLiteral("Tourmaline"));
    background_solid_combobox->addItem(QStringLiteral("Beryl"));
    background_solid_combobox->addItem(QStringLiteral("Graphite"));
    background_solid_combobox->addItem(QStringLiteral("Wusite"));
    background_solid_combobox->addItem(QStringLiteral("Manganosite"));
    background_solid_combobox->addItem(QStringLiteral("Periclase"));
    background_solid_combobox->addItem(QStringLiteral("Magnetite"));
    background_solid_combobox->addItem(QStringLiteral("Chromite"));
    background_solid_combobox->addItem(QStringLiteral("Spinel"));
    background_solid_combobox->addItem(QStringLiteral("Pyrite"));
    background_solid_combobox->addItem(QStringLiteral("Galena"));
    background_solid_combobox->addItem(QStringLiteral("Sphalerite"));
    background_solid_combobox->addItem(QStringLiteral("Fluorite"));
    background_solid_combobox->addItem(QStringLiteral("Halite"));
    background_solid_combobox->addItem(QStringLiteral("Sylvite"));
    background_solid_combobox->setCurrentIndex(24);
    background_solid_bulkmodulus_label = new QLabel(this);
    background_solid_bulkmodulus_label->setText("bulk modulus");
    background_solid_bulkmodulus_value_lineedit = new QLineEdit(this);
    background_solid_bulkmodulus_value_lineedit->setText(QString::number(background_solid_K));
    background_solid_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    background_solid_bulkmodulus_value_lineedit->setReadOnly(true);
    background_solid_shearmodulus_label = new QLabel(this);
    background_solid_shearmodulus_label->setText("shear modulus");
    background_solid_shearmodulus_value_lineedit = new QLineEdit(this);
    background_solid_shearmodulus_value_lineedit->setText(QString::number(background_solid_mu));
    background_solid_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    background_solid_shearmodulus_value_lineedit->setReadOnly(true);
    background_solid_density_label = new QLabel(this);
    background_solid_density_label->setText("density");
    background_solid_density_value_lineedit = new QLineEdit(this);
    background_solid_density_value_lineedit->setText(QString::number(background_solid_rho));
    background_solid_density_value_lineedit->setAlignment(Qt::AlignCenter);
    background_solid_density_value_lineedit->setReadOnly(true);
    foreground_solid_label = new QLabel(this);
    foreground_solid_label->setText("foreground solid");
    foreground_solid_combobox = new QComboBox(this);
    foreground_solid_combobox->addItem(QStringLiteral("Augite"));
    foreground_solid_combobox->addItem(QStringLiteral("Albite"));
    foreground_solid_combobox->addItem(QStringLiteral("Anorthite"));
    foreground_solid_combobox->addItem(QStringLiteral("Labradorite"));
    foreground_solid_combobox->addItem(QStringLiteral("Microcline"));
    foreground_solid_combobox->addItem(QStringLiteral("Oligoclase"));
    foreground_solid_combobox->addItem(QStringLiteral("Coesite"));
    foreground_solid_combobox->addItem(QStringLiteral("Epidote"));
    foreground_solid_combobox->addItem(QStringLiteral("Hornblende"));
    foreground_solid_combobox->addItem(QStringLiteral("Muscovite"));
    foreground_solid_combobox->addItem(QStringLiteral("Gypsum"));
    foreground_solid_combobox->addItem(QStringLiteral("Enstatite"));
    foreground_solid_combobox->addItem(QStringLiteral("Forsterite"));
    foreground_solid_combobox->addItem(QStringLiteral("Fayalite"));
    foreground_solid_combobox->addItem(QStringLiteral("Montecellite"));
    foreground_solid_combobox->addItem(QStringLiteral("Andalusite"));
    foreground_solid_combobox->addItem(QStringLiteral("Silimanite"));
    foreground_solid_combobox->addItem(QStringLiteral("Barite"));
    foreground_solid_combobox->addItem(QStringLiteral("Anhydrite"));
    foreground_solid_combobox->addItem(QStringLiteral("Dolomite"));
    foreground_solid_combobox->addItem(QStringLiteral("Rutile"));
    foreground_solid_combobox->addItem(QStringLiteral("Zircon"));
    foreground_solid_combobox->addItem(QStringLiteral("Corundum"));
    foreground_solid_combobox->addItem(QStringLiteral("Calcite"));
    foreground_solid_combobox->addItem(QStringLiteral("Quartz"));
    foreground_solid_combobox->addItem(QStringLiteral("Tourmaline"));
    foreground_solid_combobox->addItem(QStringLiteral("Beryl"));
    foreground_solid_combobox->addItem(QStringLiteral("Graphite"));
    foreground_solid_combobox->addItem(QStringLiteral("Wusite"));
    foreground_solid_combobox->addItem(QStringLiteral("Manganosite"));
    foreground_solid_combobox->addItem(QStringLiteral("Periclase"));
    foreground_solid_combobox->addItem(QStringLiteral("Magnetite"));
    foreground_solid_combobox->addItem(QStringLiteral("Chromite"));
    foreground_solid_combobox->addItem(QStringLiteral("Spinel"));
    foreground_solid_combobox->addItem(QStringLiteral("Pyrite"));
    foreground_solid_combobox->addItem(QStringLiteral("Galena"));
    foreground_solid_combobox->addItem(QStringLiteral("Sphalerite"));
    foreground_solid_combobox->addItem(QStringLiteral("Fluorite"));
    foreground_solid_combobox->addItem(QStringLiteral("Halite"));
    foreground_solid_combobox->addItem(QStringLiteral("Sylvite"));
    foreground_solid_combobox->setCurrentIndex(9);
    foreground_solid_bulkmodulus_label = new QLabel(this);
    foreground_solid_bulkmodulus_label->setText("bulk modulus");
    foreground_solid_bulkmodulus_value_lineedit = new QLineEdit(this);
    foreground_solid_bulkmodulus_value_lineedit->setText(QString::number(foreground_solid_K));  // default muscovite
    foreground_solid_bulkmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_solid_bulkmodulus_value_lineedit->setReadOnly(true);
    foreground_solid_shearmodulus_label = new QLabel(this);
    foreground_solid_shearmodulus_label->setText("shear modulus");
    foreground_solid_shearmodulus_value_lineedit = new QLineEdit(this);
    foreground_solid_shearmodulus_value_lineedit->setText(QString::number(foreground_solid_mu));  // default muscovite
    foreground_solid_shearmodulus_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_solid_shearmodulus_value_lineedit->setReadOnly(true);
    foreground_solid_density_label = new QLabel(this);
    foreground_solid_density_label->setText("density");
    foreground_solid_density_value_lineedit = new QLineEdit(this);
    foreground_solid_density_value_lineedit->setText(QString::number(foreground_solid_rho));  // default muscovite
    foreground_solid_density_value_lineedit->setAlignment(Qt::AlignCenter);
    foreground_solid_density_value_lineedit->setReadOnly(true);
    hill_average_label = new QLabel(this);
    hill_average_label->setText("Hill average");
    hill_average_slider = new QSlider(this);
    hill_average_slider->setOrientation(Qt::Horizontal);
    hill_average_slider->setRange(0, 100);  // slider scalar = 0.01
    hill_average_slider->setValue(int(hill_weighting_coefficient / 0.01));  // 0.5 / 0.01 => 50
    hill_average_value_lineedit = new QLineEdit(this);
    hill_average_value_lineedit->setText(QString::number(hill_weighting_coefficient));
    hill_average_value_lineedit->setAlignment(Qt::AlignCenter);
    hill_average_value_lineedit->setReadOnly(true);
    QGridLayout* solids_groupbox_layout = new QGridLayout(this);
    solids_groupbox_layout->addWidget(background_solid_label, 0, 0);
    solids_groupbox_layout->addWidget(background_solid_combobox, 0, 1);
    solids_groupbox_layout->addWidget(background_solid_bulkmodulus_label, 0, 2);
    solids_groupbox_layout->addWidget(background_solid_bulkmodulus_value_lineedit, 0, 3);
    solids_groupbox_layout->addWidget(background_solid_shearmodulus_label, 0, 4);
    solids_groupbox_layout->addWidget(background_solid_shearmodulus_value_lineedit, 0, 5);
    solids_groupbox_layout->addWidget(background_solid_density_label, 0, 6);
    solids_groupbox_layout->addWidget(background_solid_density_value_lineedit, 0, 7);
    solids_groupbox_layout->addWidget(foreground_solid_label, 1, 0);
    solids_groupbox_layout->addWidget(foreground_solid_combobox, 1, 1);
    solids_groupbox_layout->addWidget(foreground_solid_bulkmodulus_label, 1, 2);
    solids_groupbox_layout->addWidget(foreground_solid_bulkmodulus_value_lineedit, 1, 3);
    solids_groupbox_layout->addWidget(foreground_solid_shearmodulus_label, 1, 4);
    solids_groupbox_layout->addWidget(foreground_solid_shearmodulus_value_lineedit, 1, 5);
    solids_groupbox_layout->addWidget(foreground_solid_density_label, 1, 6);
    solids_groupbox_layout->addWidget(foreground_solid_density_value_lineedit, 1, 7);
    solids_groupbox_layout->addWidget(hill_average_label, 2, 0);
    solids_groupbox_layout->addWidget(hill_average_slider, 2, 1, 1, 6);
    solids_groupbox_layout->addWidget(hill_average_value_lineedit, 2, 7);
    solids_groupbox->setLayout(solids_groupbox_layout);

    // porosity box
    QGroupBox* porosity_groupbox = new QGroupBox("porosity", this);
    porosity_label = new QLabel(this);
    porosity_label->setText("porosity");
    porosity_slider = new QSlider(this);
    porosity_slider->setOrientation(Qt::Horizontal);
    porosity_slider->setRange(2, 36);
    porosity_slider->setValue(int(fluid_volume_fraction / 0.01));
    porosity_value_lineedit = new QLineEdit(this);
    porosity_value_lineedit->setText(QString::number(fluid_volume_fraction));
    porosity_value_lineedit->setAlignment(Qt::AlignCenter);
    porosity_value_lineedit->setReadOnly(true);
    QGridLayout* porosity_groupbox_layout = new QGridLayout(this);
    porosity_groupbox_layout->addWidget(porosity_label, 0, 0);
    porosity_groupbox_layout->addWidget(porosity_slider, 0, 1);
    porosity_groupbox_layout->addWidget(porosity_value_lineedit, 0, 2);
    porosity_groupbox->setLayout(porosity_groupbox_layout);

    rockproperty_combobox = new QComboBox(this);
    rockproperty_combobox->addItem("saturated bulk modulus");
    rockproperty_combobox->addItem("effective shear modulus");
    rockproperty_combobox->addItem("effective density");
    rockproperty_combobox->addItem("effective p-wave velocity");
    rockproperty_combobox->addItem("effective s-wave velocity");
    rockproperty_combobox->addItem("effective Vp/Vs ratio");
    rockproperty_combobox->addItem("effective Vs/Vp ratio");
    rockproperty_combobox->addItem("effective Poisson's ratio");

    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(fluids_groupbox);
    controls_widget_layout->addWidget(solids_groupbox);
    controls_widget_layout->addWidget(porosity_groupbox);
    controls_widget_layout->addWidget(rockproperty_combobox);
    controls_widget->setLayout(controls_widget_layout);

    // VTK views
    qvtkopenglwidget = new QVTKOpenGLWidget(this);
    vtkgenericopenglwindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget->SetRenderWindow(vtkgenericopenglwindow);
    vtkrenderwindow = qvtkopenglwidget->GetRenderWindow();

    vtknamedcolors = vtkSmartPointer<vtkNamedColors>::New();

    // You can continue to use 'vtkrenderwindow' as a regular vtkRenderWindow
    // including adding renderers, actors, etc.
    vtkrenderer = vtkSmartPointer<vtkRenderer>::New();
    vtkrenderer->GradientBackgroundOn();
    vtkrenderer->SetBackground(vtknamedcolors->GetColor3d("Black").GetData());
    vtkrenderer->SetBackground2(vtknamedcolors->GetColor3d("DarkGray").GetData());
    vtkrenderwindow->AddRenderer(vtkrenderer);

    vtkcamera = vtkrenderer->GetActiveCamera();

    vtkrenderwindowinteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    vtkrenderwindowinteractor->SetRenderWindow(vtkrenderwindow);
    vtkrenderwindowinteractor = vtkrenderwindow->GetInteractor();

    // vtk examples : colored elevation
    vtkpoints = vtkSmartPointer<vtkPoints>::New();


    // Add the grid points to a polydata object
    vtkinputpolydata = vtkSmartPointer<vtkPolyData>::New();
    vtkinputpolydata->SetPoints(vtkpoints);

    // vtk examples - TriangulateTerrainMap.cxx
    vtkglyphfilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    vtkglyphfilter->SetInputData(vtkinputpolydata);
    vtkglyphfilter->Update();

    vtkpointsmapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkpointsmapper->SetInputConnection(vtkglyphfilter->GetOutputPort());

    vtkpointsactor = vtkSmartPointer<vtkActor>::New();
    vtkpointsactor->SetMapper(vtkpointsmapper);
    vtkpointsactor->GetProperty()->SetPointSize(3);
    vtkpointsactor->GetProperty()->SetColor(0.5,0.5,0.5);
    vtkrenderer->AddActor(vtkpointsactor);

    // Triangulate the grid points
    vtkdelaunay2d = vtkSmartPointer<vtkDelaunay2D>::New();
    vtkdelaunay2d->SetInputData(vtkinputpolydata);
    vtkdelaunay2d->Update();
    vtkoutputpolydata = vtkdelaunay2d->GetOutput();

    // Create the color map
    vtkcolorlookuptable = vtkSmartPointer<vtkLookupTable>::New();
//    vtkcolorlookuptable->SetTableRange(minz, maxz);
//    vtkcolorlookuptable->Build();

    // Generate the colors for each point based on the color map
    vtkcolorchararray = vtkSmartPointer<vtkUnsignedCharArray>::New();
    vtkcolorchararray->SetNumberOfComponents(3);
    vtkcolorchararray->SetName("Colors");

    // Create a mapper and actor
    vtkpolydatamapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkpolydatamapper->SetInputData(vtkoutputpolydata);

    vtkactor = vtkSmartPointer<vtkActor>::New();
    vtkactor->SetMapper(vtkpolydatamapper);

    // Add the actor to the scene
    vtkrenderer->AddActor(vtkactor);
    // END vtk examples : colored elevation ============================================================================

    // vtk examples : CubeAxesActor2D.cxx
    // Create a vtkOutlineFilter to draw the bounding box of the data set.
    // Also create the associated mapper and actor.
    vtkoutline = vtkSmartPointer<vtkOutlineFilter>::New();
    vtkoutline->SetInputConnection(vtkdelaunay2d->GetOutputPort());  // requires subclass of vtkAlgorithm


    vtkoutlinemapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkoutlinemapper->SetInputConnection(vtkoutline->GetOutputPort());

    vtkoutlineactor = vtkSmartPointer<vtkActor>::New();
    vtkoutlineactor->SetMapper(vtkoutlinemapper.GetPointer());
    vtkoutlineactor->GetProperty()->SetColor(0., 0., 0.);

    // add the actors to the renderer
    vtkrenderer->AddViewProp(vtkoutlineactor.GetPointer());

    // Create a text property
    vtktextproperty = vtkSmartPointer<vtkTextProperty>::New();
    vtktextproperty->SetColor(1, 1, 1);
    vtktextproperty->ShadowOn();
    vtktextproperty->SetFontSize(20);

    // Create a vtkCubeAxesActor2D.  Use the outer edges of the bounding box to
    // draw the axes.  Add the actor to the renderer.
    vtkcubeaxesactor2d = vtkSmartPointer<vtkCubeAxesActor2D>::New();
    vtkcubeaxesactor2d->SetInputConnection(vtkdelaunay2d->GetOutputPort());
    //vtkcubeaxesactor2d->SetCamera(vtkrenderer->GetActiveCamera());
    vtkcubeaxesactor2d->SetCamera(vtkcamera);
    vtkrenderer->ResetCamera();  // REQUIRED !!!
    vtkcubeaxesactor2d->SetLabelFormat("%6.4g");
    vtkcubeaxesactor2d->SetFlyModeToOuterEdges();
    //vtkcubeaxesactor2d->SetFlyModeToClosestTriad();
    //vtkcubeaxesactor2d->SetFlyModeToNone();
    vtkcubeaxesactor2d->SetAxisTitleTextProperty(vtktextproperty.GetPointer());
    vtkcubeaxesactor2d->SetAxisLabelTextProperty(vtktextproperty.GetPointer());
    vtkcubeaxesactor2d->SetXLabel("background fluid saturation");
    vtkcubeaxesactor2d->SetYLabel("background solid concentration");
    vtkcubeaxesactor2d->SetZLabel("saturated bulk modulus (GPa)");
    vtkrenderer->AddViewProp(vtkcubeaxesactor2d.GetPointer());

    // vtk examples : ScalarBarActor.cxx
    vtkscalarbaractor = vtkSmartPointer<vtkScalarBarActor>::New();
    vtkscalarbaractor->SetLookupTable(vtkcolorlookuptable);
    vtkscalarbaractor->SetTitle("saturated bulk modulus (GPa)");
    vtkscalarbaractor->SetLabelFormat("%6.4g");
    vtkscalarbaractor->SetTitleTextProperty(vtktextproperty.GetPointer());
    vtkscalarbaractor->SetLabelTextProperty(vtktextproperty.GetPointer());
    vtkscalarbaractor->SetWidth(0.09);
    vtkscalarbaractor->SetHeight(0.8);
    //vtkscalarbaractor->GetPositionCoordinate()->SetValue(0.1, 0.01);
    vtkscalarbaractor->SetUnconstrainedFontSize(true);
    vtkrenderer->AddActor2D(vtkscalarbaractor);

    PrivateUpdatePlot();



    // =================================================================================================================
    // main splitter
    QSplitter* splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(controls_widget);
    splitter->addWidget(qvtkopenglwidget);

    /* === signals/slots === */
    connect(foreground_fluid_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnForegroundFluidComboBoxChanged(int)));
    connect(background_solid_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnBackgroundSolidComboBoxChanged(int)));
    connect(foreground_solid_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnForegroundSolidComboBoxChanged(int)));
    connect(hill_average_slider, SIGNAL(sliderReleased()), this, SLOT(OnHillAverageSliderReleased()));
    connect(porosity_slider, SIGNAL(sliderReleased()), this, SLOT(OnPorositySliderReleaed()));
    connect(rockproperty_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnRockPropertyComboBoxChanged(int)));

    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);
}

MixingLawsView::~MixingLawsView() {
    // destructor
}

// slots
void MixingLawsView::OnForegroundFluidComboBoxChanged(int i) {
    // update the active fluid properties value
    // DEBUG std::cout << "OnFluidComboBoxChanged called with i = " << i << std::endl;
    switch(i) {
        case 0: {
            // oil
            foreground_fluid_K = oil_K;       // (GPa)
            foreground_fluid_rho = oil_rho;   // (g/cm**3)
            break;
        }
        case 1: {
            // gas
            foreground_fluid_K = gas_K;       // (GPa)
            foreground_fluid_rho = gas_rho;   // (g/cm**3)
            break;
        }
        default: {
            // brine
            foreground_fluid_K = brine_K;       // (GPa)
            foreground_fluid_rho = brine_rho;   // (g/cm**3)
            break;
        }
    }
    // DEBUG std::cout << "acitve fluid density : " << active_fluid_rho << std::endl;
    // DEBUG std::cout << "acitve fluid bulk mod : " << active_fluid_K << std::endl;
    foreground_fluid_density_value_lineedit->setText(QString::number(foreground_fluid_rho));
    foreground_fluid_bulkmodulus_value_lineedit->setText(QString::number(foreground_fluid_K));

    PrivateUpdatePlot();
}

void MixingLawsView::OnBackgroundSolidComboBoxChanged(int i) {
    //
    switch(i) {
        case 0: { // Augite
            background_solid_K = mpc::data::AugiteBulkModulus<double>();
            background_solid_mu = mpc::data::AugiteShearModulus<double>();
            background_solid_rho = mpc::data::AugiteDensity<double>();
            break;
        }
        case 1: { // Albite
            background_solid_K = mpc::data::AlbiteBulkModulus<double>();
            background_solid_mu = mpc::data::AlbiteShearModulus<double>();
            background_solid_rho = mpc::data::AlbiteDensity<double>();
            break;
        }
        case 2: { // Anorthite
            background_solid_K = mpc::data::AnorthiteBulkModulus<double>();
            background_solid_mu = mpc::data::AnorthiteShearModulus<double>();
            background_solid_rho = mpc::data::AnorthiteDensity<double>();
            break;
        }
        case 3: { // Labradorite
            background_solid_K = mpc::data::LabradoriteBulkModulus<double>();
            background_solid_mu = mpc::data::LabradoriteShearModulus<double>();
            background_solid_rho = mpc::data::LabradoriteDensity<double>();
            break;
        }
        case 4: { // Microcline
            background_solid_K = mpc::data::MicroclineBulkModulus<double>();
            background_solid_mu = mpc::data::MicroclineShearModulus<double>();
            background_solid_rho = mpc::data::MicroclineDensity<double>();
            break;
        }
        case 5: { // Oligoclase
            background_solid_K = mpc::data::OligoclaseBulkModulus<double>();
            background_solid_mu = mpc::data::OligoclaseShearModulus<double>();
            background_solid_rho = mpc::data::OligoclaseDensity<double>();
            break;
        }
        case 6: { // Coesite
            background_solid_K = mpc::data::CoesiteBulkModulus<double>();
            background_solid_mu = mpc::data::CoesiteShearModulus<double>();
            background_solid_rho = mpc::data::CoesiteDensity<double>();
            break;
        }
        case 7: { // Epidote
            background_solid_K = mpc::data::EpidoteBulkModulus<double>();
            background_solid_mu = mpc::data::EpidoteShearModulus<double>();
            background_solid_rho = mpc::data::EpidoteDensity<double>();
            break;
        }
        case 8: { // Hornblende
            background_solid_K = mpc::data::HornblendeBulkModulus<double>();
            background_solid_mu = mpc::data::HornblendeShearModulus<double>();
            background_solid_rho = mpc::data::HornblendeDensity<double>();
            break;
        }
        case 9: { // Muscovite
            background_solid_K = mpc::data::MuscoviteBulkModulus<double>();
            background_solid_mu = mpc::data::MuscoviteShearModulus<double>();
            background_solid_rho = mpc::data::MuscoviteDensity<double>();
            break;
        }
        case 10: { // Gypsum
            background_solid_K = mpc::data::GypsumBulkModulus<double>();
            background_solid_mu = mpc::data::GypsumShearModulus<double>();
            background_solid_rho = mpc::data::GypsumDensity<double>();
            break;
        }
        case 11: { // Enstatite
            background_solid_K = mpc::data::EnstatiteBulkModulus<double>();
            background_solid_mu = mpc::data::EnstatiteShearModulus<double>();
            background_solid_rho = mpc::data::EnstatiteDensity<double>();
            break;
        }
        case 12: { // Forsterite
            background_solid_K = mpc::data::ForsteriteBulkModulus<double>();
            background_solid_mu = mpc::data::ForsteriteShearModulus<double>();
            background_solid_rho = mpc::data::ForsteriteDensity<double>();
            break;
        }
        case 13: { // Fayalite
            background_solid_K = mpc::data::FayaliteBulkModulus<double>();
            background_solid_mu = mpc::data::FayaliteShearModulus<double>();
            background_solid_rho = mpc::data::FayaliteDensity<double>();
            break;
        }
        case 14: { // Montecellite
            background_solid_K = mpc::data::MontecelliteBulkModulus<double>();
            background_solid_mu = mpc::data::MontecelliteShearModulus<double>();
            background_solid_rho = mpc::data::MontecelliteDensity<double>();
            break;
        }
        case 15: { // Andalusite
            background_solid_K = mpc::data::AndalusiteBulkModulus<double>();
            background_solid_mu = mpc::data::AndalusiteShearModulus<double>();
            background_solid_rho = mpc::data::AndalusiteDensity<double>();
            break;
        }
        case 16: { // Silimanite
            background_solid_K = mpc::data::SilimaniteBulkModulus<double>();
            background_solid_mu = mpc::data::SilimaniteShearModulus<double>();
            background_solid_rho = mpc::data::SilimaniteDensity<double>();
            break;
        }
        case 17: { // Barite
            background_solid_K = mpc::data::BariteBulkModulus<double>();
            background_solid_mu = mpc::data::BariteShearModulus<double>();
            background_solid_rho = mpc::data::BariteDensity<double>();
            break;
        }
        case 18: { // Anhydrite
            background_solid_K = mpc::data::AnhydriteBulkModulus<double>();
            background_solid_mu = mpc::data::AnhydriteShearModulus<double>();
            background_solid_rho = mpc::data::AnhydriteDensity<double>();
            break;
        }
        case 19: { // Dolomite
            background_solid_K = mpc::data::DolomiteBulkModulus<double>();
            background_solid_mu = mpc::data::DolomiteShearModulus<double>();
            background_solid_rho = mpc::data::DolomiteDensity<double>();
            break;
        }
        case 20: { // Rutile
            background_solid_K = mpc::data::RutileBulkModulus<double>();
            background_solid_mu = mpc::data::RutileShearModulus<double>();
            background_solid_rho = mpc::data::RutileDensity<double>();
            break;
        }
        case 21: { // Zircon
            background_solid_K = mpc::data::ZirconBulkModulus<double>();
            background_solid_mu = mpc::data::ZirconShearModulus<double>();
            background_solid_rho = mpc::data::ZirconDensity<double>();
            break;
        }
        case 22: { // Corundum
            background_solid_K = mpc::data::CorundumBulkModulus<double>();
            background_solid_mu = mpc::data::CorundumShearModulus<double>();
            background_solid_rho = mpc::data::CorundumDensity<double>();
            break;
        }
        case 23: { // Calcite
            background_solid_K = mpc::data::CalciteBulkModulus<double>();
            background_solid_mu = mpc::data::CalciteShearModulus<double>();
            background_solid_rho = mpc::data::CalciteDensity<double>();
            break;
        }
        case 24: { // Quartz
            background_solid_K = mpc::data::QuartzBulkModulus<double>();
            background_solid_mu = mpc::data::QuartzShearModulus<double>();
            background_solid_rho = mpc::data::QuartzDensity<double>();
            break;
        }
        case 25: { // Tourmaline
            background_solid_K = mpc::data::TourmalineBulkModulus<double>();
            background_solid_mu = mpc::data::TourmalineShearModulus<double>();
            background_solid_rho = mpc::data::TourmalineDensity<double>();
            break;
        }
        case 26: { // Beryl
            background_solid_K = mpc::data::BerylBulkModulus<double>();
            background_solid_mu = mpc::data::BerylShearModulus<double>();
            background_solid_rho = mpc::data::BerylDensity<double>();
            break;
        }
        case 27: { // Graphite
            background_solid_K = mpc::data::GraphiteBulkModulus<double>();
            background_solid_mu = mpc::data::GraphiteShearModulus<double>();
            background_solid_rho = mpc::data::GraphiteDensity<double>();
            break;
        }
        case 28: { // Wusite
            background_solid_K = mpc::data::WusiteBulkModulus<double>();
            background_solid_mu = mpc::data::WusiteShearModulus<double>();
            background_solid_rho = mpc::data::WusiteDensity<double>();
            break;
        }
        case 29: { // Manganosite
            background_solid_K = mpc::data::ManganositeBulkModulus<double>();
            background_solid_mu = mpc::data::ManganositeShearModulus<double>();
            background_solid_rho = mpc::data::ManganositeDensity<double>();
            break;
        }
        case 30: { // Periclase
            background_solid_K = mpc::data::PericlaseBulkModulus<double>();
            background_solid_mu = mpc::data::PericlaseShearModulus<double>();
            background_solid_rho = mpc::data::PericlaseDensity<double>();
            break;
        }
        case 31: { // Magnetite
            background_solid_K = mpc::data::MagnetiteBulkModulus<double>();
            background_solid_mu = mpc::data::MagnetiteShearModulus<double>();
            background_solid_rho = mpc::data::MagnetiteDensity<double>();
            break;
        }
        case 32: { // Chromite
            background_solid_K = mpc::data::ChromiteBulkModulus<double>();
            background_solid_mu = mpc::data::ChromiteShearModulus<double>();
            background_solid_rho = mpc::data::ChromiteDensity<double>();
            break;
        }
        case 33: { // Spinel
            background_solid_K = mpc::data::SpinelBulkModulus<double>();
            background_solid_mu = mpc::data::SpinelShearModulus<double>();
            background_solid_rho = mpc::data::SpinelDensity<double>();
            break;
        }
        case 34: { // Pyrite
            background_solid_K = mpc::data::PyriteBulkModulus<double>();
            background_solid_mu = mpc::data::PyriteShearModulus<double>();
            background_solid_rho = mpc::data::PyriteDensity<double>();
            break;
        }
        case 35: { // Galena
            background_solid_K = mpc::data::GalenaBulkModulus<double>();
            background_solid_mu = mpc::data::GalenaShearModulus<double>();
            background_solid_rho = mpc::data::GalenaDensity<double>();
            break;
        }
        case 36: { // Sphalerite
            background_solid_K = mpc::data::SphaleriteBulkModulus<double>();
            background_solid_mu = mpc::data::SphaleriteShearModulus<double>();
            background_solid_rho = mpc::data::SphaleriteDensity<double>();
            break;
        }
        case 37: { // Fluorite
            background_solid_K = mpc::data::FluoriteBulkModulus<double>();
            background_solid_mu = mpc::data::FluoriteShearModulus<double>();
            background_solid_rho = mpc::data::FluoriteDensity<double>();
            break;
        }
        case 38: { // Halite
            background_solid_K = mpc::data::HaliteBulkModulus<double>();
            background_solid_mu = mpc::data::HaliteShearModulus<double>();
            background_solid_rho = mpc::data::HaliteDensity<double>();
            break;
        }
        case 39: { // Sylvite
            background_solid_K = mpc::data::SylviteBulkModulus<double>();
            background_solid_mu = mpc::data::SylviteShearModulus<double>();
            background_solid_rho = mpc::data::SylviteDensity<double>();
            break;
        }
        default: {}

    }  // end switch
    background_solid_bulkmodulus_value_lineedit->setText(QString::number(background_solid_K));
    background_solid_shearmodulus_value_lineedit->setText(QString::number(background_solid_mu));
    background_solid_density_value_lineedit->setText(QString::number(background_solid_rho));

    PrivateUpdatePlot();
}

void MixingLawsView::OnForegroundSolidComboBoxChanged(int i) {
    //
    switch(i) {
        case 0: { // Augite
            foreground_solid_K = mpc::data::AugiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::AugiteShearModulus<double>();
            foreground_solid_rho = mpc::data::AugiteDensity<double>();
            break;
        }
        case 1: { // Albite
            foreground_solid_K = mpc::data::AlbiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::AlbiteShearModulus<double>();
            foreground_solid_rho = mpc::data::AlbiteDensity<double>();
            break;
        }
        case 2: { // Anorthite
            foreground_solid_K = mpc::data::AnorthiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::AnorthiteShearModulus<double>();
            foreground_solid_rho = mpc::data::AnorthiteDensity<double>();
            break;
        }
        case 3: { // Labradorite
            foreground_solid_K = mpc::data::LabradoriteBulkModulus<double>();
            foreground_solid_mu = mpc::data::LabradoriteShearModulus<double>();
            foreground_solid_rho = mpc::data::LabradoriteDensity<double>();
            break;
        }
        case 4: { // Microcline
            foreground_solid_K = mpc::data::MicroclineBulkModulus<double>();
            foreground_solid_mu = mpc::data::MicroclineShearModulus<double>();
            foreground_solid_rho = mpc::data::MicroclineDensity<double>();
            break;
        }
        case 5: { // Oligoclase
            foreground_solid_K = mpc::data::OligoclaseBulkModulus<double>();
            foreground_solid_mu = mpc::data::OligoclaseShearModulus<double>();
            foreground_solid_rho = mpc::data::OligoclaseDensity<double>();
            break;
        }
        case 6: { // Coesite
            foreground_solid_K = mpc::data::CoesiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::CoesiteShearModulus<double>();
            foreground_solid_rho = mpc::data::CoesiteDensity<double>();
            break;
        }
        case 7: { // Epidote
            foreground_solid_K = mpc::data::EpidoteBulkModulus<double>();
            foreground_solid_mu = mpc::data::EpidoteShearModulus<double>();
            foreground_solid_rho = mpc::data::EpidoteDensity<double>();
            break;
        }
        case 8: { // Hornblende
            foreground_solid_K = mpc::data::HornblendeBulkModulus<double>();
            foreground_solid_mu = mpc::data::HornblendeShearModulus<double>();
            foreground_solid_rho = mpc::data::HornblendeDensity<double>();
            break;
        }
        case 9: { // Muscovite
            foreground_solid_K = mpc::data::MuscoviteBulkModulus<double>();
            foreground_solid_mu = mpc::data::MuscoviteShearModulus<double>();
            foreground_solid_rho = mpc::data::MuscoviteDensity<double>();
            break;
        }
        case 10: { // Gypsum
            foreground_solid_K = mpc::data::GypsumBulkModulus<double>();
            foreground_solid_mu = mpc::data::GypsumShearModulus<double>();
            foreground_solid_rho = mpc::data::GypsumDensity<double>();
            break;
        }
        case 11: { // Enstatite
            foreground_solid_K = mpc::data::EnstatiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::EnstatiteShearModulus<double>();
            foreground_solid_rho = mpc::data::EnstatiteDensity<double>();
            break;
        }
        case 12: { // Forsterite
            foreground_solid_K = mpc::data::ForsteriteBulkModulus<double>();
            foreground_solid_mu = mpc::data::ForsteriteShearModulus<double>();
            foreground_solid_rho = mpc::data::ForsteriteDensity<double>();
            break;
        }
        case 13: { // Fayalite
            foreground_solid_K = mpc::data::FayaliteBulkModulus<double>();
            foreground_solid_mu = mpc::data::FayaliteShearModulus<double>();
            foreground_solid_rho = mpc::data::FayaliteDensity<double>();
            break;
        }
        case 14: { // Montecellite
            foreground_solid_K = mpc::data::MontecelliteBulkModulus<double>();
            foreground_solid_mu = mpc::data::MontecelliteShearModulus<double>();
            foreground_solid_rho = mpc::data::MontecelliteDensity<double>();
            break;
        }
        case 15: { // Andalusite
            foreground_solid_K = mpc::data::AndalusiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::AndalusiteShearModulus<double>();
            foreground_solid_rho = mpc::data::AndalusiteDensity<double>();
            break;
        }
        case 16: { // Silimanite
            foreground_solid_K = mpc::data::SilimaniteBulkModulus<double>();
            foreground_solid_mu = mpc::data::SilimaniteShearModulus<double>();
            foreground_solid_rho = mpc::data::SilimaniteDensity<double>();
            break;
        }
        case 17: { // Barite
            foreground_solid_K = mpc::data::BariteBulkModulus<double>();
            foreground_solid_mu = mpc::data::BariteShearModulus<double>();
            foreground_solid_rho = mpc::data::BariteDensity<double>();
            break;
        }
        case 18: { // Anhydrite
            foreground_solid_K = mpc::data::AnhydriteBulkModulus<double>();
            foreground_solid_mu = mpc::data::AnhydriteShearModulus<double>();
            foreground_solid_rho = mpc::data::AnhydriteDensity<double>();
            break;
        }
        case 19: { // Dolomite
            foreground_solid_K = mpc::data::DolomiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::DolomiteShearModulus<double>();
            foreground_solid_rho = mpc::data::DolomiteDensity<double>();
            break;
        }
        case 20: { // Rutile
            foreground_solid_K = mpc::data::RutileBulkModulus<double>();
            foreground_solid_mu = mpc::data::RutileShearModulus<double>();
            foreground_solid_rho = mpc::data::RutileDensity<double>();
            break;
        }
        case 21: { // Zircon
            foreground_solid_K = mpc::data::ZirconBulkModulus<double>();
            foreground_solid_mu = mpc::data::ZirconShearModulus<double>();
            foreground_solid_rho = mpc::data::ZirconDensity<double>();
            break;
        }
        case 22: { // Corundum
            foreground_solid_K = mpc::data::CorundumBulkModulus<double>();
            foreground_solid_mu = mpc::data::CorundumShearModulus<double>();
            foreground_solid_rho = mpc::data::CorundumDensity<double>();
            break;
        }
        case 23: { // Calcite
            foreground_solid_K = mpc::data::CalciteBulkModulus<double>();
            foreground_solid_mu = mpc::data::CalciteShearModulus<double>();
            foreground_solid_rho = mpc::data::CalciteDensity<double>();
            break;
        }
        case 24: { // Quartz
            foreground_solid_K = mpc::data::QuartzBulkModulus<double>();
            foreground_solid_mu = mpc::data::QuartzShearModulus<double>();
            foreground_solid_rho = mpc::data::QuartzDensity<double>();
            break;
        }
        case 25: { // Tourmaline
            foreground_solid_K = mpc::data::TourmalineBulkModulus<double>();
            foreground_solid_mu = mpc::data::TourmalineShearModulus<double>();
            foreground_solid_rho = mpc::data::TourmalineDensity<double>();
            break;
        }
        case 26: { // Beryl
            foreground_solid_K = mpc::data::BerylBulkModulus<double>();
            foreground_solid_mu = mpc::data::BerylShearModulus<double>();
            foreground_solid_rho = mpc::data::BerylDensity<double>();
            break;
        }
        case 27: { // Graphite
            foreground_solid_K = mpc::data::GraphiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::GraphiteShearModulus<double>();
            foreground_solid_rho = mpc::data::GraphiteDensity<double>();
            break;
        }
        case 28: { // Wusite
            foreground_solid_K = mpc::data::WusiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::WusiteShearModulus<double>();
            foreground_solid_rho = mpc::data::WusiteDensity<double>();
            break;
        }
        case 29: { // Manganosite
            foreground_solid_K = mpc::data::ManganositeBulkModulus<double>();
            foreground_solid_mu = mpc::data::ManganositeShearModulus<double>();
            foreground_solid_rho = mpc::data::ManganositeDensity<double>();
            break;
        }
        case 30: { // Periclase
            foreground_solid_K = mpc::data::PericlaseBulkModulus<double>();
            foreground_solid_mu = mpc::data::PericlaseShearModulus<double>();
            foreground_solid_rho = mpc::data::PericlaseDensity<double>();
            break;
        }
        case 31: { // Magnetite
            foreground_solid_K = mpc::data::MagnetiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::MagnetiteShearModulus<double>();
            foreground_solid_rho = mpc::data::MagnetiteDensity<double>();
            break;
        }
        case 32: { // Chromite
            foreground_solid_K = mpc::data::ChromiteBulkModulus<double>();
            foreground_solid_mu = mpc::data::ChromiteShearModulus<double>();
            foreground_solid_rho = mpc::data::ChromiteDensity<double>();
            break;
        }
        case 33: { // Spinel
            foreground_solid_K = mpc::data::SpinelBulkModulus<double>();
            foreground_solid_mu = mpc::data::SpinelShearModulus<double>();
            foreground_solid_rho = mpc::data::SpinelDensity<double>();
            break;
        }
        case 34: { // Pyrite
            foreground_solid_K = mpc::data::PyriteBulkModulus<double>();
            foreground_solid_mu = mpc::data::PyriteShearModulus<double>();
            foreground_solid_rho = mpc::data::PyriteDensity<double>();
            break;
        }
        case 35: { // Galena
            foreground_solid_K = mpc::data::GalenaBulkModulus<double>();
            foreground_solid_mu = mpc::data::GalenaShearModulus<double>();
            foreground_solid_rho = mpc::data::GalenaDensity<double>();
            break;
        }
        case 36: { // Sphalerite
            foreground_solid_K = mpc::data::SphaleriteBulkModulus<double>();
            foreground_solid_mu = mpc::data::SphaleriteShearModulus<double>();
            foreground_solid_rho = mpc::data::SphaleriteDensity<double>();
            break;
        }
        case 37: { // Fluorite
            foreground_solid_K = mpc::data::FluoriteBulkModulus<double>();
            foreground_solid_mu = mpc::data::FluoriteShearModulus<double>();
            foreground_solid_rho = mpc::data::FluoriteDensity<double>();
            break;
        }
        case 38: { // Halite
            foreground_solid_K = mpc::data::HaliteBulkModulus<double>();
            foreground_solid_mu = mpc::data::HaliteShearModulus<double>();
            foreground_solid_rho = mpc::data::HaliteDensity<double>();
            break;
        }
        case 39: { // Sylvite
            foreground_solid_K = mpc::data::SylviteBulkModulus<double>();
            foreground_solid_mu = mpc::data::SylviteShearModulus<double>();
            foreground_solid_rho = mpc::data::SylviteDensity<double>();
            break;
        }
        default: {}

    }  // end switch
    foreground_solid_bulkmodulus_value_lineedit->setText(QString::number(foreground_solid_K));
    foreground_solid_shearmodulus_value_lineedit->setText(QString::number(foreground_solid_mu));
    foreground_solid_density_value_lineedit->setText(QString::number(foreground_solid_rho));

    PrivateUpdatePlot();
}

void MixingLawsView::OnHillAverageSliderReleased() {
    // when slider is released, update the hill weighting coefficient data member and the hill average label
    hill_weighting_coefficient = hill_average_slider->value() * 0.01;
    hill_average_value_lineedit->setText(QString::number(hill_weighting_coefficient));

    PrivateUpdatePlot();
}

void MixingLawsView::OnPorositySliderReleaed() {
    //
    int value = porosity_slider->value();
    fluid_volume_fraction = value * 0.01;
    solid_volume_fraction = 1 - fluid_volume_fraction;
    porosity_value_lineedit->setText(QString::number(fluid_volume_fraction));

    PrivateUpdatePlot();
}

void MixingLawsView::OnRockPropertyComboBoxChanged(int i) {
    // 0 : "saturated bulk modulus"
    // 1 : "effective shear modulus"
    // 2 : "effective density"
    // 3 : "effective p-wave velocity"
    // 4 : "effective s-wave velocity"
    // 5 : "effective Vp/Vs ratio"
    // 6 : "effective Vs/Vp ratio"
    // 7 : "effective Poisson's ratio"
    PrivateUpdatePlot();
}

// member functions

// private member functions
void MixingLawsView::PrivateUpdatePlot() {
    // update the effective values and plot points

    int requested_rockproperty = rockproperty_combobox->currentIndex();
    // determines the output rock property to plot
    // 0 : "saturated bulk modulus"
    // 1 : "effective shear modulus"
    // 2 : "effective density"
    // 3 : "effective p-wave velocity"
    // 4 : "effective s-wave velocity"
    // 5 : "effective Vp/Vs ratio"
    // 6 : "effective Vs/Vp ratio"
    // 7 : "effective Poisson's ratio"
    //--std::cout << "requested rock property : " << requested_rockproperty << std::endl;

    // mpc
    auto background_fluid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(background_fluid_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(background_fluid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

    auto foreground_fluid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(foreground_fluid_K), mpc::rockphysics::ShearModulusType<double>(0.0), mpc::rockphysics::DensityType<double>(foreground_fluid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > fluid_mixture_vec{
            background_fluid_mixture_tuple,
            foreground_fluid_mixture_tuple
    };

    mpc::rockphysics::FluidPhase<double> fluidphase = mpc::rockphysics::FluidPhase(fluid_mixture_vec);

    auto background_solid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(background_solid_K), mpc::rockphysics::ShearModulusType<double>(background_solid_mu), mpc::rockphysics::DensityType<double>(background_solid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));

    auto foreground_solid_mixture_tuple = std::make_tuple(mpc::rockphysics::BulkModulusType<double>(foreground_solid_K), mpc::rockphysics::ShearModulusType<double>(foreground_solid_mu), mpc::rockphysics::DensityType<double>(foreground_solid_rho), mpc::rockphysics::VolumeFractionType<double>(0.5));


    std::vector< std::tuple<mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double>, mpc::rockphysics::DensityType<double>, mpc::rockphysics::VolumeFractionType<double> > > solid_mixture_vec{
            background_solid_mixture_tuple,
            foreground_solid_mixture_tuple
    };

    mpc::rockphysics::SolidPhase<double> solidphase = mpc::rockphysics::SolidPhase(solid_mixture_vec);

    // update plot;
    vtkpoints->Reset();
    double xx, yy, zz;
    std::vector<double> vf_vec_values{1.0, 0.0};
    double interval = 1.0 / (numgridpoints-1);

    // initialize upper and lower bound pairs
    std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_upper = solidphase.VoigtUpperBound();

    std::pair< mpc::rockphysics::BulkModulusType<double>, mpc::rockphysics::ShearModulusType<double> > kmu_lower = solidphase.RuessLowerBound();

    double solid_effective_density = 1.0;
    double solid_effective_bulkmodulus = 1.0;
    double solid_effective_shearmodulus = 1.0;
    double fluid_effective_density = 1.0;
    double fluid_effective_bulkmodulus = 1.0;
    double fluid_effective_shearmodulus = 1.0;
    double porous_rockframe_bulkmodulus = 1.0;
    double composite_saturated_bulkmodulus = 1.0;
    double composite_shearmodulus = 1.0;
    double composite_density = 1.0;
    double composite_pwave_velocity = 1.0;
    double composite_swave_velocity = 1.0;
    double composite_VpVs_ratio = 1.0;
    double composite_VsVp_ratio = 1.0;
    double composite_poissons_ratio = 1.0;


    for (int m=0; m<numgridpoints; ++m) {
        // fluid phase
        // increasing row index corresponds to increasing BACKGROUND fluid saturation
        vf_vec_values = std::vector<double>({ m*interval, 1.0 - (m*interval) });

        fluidphase.VolumeFractionTypeVector(vf_vec_values);
        fluid_effective_bulkmodulus = fluidphase.EffectiveBulkModulusType().value;
        fluid_effective_shearmodulus = fluidphase.EffectiveShearModulusType().value;
        fluid_effective_density = fluidphase.EffectiveDensityType().value;
        for (int n=0; n<numgridpoints; ++n) {
            // solid phase
            // increasing column index corresponds to increasing BACKGROUND solid concentration
            vf_vec_values = std::vector<double>({ n*interval, 1.0 - (n*interval) });

            solidphase.VolumeFractionTypeVector(vf_vec_values);
            kmu_upper = solidphase.VoigtUpperBound();
            kmu_lower = solidphase.RuessLowerBound();

            solid_effective_density = solidphase.EffectiveDensityType().value;

            solid_effective_shearmodulus = (kmu_upper.second.value * hill_weighting_coefficient) + (kmu_lower.second.value * (1-hill_weighting_coefficient));  // 0 -> Ruess lower bound; 1 -> Voigt upper bound

            solid_effective_bulkmodulus = (kmu_upper.first.value * hill_weighting_coefficient) + (kmu_lower.first.value * (1-hill_weighting_coefficient));  // 0 -> Ruess lower bound; 1 -> Voigt upper bound
            porous_rockframe_bulkmodulus = 1.5 * solid_effective_shearmodulus;  // oversimiplified assumption!!!!
            composite_saturated_bulkmodulus = this->PrivateCalcKSat(porous_rockframe_bulkmodulus, solid_effective_bulkmodulus, fluid_effective_bulkmodulus, fluid_volume_fraction);


            composite_shearmodulus = solid_effective_shearmodulus;  // no influence from fluid
            composite_density = 0.5 * (solid_effective_density + fluid_effective_density);

            std::cout << "porosity" << porosity_slider->value()*0.01 << std::endl;
            std::cout << "composite bulkmodulus" << composite_saturated_bulkmodulus << std::endl;
            mpc::rockphysics::BulkModulusType<double> K_type = mpc::rockphysics::BulkModulusType<double>(composite_saturated_bulkmodulus);
            mpc::rockphysics::ShearModulusType<double> mu_type = mpc::rockphysics::ShearModulusType<double>(solid_effective_shearmodulus);
            mpc::rockphysics::DensityType<double> rho_type = mpc::rockphysics::DensityType<double>(0.5 * (solid_effective_density + fluid_effective_density));
            mpc::rockphysics::CompressionalWaveVelocityType<double> pvel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::CompressionalWaveVelocityType<double> >::Compute(K_type, mu_type, rho_type);
            composite_pwave_velocity = pvel_type.value;

            mpc::rockphysics::ShearWaveVelocityType<double> svel_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::ShearWaveVelocityType<double> >::Compute(mu_type, rho_type);
            composite_swave_velocity = svel_type.value;

            composite_VpVs_ratio = composite_pwave_velocity / composite_swave_velocity;
            composite_VsVp_ratio = composite_swave_velocity / composite_pwave_velocity;

            mpc::rockphysics::PoissonsRatioType<double> nu_type = mpc::rockphysics::RockPhysicsTransforms<double,mpc::rockphysics::PoissonsRatioType<double> >::Compute(K_type, mu_type);
            double composite_poissons_ratio = nu_type.value;


            // IMPORTANT !!!  TODO: zscale???
            xx = double(m) / double((numgridpoints - 1));  // background fluid saturation
            yy = double(n) / double((numgridpoints - 1));  // background solid concentration
            // TODO: redesign with switch outside for loop?
            switch (requested_rockproperty) {
                case 0: {
                    // 0 : "saturated bulk modulus"
                    //--std::cout << "saturated bulk modulus called" << std::endl;
                    zz = composite_saturated_bulkmodulus * zscale_K;  // default
                    break;
                }
                case 1: {
                    // 1 : "effective shear modulus"
                    //--std::cout << "effective shear modulus called" << std::endl;
                    zz = composite_shearmodulus * zscale_mu;
                    break;
                }
                case 2: {
                    // 2 : "effective density"
                    //--std::cout << "effective density called" << std::endl;
                    zz = composite_density * zscale_rho;  // simple mean
                    break;
                }
                case 3: {
                    // 3 : "effective p-wave velocity"
                    //--std::cout << "effective p-wave velocity called" << std::endl;
                    zz = composite_pwave_velocity * zscale_pvel;
                    break;
                }
                case 4: {
                    // 4 : "effective s-wave velocity"
                    //--std::cout << "effective s-wave velocity called" << std::endl;
                    zz = composite_swave_velocity * zscale_svel;
                    break;
                }
                case 5: {
                    // 5 : "effective Vp/Vs ratio"
                    //--std::cout << "effective Vp/Vs ratio called" << std::endl;
                    zz = composite_VpVs_ratio * zscale_vpvs;
                    break;
                }
                case 6: {
                    // 6 : "effective Vs/Vp ratio"
                    //--std::cout << "effective Vs/Vp ratio called" << std::endl;
                    zz = composite_VsVp_ratio * zscale_vsvp;
                    break;
                }
                case 7: {
                    // 7 : "effective Poisson's ratio"
                    //--std::cout << "effective Poisson's ratio called" << std::endl;
                    zz = composite_poissons_ratio * zscale_nu;
                    break;
                }
                default: {
                    //--std::cout << "default; something went wrong!" << std::endl;
                    zz = 0.0;
                    break;
                }
            }
            //std::cout << "output z value : " << zz << std::endl;  // =================================================
            vtkpoints->InsertNextPoint(xx, yy, zz);

        }  // END for (n ...)
    }  // END for (m ...)



    // Add the grid points to a polydata object
    //..vtkinputpolydata = vtkSmartPointer<vtkPolyData>::New();
    //vtkinputpolydata->SetPoints(vtkpoints);

    // vtk examples - TriangulateTerrainMap.cxx
    //..vtkglyphfilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
    //..vtkglyphfilter->SetInputData(vtkinputpolydata);
    vtkglyphfilter->Update();

    //..pointsmapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    //..vtkpointsmapper->SetInputConnection(vtkglyphfilter->GetOutputPort());

    //..pointsactor = vtkSmartPointer<vtkActor>::New();
    //..vtkpointsactor->SetMapper(vtkpointsmapper);
    //..pointsactor->GetProperty()->SetPointSize(3);
    //..pointsactor->GetProperty()->SetColor(0.5,0.5,0.5);
    //..vtkrenderer->AddActor(pointsactor);

    // Triangulate the grid points
    //..vtkdelaunay2d = vtkSmartPointer<vtkDelaunay2D>::New();
    //..vtkdelaunay2d->SetInputData(vtkinputpolydata);
    vtkdelaunay2d->Update();
    vtkoutputpolydata = vtkdelaunay2d->GetOutput();

    double bounds[6];
    vtkoutputpolydata->GetBounds(bounds);

    // Find min and max z
    double minx = bounds[0];
    double maxx = bounds[1];
    double miny = bounds[2];
    double maxy = bounds[3];
    double minz = bounds[4];
    double maxz = bounds[5];

    //--std::cout << "bounds : " << minx << " , " << maxx << " , " << miny << " , " << maxy << " , " << minz << " , " << maxz << std::endl;

    // Create the color map
    //..vtkcolorlookuptable = vtkSmartPointer<vtkLookupTable>::New();
    vtkcolorlookuptable->SetTableRange(minz, maxz);
    vtkcolorlookuptable->Build();

    // Generate the colors for each point based on the color map
    //..vtkcolorchararray = vtkSmartPointer<vtkUnsignedCharArray>::New();
    //..vtkcolorchararray->SetNumberOfComponents(3);
    //..vtkcolorchararray->SetName("Colors");

    //++std::cout << "There are " << vtkoutputpolydata->GetNumberOfPoints() << " points." << std::endl;

    vtkcolorchararray->Reset();
    for(int i = 0; i < vtkoutputpolydata->GetNumberOfPoints(); i++)
    {
        double p[3];
        vtkoutputpolydata->GetPoint(i,p);
        //std::cout << "point : " << i << ", x : " << p[0] << ", y : " << p[1] << ", z : " << p[2] << std::endl;

        double dcolor[3];
        vtkcolorlookuptable->GetColor(p[2], dcolor);
        //std::cout << "dcolor: " << dcolor[0] << " " << dcolor[1] << " " << dcolor[2] << std::endl;
        unsigned char color[3];
        for(unsigned int j = 0; j < 3; j++)
        {
            color[j] = static_cast<unsigned char>(255.0 * dcolor[j]);
        }
        //std::cout << "color: " << (int)color[0] << " " << (int)color[1] << " " << (int)color[2] << std::endl;

        //vtkcolorchararray->InsertNextTupleValue(color);  // VTK version < 7
        vtkcolorchararray->InsertNextTypedTuple(color);
    }

    vtkoutputpolydata->GetPointData()->SetScalars(vtkcolorchararray);  // vtkPointData.h

    // Create a mapper and actor
    //..vtkpolydatamapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    //..vtkpolydatamapper->SetInputData(vtkoutputpolydata);


    //..vtkactor = vtkSmartPointer<vtkActor>::New();
    //..vtkactor->SetMapper(vtkpolydatamapper);


    // Add the actor to the scene
    //..vtkrenderer->AddActor(vtkactor);
    // END vtk examples : colored elevation ============================================================================

    // vtk examples : CubeAxesActor2D.cxx
    // Create a vtkOutlineFilter to draw the bounding box of the data set.
    // Also create the associated mapper and actor.
    //..vtkoutline = vtkSmartPointer<vtkOutlineFilter>::New();
    //..vtkoutline->SetInputConnection(vtkdelaunay2d->GetOutputPort());  // requires subclass of vtkAlgorithm


    //..vtkoutlinemapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    //..vtkoutlinemapper->SetInputConnection(vtkoutline->GetOutputPort());

    //..vtkoutlineactor = vtkSmartPointer<vtkActor>::New();
    //..vtkoutlineactor->SetMapper(vtkoutlinemapper.GetPointer());
    //..vtkoutlineactor->GetProperty()->SetColor(0., 0., 0.);

    // add the actors to the renderer
    //..vtkrenderer->AddViewProp(vtkoutlineactor.GetPointer());

    // Create a text property
    //..vtktextproperty = vtkSmartPointer<vtkTextProperty>::New();
    //..vtktextproperty->SetColor(1, 1, 1);
    //..vtktextproperty->ShadowOn();
    //..vtktextproperty->SetFontSize(20);

    // Create a vtkCubeAxesActor2D.  Use the outer edges of the bounding box to
    // draw the axes.  Add the actor to the renderer.
    //..vtkcubeaxesactor2d = vtkSmartPointer<vtkCubeAxesActor2D>::New();
    //..vtkcubeaxesactor2d->SetInputConnection(vtkdelaunay2d->GetOutputPort());
    //..vtkcubeaxesactor2d->SetCamera(vtkrenderer->GetActiveCamera());
    //..vtkrenderer->ResetCamera();  // REQUIRED !!!
    //..vtkcubeaxesactor2d->SetLabelFormat("%6.4g");
    //..vtkcubeaxesactor2d->SetFlyModeToOuterEdges();
    //vtkcubeaxesactor2d->SetFlyModeToClosestTriad();
    //vtkcubeaxesactor2d->SetFlyModeToNone();
    //..vtkcubeaxesactor2d->SetAxisTitleTextProperty(vtktextproperty.GetPointer());
    //..vtkcubeaxesactor2d->SetAxisLabelTextProperty(vtktextproperty.GetPointer());
    //..vtkcubeaxesactor2d->SetXLabel("background fluid saturation");
    //..vtkcubeaxesactor2d->SetYLabel("background solid concentration");
    switch (requested_rockproperty) {
        case 0: {
            // 0 : "saturated bulk modulus"
            cubeaxesactor2d_str = "saturated bulk modulus (GPa x" + std::to_string(zscale_K) + ")";
            scalarbaractor_str = "K (GPa x" + std::to_string(zscale_K) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 1: {
            // 1 : "effective shear modulus"
            cubeaxesactor2d_str = "effective shear modulus (GPa x" + std::to_string(zscale_mu) + ")";
            scalarbaractor_str = "mu (GPa x" + std::to_string(zscale_mu) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 2: {
            // 2 : "effective density"
            cubeaxesactor2d_str = "effective density (g/cc x" + std::to_string(zscale_rho) + ")";
            scalarbaractor_str = "rho (g/cc x" + std::to_string(zscale_rho) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 3: {
            // 3 : "effective p-wave velocity"
            cubeaxesactor2d_str = "effective p-wave velocity (km/s x" + std::to_string(zscale_pvel) + ")";
            scalarbaractor_str = "Vp (km/s x" + std::to_string(zscale_pvel) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 4: {
            // 4 : "effective s-wave velocity"
            cubeaxesactor2d_str = "effective s-wave velocity (km/s x" + std::to_string(zscale_svel) + ")";
            scalarbaractor_str = "Vs (km/s x" + std::to_string(zscale_svel) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 5: {
            // 5 : "effective Vp/Vs ratio"
            cubeaxesactor2d_str = "effective Vp/Vs ratio (dimensionless x" + std::to_string(zscale_vpvs) + ")";
            scalarbaractor_str = "Vp/Vs (dimensionless x" + std::to_string(zscale_vpvs) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 6: {
            // 6 : "effective Vs/Vp ratio"
            cubeaxesactor2d_str = "effective Vs/Vp ratio (dimensionless x" + std::to_string(zscale_vsvp) + ")";
            scalarbaractor_str = "Vs/Vp (dimensionless x" + std::to_string(zscale_vsvp) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        case 7: {
            // 7 : "effective Poisson's ratio"
            cubeaxesactor2d_str = "effective Poisson's ratio (dimensionless x" + std::to_string(zscale_nu) + ")";
            scalarbaractor_str = "nu (dimensionless x" + std::to_string(zscale_nu) + ")";
            vtkcubeaxesactor2d->SetZLabel(cubeaxesactor2d_str.c_str());
            vtkscalarbaractor->SetTitle(scalarbaractor_str.c_str());
            break;
        }
        default: {
            // something went wrong!!!
            vtkcubeaxesactor2d->SetZLabel("");
            vtkscalarbaractor->SetTitle("");
            break;
        }
    }

    //..vtkrenderer->AddViewProp(vtkcubeaxesactor2d.GetPointer());

    // vtk examples : ScalarBarActor.cxx
    //..vtkscalarbaractor = vtkSmartPointer<vtkScalarBarActor>::New();
    //..vtkscalarbaractor->SetLookupTable(vtkcolorlookuptable);
    //..vtkscalarbaractor->SetTitle("Ksat");
    //..vtkscalarbaractor->SetLabelFormat("%6.4g");
    //..vtkscalarbaractor->SetTitleTextProperty(vtktextproperty.GetPointer());
    //..vtkscalarbaractor->SetLabelTextProperty(vtktextproperty.GetPointer());
    //..vtkscalarbaractor->SetUnconstrainedFontSize(true);
    //..vtkrenderer->AddActor2D(vtkscalarbaractor);

    vtkrenderer->ResetCamera();


}

double MixingLawsView::PrivateCalcKSat(double K_porous_rockframe, double K_mineral_matrix, double K_fluid, double porosity) {
    // (Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440)

    //double K_porous_rockframe = 1.5 * effective_shearmodulus;  // over-simplified assumption
    double tmp_numerator = std::pow(1.0 - (K_porous_rockframe / K_mineral_matrix), 2);
    double tmp_denominator = (porosity / K_fluid) + ((1.0 - porosity) / K_mineral_matrix) - (K_porous_rockframe / std::pow(K_mineral_matrix, 2));

    return K_porous_rockframe + (tmp_numerator / tmp_denominator);
}