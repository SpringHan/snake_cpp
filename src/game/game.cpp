#include "game.hpp"
#include "../control_line/control_line.hpp"

#include <chrono>

#include <string>
#include <sstream>

#define REFRESH_TIME 350

// Game
Game::Game(QObject *parent): QObject(parent) {
	snake = new Snake(this);
	food = new Food(this);

	score = 0;
	stored_time = 0;
	paused = true;
	initialized = false;
}

void Game::startGame() {
	paused = false;

	if (initialized) {
		stored_time = 0;
		score = 0;

		snake->initBlocks();
		snake->paintInitialBlocks();
		food->removeFood();
		food->newFood();

		initTime();
		timer.start(REFRESH_TIME);

		ControlLine *controller = this->parent()->findChild<ControlLine*>();
		controller->changeScore(0);
		controller->showTime(false);
		return;
	}

	initialized = true;

	snake->initBlocks();
	snake->paintInitialBlocks();
	food->newFood();
	connect(&timer, SIGNAL(timeout()), snake, SLOT(advance()));

	initTime();
	timer.start(REFRESH_TIME);
}

void Game::pauseGame() {
	if (!initialized) {
		return;
	}

	stored_time += this->playTime();
	paused = true;
	timer.stop();

	this->parent()
		->findChild<ControlLine*>()
		->changeTime(time_format(stored_time));
}

void Game::continueGame() {
	if (!initialized) {
		return;
	}

	paused = false;
	this->initTime();
	timer.start(REFRESH_TIME);

	this->parent()->findChild<ControlLine*>()->showTime(false);
}

void Game::addScore() {
	score += food->getScore();

	this->parent()->findChild<ControlLine*>()->changeScore(score);
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

	snake->mtx.lock();

	snake->next_to.push_back(direction);

	snake->mtx.unlock();
}

bool Game::gamePaused() const {
	return paused;
}

bool Game::gameInitialized() const {
	return initialized;
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

	ss << hour << ":" << minute << ":" << second;

	return ss.str();
}
