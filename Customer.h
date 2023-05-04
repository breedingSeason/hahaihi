#ifndef CUSTOMER_H
#define CUSTOMER_H	
#include "Person.h"
#include <cstdlib>

class Customer:public Person{

private:
	 const int max_drunk_level = 100;
	 int drunk_level = 0;
	 int hunger_level = 75;
	 int money = 150;
	 std::string sober_response[5]; 
	 std::string drunk_response[5];

public:

	Customer(); // Default constructor
	Customer(std::string, int); // Parameterized constructor that accepts name and age
	int buy_drink(int); // Take customer money according to the price of the object they buy
	int buy_food(int); // Take customer money from the food they buy
	void greet() override; // Greeting messages
	int drink(int); // Modify value of drunk level
	int eat(int); // Modify value of hunger_level
	int how_drunk(); // Return drunk level;
	int how_hungry(); // Return hunger level
	int return_money(); // Return current money;




};
#endif