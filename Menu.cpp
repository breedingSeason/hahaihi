#include "Menu.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>


Menu::Menu(){}
void Menu::main_menu(){

	std::cout << "1. List of drinks" << std::endl;
	std::cout << "2. List of food" << std::endl;
	std::cout << "Press 0 to exit" << std::endl;
	std::cout << "Enter the number or to navigate around the program: ";
}

void Menu::module(Customer a, Bartender b){
	
	
	// This the main module, every major calculation and user interaction happens here
	int choice;
	std::cout << "You have " << a.return_money() << " dollars. ";
	std::cout << "Your drunk level is " << a.how_drunk() << ". Don't go too crazy!" << std::endl;
	this->main_menu();
	std:: cin >> choice;
	choice = this -> validate(choice);
	choice = this -> validate_range(0,2,choice);


	this -> set_drinks(b);
	this -> set_food(b);

	while(choice == 1 || choice == 2 || choice == 0){
		if(choice == 1){
			int general_response;
			std::cout << std::endl;
			this -> A_drink();
			std::cin >> general_response;
			std::cout << std::endl;
			general_response = this -> validate(general_response);
			general_response = this -> validate_range(0, num_drinks, general_response);

			while(general_response >= 0 || general_response <= num_drinks){
				if(general_response == 0){
					break;
				}else{
					list_of_drinks[general_response-1]->brew();
					if(list_of_drinks[general_response-1]->get_count() >= 0){
						a.buy_drink(list_of_drinks[general_response-1]->get_price());
						a.drink(list_of_drinks[general_response-1]->get_info_level());
						a.greet();
						b.greet(a.how_drunk());
						break;
					}else{
						std::cout << "Bartender: We ran out of " << list_of_drinks[general_response-1]->get_name() << std::endl;
						list_of_drinks[general_response-1]->change_count();
					}
					break;
				}
			}

		}else if(choice == 0){
			std::cout << "Come again" << std::endl;
			break;


		}else if(choice == 2){
			int general_response;
			std::cout << std::endl;
			this -> A_food();
			std::cin >> general_response;
			std::cout << std::endl;
			general_response = this -> validate(general_response);
			general_response = this -> validate_range(0,3,general_response);

			while(general_response >= 0 || general_response <= 3){
				if(general_response == 0){
					break;
				}else{
					list_of_food[general_response-1].brew();
					if(list_of_food[general_response-1].get_count() >= 0){
						a.buy_food(list_of_food[general_response-1].get_price());
						a.eat(list_of_food[general_response-1].get_info_level());
						a.greet();
						b.greet(a.how_drunk());
						break;
					}else{
						std::cout << "Bartender: We're out of " << list_of_food[general_response-1].get_name() << std::endl;
						list_of_food[general_response-1].change_count();
					}
					break;
				}
			}
			
		}else{
			std::cout << "Invalid input, try again: ";
			std::cin >> choice;
		}
		// Conditions where the loop should stop 
		if(a.how_drunk() >= 100){
			std::cout << "Bartender: You're too drunk, go home" << std::endl;
			break;
		}
		if(a.return_money() <= 0){
			std::cout << "You      : That's the last of my cent, goodbye" << std::endl;
			break;
		}
		if(a.how_hungry() <= 0){
			std::cout << "You      : I'm full, bye now" << std::endl;
			break;
		}


		// While choice is not 0, this loop will continue to go
		this -> essential_info(a);
		this -> main_menu();
		std::cin >> choice;
		choice = this -> validate(choice);
		choice = this -> validate_range(0,2,choice);
	}

}
void Menu::A_drink(){
	// prints out the drinks 
	for(int i = 0; i < num_drinks; i++){
		std::cout << i+1<<". "<< list_of_drinks[i]->get_name() << " ($" << list_of_drinks[i]->get_price() << ")" << " -" << list_of_drinks[i]->get_count() << " left" << std::endl;
	}
	std:: cout << "Choose your drink with numbers on the list or 0 to exit: ";
}

void Menu::A_food(){
	// prints out the food
	for(int i = 0; i < 3; i++){
		std::cout << i+1<<". "<< list_of_food[i].get_name() << " ($" << list_of_food[i].get_price() << ")" << "-" << list_of_food[i].get_count() << " left" << std::endl;
	}
	std:: cout << "Choose your food with numbers on the list or 0 to exit: ";

}

void Menu::set_drinks(Bartender){
	
	// This function is to set up the list_of_drink array
	std::fstream drink_file("Drink.csv");
	if (drink_file.is_open()){
		std::string line;
		num_drinks = 0;
		while(std::getline(drink_file, line)){
			num_drinks++;
		}

		// Make getline start from beggining
		drink_file.clear();
		drink_file.seekg(0);


		list_of_drinks = new Drink*[num_drinks];
		for(int j= 0; std::getline(drink_file, line); j++){
			if(line == "")continue;
			std::string col;
			std::string array[6];
			std::stringstream stream(line);
			for(int i=0; std::getline(stream, col, ','); i++){
				array[i] = col;
			}
			if(array[5] == "y"){
				list_of_drinks[j] = new Alcoholic(array[0], std::stoi(array[1]), std::stoi(array[2]), std::stoi(array[3]), std::stoi(array[4])); 
			}else if(array[5] == "n"){
				list_of_drinks[j] = new Non_Alcoholic(array[0], std::stoi(array[2]), std::stoi(array[3]), std::stoi(array[4]));
			}
		}
	}else{
		std::cout << "Can't open file" << std::endl;
	}

}

void Menu::set_food(Bartender b){
	Food Nachos("Nachos",15,5,15,7);
	Food Mozz("Mozzarella Stick",20,3,12,5);
	Food Wings("Wings",17,5,15,5);

	list_of_food[0] = Nachos;
	list_of_food[1] = Mozz;
	list_of_food[2] = Wings;
}


void Menu::welcome_message(int x, Customer c1){
	if(x == 1){
		std::cout << "Hi " << c1.get_name()<< ". Welcome to OOP Bar club" << std::endl << std::endl;
	}else if(x ==2){
		std::cout << "You have to be at least 19, get out."<< std::endl;
	}
}

void Menu::essential_info(Customer a){
	std::cout << std::endl;
	std::cout << "Money       : " << a.return_money() << std::endl;
	std::cout << "Drunk level : " << a.how_drunk() << std::endl;
	std::cout << "Hunger level: " << a.how_hungry() << std::endl;
}

std::string Menu::prompt_name(){
	std::string name;
	std::cout << "Please enter your name: ";
	std::cin >> name;

	while(this -> isValidName(name) == 0){
		std::cout << "Invalid name, try again: ";
		std::cin >> name;
	}

	
		return name;
	
}

bool Menu::isValidName(std::string name){
	bool correct = false;

	for(int i = 0; i < name.length(); i++){
		if((name[i] >= 65 and name[i] <= 90) or (name[i] >= 97 and name[i] <= 122) or name[i] == 32){
			correct = true;
		}else{
			return false;
		}
	}
	return correct;
}

int Menu::prompt_age(){
	int age_;
	std::cout << "Please enter your age: ";
	std::cin >> age_;
	while(age_ <= 5 or age_ >= 100){
		std::cout << "Please input valid number, try again: ";
		std::cin >> age_;
		age_ = this -> validate(age_);
	}

	return age_;
}


int Menu::validate(int x){
	while(std::cin.fail()){
		std::cout << "it can't accept letters, please put in numbers: ";
		std::cin.clear();
		std::cin.ignore(sizeof(unsigned int), '\n');
		std::cin >> x;
	}
	return x;
}

int Menu::validate_range(int x, int y, int z){
	while(z < x || z > y){
		std::cout << "The number you input is not within range, try again: ";
		std::cin >> z;
		while(std::cin.fail()){
			std::cout << "it can't accept letters, please put in numbers: ";
			std::cin.clear();
			std::cin.ignore(sizeof(unsigned int), '\n');
			std::cin >> z;
		}
	}
	return z;
}

void Menu::starting_module(){


	std::string name = this -> prompt_name();
	int age = this -> prompt_age();
	Customer c1(name, age);
	Bartender b1("Jack", 28);


	if(age >= 19){
		this->welcome_message(1, c1);
		this->module(c1, b1);

	}else if(age >= 5 or age < 19){
		std::cout << "You have to be at least 19, get out."<< std::endl;
	}
	
}

Menu::~Menu(){
	for(int i = 0; i < num_drinks; i++){
		delete list_of_drinks[i];
	}

	delete[] list_of_drinks;
}

