#include "mineralvelsview.h"

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


MineralVelsView::MineralVelsView(QWidget *parent) {
    // constructor

    // initialize variables
    mineral_C11 = mpc::data::QuartzC11<double>();
    mineral_C12 = mpc::data::QuartzC12<double>();
    mineral_C13 = mpc::data::QuartzC13<double>();
    mineral_C14 = mpc::data::QuartzC14<double>();
    mineral_C15 = mpc::data::QuartzC15<double>();
    mineral_C16 = mpc::data::QuartzC16<double>();
    mineral_C22 = mpc::data::QuartzC22<double>();
    mineral_C23 = mpc::data::QuartzC23<double>();
    mineral_C24 = mpc::data::QuartzC24<double>();
    mineral_C25 = mpc::data::QuartzC25<double>();
    mineral_C26 = mpc::data::QuartzC26<double>();
    mineral_C33 = mpc::data::QuartzC33<double>();
    mineral_C34 = mpc::data::QuartzC34<double>();
    mineral_C35 = mpc::data::QuartzC35<double>();
    mineral_C36 = mpc::data::QuartzC36<double>();
    mineral_C44 = mpc::data::QuartzC44<double>();
    mineral_C45 = mpc::data::QuartzC45<double>();
    mineral_C46 = mpc::data::QuartzC46<double>();
    mineral_C55 = mpc::data::QuartzC55<double>();
    mineral_C56 = mpc::data::QuartzC56<double>();
    mineral_C66 = mpc::data::QuartzC66<double>();

    // mpc

    // controls widget
    QWidget* controls_widget = new QWidget(this);

    QWidget* mineral_widget = new QWidget(this);
    mineral_label = new QLabel(this);
    mineral_label->setText("mineral");
    mineral_combobox = new QComboBox(this);
    mineral_combobox->addItem(QStringLiteral("Augite"));
    mineral_combobox->addItem(QStringLiteral("Albite"));
    mineral_combobox->addItem(QStringLiteral("Anorthite"));
    mineral_combobox->addItem(QStringLiteral("Labradorite"));
    mineral_combobox->addItem(QStringLiteral("Microcline"));
    mineral_combobox->addItem(QStringLiteral("Oligoclase"));
    mineral_combobox->addItem(QStringLiteral("Coesite"));
    mineral_combobox->addItem(QStringLiteral("Epidote"));
    mineral_combobox->addItem(QStringLiteral("Hornblende"));
    mineral_combobox->addItem(QStringLiteral("Muscovite"));
    mineral_combobox->addItem(QStringLiteral("Gypsum"));
    mineral_combobox->addItem(QStringLiteral("Enstatite"));
    mineral_combobox->addItem(QStringLiteral("Forsterite"));
    mineral_combobox->addItem(QStringLiteral("Fayalite"));
    mineral_combobox->addItem(QStringLiteral("Montecellite"));
    mineral_combobox->addItem(QStringLiteral("Andalusite"));
    mineral_combobox->addItem(QStringLiteral("Silimanite"));
    mineral_combobox->addItem(QStringLiteral("Barite"));
    mineral_combobox->addItem(QStringLiteral("Anhydrite"));
    mineral_combobox->addItem(QStringLiteral("Dolomite"));
    mineral_combobox->addItem(QStringLiteral("Rutile"));
    mineral_combobox->addItem(QStringLiteral("Zircon"));
    mineral_combobox->addItem(QStringLiteral("Corundum"));
    mineral_combobox->addItem(QStringLiteral("Calcite"));
    mineral_combobox->addItem(QStringLiteral("Quartz"));
    mineral_combobox->addItem(QStringLiteral("Tourmaline"));
    mineral_combobox->addItem(QStringLiteral("Beryl"));
    mineral_combobox->addItem(QStringLiteral("Graphite"));
    mineral_combobox->addItem(QStringLiteral("Wusite"));
    mineral_combobox->addItem(QStringLiteral("Manganosite"));
    mineral_combobox->addItem(QStringLiteral("Periclase"));
    mineral_combobox->addItem(QStringLiteral("Magnetite"));
    mineral_combobox->addItem(QStringLiteral("Chromite"));
    mineral_combobox->addItem(QStringLiteral("Spinel"));
    mineral_combobox->addItem(QStringLiteral("Pyrite"));
    mineral_combobox->addItem(QStringLiteral("Galena"));
    mineral_combobox->addItem(QStringLiteral("Sphalerite"));
    mineral_combobox->addItem(QStringLiteral("Fluorite"));
    mineral_combobox->addItem(QStringLiteral("Halite"));
    mineral_combobox->addItem(QStringLiteral("Sylvite"));
    mineral_combobox->setCurrentIndex(24);

    QHBoxLayout* mineral_widget_layout = new QHBoxLayout(this);
    mineral_widget_layout->addWidget(mineral_label);
    mineral_widget_layout->addWidget(mineral_combobox);
    mineral_widget->setLayout(mineral_widget_layout);

    mineral_C11_label = new QLabel(this);
    mineral_C11_label->setText("C11");
    mineral_C11_lineedit = new QLineEdit(this);
    mineral_C11_lineedit->setText(QString::number(mineral_C11));
    mineral_C11_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C11_lineedit->setReadOnly(true);

    mineral_C12_label = new QLabel(this);
    mineral_C12_label->setText("C12");
    mineral_C12_lineedit = new QLineEdit(this);
    mineral_C12_lineedit->setText(QString::number(mineral_C12));
    mineral_C12_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C12_lineedit->setReadOnly(true);

    mineral_C13_label = new QLabel(this);
    mineral_C13_label->setText("C13");
    mineral_C13_lineedit = new QLineEdit(this);
    mineral_C13_lineedit->setText(QString::number(mineral_C13));
    mineral_C13_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C13_lineedit->setReadOnly(true);

    mineral_C14_label = new QLabel(this);
    mineral_C14_label->setText("C14");
    mineral_C14_lineedit = new QLineEdit(this);
    mineral_C14_lineedit->setText(QString::number(mineral_C14));
    mineral_C14_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C14_lineedit->setReadOnly(true);

    mineral_C15_label = new QLabel(this);
    mineral_C15_label->setText("C15");
    mineral_C15_lineedit = new QLineEdit(this);
    mineral_C15_lineedit->setText(QString::number(mineral_C15));
    mineral_C15_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C15_lineedit->setReadOnly(true);

    mineral_C16_label = new QLabel(this);
    mineral_C16_label->setText("C16");
    mineral_C16_lineedit = new QLineEdit(this);
    mineral_C16_lineedit->setText(QString::number(mineral_C16));
    mineral_C16_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C16_lineedit->setReadOnly(true);

    mineral_C22_label = new QLabel(this);
    mineral_C22_label->setText("C22");
    mineral_C22_lineedit = new QLineEdit(this);
    mineral_C22_lineedit->setText(QString::number(mineral_C22));
    mineral_C22_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C22_lineedit->setReadOnly(true);

    mineral_C23_label = new QLabel(this);
    mineral_C23_label->setText("C23");
    mineral_C23_lineedit = new QLineEdit(this);
    mineral_C23_lineedit->setText(QString::number(mineral_C23));
    mineral_C23_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C23_lineedit->setReadOnly(true);

    mineral_C24_label = new QLabel(this);
    mineral_C24_label->setText("C24");
    mineral_C24_lineedit = new QLineEdit(this);
    mineral_C24_lineedit->setText(QString::number(mineral_C24));
    mineral_C24_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C24_lineedit->setReadOnly(true);

    mineral_C25_label = new QLabel(this);
    mineral_C25_label->setText("C25");
    mineral_C25_lineedit = new QLineEdit(this);
    mineral_C25_lineedit->setText(QString::number(mineral_C25));
    mineral_C25_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C25_lineedit->setReadOnly(true);

    mineral_C26_label = new QLabel(this);
    mineral_C26_label->setText("C26");
    mineral_C26_lineedit = new QLineEdit(this);
    mineral_C26_lineedit->setText(QString::number(mineral_C26));
    mineral_C26_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C26_lineedit->setReadOnly(true);

    mineral_C33_label = new QLabel(this);
    mineral_C33_label->setText("C33");
    mineral_C33_lineedit = new QLineEdit(this);
    mineral_C33_lineedit->setText(QString::number(mineral_C33));
    mineral_C33_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C33_lineedit->setReadOnly(true);

    mineral_C34_label = new QLabel(this);
    mineral_C34_label->setText("C34");
    mineral_C34_lineedit = new QLineEdit(this);
    mineral_C34_lineedit->setText(QString::number(mineral_C34));
    mineral_C34_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C34_lineedit->setReadOnly(true);

    mineral_C35_label = new QLabel(this);
    mineral_C35_label->setText("C35");
    mineral_C35_lineedit = new QLineEdit(this);
    mineral_C35_lineedit->setText(QString::number(mineral_C35));
    mineral_C35_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C35_lineedit->setReadOnly(true);

    mineral_C36_label = new QLabel(this);
    mineral_C36_label->setText("C36");
    mineral_C36_lineedit = new QLineEdit(this);
    mineral_C36_lineedit->setText(QString::number(mineral_C36));
    mineral_C36_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C36_lineedit->setReadOnly(true);

    mineral_C44_label = new QLabel(this);
    mineral_C44_label->setText("C44");
    mineral_C44_lineedit = new QLineEdit(this);
    mineral_C44_lineedit->setText(QString::number(mineral_C44));
    mineral_C44_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C44_lineedit->setReadOnly(true);

    mineral_C45_label = new QLabel(this);
    mineral_C45_label->setText("C45");
    mineral_C45_lineedit = new QLineEdit(this);
    mineral_C45_lineedit->setText(QString::number(mineral_C45));
    mineral_C45_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C45_lineedit->setReadOnly(true);

    mineral_C46_label = new QLabel(this);
    mineral_C46_label->setText("C46");
    mineral_C46_lineedit = new QLineEdit(this);
    mineral_C46_lineedit->setText(QString::number(mineral_C46));
    mineral_C46_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C46_lineedit->setReadOnly(true);

    mineral_C55_label = new QLabel(this);
    mineral_C55_label->setText("C55");
    mineral_C55_lineedit = new QLineEdit(this);
    mineral_C55_lineedit->setText(QString::number(mineral_C55));
    mineral_C55_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C55_lineedit->setReadOnly(true);

    mineral_C56_label = new QLabel(this);
    mineral_C56_label->setText("C56");
    mineral_C56_lineedit = new QLineEdit(this);
    mineral_C56_lineedit->setText(QString::number(mineral_C56));
    mineral_C56_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C56_lineedit->setReadOnly(true);

    mineral_C66_label = new QLabel(this);
    mineral_C66_label->setText("C66");
    mineral_C66_lineedit = new QLineEdit(this);
    mineral_C66_lineedit->setText(QString::number(mineral_C66));
    mineral_C66_lineedit->setAlignment(Qt::AlignCenter);
    mineral_C66_lineedit->setReadOnly(true);

    QGroupBox* mineral_stiffness_groupbox = new QGroupBox(this);
    mineral_stiffness_groupbox->setTitle("mineral stiffness tensor components");
    QGridLayout* mineral_stiffness_gridlayout = new QGridLayout(this);
    mineral_stiffness_gridlayout->addWidget(mineral_C11_label,    0, 0);
    mineral_stiffness_gridlayout->addWidget(mineral_C11_lineedit, 0, 1);
    mineral_stiffness_gridlayout->addWidget(mineral_C12_label,    0, 2);
    mineral_stiffness_gridlayout->addWidget(mineral_C12_lineedit, 0, 3);
    mineral_stiffness_gridlayout->addWidget(mineral_C13_label,    0, 4);
    mineral_stiffness_gridlayout->addWidget(mineral_C13_lineedit, 0, 5);
    mineral_stiffness_gridlayout->addWidget(mineral_C14_label,    0, 6);
    mineral_stiffness_gridlayout->addWidget(mineral_C14_lineedit, 0, 7);
    mineral_stiffness_gridlayout->addWidget(mineral_C15_label,    0, 8);
    mineral_stiffness_gridlayout->addWidget(mineral_C15_lineedit, 0, 9);
    mineral_stiffness_gridlayout->addWidget(mineral_C16_label,    0, 10);
    mineral_stiffness_gridlayout->addWidget(mineral_C16_lineedit, 0, 11);
    mineral_stiffness_gridlayout->addWidget(mineral_C22_label,    1, 2);
    mineral_stiffness_gridlayout->addWidget(mineral_C22_lineedit, 1, 3);
    mineral_stiffness_gridlayout->addWidget(mineral_C23_label,    1, 4);
    mineral_stiffness_gridlayout->addWidget(mineral_C23_lineedit, 1, 5);
    mineral_stiffness_gridlayout->addWidget(mineral_C24_label,    1, 6);
    mineral_stiffness_gridlayout->addWidget(mineral_C24_lineedit, 1, 7);
    mineral_stiffness_gridlayout->addWidget(mineral_C25_label,    1, 8);
    mineral_stiffness_gridlayout->addWidget(mineral_C25_lineedit, 1, 9);
    mineral_stiffness_gridlayout->addWidget(mineral_C26_label,    1, 10);
    mineral_stiffness_gridlayout->addWidget(mineral_C26_lineedit, 1, 11);
    mineral_stiffness_gridlayout->addWidget(mineral_C33_label,    2, 4);
    mineral_stiffness_gridlayout->addWidget(mineral_C33_lineedit, 2, 5);
    mineral_stiffness_gridlayout->addWidget(mineral_C34_label,    2, 6);
    mineral_stiffness_gridlayout->addWidget(mineral_C34_lineedit, 2, 7);
    mineral_stiffness_gridlayout->addWidget(mineral_C35_label,    2, 8);
    mineral_stiffness_gridlayout->addWidget(mineral_C35_lineedit, 2, 9);
    mineral_stiffness_gridlayout->addWidget(mineral_C36_label,    2, 10);
    mineral_stiffness_gridlayout->addWidget(mineral_C36_lineedit, 2, 11);
    mineral_stiffness_gridlayout->addWidget(mineral_C44_label,    3, 6);
    mineral_stiffness_gridlayout->addWidget(mineral_C44_lineedit, 3, 7);
    mineral_stiffness_gridlayout->addWidget(mineral_C45_label,    3, 8);
    mineral_stiffness_gridlayout->addWidget(mineral_C45_lineedit, 3, 9);
    mineral_stiffness_gridlayout->addWidget(mineral_C46_label,    3, 10);
    mineral_stiffness_gridlayout->addWidget(mineral_C46_lineedit, 3, 11);
    mineral_stiffness_gridlayout->addWidget(mineral_C55_label,    4, 8);
    mineral_stiffness_gridlayout->addWidget(mineral_C55_lineedit, 4, 9);
    mineral_stiffness_gridlayout->addWidget(mineral_C56_label,    4, 10);
    mineral_stiffness_gridlayout->addWidget(mineral_C56_lineedit, 4, 11);
    mineral_stiffness_gridlayout->addWidget(mineral_C66_label,    5, 10);
    mineral_stiffness_gridlayout->addWidget(mineral_C66_lineedit, 5, 11);
    mineral_stiffness_groupbox->setLayout(mineral_stiffness_gridlayout);

    velocity_surface_combobox = new QComboBox(this);
    velocity_surface_combobox->addItem("phase velocity surface");
    velocity_surface_combobox->addItem("group velocity surface");
    velocity_surface_combobox->addItem("slowness surface");

    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(mineral_widget);
    controls_widget_layout->addWidget(mineral_stiffness_groupbox);
    controls_widget_layout->addWidget(velocity_surface_combobox);
    controls_widget->setLayout(controls_widget_layout);

    // VTK views
    vtknamedcolors = vtkSmartPointer<vtkNamedColors>::New();

    qvtkopenglwidget_vp0 = new QVTKOpenGLWidget(this);
    vtkgenericopenglwindow_vp0 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_vp0->SetRenderWindow(vtkgenericopenglwindow_vp0);
    vtkrenderwindow_vp0 = qvtkopenglwidget_vp0->GetRenderWindow();


//
//    // You can continue to use 'vtkrenderwindow' as a regular vtkRenderWindow
//    // including adding renderers, actors, etc.
//    vtkrenderer = vtkSmartPointer<vtkRenderer>::New();
//    vtkrenderer->GradientBackgroundOn();
//    vtkrenderer->SetBackground(vtknamedcolors->GetColor3d("Black").GetData());
//    vtkrenderer->SetBackground2(vtknamedcolors->GetColor3d("DarkGray").GetData());
//    vtkrenderwindow->AddRenderer(vtkrenderer);
//
//    vtkrenderwindowinteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    vtkrenderwindowinteractor = vtkrenderwindow->GetInteractor();
//
//    vtkpoints = vtkSmartPointer<vtkPoints>::New();
//
//    // Add the grid points to a polydata object
//    vtkinputpolydata = vtkSmartPointer<vtkPolyData>::New();
//    vtkinputpolydata->SetPoints(vtkpoints);
//
//    // normal vector endpoints
//    vtkglyphfilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
//    vtkglyphfilter->SetInputData(vtkinputpolydata);
//    vtkglyphfilter->Update();
//
//    pointsmapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//    pointsmapper->SetInputConnection(vtkglyphfilter->GetOutputPort());
//
//    pointsactor = vtkSmartPointer<vtkActor>::New();
//    pointsactor->SetMapper(pointsmapper);
//    pointsactor->GetProperty()->SetPointSize(3);
//    pointsactor->GetProperty()->SetColor(0.5,0.5,0.5);
//    vtkrenderer->AddActor(pointsactor);
//
//    // Triangulate the grid points
//    vtkdelaunay2d = vtkSmartPointer<vtkDelaunay2D>::New();
//    vtkdelaunay2d->SetInputData(vtkinputpolydata);
//    vtkdelaunay2d->Update();
//    vtkoutputpolydata = vtkdelaunay2d->GetOutput();
//
//    double bounds[6];
//    vtkoutputpolydata->GetBounds(bounds);
//
////    // Find min and max z
////    double minx = bounds[0];
////    double maxx = bounds[1];
////    double miny = bounds[2];
////    double maxy = bounds[3];
////    double minz = bounds[4];
////    double maxz = bounds[5];
//
//    // Create the color map
//    vtkcolorlookuptable = vtkSmartPointer<vtkLookupTable>::New();
////    vtkcolorlookuptable->SetTableRange(minz, maxz);
////    vtkcolorlookuptable->Build();
//
//    // Generate the colors for each point based on the color map
//    vtkcolorchararray = vtkSmartPointer<vtkUnsignedCharArray>::New();
//    vtkcolorchararray->SetNumberOfComponents(3);
//    vtkcolorchararray->SetName("Colors");
//
//    //++std::cout << "There are " << vtkoutputpolydata->GetNumberOfPoints() << " points." << std::endl;
//
////    for(int i = 0; i < vtkoutputpolydata->GetNumberOfPoints(); i++)
////    {
////        double p[3];
////        vtkoutputpolydata->GetPoint(i,p);
////        //std::cout << "point : " << i << ", x : " << p[0] << ", y : " << p[1] << ", z : " << p[2] << std::endl;
////
////        double dcolor[3];
////        vtkcolorlookuptable->GetColor(p[2], dcolor);
////
////        unsigned char color[3];
////        for(unsigned int j = 0; j < 3; j++)
////        {
////            color[j] = static_cast<unsigned char>(255.0 * dcolor[j]);
////        }
////
////        //vtkcolorchararray->InsertNextTupleValue(color);  // VTK version < 7
////        vtkcolorchararray->InsertNextTypedTuple(color);
////    }
//
//    vtkoutputpolydata->GetPointData()->SetScalars(vtkcolorchararray);  // vtkPointData.h
//
//    // Create a mapper and actor
//    vtkpolydatamapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//    vtkpolydatamapper->SetInputData(vtkoutputpolydata);
//
//
//    vtkactor = vtkSmartPointer<vtkActor>::New();
//    vtkactor->SetMapper(vtkpolydatamapper);
//
//    // Add the actor to the scene
//    vtkrenderer->AddActor(vtkactor);
//    // END vtk examples : colored elevation ============================================================================
//
//    // vtk examples : CubeAxesActor2D.cxx
//    // Create a vtkOutlineFilter to draw the bounding box of the data set.
//    // Also create the associated mapper and actor.
//    vtkoutline = vtkSmartPointer<vtkOutlineFilter>::New();
//    vtkoutline->SetInputConnection(vtkdelaunay2d->GetOutputPort());  // requires subclass of vtkAlgorithm
//
//
//    vtkoutlinemapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//    vtkoutlinemapper->SetInputConnection(vtkoutline->GetOutputPort());
//
//    vtkoutlineactor = vtkSmartPointer<vtkActor>::New();
//    vtkoutlineactor->SetMapper(vtkoutlinemapper.GetPointer());
//    vtkoutlineactor->GetProperty()->SetColor(0., 0., 0.);
//
//    // add the actors to the renderer
//    vtkrenderer->AddViewProp(vtkoutlineactor.GetPointer());
//
//    // Create a text property
//    vtktextproperty = vtkSmartPointer<vtkTextProperty>::New();
//    vtktextproperty->SetColor(1, 1, 1);
//    vtktextproperty->ShadowOn();
//    vtktextproperty->SetFontSize(20);
//
//    // Create a vtkCubeAxesActor2D.  Use the outer edges of the bounding box to
//    // draw the axes.  Add the actor to the renderer.
//    vtkcubeaxesactor2d = vtkSmartPointer<vtkCubeAxesActor2D>::New();
//    vtkcubeaxesactor2d->SetInputConnection(vtkdelaunay2d->GetOutputPort());
//    vtkcubeaxesactor2d->SetCamera(vtkrenderer->GetActiveCamera());
//    vtkrenderer->ResetCamera();  // REQUIRED !!!
//    vtkcubeaxesactor2d->SetLabelFormat("%6.4g");
//    vtkcubeaxesactor2d->SetFlyModeToOuterEdges();
//    //vtkcubeaxesactor2d->SetFlyModeToClosestTriad();
//    //vtkcubeaxesactor2d->SetFlyModeToNone();
//    vtkcubeaxesactor2d->SetAxisTitleTextProperty(vtktextproperty.GetPointer());
//    vtkcubeaxesactor2d->SetAxisLabelTextProperty(vtktextproperty.GetPointer());
//    vtkcubeaxesactor2d->SetXLabel("background fluid saturation");
//    vtkcubeaxesactor2d->SetYLabel("background solid concentration");
//    vtkcubeaxesactor2d->SetZLabel("saturated bulk modulus");
//    vtkrenderer->AddViewProp(vtkcubeaxesactor2d.GetPointer());
//
//    // vtk examples : ScalarBarActor.cxx
//    vtkscalarbaractor = vtkSmartPointer<vtkScalarBarActor>::New();
//    vtkscalarbaractor->SetLookupTable(vtkcolorlookuptable);
//    vtkscalarbaractor->SetTitle("Ksat");
//    vtkscalarbaractor->SetLabelFormat("%6.4g");
//    vtkscalarbaractor->SetTitleTextProperty(vtktextproperty.GetPointer());
//    vtkscalarbaractor->SetLabelTextProperty(vtktextproperty.GetPointer());
//    //vtkscalarbaractor->SetHeight(0.7);
//    vtkscalarbaractor->SetUnconstrainedFontSize(true);
//    vtkrenderer->AddActor2D(vtkscalarbaractor);

    qvtkopenglwidget_vs1 = new QVTKOpenGLWidget(this);
    vtkgenericopenglwindow_vs1 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_vs1->SetRenderWindow(vtkgenericopenglwindow_vs1);
    vtkrenderwindow_vs1 = qvtkopenglwidget_vs1->GetRenderWindow();

    //

    qvtkopenglwidget_vs2 = new QVTKOpenGLWidget(this);
    vtkgenericopenglwindow_vs2 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qvtkopenglwidget_vs2->SetRenderWindow(vtkgenericopenglwindow_vs2);
    vtkrenderwindow_vs2 = qvtkopenglwidget_vs2->GetRenderWindow();


    // =================================================================================================================
    QWidget* vtkviews_widget = new QWidget(this);
    QHBoxLayout* vtkviews_widget_layout = new QHBoxLayout(this);
    vtkviews_widget_layout->addWidget(qvtkopenglwidget_vp0);
    vtkviews_widget_layout->addWidget(qvtkopenglwidget_vs1);
    vtkviews_widget_layout->addWidget(qvtkopenglwidget_vs2);
    vtkviews_widget->setLayout(vtkviews_widget_layout);

    // main splitter
    QSplitter* splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(controls_widget);
    //splitter->addWidget(qvtkopenglwidget);
    splitter->addWidget(vtkviews_widget);

    /* === signals/slots === */
    connect(mineral_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnMineralComboBoxChanged(int)));

    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);
}

MineralVelsView::~MineralVelsView() {
    // destructor
}

// slots
void MineralVelsView::OnMineralComboBoxChanged(int i) {
    //
    switch(i) {
        case 0: { // Augite
            mineral_C11 = mpc::data::AugiteC11<double>();
            mineral_C12 = mpc::data::AugiteC12<double>();
            mineral_C13 = mpc::data::AugiteC13<double>();
            mineral_C14 = mpc::data::AugiteC14<double>();
            mineral_C15 = mpc::data::AugiteC15<double>();
            mineral_C16 = mpc::data::AugiteC16<double>();
            mineral_C22 = mpc::data::AugiteC22<double>();
            mineral_C23 = mpc::data::AugiteC23<double>();
            mineral_C24 = mpc::data::AugiteC24<double>();
            mineral_C25 = mpc::data::AugiteC25<double>();
            mineral_C26 = mpc::data::AugiteC26<double>();
            mineral_C33 = mpc::data::AugiteC33<double>();
            mineral_C34 = mpc::data::AugiteC34<double>();
            mineral_C35 = mpc::data::AugiteC35<double>();
            mineral_C36 = mpc::data::AugiteC36<double>();
            mineral_C44 = mpc::data::AugiteC44<double>();
            mineral_C45 = mpc::data::AugiteC45<double>();
            mineral_C46 = mpc::data::AugiteC46<double>();
            mineral_C55 = mpc::data::AugiteC55<double>();
            mineral_C56 = mpc::data::AugiteC56<double>();
            mineral_C66 = mpc::data::AugiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 1: { // Albite
            mineral_C11 = mpc::data::AlbiteC11<double>();
            mineral_C12 = mpc::data::AlbiteC12<double>();
            mineral_C13 = mpc::data::AlbiteC13<double>();
            mineral_C14 = mpc::data::AlbiteC14<double>();
            mineral_C15 = mpc::data::AlbiteC15<double>();
            mineral_C16 = mpc::data::AlbiteC16<double>();
            mineral_C22 = mpc::data::AlbiteC22<double>();
            mineral_C23 = mpc::data::AlbiteC23<double>();
            mineral_C24 = mpc::data::AlbiteC24<double>();
            mineral_C25 = mpc::data::AlbiteC25<double>();
            mineral_C26 = mpc::data::AlbiteC26<double>();
            mineral_C33 = mpc::data::AlbiteC33<double>();
            mineral_C34 = mpc::data::AlbiteC34<double>();
            mineral_C35 = mpc::data::AlbiteC35<double>();
            mineral_C36 = mpc::data::AlbiteC36<double>();
            mineral_C44 = mpc::data::AlbiteC44<double>();
            mineral_C45 = mpc::data::AlbiteC45<double>();
            mineral_C46 = mpc::data::AlbiteC46<double>();
            mineral_C55 = mpc::data::AlbiteC55<double>();
            mineral_C56 = mpc::data::AlbiteC56<double>();
            mineral_C66 = mpc::data::AlbiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 2: { // Anorthite
            mineral_C11 = mpc::data::AnorthiteC11<double>();
            mineral_C12 = mpc::data::AnorthiteC12<double>();
            mineral_C13 = mpc::data::AnorthiteC13<double>();
            mineral_C14 = mpc::data::AnorthiteC14<double>();
            mineral_C15 = mpc::data::AnorthiteC15<double>();
            mineral_C16 = mpc::data::AnorthiteC16<double>();
            mineral_C22 = mpc::data::AnorthiteC22<double>();
            mineral_C23 = mpc::data::AnorthiteC23<double>();
            mineral_C24 = mpc::data::AnorthiteC24<double>();
            mineral_C25 = mpc::data::AnorthiteC25<double>();
            mineral_C26 = mpc::data::AnorthiteC26<double>();
            mineral_C33 = mpc::data::AnorthiteC33<double>();
            mineral_C34 = mpc::data::AnorthiteC34<double>();
            mineral_C35 = mpc::data::AnorthiteC35<double>();
            mineral_C36 = mpc::data::AnorthiteC36<double>();
            mineral_C44 = mpc::data::AnorthiteC44<double>();
            mineral_C45 = mpc::data::AnorthiteC45<double>();
            mineral_C46 = mpc::data::AnorthiteC46<double>();
            mineral_C55 = mpc::data::AnorthiteC55<double>();
            mineral_C56 = mpc::data::AnorthiteC56<double>();
            mineral_C66 = mpc::data::AnorthiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 3: { // Labradorite
            mineral_C11 = mpc::data::LabradoriteC11<double>();
            mineral_C12 = mpc::data::LabradoriteC12<double>();
            mineral_C13 = mpc::data::LabradoriteC13<double>();
            mineral_C14 = mpc::data::LabradoriteC14<double>();
            mineral_C15 = mpc::data::LabradoriteC15<double>();
            mineral_C16 = mpc::data::LabradoriteC16<double>();
            mineral_C22 = mpc::data::LabradoriteC22<double>();
            mineral_C23 = mpc::data::LabradoriteC23<double>();
            mineral_C24 = mpc::data::LabradoriteC24<double>();
            mineral_C25 = mpc::data::LabradoriteC25<double>();
            mineral_C26 = mpc::data::LabradoriteC26<double>();
            mineral_C33 = mpc::data::LabradoriteC33<double>();
            mineral_C34 = mpc::data::LabradoriteC34<double>();
            mineral_C35 = mpc::data::LabradoriteC35<double>();
            mineral_C36 = mpc::data::LabradoriteC36<double>();
            mineral_C44 = mpc::data::LabradoriteC44<double>();
            mineral_C45 = mpc::data::LabradoriteC45<double>();
            mineral_C46 = mpc::data::LabradoriteC46<double>();
            mineral_C55 = mpc::data::LabradoriteC55<double>();
            mineral_C56 = mpc::data::LabradoriteC56<double>();
            mineral_C66 = mpc::data::LabradoriteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 4: { // Microcline
            mineral_C11 = mpc::data::MicroclineC11<double>();
            mineral_C12 = mpc::data::MicroclineC12<double>();
            mineral_C13 = mpc::data::MicroclineC13<double>();
            mineral_C14 = mpc::data::MicroclineC14<double>();
            mineral_C15 = mpc::data::MicroclineC15<double>();
            mineral_C16 = mpc::data::MicroclineC16<double>();
            mineral_C22 = mpc::data::MicroclineC22<double>();
            mineral_C23 = mpc::data::MicroclineC23<double>();
            mineral_C24 = mpc::data::MicroclineC24<double>();
            mineral_C25 = mpc::data::MicroclineC25<double>();
            mineral_C26 = mpc::data::MicroclineC26<double>();
            mineral_C33 = mpc::data::MicroclineC33<double>();
            mineral_C34 = mpc::data::MicroclineC34<double>();
            mineral_C35 = mpc::data::MicroclineC35<double>();
            mineral_C36 = mpc::data::MicroclineC36<double>();
            mineral_C44 = mpc::data::MicroclineC44<double>();
            mineral_C45 = mpc::data::MicroclineC45<double>();
            mineral_C46 = mpc::data::MicroclineC46<double>();
            mineral_C55 = mpc::data::MicroclineC55<double>();
            mineral_C56 = mpc::data::MicroclineC56<double>();
            mineral_C66 = mpc::data::MicroclineC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 5: { // Oligoclase
            mineral_C11 = mpc::data::OligoclaseC11<double>();
            mineral_C12 = mpc::data::OligoclaseC12<double>();
            mineral_C13 = mpc::data::OligoclaseC13<double>();
            mineral_C14 = mpc::data::OligoclaseC14<double>();
            mineral_C15 = mpc::data::OligoclaseC15<double>();
            mineral_C16 = mpc::data::OligoclaseC16<double>();
            mineral_C22 = mpc::data::OligoclaseC22<double>();
            mineral_C23 = mpc::data::OligoclaseC23<double>();
            mineral_C24 = mpc::data::OligoclaseC24<double>();
            mineral_C25 = mpc::data::OligoclaseC25<double>();
            mineral_C26 = mpc::data::OligoclaseC26<double>();
            mineral_C33 = mpc::data::OligoclaseC33<double>();
            mineral_C34 = mpc::data::OligoclaseC34<double>();
            mineral_C35 = mpc::data::OligoclaseC35<double>();
            mineral_C36 = mpc::data::OligoclaseC36<double>();
            mineral_C44 = mpc::data::OligoclaseC44<double>();
            mineral_C45 = mpc::data::OligoclaseC45<double>();
            mineral_C46 = mpc::data::OligoclaseC46<double>();
            mineral_C55 = mpc::data::OligoclaseC55<double>();
            mineral_C56 = mpc::data::OligoclaseC56<double>();
            mineral_C66 = mpc::data::OligoclaseC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 6: { // Coesite
            mineral_C11 = mpc::data::CoesiteC11<double>();
            mineral_C12 = mpc::data::CoesiteC12<double>();
            mineral_C13 = mpc::data::CoesiteC13<double>();
            mineral_C14 = mpc::data::CoesiteC14<double>();
            mineral_C15 = mpc::data::CoesiteC15<double>();
            mineral_C16 = mpc::data::CoesiteC16<double>();
            mineral_C22 = mpc::data::CoesiteC22<double>();
            mineral_C23 = mpc::data::CoesiteC23<double>();
            mineral_C24 = mpc::data::CoesiteC24<double>();
            mineral_C25 = mpc::data::CoesiteC25<double>();
            mineral_C26 = mpc::data::CoesiteC26<double>();
            mineral_C33 = mpc::data::CoesiteC33<double>();
            mineral_C34 = mpc::data::CoesiteC34<double>();
            mineral_C35 = mpc::data::CoesiteC35<double>();
            mineral_C36 = mpc::data::CoesiteC36<double>();
            mineral_C44 = mpc::data::CoesiteC44<double>();
            mineral_C45 = mpc::data::CoesiteC45<double>();
            mineral_C46 = mpc::data::CoesiteC46<double>();
            mineral_C55 = mpc::data::CoesiteC55<double>();
            mineral_C56 = mpc::data::CoesiteC56<double>();
            mineral_C66 = mpc::data::CoesiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 7: { // Epidote
            mineral_C11 = mpc::data::EpidoteC11<double>();
            mineral_C12 = mpc::data::EpidoteC12<double>();
            mineral_C13 = mpc::data::EpidoteC13<double>();
            mineral_C14 = mpc::data::EpidoteC14<double>();
            mineral_C15 = mpc::data::EpidoteC15<double>();
            mineral_C16 = mpc::data::EpidoteC16<double>();
            mineral_C22 = mpc::data::EpidoteC22<double>();
            mineral_C23 = mpc::data::EpidoteC23<double>();
            mineral_C24 = mpc::data::EpidoteC24<double>();
            mineral_C25 = mpc::data::EpidoteC25<double>();
            mineral_C26 = mpc::data::EpidoteC26<double>();
            mineral_C33 = mpc::data::EpidoteC33<double>();
            mineral_C34 = mpc::data::EpidoteC34<double>();
            mineral_C35 = mpc::data::EpidoteC35<double>();
            mineral_C36 = mpc::data::EpidoteC36<double>();
            mineral_C44 = mpc::data::EpidoteC44<double>();
            mineral_C45 = mpc::data::EpidoteC45<double>();
            mineral_C46 = mpc::data::EpidoteC46<double>();
            mineral_C55 = mpc::data::EpidoteC55<double>();
            mineral_C56 = mpc::data::EpidoteC56<double>();
            mineral_C66 = mpc::data::EpidoteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 8: { // Hornblende
            mineral_C11 = mpc::data::HornblendeC11<double>();
            mineral_C12 = mpc::data::HornblendeC12<double>();
            mineral_C13 = mpc::data::HornblendeC13<double>();
            mineral_C14 = mpc::data::HornblendeC14<double>();
            mineral_C15 = mpc::data::HornblendeC15<double>();
            mineral_C16 = mpc::data::HornblendeC16<double>();
            mineral_C22 = mpc::data::HornblendeC22<double>();
            mineral_C23 = mpc::data::HornblendeC23<double>();
            mineral_C24 = mpc::data::HornblendeC24<double>();
            mineral_C25 = mpc::data::HornblendeC25<double>();
            mineral_C26 = mpc::data::HornblendeC26<double>();
            mineral_C33 = mpc::data::HornblendeC33<double>();
            mineral_C34 = mpc::data::HornblendeC34<double>();
            mineral_C35 = mpc::data::HornblendeC35<double>();
            mineral_C36 = mpc::data::HornblendeC36<double>();
            mineral_C44 = mpc::data::HornblendeC44<double>();
            mineral_C45 = mpc::data::HornblendeC45<double>();
            mineral_C46 = mpc::data::HornblendeC46<double>();
            mineral_C55 = mpc::data::HornblendeC55<double>();
            mineral_C56 = mpc::data::HornblendeC56<double>();
            mineral_C66 = mpc::data::HornblendeC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 9: { // Muscovite
            mineral_C11 = mpc::data::MuscoviteC11<double>();
            mineral_C12 = mpc::data::MuscoviteC12<double>();
            mineral_C13 = mpc::data::MuscoviteC13<double>();
            mineral_C14 = mpc::data::MuscoviteC14<double>();
            mineral_C15 = mpc::data::MuscoviteC15<double>();
            mineral_C16 = mpc::data::MuscoviteC16<double>();
            mineral_C22 = mpc::data::MuscoviteC22<double>();
            mineral_C23 = mpc::data::MuscoviteC23<double>();
            mineral_C24 = mpc::data::MuscoviteC24<double>();
            mineral_C25 = mpc::data::MuscoviteC25<double>();
            mineral_C26 = mpc::data::MuscoviteC26<double>();
            mineral_C33 = mpc::data::MuscoviteC33<double>();
            mineral_C34 = mpc::data::MuscoviteC34<double>();
            mineral_C35 = mpc::data::MuscoviteC35<double>();
            mineral_C36 = mpc::data::MuscoviteC36<double>();
            mineral_C44 = mpc::data::MuscoviteC44<double>();
            mineral_C45 = mpc::data::MuscoviteC45<double>();
            mineral_C46 = mpc::data::MuscoviteC46<double>();
            mineral_C55 = mpc::data::MuscoviteC55<double>();
            mineral_C56 = mpc::data::MuscoviteC56<double>();
            mineral_C66 = mpc::data::MuscoviteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 10: { // Gypsum
            mineral_C11 = mpc::data::GypsumC11<double>();
            mineral_C12 = mpc::data::GypsumC12<double>();
            mineral_C13 = mpc::data::GypsumC13<double>();
            mineral_C14 = mpc::data::GypsumC14<double>();
            mineral_C15 = mpc::data::GypsumC15<double>();
            mineral_C16 = mpc::data::GypsumC16<double>();
            mineral_C22 = mpc::data::GypsumC22<double>();
            mineral_C23 = mpc::data::GypsumC23<double>();
            mineral_C24 = mpc::data::GypsumC24<double>();
            mineral_C25 = mpc::data::GypsumC25<double>();
            mineral_C26 = mpc::data::GypsumC26<double>();
            mineral_C33 = mpc::data::GypsumC33<double>();
            mineral_C34 = mpc::data::GypsumC34<double>();
            mineral_C35 = mpc::data::GypsumC35<double>();
            mineral_C36 = mpc::data::GypsumC36<double>();
            mineral_C44 = mpc::data::GypsumC44<double>();
            mineral_C45 = mpc::data::GypsumC45<double>();
            mineral_C46 = mpc::data::GypsumC46<double>();
            mineral_C55 = mpc::data::GypsumC55<double>();
            mineral_C56 = mpc::data::GypsumC56<double>();
            mineral_C66 = mpc::data::GypsumC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 11: { // Enstatite
            mineral_C11 = mpc::data::EnstatiteC11<double>();
            mineral_C12 = mpc::data::EnstatiteC12<double>();
            mineral_C13 = mpc::data::EnstatiteC13<double>();
            mineral_C14 = mpc::data::EnstatiteC14<double>();
            mineral_C15 = mpc::data::EnstatiteC15<double>();
            mineral_C16 = mpc::data::EnstatiteC16<double>();
            mineral_C22 = mpc::data::EnstatiteC22<double>();
            mineral_C23 = mpc::data::EnstatiteC23<double>();
            mineral_C24 = mpc::data::EnstatiteC24<double>();
            mineral_C25 = mpc::data::EnstatiteC25<double>();
            mineral_C26 = mpc::data::EnstatiteC26<double>();
            mineral_C33 = mpc::data::EnstatiteC33<double>();
            mineral_C34 = mpc::data::EnstatiteC34<double>();
            mineral_C35 = mpc::data::EnstatiteC35<double>();
            mineral_C36 = mpc::data::EnstatiteC36<double>();
            mineral_C44 = mpc::data::EnstatiteC44<double>();
            mineral_C45 = mpc::data::EnstatiteC45<double>();
            mineral_C46 = mpc::data::EnstatiteC46<double>();
            mineral_C55 = mpc::data::EnstatiteC55<double>();
            mineral_C56 = mpc::data::EnstatiteC56<double>();
            mineral_C66 = mpc::data::EnstatiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 12: { // Forsterite
            mineral_C11 = mpc::data::ForsteriteC11<double>();
            mineral_C12 = mpc::data::ForsteriteC12<double>();
            mineral_C13 = mpc::data::ForsteriteC13<double>();
            mineral_C14 = mpc::data::ForsteriteC14<double>();
            mineral_C15 = mpc::data::ForsteriteC15<double>();
            mineral_C16 = mpc::data::ForsteriteC16<double>();
            mineral_C22 = mpc::data::ForsteriteC22<double>();
            mineral_C23 = mpc::data::ForsteriteC23<double>();
            mineral_C24 = mpc::data::ForsteriteC24<double>();
            mineral_C25 = mpc::data::ForsteriteC25<double>();
            mineral_C26 = mpc::data::ForsteriteC26<double>();
            mineral_C33 = mpc::data::ForsteriteC33<double>();
            mineral_C34 = mpc::data::ForsteriteC34<double>();
            mineral_C35 = mpc::data::ForsteriteC35<double>();
            mineral_C36 = mpc::data::ForsteriteC36<double>();
            mineral_C44 = mpc::data::ForsteriteC44<double>();
            mineral_C45 = mpc::data::ForsteriteC45<double>();
            mineral_C46 = mpc::data::ForsteriteC46<double>();
            mineral_C55 = mpc::data::ForsteriteC55<double>();
            mineral_C56 = mpc::data::ForsteriteC56<double>();
            mineral_C66 = mpc::data::ForsteriteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 13: { // Fayalite
            mineral_C11 = mpc::data::FayaliteC11<double>();
            mineral_C12 = mpc::data::FayaliteC12<double>();
            mineral_C13 = mpc::data::FayaliteC13<double>();
            mineral_C14 = mpc::data::FayaliteC14<double>();
            mineral_C15 = mpc::data::FayaliteC15<double>();
            mineral_C16 = mpc::data::FayaliteC16<double>();
            mineral_C22 = mpc::data::FayaliteC22<double>();
            mineral_C23 = mpc::data::FayaliteC23<double>();
            mineral_C24 = mpc::data::FayaliteC24<double>();
            mineral_C25 = mpc::data::FayaliteC25<double>();
            mineral_C26 = mpc::data::FayaliteC26<double>();
            mineral_C33 = mpc::data::FayaliteC33<double>();
            mineral_C34 = mpc::data::FayaliteC34<double>();
            mineral_C35 = mpc::data::FayaliteC35<double>();
            mineral_C36 = mpc::data::FayaliteC36<double>();
            mineral_C44 = mpc::data::FayaliteC44<double>();
            mineral_C45 = mpc::data::FayaliteC45<double>();
            mineral_C46 = mpc::data::FayaliteC46<double>();
            mineral_C55 = mpc::data::FayaliteC55<double>();
            mineral_C56 = mpc::data::FayaliteC56<double>();
            mineral_C66 = mpc::data::FayaliteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 14: { // Montecellite
            mineral_C11 = mpc::data::MontecelliteC11<double>();
            mineral_C12 = mpc::data::MontecelliteC12<double>();
            mineral_C13 = mpc::data::MontecelliteC13<double>();
            mineral_C14 = mpc::data::MontecelliteC14<double>();
            mineral_C15 = mpc::data::MontecelliteC15<double>();
            mineral_C16 = mpc::data::MontecelliteC16<double>();
            mineral_C22 = mpc::data::MontecelliteC22<double>();
            mineral_C23 = mpc::data::MontecelliteC23<double>();
            mineral_C24 = mpc::data::MontecelliteC24<double>();
            mineral_C25 = mpc::data::MontecelliteC25<double>();
            mineral_C26 = mpc::data::MontecelliteC26<double>();
            mineral_C33 = mpc::data::MontecelliteC33<double>();
            mineral_C34 = mpc::data::MontecelliteC34<double>();
            mineral_C35 = mpc::data::MontecelliteC35<double>();
            mineral_C36 = mpc::data::MontecelliteC36<double>();
            mineral_C44 = mpc::data::MontecelliteC44<double>();
            mineral_C45 = mpc::data::MontecelliteC45<double>();
            mineral_C46 = mpc::data::MontecelliteC46<double>();
            mineral_C55 = mpc::data::MontecelliteC55<double>();
            mineral_C56 = mpc::data::MontecelliteC56<double>();
            mineral_C66 = mpc::data::MontecelliteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 15: { // Andalusite
            mineral_C11 = mpc::data::AndalusiteC11<double>();
            mineral_C12 = mpc::data::AndalusiteC12<double>();
            mineral_C13 = mpc::data::AndalusiteC13<double>();
            mineral_C14 = mpc::data::AndalusiteC14<double>();
            mineral_C15 = mpc::data::AndalusiteC15<double>();
            mineral_C16 = mpc::data::AndalusiteC16<double>();
            mineral_C22 = mpc::data::AndalusiteC22<double>();
            mineral_C23 = mpc::data::AndalusiteC23<double>();
            mineral_C24 = mpc::data::AndalusiteC24<double>();
            mineral_C25 = mpc::data::AndalusiteC25<double>();
            mineral_C26 = mpc::data::AndalusiteC26<double>();
            mineral_C33 = mpc::data::AndalusiteC33<double>();
            mineral_C34 = mpc::data::AndalusiteC34<double>();
            mineral_C35 = mpc::data::AndalusiteC35<double>();
            mineral_C36 = mpc::data::AndalusiteC36<double>();
            mineral_C44 = mpc::data::AndalusiteC44<double>();
            mineral_C45 = mpc::data::AndalusiteC45<double>();
            mineral_C46 = mpc::data::AndalusiteC46<double>();
            mineral_C55 = mpc::data::AndalusiteC55<double>();
            mineral_C56 = mpc::data::AndalusiteC56<double>();
            mineral_C66 = mpc::data::AndalusiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 16: { // Silimanite
            mineral_C11 = mpc::data::SilimaniteC11<double>();
            mineral_C12 = mpc::data::SilimaniteC12<double>();
            mineral_C13 = mpc::data::SilimaniteC13<double>();
            mineral_C14 = mpc::data::SilimaniteC14<double>();
            mineral_C15 = mpc::data::SilimaniteC15<double>();
            mineral_C16 = mpc::data::SilimaniteC16<double>();
            mineral_C22 = mpc::data::SilimaniteC22<double>();
            mineral_C23 = mpc::data::SilimaniteC23<double>();
            mineral_C24 = mpc::data::SilimaniteC24<double>();
            mineral_C25 = mpc::data::SilimaniteC25<double>();
            mineral_C26 = mpc::data::SilimaniteC26<double>();
            mineral_C33 = mpc::data::SilimaniteC33<double>();
            mineral_C34 = mpc::data::SilimaniteC34<double>();
            mineral_C35 = mpc::data::SilimaniteC35<double>();
            mineral_C36 = mpc::data::SilimaniteC36<double>();
            mineral_C44 = mpc::data::SilimaniteC44<double>();
            mineral_C45 = mpc::data::SilimaniteC45<double>();
            mineral_C46 = mpc::data::SilimaniteC46<double>();
            mineral_C55 = mpc::data::SilimaniteC55<double>();
            mineral_C56 = mpc::data::SilimaniteC56<double>();
            mineral_C66 = mpc::data::SilimaniteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 17: { // Barite
            mineral_C11 = mpc::data::BariteC11<double>();
            mineral_C12 = mpc::data::BariteC12<double>();
            mineral_C13 = mpc::data::BariteC13<double>();
            mineral_C14 = mpc::data::BariteC14<double>();
            mineral_C15 = mpc::data::BariteC15<double>();
            mineral_C16 = mpc::data::BariteC16<double>();
            mineral_C22 = mpc::data::BariteC22<double>();
            mineral_C23 = mpc::data::BariteC23<double>();
            mineral_C24 = mpc::data::BariteC24<double>();
            mineral_C25 = mpc::data::BariteC25<double>();
            mineral_C26 = mpc::data::BariteC26<double>();
            mineral_C33 = mpc::data::BariteC33<double>();
            mineral_C34 = mpc::data::BariteC34<double>();
            mineral_C35 = mpc::data::BariteC35<double>();
            mineral_C36 = mpc::data::BariteC36<double>();
            mineral_C44 = mpc::data::BariteC44<double>();
            mineral_C45 = mpc::data::BariteC45<double>();
            mineral_C46 = mpc::data::BariteC46<double>();
            mineral_C55 = mpc::data::BariteC55<double>();
            mineral_C56 = mpc::data::BariteC56<double>();
            mineral_C66 = mpc::data::BariteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 18: { // Anhydrite
            mineral_C11 = mpc::data::AnhydriteC11<double>();
            mineral_C12 = mpc::data::AnhydriteC12<double>();
            mineral_C13 = mpc::data::AnhydriteC13<double>();
            mineral_C14 = mpc::data::AnhydriteC14<double>();
            mineral_C15 = mpc::data::AnhydriteC15<double>();
            mineral_C16 = mpc::data::AnhydriteC16<double>();
            mineral_C22 = mpc::data::AnhydriteC22<double>();
            mineral_C23 = mpc::data::AnhydriteC23<double>();
            mineral_C24 = mpc::data::AnhydriteC24<double>();
            mineral_C25 = mpc::data::AnhydriteC25<double>();
            mineral_C26 = mpc::data::AnhydriteC26<double>();
            mineral_C33 = mpc::data::AnhydriteC33<double>();
            mineral_C34 = mpc::data::AnhydriteC34<double>();
            mineral_C35 = mpc::data::AnhydriteC35<double>();
            mineral_C36 = mpc::data::AnhydriteC36<double>();
            mineral_C44 = mpc::data::AnhydriteC44<double>();
            mineral_C45 = mpc::data::AnhydriteC45<double>();
            mineral_C46 = mpc::data::AnhydriteC46<double>();
            mineral_C55 = mpc::data::AnhydriteC55<double>();
            mineral_C56 = mpc::data::AnhydriteC56<double>();
            mineral_C66 = mpc::data::AnhydriteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 19: { // Dolomite
            mineral_C11 = mpc::data::DolomiteC11<double>();
            mineral_C12 = mpc::data::DolomiteC12<double>();
            mineral_C13 = mpc::data::DolomiteC13<double>();
            mineral_C14 = mpc::data::DolomiteC14<double>();
            mineral_C15 = mpc::data::DolomiteC15<double>();
            mineral_C16 = mpc::data::DolomiteC16<double>();
            mineral_C22 = mpc::data::DolomiteC22<double>();
            mineral_C23 = mpc::data::DolomiteC23<double>();
            mineral_C24 = mpc::data::DolomiteC24<double>();
            mineral_C25 = mpc::data::DolomiteC25<double>();
            mineral_C26 = mpc::data::DolomiteC26<double>();
            mineral_C33 = mpc::data::DolomiteC33<double>();
            mineral_C34 = mpc::data::DolomiteC34<double>();
            mineral_C35 = mpc::data::DolomiteC35<double>();
            mineral_C36 = mpc::data::DolomiteC36<double>();
            mineral_C44 = mpc::data::DolomiteC44<double>();
            mineral_C45 = mpc::data::DolomiteC45<double>();
            mineral_C46 = mpc::data::DolomiteC46<double>();
            mineral_C55 = mpc::data::DolomiteC55<double>();
            mineral_C56 = mpc::data::DolomiteC56<double>();
            mineral_C66 = mpc::data::DolomiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 20: { // Rutile
            mineral_C11 = mpc::data::RutileC11<double>();
            mineral_C12 = mpc::data::RutileC12<double>();
            mineral_C13 = mpc::data::RutileC13<double>();
            mineral_C14 = mpc::data::RutileC14<double>();
            mineral_C15 = mpc::data::RutileC15<double>();
            mineral_C16 = mpc::data::RutileC16<double>();
            mineral_C22 = mpc::data::RutileC22<double>();
            mineral_C23 = mpc::data::RutileC23<double>();
            mineral_C24 = mpc::data::RutileC24<double>();
            mineral_C25 = mpc::data::RutileC25<double>();
            mineral_C26 = mpc::data::RutileC26<double>();
            mineral_C33 = mpc::data::RutileC33<double>();
            mineral_C34 = mpc::data::RutileC34<double>();
            mineral_C35 = mpc::data::RutileC35<double>();
            mineral_C36 = mpc::data::RutileC36<double>();
            mineral_C44 = mpc::data::RutileC44<double>();
            mineral_C45 = mpc::data::RutileC45<double>();
            mineral_C46 = mpc::data::RutileC46<double>();
            mineral_C55 = mpc::data::RutileC55<double>();
            mineral_C56 = mpc::data::RutileC56<double>();
            mineral_C66 = mpc::data::RutileC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 21: { // Zircon
            mineral_C11 = mpc::data::ZirconC11<double>();
            mineral_C12 = mpc::data::ZirconC12<double>();
            mineral_C13 = mpc::data::ZirconC13<double>();
            mineral_C14 = mpc::data::ZirconC14<double>();
            mineral_C15 = mpc::data::ZirconC15<double>();
            mineral_C16 = mpc::data::ZirconC16<double>();
            mineral_C22 = mpc::data::ZirconC22<double>();
            mineral_C23 = mpc::data::ZirconC23<double>();
            mineral_C24 = mpc::data::ZirconC24<double>();
            mineral_C25 = mpc::data::ZirconC25<double>();
            mineral_C26 = mpc::data::ZirconC26<double>();
            mineral_C33 = mpc::data::ZirconC33<double>();
            mineral_C34 = mpc::data::ZirconC34<double>();
            mineral_C35 = mpc::data::ZirconC35<double>();
            mineral_C36 = mpc::data::ZirconC36<double>();
            mineral_C44 = mpc::data::ZirconC44<double>();
            mineral_C45 = mpc::data::ZirconC45<double>();
            mineral_C46 = mpc::data::ZirconC46<double>();
            mineral_C55 = mpc::data::ZirconC55<double>();
            mineral_C56 = mpc::data::ZirconC56<double>();
            mineral_C66 = mpc::data::ZirconC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 22: { // Corundum
            mineral_C11 = mpc::data::CorundumC11<double>();
            mineral_C12 = mpc::data::CorundumC12<double>();
            mineral_C13 = mpc::data::CorundumC13<double>();
            mineral_C14 = mpc::data::CorundumC14<double>();
            mineral_C15 = mpc::data::CorundumC15<double>();
            mineral_C16 = mpc::data::CorundumC16<double>();
            mineral_C22 = mpc::data::CorundumC22<double>();
            mineral_C23 = mpc::data::CorundumC23<double>();
            mineral_C24 = mpc::data::CorundumC24<double>();
            mineral_C25 = mpc::data::CorundumC25<double>();
            mineral_C26 = mpc::data::CorundumC26<double>();
            mineral_C33 = mpc::data::CorundumC33<double>();
            mineral_C34 = mpc::data::CorundumC34<double>();
            mineral_C35 = mpc::data::CorundumC35<double>();
            mineral_C36 = mpc::data::CorundumC36<double>();
            mineral_C44 = mpc::data::CorundumC44<double>();
            mineral_C45 = mpc::data::CorundumC45<double>();
            mineral_C46 = mpc::data::CorundumC46<double>();
            mineral_C55 = mpc::data::CorundumC55<double>();
            mineral_C56 = mpc::data::CorundumC56<double>();
            mineral_C66 = mpc::data::CorundumC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 23: { // Calcite
            mineral_C11 = mpc::data::CalciteC11<double>();
            mineral_C12 = mpc::data::CalciteC12<double>();
            mineral_C13 = mpc::data::CalciteC13<double>();
            mineral_C14 = mpc::data::CalciteC14<double>();
            mineral_C15 = mpc::data::CalciteC15<double>();
            mineral_C16 = mpc::data::CalciteC16<double>();
            mineral_C22 = mpc::data::CalciteC22<double>();
            mineral_C23 = mpc::data::CalciteC23<double>();
            mineral_C24 = mpc::data::CalciteC24<double>();
            mineral_C25 = mpc::data::CalciteC25<double>();
            mineral_C26 = mpc::data::CalciteC26<double>();
            mineral_C33 = mpc::data::CalciteC33<double>();
            mineral_C34 = mpc::data::CalciteC34<double>();
            mineral_C35 = mpc::data::CalciteC35<double>();
            mineral_C36 = mpc::data::CalciteC36<double>();
            mineral_C44 = mpc::data::CalciteC44<double>();
            mineral_C45 = mpc::data::CalciteC45<double>();
            mineral_C46 = mpc::data::CalciteC46<double>();
            mineral_C55 = mpc::data::CalciteC55<double>();
            mineral_C56 = mpc::data::CalciteC56<double>();
            mineral_C66 = mpc::data::CalciteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 24: { // Quartz
            mineral_C11 = mpc::data::QuartzC11<double>();
            mineral_C12 = mpc::data::QuartzC12<double>();
            mineral_C13 = mpc::data::QuartzC13<double>();
            mineral_C14 = mpc::data::QuartzC14<double>();
            mineral_C15 = mpc::data::QuartzC15<double>();
            mineral_C16 = mpc::data::QuartzC16<double>();
            mineral_C22 = mpc::data::QuartzC22<double>();
            mineral_C23 = mpc::data::QuartzC23<double>();
            mineral_C24 = mpc::data::QuartzC24<double>();
            mineral_C25 = mpc::data::QuartzC25<double>();
            mineral_C26 = mpc::data::QuartzC26<double>();
            mineral_C33 = mpc::data::QuartzC33<double>();
            mineral_C34 = mpc::data::QuartzC34<double>();
            mineral_C35 = mpc::data::QuartzC35<double>();
            mineral_C36 = mpc::data::QuartzC36<double>();
            mineral_C44 = mpc::data::QuartzC44<double>();
            mineral_C45 = mpc::data::QuartzC45<double>();
            mineral_C46 = mpc::data::QuartzC46<double>();
            mineral_C55 = mpc::data::QuartzC55<double>();
            mineral_C56 = mpc::data::QuartzC56<double>();
            mineral_C66 = mpc::data::QuartzC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 25: { // Tourmaline
            mineral_C11 = mpc::data::TourmalineC11<double>();
            mineral_C12 = mpc::data::TourmalineC12<double>();
            mineral_C13 = mpc::data::TourmalineC13<double>();
            mineral_C14 = mpc::data::TourmalineC14<double>();
            mineral_C15 = mpc::data::TourmalineC15<double>();
            mineral_C16 = mpc::data::TourmalineC16<double>();
            mineral_C22 = mpc::data::TourmalineC22<double>();
            mineral_C23 = mpc::data::TourmalineC23<double>();
            mineral_C24 = mpc::data::TourmalineC24<double>();
            mineral_C25 = mpc::data::TourmalineC25<double>();
            mineral_C26 = mpc::data::TourmalineC26<double>();
            mineral_C33 = mpc::data::TourmalineC33<double>();
            mineral_C34 = mpc::data::TourmalineC34<double>();
            mineral_C35 = mpc::data::TourmalineC35<double>();
            mineral_C36 = mpc::data::TourmalineC36<double>();
            mineral_C44 = mpc::data::TourmalineC44<double>();
            mineral_C45 = mpc::data::TourmalineC45<double>();
            mineral_C46 = mpc::data::TourmalineC46<double>();
            mineral_C55 = mpc::data::TourmalineC55<double>();
            mineral_C56 = mpc::data::TourmalineC56<double>();
            mineral_C66 = mpc::data::TourmalineC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 26: { // Beryl
            mineral_C11 = mpc::data::BerylC11<double>();
            mineral_C12 = mpc::data::BerylC12<double>();
            mineral_C13 = mpc::data::BerylC13<double>();
            mineral_C14 = mpc::data::BerylC14<double>();
            mineral_C15 = mpc::data::BerylC15<double>();
            mineral_C16 = mpc::data::BerylC16<double>();
            mineral_C22 = mpc::data::BerylC22<double>();
            mineral_C23 = mpc::data::BerylC23<double>();
            mineral_C24 = mpc::data::BerylC24<double>();
            mineral_C25 = mpc::data::BerylC25<double>();
            mineral_C26 = mpc::data::BerylC26<double>();
            mineral_C33 = mpc::data::BerylC33<double>();
            mineral_C34 = mpc::data::BerylC34<double>();
            mineral_C35 = mpc::data::BerylC35<double>();
            mineral_C36 = mpc::data::BerylC36<double>();
            mineral_C44 = mpc::data::BerylC44<double>();
            mineral_C45 = mpc::data::BerylC45<double>();
            mineral_C46 = mpc::data::BerylC46<double>();
            mineral_C55 = mpc::data::BerylC55<double>();
            mineral_C56 = mpc::data::BerylC56<double>();
            mineral_C66 = mpc::data::BerylC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 27: { // Graphite
            mineral_C11 = mpc::data::GraphiteC11<double>();
            mineral_C12 = mpc::data::GraphiteC12<double>();
            mineral_C13 = mpc::data::GraphiteC13<double>();
            mineral_C14 = mpc::data::GraphiteC14<double>();
            mineral_C15 = mpc::data::GraphiteC15<double>();
            mineral_C16 = mpc::data::GraphiteC16<double>();
            mineral_C22 = mpc::data::GraphiteC22<double>();
            mineral_C23 = mpc::data::GraphiteC23<double>();
            mineral_C24 = mpc::data::GraphiteC24<double>();
            mineral_C25 = mpc::data::GraphiteC25<double>();
            mineral_C26 = mpc::data::GraphiteC26<double>();
            mineral_C33 = mpc::data::GraphiteC33<double>();
            mineral_C34 = mpc::data::GraphiteC34<double>();
            mineral_C35 = mpc::data::GraphiteC35<double>();
            mineral_C36 = mpc::data::GraphiteC36<double>();
            mineral_C44 = mpc::data::GraphiteC44<double>();
            mineral_C45 = mpc::data::GraphiteC45<double>();
            mineral_C46 = mpc::data::GraphiteC46<double>();
            mineral_C55 = mpc::data::GraphiteC55<double>();
            mineral_C56 = mpc::data::GraphiteC56<double>();
            mineral_C66 = mpc::data::GraphiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 28: { // Wusite
            mineral_C11 = mpc::data::WusiteC11<double>();
            mineral_C12 = mpc::data::WusiteC12<double>();
            mineral_C13 = mpc::data::WusiteC13<double>();
            mineral_C14 = mpc::data::WusiteC14<double>();
            mineral_C15 = mpc::data::WusiteC15<double>();
            mineral_C16 = mpc::data::WusiteC16<double>();
            mineral_C22 = mpc::data::WusiteC22<double>();
            mineral_C23 = mpc::data::WusiteC23<double>();
            mineral_C24 = mpc::data::WusiteC24<double>();
            mineral_C25 = mpc::data::WusiteC25<double>();
            mineral_C26 = mpc::data::WusiteC26<double>();
            mineral_C33 = mpc::data::WusiteC33<double>();
            mineral_C34 = mpc::data::WusiteC34<double>();
            mineral_C35 = mpc::data::WusiteC35<double>();
            mineral_C36 = mpc::data::WusiteC36<double>();
            mineral_C44 = mpc::data::WusiteC44<double>();
            mineral_C45 = mpc::data::WusiteC45<double>();
            mineral_C46 = mpc::data::WusiteC46<double>();
            mineral_C55 = mpc::data::WusiteC55<double>();
            mineral_C56 = mpc::data::WusiteC56<double>();
            mineral_C66 = mpc::data::WusiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 29: { // Manganosite
            mineral_C11 = mpc::data::ManganositeC11<double>();
            mineral_C12 = mpc::data::ManganositeC12<double>();
            mineral_C13 = mpc::data::ManganositeC13<double>();
            mineral_C14 = mpc::data::ManganositeC14<double>();
            mineral_C15 = mpc::data::ManganositeC15<double>();
            mineral_C16 = mpc::data::ManganositeC16<double>();
            mineral_C22 = mpc::data::ManganositeC22<double>();
            mineral_C23 = mpc::data::ManganositeC23<double>();
            mineral_C24 = mpc::data::ManganositeC24<double>();
            mineral_C25 = mpc::data::ManganositeC25<double>();
            mineral_C26 = mpc::data::ManganositeC26<double>();
            mineral_C33 = mpc::data::ManganositeC33<double>();
            mineral_C34 = mpc::data::ManganositeC34<double>();
            mineral_C35 = mpc::data::ManganositeC35<double>();
            mineral_C36 = mpc::data::ManganositeC36<double>();
            mineral_C44 = mpc::data::ManganositeC44<double>();
            mineral_C45 = mpc::data::ManganositeC45<double>();
            mineral_C46 = mpc::data::ManganositeC46<double>();
            mineral_C55 = mpc::data::ManganositeC55<double>();
            mineral_C56 = mpc::data::ManganositeC56<double>();
            mineral_C66 = mpc::data::ManganositeC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 30: { // Periclase
            mineral_C11 = mpc::data::PericlaseC11<double>();
            mineral_C12 = mpc::data::PericlaseC12<double>();
            mineral_C13 = mpc::data::PericlaseC13<double>();
            mineral_C14 = mpc::data::PericlaseC14<double>();
            mineral_C15 = mpc::data::PericlaseC15<double>();
            mineral_C16 = mpc::data::PericlaseC16<double>();
            mineral_C22 = mpc::data::PericlaseC22<double>();
            mineral_C23 = mpc::data::PericlaseC23<double>();
            mineral_C24 = mpc::data::PericlaseC24<double>();
            mineral_C25 = mpc::data::PericlaseC25<double>();
            mineral_C26 = mpc::data::PericlaseC26<double>();
            mineral_C33 = mpc::data::PericlaseC33<double>();
            mineral_C34 = mpc::data::PericlaseC34<double>();
            mineral_C35 = mpc::data::PericlaseC35<double>();
            mineral_C36 = mpc::data::PericlaseC36<double>();
            mineral_C44 = mpc::data::PericlaseC44<double>();
            mineral_C45 = mpc::data::PericlaseC45<double>();
            mineral_C46 = mpc::data::PericlaseC46<double>();
            mineral_C55 = mpc::data::PericlaseC55<double>();
            mineral_C56 = mpc::data::PericlaseC56<double>();
            mineral_C66 = mpc::data::PericlaseC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 31: { // Magnetite
            mineral_C11 = mpc::data::MagnetiteC11<double>();
            mineral_C12 = mpc::data::MagnetiteC12<double>();
            mineral_C13 = mpc::data::MagnetiteC13<double>();
            mineral_C14 = mpc::data::MagnetiteC14<double>();
            mineral_C15 = mpc::data::MagnetiteC15<double>();
            mineral_C16 = mpc::data::MagnetiteC16<double>();
            mineral_C22 = mpc::data::MagnetiteC22<double>();
            mineral_C23 = mpc::data::MagnetiteC23<double>();
            mineral_C24 = mpc::data::MagnetiteC24<double>();
            mineral_C25 = mpc::data::MagnetiteC25<double>();
            mineral_C26 = mpc::data::MagnetiteC26<double>();
            mineral_C33 = mpc::data::MagnetiteC33<double>();
            mineral_C34 = mpc::data::MagnetiteC34<double>();
            mineral_C35 = mpc::data::MagnetiteC35<double>();
            mineral_C36 = mpc::data::MagnetiteC36<double>();
            mineral_C44 = mpc::data::MagnetiteC44<double>();
            mineral_C45 = mpc::data::MagnetiteC45<double>();
            mineral_C46 = mpc::data::MagnetiteC46<double>();
            mineral_C55 = mpc::data::MagnetiteC55<double>();
            mineral_C56 = mpc::data::MagnetiteC56<double>();
            mineral_C66 = mpc::data::MagnetiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 32: { // Chromite
            mineral_C11 = mpc::data::ChromiteC11<double>();
            mineral_C12 = mpc::data::ChromiteC12<double>();
            mineral_C13 = mpc::data::ChromiteC13<double>();
            mineral_C14 = mpc::data::ChromiteC14<double>();
            mineral_C15 = mpc::data::ChromiteC15<double>();
            mineral_C16 = mpc::data::ChromiteC16<double>();
            mineral_C22 = mpc::data::ChromiteC22<double>();
            mineral_C23 = mpc::data::ChromiteC23<double>();
            mineral_C24 = mpc::data::ChromiteC24<double>();
            mineral_C25 = mpc::data::ChromiteC25<double>();
            mineral_C26 = mpc::data::ChromiteC26<double>();
            mineral_C33 = mpc::data::ChromiteC33<double>();
            mineral_C34 = mpc::data::ChromiteC34<double>();
            mineral_C35 = mpc::data::ChromiteC35<double>();
            mineral_C36 = mpc::data::ChromiteC36<double>();
            mineral_C44 = mpc::data::ChromiteC44<double>();
            mineral_C45 = mpc::data::ChromiteC45<double>();
            mineral_C46 = mpc::data::ChromiteC46<double>();
            mineral_C55 = mpc::data::ChromiteC55<double>();
            mineral_C56 = mpc::data::ChromiteC56<double>();
            mineral_C66 = mpc::data::ChromiteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 33: { // Spinel
            mineral_C11 = mpc::data::SpinelC11<double>();
            mineral_C12 = mpc::data::SpinelC12<double>();
            mineral_C13 = mpc::data::SpinelC13<double>();
            mineral_C14 = mpc::data::SpinelC14<double>();
            mineral_C15 = mpc::data::SpinelC15<double>();
            mineral_C16 = mpc::data::SpinelC16<double>();
            mineral_C22 = mpc::data::SpinelC22<double>();
            mineral_C23 = mpc::data::SpinelC23<double>();
            mineral_C24 = mpc::data::SpinelC24<double>();
            mineral_C25 = mpc::data::SpinelC25<double>();
            mineral_C26 = mpc::data::SpinelC26<double>();
            mineral_C33 = mpc::data::SpinelC33<double>();
            mineral_C34 = mpc::data::SpinelC34<double>();
            mineral_C35 = mpc::data::SpinelC35<double>();
            mineral_C36 = mpc::data::SpinelC36<double>();
            mineral_C44 = mpc::data::SpinelC44<double>();
            mineral_C45 = mpc::data::SpinelC45<double>();
            mineral_C46 = mpc::data::SpinelC46<double>();
            mineral_C55 = mpc::data::SpinelC55<double>();
            mineral_C56 = mpc::data::SpinelC56<double>();
            mineral_C66 = mpc::data::SpinelC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 34: { // Pyrite
            mineral_C11 = mpc::data::PyriteC11<double>();
            mineral_C12 = mpc::data::PyriteC12<double>();
            mineral_C13 = mpc::data::PyriteC13<double>();
            mineral_C14 = mpc::data::PyriteC14<double>();
            mineral_C15 = mpc::data::PyriteC15<double>();
            mineral_C16 = mpc::data::PyriteC16<double>();
            mineral_C22 = mpc::data::PyriteC22<double>();
            mineral_C23 = mpc::data::PyriteC23<double>();
            mineral_C24 = mpc::data::PyriteC24<double>();
            mineral_C25 = mpc::data::PyriteC25<double>();
            mineral_C26 = mpc::data::PyriteC26<double>();
            mineral_C33 = mpc::data::PyriteC33<double>();
            mineral_C34 = mpc::data::PyriteC34<double>();
            mineral_C35 = mpc::data::PyriteC35<double>();
            mineral_C36 = mpc::data::PyriteC36<double>();
            mineral_C44 = mpc::data::PyriteC44<double>();
            mineral_C45 = mpc::data::PyriteC45<double>();
            mineral_C46 = mpc::data::PyriteC46<double>();
            mineral_C55 = mpc::data::PyriteC55<double>();
            mineral_C56 = mpc::data::PyriteC56<double>();
            mineral_C66 = mpc::data::PyriteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 35: { // Galena
            mineral_C11 = mpc::data::GalenaC11<double>();
            mineral_C12 = mpc::data::GalenaC12<double>();
            mineral_C13 = mpc::data::GalenaC13<double>();
            mineral_C14 = mpc::data::GalenaC14<double>();
            mineral_C15 = mpc::data::GalenaC15<double>();
            mineral_C16 = mpc::data::GalenaC16<double>();
            mineral_C22 = mpc::data::GalenaC22<double>();
            mineral_C23 = mpc::data::GalenaC23<double>();
            mineral_C24 = mpc::data::GalenaC24<double>();
            mineral_C25 = mpc::data::GalenaC25<double>();
            mineral_C26 = mpc::data::GalenaC26<double>();
            mineral_C33 = mpc::data::GalenaC33<double>();
            mineral_C34 = mpc::data::GalenaC34<double>();
            mineral_C35 = mpc::data::GalenaC35<double>();
            mineral_C36 = mpc::data::GalenaC36<double>();
            mineral_C44 = mpc::data::GalenaC44<double>();
            mineral_C45 = mpc::data::GalenaC45<double>();
            mineral_C46 = mpc::data::GalenaC46<double>();
            mineral_C55 = mpc::data::GalenaC55<double>();
            mineral_C56 = mpc::data::GalenaC56<double>();
            mineral_C66 = mpc::data::GalenaC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 36: { // Sphalerite
            mineral_C11 = mpc::data::SphaleriteC11<double>();
            mineral_C12 = mpc::data::SphaleriteC12<double>();
            mineral_C13 = mpc::data::SphaleriteC13<double>();
            mineral_C14 = mpc::data::SphaleriteC14<double>();
            mineral_C15 = mpc::data::SphaleriteC15<double>();
            mineral_C16 = mpc::data::SphaleriteC16<double>();
            mineral_C22 = mpc::data::SphaleriteC22<double>();
            mineral_C23 = mpc::data::SphaleriteC23<double>();
            mineral_C24 = mpc::data::SphaleriteC24<double>();
            mineral_C25 = mpc::data::SphaleriteC25<double>();
            mineral_C26 = mpc::data::SphaleriteC26<double>();
            mineral_C33 = mpc::data::SphaleriteC33<double>();
            mineral_C34 = mpc::data::SphaleriteC34<double>();
            mineral_C35 = mpc::data::SphaleriteC35<double>();
            mineral_C36 = mpc::data::SphaleriteC36<double>();
            mineral_C44 = mpc::data::SphaleriteC44<double>();
            mineral_C45 = mpc::data::SphaleriteC45<double>();
            mineral_C46 = mpc::data::SphaleriteC46<double>();
            mineral_C55 = mpc::data::SphaleriteC55<double>();
            mineral_C56 = mpc::data::SphaleriteC56<double>();
            mineral_C66 = mpc::data::SphaleriteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 37: { // Fluorite
            mineral_C11 = mpc::data::FluoriteC11<double>();
            mineral_C12 = mpc::data::FluoriteC12<double>();
            mineral_C13 = mpc::data::FluoriteC13<double>();
            mineral_C14 = mpc::data::FluoriteC14<double>();
            mineral_C15 = mpc::data::FluoriteC15<double>();
            mineral_C16 = mpc::data::FluoriteC16<double>();
            mineral_C22 = mpc::data::FluoriteC22<double>();
            mineral_C23 = mpc::data::FluoriteC23<double>();
            mineral_C24 = mpc::data::FluoriteC24<double>();
            mineral_C25 = mpc::data::FluoriteC25<double>();
            mineral_C26 = mpc::data::FluoriteC26<double>();
            mineral_C33 = mpc::data::FluoriteC33<double>();
            mineral_C34 = mpc::data::FluoriteC34<double>();
            mineral_C35 = mpc::data::FluoriteC35<double>();
            mineral_C36 = mpc::data::FluoriteC36<double>();
            mineral_C44 = mpc::data::FluoriteC44<double>();
            mineral_C45 = mpc::data::FluoriteC45<double>();
            mineral_C46 = mpc::data::FluoriteC46<double>();
            mineral_C55 = mpc::data::FluoriteC55<double>();
            mineral_C56 = mpc::data::FluoriteC56<double>();
            mineral_C66 = mpc::data::FluoriteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 38: { // Halite
            mineral_C11 = mpc::data::HaliteC11<double>();
            mineral_C12 = mpc::data::HaliteC12<double>();
            mineral_C13 = mpc::data::HaliteC13<double>();
            mineral_C14 = mpc::data::HaliteC14<double>();
            mineral_C15 = mpc::data::HaliteC15<double>();
            mineral_C16 = mpc::data::HaliteC16<double>();
            mineral_C22 = mpc::data::HaliteC22<double>();
            mineral_C23 = mpc::data::HaliteC23<double>();
            mineral_C24 = mpc::data::HaliteC24<double>();
            mineral_C25 = mpc::data::HaliteC25<double>();
            mineral_C26 = mpc::data::HaliteC26<double>();
            mineral_C33 = mpc::data::HaliteC33<double>();
            mineral_C34 = mpc::data::HaliteC34<double>();
            mineral_C35 = mpc::data::HaliteC35<double>();
            mineral_C36 = mpc::data::HaliteC36<double>();
            mineral_C44 = mpc::data::HaliteC44<double>();
            mineral_C45 = mpc::data::HaliteC45<double>();
            mineral_C46 = mpc::data::HaliteC46<double>();
            mineral_C55 = mpc::data::HaliteC55<double>();
            mineral_C56 = mpc::data::HaliteC56<double>();
            mineral_C66 = mpc::data::HaliteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        case 39: { // Sylvite
            mineral_C11 = mpc::data::SylviteC11<double>();
            mineral_C12 = mpc::data::SylviteC12<double>();
            mineral_C13 = mpc::data::SylviteC13<double>();
            mineral_C14 = mpc::data::SylviteC14<double>();
            mineral_C15 = mpc::data::SylviteC15<double>();
            mineral_C16 = mpc::data::SylviteC16<double>();
            mineral_C22 = mpc::data::SylviteC22<double>();
            mineral_C23 = mpc::data::SylviteC23<double>();
            mineral_C24 = mpc::data::SylviteC24<double>();
            mineral_C25 = mpc::data::SylviteC25<double>();
            mineral_C26 = mpc::data::SylviteC26<double>();
            mineral_C33 = mpc::data::SylviteC33<double>();
            mineral_C34 = mpc::data::SylviteC34<double>();
            mineral_C35 = mpc::data::SylviteC35<double>();
            mineral_C36 = mpc::data::SylviteC36<double>();
            mineral_C44 = mpc::data::SylviteC44<double>();
            mineral_C45 = mpc::data::SylviteC45<double>();
            mineral_C46 = mpc::data::SylviteC46<double>();
            mineral_C55 = mpc::data::SylviteC55<double>();
            mineral_C56 = mpc::data::SylviteC56<double>();
            mineral_C66 = mpc::data::SylviteC66<double>();
            mineral_C11_lineedit->setText(QString::number(mineral_C11));
            mineral_C12_lineedit->setText(QString::number(mineral_C12));
            mineral_C13_lineedit->setText(QString::number(mineral_C13));
            mineral_C14_lineedit->setText(QString::number(mineral_C14));
            mineral_C15_lineedit->setText(QString::number(mineral_C15));
            mineral_C16_lineedit->setText(QString::number(mineral_C16));
            mineral_C22_lineedit->setText(QString::number(mineral_C22));
            mineral_C23_lineedit->setText(QString::number(mineral_C23));
            mineral_C24_lineedit->setText(QString::number(mineral_C24));
            mineral_C25_lineedit->setText(QString::number(mineral_C25));
            mineral_C26_lineedit->setText(QString::number(mineral_C26));
            mineral_C33_lineedit->setText(QString::number(mineral_C33));
            mineral_C34_lineedit->setText(QString::number(mineral_C34));
            mineral_C35_lineedit->setText(QString::number(mineral_C35));
            mineral_C36_lineedit->setText(QString::number(mineral_C36));
            mineral_C44_lineedit->setText(QString::number(mineral_C44));
            mineral_C45_lineedit->setText(QString::number(mineral_C45));
            mineral_C46_lineedit->setText(QString::number(mineral_C46));
            mineral_C55_lineedit->setText(QString::number(mineral_C55));
            mineral_C56_lineedit->setText(QString::number(mineral_C56));
            mineral_C66_lineedit->setText(QString::number(mineral_C66));
            break;
        }
        default: {}

    }  // end switch

    PrivateUpdatePlot();
}


void MineralVelsView::OnVelocitySurfaceComboBoxChanged(int i) {
    // 0 : "phase velocity surface"
    // 1 : "group velocity surface"
    // 2 : "slowness surface"
    PrivateUpdatePlot();
}

// member functions

// private member functions
void MineralVelsView::PrivateUpdatePlot() {
    // update the effective values and plot points

    mpc::core::StiffnessTensor<double> stiffnesstensortype = mpc::core::StiffnessTensor<double>();

}

