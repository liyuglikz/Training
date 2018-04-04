#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QToolButton>

#include <QWidget>
#include <QVBoxLayout>

#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPicture>

#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVBoxLayout *layout;

    QImage *image;
    QPixmap *pixmap;
    QBitmap *bitmap;
    QPicture *pic;

    QLabel label[32];

    QPushButton b1;
    QToolButton b2;
};

#endif // MAINWINDOW_H
