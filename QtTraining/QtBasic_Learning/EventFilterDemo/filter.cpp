#include "filter.h"

#include <QDebug>

Filter::Filter(QWidget *parent):QPushButton(parent)
{

}

Filter::~Filter()
{

}

void Filter::mouseMoveEvent(QMouseEvent *event)
{
    if(NULL == event)
        return;

    qDebug() << event->x() << " " << event->y();
    QPushButton::mouseMoveEvent(event);
}
