#include "PaintArea.h"
#include <QDebug>

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    paint_board = new QLabel();
    paint_papper = new QPixmap();
//    paint_papper->fill();
//    if(paint_papper->load("./0535.jpg", "JPG"))
//        qDebug() << "Got";
//    paint_board->setPixmap( *paint_papper );

	layout = new QVBoxLayout();

    this->setLayout( layout );
    layout->addWidget( paint_board );

    // init
    mouse_pos = QPoint(0, 0);
    pen_color = QColor(0, 255, 255);
    pen_width = 10;

    painter_pen.setColor( pen_color );
    painter_pen.setWidth( pen_width );
}

PaintArea::~PaintArea()
{
	delete layout;
    delete paint_board;
    delete paint_papper;
}

void PaintArea::setPenColor(const QColor &color)
{
	pen_color = color;
	painter_pen.setColor( pen_color );
}

void PaintArea::setPen(const QPen &pen)
{
	painter_pen = pen;
}

void PaintArea::setPenWidth( const unsigned int &width)
{
	pen_width = width;
	painter_pen.setWidth( pen_width );
}

void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
	mouse_pos = event->pos();
	qDebug() << mouse_pos.x() << ", " << mouse_pos.y();

   this->draw();
    paint_board->setPixmap( *paint_papper );

    update();
	if(NULL == event)
		return;
}

void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen( painter_pen );
    painter.drawPoint( mouse_pos );

    painter.end();

    if(NULL == event)
        return;
}

void PaintArea::draw()
{
    /*
    QPainter painter( paint_papper );
    painter.setPen( painter_pen );
    painter.drawPoint( mouse_pos );
    painter.end();
    */
}
