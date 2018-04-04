#ifndef _HEAD_MAINWINDOW_
#define _HEAD_MAINWINDOW_

#include <QDialog>
#include <QVBoxLayout>
#include "PaintWidget.h"

class MainWindow : public QDialog
{
	Q_OBJECT
	public:
		MainWindow( QWidget *parent = 0);
		~MainWindow();

    private:
        PaintWidget pw;
        QVBoxLayout layout;
};

#endif
