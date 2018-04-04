#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QApplication>
#include <QDesktopWidget>

#include <QPixmap>
#include <QLabel>
#include <QPushButton>

#include <QGridLayout>
#include <QVBoxLayout>

#include <QTimer>

//#include <QApplication>
//#include <QDesktopWidget>

class MainWindow : public QDialog
{
    Q_OBJECT

signals:
    void deployShot(QPixmap pixmap);

public slots:
    void startV();
    void pauseV();
    void screenShot()
    {
        *(this->pixmap) = QPixmap::grabWindow(
                    QApplication::desktop()->winId());
        emit deployShot( *pixmap );

        this->viwer->setPixmap(
            pixmap->scaled(QSize(800, 450)));
    }

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    int f_time;

    QVBoxLayout *layout;
    QPushButton *startButton;
    QPushButton *pauseButton;

    QPixmap *pixmap;
    QLabel *viwer;

    QTimer t;
    bool flag;
};

#endif // MAINWINDOW_H
