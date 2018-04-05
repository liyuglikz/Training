#ifndef _H_MAINWINDOW_
#define _H_MAINWINDOW_

#include <QDialog>

//#include <QBoxLayout>
#include <QGridLayout>

#include <QPushButton>

#include <QTextEdit>
#include <QLineEdit>

#include "numbutton.h"

class MainWindow : public QDialog
{
	Q_OBJECT
	signals:
	public slots:

    void pushNumButton(int id);
    void setOperator(int id);
    void initScreen();
    void getAns();

	public:

	MainWindow( QWidget *parent = 0);
    ~MainWindow();
	
	private:

    QLineEdit *screen;

    //QBoxLayout *layout;
    QGridLayout *layout;

    NumButton keys_num[10];
    NumButton keys_op[5];
    QPushButton keys_ctrl[5];

    double x, y, ans;
    char _operator;
};

#endif
