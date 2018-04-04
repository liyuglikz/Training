#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class TcpClient : public QWidget
{
    Q_OBJECT
private slots:
    void requestMSG();
    void receiveMSG();

public:
    TcpClient(QWidget *parent = 0);
    ~TcpClient();
private:

    QVBoxLayout *layout_main;
    QLineEdit *line_add;
    QLineEdit *line_port;
    QPushButton *button_submit;
    QLabel label;
    QTcpSocket *socket;
    QString currentBuff;

    int blocksize;
};

#endif // TCPCLIENT_H
