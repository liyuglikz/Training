#include "numbutton.h"

void NumButton::sendClickID()
{
    emit clickID(this->getVal());
}

NumButton::NumButton(QWidget *parent) : QPushButton(parent)
{
    this->val = 0;
    connect(this, SIGNAL(clicked()), this, SLOT(sendClickID()));
}

NumButton::~NumButton()
{

}

void NumButton::setVal(const int k)
{
    this->val = k;
}

int NumButton::getVal()
{
    return this->val;
}
