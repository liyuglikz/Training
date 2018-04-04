#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSplitter>

#include "Widget.h"

class Window : public QMainWindow
{
	Q_OBJECT
	signals:
	public slots:
	public:
		explicit Window( QMainWindow *parent = 0);
		~Window();

	private:

		Widget *s;
		QSplitter *splitter_main;

		static const int cnt = 5;
		Widget w[ cnt ];
};

#endif
