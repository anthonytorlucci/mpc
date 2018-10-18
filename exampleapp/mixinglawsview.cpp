#include "mixinglawsview.h"

#include <iostream>

// Qt
#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSurfaceFormat>
#include <QSplitter>

// VTK
#include <vtkActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>

#include <QVTKOpenGLWidget.h>



MixingLawsView::MixingLawsView(QWidget *parent) {
    // constructor

    // data box
    QGroupBox* data_groupbox = new QGroupBox("data", this);
    // TODO: add sand and mudrock data widgets
    QWidget* mudrock_data_widget = new QWidget(this);
    QComboBox* mudrock_combobox = new QComboBox(this);
    mudrock_combobox->addItem(QStringLiteral("mudrock"));
    QLabel* mudrock_density_label = new QLabel("density :", this);
    QLabel* mudrock_density_value_label = new QLabel(QString::number(mudrock_rho), this);
    QLabel* mudrock_bulkmodulus_label = new QLabel("bulk modulus :", this);
    QLabel* mudrock_bulk_modulus_value_label = new QLabel(QString::number(mudrock_K), this);
    QLabel* mudrock_shearmodulus_label = new QLabel("shear modulus :", this);
    QLabel* mudrock_shearmodulus_value_label = new QLabel(QString::number(mudrock_mu), this);
    QHBoxLayout* mudrock_data_widget_layout = new QHBoxLayout(this);
    mudrock_data_widget_layout->addWidget(mudrock_combobox);
    mudrock_data_widget_layout->addStretch(0);
    mudrock_data_widget_layout->addWidget(mudrock_density_label);
    mudrock_data_widget_layout->addWidget(mudrock_density_value_label);
    mudrock_data_widget_layout->addStretch(0);
    mudrock_data_widget_layout->addWidget(mudrock_bulkmodulus_label);
    mudrock_data_widget_layout->addWidget(mudrock_bulk_modulus_value_label);
    mudrock_data_widget_layout->addStretch(0);
    mudrock_data_widget_layout->addWidget(mudrock_shearmodulus_label);
    mudrock_data_widget_layout->addWidget(mudrock_shearmodulus_value_label);
    mudrock_data_widget_layout->addStretch(0);
    mudrock_data_widget->setLayout(mudrock_data_widget_layout);

    QWidget* sand_data_widget = new QWidget(this);
    QComboBox* sand_combobox = new QComboBox(this);
    sand_combobox->addItem(QStringLiteral("sandstone"));
    QLabel* sand_density_label = new QLabel("density :", this);
    QLabel* sand_density_value_label = new QLabel(QString::number(sand_rho), this);
    QLabel* sand_bulkmodulus_label = new QLabel("bulk modulus :", this);
    QLabel* sand_bulk_modulus_value_label = new QLabel(QString::number(sand_K), this);
    QLabel* sand_shearmodulus_label = new QLabel("shear modulus :", this);
    QLabel* sand_shearmodulus_value_label = new QLabel(QString::number(sand_mu), this);
    QHBoxLayout* sand_data_widget_layout = new QHBoxLayout(this);
    sand_data_widget_layout->addWidget(sand_combobox);
    sand_data_widget_layout->addStretch(0);
    sand_data_widget_layout->addWidget(sand_density_label);
    sand_data_widget_layout->addWidget(sand_density_value_label);
    sand_data_widget_layout->addStretch(0);
    sand_data_widget_layout->addWidget(sand_bulkmodulus_label);
    sand_data_widget_layout->addWidget(sand_bulk_modulus_value_label);
    sand_data_widget_layout->addStretch(0);
    sand_data_widget_layout->addWidget(sand_shearmodulus_label);
    sand_data_widget_layout->addWidget(sand_shearmodulus_value_label);
    sand_data_widget_layout->addStretch(0);
    sand_data_widget->setLayout(sand_data_widget_layout);

    QWidget* fluid_data_widget = new QWidget(this);
    fluid_combobox = new QComboBox(this);
    fluid_combobox->addItem(QStringLiteral("gas"));
    fluid_combobox->addItem(QStringLiteral("oil"));
    fluid_combobox->addItem(QStringLiteral("brine"));
    QLabel* fluid_density_label = new QLabel("density :", this);
    fluid_density_value_label = new QLabel(QString::number(0.186), this);  // init to gas values
    QLabel* fluid_bulkmodulus_label = new QLabel("bulk modulus :", this);
    fluid_bulkmodulus_value_label = new QLabel(QString::number(0.044), this);  // init to gas values
    QLabel* fluid_shearmodulus_label = new QLabel("shear modulus :", this);
    QLabel* fluid_shearmodulus_value_label = new QLabel(QString::number(0.0), this);
    QHBoxLayout* fluid_data_widget_layout = new QHBoxLayout(this);
    fluid_data_widget_layout->addWidget(fluid_combobox);
    fluid_data_widget_layout->addStretch(0);
    fluid_data_widget_layout->addWidget(fluid_density_label);
    fluid_data_widget_layout->addWidget(fluid_density_value_label);
    fluid_data_widget_layout->addStretch(0);
    fluid_data_widget_layout->addWidget(fluid_bulkmodulus_label);
    fluid_data_widget_layout->addWidget(fluid_bulkmodulus_value_label);
    fluid_data_widget_layout->addStretch(0);
    fluid_data_widget_layout->addWidget(fluid_shearmodulus_label);
    fluid_data_widget_layout->addWidget(fluid_shearmodulus_value_label);
    fluid_data_widget_layout->addStretch(0);
    fluid_data_widget->setLayout(fluid_data_widget_layout);

    QVBoxLayout* data_groupbox_layout = new QVBoxLayout(this);
    data_groupbox_layout->addWidget(mudrock_data_widget);
    data_groupbox_layout->addWidget(sand_data_widget);
    data_groupbox_layout->addWidget(fluid_data_widget);
    data_groupbox->setLayout(data_groupbox_layout);

    // hill average box
    QGroupBox* hill_average_groupbox = new QGroupBox("Hill average", this);
    QLabel* hill_average_label = new QLabel("Hill average : ", this);
    hill_average_slider = new QSlider(Qt::Horizontal, this);
    hill_average_slider->setRange(0,100);
    hill_average_slider->setValue(0);
    hill_average_value_label = new QLabel(QString::number(0), this);
    QHBoxLayout* hill_average_groupbox_layout = new QHBoxLayout(this);
    hill_average_groupbox_layout->addWidget(hill_average_label);
    hill_average_groupbox_layout->addWidget(hill_average_slider);
    hill_average_groupbox_layout->addWidget(hill_average_value_label);
    hill_average_groupbox_layout->addStretch(0);
    hill_average_groupbox->setLayout(hill_average_groupbox_layout);

    QWidget* controls_widget = new QWidget(this);
    QVBoxLayout* controls_widget_layout = new QVBoxLayout(this);
    controls_widget_layout->addWidget(data_groupbox);
    controls_widget_layout->addWidget(hill_average_groupbox);
    controls_widget->setLayout(controls_widget_layout);

    // vtk render window
    QVTKOpenGLWidget* vtkopenglwidget = new QVTKOpenGLWidget(this);  // TODO: use smart pointer!!!
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkopenglwidget->SetRenderWindow(renderWindow);

    //widget.resize( 256, 256 );

    vtkNew<vtkSphereSource> sphereSource;  // TODO: vtkSmartPointer

    vtkNew<vtkPolyDataMapper> sphereMapper;  // TODO: vtkSmartPointer
    sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );

    vtkNew<vtkActor> sphereActor;
    sphereActor->SetMapper( sphereMapper );

    vtkNew<vtkRenderer> renderer;
    renderer->AddActor( sphereActor );

    vtkopenglwidget->GetRenderWindow()->AddRenderer( renderer );

    // main splitter
    QSplitter* splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(controls_widget);
    splitter->addWidget(vtkopenglwidget);

    /* === signals/slots === */
    connect(fluid_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(OnFluidComboBoxChanged(int)));
    connect(hill_average_slider, SIGNAL(sliderReleased()), this, SLOT(OnHillAverageSliderReleased()));

    // this
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(splitter);
    setLayout(layout);
}

MixingLawsView::~MixingLawsView() {
    // destructor
}

// slots
void MixingLawsView::OnFluidComboBoxChanged(int i) {
    // update the active fluid properties value
    // DEBUG std::cout << "OnFluidComboBoxChanged called with i = " << i << std::endl;
    switch(i) {
        case 0: {
            // gas
            active_fluid_K = 0.044;       // (GPa)
            active_fluid_rho = 0.186;     // (g/cm**3)
            break;
        }
        case 1: {
            // oil
            active_fluid_K = 0.561;       // (GPa)
            active_fluid_rho = 0.709;     // (g/cm**3)
            break;
        }
        case 2: {
            // brine
            active_fluid_K = 2.865;     // (GPa)
            active_fluid_rho = 1.043;   // (g/cm**3)
            break;
        }
        default: {
            // something went wrong
        }
    }
    // DEBUG std::cout << "acitve fluid density : " << active_fluid_rho << std::endl;
    // DEBUG std::cout << "acitve fluid bulk mod : " << active_fluid_K << std::endl;
    fluid_density_value_label->setText(QString::number(active_fluid_rho));
    fluid_bulkmodulus_value_label->setText(QString::number(active_fluid_K));
}

void MixingLawsView::OnHillAverageSliderReleased() {
    // when slider is released, update the hill weighting coefficient data member and the hill average label
    hill_weighting_coefficient = hill_average_slider->value() * 0.01;
    hill_average_value_label->setText(QString::number(hill_weighting_coefficient));
}

// member functions