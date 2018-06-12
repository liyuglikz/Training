#include <QApplication>
#include <QChart>
#include <QChartView>
#include <QDebug>
#include <QtWidgets>
#include "ListWidgetTest.h"

int main(int argc, char *argv[])
{
//	QApplication::setDesktopSettingsAware(false);
	QApplication app(argc, argv);

    qDebug() << QStyleFactory::keys();
    qDebug() << QApplication::style()->metaObject()->className();

	ListWidgetTest list;
	list.show();

    /*
    QtCharts::QChartView chartview;
    QtCharts::QChart chart;
    chartview.show();
	*/

	return app.exec();
}
