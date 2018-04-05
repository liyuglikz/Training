#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

#include <QScrollArea>
#include <QScrollBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVBoxLayout *layout;
    QScrollArea sa;
    QScrollBar sb;

    QPixmap pixmap;
    QLabel label;
};

#endif // MAINWINDOW_H
