#ifndef SNAKE_H
#define SNAKE_H

#include "qobject.h"
#include "qobjectdefs.h"

#define INITIAL_POS 5 * 25 + 12 - 1

#include <vector>

#include <QObject>

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
	int unused_block;

	bool checkCollision(int new_head, MoveDirection direction);
	void addBlock(int pos);
	void updateBlocks(bool initial = false);
	void initBlocks();
public:
  Snake(QObject *parent = nullptr);

	void paintInitialBlocks();

	int getLength() const {
		return blocks.size();
	}

	friend class Game;

public slots:
	void advance();
};


#endif
