#include "TcpThread.h"
#include <QDebug>

TcpThread::TcpThread( int id_connection, QObject *parent) : QThread( parent )
{
    this->socket_descriptor = id_connection;
}

TcpThread::~TcpThread()
{
}

void TcpThread::run()
{
    socket = new QTcpSocket();
    if( !socket->setSocketDescriptor( this->socket_descriptor ))
    {
        qDebug() << this->socket_descriptor << " Connection failed";
	}

    connect( this->socket, SIGNAL( readyRead()),
            this, SLOT( slot_readyRead()), Qt::DirectConnection);

    connect( this->socket, SIGNAL( disconnected()),
             this, SLOT( slot_disconnected()), Qt::DirectConnection);
    this->exec();
}

void TcpThread::slot_readyRead()
{
    qDebug() << this->socket_descriptor << " read data:";
    QByteArray data_receive = this->socket->readAll();
    qDebug() << data_receive.data();
    this->socket->write( data_receive.data() );
}

void TcpThread::slot_disconnected()
{
    qDebug() << this->socket_descriptor << " Disconnected";
    this->socket->deleteLater();
    this->exit(0);
}
