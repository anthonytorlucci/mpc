#ifndef MPCEXAMPLEAPP_MIXINGLAWSVIEW_H
#define MPCEXAMPLEAPP_MIXINGLAWSVIEW_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSlider>

class MixingLawsView : public QWidget {
Q_OBJECT
public:
    explicit MixingLawsView(QWidget *parent = nullptr);
    ~MixingLawsView();

signals:

public slots:
    void OnFluidComboBoxChanged(int);
    void OnHillAverageSliderReleased();

private:
    // data
    // ref : Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
    // p. 161, 170
    const double sand_K = 16.334;     // (GPa)
    const double sand_mu = 6.604;     // (GPa)
    const double sand_rho = 2.24;     // (g/cm**3)
    const double mudrock_K = 15.144;  // (GPa)
    const double mudrock_mu = 4.064;  // (GPa)
    const double mudrock_rho = 2.45;  // (g/cm**3)





    // variables
    double active_fluid_K;
    double active_fluid_rho;
    double fluid_volume_fraction;  // solid_volume_fraction = 1-fluid_volume_fraction
    double sand_volume_fraction;
    double mudrock_volume_fraction;  // sand_volume_fraction + mudrock_volume_fraction = solid_volume_fraction
    double hill_weighting_coefficient;  // 0 -> Ruess lower bound; 1 -> Voigt upper bound

    // Qt widgets
    QComboBox* fluid_combobox;
    QLabel* fluid_density_value_label;
    QLabel* fluid_bulkmodulus_value_label;

    QSlider* hill_average_slider;
    QLabel* hill_average_value_label;
};


#endif //MPCEXAMPLEAPP_MIXINGLAWSVIEW_H
