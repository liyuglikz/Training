#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    layout = new QVBoxLayout();
    p = new QInputDialog();

    n = 6;

    // init buttons
    for(int i = 0; i < n; ++i)
    {
        layout -> addWidget( s + i );
    }
    s[0].setText("Input Dialog");
    connect(s, SIGNAL(clicked()), this, SLOT(pop_inputdialog()));

    this->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete p;
    delete layout;
}

void MainWindow::pop_inputdialog()
{
    p->show();
}
