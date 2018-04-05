#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>

#include "filter.h"

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    // 事件过滤器
    bool eventFilter(QObject *, QEvent *);

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:

    QLabel *l;
    QLayout *layout;

    Filter f;
};

#endif // DIALOG_H
