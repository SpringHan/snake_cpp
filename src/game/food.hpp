// Food

#ifndef _FOOD_H_
#define _FOOD_H_

#include <QObject>

class Food: public QObject
{
	Q_OBJECT

private:
	bool advance;
	int position;

	int randomNum(int rl, int rr);

public:
  Food(QObject *parent = nullptr): QObject(parent) {}

	void newFood();
	void removeFood();
	int getScore();

	int getPosition() const {
		return position;
	}
};

#endif
