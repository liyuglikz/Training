#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    start.setText("Start");
    lay.addWidget( &start );
    connect(&start, SIGNAL(clicked(bool)), this, SLOT(run()));

    //this->setLayout(&lay);

    now.setX(0);
    now.setY(0);
    last.setX(0);
    last.setY(0);
    //this->setFocusPolicy(Qt::StrongFocus);
    dirctor = 0;
}

Dialog::~Dialog()
{

}

void Dialog::paintEvent(QPaintEvent *event)
{
    if(event == NULL)
        return;

    QPainter painter(this);
    QPen pen;

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(5);

    painter.setPen(pen);
    //painter.drawLine(last, now);

    unsigned int count = (unsigned int)lib.size();
    for(unsigned int i = 0; i < count; ++i)
        painter.drawLine( lib[i].p1(), lib[i].p2());

    painter.end();
    last = now;
}

void Dialog::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_D)
        dirctor = 0;
    else if(e->key() == Qt::Key_A)
        dirctor = 1;
    else if(e->key() == Qt::Key_W)
        dirctor = 2;
    else if(e->key() == Qt::Key_S)
        dirctor = 3;

    update();
}

void Dialog::run()
{
    this->resize(QSize(640, 400));
    lay.removeWidget(&start);
    start.deleteLater();

    update();

    while(1)
    {
        switch(dirctor)
        {
        case 0:
        now.setX(last.x() + 10);
            break;
        case 1:
        now.setX(last.x() - 10);
            break;
        case 2:
        now.setY(last.y() - 10);
            break;
        case 3:
        now.setY(last.y() + 10);
            break;
            default:break;
        }
        lib.push_back( QLine(now, last));
        lib.pop_front();
        update();
        sleep(1000);
    }
}
void inline Dialog::sleep(int k)
{
    QTime n = QTime::currentTime();
    QTime now;
    do{
        now = QTime::currentTime();
    }   while(n.msecsTo(now) <= k);
}
