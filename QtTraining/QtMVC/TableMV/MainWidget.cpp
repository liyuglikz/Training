#include "MainWidget.h"
#include "ui_MainWidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->table_model = new TableModel();
    this->table_model->insertColumns(0, 3);
    this->table_model->insertRows(0, 3);
    this->ui->tableView->setModel( table_model);
}

MainWidget::~MainWidget()
{
    delete ui;
}
