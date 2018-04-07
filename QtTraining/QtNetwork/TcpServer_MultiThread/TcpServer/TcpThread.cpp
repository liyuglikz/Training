#include "TcpThread.h"
#include <QDebug>

TcpThread::TcpThread( int id_connection, QObject *parent) : QThread( parent )
{
	// got socket_descritor;
    this->socket_descriptor = id_connection;
}

TcpThread::~TcpThread()
{
}

void TcpThread::run()
{
	// init socket with socketDescriptor which receive by QtTcpServer
    socket = new QTcpSocket();
    if( !socket->setSocketDescriptor( this->socket_descriptor ))
    {
        qDebug() << this->socket_descriptor << " Connection failed";
	}

	// readData
    connect( this->socket, SIGNAL( readyRead()),
            this, SLOT( slot_readyRead()), Qt::DirectConnection);

	// disconneced
    connect( this->socket, SIGNAL( disconnected()),
             this, SLOT( slot_disconnected()), Qt::DirectConnection);


    this->exec();
}

void TcpThread::slot_readyRead()
{
    qDebug() << this->socket_descriptor << " read data:";
    QByteArray data_receive = this->socket->readAll();

    qDebug() << data_receive.data();

	// Reply msg	
    this->socket->write( "Received:" );
    this->socket->write( data_receive.data() );

	// if reply time out
	if (! this->socket->waitForBytesWritten( 3000 ))
	{
		qDebug() << this->socket_descriptor << " Reply time out..";
	}
}

void TcpThread::slot_disconnected()
{
	// disconnect
    qDebug() << this->socket_descriptor << " Disconnected";
    this->socket->deleteLater();
    this->exit(0);
}
