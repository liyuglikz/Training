#ifndef TESTTHREAD_H
#define TESTTHREAD_H
#include <unistd.h>
#include <QThread>

class mThread : public QThread
{
    Q_OBJECT
signals:
    void signal_value(double k);
public:
    mThread(QObject *parent = NULL) : QThread(parent){

    }

    void run()
    {
        while(1)
        {
            sleep(1);
            emit signal_value( (int)(qrand() % 100));
        }
    }

};

#endif // TESTTHREAD_H
