#include "Thread.h"
#include <QDebug>
#include <QMutex>

Thread::Thread() : flag(false)
{
}

void Thread::run()
{
	qDebug() << this->name << " Running";
	for(int i = 0; i < 100000; ++i)
	{
		QMutex mutex;

		// thread1 would stop delay without mutex lock
		mutex.lock();
		if( this->flag )
		{
			qDebug() << this->name << " Stoped";
			break;
		}
		mutex.unlock();

		this->msleep(100); // sleep ms

		emit this->signal_num( i ); //emit signal
	}
}
