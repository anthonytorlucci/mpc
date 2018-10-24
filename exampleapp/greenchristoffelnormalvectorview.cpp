#include "greenchristoffelnormalvectorview.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>


// mpc
#include <mpc/transformation/eulerrotation.hpp>
#include <mpc/transformation/transformer.hpp>
#include <mpc/utilities/norm.hpp>

GreenChristoffelNormalVectorView::GreenChristoffelNormalVectorView(QWidget *parent) : QWidget(parent)
{
    // constructor
    n0 = 1;
    n1 = 0;
    n2 = 0;

    QGroupBox *mineral_group_box = new QGroupBox(tr("mineral"));
    mineral_combo_box = new QComboBox();
    mineral_combo_box->addItem(QStringLiteral("Augite"));
    mineral_combo_box->addItem(QStringLiteral("Albite"));
    mineral_combo_box->addItem(QStringLiteral("Anorthite"));
    mineral_combo_box->addItem(QStringLiteral("Labradorite"));
    mineral_combo_box->addItem(QStringLiteral("Microcline"));
    mineral_combo_box->addItem(QStringLiteral("Oligoclase"));
    mineral_combo_box->addItem(QStringLiteral("Coesite"));
    mineral_combo_box->addItem(QStringLiteral("Epidote"));
    mineral_combo_box->addItem(QStringLiteral("Hornblende"));
    mineral_combo_box->addItem(QStringLiteral("Muscovite"));
    mineral_combo_box->addItem(QStringLiteral("Gypsum"));
    mineral_combo_box->addItem(QStringLiteral("Enstatite"));
    mineral_combo_box->addItem(QStringLiteral("Forsterite"));
    mineral_combo_box->addItem(QStringLiteral("Fayalite"));
    mineral_combo_box->addItem(QStringLiteral("Montecellite"));
    mineral_combo_box->addItem(QStringLiteral("Andalusite"));
    mineral_combo_box->addItem(QStringLiteral("Silimanite"));
    mineral_combo_box->addItem(QStringLiteral("Barite"));
    mineral_combo_box->addItem(QStringLiteral("Anhydrite"));
    mineral_combo_box->addItem(QStringLiteral("Dolomite"));
    mineral_combo_box->addItem(QStringLiteral("Rutile"));
    mineral_combo_box->addItem(QStringLiteral("Zircon"));
    mineral_combo_box->addItem(QStringLiteral("Corundum"));
    mineral_combo_box->addItem(QStringLiteral("Calcite"));
    mineral_combo_box->addItem(QStringLiteral("Quartz"));
    mineral_combo_box->addItem(QStringLiteral("Tourmaline"));
    mineral_combo_box->addItem(QStringLiteral("Beryl"));
    mineral_combo_box->addItem(QStringLiteral("Graphite"));
    mineral_combo_box->addItem(QStringLiteral("Wusite"));
    mineral_combo_box->addItem(QStringLiteral("Manganosite"));
    mineral_combo_box->addItem(QStringLiteral("Periclase"));
    mineral_combo_box->addItem(QStringLiteral("Magnetite"));
    mineral_combo_box->addItem(QStringLiteral("Chromite"));
    mineral_combo_box->addItem(QStringLiteral("Spinel"));
    mineral_combo_box->addItem(QStringLiteral("Pyrite"));
    mineral_combo_box->addItem(QStringLiteral("Galena"));
    mineral_combo_box->addItem(QStringLiteral("Sphalerite"));
    mineral_combo_box->addItem(QStringLiteral("Fluorite"));
    mineral_combo_box->addItem(QStringLiteral("Halite"));
    mineral_combo_box->addItem(QStringLiteral("Sylvite"));
    mineral_combo_box->setCurrentIndex(0);

    QLabel* mineral_density_label = new QLabel(tr("density"));
    mineral_density_line_edit = new QLineEdit();
    mineral_density_line_edit->setReadOnly(true);
    mineral_density_line_edit->setText(QString::number(mpc::data::AugiteDensity<double>()));

    QHBoxLayout* mineral_widget_layout = new QHBoxLayout();
    mineral_widget_layout->addWidget(mineral_combo_box);
    mineral_widget_layout->addWidget(mineral_density_label);
    mineral_widget_layout->addWidget(mineral_density_line_edit);
    mineral_widget_layout->addStretch();

    mineral_group_box->setLayout(mineral_widget_layout);

    // Normal Vector GroupBox
    QGroupBox *normal_vector_groupbox = new QGroupBox(tr("normal vector"));

    QLabel* header_euler_angles_label = new QLabel(tr("angle (radians)"));
    QLabel* header_transformation_label = new QLabel(tr("transformation tensor"));
    QLabel* header_normal_vector_label = new QLabel(tr("normal_vector"));

    QLabel* euler_angle_0_label = new QLabel(tr("Euler angle 0"));
    euler_angle_0_slider = new QSlider(Qt::Horizontal);
    euler_angle_0_slider->setSingleStep(4);
    euler_angle_0_slider->setRange(0,628);
    euler_angle_0_line_edit = new QLineEdit();
    euler_angle_0_line_edit->setReadOnly(true);
    euler_angle_0_line_edit->setText(QString::number(0.0));

    QLabel* euler_angle_1_label = new QLabel(tr("Euler angle 1"));
    euler_angle_1_slider = new QSlider(Qt::Horizontal);
    euler_angle_1_slider->setSingleStep(4);
    euler_angle_1_slider->setRange(0,628);
    euler_angle_1_line_edit = new QLineEdit();
    euler_angle_1_line_edit->setReadOnly(true);
    euler_angle_1_line_edit->setText(QString::number(0.0));

    QLabel* euler_angle_2_label = new QLabel(tr("Euler angle 2"));
    euler_angle_2_slider = new QSlider(Qt::Horizontal);
    euler_angle_2_slider->setSingleStep(4);
    euler_angle_2_slider->setRange(0,628);
    euler_angle_2_line_edit = new QLineEdit();
    euler_angle_2_line_edit->setReadOnly(true);
    euler_angle_2_line_edit->setText(QString::number(0.0));

    // transformation tensor
    mpc::transformation::EulerRotationX3X1X3<double> euler_rotation_fo;
    blitz::Array<double,2> rot = euler_rotation_fo(0.0, 0.0, 0.0);

    transtensor_00_line_edit = new QLineEdit();
    transtensor_00_line_edit->setReadOnly(true);
    transtensor_00_line_edit->setText(QString::number(rot(0,0)));
    transtensor_01_line_edit = new QLineEdit();
    transtensor_01_line_edit->setReadOnly(true);
    transtensor_01_line_edit->setText(QString::number(rot(0,1)));
    transtensor_02_line_edit = new QLineEdit();
    transtensor_02_line_edit->setReadOnly(true);
    transtensor_02_line_edit->setText(QString::number(rot(0,2)));
    transtensor_10_line_edit = new QLineEdit();
    transtensor_10_line_edit->setReadOnly(true);
    transtensor_10_line_edit->setText(QString::number(rot(1,0)));
    transtensor_11_line_edit = new QLineEdit();
    transtensor_11_line_edit->setReadOnly(true);
    transtensor_11_line_edit->setText(QString::number(rot(1,1)));
    transtensor_12_line_edit = new QLineEdit();
    transtensor_12_line_edit->setReadOnly(true);
    transtensor_12_line_edit->setText(QString::number(rot(1,2)));
    transtensor_20_line_edit = new QLineEdit();
    transtensor_20_line_edit->setReadOnly(true);
    transtensor_20_line_edit->setText(QString::number(rot(2,0)));
    transtensor_21_line_edit = new QLineEdit();
    transtensor_21_line_edit->setReadOnly(true);
    transtensor_21_line_edit->setText(QString::number(rot(2,1)));
    transtensor_22_line_edit = new QLineEdit();
    transtensor_22_line_edit->setReadOnly(true);
    transtensor_22_line_edit->setText(QString::number(rot(2,2)));

    // normal vector
    QLabel* normal_vector_0_label = new QLabel(tr("n(0)"));
    normal_vector_0_line_edit = new QLineEdit();
    normal_vector_0_line_edit->setReadOnly(true);
    normal_vector_0_line_edit->setText(QString::number(n0));
    QLabel* normal_vector_1_label = new QLabel(tr("n(1)"));
    normal_vector_1_line_edit = new QLineEdit();
    normal_vector_1_line_edit->setReadOnly(true);
    normal_vector_1_line_edit->setText(QString::number(n1));
    QLabel* normal_vector_2_label = new QLabel(tr("n(2)"));
    normal_vector_2_line_edit = new QLineEdit();
    normal_vector_2_line_edit->setReadOnly(true);
    normal_vector_2_line_edit->setText(QString::number(n2));

    QGridLayout* normal_vector_grid_layout = new QGridLayout();
    // addWidget(*Widget, row, column, rowspan, colspan)
    normal_vector_grid_layout->addWidget(header_euler_angles_label, 0, 4, 1, 1);
    normal_vector_grid_layout->addWidget(header_transformation_label, 0, 5, 1, 3);
    normal_vector_grid_layout->addWidget(header_normal_vector_label, 0, 9, 1, 1);

    normal_vector_grid_layout->addWidget(euler_angle_0_label, 1, 0, 1, 1);
    normal_vector_grid_layout->addWidget(euler_angle_0_slider, 1, 1, 1, 3);
    normal_vector_grid_layout->addWidget(euler_angle_0_line_edit, 1, 4, 1, 1);

    normal_vector_grid_layout->addWidget(euler_angle_1_label, 2, 0, 1, 1);
    normal_vector_grid_layout->addWidget(euler_angle_1_slider, 2, 1, 1, 3);
    normal_vector_grid_layout->addWidget(euler_angle_1_line_edit, 2, 4, 1, 1);

    normal_vector_grid_layout->addWidget(euler_angle_2_label, 3, 0, 1, 1);
    normal_vector_grid_layout->addWidget(euler_angle_2_slider, 3, 1, 1, 3);
    normal_vector_grid_layout->addWidget(euler_angle_2_line_edit, 3, 4, 1, 1);

    normal_vector_grid_layout->addWidget(transtensor_00_line_edit, 1, 5, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_01_line_edit, 1, 6, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_02_line_edit, 1, 7, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_10_line_edit, 2, 5, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_11_line_edit, 2, 6, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_12_line_edit, 2, 7, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_20_line_edit, 3, 5, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_21_line_edit, 3, 6, 1, 1);
    normal_vector_grid_layout->addWidget(transtensor_22_line_edit, 3, 7, 1, 1);

    normal_vector_grid_layout->addWidget(normal_vector_0_label, 1, 8, 1, 1);
    normal_vector_grid_layout->addWidget(normal_vector_0_line_edit, 1, 9, 1, 1);
    normal_vector_grid_layout->addWidget(normal_vector_1_label, 2, 8, 1, 1);
    normal_vector_grid_layout->addWidget(normal_vector_1_line_edit, 2, 9, 1, 1);
    normal_vector_grid_layout->addWidget(normal_vector_2_label, 3, 8, 1, 1);
    normal_vector_grid_layout->addWidget(normal_vector_2_line_edit, 3, 9, 1, 1);

    normal_vector_groupbox->setLayout(normal_vector_grid_layout);


    // Green-Christoffel GroupBox
    QGroupBox *green_christoffel_groupbox = new QGroupBox(tr("Green-Christoffel"));
    QLabel* header_greenchristoffel_label = new QLabel(tr("Green-Christoffel"));
    QLabel* header_eigenvalues_real_label = new QLabel(tr("eigenvalues (real)"));
    QLabel* header_eigenvalues_imag_label = new QLabel(tr("eigenvalues (imag)"));
    QLabel* header_phase_vels_label = new QLabel(tr("phase velocities (km/s)"));

    greenchristoffel_00_line_edit = new QLineEdit();
    greenchristoffel_00_line_edit->setReadOnly(true);
    greenchristoffel_01_line_edit = new QLineEdit();
    greenchristoffel_01_line_edit->setReadOnly(true);
    greenchristoffel_02_line_edit = new QLineEdit();
    greenchristoffel_02_line_edit->setReadOnly(true);
    greenchristoffel_10_line_edit = new QLineEdit();
    greenchristoffel_10_line_edit->setReadOnly(true);
    greenchristoffel_11_line_edit = new QLineEdit();
    greenchristoffel_11_line_edit->setReadOnly(true);
    greenchristoffel_12_line_edit = new QLineEdit();
    greenchristoffel_12_line_edit->setReadOnly(true);
    greenchristoffel_20_line_edit = new QLineEdit();
    greenchristoffel_20_line_edit->setReadOnly(true);
    greenchristoffel_21_line_edit = new QLineEdit();
    greenchristoffel_21_line_edit->setReadOnly(true);
    greenchristoffel_22_line_edit = new QLineEdit();
    greenchristoffel_22_line_edit->setReadOnly(true);

    eigenvalues_real_0_line_edit = new QLineEdit();
    eigenvalues_real_0_line_edit->setReadOnly(true);
    eigenvalues_real_1_line_edit = new QLineEdit();
    eigenvalues_real_1_line_edit->setReadOnly(true);
    eigenvalues_real_2_line_edit = new QLineEdit();
    eigenvalues_real_2_line_edit->setReadOnly(true);

    eigenvalues_imag_0_line_edit = new QLineEdit();
    eigenvalues_imag_0_line_edit->setReadOnly(true);
    eigenvalues_imag_1_line_edit = new QLineEdit();
    eigenvalues_imag_1_line_edit->setReadOnly(true);
    eigenvalues_imag_2_line_edit = new QLineEdit();
    eigenvalues_imag_2_line_edit->setReadOnly(true);

    phase_vels_0_line_edit = new QLineEdit();
    phase_vels_0_line_edit->setReadOnly(true);
    phase_vels_1_line_edit = new QLineEdit();
    phase_vels_1_line_edit->setReadOnly(true);
    phase_vels_2_line_edit = new QLineEdit();
    phase_vels_2_line_edit->setReadOnly(true);

    QGridLayout* green_christoffel_grid_layout = new QGridLayout();
    // addWidget(*Widget, row, column, rowspan, colspan)
    green_christoffel_grid_layout->addWidget(header_greenchristoffel_label, 0, 0, 1, 3);
    green_christoffel_grid_layout->addWidget(header_eigenvalues_real_label, 0, 3, 1, 1);
    green_christoffel_grid_layout->addWidget(header_eigenvalues_imag_label, 0, 4, 1, 1);
    green_christoffel_grid_layout->addWidget(header_phase_vels_label, 0, 5, 1, 1);

    green_christoffel_grid_layout->addWidget(greenchristoffel_00_line_edit, 1, 0, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_01_line_edit, 1, 1, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_02_line_edit, 1, 2, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_10_line_edit, 2, 0, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_11_line_edit, 2, 1, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_12_line_edit, 2, 2, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_20_line_edit, 3, 0, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_21_line_edit, 3, 1, 1, 1);
    green_christoffel_grid_layout->addWidget(greenchristoffel_22_line_edit, 3, 2, 1, 1);

    green_christoffel_grid_layout->addWidget(eigenvalues_real_0_line_edit, 1, 3, 1, 1);
    green_christoffel_grid_layout->addWidget(eigenvalues_real_1_line_edit, 2, 3, 1, 1);
    green_christoffel_grid_layout->addWidget(eigenvalues_real_2_line_edit, 3, 3, 1, 1);
    green_christoffel_grid_layout->addWidget(eigenvalues_imag_0_line_edit, 1, 4, 1, 1);
    green_christoffel_grid_layout->addWidget(eigenvalues_imag_1_line_edit, 2, 4, 1, 1);
    green_christoffel_grid_layout->addWidget(eigenvalues_imag_2_line_edit, 3, 4, 1, 1);

    green_christoffel_grid_layout->addWidget(phase_vels_0_line_edit, 1, 5, 1, 1);
    green_christoffel_grid_layout->addWidget(phase_vels_1_line_edit, 2, 5, 1, 1);
    green_christoffel_grid_layout->addWidget(phase_vels_2_line_edit, 3, 5, 1, 1);

    green_christoffel_groupbox->setLayout(green_christoffel_grid_layout);

    UpdateGreenChristoffelTensor();

    // signals/slots
    connect(mineral_combo_box, SIGNAL(currentIndexChanged(int)), this, SLOT(OnMineralComboBoxChanged(int)));
    connect(euler_angle_0_slider, SIGNAL(sliderReleased()), this, SLOT(OnEulerAngle0SliderReleased()));
    connect(euler_angle_1_slider, SIGNAL(sliderReleased()), this, SLOT(OnEulerAngle1SliderReleased()));
    connect(euler_angle_2_slider, SIGNAL(sliderReleased()), this, SLOT(OnEulerAngle2SliderReleased()));

    // finally set the widget layout...
    QVBoxLayout* widget_layout = new QVBoxLayout();
    widget_layout->addWidget(mineral_group_box);
    widget_layout->addWidget(normal_vector_groupbox);
    widget_layout->addWidget(green_christoffel_groupbox);
    widget_layout->addStretch();
    this->setLayout(widget_layout);
}

GreenChristoffelNormalVectorView::~GreenChristoffelNormalVectorView()
{
    // destructor
    delete mineral_combo_box;
    delete mineral_density_line_edit;

    delete euler_angle_0_slider;
    delete euler_angle_0_line_edit;
    delete euler_angle_1_slider;
    delete euler_angle_1_line_edit;
    delete euler_angle_2_slider;
    delete euler_angle_2_line_edit;
    delete transtensor_00_line_edit;
    delete transtensor_01_line_edit;
    delete transtensor_02_line_edit;
    delete transtensor_10_line_edit;
    delete transtensor_11_line_edit;
    delete transtensor_12_line_edit;
    delete transtensor_20_line_edit;
    delete transtensor_21_line_edit;
    delete transtensor_22_line_edit;
    delete normal_vector_0_line_edit;
    delete normal_vector_1_line_edit;
    delete normal_vector_2_line_edit;

    delete greenchristoffel_00_line_edit;
    delete greenchristoffel_01_line_edit;
    delete greenchristoffel_02_line_edit;
    delete greenchristoffel_10_line_edit;
    delete greenchristoffel_11_line_edit;
    delete greenchristoffel_12_line_edit;
    delete greenchristoffel_20_line_edit;
    delete greenchristoffel_21_line_edit;
    delete greenchristoffel_22_line_edit;
    delete eigenvalues_real_0_line_edit;
    delete eigenvalues_real_1_line_edit;
    delete eigenvalues_real_2_line_edit;
    delete eigenvalues_imag_0_line_edit;
    delete eigenvalues_imag_1_line_edit;
    delete eigenvalues_imag_2_line_edit;

    delete phase_vels_0_line_edit;
    delete phase_vels_1_line_edit;
    delete phase_vels_2_line_edit;
}

void GreenChristoffelNormalVectorView::OnMineralComboBoxChanged(int i)
{
    // slot when the mineral combo box is changed
    switch(i) {
    case 0: { // Augite
        mineral_density_line_edit->setText(QString::number(mpc::data::AugiteDensity<double>()));
        break;
    }
    case 1: { // Albite
        mineral_density_line_edit->setText(QString::number(mpc::data::AlbiteDensity<double>()));
        break;
    }
    case 2: { // Anorthite
        mineral_density_line_edit->setText(QString::number(mpc::data::AnorthiteDensity<double>()));
        break;
    }
    case 3: { // Labradorite
        mineral_density_line_edit->setText(QString::number(mpc::data::LabradoriteDensity<double>()));
        break;
    }
    case 4: { // Microcline
        mineral_density_line_edit->setText(QString::number(mpc::data::MicroclineDensity<double>()));
        break;
    }
    case 5: { // Oligoclase
        mineral_density_line_edit->setText(QString::number(mpc::data::OligoclaseDensity<double>()));
        break;
    }
    case 6: { // Coesite
        mineral_density_line_edit->setText(QString::number(mpc::data::CoesiteDensity<double>()));
        break;
    }
    case 7: { // Epidote
        mineral_density_line_edit->setText(QString::number(mpc::data::EpidoteDensity<double>()));
        break;
    }
    case 8: { // Hornblende
        mineral_density_line_edit->setText(QString::number(mpc::data::HornblendeDensity<double>()));
        break;
    }
    case 9: { // Muscovite
        mineral_density_line_edit->setText(QString::number(mpc::data::MuscoviteDensity<double>()));
        break;
    }
    case 10: { // Gypsum
        mineral_density_line_edit->setText(QString::number(mpc::data::GypsumDensity<double>()));
        break;
    }
    case 11: { // Enstatite
        mineral_density_line_edit->setText(QString::number(mpc::data::EnstatiteDensity<double>()));
        break;
    }
    case 12: { // Forsterite
        mineral_density_line_edit->setText(QString::number(mpc::data::ForsteriteDensity<double>()));
        break;
    }
    case 13: { // Fayalite
        mineral_density_line_edit->setText(QString::number(mpc::data::FayaliteDensity<double>()));
        break;
    }
    case 14: { // Montecellite
        mineral_density_line_edit->setText(QString::number(mpc::data::MontecelliteDensity<double>()));
        break;
    }
    case 15: { // Andalusite
        mineral_density_line_edit->setText(QString::number(mpc::data::AndalusiteDensity<double>()));
        break;
    }
    case 16: { // Silimanite
        mineral_density_line_edit->setText(QString::number(mpc::data::SilimaniteDensity<double>()));
        break;
    }
    case 17: { // Barite
        mineral_density_line_edit->setText(QString::number(mpc::data::BariteDensity<double>()));
        break;
    }
    case 18: { // Anhydrite
        mineral_density_line_edit->setText(QString::number(mpc::data::AnhydriteDensity<double>()));
        break;
    }
    case 19: { // Dolomite
        mineral_density_line_edit->setText(QString::number(mpc::data::DolomiteDensity<double>()));
        break;
    }
    case 20: { // Rutile
        mineral_density_line_edit->setText(QString::number(mpc::data::RutileDensity<double>()));
        break;
    }
    case 21: { // Zircon
        mineral_density_line_edit->setText(QString::number(mpc::data::ZirconDensity<double>()));
        break;
    }
    case 22: { // Corundum
        mineral_density_line_edit->setText(QString::number(mpc::data::CorundumDensity<double>()));
        break;
    }
    case 23: { // Calcite
        mineral_density_line_edit->setText(QString::number(mpc::data::CalciteDensity<double>()));
        break;
    }
    case 24: { // Quartz
        mineral_density_line_edit->setText(QString::number(mpc::data::QuartzDensity<double>()));
        break;
    }
    case 25: { // Tourmaline
        mineral_density_line_edit->setText(QString::number(mpc::data::TourmalineDensity<double>()));
        break;
    }
    case 26: { // Beryl
        mineral_density_line_edit->setText(QString::number(mpc::data::BerylDensity<double>()));
        break;
    }
    case 27: { // Graphite
        mineral_density_line_edit->setText(QString::number(mpc::data::GraphiteDensity<double>()));
        break;
    }
    case 28: { // Wusite
        mineral_density_line_edit->setText(QString::number(mpc::data::WusiteDensity<double>()));
        break;
    }
    case 29: { // Manganosite
        mineral_density_line_edit->setText(QString::number(mpc::data::ManganositeDensity<double>()));
        break;
    }
    case 30: { // Periclase
        mineral_density_line_edit->setText(QString::number(mpc::data::PericlaseDensity<double>()));
        break;
    }
    case 31: { // Magnetite
        mineral_density_line_edit->setText(QString::number(mpc::data::MagnetiteDensity<double>()));
        break;
    }
    case 32: { // Chromite
        mineral_density_line_edit->setText(QString::number(mpc::data::ChromiteDensity<double>()));
        break;
    }
    case 33: { // Spinel
        mineral_density_line_edit->setText(QString::number(mpc::data::SpinelDensity<double>()));
        break;
    }
    case 34: { // Pyrite
        mineral_density_line_edit->setText(QString::number(mpc::data::PyriteDensity<double>()));
        break;
    }
    case 35: { // Galena
        mineral_density_line_edit->setText(QString::number(mpc::data::GalenaDensity<double>()));
        break;
    }
    case 36: { // Sphalerite
        mineral_density_line_edit->setText(QString::number(mpc::data::SphaleriteDensity<double>()));
        break;
    }
    case 37: { // Fluorite
        mineral_density_line_edit->setText(QString::number(mpc::data::FluoriteDensity<double>()));
        break;
    }
    case 38: { // Halite
        mineral_density_line_edit->setText(QString::number(mpc::data::HaliteDensity<double>()));
        break;
    }
    case 39: { // Sylvite
        mineral_density_line_edit->setText(QString::number(mpc::data::SylviteDensity<double>()));
        break;
    }
    default: {}

    }  // end switch
    // TODO update green christoffel tensor
    UpdateGreenChristoffelTensor();
}

void GreenChristoffelNormalVectorView::UpdateTransformationTensorAndNormalVector()
{
    // update the transformation tensor and get the new normal vector
    n0 = 1;  // the transformation is always relative to a vector initially along the x0 axis
    n1 = 0;
    n2 = 0;
    blitz::Array<double,1> normal_vector = blitz::Array<double,1>(3);
    normal_vector = n0, n1, n2;
    double phi0 = euler_angle_0_slider->value() * euler_angle_slider_scalar;
    double phi1 = euler_angle_1_slider->value() * euler_angle_slider_scalar;
    double phi2 = euler_angle_2_slider->value() * euler_angle_slider_scalar;

    mpc::transformation::EulerRotationX3X1X3<double> euler_rotation_fo;
    blitz::Array<double,2> rot = euler_rotation_fo(phi0, phi1, phi2);
    transtensor_00_line_edit->setText(QString::number(rot(0,0)));
    transtensor_01_line_edit->setText(QString::number(rot(0,1)));
    transtensor_02_line_edit->setText(QString::number(rot(0,2)));
    transtensor_10_line_edit->setText(QString::number(rot(1,0)));
    transtensor_11_line_edit->setText(QString::number(rot(1,1)));
    transtensor_12_line_edit->setText(QString::number(rot(1,2)));
    transtensor_20_line_edit->setText(QString::number(rot(2,0)));
    transtensor_21_line_edit->setText(QString::number(rot(2,1)));
    transtensor_22_line_edit->setText(QString::number(rot(2,2)));

    mpc::transformation::Transformer<double,1> trans_fo;
    blitz::Array<double,1> rotated_normal_vector = trans_fo(normal_vector, rot);
    mpc::utilities::Normalize(rotated_normal_vector);
    n0 = rotated_normal_vector(0);
    n1 = rotated_normal_vector(1);
    n2 = rotated_normal_vector(2);
    normal_vector_0_line_edit->setText(QString::number(n0));
    normal_vector_1_line_edit->setText(QString::number(n1));
    normal_vector_2_line_edit->setText(QString::number(n2));
}

void GreenChristoffelNormalVectorView::UpdateGreenChristoffelTensor()
{
    mpc::core::StiffnessTensor<double> stiffness_tensor = mpc::core::StiffnessTensor<double>();
    double density = 1;
    int current_index = mineral_combo_box->currentIndex();
    switch(current_index) {
    case 0: { // Augite
        stiffness_tensor = mpc::data::AugiteStiffnessTensor<double>();
        density = mpc::data::AugiteDensity<double>();
        break;
    }
    case 1: { // Albite
        stiffness_tensor = mpc::data::AlbiteStiffnessTensor<double>();
        density = mpc::data::AlbiteDensity<double>();
        break;
    }
    case 2: { // Anorthite
        stiffness_tensor = mpc::data::AnorthiteStiffnessTensor<double>();
        density = mpc::data::AnorthiteDensity<double>();
        break;
    }
    case 3: { // Labradorite
        stiffness_tensor = mpc::data::LabradoriteStiffnessTensor<double>();
        density = mpc::data::LabradoriteDensity<double>();
        break;
    }
    case 4: { // Microcline
        stiffness_tensor = mpc::data::MicroclineStiffnessTensor<double>();
        density = mpc::data::MicroclineDensity<double>();
        break;
    }
    case 5: { // Oligoclase
        stiffness_tensor = mpc::data::OligoclaseStiffnessTensor<double>();
        density = mpc::data::OligoclaseDensity<double>();
        break;
    }
    case 6: { // Coesite
        stiffness_tensor = mpc::data::CoesiteStiffnessTensor<double>();
        density = mpc::data::CoesiteDensity<double>();
        break;
    }
    case 7: { // Epidote
        stiffness_tensor = mpc::data::EpidoteStiffnessTensor<double>();
        density = mpc::data::EpidoteDensity<double>();
        break;
    }
    case 8: { // Hornblende
        stiffness_tensor = mpc::data::HornblendeStiffnessTensor<double>();
        density = mpc::data::HornblendeDensity<double>();
        break;
    }
    case 9: { // Muscovite
        stiffness_tensor = mpc::data::MuscoviteStiffnessTensor<double>();
        density = mpc::data::MuscoviteDensity<double>();
        break;
    }
    case 10: { // Gypsum
        stiffness_tensor = mpc::data::GypsumStiffnessTensor<double>();
        density = mpc::data::GypsumDensity<double>();
        break;
    }
    case 11: { // Enstatite
        stiffness_tensor = mpc::data::EnstatiteStiffnessTensor<double>();
        density = mpc::data::EnstatiteDensity<double>();
        break;
    }
    case 12: { // Forsterite
        stiffness_tensor = mpc::data::ForsteriteStiffnessTensor<double>();
        density = mpc::data::ForsteriteDensity<double>();
        break;
    }
    case 13: { // Fayalite
        stiffness_tensor = mpc::data::FayaliteStiffnessTensor<double>();
        density = mpc::data::FayaliteDensity<double>();
        break;
    }
    case 14: { // Montecellite
        stiffness_tensor = mpc::data::MontecelliteStiffnessTensor<double>();
        density = mpc::data::MontecelliteDensity<double>();
        break;
    }
    case 15: { // Andalusite
        stiffness_tensor = mpc::data::AndalusiteStiffnessTensor<double>();
        density = mpc::data::AndalusiteDensity<double>();
        break;
    }
    case 16: { // Silimanite
        stiffness_tensor = mpc::data::SilimaniteStiffnessTensor<double>();
        density = mpc::data::SilimaniteDensity<double>();
        break;
    }
    case 17: { // Barite
        stiffness_tensor = mpc::data::BariteStiffnessTensor<double>();
        density = mpc::data::BariteDensity<double>();
        break;
    }
    case 18: { // Anhydrite
        stiffness_tensor = mpc::data::AnhydriteStiffnessTensor<double>();
        density = mpc::data::AnhydriteDensity<double>();
        break;
    }
    case 19: { // Dolomite
        stiffness_tensor = mpc::data::DolomiteStiffnessTensor<double>();
        density = mpc::data::DolomiteDensity<double>();
        break;
    }
    case 20: { // Rutile
        stiffness_tensor = mpc::data::RutileStiffnessTensor<double>();
        density = mpc::data::RutileDensity<double>();
        break;
    }
    case 21: { // Zircon
        stiffness_tensor = mpc::data::ZirconStiffnessTensor<double>();
        density = mpc::data::ZirconDensity<double>();
        break;
    }
    case 22: { // Corundum
        stiffness_tensor = mpc::data::CorundumStiffnessTensor<double>();
        density = mpc::data::CorundumDensity<double>();
        break;
    }
    case 23: { // Calcite
        stiffness_tensor = mpc::data::CalciteStiffnessTensor<double>();
        density = mpc::data::CalciteDensity<double>();
        break;
    }
    case 24: { // Quartz
        stiffness_tensor = mpc::data::QuartzStiffnessTensor<double>();
        density = mpc::data::QuartzDensity<double>();
        break;
    }
    case 25: { // Tourmaline
        stiffness_tensor = mpc::data::TourmalineStiffnessTensor<double>();
        density = mpc::data::TourmalineDensity<double>();
        break;
    }
    case 26: { // Beryl
        stiffness_tensor = mpc::data::BerylStiffnessTensor<double>();
        density = mpc::data::BerylDensity<double>();
        break;
    }
    case 27: { // Graphite
        stiffness_tensor = mpc::data::GraphiteStiffnessTensor<double>();
        density = mpc::data::GraphiteDensity<double>();
        break;
    }
    case 28: { // Wusite
        stiffness_tensor = mpc::data::WusiteStiffnessTensor<double>();
        density = mpc::data::WusiteDensity<double>();
        break;
    }
    case 29: { // Manganosite
        stiffness_tensor = mpc::data::ManganositeStiffnessTensor<double>();
        density = mpc::data::ManganositeDensity<double>();
        break;
    }
    case 30: { // Periclase
        stiffness_tensor = mpc::data::PericlaseStiffnessTensor<double>();
        density = mpc::data::PericlaseDensity<double>();
        break;
    }
    case 31: { // Magnetite
        stiffness_tensor = mpc::data::MagnetiteStiffnessTensor<double>();
        density = mpc::data::MagnetiteDensity<double>();
        break;
    }
    case 32: { // Chromite
        stiffness_tensor = mpc::data::ChromiteStiffnessTensor<double>();
        density = mpc::data::ChromiteDensity<double>();
        break;
    }
    case 33: { // Spinel
        stiffness_tensor = mpc::data::SpinelStiffnessTensor<double>();
        density = mpc::data::SpinelDensity<double>();
        break;
    }
    case 34: { // Pyrite
        stiffness_tensor = mpc::data::PyriteStiffnessTensor<double>();
        density = mpc::data::PyriteDensity<double>();
        break;
    }
    case 35: { // Galena
        stiffness_tensor = mpc::data::GalenaStiffnessTensor<double>();
        density = mpc::data::GalenaDensity<double>();
        break;
    }
    case 36: { // Sphalerite
        stiffness_tensor = mpc::data::SphaleriteStiffnessTensor<double>();
        density = mpc::data::SphaleriteDensity<double>();
        break;
    }
    case 37: { // Fluorite
        stiffness_tensor = mpc::data::FluoriteStiffnessTensor<double>();
        density = mpc::data::FluoriteDensity<double>();
        break;
    }
    case 38: { // Halite
        stiffness_tensor = mpc::data::HaliteStiffnessTensor<double>();
        density = mpc::data::HaliteDensity<double>();
        break;
    }
    case 39: { // Sylvite
        stiffness_tensor = mpc::data::SylviteStiffnessTensor<double>();
        density = mpc::data::SylviteDensity<double>();
        break;
    }
    default: {}

    }  // end switch
    //
    mpc::mechanics::GreenChristoffel<double> greenchristoffel = mpc::mechanics::GreenChristoffel<double>();
    blitz::Array<double,1> normal_vector = blitz::Array<double,1>(3);
    normal_vector = n0, n1, n2;
    greenchristoffel.SetComponents(stiffness_tensor, normal_vector);
    greenchristoffel_00_line_edit->setText(QString::number(greenchristoffel.tensor(0,0)));
    greenchristoffel_01_line_edit->setText(QString::number(greenchristoffel.tensor(0,1)));
    greenchristoffel_02_line_edit->setText(QString::number(greenchristoffel.tensor(0,2)));
    greenchristoffel_10_line_edit->setText(QString::number(greenchristoffel.tensor(1,0)));
    greenchristoffel_11_line_edit->setText(QString::number(greenchristoffel.tensor(1,1)));
    greenchristoffel_12_line_edit->setText(QString::number(greenchristoffel.tensor(1,2)));
    greenchristoffel_20_line_edit->setText(QString::number(greenchristoffel.tensor(2,0)));
    greenchristoffel_21_line_edit->setText(QString::number(greenchristoffel.tensor(2,1)));
    greenchristoffel_22_line_edit->setText(QString::number(greenchristoffel.tensor(2,2)));

    Eigen::Matrix<double,3,3> gctensor = mpc::utilities::Blitz2Eigen<double,3,3,2>(greenchristoffel.tensor);
    //std::cout << gctensor << std::endl;
    //Eigen::SelfAdjointEigenSolver< Eigen::Matrix<T,3,3> > eigensolver(gctensor);
    Eigen::EigenSolver< Eigen::Matrix<double,3,3> > eigensolver(gctensor); // https://eigen.tuxfamily.org/dox/classEigen_1_1EigenSolver.html#adc446bcb60572758fa64515f2825db62
    auto rho_vel_squared = eigensolver.eigenvalues();
    eigenvalues_real_0_line_edit->setText(QString::number(rho_vel_squared(0).real()));
    eigenvalues_imag_0_line_edit->setText(QString::number(rho_vel_squared(0).imag()));
    eigenvalues_real_1_line_edit->setText(QString::number(rho_vel_squared(1).real()));
    eigenvalues_imag_1_line_edit->setText(QString::number(rho_vel_squared(1).imag()));
    eigenvalues_real_2_line_edit->setText(QString::number(rho_vel_squared(2).real()));
    eigenvalues_imag_2_line_edit->setText(QString::number(rho_vel_squared(2).imag()));

    if(density != 0.0) {
        //std::array<double,3> phase_velocities = greenchristoffel.PhaseVelocities(density);
        double pvel0 = std::sqrt(rho_vel_squared(0).real()) / density;
        double pvel1 = std::sqrt(rho_vel_squared(1).real()) / density;
        double pvel2 = std::sqrt(rho_vel_squared(2).real()) / density;
        phase_vels_0_line_edit->setText(QString::number(pvel0));
        phase_vels_1_line_edit->setText(QString::number(pvel1));
        phase_vels_2_line_edit->setText(QString::number(pvel2));
    } else {
        // density is zero...
        phase_vels_0_line_edit->setText(QString::number(0.0));
        phase_vels_1_line_edit->setText(QString::number(0.0));
        phase_vels_2_line_edit->setText(QString::number(0.0));
    }

}

void GreenChristoffelNormalVectorView::OnEulerAngle0SliderReleased()
{
    double slider_value = euler_angle_0_slider->value() * euler_angle_slider_scalar;
    // update transformation tensor and normal vector
    euler_angle_0_line_edit->setText(QString::number(slider_value));
    UpdateTransformationTensorAndNormalVector();
    UpdateGreenChristoffelTensor();
}

void GreenChristoffelNormalVectorView::OnEulerAngle1SliderReleased()
{
    double slider_value = euler_angle_1_slider->value() * euler_angle_slider_scalar;
    // update transformation tensor and normal vector
    euler_angle_1_line_edit->setText(QString::number(slider_value));
    UpdateTransformationTensorAndNormalVector();
    UpdateGreenChristoffelTensor();
}

void GreenChristoffelNormalVectorView::OnEulerAngle2SliderReleased()
{
    double slider_value = euler_angle_2_slider->value() * euler_angle_slider_scalar;
    // update transformation tensor and normal vector
    euler_angle_2_line_edit->setText(QString::number(slider_value));
    UpdateTransformationTensorAndNormalVector();
    UpdateGreenChristoffelTensor();
}


