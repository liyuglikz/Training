#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{

}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GLWidget::paintGL()
{

    glBegin(GL_QUADS);
    drawTexture(rect,texture,GL_TEXTURE_2D);
    glEnd();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::setPixmap(const QPixmap &_pixmap)
{
    this->pixmap = _pixmap;
    texture = bindTexture( pixmap, GL_TEXTURE_2D);
    rect.setX(0.0);
    rect.setY(0.0);
//    rect.setWidth( (qreal)size().width() );
//   rect.setHeight( (qreal) size().height());
    rect.setWidth( (qreal) pixmap.size().width());
    rect.setHeight( (qreal) pixmap.height());
//    drawTexture(rect,texture,GL_TEXTURE_2D);
}
