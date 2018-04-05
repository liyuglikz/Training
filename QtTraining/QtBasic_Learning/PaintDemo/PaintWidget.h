#ifndef _HEAD_PAINTWIDGET_
#define _HEAD_PAINTWIDGET_

#include <QWidget>

#include <QPaintDevice>
#include <QPaintEvent>
#include <QPainter>

#include <QPainterPath>
#include <QPoint>
#include <QPen>

#include <QMouseEvent>
#include <QVector>

class PaintWidget : public QWidget
{
public:
	PaintWidget( QWidget *parent = 0);
	~PaintWidget();

protected:
    void paintEvent( QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:

    int pen_width;
    QColor pen_Color;
    QPen pen;
    QPoint start_point;
    QPoint end_point;
    QPainter *painter;
    QPainterPath path;

    QVector<QPoint> lib;
};

#endif
