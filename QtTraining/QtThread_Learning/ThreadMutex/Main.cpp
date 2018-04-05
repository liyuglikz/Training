#include <unistd.h>
#include <QCoreApplication>
#include "thread.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Thread t1;
	t1.name = "Thread 1";

	Thread t2;
	t2.name = "Thread 2";

	Thread t3;
	t3.name = "Thread 3";

	t1.start();
	t2.start();
	t3.start();

	t1.flag = true;


	return app.exec();
}
