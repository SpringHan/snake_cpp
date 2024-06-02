#include "mainwindow.hpp"

#include "src/control_line/control_line.hpp"
#include "src/game_tables/game_tables.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowTitle("Snake game");
	main_widget = new QWidget(this);
	whole = new QVBoxLayout;

	control_line = new ControlLine;

	// Game blocks
	blocks = new GameBlocks;

	// Whole Vertical layout
	whole->addWidget(control_line);
	whole->addWidget(blocks);

	main_widget->setLayout(whole);
	this->setCentralWidget(main_widget);
}

MainWindow::~MainWindow() {}
