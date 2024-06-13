#include "./game.hpp"
#include "./snake.hpp"
#include "./food.hpp"
#include "../game_blocks/game_blocks.hpp"

Snake::Snake(QObject *parent): QObject(parent) {}

void Snake::initBlocks() {
	if (!blocks.empty()) {
		GameBlocks *controller = this->parent()
			->parent()
			->findChild<GameBlocks*>();

		for (int &i : blocks) {
			controller->changeItemColor(i, Qt::white);
		}

		blocks.clear();
	}

	blocks.push_back(INITIAL_POS);
	blocks.push_back(INITIAL_POS + 1);
	direction = MoveDirection::Left;
}

void Snake::paintInitialBlocks() {
	updateBlocks(true, true);
}

void Snake::updateBlocks(bool no_remove, bool initial) {
	GameBlocks *controller = this->parent()
		->parent()
		->findChild<GameBlocks*>();

	if (initial) {
		for (int &i : this->blocks) {
			controller->changeItemColor(i, Qt::black);
		}

		return;
	}  

	controller->changeItemColor(blocks[0], Qt::black);

	if (!no_remove) {
		// Avoid the forcible erasing when the head is moving to the tail.
		if (unused_block != blocks[0]) {
			controller->changeItemColor(unused_block, Qt::white);
		}
	}
}

bool Snake::checkCollision(int new_head, MoveDirection direction) {
	// NOTE: The last position index of the snake haven't been removed yet.

	// Border Check
	switch (direction) {
	case MoveDirection::Up:
		if (new_head < 0) return true;
		break;
	case MoveDirection::Down:
		if (new_head >= TOTAL_BLOCKS) return true;
		break;
	default:
		float temp = (float)(blocks[0] + 1) / 25;
		int origin_line = (int)temp;
		if (temp == origin_line) {
			origin_line--;
		}

		temp = (float)(new_head + 1) / 25;
		int new_line = (int)temp;
		if (temp == new_line) {
			new_line--;
		}

		if (origin_line != new_line) return true;
	}

	// Repetition
	for (int i = 0; i < blocks.size() - 1; i++) {
		if (blocks[i] == new_head) {
			return true;
		}
	}

	return false;
}

void Snake::changeDirection() {
	if (!next_to.empty()) {
		int origin = this->direction;
		int modify_to = next_to[0];

		next_to.erase(next_to.begin());

		if (origin == modify_to || origin == -modify_to) {
			return;
		}

		this->direction = (MoveDirection)modify_to;
	}
}

void Snake::advance() {
	mtx.lock();

	this->changeDirection();

	int head;
	MoveDirection temp_direction = this->direction;

	switch (temp_direction) {
	case MoveDirection::Up:
		head = blocks[0] - 25;
		break;
	case MoveDirection::Down:
		head = blocks[0] + 25;
		break;
	case MoveDirection::Left:
		head = blocks[0] - 1;
		break;
	case MoveDirection::Right:
		head = blocks[0] + 1;
		break;
	}

	if (checkCollision(head, temp_direction)) {
		mtx.unlock();
		((Game*)this->parent())->pauseGame();
		return;
	}

	blocks.insert(blocks.begin(), head);

	// Food check
	Food *food = this->parent()->findChild<Food*>();

	if (food->getPosition() == head) {
		((Game*)this->parent())->addScore();
		food->newFood();
		updateBlocks(true);

		mtx.unlock();
		return;
	}

	unused_block = blocks.back();
	blocks.pop_back();
	updateBlocks();

	mtx.unlock();
}
