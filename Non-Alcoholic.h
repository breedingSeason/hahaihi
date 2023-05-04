#ifndef NON_ALCOHOLIC_H
#define NON_ALCOHOLIC_H
#include "Drink.h"


class Non_Alcoholic: public Drink{

public:
	Non_Alcoholic(std::string, int, int, int); // Parameterized constructor that will accept name, quantity, price and maximum quantity.
};
#endif
