#include "mainwindow.hpp"
#include "qboxlayout.h"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qtableview.h"

#include <QPushButton>
#include <QTableView>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowTitle("Snake game");

	// Controller layout
	start_btn = new QPushButton("开始");
	pause_btn = new QPushButton("暂停");

	control_line = new QHBoxLayout;
	control_line->addWidget(start_btn, 0, Qt::Alignment().setFlag(Qt::AlignLeft));
	control_line->addWidget(pause_btn, 1, Qt::Alignment().setFlag(Qt::AlignRight));

	// Game blocks
	blocks_table = new QTableView;

	// Whole Vertical layout
	whole = new QVBoxLayout;
	whole->addLayout(control_line);
	whole->addWidget(blocks_table);

	main_widget = new QWidget(this);
	main_widget->setLayout(whole);
	this->setCentralWidget(main_widget);
}

MainWindow::~MainWindow() {}
