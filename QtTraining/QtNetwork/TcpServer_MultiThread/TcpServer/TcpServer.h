#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

class TcpServer : public QTcpServer
{
	Q_OBJECT
	signals:
	public slots:
	public:
		explicit TcpServer( QObject *parent = 0);
		~TcpServer();

		void StartServer();

	private:

	protected:
		void incomingConnection( qintptr socketDescriptor);
};

#endif
