#ifndef Widget_H
#define Widget_H

#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "Thread.h"

class Widget : public QWidget
{
	Q_OBJECT
	signals:
	public slots:
		void slot_start();
		void slot_pause();
		void slot_set_num(int k);

	public:
		explicit Widget( QWidget *parent = 0);
		~Widget();

	private:

		void init_memory_alloc();
		void init_layout();
		void init_signals_slots();

		QVBoxLayout *layout_main;
		QPushButton *button_start;
		QPushButton *button_pause;
		QLabel *label_num;

		Thread *thread_1;
};

#endif
