#ifndef GREENCHRISTOFFELNORMALVECTORVIEW_H
#define GREENCHRISTOFFELNORMALVECTORVIEW_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QSlider>
#include <QComboBox>

// blitz
#include <blitz/array.h>

// mpc
#include <mpc/data/mineraldataproperties.hpp>
#include <mpc/data/mineraldatatensors.hpp>
#include <mpc/mechanics/greenchristoffel.hpp>

class GreenChristoffelNormalVectorView : public QWidget
{
    Q_OBJECT
public:
    explicit GreenChristoffelNormalVectorView(QWidget *parent = nullptr);
    ~GreenChristoffelNormalVectorView();

signals:

public slots:
    void OnMineralComboBoxChanged(int);
    void OnEulerAngle0SliderReleased();
    void OnEulerAngle1SliderReleased();
    void OnEulerAngle2SliderReleased();

private:
    void UpdateTransformationTensorAndNormalVector();
    void UpdateGreenChristoffelTensor();

    // data members
    const double euler_angle_slider_scalar = 0.01;
    double n0;  // normal_vector(0)
    double n1;  // normal_vector(1)
    double n2;  // normal_vector(2)

    // mineral group box
    QComboBox* mineral_combo_box;
    QLineEdit* mineral_density_line_edit;

    // normal vector group box
    QSlider* euler_angle_0_slider;
    QLineEdit* euler_angle_0_line_edit;
    QSlider* euler_angle_1_slider;
    QLineEdit* euler_angle_1_line_edit;
    QSlider* euler_angle_2_slider;
    QLineEdit* euler_angle_2_line_edit;
    QLineEdit* transtensor_00_line_edit;
    QLineEdit* transtensor_01_line_edit;
    QLineEdit* transtensor_02_line_edit;
    QLineEdit* transtensor_10_line_edit;
    QLineEdit* transtensor_11_line_edit;
    QLineEdit* transtensor_12_line_edit;
    QLineEdit* transtensor_20_line_edit;
    QLineEdit* transtensor_21_line_edit;
    QLineEdit* transtensor_22_line_edit;
    QLineEdit* normal_vector_0_line_edit;
    QLineEdit* normal_vector_1_line_edit;
    QLineEdit* normal_vector_2_line_edit;

    // Green-Christoffel group box
    QLineEdit* greenchristoffel_00_line_edit;
    QLineEdit* greenchristoffel_01_line_edit;
    QLineEdit* greenchristoffel_02_line_edit;
    QLineEdit* greenchristoffel_10_line_edit;
    QLineEdit* greenchristoffel_11_line_edit;
    QLineEdit* greenchristoffel_12_line_edit;
    QLineEdit* greenchristoffel_20_line_edit;
    QLineEdit* greenchristoffel_21_line_edit;
    QLineEdit* greenchristoffel_22_line_edit;
    QLineEdit* eigenvalues_real_0_line_edit;
    QLineEdit* eigenvalues_real_1_line_edit;
    QLineEdit* eigenvalues_real_2_line_edit;
    QLineEdit* eigenvalues_imag_0_line_edit;
    QLineEdit* eigenvalues_imag_1_line_edit;
    QLineEdit* eigenvalues_imag_2_line_edit;

    QLineEdit* phase_vels_0_line_edit;
    QLineEdit* phase_vels_1_line_edit;
    QLineEdit* phase_vels_2_line_edit;


};

#endif // GREENCHRISTOFFELNORMALVECTORVIEW_H
