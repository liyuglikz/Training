#include "thread.h"
#include <QDebug>
#include <QMutex>

Thread::Thread() : flag(false)
{
}

void Thread::run()
{
	qDebug() << this->name << " Running";
	for(int i = 0; i < 100; ++i)
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
		//this->sleep(1) //sleep 1 second
		this->msleep(100); // sleep ms

		qDebug() << this->name << i;
	}
}
