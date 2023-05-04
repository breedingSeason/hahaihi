#include "Person.h"

Person::Person(){}
	

Person::Person(std::string name_, int age_){
	name = name_;
	age = age_;
}

std::string Person::get_name(){
	return name;
}

int Person::get_age(){
	return age;
}

