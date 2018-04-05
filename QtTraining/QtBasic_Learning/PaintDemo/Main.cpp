#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *args[])
{
	QApplication app( argc, args );

	MainWindow w;
	w.show();

	return app.exec();
}
