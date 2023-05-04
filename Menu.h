#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Alcoholic.h"
#include "Customer.h"
#include "Bartender.h"
#include "Non-Alcoholic.h"
#include "Food.h"

class Menu{
	
	Drink** list_of_drinks;
	Food list_of_food[3];
	int num_drinks;


public:
	Menu(); // Default constructor
	void set_drinks(Bartender); // Allows the bartender to prepare the drink/ fill in list_of_drinks array. Database of drink is in Drink.csv
	void set_food(Bartender); // Allows the bartender to prepare the food/fill in list_of_food array.
	void main_menu(); // A statically written message for customer to interact with
	void module(Customer, Bartender); // Where all main calculation and interaction happens, the parameter will receive a customer and a bartender
	void starting_module(); // Allows the code in main to be encapsulated here
	void A_drink(); // Print out the list of drinks 
	void A_food(); // Print out the list of food
	void welcome_message(int, Customer); // A message at the beginning of program
	void essential_info(Customer); // Output user relevant information
	int validate(int); // Makes sure user input only integers
	int validate_range(int, int, int); // Makes sure user input is within range
	int prompt_age(); // Asks the user for age
	bool isValidName(std::string); // Validate name input
	std::string prompt_name(); // Asks user for name
    ~Menu(); // Destructor to delete list_of_drinks


};
#endif
