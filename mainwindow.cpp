#include "mainwindow.hpp"
#include "qlabel.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	button = new QPushButton("Text", this);
	temp_text = new QLabel("Text", this);
	temp_text->setGeometry(200, 200, 100, 30);
	// button->setGeometry(10, 10, 80, 30);

	// QObject::connect(button, SIGNAL(click()), );
}

MainWindow::~MainWindow() {}
