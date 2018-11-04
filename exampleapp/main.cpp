#include "mainwindow.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[]) {
    QApplication a(argc,argv);
    QFont new_font = a.font();
    new_font.setPointSize( 18 ); //your option
    //new_font.setWeight( int ** ); //your option
    a.setFont( new_font );

    MainWindow w;
    w.show();

    return a.exec();
}