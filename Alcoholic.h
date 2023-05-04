#ifndef ALCOHOLIC_H
#define ALCOHOLIC_H
#include "Drink.h"

class Alcoholic:public Drink{
private:
	int drunk_level;

public:
	Alcoholic(); // Default constructor
	Alcoholic(std::string, int, int, int, int); // Parameterized constructor that will accept name, drunk level, quantity, price, and maximum quantity
	int get_info_level() override;  // Return drunk level inherited by Drink class
};
#endif
