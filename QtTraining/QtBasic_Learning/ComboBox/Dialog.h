#ifndef Dialog_Head
#define Dialog_Head

#include <QDialog>

#include <QComboBox>
#include <QPushButton>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QMessageBox>

class Dialog : public QDialog
{
	Q_OBJECT
	signals:

	public slots:
        void Button_onClicked();
	public:

	Dialog(QWidget *parent = 0);
	~Dialog();

    QComboBox cb;
    QPushButton button;

    QGridLayout layout;
};

#endif
