#ifndef FILTER_H
#define FILTER_H

#include <QPushButton>
#include <QMouseEvent>

class Filter : public QPushButton
{

public:
    Filter(QWidget *parent=NULL);
    ~Filter();
protected:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // FILTER_H
