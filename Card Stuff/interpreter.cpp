/*interpreter*/
#include <iostream>
#include <fstream>
#include "Hand.cpp"
#include "Deck.cpp"
using namespace std;

int main() {
	int ID;
	Deck deck, discard;
	Hand hand1, hand2;

	//extractor
	string database = "database.txt"
	ifstream inFile;

	inFile.open(database.c_str());

	ID = hand1.selectCard(1);

	if(ID == 0) {
		//Add points to victory
	}

	inFile.close();

	return 0;
}