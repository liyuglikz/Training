#include "TcpClient.h"

#include <QDebug>

TcpClient :: TcpClient( QWidget *parent ) : QWidget( parent )
{
	this->socket = NULL;
	line_ip = new QLineEdit("127.0.0.1");
	line_port = new QLineEdit("9248");
	text_message = new QTextEdit("msg");
	button_submit = new QPushButton("Submit");
	layout_main = new QVBoxLayout();

	layout_main->addWidget( line_ip );
	layout_main->addWidget( line_port );
	layout_main->addWidget( text_message );
	layout_main->addWidget( button_submit );

	this->setLayout( layout_main );

	connect( button_submit, SIGNAL( clicked(bool)),
			this, SLOT( slot_submit()));
}

TcpClient::~TcpClient()
{

	delete line_ip;
	delete line_port;
	delete text_message;
	delete button_submit;
	delete layout_main;

}

void TcpClient::slot_connected()
{

}

void TcpClient::slot_disconnected()
{
	socket->deleteLater();
	socket = NULL;
}

void TcpClient::slot_readyRead()
{
	QByteArray buff = this->socket->readAll();
	this->text_message->setText( buff.data() );
}

void TcpClient::slot_submit()
{
	socket = new QTcpSocket();

	connect( this->socket, SIGNAL( connected() ),
			this, SLOT( slot_send()));

	connect( this->socket, SIGNAL( readyRead() ), 
			this, SLOT( slot_readyRead()));

	connect( this->socket, SIGNAL( disconnected()),
			this, SLOT( slot_disconnected()));


	socket->connectToHost( line_ip->text(), line_port->text().toInt());
	if( !socket->waitForConnected(2000) )
	{
		qDebug() << socket->errorString();
	}

}

void TcpClient::slot_send()
{
	if( !this->socket )
	{
		qDebug() << "Did not connected";
		return;
	}

	QByteArray buff = this->text_message->toPlainText().toLatin1();
	this->socket->write( buff.data() );
}
