#include <unistd.h>
#include <QApplication>

#include "ChartWidget.h"
#include "ChartTimeWidget.h"

#include <QTimer>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ChartWidget w;
	w.show();

	/*
	for(int i = 1; i < 100; ++i)
	{
		w.append( QPointF(i, i * i + 2 / i) );
	}
	w.append( QPointF(0,0) );
	*/

    ChartTimeWidget chart;

    QTimer timer;
    timer.start( 1000 );
    QObject::connect( &timer, SIGNAL(timeout()),
                      &w, SLOT(slot_test()));
    chart.show();
    chart.start(1000);
    chart.setValue( 50 );

	return app.exec();
}
