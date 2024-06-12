#ifndef SNAKE_H
#define SNAKE_H

#define INITIAL_POS 5 * 25 + 12 - 1

#include <vector>

#include <QObject>
#include <QMutex>

enum MoveDirection {
	Up = -1,
	Down = 1,
	Left = -2,
	Right = 2
};

class Snake: public QObject
{
	Q_OBJECT

private:
	MoveDirection direction;
	std::vector<int> blocks;
	std::vector<MoveDirection> next_to;
	int unused_block;

	QMutex mtx;

	bool checkCollision(int new_head, MoveDirection direction);
	void updateBlocks(bool no_remove = false, bool initial = false);
	void initBlocks();
	void changeDirection();

public:
  Snake(QObject *parent = nullptr);

	void paintInitialBlocks();

	int getLength() const {
		return blocks.size();
	}

	friend class Food;
	friend class Game;

public slots:
	void advance();
};


#endif
