#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QLabel>
#include <QPixmap>

#include <QHBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:

    QPixmap *pm;
    QLabel *l;
    QLabel l2;
    QHBoxLayout *layout;
};

#endif // DIALOG_H
