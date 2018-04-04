#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    image = new QImage();
    pixmap = new QPixmap();
    bitmap = new QBitmap();
    pic = new QPicture();

    Q_INIT_RESOURCE(res);
    image->load(":p.jpg", "JPG");
    pixmap->load(":p.jpg", "JPG");
    bitmap->load(":p.jpg", "JPG");
    pic->load(":p.jpg", "JPG");

    layout = new QVBoxLayout();

    label[0].setPixmap(*pixmap);
    label[1].setPixmap( QPixmap::fromImage(*image ));

    layout->addWidget( (label + 1) );

    this->setLayout( layout );
}

MainWindow::~MainWindow()
{
    delete image;
    delete pixmap;
    delete bitmap;
    delete pic;

    delete layout;
}
