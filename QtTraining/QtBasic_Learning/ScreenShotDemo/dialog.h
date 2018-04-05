#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <QPixmap>
#include <QDesktopWidget>

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    void shotScreen();

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QPushButton *shot;
    QLabel *s;
    QPixmap *pixmap;

    QHBoxLayout *layout;
};

#endif // DIALOG_H
