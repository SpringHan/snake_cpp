#ifndef SNAKE_H
#define SNAKE_H

#define INITIAL_POS 5 * 25 + 12 - 1

#include <vector>

class Snake
{
	unsigned int length;
	std::vector<int> blocks;
public:
  Snake();
	~Snake() {}

	unsigned int getLength() const {
		return length;
	}

	void update();
};


#endif
