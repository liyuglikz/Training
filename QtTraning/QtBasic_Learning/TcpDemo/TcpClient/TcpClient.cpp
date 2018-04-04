#include "TcpClient.h"
#include <QTimer>

TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
{
    layout_main = new QVBoxLayout();
    line_add = new QLineEdit("10.22.27.172");
    line_port = new QLineEdit("9248");
    button_submit = new QPushButton("Submit");
    socket = new QTcpSocket();

    connect( button_submit, SIGNAL(clicked(bool)),
             this, SLOT(requestMSG()));
    connect( socket, SIGNAL(readyRead()),
             this, SLOT(receiveMSG()));

    layout_main->addWidget( line_add );
    layout_main->addWidget( line_port );
    layout_main->addWidget( button_submit );
    layout_main->addWidget( &label );
    this->setLayout( layout_main );
}

TcpClient::~TcpClient()
{

}

void TcpClient::requestMSG()
{
    socket->abort();
    socket->connectToHost(
                line_add->text(),
                line_port->text().toInt()
                );
    qDebug() << line_add->text();
    qDebug() << line_port->text().toInt();
    blocksize = 0;
}

void TcpClient::receiveMSG()
{
	qDebug() << "Got";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);

    QString buff;
    in >> buff;
    qDebug() << buff;
	currentBuff = buff;
    label.setText( buff );
}

/*
void TcpClient::receiveMSG()
{
	qDebug() << "Got";
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);

    if( !blocksize )
    {
        if( socket->bytesAvailable() < (int)sizeof(quint16))
        {
            qDebug() << "Error 0";
            return;
        }
        in >> blocksize;
    }
	qDebug() << blocksize;
    if( socket->bytesAvailable() < blocksize)
    {
        qDebug() << "Error 1";
        return;
    }

    QString buff;
    in >> buff;
    if ( buff == currentBuff) {
		qDebug() << "Timer";
//        QTimer::singleShot(0, this, &TcpClient::requestMSG);

        return;
    }
	currentBuff = buff;
    qDebug() << buff;
    label.setText( buff );
}
*/
