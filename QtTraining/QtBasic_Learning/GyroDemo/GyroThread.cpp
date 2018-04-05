#include "GyroThread.h"
#include <unistd.h>
#include <QDebug>

GyroThread::GyroThread(QObject *parent) : QThread(parent)
{
    this->flag = true;

    t = 25000;
    gs1.setActive( true );
    gs1.setAlwaysOn(true);

    gs1.start();
    gsreader = gs1.reading();
}

GyroThread::~GyroThread()
{
    delete gsreader;
}

void GyroThread::start(Priority p)
{
    this->flag = true;
    QThread::start( p );
}

void GyroThread::pause()
{
    this->flag = false;
}

void GyroThread::run()
{
    while(flag)
    {
        usleep(t);

        X = gsreader->x();
        Y = gsreader->y();
        Z = gsreader->z();

        qDebug("%g %g %g", X, Y, Z);
        emit transData(X, Y, Z);
//        emit transDataM(X, Y, Z, 0);
    }
}

void GyroThread::sendRightClick()
{
    X = gsreader->x();
    Y = gsreader->y();
    Z = gsreader->z();

    emit transData(X, Y, Z);
    emit transDataM(X, Y, Z, 2);
}

void GyroThread::sendLeftClick()
{
    X = gsreader->x();
    Y = gsreader->y();
    Z = gsreader->z();

    emit transData(X, Y, Z);
    emit transDataM(X, Y, Z, 1);
}

void GyroThread::setT(const int &k)
{
    t = k;
}

int GyroThread::getT()
{
    return t;
}
