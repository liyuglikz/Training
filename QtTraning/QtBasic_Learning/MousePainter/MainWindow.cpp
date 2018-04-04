#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(QSize(32, 32));

    this->createActions();
    this->createMenus();

	paint_area = new PaintArea();
	this->setCentralWidget( paint_area );
}

MainWindow::~MainWindow()
{
    delete action_fileopen;
    delete action_filesave;
    delete action_filesaveas;

    delete file;
    delete options;

	delete paint_area;
}

void MainWindow::createActions()
{
    action_fileopen = new QAction(tr("open"), this);
    action_filesave = new QAction(tr("save"), this);
    action_filesaveas = new QAction(tr("save as"), this);

    action_fileopen->setShortcut(tr("Ctrl+O"));
    action_filesave->setShortcut(tr("Ctrl+S"));
}

void MainWindow::createMenus()
{
    file = new QMenu(tr("File"), this);
    options = new QMenu(tr("Options"), this);

 //   file = new QMenu(this);
//    options = new QMenu(this);
//    file->setTitle(tr("File"));
//    options->setTitle(tr("Options"));

    file->addAction(action_fileopen);
    file->addAction(action_filesave);
    file->addAction(action_filesaveas);

    (this->menuBar())->addMenu( file );
    this->menuBar()->addMenu( options );
}
