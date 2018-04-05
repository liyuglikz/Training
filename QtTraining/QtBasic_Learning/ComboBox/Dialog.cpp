#include "Dialog.h"

Dialog::Dialog( QWidget *parent) : QDialog(parent)
{
    this->setMaximumSize(QSize(1920, 1080));
    this->setMinimumSize(QSize(640, 400));

    cb.addItem("A", 0);
    cb.addItem("B", 1);
    cb.addItem("C", 2);
    cb.addItem("D", 3);
    button.setText("Click me");

    layout.addWidget ( &cb, 0, 0, 1, 3);
    layout.addWidget ( &button, 0, 3, 1, 1);

    connect(&button, SIGNAL(clicked(bool)), this, SLOT(Button_onClicked()));

    this->setLayout( &layout);
}


Dialog::~Dialog()
{

}

void Dialog::Button_onClicked()
{
    QMessageBox::information(this, "title", "You selected " + cb.currentText());
    //if(cb.currentText() == "C")
    //   QMessageBox::information(this, "title", "You selected \"C\"");
}
