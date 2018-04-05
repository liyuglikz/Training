#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *args[])
{
	QApplication app(argc, args);

	MainWindow w;
	w.show();

	return app.exec();
}
