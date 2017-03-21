#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

#include <QPainter>
#include <QPen>

#include <QKeyEvent>
#include <QVector>

#include <QLine>
#include <QPoint>

#include <QTime>
#include <QTimer>

#include <QDebug>

class Dialog : public QDialog
{
    Q_OBJECT

signals:
public slots:
    void run();
public:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *e);
    void sleep(int k);

    Dialog(QWidget *parent = 0);
    ~Dialog();


private:
    QPoint now, last;
    int dirctor;
    QVector<QLine> lib;

    QVBoxLayout lay;
    QPushButton start;
};

#endif // DIALOG_H
