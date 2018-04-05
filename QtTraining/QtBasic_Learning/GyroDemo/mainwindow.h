#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GyroScopeArea.h"
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void getData(double x, double y, double z);
    void switch_button();

public:
    MainWindow(QWidget *parent = 0);
private:
    GyroScopeArea *g;
    QPushButton *button;
    bool flag = false;
};

#endif // MAINWINDOW_H
