#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QRectF>
#include <QPixmap>

class GLWidget : public QGLWidget
{
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    void setPixmap(const QPixmap &_pixmap);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    QPixmap pixmap;
    QRectF rect;
    GLuint texture;
};

#endif // GLWIDGET_H
