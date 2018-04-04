#include "dialog.h"
#include <QApplication>

#include <QPixmap>
#include <QSplashScreen>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    //QPixmap pixmap("t.png");
    QPixmap pixmap("/home/ytexas/Pictures/wifi.png");
    QSplashScreen splash(pixmap);

    qDebug() << "Start";
    splash.show();

    for(int i = 0; i < 0x7fffffff; ++i)
        ;

    w.show();
    splash.finish(&w);

    return a.exec();
}
