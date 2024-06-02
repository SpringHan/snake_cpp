// Basic classes for snake.
#ifndef _GAME_H_
#define _GAME_H_

#include "food.hpp"

#include <vector>
#include <chrono>
#include <string>

#define TOTAL_BLOCKS 28 * 18
#define INITIAL_POS 9 * 18 + 8

class Map
{
	short blocks[TOTAL_BLOCKS];
public:
  Map() { this->reset(); }

	void reset();

	~Map() {}
};

class Snake
{
	unsigned int length;
	std::vector<int> blocks;
public:
  Snake(): length(1) {
		this->blocks.push_back(INITIAL_POS);
	}

	~Snake() {}

	unsigned int getLength() const {
		return length;
	}

	void update();
};

using namespace std::chrono;

class Game
{
	Map blocks;
	Snake snake;

	int score;

	time_point<system_clock> start_time;
	int stored_time;
public:
  Game(): stored_time(0) {}
	~Game() {}

	int getScore() const;

	// General
	void pauseGame();
	void continueGame();
	void finishGame();

	// Time
	void initTime();
	int playTime();
};

// Utils
std::string time_format(int);

#endif
