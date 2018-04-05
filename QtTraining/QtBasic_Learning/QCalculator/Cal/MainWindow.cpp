#include "MainWindow.h"

MainWindow::MainWindow( QWidget *parent):QDialog(parent)
{
    // 1. Init Window
    //this->resize(QSize(640, 400));
    this->setWindowTitle("Tiny Calculator");
    //this->setMinimumSize(200, 320);

    // 2. Allocate xxx
    layout = new QGridLayout();
    screen = new QLineEdit();

    // 3. set them

        //a. init numbers
    this->x = 0;
    this->y = 0;
    this->ans = 0;

        //b. init screen
    screen->setText( QString::number(ans));
    layout->addWidget(screen, 0, 0, 1, 4);

        //c. init number buttons
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int t = i * 3 + j;
            keys_num[t + 1].setVal(t + 1);
            keys_num[t + 1].setText(QString::number(t + 1));
            layout->addWidget(keys_num + t + 1, i + 1, j);
            connect(keys_num + t + 1, SIGNAL(clickID(int)), this, SLOT(pushNumButton(int)));
        }
    }
    keys_num->setText("0");
    connect(keys_num, SIGNAL(clickID(int)), this, SLOT(pushNumButton(int)));
    layout->addWidget(keys_num, 4, 1);

        //////////////////////////
        //d. init opeartor buttons
    keys_op[0].setText("+");
    keys_op[1].setText("-");
    keys_op[2].setText("*");
    keys_op[3].setText("/");

    keys_op[0].setVal((int)'+');
    keys_op[1].setVal((int)'-');
    keys_op[2].setVal((int)'*');
    keys_op[3].setVal((int)'/');

    for(int i = 0; i < 4; ++i)
    {
        connect(keys_op + i, SIGNAL(clickID(int)), this, SLOT(setOperator(int)));
        layout->addWidget(keys_op + i, i + 1, 5);
    }

        /////////////////////////
        //e. init control buttons
    keys_ctrl[0].setText("Clear");
    keys_ctrl[2].setText("=");
    layout->addWidget(keys_ctrl + 0, 4, 0);
    layout->addWidget(keys_ctrl + 2, 4, 2);

    connect(keys_ctrl, SIGNAL(clicked()), this, SLOT(initScreen()));
    connect(keys_ctrl + 2, SIGNAL(clicked()), this, SLOT(getAns()));

//    layout->setSpacing(5);
    this->setLayout( layout );
}


MainWindow::~MainWindow()
{
    delete layout;
}

void MainWindow::pushNumButton(int id)
{
    ans = ans * 10 + id;
    this->screen->setText(QString::number( ans ));
}

void MainWindow::setOperator(int id)
{
    x = ans;
    ans = 0;
    screen->setText(QString::number(ans));
    _operator = (char)id;
}

void MainWindow::initScreen()
{
    x = y = ans = 0;
    screen->setText("0");
}

void MainWindow::getAns()
{
    y = ans;
    ans = 0;
    switch(_operator)
    {
        case '+':
        ans = x + y;
        break;
        case '-':
        ans = x - y;
        break;
        case '*':
        ans = x * y;
        break;
        case '/':
        ans = x / y;
        break;
    default: ans = 0; break;
    }
    screen->setText(QString::number(ans));
}
