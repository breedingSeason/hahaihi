#include "Customer.h"


Customer::Customer(std::string name_, int age_):Person(name_, age_){

    // Sets the response array
	sober_response[0] = "You      : The weather is nice wouldn't you say?";
	sober_response[1] = "You      : Ahhh, that tastes good";
	sober_response[2] = "You      : This bar feels nice";
	sober_response[3] = "You      : It must be fun to work as a bartender";
	sober_response[4] = "You      : I haven't had a nice drink like this in a long time";


	drunk_response[0] = "You      : Oh man, I don't feel so good";
	drunk_response[1] = "You      : *delirious*";
	drunk_response[2] = "You      : *sob* *sob*";
	drunk_response[3] = "You      : Why did she leave me!?";
	drunk_response[4] = "You      : Come on, pour some little more";

}

void Customer::greet(){
	// greet level depends on customer drunk_level
	if(drunk_level >= 75 and drunk_level < 100){
		std::cout << drunk_response[(rand() % 5)] << std::endl;
	}else if(drunk_level >= 0 and drunk_level <75){
		std::cout << sober_response[(rand() % 5)] << std::endl;
	}else if(drunk_level >= 100){
		std::cout << "You: *zzzz* " << std::endl;
	}else{
		std::cout << drunk_response[(rand() % 5)] << std::endl;
	}
}

int Customer::buy_drink(int price){
	money = money - price;
	if(money < 0){
		money = money + price;
		std::cout << "Bartender: You do not have enough money" << std::endl;
		return money;
	}else{
		std::cout << "Bartender: Enjor your drink!" << std::endl;
		return money;
	}
	
}

int Customer::buy_food(int price){
	money = money - price;
	if(money < 0){
		money = money + price;
		std::cout << "Bartender: You do not have enough money" << std::endl;
		return money;
	}else{
		std::cout << "Bartender: Enjor your food!" << std::endl;
		return money;
	}
	
}

int Customer::drink(int x){
	// Increase drunk level
	drunk_level = drunk_level + x;
	if(drunk_level > 100){
		return drunk_level;
	}else if(drunk_level < 0){
		drunk_level = 0;
		std::cout << "You are sober, too sober in fact" << std::endl;
		return drunk_level;
	}else{
		return drunk_level;
	}
}

int Customer::eat(int x){
	// Increase drunk level
	hunger_level =  hunger_level - x;
	if(hunger_level < 75 and hunger_level > 0){
		return hunger_level;
	}else if(hunger_level <= 0){
		hunger_level = 0;
		std::cout << "You      : Oh my, I'm so full" << std::endl;
		return hunger_level;
	}else{
		return hunger_level;
	}
}

int Customer::how_drunk(){
	return drunk_level;
}

int Customer::how_hungry(){
	return hunger_level;
}

int Customer::return_money(){
	return money;
}

