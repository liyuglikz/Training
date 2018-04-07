#ifndef TCPCLIENT_H
#define TCPCLIENT_H


#include <QTcpSocket>

#include <QStringListModel>
#include <QStringList>
#include <QListView>

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

		void slot_submit();
		void slot_login();
		void slot_logout();

	public:
		explicit TcpClient( QWidget *parent = 0 );
		~TcpClient();

	private:

		QTcpSocket *socket;
		QLineEdit *line_ip;
		QLineEdit *line_port;
		QTextEdit *text_message;
		QPushButton *button_submit;
		QPushButton *button_login;
		QPushButton *button_logout;

		QVBoxLayout *layout_main;	

		QStringList *string_list;
		QStringListModel *model_list;
		QListView *view_list;
};


#endif
