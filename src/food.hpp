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
  FoodKind(int kind);
	~FoodKind() {}

	friend class Food;
};

class Food
{
	FoodKind kind;
	int position;
public:
  Food(int _kind, int pos): kind(_kind), position(pos) {}
	~Food() {}

	int earnScore() { return kind.color; }
};

#endif
