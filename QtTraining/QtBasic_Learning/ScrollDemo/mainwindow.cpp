#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    layout = new QVBoxLayout();
    pixmap.load(":p.jpg", "JPG");
    label.setPixmap( pixmap );
    sa.setWidget( &label );
    this->setCentralWidget( &sa );
}

MainWindow::~MainWindow()
{
    delete layout;
}
