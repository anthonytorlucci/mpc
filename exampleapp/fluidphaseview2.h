#ifndef MPCEXAMPLEAPP_FLUIDPHASEVIEW2_H
#define MPCEXAMPLEAPP_FLUIDPHASEVIEW2_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>

#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkChartXY.h>
#include <vtkContextView.h>

// http://www.labvib.ufc.br/P_Free/DIR/Patterns/WinMyProjet3_Dialog_Charts.pdf

//class vtkRenderWindow;
//class vtkRnederer;
//class vtkContextView;
//class vtkChartXY;

class FluidPhaseView2 : public QWidget {
Q_OBJECT
public:
    explicit FluidPhaseView2(QWidget *parent = nullptr);
    ~FluidPhaseView2();

signals:

public slots:
    void OnInteractiveCheckBoxStateChanged(int);

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

    // variables


    // Qt widgets
    QCheckBox* interactive_checkbox;


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
