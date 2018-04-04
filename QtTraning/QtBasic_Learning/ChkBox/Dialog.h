#ifndef Dialog_Head
#define Dialog_Head

#include <QDialog>

#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Dialog : public QDialog
{
    static const int N = 32;

	Q_OBJECT
signals:
public slots:
public:
    Dialog(QWidget *parent);
    Dialog();
	~Dialog();

private:
    QCheckBox *(cb[N]);
    int n;

	QHBoxLayout hLayout;
	QVBoxLayout vLayout;
};

#endif
