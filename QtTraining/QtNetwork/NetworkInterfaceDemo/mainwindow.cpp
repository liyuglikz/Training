#include "mainwindow.h"
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->label = new QLabel();
    this->setCentralWidget( label );

    QList<QHostAddress> list  = QNetworkInterface::allAddresses();
    QList<QHostAddress> :: iterator it;

    QString str;
    for(it = list.begin(); it != list.end(); ++it)
    {
        str += it->toString();
        str += "\n";
    }
    label->setText( str );
}

MainWindow::~MainWindow()
{
    delete label;
}
