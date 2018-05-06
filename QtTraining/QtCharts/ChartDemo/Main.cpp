#include <unistd.h>
#include <QApplication>
#include "ChartWidget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ChartWidget w;
	w.show();

	for(int i = 1; i < 100; ++i)
	{
		w.append( QPointF(i, i * i + 2 / i) );
//		sleep(1);
	}
	w.append( QPointF(0,0) );

	return app.exec();
}
