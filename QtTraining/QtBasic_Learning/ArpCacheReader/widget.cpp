#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout_main = new QVBoxLayout();
    arpreader = new ArpCacheReaderLinux();

    layout_main->addWidget( arpreader);
    arpreader->sendArp();

    this->setLayout( layout_main);
}

Widget::~Widget()
{
    delete arpreader;
    delete layout_main;
}
