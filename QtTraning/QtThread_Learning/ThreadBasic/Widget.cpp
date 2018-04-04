#include "Widget.h"

Widget::Widget( QWidget *parent) : QWidget( parent )
{
	this->init_memory_alloc();
	this->init_signals_slots();
	this->init_layout();
}

void Widget::init_memory_alloc()
{
	layout_main = new QVBoxLayout();
	button_start = new QPushButton("Start");
	button_pause = new QPushButton("Pause");
	label_num = new QLabel("Stopped");

	thread_1 = new Thread();

}

void Widget::init_signals_slots()
{
	connect( this->thread_1, SIGNAL( signal_num(int) ),
			this, SLOT( slot_set_num(int)));

	connect( this->button_start, SIGNAL( clicked(bool)),
			this, SLOT( slot_start()));

	connect( this->button_pause, SIGNAL( clicked(bool)),
			this, SLOT( slot_pause()));

}

void Widget::init_layout()
{
	layout_main->addWidget( label_num );
	layout_main->addWidget( button_start );
	layout_main->addWidget( button_pause );

	this->setLayout( layout_main);
}

Widget::~Widget()
{
	delete layout_main;
	delete button_start;
	delete button_pause;
	delete label_num;
}

void Widget::slot_start()
{
	this->thread_1->flag = false;
	this->thread_1->start();
}

void Widget::slot_pause()
{
	this->thread_1->flag = true;
}

void Widget::slot_set_num(int k)
{
	this->label_num->setNum( k );
}
