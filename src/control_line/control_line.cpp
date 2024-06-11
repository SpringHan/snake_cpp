#include "./control_line.hpp"
#include "../../mainwindow.hpp"
#include "../game/game.hpp"

#include "qboxlayout.h"
#include "qmainwindow.h"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
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

	connect(start_btn, &QPushButton::clicked, this, [this]() {
		this->parentWidget()->parentWidget()->findChild<Game*>()->startGame();
	});

	// connect(start_btn, &QPushButton::clicked, this, [this]() {
	// 	this->parentWidget()->findChild<GameBlocks*>()->changeItemColor(0, Qt::red);
	// });
}
