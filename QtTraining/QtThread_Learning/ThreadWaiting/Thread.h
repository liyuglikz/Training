#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QString>

class Thread : public QThread
{
	public:
		explicit Thread();
		void run();
		QString name;
		bool flag;
};

#endif
