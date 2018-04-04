#include "Dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{

}

Dialog::Dialog() : QDialog(NULL)
{
	n = 8;
	for(int i = 0; i < n; ++i)
	{
		cb[i] = new QCheckBox();
		vLayout.addWidget( cb[i] );
	}

	this->setLayout( &vLayout );
}

Dialog::~Dialog()
{
	for(int i = 0; i < n; ++i)
	{
		free( cb[i] );
	}
}
