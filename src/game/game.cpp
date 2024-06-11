#include "game.hpp"

#include "qobject.h"
#include "qobjectdefs.h"
#include "snake.hpp"

#include <chrono>

#include <string>
#include <sstream>

// TODO: Remove
#include <iostream>

// Map
void Map::reset() {
	for (short &x : this->blocks) {
		x = 0;
	}
}

// Game
Game::Game(QObject *parent): QObject(parent) {
	snake = new Snake(this);

	stored_time = 0;
	paused = true;
	// TODO: Start timer.
}

void Game::startGame() {
	paused = false;
	snake->paintInitialBlocks();
	connect(&timer, SIGNAL(timeout()), snake, SLOT(advance()));
	timer.start(900);
}

void Game::pauseGame() {
	stored_time += this->playTime();
	paused = true;
}

void Game::continueGame() {
	this->initTime();
}

void Game::finishGame() {
}

void Game::initTime() {
	start_time = std::chrono::system_clock::now();
}

// Return the duration in seconds.
int Game::playTime() {
	using namespace std::chrono;

	time_point<system_clock> end_time = system_clock::now();
	duration<double> duration_time = end_time - this->start_time;

	return (int) duration_time.count();
}

void Game::changeDirection(MoveDirection direction) {
	if (paused) {
		return;
	}

	int origin = snake->direction;
	int modify_to = direction;

	if (origin == modify_to || origin == -modify_to) {
		return;
	}

	snake->direction = direction;
}

// Utils
std::string time_format(int time) {
	int hour = 0, minute = 0, second = time;
	float over = (float)time / 60;
	int temp;

	if (over >= 1) {
		temp = (int)over;
		second -= temp * 60;
		minute += temp;
	}

	over = (float)minute / 60;

	if (over >= 1) {
		temp = (int)over;
		minute -= temp * 60;
		hour += temp;
	}

	std::stringstream ss;

	ss << hour << "小时" << minute << "分钟" << second << "秒";

	return ss.str();
}
