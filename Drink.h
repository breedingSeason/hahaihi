#ifndef DRINK_H
#define DRINK_H
#include <iostream>


class Drink{

protected:

	Drink(); // Default constructor
    Drink(std::string, int, int, int); // Parameterized constructor that will accept name, count, prize, and maximum quantity
	std::string name;
	int maximum;
	int count;
	int price;

public:

	int get_count(); // Return drink's quantity
	int get_price(); // Return drink's price
	int brew(); // Allows bartender to create a drink/decrease the quantity by 1
	void change_count(); // Makes sure drinks that are empty will not get deducted to negative quantity;
	
	std::string get_name(); // Return the name of the drink

	virtual int get_info_level(); // Return info level
	virtual ~Drink(); // Virtual destructor


};
#endif
