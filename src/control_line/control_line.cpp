#include "./control_line.hpp"
#include "../game/game.hpp"

#include <sstream>

ControlLine::ControlLine(QWidget *parent)
	:QWidget(parent)
{
	main_layout = new QHBoxLayout;

	start_btn = new QPushButton("开始");
	pause_btn = new QPushButton("暂停");
	start_btn->setFocusPolicy(Qt::NoFocus);
	pause_btn->setFocusPolicy(Qt::NoFocus);

	score = new QLabel;
	time = new QLabel;
	score->setText("得分: 0");
	time->setText("时间: ");
	time->setVisible(false);

	main_layout->addWidget(start_btn, 0, Qt::AlignLeft);
	main_layout->addWidget(score, 0, Qt::AlignCenter);
	main_layout->addWidget(time, 0, Qt::AlignCenter);
	main_layout->addWidget(pause_btn, 0, Qt::AlignRight);
	
	this->setLayout(main_layout);

	connect(start_btn, SIGNAL(clicked()), this, SLOT(startBtnFunc()));
	connect(pause_btn, &QPushButton::clicked, this, [this]() {
		this->pauseBtnFunc();
	});
}

void ControlLine::changeScore(int score) {
	std::stringstream text;
	text << "得分: " << score;

	this->score->setText(QString::fromStdString(text.str()));
}

void ControlLine::changeTime(std::string time) {
	std::stringstream text;
	text << "时间: " << time;

	this->time->setText(QString::fromStdString(text.str()));
	showTime(true);
}

void ControlLine::showTime(bool show) {
	time->setVisible(show);
}

void ControlLine::startBtnFunc() {
	start_btn->setText("重开");
	pause_btn->setText("暂停");
	this->parentWidget()->parentWidget()->findChild<Game*>()->startGame();
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
