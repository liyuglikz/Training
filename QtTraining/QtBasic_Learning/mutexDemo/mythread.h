#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>
#include <QMutex>

class MyThread:public QThread
{
//    Q_OBJECT
signals:
public slots:

public:
    MyThread();
    void run();
    bool Stop;
    int id;
};

#endif // MYTHREAD_H
