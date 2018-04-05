#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toucharea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void getMousePos(double x, double y);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    TouchArea *toucharea;
};

#endif // MAINWINDOW_H
