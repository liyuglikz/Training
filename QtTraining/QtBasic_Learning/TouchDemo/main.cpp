#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(res);

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":TouchDemoIcon.png"));

    MainWindow w;
    w.show();

    return a.exec();
}
