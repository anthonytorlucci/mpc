#ifndef MPCEXAMPLEAPP_FLUIDPHASEVIEW2_H
#define MPCEXAMPLEAPP_FLUIDPHASEVIEW2_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>

#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkChartXY.h>
#include <vtkContextView.h>
#include <vtkTextProperty.h>

// http://www.labvib.ufc.br/P_Free/DIR/Patterns/WinMyProjet3_Dialog_Charts.pdf

class FluidPhaseView2 : public QWidget {
Q_OBJECT
public:
    explicit FluidPhaseView2(QWidget *parent = nullptr);
    ~FluidPhaseView2();

signals:

public slots:


private:
    // data
    // ref : Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
    // p. 161, 170
    const double gas_K = 0.0435;  // GPa
    const double gas_rho = 0.1770;  // g/cm**3

    const double oil_K = 0.3922;  // GPa
    const double oil_rho = 0.6359;  // g/cm**3

    const double brine_K = 2.6819;  // GPa
    const double brine_rho = 1.0194;  // g/cm**3


    const int font_size = 18;
    // variables


    // Qt widgets
    QLabel*    background_fluid_label;
    QComboBox* background_fluid_combobox;
    QLabel*    background_fluid_bulkmodulus_label;
    QLineEdit* background_fluid_bulkmodulus_value_lineedit;
    QLabel*    background_fluid_shearmodulus_label;
    QLineEdit* background_fluid_shearmodulus_value_lineedit;
    QLabel*    background_fluid_density_label;
    QLineEdit* background_fluid_density_value_lineedit;

    QLabel*    foreground_fluid1_label;
    QComboBox* foreground_fluid1_combobox;
    QLabel*    foreground_fluid1_bulkmodulus_label;
    QLineEdit* foreground_fluid1_bulkmodulus_value_lineedit;
    QLabel*    foreground_fluid1_shearmodulus_label;
    QLineEdit* foreground_fluid1_shearmodulus_value_lineedit;
    QLabel*    foreground_fluid1_density_label;
    QLineEdit* foreground_fluid1_density_value_lineedit;

    QLabel*    foreground_fluid2_label;
    QComboBox* foreground_fluid2_combobox;
    QLabel*    foreground_fluid2_bulkmodulus_label;
    QLineEdit* foreground_fluid2_bulkmodulus_value_lineedit;
    QLabel*    foreground_fluid2_shearmodulus_label;
    QLineEdit* foreground_fluid2_shearmodulus_value_lineedit;
    QLabel*    foreground_fluid2_density_label;
    QLineEdit* foreground_fluid2_density_value_lineedit;

    // VTK
    QVTKOpenGLWidget* qvtkopenglwidget_K;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_K;
    //vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview_effK;

    vtkSmartPointer<vtkChartXY> vtkchart_effK;

    QVTKOpenGLWidget* qvtkopenglwidget_mu;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_mu;
    //vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview_effmu;
    vtkSmartPointer<vtkChartXY> vtkchart_effmu;

    QVTKOpenGLWidget* qvtkopenglwidget_rho;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_rho;
    //vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview_effrho;
    vtkSmartPointer<vtkChartXY> vtkchart_effrho;

};


#endif //MPCEXAMPLEAPP_FLUIDPHASEVIEW2_H
