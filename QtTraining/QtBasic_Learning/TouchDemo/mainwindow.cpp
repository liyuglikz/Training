#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    toucharea = new TouchArea();

    this->setCentralWidget( toucharea );

    connect( toucharea, SIGNAL(transPos(double,double))
             , this, SLOT( getMousePos(double,double)));
}

MainWindow::~MainWindow()
{
    delete toucharea;
}

void MainWindow::getMousePos(double x, double y)
{
    qDebug() << "Got Pos:" << x << ", " << y;
}
