#ifndef MPCEXAMPLEAPP_SOLIDPHASEVIEW2_H
#define MPCEXAMPLEAPP_SOLIDPHASEVIEW2_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>

// VTK
#include <QVTKOpenGLWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkChartXY.h>
#include <vtkContextView.h>
#include <vtkTable.h>
#include <vtkFloatArray.h>
#include <vtkPlot.h>
#include <vtkColorTransferFunction.h>
#include <vtkChartLegend.h>

// http://www.labvib.ufc.br/P_Free/DIR/Patterns/WinMyProjet3_Dialog_Charts.pdf


class SolidPhaseView2 : public QWidget {
Q_OBJECT
public:
    explicit SolidPhaseView2(QWidget *parent = nullptr);
    ~SolidPhaseView2();

signals:

public slots:
    void OnForegroundSolidComboBoxChanged(int);
    void OnBackgroundSolidComboBoxChanged(int);

private:
    void PrivateUpdatePlot();

    const int font_size = 18;
    int num_points;  // number of points sampled along the brine saturation axis
    double sample_interval;

    // variables
    double background_K;
    double background_mu;
    double background_rho;

    double foreground_K;
    double foreground_mu;
    double foreground_rho;

    double color_00[3];  // VRH_00
    double color_02[3];  // VRH_02
    double color_04[3];  // VRH_04
    double color_06[3];  // VRH_06
    double color_08[3];  // VRH_08
    double color_10[3];  // VRH_10


    // Qt widgets
    QLabel*    background_label;
    QComboBox* background_combobox;
    QLabel*    background_bulkmodulus_label;
    QLineEdit* background_bulkmodulus_value_lineedit;
    QLabel*    background_shearmodulus_label;
    QLineEdit* background_shearmodulus_value_lineedit;
    QLabel*    background_density_label;
    QLineEdit* background_density_value_lineedit;

    QLabel*    foreground_label;
    QComboBox* foreground_combobox;
    QLabel*    foreground_bulkmodulus_label;
    QLineEdit* foreground_bulkmodulus_value_lineedit;
    QLabel*    foreground_shearmodulus_label;
    QLineEdit* foreground_shearmodulus_value_lineedit;
    QLabel*    foreground_density_label;
    QLineEdit* foreground_density_value_lineedit;


    // VTK
    vtkSmartPointer<vtkColorTransferFunction> color_transfer_function;
    vtkSmartPointer<vtkTable> table;
    vtkSmartPointer<vtkFloatArray> arr_sand_volumefraction;
    vtkSmartPointer<vtkFloatArray> arr_effective_K;
    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_10;
    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_08;
    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_06;
    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_04;
    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_02;
    vtkSmartPointer<vtkFloatArray> arr_effective_K_VRH_00;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_10;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_08;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_06;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_04;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_02;
    vtkSmartPointer<vtkFloatArray> arr_effective_mu_VRH_00;
    vtkSmartPointer<vtkFloatArray> arr_effective_rho;

    QVTKOpenGLWidget* qvtkopenglwidget_K;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_K;
    //vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview_effK;
    vtkSmartPointer<vtkChartXY> vtkchart_effK;
    vtkSmartPointer<vtkChartLegend> vtkchartlegend_effK;
    vtkSmartPointer<vtkPlot> line_effK;
    vtkSmartPointer<vtkPlot> line_effK_10;
    vtkSmartPointer<vtkPlot> line_effK_08;
    vtkSmartPointer<vtkPlot> line_effK_06;
    vtkSmartPointer<vtkPlot> line_effK_04;
    vtkSmartPointer<vtkPlot> line_effK_02;
    vtkSmartPointer<vtkPlot> line_effK_00;

    QVTKOpenGLWidget* qvtkopenglwidget_mu;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_mu;
    //vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview_effmu;
    vtkSmartPointer<vtkChartXY> vtkchart_effmu;
    vtkSmartPointer<vtkChartLegend> vtkchartlegend_effmu;
    vtkSmartPointer<vtkPlot> line_effmu;
    vtkSmartPointer<vtkPlot> line_effmu_10;
    vtkSmartPointer<vtkPlot> line_effmu_08;
    vtkSmartPointer<vtkPlot> line_effmu_06;
    vtkSmartPointer<vtkPlot> line_effmu_04;
    vtkSmartPointer<vtkPlot> line_effmu_02;
    vtkSmartPointer<vtkPlot> line_effmu_00;

    QVTKOpenGLWidget* qvtkopenglwidget_rho;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_rho;
    //vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkContextView> vtkcontextview_effrho;
    vtkSmartPointer<vtkChartXY> vtkchart_effrho;
    vtkSmartPointer<vtkChartLegend> vtkchartlegend_effrho;
    vtkSmartPointer<vtkPlot> line_effrho;

};


#endif //MPCEXAMPLEAPP_SOLIDPHASEVIEW2_H
