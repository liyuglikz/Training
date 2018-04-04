#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>

#include <QLabel>
#include <QVBoxLayout>

class TcpServer : public QWidget
{
    Q_OBJECT
private slots:
    void sendMsg();
	void sendMsg_Streamming();

public:
    TcpServer(QWidget *parent = 0);
    ~TcpServer();

private:
    QTcpServer *tcpserver;
    QVBoxLayout *layout_main;
    QLabel label_add;
    QLabel label_port;
};

#endif // TCPSERVER_H
