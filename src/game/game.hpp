// Basic classes for snake.
#ifndef _GAME_H_
#define _GAME_H_

#include "./food.hpp"
#include "./snake.hpp"

#include <chrono>
#include <string>

#include <QObject>
#include <QTimer>

#define TOTAL_BLOCKS 25 * 15

// Game
using namespace std::chrono;

class Game: public QObject
{
	Q_OBJECT

private:
	Food *food;
	Snake *snake;

	int score;

	time_point<system_clock> start_time;
	int stored_time;

	bool paused;
	bool initialized;
	QTimer timer;

	void adjustDifficulty();

public:
  Game(QObject *parent = nullptr);

	int getScore() const;

	bool gameInitialized() const;
	bool gamePaused() const;

	// Time
	void initTime();
	int playTime();

	// General
	void startGame();
	void pauseGame();
	void continueGame();

	// Score
	void addScore();

	void changeDirection(MoveDirection direction);
};

// Utils
std::string time_format(int);

#endif
