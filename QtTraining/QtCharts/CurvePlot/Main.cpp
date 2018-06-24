#include <QApplication>
#include "CurvePlotWidget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CurvePlotWidget curve_widget;
	curve_widget.show();

	return app.exec();
}
