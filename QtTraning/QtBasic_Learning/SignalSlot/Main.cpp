#include "MainWindow.h"
#include <QApplication>

int main(int args, char *argv[])
{
	QApplication a(args, argv);

    MainWindow win;
    win.show();

	return a.exec();
}
