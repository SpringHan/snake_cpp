#include "food.hpp"

FoodKind::FoodKind(int kind) {
	// NOTE: Maybe this code would be extracted out.
  switch (kind) {
  case 0:
    color = Color::Red;
    break;
	case 1:
		color = Color::Orange;
		break;
	case 2:
		color = Color::Yellow;
		break;
	case 3:
		color = Color::Green;
		break;
	case 4:
		color = Color::Blue;
		break;
	case 5:
		color = Color::Purple;
		break;
	case 6:
		color = Color::White;
		break;
  }
}
