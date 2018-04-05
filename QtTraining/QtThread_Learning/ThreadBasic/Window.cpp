#include "Window.h"

Window::Window( QMainWindow *parent) : QMainWindow( parent )
{ 
	splitter_main = new QSplitter();

	for(int i = 0; i < cnt; ++i)
		splitter_main->addWidget( &w[i] );

	this->setCentralWidget( splitter_main );
}

Window::~Window()
{
	delete splitter_main;
}
