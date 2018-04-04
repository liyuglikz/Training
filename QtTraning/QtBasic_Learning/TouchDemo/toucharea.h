#ifndef TOUCHAREA_H
#define TOUCHAREA_H

#include <QWidget>
#include <QEvent>
#include <QTouchEvent>
#include <QList>

class TouchArea : public QWidget
{
    Q_OBJECT
signals:
   void transV(double x, double y);
   void transPos(double x, double y);
private slots:
   void tVdata(double x, double y);
public:
    TouchArea(QWidget *parent = 0);
    ~TouchArea();

protected:
    bool event(QEvent *e);
private:
    void decTouchPoints(QEvent *e);

private:
    double X0, Y0;
};

#endif // TOUCHAREA_H
