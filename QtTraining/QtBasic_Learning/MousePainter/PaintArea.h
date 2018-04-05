#ifndef _HEAD_PAINTAREA_
#define _HEAD_PaintAREA_

#include <QWidget>
#include <QPixmap>

#include <QVBoxLayout>

#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QColor>
#include <QPen>
#include <QBrush>

#include <QMouseEvent>
#include <QPoint>

#include <QLabel>
#include <QPixmap>
#include <QImage>

class PaintArea : public QWidget
{
Q_OBJECT

public:
	PaintArea(QWidget *parent = NULL);
	~PaintArea();

	void setPenColor( const QColor &color);
	void setPen	(const QPen &pen);
	void setPenWidth( const unsigned int &width);

protected:
	void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void draw();

private:
	QPen painter_pen;
	QColor pen_color;
	unsigned int pen_width;

	QPoint mouse_pos;
	QVBoxLayout *layout;

    QLabel *paint_board;
    QPixmap *paint_papper;
};

#endif
