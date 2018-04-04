#ifndef NUMBUTTON_H
#define NUMBUTTON_H

#include <QPushButton>

class NumButton : public QPushButton
{
    Q_OBJECT
signals:
    void clickID(int k);
public slots:
    void sendClickID();
public:
    NumButton(QWidget *parent = 0);
    ~NumButton();

    void setVal(const int k);
    int getVal();

private:
    int val;
};

#endif // NUMBUTTON_H
