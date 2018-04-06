#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QTcpSocket>

class TcpThread : public QThread
{
	Q_OBJECT
	signals:
	public slots:
        void slot_readyRead();
        void slot_disconnected();
	public:
		explicit TcpThread( int id_connection, QObject *parent = 0);
		~TcpThread();

        void run();

	private:
		QTcpSocket *socket;
        int socket_descriptor;
};

#endif
