#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model_dir = new QDirModel(this);
    model_dir->setSorting( QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    model_dir->setReadOnly(false);

    ui->treeView->setModel( model_dir );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    // add a dir
    // name input from linedit
    QString dir_name = ui->lineEdit->text();
    if( dir_name.isEmpty())
        return;
    else
    {
        QModelIndex index_current = ui->treeView->currentIndex();
        if( index_current.isValid())
            this->model_dir->mkdir( index_current, dir_name );
    }
}

void Dialog::on_pushButton_2_clicked()
{
    // remove a dir
    // remove selected dir
    QModelIndex index_current = ui->treeView->currentIndex();
    if( index_current.isValid())
    {

        if( model_dir->fileInfo( index_current ).isDir())
        {
            // remove dir
            this->model_dir->rmdir( index_current );
        }
        else if( model_dir->fileInfo( index_current ).isFile())
        {
            // remove file
            this->model_dir->remove( index_current );
        }
    }
}
