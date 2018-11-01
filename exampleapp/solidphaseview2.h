#ifndef MPCEXAMPLEAPP_SOLIDPHASEVIEW2_H
#define MPCEXAMPLEAPP_SOLIDPHASEVIEW2_H

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

class SolidPhaseView2 : public QWidget {
Q_OBJECT
public:
    explicit SolidPhaseView2(QWidget *parent = nullptr);
    ~SolidPhaseView2();

signals:

public slots:
    void OnInteractiveCheckBoxStateChanged(int);

private:
    // data
    // ref : Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
    // p. 161, 170
//    const double sand_K = 16.334;     // (GPa)
//    const double sand_mu = 6.604;     // (GPa)
//    const double sand_rho = 2.24;     // (g/cm**3)
//
//    const double mudrock_K = 15.144;  // (GPa)
//    const double mudrock_mu = 4.064;  // (GPa)
//    const double mudrock_rho = 2.45;  // (g/cm**3)

    // variables
    double background_K;
    double background_mu;
    double background_rho;

    double foreground_K;
    double foreground_mu;
    double foreground_rho;


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


#endif //MPCEXAMPLEAPP_SOLIDPHASEVIEW2_H
