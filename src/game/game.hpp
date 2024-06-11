// Basic classes for snake.
#ifndef _GAME_H_
#define _GAME_H_

#include "qobject.h"
#include "qobjectdefs.h"

#include "./food.hpp"
#include "./snake.hpp"
#include "qtimer.h"

#include <chrono>
#include <string>

#include <QObject>
#include <QTimer>

#define TOTAL_BLOCKS 25 * 15

// Map
class Map
{
	short blocks[TOTAL_BLOCKS];
public:
  Map() { this->reset(); }

	void reset();

	~Map() {}
};


// Game
using namespace std::chrono;

class Game: public QObject
{
	Q_OBJECT

private:
	Map blocks;
	Food food;
	Snake *snake;

	int score;

	time_point<system_clock> start_time;
	int stored_time;

	bool paused;
	QTimer timer;

public:
  Game(QObject *parent = nullptr);
	~Game() {}

	int getScore() const;

	// Time
	void initTime();
	int playTime();

	// General
	void startGame();
	void pauseGame();
	void continueGame();
	void finishGame();

	void changeDirection(MoveDirection direction);
};

// Utils
std::string time_format(int);

#endif
