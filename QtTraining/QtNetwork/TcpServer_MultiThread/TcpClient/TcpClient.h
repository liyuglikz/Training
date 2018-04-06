#ifndef TCPCLIENT_H
#define TCPCLIENT_H


#include <QTcpSocket>

#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include <QWidget>

class TcpClient : public QWidget
{

	Q_OBJECT

	signals:

	public slots:
		void slot_connected();
		void slot_disconnected();
		void slot_readyRead();

		void slot_send();
		void slot_submit();

	public:
		explicit TcpClient( QWidget *parent = 0 );
		~TcpClient();

	private:

		QTcpSocket *socket;
		QLineEdit *line_ip;
		QLineEdit *line_port;
		QTextEdit *text_message;
		QPushButton *button_submit;
		QVBoxLayout *layout_main;	
};


#endif
