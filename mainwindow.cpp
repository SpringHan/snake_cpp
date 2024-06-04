#include "mainwindow.hpp"

#include "qnamespace.h"
#include "qsize.h"

#include "qwidget.h"
#include "src/control_line/control_line.hpp"
#include "src/game_blocks/game_blocks.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowTitle("Snake game");
	main_widget = new QWidget(this);
	whole = new QVBoxLayout;

	// Control Line
	control_line = new ControlLine;

	// Game blocks
	blocks = new GameBlocks;

	// Whole Vertical layout
	whole->addWidget(control_line, 0, Qt::AlignTop);
	whole->addWidget(blocks, 1);

	main_widget->setLayout(whole);
	this->setCentralWidget(main_widget);
}

void MainWindow::initControlLine() {}

void MainWindow::initGameTables() {}

void MainWindow::resizeEvent(QResizeEvent *event) {
	blocks->setMaximumSize(this->size().width(), this->size().height() * 0.7);
}

MainWindow::~MainWindow() {}
