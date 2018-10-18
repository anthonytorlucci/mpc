#ifndef MPCEXAMPLEAPP_FLUIDPHASEVIEW_H
#define MPCEXAMPLEAPP_FLUIDPHASEVIEW_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSlider>

#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>

// http://www.labvib.ufc.br/P_Free/DIR/Patterns/WinMyProjet3_Dialog_Charts.pdf

class vtkRenderWindow;
class vtkRnederer;
class vtkContextView;
class vtkChartXY;

class FluidPhaseView : public QWidget {
Q_OBJECT
public:
    explicit FluidPhaseView(QWidget *parent = nullptr);
    ~FluidPhaseView();

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

    // variables


    // Qt widgets

    // VTK
    QVTKOpenGLWidget* qvtkopenglwidget;

    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow;
    vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview;
    vtkSmartPointer<vtkChartXY> vtkchart;

};


#endif //MPCEXAMPLEAPP_FLUIDPHASEVIEW_H
