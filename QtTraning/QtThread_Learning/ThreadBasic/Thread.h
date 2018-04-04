#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QString>

class Thread : public QThread
{
	Q_OBJECT
		signals:
		void signal_num( int k );
	public:
		explicit Thread();
		void run();
		QString name;
		bool flag;
};

#endif
