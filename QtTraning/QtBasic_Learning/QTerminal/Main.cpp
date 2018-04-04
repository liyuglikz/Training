#include "App.h"
#include <QCoreApplication>

int main(int args, char *argv[])
{
    App a(args, argv);
    return a.exec();
}
