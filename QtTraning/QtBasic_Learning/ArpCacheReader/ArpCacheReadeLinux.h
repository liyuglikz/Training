#ifndef ARPCACHEREADER_H
#define ARPCACHEREADER_H

#include <QWidget>
#include <QStack>
#include <QList>
#include <QListWidget>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>

class ArpCacheReaderLinux : public QWidget
{
    Q_OBJECT
signals:
    void signal_IP(QString ip);

public slots:
    void slot_GotIP();
    void slot_FreshList();

public:
    ArpCacheReaderLinux(QWidget *parent = 0);
    ~ArpCacheReaderLinux();

    void sendArp();
private:
    void allocVars();
    void initLayout();
    void connectSignalsSlots();

private:
    QList<QString> ip_list;

    QVBoxLayout *layout_main;
    QHBoxLayout *layout_buttons;

    QListWidget *listwidget;
    QPushButton *button_connect;
    QPushButton *button_fresh;
};

#endif // ARPCACHEREADER_H
