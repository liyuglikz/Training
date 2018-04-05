Qt MVD(MVC) Model-View-Delegate work like:

[Simple Template:]
	// Data with Model
	QXxxModel * model = new QXxxModel();
	Qxxx *data = new QXxx();
	model->setXxx( *data );

	// Model with View
	Q****View view;
	view.setModel( model );
	ui->xxxView->setModel( model );

[Example:]

	// Data with Model
	QStringListModel *model = new QStringListModel( this );
	QStringList list;
	list << "Str1" << "Str2" << "Str3";
	model->setStringList( list );

	// Model with View
	ui->listView->setModel( model );
	ui->listView->setEditTriggers( QAbstractItemView::AnyKeyPressed | AbstractItemView::DoubleClicked);

	ui->comboBox->setModel( model );

