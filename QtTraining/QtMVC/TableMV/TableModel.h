#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

const static int Table_Column_max = 5;
const static int Table_Row_max = 8;

// table data struct
class TableData
{
	public:
	int array[Table_Row_max][Table_Column_max];
};

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public slots:
    void slot_setData(int x, int y, int value);

public:
    explicit TableModel( QObject *parent = 0);
    ~TableModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	// data to view
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	// data's header 
	QVariant headerData( int section, Qt::Orientation orientation, int role) const override;

	// set data
	void setData(int x, int y, int value);

	// update data view
	void updateView(); // update all
	void updateView( const QModelIndex &pos); // update singal point

private:
	// inits:
	void initTableData();

	TableData *table_data;
    QStringList *headers;
};

//----------------------------------------------
#endif
