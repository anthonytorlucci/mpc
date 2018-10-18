#include "mainwindow.h"

// c++ standard

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>

#include <QVTKOpenGLWidget.h>

#include "homepage.h"
#include "fluidphaseview.h"
#include "mixinglawsview.h"

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
    FluidPhaseView* fluidphaseview = new FluidPhaseView(this);
    stacked_widget->addWidget(fluidphaseview);
    QAction * action_fluidphase = new QAction("&fluid phase", this);
    connect(action_fluidphase, &QAction::triggered, this, &MainWindow::OnFLuidPhaseView);
    menu->addAction(action_fluidphase);

    // TODO: solid phase view

    // mixing laws view
    MixingLawsView* mixinglawsview = new MixingLawsView(this);
    stacked_widget->addWidget(mixinglawsview);
    // action and slot
    QAction * action_mixinglawsview = new QAction("&mixing laws", this);
    connect(action_mixinglawsview, &QAction::triggered, this, &MainWindow::OnMixingLawsView);
    menu->addAction(action_mixinglawsview);

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
    status_bar->showMessage("loading mixing laws ...");
    stacked_widget->setCurrentIndex(1);
    status_bar->showMessage("done");
}

// TODO: OnSolidPhaseView

void MainWindow::OnMixingLawsView() {
    status_bar->showMessage("loading mixing laws ...");
    stacked_widget->setCurrentIndex(2);
    status_bar->showMessage("done");
}

// END