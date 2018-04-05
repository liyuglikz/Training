#include "MainWindow.h"

MainWindow::MainWindow( QWidget *parent): QDialog( parent )
{
    this->setMinimumSize(QSize(320,400));
    layout.addWidget( &pw );
    this->setLayout( &layout );
}

MainWindow::~MainWindow()
{

}
