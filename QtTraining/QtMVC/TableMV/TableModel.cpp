#include "TableModel.h"
#include <QDebug>

// init class TableModel
TableModel::TableModel( QObject *parent ) : QAbstractTableModel( parent )
{
	this->initTableData();
}

void TableModel::initTableData()
{
    this->headers = new QStringList();
    this->headers->append( "A");
    this->table_data = new TableData();
}


// del TalbeModel
TableModel::~TableModel()
{
    if(this->table_data)
        delete this->table_data;
    if(this->headers)
        delete this->headers;
}



// get table's row count
int TableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return Table_Row_max;
}

// get table's column count
int TableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return Table_Column_max;
}

// get table's data to view
QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
	   return this->table_data->array[index.row()][index.column()];
    }
    return QVariant();
}

// get table's header
QVariant TableModel::headerData( int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            if( this->headers->size() > section)
            {
                return this->headers->at(section);
            }
			return QString( "section: ") + QString::number( section );
        }
    }
    return QVariant();
}

// set Data:
void TableModel::setData( int x, int y, int value)
{
	this->table_data->array[x][y] = value;
    // update cell debug:
    //qDebug() << "Debug Point:" << this->table_data->array[x][y];
	this->updateView();
}

void TableModel::updateView()
{
	QModelIndex topLeft = this->createIndex(0, 0);
	QModelIndex bottomRight = this->createIndex( this->rowCount()- 1, this->columnCount() - 1);
	emit dataChanged( topLeft, bottomRight);
}

void TableModel::updateView( const QModelIndex &pos)
{
	emit dataChanged( pos, pos);
}

//-------------------------------------------------------------
//
//------------------------------------------------------------

//------------------------------------------
// slots:

void TableModel::slot_setData( int x, int y, int value)
{
    this->setData(x, y, value);
}
