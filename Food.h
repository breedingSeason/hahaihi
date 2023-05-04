#ifndef FOOD_H
#define FOOD_H
#include "Drink.h"


class Food:public Drink{
private:
	int hunger_level;

public:
	Food(); // Default constructor
	Food(std::string, int, int, int, int); // Parameterized constructor that will accept name, drunk level, quantity, price, and maximum quantity
	int get_info_level() override;  // Return hunger level



};

#endif