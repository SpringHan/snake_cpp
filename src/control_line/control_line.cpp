#include "./control_line.hpp"
#include "../game/game.hpp"
#include "../game_blocks/game_blocks.hpp"

#include "qboxlayout.h"
#include "qmainwindow.h"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qtablewidget.h"
#include "qwidget.h"

// TODO: Remove this line.
#include <iostream>

ControlLine::ControlLine(QWidget *parent)
	:QWidget(parent)
{
	main_layout = new QHBoxLayout;

	start_btn = new QPushButton("开始");
	pause_btn = new QPushButton("暂停");
	start_btn->setFocusPolicy(Qt::NoFocus);
	pause_btn->setFocusPolicy(Qt::NoFocus);

	main_layout->addWidget(start_btn, 0, Qt::AlignLeft);
	main_layout->addWidget(pause_btn, 1, Qt::AlignRight);
	
	this->setLayout(main_layout);

	connect(start_btn, SIGNAL(clicked()), this, SLOT(startBtnFunc()));
	connect(pause_btn, SIGNAL(clicked()), this, SLOT(pauseBtnFunc()));
}

void ControlLine::startBtnFunc() {
	start_btn->setText("重开");
	pause_btn->setText("暂停");
	this->parentWidget()->parentWidget()->findChild<Game*>()->startGame();

	// TODO: Remove this line.
	// this->parentWidget()->findChild<GameBlocks*>()->changeItemColor(48, Qt::black);
}

void ControlLine::pauseBtnFunc() {
	Game *game = this->parentWidget()->parentWidget()->findChild<Game*>();
	if (!game->gameInitialized()) {
		return;
	}

	if (game->gamePaused()) {
		pause_btn->setText("暂停");
		game->continueGame();
	} else {
		pause_btn->setText("继续");
		game->pauseGame();
	}
}
