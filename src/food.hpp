// Food

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

	int foodScore() { return color; }
};

class Food
{
	FoodKind kind;
	int position;
public:
  Food(int _kind, int pos): kind(_kind), position(pos) {}
	~Food() {}
};
