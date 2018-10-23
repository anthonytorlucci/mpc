#include "mainwindow.h"

// c++ standard

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>

#include <QVTKOpenGLWidget.h>

#include "homepage.h"
//#include "fluidphaseview.h"
#include "fluidphaseview2.h"
//#include "solidphaseview.h"
#include "solidphaseview2.h"
#include "mixinglawsview.h"
#include "mineralvelsview.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // needed to ensure appropriate OpenGL context is created for VTK rendering
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

    //
    setWindowTitle("mpc example app");
    stacked_widget = QSharedPointer<QStackedWidget>(new QStackedWidget());

    QMenuBar * menubar = new QMenuBar(this);
    setMenuBar(menubar);

    QMenu* menu = menubar->addMenu("&Views");

    // home page
    HomePage* homepage = new HomePage(this);
    stacked_widget->addWidget(homepage);
    QAction * action_home_page = new QAction("&home page", this);
    connect(action_home_page, &QAction::triggered, this, &MainWindow::OnHomePage);
    menu->addAction(action_home_page);

    // fluid phase view
//    FluidPhaseView* fluidphaseview = new FluidPhaseView(this);
//    stacked_widget->addWidget(fluidphaseview);
//    QAction * action_fluidphase = new QAction("&fluid phase", this);
//    connect(action_fluidphase, &QAction::triggered, this, &MainWindow::OnFLuidPhaseView);
//    menu->addAction(action_fluidphase);

    FluidPhaseView2* fluidphaseview2 = new FluidPhaseView2(this);
    stacked_widget->addWidget(fluidphaseview2);
    QAction * action_fluidphase = new QAction("fluid phase", this);
    connect(action_fluidphase, &QAction::triggered, this, &MainWindow::OnFLuidPhaseView);
    menu->addAction(action_fluidphase);

    // solid phase view
//    SolidPhaseView* solidphaseview = new SolidPhaseView(this);
//    stacked_widget->addWidget(solidphaseview);
//    QAction * action_solidphase = new QAction("&solid phase", this);
//    connect(action_solidphase, &QAction::triggered, this, &MainWindow::OnSolidPhaseView);
//    menu->addAction(action_solidphase);

    SolidPhaseView2* solidphaseview2 = new SolidPhaseView2(this);
    stacked_widget->addWidget(solidphaseview2);
    QAction * action_solidphase = new QAction("solid phase", this);
    connect(action_solidphase, &QAction::triggered, this, &MainWindow::OnSolidPhaseView);
    menu->addAction(action_solidphase);


    // mixing laws view
    MixingLawsView* mixinglawsview = new MixingLawsView(this);
    stacked_widget->addWidget(mixinglawsview);
    // action and slot
    QAction * action_mixinglawsview = new QAction("mixing laws", this);
    connect(action_mixinglawsview, &QAction::triggered, this, &MainWindow::OnMixingLawsView);
    menu->addAction(action_mixinglawsview);

    // mineral vels view
    MineralVelsView* mineralvelsview = new MineralVelsView(this);
    stacked_widget->addWidget(mineralvelsview);
    // action and slot
    QAction * action_mineralvelsview = new QAction("mineral vels", this);
    connect(action_mineralvelsview, &QAction::triggered, this, &MainWindow::OnMineralVelsView);
    menu->addAction(action_mineralvelsview);


//    menu->addSeparator();
//    // quit application
//    QAction*  action_quit = new QAction("&quit", this);
//    connect(action_quit, &QAction::triggered, this, &MainWindow::close);
//    menu->addAction(action_quit);

    status_bar = QSharedPointer<QStatusBar>(new QStatusBar(this));
    setStatusBar(status_bar.get());
    status_bar->showMessage("done");

    setCentralWidget(stacked_widget.get());
}

MainWindow::~MainWindow()
{
    // destructor
}

// private slots
void MainWindow::OnHomePage() {
    status_bar->showMessage("loading home page ...");
    stacked_widget->setCurrentIndex(0);
    status_bar->showMessage("done");
}

void MainWindow::OnFLuidPhaseView() {
    status_bar->showMessage("loading fluid phase ...");
    stacked_widget->setCurrentIndex(1);
    status_bar->showMessage("done");
}

void MainWindow::OnSolidPhaseView() {
    status_bar->showMessage("loading solid phase ...");
    stacked_widget->setCurrentIndex(2);
    status_bar->showMessage("done");
}

void MainWindow::OnMixingLawsView() {
    status_bar->showMessage("loading mixing laws ...");
    stacked_widget->setCurrentIndex(3);
    status_bar->showMessage("done");
}

void MainWindow::OnMineralVelsView() {
    status_bar->showMessage("loading mineral vels ...");
    stacked_widget->setCurrentIndex(4);
    status_bar->showMessage("done");
}

// END