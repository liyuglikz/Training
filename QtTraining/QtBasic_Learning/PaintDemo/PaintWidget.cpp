#include "PaintWidget.h"
#include <QDebug>

PaintWidget::PaintWidget( QWidget *parent ):QWidget(parent)
{
    lib.clear();
    pen.setStyle(Qt::SolidLine);

    pen_width = 10;
    pen_Color = QColor(255, 0, 255);

    pen.setWidth( pen_width );
    pen.setColor( pen_Color);
}

PaintWidget::~PaintWidget()
{
    delete painter;
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    painter->setPen( pen );
    painter->drawLine(start_point, end_point);
//    painter->drawLines( lib );
    painter->drawPath(path);
    painter->end();

    delete painter;
    if(NULL == event)
        return;
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    end_point = event->pos();
    /*
    if(lib.size() < 2014)
        lib.push_back( end_point);
     */
    path.moveTo(end_point);
    update();
}
