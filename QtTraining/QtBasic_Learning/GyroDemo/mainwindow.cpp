#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent ) : QMainWindow(parent)
{
    g = new GyroScopeArea();
    button = new QPushButton();
    button->setText("Switch");

    this->setCentralWidget( button );
    connect( g, SIGNAL(emitData(double,double,double))
             ,this, SLOT(getData(double,double,double)));
    connect( button, SIGNAL(clicked(bool)),
             this, SLOT(switch_button()));
}

void MainWindow::getData(double x, double y, double z)
{
    qDebug() << "Pos: " << x << " , " << y << " , " << z;
}

void MainWindow::switch_button()
{
    flag = !flag;

    if(flag)
        this->g->Start();
    else
        this->g->Pause();
}
