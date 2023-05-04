#ifndef BARTENDER_H
#define BARTENDER_H
#include "Person.h"

class Bartender:public Person{
private:
	std::string sober_response[6];
	std::string drunk_response[5];
public:

	Bartender(); // Default constructor
	Bartender(std::string, int); // Parameterized constructor
	void greet(int); // Allows bartender to interact with customer according to their drunk level
	void greet() override; // override virtual function from person

};
#endif