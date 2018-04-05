#include "ArpCacheReadeLinux.h"

#include <stdio.h>
#include <stdlib.h>
#include <QListWidgetItem>
#include <QDebug>

#define CMD_SEND_ARP "arp -a"
#define DIR_ARPCACHE "/proc/net/arp"

ArpCacheReaderLinux::ArpCacheReaderLinux(QWidget *parent) : QWidget(parent)
{
    allocVars();
    initLayout();
    connectSignalsSlots();
}

ArpCacheReaderLinux::~ArpCacheReaderLinux()
{

}

void ArpCacheReaderLinux::allocVars()
{
    listwidget = new QListWidget();
    button_connect = new QPushButton("Connect");
    button_fresh = new QPushButton("Fresh");
}

void ArpCacheReaderLinux::initLayout()
{
    layout_main = new QVBoxLayout();
    layout_main->addWidget( listwidget );

    layout_buttons = new QHBoxLayout();
    layout_buttons->addWidget( button_connect );
    layout_buttons->addWidget( button_fresh );

    layout_main->addLayout( layout_buttons);

    this->setLayout( layout_main );
}

void ArpCacheReaderLinux::connectSignalsSlots()
{
    connect( button_connect, SIGNAL(clicked(bool)),
             this, SLOT(slot_GotIP()));

    connect( button_fresh, SIGNAL(clicked(bool)),
             this, SLOT(slot_FreshList()));
}

void ArpCacheReaderLinux::slot_GotIP()
{
    QListWidgetItem *it;
    it = listwidget->currentItem();

    if(NULL == it)
    {
        qDebug() << "Have not selected!";
        return;
    }
   // qDebug() << "Got IP:" << it->text();
    emit( signal_IP( it->text() ));
}

void ArpCacheReaderLinux::slot_FreshList()
{
    this->sendArp();
}

void ArpCacheReaderLinux::sendArp()
{
    system( CMD_SEND_ARP );
    FILE *fp = fopen( DIR_ARPCACHE, "r");
    if( NULL == fp )
    {
        printf("Open Arp Cache fail!");
        return;
    }

    char buff[256], ip_buff[64];

    fgets(buff, 256, fp);

    ip_list.clear();
    listwidget->clear();

    while( NULL != fgets(buff, 256, fp))
    {
        sscanf( buff, "%s", ip_buff);
        ip_list.push_back( QString(ip_buff));
        listwidget->addItem( QString( ip_buff));
    }
}
