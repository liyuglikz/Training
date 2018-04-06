#include <QCoreApplication>
#include "TcpServer.h"

int main( int argc, char *argv[])
{
	QCoreApplication app(argc, argv );

	TcpServer server;
	server.StartServer();

	return app.exec();
}
