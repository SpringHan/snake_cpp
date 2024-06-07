#include "game.hpp"
#include "qobject.h"

#include <chrono>

#include <string>
#include <sstream>

// Map
void Map::reset() {
	for (short &x : this->blocks) {
		x = 0;
	}
}

// Game
Game::Game(QObject *parent): QObject(parent) {
	stored_time = 0;
}

void Game::pauseGame() {
	stored_time += this->playTime();
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
