#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel( QObject *parent = 0);
    ~TableModel();

	void test_init()
	{
		for(int i = 0; i < row_max; ++i)
		{
			for(int j = 0; j < column_max; ++j)
				s[i][j] = i + j;
		}
	}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	// set data to view
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	// set data's header to view
	QVariant headerData( int section, Qt::Orientation orientation, int role) const override;

	void set_data(int x, int y, int value);
	void update_data(); // update all
	void update_data( const QModelIndex &pos); // update singal point

private:
	const static int column_max = 5;
	const static int row_max = 8;
	int s[row_max][column_max];

};

//----------------------------------------------
#endif
