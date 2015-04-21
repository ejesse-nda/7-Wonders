/*interpreter*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Hand.h"
#include "Deck.h"
using namespace std;

int main() {
	int ID;
	Deck deck(10), discard;
	Hand hand1(1), hand2(2);
	string line;

	cout << "TEST1" << endl;

	/*extractor*/
	fstream inFile("database.txt");

	ID = hand1.selectCard(5);
	discard.addCard(ID);

	hand1.displayCard();
	discard.displayCard();

	inFile.seekg(ios::beg);
	for (int i = 0; i < ID; ++i) {
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	inFile >> line;

	cout << line << endl;

	return 0;
}