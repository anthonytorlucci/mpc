#ifndef MPCEXAMPLEAPP_MIXINGLAWSVIEW_H
#define MPCEXAMPLEAPP_MIXINGLAWSVIEW_H

// Qt
#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>

// VTK
#include <QVTKOpenGLWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkDelaunay2D.h>
#include <vtkLookupTable.h>
#include <vtkUnsignedCharArray.h>
#include <vtkActor.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkOutlineFilter.h>
#include <vtkTextProperty.h>
#include <vtkCubeAxesActor2D.h>
#include <vtkScalarBarActor.h>
#include <vtkCamera.h>

// blitz
#include <blitz/array.h>

class MixingLawsView : public QWidget {
Q_OBJECT
public:
    explicit MixingLawsView(QWidget *parent = nullptr);
    ~MixingLawsView();

signals:

public slots:
    void OnForegroundFluidComboBoxChanged(int);
    void OnBackgroundSolidComboBoxChanged(int);
    void OnForegroundSolidComboBoxChanged(int);
    void OnHillAverageSliderReleased();
    void OnPorositySliderReleaed();
    void OnRockPropertyComboBoxChanged(int);

private:
    // private member functions
    void PrivateUpdatePlot();
    double PrivateCalcKSat(double K_porous_rockframe, double K_mineral_matrix, double K_fluid, double porosity);

    const int numgridpoints = 21;

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
    double background_fluid_K;
    double background_fluid_rho;
    double foreground_fluid_K;
    double foreground_fluid_rho;
    double background_solid_K;
    double background_solid_mu;
    double background_solid_rho;
    double foreground_solid_K;
    double foreground_solid_mu;
    double foreground_solid_rho;
    double fluid_volume_fraction;  // fluid_volume_fraction = 1-solid_volume_fraction, i.e., fluid_volume_fraction = porosity
    double solid_volume_fraction;  // solid_volume_fraction = 1-fluid_volume_fraction, i.e., solid_volume_fraction =  1-porosity
    double hill_weighting_coefficient;  // 0 -> Ruess lower bound; 1 -> Voigt upper bound


    // Qt widgets
    QLabel*    background_fluid_label;
    QComboBox* background_fluid_combobox;
    QLabel*    background_fluid_bulkmodulus_label;
    QLineEdit* background_fluid_bulkmodulus_value_lineedit;
    QLabel*    background_fluid_shearmodulus_label;
    QLineEdit* background_fluid_shearmodulus_value_lineedit;
    QLabel*    background_fluid_density_label;
    QLineEdit* background_fluid_density_value_lineedit;

    QLabel*    foreground_fluid_label;
    QComboBox* foreground_fluid_combobox;
    QLabel*    foreground_fluid_bulkmodulus_label;
    QLineEdit* foreground_fluid_bulkmodulus_value_lineedit;
    QLabel*    foreground_fluid_shearmodulus_label;
    QLineEdit* foreground_fluid_shearmodulus_value_lineedit;
    QLabel*    foreground_fluid_density_label;
    QLineEdit* foreground_fluid_density_value_lineedit;

    QLabel*    background_solid_label;
    QComboBox* background_solid_combobox;
    QLabel*    background_solid_bulkmodulus_label;
    QLineEdit* background_solid_bulkmodulus_value_lineedit;
    QLabel*    background_solid_shearmodulus_label;
    QLineEdit* background_solid_shearmodulus_value_lineedit;
    QLabel*    background_solid_density_label;
    QLineEdit* background_solid_density_value_lineedit;

    QLabel*    foreground_solid_label;
    QComboBox* foreground_solid_combobox;
    QLabel*    foreground_solid_bulkmodulus_label;
    QLineEdit* foreground_solid_bulkmodulus_value_lineedit;
    QLabel*    foreground_solid_shearmodulus_label;
    QLineEdit* foreground_solid_shearmodulus_value_lineedit;
    QLabel*    foreground_solid_density_label;
    QLineEdit* foreground_solid_density_value_lineedit;

    QLabel* hill_average_label;
    QSlider* hill_average_slider;
    QLineEdit* hill_average_value_lineedit;

    QLabel* porosity_label;
    QSlider* porosity_slider;
    QLineEdit* porosity_value_lineedit;

    QComboBox* rockproperty_combobox;

    // VTK
    QVTKOpenGLWidget* qvtkopenglwidget;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow;
    vtkSmartPointer<vtkRenderer> vtkrenderer;
    vtkSmartPointer<vtkNamedColors> vtknamedcolors;
    vtkSmartPointer<vtkPoints> vtkpoints;
    vtkSmartPointer<vtkPolyData> vtkinputpolydata;
    vtkSmartPointer<vtkPolyData> vtkoutputpolydata;
    vtkSmartPointer<vtkDelaunay2D> vtkdelaunay2d;
    vtkSmartPointer<vtkLookupTable> vtkcolorlookuptable;
    vtkSmartPointer<vtkUnsignedCharArray> vtkcolorchararray;
    vtkSmartPointer<vtkPolyDataMapper> vtkpolydatamapper;
    vtkSmartPointer<vtkActor> vtkactor;
    vtkSmartPointer<vtkRenderWindowInteractor> vtkrenderwindowinteractor;
    vtkSmartPointer<vtkCamera> vtkcamera;
    vtkSmartPointer<vtkVertexGlyphFilter> vtkglyphfilter;
    vtkSmartPointer<vtkPolyDataMapper> pointsmapper;
    vtkSmartPointer<vtkActor> pointsactor;
    vtkSmartPointer<vtkOutlineFilter> vtkoutline;
    vtkSmartPointer<vtkPolyDataMapper> vtkoutlinemapper;
    vtkSmartPointer<vtkActor> vtkoutlineactor;
    vtkSmartPointer<vtkTextProperty> vtktextproperty;
    vtkSmartPointer<vtkCubeAxesActor2D> vtkcubeaxesactor2d;
    vtkSmartPointer<vtkScalarBarActor> vtkscalarbaractor;

};


#endif //MPCEXAMPLEAPP_MIXINGLAWSVIEW_H
