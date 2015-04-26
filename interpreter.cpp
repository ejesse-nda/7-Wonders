/*interpreter*/
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "Hand.h"
#include "Deck.h"
using namespace std;

int main() {
	cout << "TEST" << endl; //for TEST purposes

	/**INSTANTIATIONS: populates Hand and Deck objects**/
	Deck deck(3,1), discard; //deck and discard pile
	Hand hand1(1), hand2(2); //player 1 and player 2 hands

	cout << "Deck: ";
	deck.displayCard(); //TEST: prints cards in deck

	for (int i = 0; i < 2; ++i) {
		hand1.addCard(deck.dealCard());
		hand2.addCard(deck.dealCard());
	}

	cout << "Player " << hand1.gethandID() << ": ";
	hand1.displayCard(); //TEST: prints cards
	cout << "Player " << hand2.gethandID() << ": ";
	hand2.displayCard(); //TEST: prints cards
	/****/

	/**SIMULATION: pretends player is selecting cards**/
	while (!hand1.checkEmpty()) { //reprsents only player 1, for simplicity's sake
		string line; //stores a line from the database

		cout << "\nPlayer " << hand1.gethandID() << ": ";
		hand1.displayCard(); //TEST: prints cards (REMINDER: needs empty checking)

		int ID = hand1.selectCard(1); //selects first card in hand (ideally would be a user input)

		/*IMPORTANT: this is a sloppy implementation of discard cards into a discard deck*/
		discard.addCard(ID);
		/**/

		/**EXTRACTOR: extracts data from database.txt**/
		fstream inFile("database.txt");
		inFile.seekg(ios::beg); //returns file iterator to beginning of file
		for (int i = 0; i < ID; ++i) { //loop skips lines to appropriate data
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		inFile >> line; //extract the line from the file

		int type = line[3] - '0', value = line[5] - '0'; //"- '0'" converts a numberic char to int (REMINDER: needs numeric checking)
		string info = hand1.getInfo(ID); //grabs info through function (function may be redundant, iron out later)
		cout << "Resource Type ID: " << type << endl;
		cout << "Resource Value: " << value << endl;
		cout << "Description: " << info << endl;
		/****/
	}
	/****/

	return 0;
}
