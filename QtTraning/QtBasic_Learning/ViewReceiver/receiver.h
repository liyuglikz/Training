#ifndef RECEIVER_H
#define RECEIVER_H

#include <QWidget>
#include <QPushButton>
#include <QUdpSocket>
#include <QAction>

#include <QSize>
#include <QLabel>
#include <QPixmap>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "glwidget.h"

class Receiver : public QWidget
{
    Q_OBJECT

public:
    Receiver(QWidget *parent = 0);
    ~Receiver();

private slots:
    void processPendingDatagrams();

    void startV();
    void pauseV();

private:
    QLabel *viewLabel;
    GLWidget *viewWin;
    QPushButton *quitButton;
    QPushButton *startButton;
    QPushButton *pauseButton;

    QUdpSocket *udpSocket;

    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;

    QSize viewSize;
    QPixmap *pixmap;
    QByteArray *datagram;

    int port;
    bool flag;
    char imageType[32];
};

#endif
