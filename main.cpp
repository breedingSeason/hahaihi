#include <ctime>
#include <iostream>

#include "Alcoholic.h"
#include "Bartender.h"
#include "Customer.h"
#include "Drink.h"
#include "Menu.h"
#include "Person.h"

int main() {
  srand(time(NULL));        // To randomize index choosing for responses
  Menu* main = new Menu;    // Create a new object main
  main->starting_module();  // Module to start the program

  delete main;
}