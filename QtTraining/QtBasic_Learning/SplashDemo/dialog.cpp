#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    layout = new QHBoxLayout();
    pm = new QPixmap("t.png");

    l2.setText("Pic");
    layout->addWidget( &l2);
    this->setLayout(layout);
}

Dialog::~Dialog()
{
    delete pm;
    delete layout;
}
