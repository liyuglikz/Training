#ifndef MAINWINDOW
#define MAINWINDOW

#include <QWidget>
#include <QMainWindow>

#include <QVBoxLayout>
#include <QSlider>
#include <QProgressBar>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:

private:

    QWidget *w;
    QVBoxLayout *layout;

    QSlider *q;
    QProgressBar *pb;
};

#endif
