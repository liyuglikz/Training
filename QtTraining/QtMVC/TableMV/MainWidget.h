#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "TableModel.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

signals:
    void signal_updateCellData(int x, int y, int value);

public slots:
    void slot_deployUpdateSignal();

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    void initLayout();
    void initSignalSlots();

    Ui::MainWidget *ui;
	TableModel *table_model;
};

#endif // MAINWIDGET_H
