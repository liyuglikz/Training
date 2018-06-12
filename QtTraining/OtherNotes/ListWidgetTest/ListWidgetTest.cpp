#include "ListWidgetTest.h"
#include "ui_ListWidgetTest.h"
#include <QDebug>

ListWidgetTest::ListWidgetTest(QWidget* parent)
    : QWidget(parent), ui(new Ui::ListWidgetTest)
{
    ui->setupUi(this);

    for (int i = 0; i < 5; ++i) {
        QListWidgetItem* item = new QListWidgetItem(QString("Item %1").arg(i));
        ui->listWidget->addItem(item);
    }

	/*
	//----code 0:
	//issue: in selection changed slot, count is still 5
    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(clearList()));

    QObject::connect(ui->listWidget, SIGNAL(itemSelectionChanged()),
                     this, SLOT(selectionChanged()));

	//----code 1:
	//issue: in selection changed slot, count is still 5
    connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(clearList()), Qt::QueuedConnection);

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()),
                     this, SLOT(selectionChanged()));

	*/
	//----code 2:
	//now is correct:(Qt信号时序问题，使用Qt::QueuedConnection解决)
    connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(clearList()), Qt::QueuedConnection);

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()),
                     this, SLOT(selectionChanged()), Qt::QueuedConnection);
}

ListWidgetTest::~ListWidgetTest()
{
    delete ui;
}

void ListWidgetTest::clearList()
{
    qDebug() << "void ListWidgetTest::clearList()";
    ui->listWidget->clear();
    qDebug() << "clearList: ui->listWidget->count() is " << ui->listWidget->count();
}

void ListWidgetTest::selectionChanged()
{
    qDebug() << "void ListWidgetTest::selectionChanged()";
    qDebug() << "selectionChanged: ui->listWidget->count() is " << ui->listWidget->count();
}
