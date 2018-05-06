#include <unistd.h>
#include <QApplication>
#include "testthread.h"

#include "ChartWidget.h"
#include "ChartTimeWidget.h"

#include <QTimer>


int main(int argc, char *argv[])
{
    srand( (unsigned int) time(NULL));
    QApplication app(argc, argv);

    /*
	ChartWidget w;
	w.show();


    QTimer timer;
    timer.start( 1000 );
    QObject::connect( &timer, SIGNAL(timeout()),
                      &w, SLOT(slot_test()));
                      */


    mThread m_thread;
    ChartTimeWidget chart;
    QObject::connect( &m_thread, SIGNAL(signal_value(double)),
                      &chart, SLOT(slot_setValue(double)));
    m_thread.start();

    chart.show();
    chart.start(1000);
    chart.setValue( 50 );


	return app.exec();
}
