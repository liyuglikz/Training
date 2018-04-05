#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    flag = false;
    layout = new QVBoxLayout();

    startButton = new QPushButton();
    pauseButton = new QPushButton();

    startButton->setText("Start");
    pauseButton->setText("Pause");

    viwer = new QLabel();
    pixmap = new QPixmap();


    layout->addWidget( viwer );
    layout->addWidget( startButton );
    layout->addWidget( pauseButton );
    this->setLayout( layout );

    // Connect signals slots
    connect(startButton, SIGNAL(clicked(bool)),
            this, SLOT(startV()));
    connect(pauseButton, SIGNAL(clicked(bool)),
            this, SLOT(pauseV()));
    connect(&t, SIGNAL(timeout()),
            this, SLOT(screenShot()));
    f_time = 16;
    t.setInterval(f_time);
}

MainWindow::~MainWindow()
{
    delete startButton;
    delete pauseButton;
    delete viwer;
    delete pixmap;
    delete layout;
}

/*
inline void MainWindow::screenShot()
{
    *(this->pixmap) = QPixmap::grabWindow(
                QApplication::desktop()->winId());
    emit deployShot( *pixmap );

    this->viwer->setPixmap(
        pixmap->scaled(QSize(800, 450)));
}
*/

void MainWindow::startV()
{
    flag = true;
    t.start();
}

void MainWindow::pauseV()
{
    flag = false;
    t.stop();
}
