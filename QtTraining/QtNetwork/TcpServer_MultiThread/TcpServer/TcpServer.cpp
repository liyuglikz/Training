#include <QDebug>

#include "TcpServer.h"
#include "TcpThread.h"

TcpServer::TcpServer( QObject *parent ) : QTcpServer( parent )
{
}

TcpServer::~TcpServer()
{
}

void TcpServer::StartServer()
{
	if( !this->listen( QHostAddress::Any, 9248 ) )
	{
		// listen failed
		qDebug() << "failed";
	}
	else
	{
		// start listen
		qDebug() << "start listen";
	}
}

void TcpServer::incomingConnection( qintptr socketDescriptor)
{
	qDebug() << "got";
	qDebug() << socketDescriptor << " connecting..";
	TcpThread *thread = new TcpThread( socketDescriptor );

	connect( thread, SIGNAL( finished()), thread, SLOT( deleteLater() ) );
	thread->start();
}
