#include "TableModel.h"

TableModel::TableModel( QObject *parent ) : QAbstractTableModel( parent )
{
	this->test_init();
}

TableModel::~TableModel()
{

}

int TableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return TableModel::row_max;
}

int TableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return TableModel::column_max;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
	   return s[index.row()][index.column()];
    }
    return QVariant();
}

QVariant TableModel::headerData( int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("A");
            case 1:
                return QString("B");
            case 2:
                return QString("C");
			default:
				return QString( "section: ") + QString::number( section );
            }
        }
    }
    return QVariant();
}

void TableModel::set_data( int x, int y, int value)
{
	this->s[x][y] = value;
	this->update_data();
}

void TableModel::update_data()
{
	QModelIndex topLeft = createIndex(0, 0);
	QModelIndex bottomRight = createIndex( row_max - 1, column_max - 1);
	emit dataChanged( topLeft, bottomRight);
}

void TableModel::update_data( const QModelIndex &pos)
{
	emit dataChanged( pos, pos);
}

//-------------------------------------------------------------
