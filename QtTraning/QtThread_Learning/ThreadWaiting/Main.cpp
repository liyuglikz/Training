#include <unistd.h>
#include <QCoreApplication>
#include <QDebug>
#include "Thread.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Thread t1;
	t1.name = "Thread 1";

	t1.start();

	t1.wait();
	qDebug() << "Done";

	return app.exec();
}
