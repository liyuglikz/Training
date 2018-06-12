#ifndef LISTWIDGETTEST_H
#define LISTWIDGETTEST_H

#include <QWidget>

namespace Ui {
class ListWidgetTest;
}

class ListWidgetTest : public QWidget
{
    Q_OBJECT
public slots:
    void clearList();
    void selectionChanged();

public:
    explicit ListWidgetTest(QWidget *parent = 0);
    ~ListWidgetTest();

private:
    Ui::ListWidgetTest *ui;
};

#endif // LISTWIDGETTEST_H
