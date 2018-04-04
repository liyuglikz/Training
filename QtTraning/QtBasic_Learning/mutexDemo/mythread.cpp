#include "mythread.h"

MyThread::MyThread()
{
    this->Stop = false;
}

QMutex mutex;
void MyThread::run()
{
    for(int i = 0; i < 5; ++i)
    {
        //QMutex mutex;
        mutex.lock();

        if(this->Stop)
        {
           break;
        }

        //mutex.unlock();
        qDebug() << id << ": " << i;
        this->msleep(100);
        mutex.unlock();
    }
    qDebug() << "End of " << id ;
}
