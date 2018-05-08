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

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
	TableModel *table_model;
};

#endif // MAINWIDGET_H
