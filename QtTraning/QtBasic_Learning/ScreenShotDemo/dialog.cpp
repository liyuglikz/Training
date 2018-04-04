#include "dialog.h"
#include <QApplication>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    layout = new QHBoxLayout();
    shot = new QPushButton();
    s = new QLabel();

    pixmap = new QPixmap();

    s->setText("Shot");

    layout->addWidget(shot);
    layout->addWidget(s);

    this->setLayout( layout );

    connect(shot, SIGNAL(clicked(bool)), this, SLOT(shotScreen()));
}

Dialog::~Dialog()
{
    delete s;
    delete shot;
    delete pixmap;
    delete layout;
}

void Dialog::shotScreen()
{
    this->setHidden(true);
    *(this->pixmap) = QPixmap::grabWindow(QApplication::desktop()->winId());
    //this->pixmap = QPixmap::grabWindow((QApplication::desktop())->effectiveWinId());

    s->setPixmap( pixmap->scaled(QSize(320, 400)));
    this->setHidden(false);
}
