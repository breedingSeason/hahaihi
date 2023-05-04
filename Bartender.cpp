#include "Bartender.h"


Bartender::Bartender(std::string name_, int age_):Person(name_, age_){

	sober_response[0] = "Bartender: That it is...";
	sober_response[1] = "Bartender: Couldn't agree more";
	sober_response[2] = "Bartender: You damn right";
	sober_response[3] = "Bartender: I wouldn't say otherwise";
	sober_response[4] = "Bartender: *nods of approval*";
	sober_response[5] = "Bartender: What are you? Mr.Factual?";

	drunk_response[0] = "Bartender: Sir... ";
	drunk_response[1] = "Bartender: You have probably had enough";
	drunk_response[2] = "Bartender: Are you okay?";
	drunk_response[3] = "Bartender: that's probably enough booze for you today";
	drunk_response[4] = "Bartender: Are you sure you're okay?";

}


void Bartender::greet(int drunk_level){
	if(drunk_level >= 75 and drunk_level < 100){
		std::cout << drunk_response[(rand() % 5)] << std::endl;
	}else if(drunk_level >= 0 and drunk_level <75){
		std::cout << sober_response[(rand() % 6)] << std::endl;
	}else if(drunk_level >= 100){
		std::cout << "Bartender: *sigh* alright " << std::endl;
	}

}


void Bartender::greet(){
	std::cout << "Here you go sir!" << std::endl;
}
