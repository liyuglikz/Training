#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Signal & Slot Demo");
    this->resize( QSize(640, 400) );

    w = new QWidget();
    layout = new QVBoxLayout();

    q = new QSlider();
    pb = new QProgressBar();

    q->setValue( 0 );
    pb->setValue( 0 );

    layout->addWidget( q );
    layout->addWidget( pb );

    w->setLayout( layout );
    this->setCentralWidget( w );

    connect( this-> q, SIGNAL(valueChanged(int)), this->pb, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete pb;
    delete q;

    delete layout;
    delete w;
}
