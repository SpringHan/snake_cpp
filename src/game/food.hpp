// Food

#ifndef _FOOD_H_
#define _FOOD_H_

enum Color {
	Red,
	Orange,
	Yellow,
	Green,
	Blue,
	Purple,
	White
};

class FoodKind
{
	Color color;
public:
  FoodKind() {}
	~FoodKind() {}

	void setKind(int kind);

	friend class Food;
};

class Food
{
	FoodKind kind;
	int position;
public:
  Food() {}
	~Food() {}

	int earnScore() { return kind.color; }
	void setFood(int kind, int pos);
};

#endif
