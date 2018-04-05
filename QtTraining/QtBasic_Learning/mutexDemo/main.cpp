#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread t1, t2, t3;
    t1.id = 1;
    t2.id = 2;
    t3.id = 3;

    // Stop the thread t2
    t2.Stop = true;

    t1.start();
    t2.start();
    t3.start();

    qDebug() << "Final";
    return a.exec();
}
