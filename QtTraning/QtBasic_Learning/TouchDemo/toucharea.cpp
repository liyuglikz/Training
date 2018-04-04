#include "toucharea.h"
#include <QDebug>

TouchArea::TouchArea(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setAttribute(Qt::WA_StaticContents);

    connect( this, SIGNAL(transPos(double,double)),
             this, SLOT(tVdata(double,double)));
}


TouchArea::~TouchArea()
{

}

bool TouchArea::event(QEvent *e)
{
    switch(e->type())
    {
        case QEvent::TouchBegin:
        case QEvent::TouchUpdate:
        case QEvent::TouchEnd:
        // Send touch position
        {
            decTouchPoints( e );
            break;
        }
    default: return QWidget::event( e );break;
    }
    return true;
}

void TouchArea::decTouchPoints(QEvent *e)
{
            //QTouchEvent *touch =
            //       static_cast<QTouchEvent*> (e);
            //QList<QTouchEvent::TouchPoint> touchpoints =
            //        (touch->touchPoints());

    QList<QTouchEvent::TouchPoint> touchpoints = static_cast<QTouchEvent *>(e)->touchPoints();

    QList<QTouchEvent::TouchPoint> :: iterator it;
    qDebug() << "Start Touch";
    int i = 0;
    for(it = touchpoints.begin(); it != touchpoints.end(); ++it)
    {
        switch( it->state())
        {
            case Qt::TouchPointStationary:
            case Qt::TouchPointReleased:
                continue;
            default:
            {
                qDebug() << i << " : " << it->rect().x() << " , " << it->rect().y();
                emit transPos( it->rect().x(), it->rect().y());
            }
            break;
        }
    }
    qDebug() << "End Touch";
}

void TouchArea::tVdata(double x, double y)
{
    emit transV(x - X0, y - Y0);
    X0 = x; Y0 = y;
}
