#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "PaintArea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void createMenus();

//private:
public:

	PaintArea *paint_area;

    QMenu *file;
    QMenu *options;

    QAction *action_fileopen;
    QAction *action_filesave;
    QAction *action_filesaveas;
};

#endif // MAINWINDOW_H
