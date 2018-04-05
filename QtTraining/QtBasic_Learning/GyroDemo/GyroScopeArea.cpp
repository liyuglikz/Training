#include "GyroScopeArea.h"

GyroScopeArea::GyroScopeArea(QWidget *parent) : QWidget(parent)
{
    xk = yk = zk = 1.0;
    gyrothread = new GyroThread();
    gyrothread->start();

    connect(gyrothread, SIGNAL(transData(double,double,double)),
            this, SLOT(transData(double,double,double)));
}

GyroScopeArea::~GyroScopeArea()
{
    gyrothread->terminate();
    delete gyrothread;
}

void GyroScopeArea::transData(double x, double y, double z)
{
    emit emitData(x * xk , y * yk, z * zk);
}

void GyroScopeArea::transDataM(double x, double y, double z, int button_state)
{
    emit emitDataM(x * xk, y * yk, z * zk, button_state);
}

void GyroScopeArea::Start()
{
    this->gyrothread->start();
}

void GyroScopeArea::Pause()
{
    this->gyrothread->pause();
}

GyroThread* GyroScopeArea::getGyroThread()
{
    return this->gyrothread;
}

/////////////////////////////////
double GyroScopeArea::get_xk()
{
    return xk;
}

void GyroScopeArea::set_xk(const double &k)
{
    xk = k;
}

double GyroScopeArea::get_yk()
{
    return yk;
}

void GyroScopeArea::set_yk(const double &k)
{
    yk = k;
}

double GyroScopeArea::get_zk()
{
    return zk;
}

void GyroScopeArea::set_zk(const double &k)
{
    zk = k;
}
/////////////////////////////////////

int GyroScopeArea::get_T()
{
    return this->gyrothread->getT();
}

void GyroScopeArea::set_T(const int &k)
{
    this->gyrothread->setT( k );
}
