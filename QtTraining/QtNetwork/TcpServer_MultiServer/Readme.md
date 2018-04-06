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

// in TcpServer
