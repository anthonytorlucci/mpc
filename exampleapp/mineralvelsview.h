#ifndef MPCEXAMPLEAPP_MINERALVELSVIEW_H
#define MPCEXAMPLEAPP_MINERALVELSVIEW_H

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
#include <vtkSphereSource.h>
#include <vtkSurfaceReconstructionFilter.h>
#include <vtkContourFilter.h>
#include <vtkReverseSense.h>
#include <vtkPolyDataAlgorithm.h>
#include <vtkLinearSubdivisionFilter.h>

// blitz
#include <blitz/array.h>

class MineralVelsView : public QWidget {
Q_OBJECT
public:
    explicit MineralVelsView(QWidget *parent = nullptr);
    ~MineralVelsView();

signals:

public slots:
    void OnMineralComboBoxChanged(int);
    void OnVelocitySurfaceComboBoxChanged(int);

private:
    // private member functions
    void PrivateSetPoints();
    void PrivateUpdatePlot();
    vtkSmartPointer<vtkPolyData> PrivateTransformBack(vtkSmartPointer<vtkPoints> pt, vtkSmartPointer<vtkPolyData> pd);

    const int numgridpoints = 21;

    // variables
    double mineral_C11;
    double mineral_C12;
    double mineral_C13;
    double mineral_C14;
    double mineral_C15;
    double mineral_C16;
    double mineral_C22;
    double mineral_C23;
    double mineral_C24;
    double mineral_C25;
    double mineral_C26;
    double mineral_C33;
    double mineral_C34;
    double mineral_C35;
    double mineral_C36;
    double mineral_C44;
    double mineral_C45;
    double mineral_C46;
    double mineral_C55;
    double mineral_C56;
    double mineral_C66;
    double mineral_density;
    double mineral_K;
    double mineral_mu;
    double minvel_vp0;  // used to get the min and max vels to set bounds
    double maxvel_vp0;
    double minvel_vs1;  // used to get the min and max vels to set bounds
    double maxvel_vs1;
    double minvel_vs2;  // used to get the min and max vels to set bounds
    double maxvel_vs2;

    // Qt widgets
    QLabel* mineral_label;
    QComboBox* mineral_combobox;
    QLabel* mineral_C11_label;
    QLineEdit* mineral_C11_lineedit;
    QLabel* mineral_C12_label;
    QLineEdit* mineral_C12_lineedit;
    QLabel* mineral_C13_label;
    QLineEdit* mineral_C13_lineedit;
    QLabel* mineral_C14_label;
    QLineEdit* mineral_C14_lineedit;
    QLabel* mineral_C15_label;
    QLineEdit* mineral_C15_lineedit;
    QLabel* mineral_C16_label;
    QLineEdit* mineral_C16_lineedit;
    QLabel* mineral_C22_label;
    QLineEdit* mineral_C22_lineedit;
    QLabel* mineral_C23_label;
    QLineEdit* mineral_C23_lineedit;
    QLabel* mineral_C24_label;
    QLineEdit* mineral_C24_lineedit;
    QLabel* mineral_C25_label;
    QLineEdit* mineral_C25_lineedit;
    QLabel* mineral_C26_label;
    QLineEdit* mineral_C26_lineedit;
    QLabel* mineral_C33_label;
    QLineEdit* mineral_C33_lineedit;
    QLabel* mineral_C34_label;
    QLineEdit* mineral_C34_lineedit;
    QLabel* mineral_C35_label;
    QLineEdit* mineral_C35_lineedit;
    QLabel* mineral_C36_label;
    QLineEdit* mineral_C36_lineedit;
    QLabel* mineral_C44_label;
    QLineEdit* mineral_C44_lineedit;
    QLabel* mineral_C45_label;
    QLineEdit* mineral_C45_lineedit;
    QLabel* mineral_C46_label;
    QLineEdit* mineral_C46_lineedit;
    QLabel* mineral_C55_label;
    QLineEdit* mineral_C55_lineedit;
    QLabel* mineral_C56_label;
    QLineEdit* mineral_C56_lineedit;
    QLabel* mineral_C66_label;
    QLineEdit* mineral_C66_lineedit;

    QComboBox* velocity_surface_combobox;  // phase velocity surface, slowness surface, group velocity surface


    // VTK
    int number_of_subdivisions;  // number of subdivisions for the isotropic sphere
    vtkSmartPointer<vtkNamedColors> vtknamedcolors;
    vtkSmartPointer<vtkTextProperty> vtktextproperty;
    vtkSmartPointer<vtkTextProperty> vtktextpropertyaxes;

    vtkSmartPointer<vtkCamera> vtkcamera;  // TODO: shared camera?

    QVTKOpenGLWidget* qvtkopenglwidget_vp0;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_vp0;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_vp0;
    vtkSmartPointer<vtkRenderer> vtkrenderer_vp0;
    vtkSmartPointer<vtkPoints> vtkpoints_vp0;
    vtkSmartPointer<vtkPolyData> vtkinputpolydata_vp0;
    vtkSmartPointer<vtkSurfaceReconstructionFilter> vtksurface_vp0;
    vtkSmartPointer<vtkContourFilter> vtkcontoursurf_vp0;
    vtkSmartPointer<vtkReverseSense> vtkreverse_vp0;
    vtkSmartPointer<vtkPolyData> vtkoutputpolydata_vp0;
    vtkSmartPointer<vtkPolyDataMapper> vtkpolydatamapper_vp0;
    vtkSmartPointer<vtkActor> vtkactor_vp0;
    vtkSmartPointer<vtkRenderWindowInteractor> vtkrenderwindowinteractor_vp0;
    vtkSmartPointer<vtkVertexGlyphFilter> vtkglyphfilter_vp0;
    vtkSmartPointer<vtkPolyDataMapper> vtkpointsmapper_vp0;
    vtkSmartPointer<vtkActor> vtkpointsactor_vp0;
//    vtkSmartPointer<vtkOutlineFilter> vtkoutline_vp0;
//    vtkSmartPointer<vtkPolyDataMapper> vtkoutlinemapper_vp0;
//    vtkSmartPointer<vtkActor> vtkoutlineactor_vp0;
    vtkSmartPointer<vtkCubeAxesActor2D> vtkcubeaxesactor2d_vp0;
    vtkSmartPointer<vtkScalarBarActor> vtkscalarbaractor_vp0;
    vtkSmartPointer<vtkLookupTable> vtkcolorlookuptable_vp0;
    // iso
    vtkSmartPointer<vtkSphereSource> vtkspheresource_isovp0;
    vtkSmartPointer<vtkPolyDataMapper> vtkmapper_isovp0;
    vtkSmartPointer<vtkActor> vtkactor_isovp0;
    vtkSmartPointer<vtkUnsignedCharArray> vtkcolorchararray_vp0;
    vtkSmartPointer<vtkLinearSubdivisionFilter> vtksubdivisionfilter_vp0;

    QVTKOpenGLWidget* qvtkopenglwidget_vs1;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_vs1;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_vs1;
    vtkSmartPointer<vtkRenderer> vtkrenderer_vs1;
    vtkSmartPointer<vtkPoints> vtkpoints_vs1;
    vtkSmartPointer<vtkPolyData> vtkinputpolydata_vs1;
    vtkSmartPointer<vtkSurfaceReconstructionFilter> vtksurface_vs1;
    vtkSmartPointer<vtkContourFilter> vtkcontoursurf_vs1;
    vtkSmartPointer<vtkReverseSense> vtkreverse_vs1;
    vtkSmartPointer<vtkPolyData> vtkoutputpolydata_vs1;
    vtkSmartPointer<vtkPolyDataMapper> vtkpolydatamapper_vs1;
    vtkSmartPointer<vtkActor> vtkactor_vs1;
    vtkSmartPointer<vtkRenderWindowInteractor> vtkrenderwindowinteractor_vs1;
    vtkSmartPointer<vtkVertexGlyphFilter> vtkglyphfilter_vs1;
    vtkSmartPointer<vtkPolyDataMapper> vtkpointsmapper_vs1;
    vtkSmartPointer<vtkActor> vtkpointsactor_vs1;
//    vtkSmartPointer<vtkOutlineFilter> vtkoutline_vs1;
//    vtkSmartPointer<vtkPolyDataMapper> vtkoutlinemapper_vs1;
//    vtkSmartPointer<vtkActor> vtkoutlineactor_vs1;
    vtkSmartPointer<vtkCubeAxesActor2D> vtkcubeaxesactor2d_vs1;
    vtkSmartPointer<vtkScalarBarActor> vtkscalarbaractor_vs1;
    vtkSmartPointer<vtkLookupTable> vtkcolorlookuptable_vs1;
    // iso
    vtkSmartPointer<vtkSphereSource> vtkspheresource_isovs1;
    vtkSmartPointer<vtkPolyDataMapper> vtkmapper_isovs1;
    vtkSmartPointer<vtkActor> vtkactor_isovs1;
    vtkSmartPointer<vtkUnsignedCharArray> vtkcolorchararray_vs1;
    vtkSmartPointer<vtkLinearSubdivisionFilter> vtksubdivisionfilter_vs1;

    QVTKOpenGLWidget* qvtkopenglwidget_vs2;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> vtkgenericopenglwindow_vs2;
    vtkSmartPointer<vtkRenderWindow> vtkrenderwindow_vs2;
    vtkSmartPointer<vtkRenderer> vtkrenderer_vs2;
    vtkSmartPointer<vtkPoints> vtkpoints_vs2;
    vtkSmartPointer<vtkPolyData> vtkinputpolydata_vs2;
    vtkSmartPointer<vtkSurfaceReconstructionFilter> vtksurface_vs2;
    vtkSmartPointer<vtkContourFilter> vtkcontoursurf_vs2;
    vtkSmartPointer<vtkReverseSense> vtkreverse_vs2;
    vtkSmartPointer<vtkPolyData> vtkoutputpolydata_vs2;
    vtkSmartPointer<vtkPolyDataMapper> vtkpolydatamapper_vs2;
    vtkSmartPointer<vtkActor> vtkactor_vs2;
    vtkSmartPointer<vtkRenderWindowInteractor> vtkrenderwindowinteractor_vs2;
    vtkSmartPointer<vtkVertexGlyphFilter> vtkglyphfilter_vs2;
    vtkSmartPointer<vtkPolyDataMapper> vtkpointsmapper_vs2;
    vtkSmartPointer<vtkActor> vtkpointsactor_vs2;
//    vtkSmartPointer<vtkOutlineFilter> vtkoutline_vs2;
//    vtkSmartPointer<vtkPolyDataMapper> vtkoutlinemapper_vs2;
//    vtkSmartPointer<vtkActor> vtkoutlineactor_vs2;
    vtkSmartPointer<vtkCubeAxesActor2D> vtkcubeaxesactor2d_vs2;
    vtkSmartPointer<vtkScalarBarActor> vtkscalarbaractor_vs2;
    vtkSmartPointer<vtkLookupTable> vtkcolorlookuptable_vs2;
    // iso
    vtkSmartPointer<vtkSphereSource> vtkspheresource_isovs2;
    vtkSmartPointer<vtkPolyDataMapper> vtkmapper_isovs2;
    vtkSmartPointer<vtkActor> vtkactor_isovs2;
    vtkSmartPointer<vtkUnsignedCharArray> vtkcolorchararray_vs2;
    vtkSmartPointer<vtkLinearSubdivisionFilter> vtksubdivisionfilter_vs2;

};


#endif //MPCEXAMPLEAPP_MINERALVELSVIEW_H
