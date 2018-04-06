this is a demo for tcp server with multiple thread 

How does it works?

//in SocketThread.h
	class SocketThread : public QTcpSocket
	{
		Q_OBJECT
		signals:
			void error(QTcoSocket::SocketError socketerror);

		public slots:
			void readyRead();
			void disconnected();

		public:
			void SocketThread( int id, QObject *parent = 0);
			void loadSocket( QTcpSocket *socket); // load socket
			void run(); // overload run();

		priavte:
			QTcpSocket *socket_thread;
			int socketDescriptor;
	};

// in SocketThread.cpp
	SocketThread::SocketThread( int id, QObjecet *parent)
	{
		this->socketDescriptor = id;
	}

	void SocketThread::run() // setup the socket
	{
		this->socket_thread = new QTcpSocket();
		if ( !this->socket_thread->setSocketDescriptor( this->socketDescriptor ) ) // set Socket Descriptor id
		{
			emit error ( socket_thread->error() );
		}

		connect( socket_thread, SIGNAL( readyRead()),
				this, SLOT( readyRead() ), Qt::DirectConnection ) );

		connect( socket_thread, SIGNAL( disconnected()),
				this, SLOT( disconnected() ), Qt::DirectConnection ) );
				
		this->exec(); //
	}

	void SocketThread::readyRead() //echo server to reply messages
	{
		QByteArray data_receive = socket_thread->readAll(); // receive
		socket_thread->write( data_receive ); // send
	}

	void SocketThread::disconnected() // disconnect
	{
		socket_thread->deletelater();
		exit(0);
	}


/*
 * 通过继承QTcpServer 
 * 使用QTcpServer::StartServer() 启动服务器
 * 重载incommingConnection( int socketDescriptor)，并调用SocketThread启动一个线程来连接客户端，并且将thread的finished()信号与deleteLater链接
 */
// in TcpServer.h
...
	clas TcpServer : public QTcpServer
	{
		Q_OBJECT
		public:
			explicit TcpServer( QObject *parent = 0);
			void StartServer();

		private:
		protected:
			void incomingConnection( qintptr socketDescriptor);
	}

// in TcpServer.cpp

	TcpServer::TcpSerer(QObject *parent) : QTcpServer(parent )
	{
	}

	void TcpServer::StartServer()
	{
		if( this->listen( QHostAddress::Any, 1234 ) )
		{
			qDebug() << "listening";
		}
		else
		{
			qDebug() << "Success";
		}

	}

	void TcpServer::incomingConnection( qintptr socketDescriptor)
	{

		qDebug() << socketDescription << " connecting";
		SocketThread *thread = new SocketThread( socketDescription );
		thread->start();
		connect( thread, SIGNAL( finished()), thread, SLOT( deleteLater() ) ); // once thread finished, then delete it.

	}
