#include "dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    this->setMinimumSize(QSize(320,400));
    p = new QPushButton(this);
    e = new QLabel(this);

    e->setText(QString::number(0));
    p->setText("PushMe");
    p->setGeometry(QRect(50, 50, 60, 50));
    qDebug() << "O.O";
}

Dialog::~Dialog()
{
    delete p;
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    if(NULL == event)
        return;

    p->setGeometry(QRect(p->x() + 10, 50, 50, 50));
    qDebug() << "hello";
    QDialog::keyPressEvent(event);
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(NULL == event)
        return;

    qDebug() << "(" << event->x() << ", " << event->y() << ")";
    e->setText(QString::number(event->x()));
    QDialog::mouseMoveEvent(event);
}
