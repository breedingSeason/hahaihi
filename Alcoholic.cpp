#include "Alcoholic.h"

Alcoholic::Alcoholic(){}

Alcoholic::Alcoholic(std::string name, int drunk_level, int count, int price, int maximum ): Drink(name, count, price, maximum){
	this->drunk_level = drunk_level;
	
}

int Alcoholic::get_info_level(){
	return drunk_level;
}
