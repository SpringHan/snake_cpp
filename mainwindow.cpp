#include "mainwindow.hpp"

#include "qnamespace.h"
#include "qsize.h"
#include "qwidget.h"

#include "src/control_line/control_line.hpp"
#include "src/game/game.hpp"
#include "src/game/snake.hpp"
#include "src/game_blocks/game_blocks.hpp"

// TODO: Debug, remove this line.
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowTitle("Snake game");
	this->setObjectName("TEst");

	main_widget = new QWidget(this);
	whole = new QVBoxLayout;
	whole->setMargin(0);

	// Game
	game = new Game(this);

	// Control Line
	control_line = new ControlLine;

	// Game blocks
	blocks = new GameBlocks;

	// Whole Vertical layout
	whole->addWidget(control_line, 0, Qt::AlignTop);
	whole->addWidget(blocks, 1, Qt::AlignTop);

	main_widget->setLayout(whole);
	this->setCentralWidget(main_widget);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
	blocks->resetSize(this->size());
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
	case Qt::Key_Up:
		game->changeDirection(MoveDirection::Up);
		break;
	case Qt::Key_Down:
		game->changeDirection(MoveDirection::Down);
		break;
	case Qt::Key_Left:
		game->changeDirection(MoveDirection::Left);
		break;
	case Qt::Key_Right:
		game->changeDirection(MoveDirection::Right);
		break;
	default:
		return;
	}
}

MainWindow::~MainWindow() {}
