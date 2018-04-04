#include "dialog.h"

#include <QDebug>
#include <QMouseEvent>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    l = new QLabel();
    layout = new QHBoxLayout();

    this->setLayout( layout );
    layout->addWidget( &f );

    // f安装Dialog的事件过滤器
    // eventFilter的第一个形参 QObject
    // 指向的就是f
    f.installEventFilter( this );
}

Dialog::~Dialog()
{
    delete l;
    delete layout;
}

bool Dialog::eventFilter(QObject *aim, QEvent *event)
{
    if(event->type() == QEvent::MouseMove)
    {
        if(aim == &f)
        {
            QMouseEvent *mouseE = (QMouseEvent*) event;
            qDebug() << mouseE->x() << " + " << mouseE->y();
        }
    }
    return QDialog::eventFilter(aim, event);
}
