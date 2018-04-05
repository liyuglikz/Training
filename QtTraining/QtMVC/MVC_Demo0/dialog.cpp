#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QStringListModel(this); // init string list model
    list << "cat" << "dog" << "fish";// init list
    model->setStringList( list ); // connect data(string list) & model

    ui->listView->setModel( model ); // set model
    ui->listView->setEditTriggers( QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

    ui->comboBox->setModel( model ); // set model

}

Dialog::~Dialog()
{
    delete ui;
}

/* Button's slots */

void Dialog::on_pushButton_clicked()
{
    // Add
    // Add a item at the end ( just modify the model);
    int row = model->rowCount();
    model->insertRow( row );
    QModelIndex index_current = model->index( row );
    ui->listView->setCurrentIndex( index_current);
    ui->listView->edit(index_current);
}

void Dialog::on_pushButton_2_clicked()
{
    // Edit
    // Edit string on model
    QModelIndex index_current = ui->listView->currentIndex();
    ui->listView->edit( index_current );
}

void Dialog::on_pushButton_3_clicked()
{
    // Delete
    // Delete a element on model
    int row = ui->listView->currentIndex().row();
    model->removeRow( row );
}
