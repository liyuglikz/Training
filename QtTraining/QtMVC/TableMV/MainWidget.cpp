#include "MainWidget.h"
#include "ui_MainWidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->table_model = new TableModel();
    this->table_model->insertColumns(0, 3);
    this->table_model->insertRows(0, 3);
    this->ui->tableView->setModel( table_model);

    this->initSignalSlots();
}

MainWidget::~MainWidget()
{
    delete ui;
    delete this->table_model;
}


void MainWidget::initLayout()
{

}

void MainWidget::initSignalSlots()
{
    connect( this->ui->pushButton_UpdateCellData, SIGNAL(clicked(bool)),
             this, SLOT(slot_deployUpdateSignal()));

    connect( this, SIGNAL(signal_updateCellData(int,int,int)),
             this->table_model, SLOT(slot_setData(int,int,int)));
}


void MainWidget::slot_deployUpdateSignal()
{
    int x = this->ui->spinBox_Column->value();
    int y = this->ui->spinBox_Row->value();
    int value_new = this->ui->spinBox_newData->value();
    emit this->signal_updateCellData(x, y, value_new );
    // update cell debug:
    //    qDebug() << x << y << value_new;
}
