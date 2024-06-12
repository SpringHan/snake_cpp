#include "food.hpp"
#include "./game.hpp"
#include "./snake.hpp"
#include "../game_blocks/game_blocks.hpp"

#include "qcolor.h"
#include "qnamespace.h"

#include <algorithm>
#include <random>
#include <vector>

// TODO: Add newFood function to relevant timings..

void Food::newFood() {
	int random_pos;
	const std::vector<int> &blocks = this->parent()
		->findChild<Snake*>()
		->blocks;

	do {
		random_pos = randomNum(0, TOTAL_BLOCKS - 1);
	} while (std::find(blocks.begin(), blocks.end(), random_pos) != blocks.end());

	position = random_pos;
	advance = randomNum(0, 1);

	QColor color = advance ? Qt::red : Qt::black;

	this->parent()
		->parent()
		->findChild<GameBlocks*>()
		->changeItemColor(position, color);
}

void Food::removeFood() {
	this->parent()
		->parent()
		->findChild<GameBlocks*>()
		->changeItemColor(position, Qt::white);
}

int Food::getScore() {
	return advance ? 2 : 1;
}

int Food::randomNum(int rl, int rr) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(rl, rr);

	return distr(gen);
}
