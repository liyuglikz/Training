#include <string.h>
#include <QtNetwork>
#include <QDebug>

#include "receiver.h"

Receiver::Receiver(QWidget *parent)
    : QWidget(parent)
{
    strcpy(imageType, "JPG");
    viewSize.setHeight(360);
    viewSize.setWidth(640);

    startButton = new QPushButton(tr("Start"));
    pauseButton = new QPushButton(tr("Pause"));
    quitButton = new QPushButton(tr("&Quit"));

    pixmap = new QPixmap();
    viewLabel = new QLabel();
    viewWin = new GLWidget();

//! [0]
//! set Port
    port = 9248;
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(port, QUdpSocket::ShareAddress);
    datagram = new QByteArray();
//! [0]

//! [1]
    flag = false;
    connect(udpSocket, SIGNAL(readyRead()),
           this, SLOT(processPendingDatagrams()));
//! [1]
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(startV()));
    connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseV()));

    buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget( startButton );
    buttonLayout->addWidget( pauseButton );
    buttonLayout->addWidget( quitButton );

    mainLayout = new QVBoxLayout();
    mainLayout->addWidget( viewLabel );
    mainLayout->addWidget( viewWin );
    mainLayout->addLayout( buttonLayout );
    setLayout( mainLayout );

    setWindowTitle(tr("View Receiver"));
}

Receiver::~Receiver()
{
    delete quitButton;
    delete startButton;
    delete pauseButton;
    delete pixmap;
    delete viewLabel;
    delete viewWin;

    delete udpSocket;
    delete datagram;

    delete buttonLayout;
    delete mainLayout;
}

void Receiver::startV()
{
    // Start
    startButton->setEnabled(false);
    flag = true;
//    connect(udpSocket, SIGNAL(readyRead()),
//            this, SLOT(processPendingDatagrams()));
}

void Receiver::pauseV()
{
    // Pause
    startButton->setEnabled(true);
    flag = false;
//    disconnect(udpSocket, SIGNAL(readyRead()),
//            this, SLOT(processPendingDatagrams()));
}


void Receiver::processPendingDatagrams()
{
//! [2]
//!
    static long i = 0;
    qDebug() << "Got " << (i++) % 0x3fffffff;

    while (udpSocket->hasPendingDatagrams()) {
        datagram->resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram->data(), datagram->size());

        if(!flag)
            continue;
        pixmap->loadFromData( *datagram , imageType);
        viewLabel->setPixmap( pixmap->scaled( viewSize ));
        viewWin->setPixmap( *pixmap );

    }
}
