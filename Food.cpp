#include "Food.h"


Food::Food(){}
Food::Food(std::string name, int hunger_level, int count, int price, int maximum):Drink(name, count, price, maximum){

	this->hunger_level = hunger_level;
}

int Food::get_info_level(){
	return hunger_level;
}

