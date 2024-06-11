// Food

#ifndef _FOOD_H_
#define _FOOD_H_

#include "qobject.h"
#include "qobjectdefs.h"

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
	int getScore();
};

#endif
