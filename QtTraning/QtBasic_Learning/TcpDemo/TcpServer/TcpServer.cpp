#include "TcpServer.h"
#include <QDebug>

#include <QList>
#include <QHostAddress>
#include <QNetworkInterface>

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
{
    tcpserver = new QTcpServer(this);
    if( false == tcpserver->listen())
    {
        qDebug() << "Fail";
        close();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    qDebug() << "Addr:" << ipAddress;
    qDebug() << "Port:" << tcpserver->serverPort();

    label_add.setText( ipAddress );
    label_port.setText( QString::number(tcpserver->serverPort() ));
    layout_main = new QVBoxLayout();
    layout_main->addWidget( &label_add );
    layout_main->addWidget( &label_port );
    this->setLayout( layout_main);


    connect( tcpserver, SIGNAL(newConnection()),
             this, SLOT(sendMsg_Streamming()));
//    connect( tcpserver, SIGNAL(newConnection()),
//             this, SLOT(sendMsg()));
}

TcpServer::~TcpServer()
{
    tcpserver->close();
    delete tcpserver;
    delete layout_main;
}

void TcpServer::sendMsg()
{
	static int i = 0;

    QByteArray block;

    block.append("Hello\0");
	qDebug() << ++i << " : " << block.data();

    QTcpSocket *socket = tcpserver->nextPendingConnection();
    connect( socket, SIGNAL(disconnected()),
             socket, SLOT(deleteLater()));

    socket->write( block );
    socket->disconnect();
}

void TcpServer::sendMsg_Streamming()
{
    QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion( QDataStream::Qt_4_0);
	// out << "...";
	out << QString("Hello");
	qDebug() << "Debug0";

    QTcpSocket *socket = tcpserver->nextPendingConnection();
    connect( socket, SIGNAL(disconnected()),
             socket, SLOT(deleteLater()));
    socket->write( block );
    socket->disconnect();
}
