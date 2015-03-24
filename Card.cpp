#include "Card.h"
#include <string>
using std::string;
#include <vector>
using std::vector;

Card::Card(){

}

Card::Card(string name) {

	if (name=="Mine") {
		Name = name;
		Resource.push_back("Ore");
		Cost.push_back("None");
		FreePlayReq = "None";
		Type = "Brown";
	} else {
		Name = "None";
		Resource.push_back("None");
		Cost.push_back("None");
		FreePlayReq = "None";
		Type = "None";
	}

}

vector<string> Card::getCost(){

	return Cost;

}

vector<string> Card::getResource(){

	return Resource;

}
