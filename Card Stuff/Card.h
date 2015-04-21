/*Card.h*/
//#ifndef CARD_H
//#define CARD_H

#include <iostream>
#include <vector>
using namespace std;

class Card {
public:
	void addCard(int); //adds card to cards vector
	int getSize(); //returns size of cards vector
	void displayCard(); //for test purposes
	string getInfo(); //returns the card description
protected:
	vector<int> cards;
};

void Card::addCard(int ID) {
	cards.insert(cards.begin(), ID);

	return;
}

int Card::getSize() {
	cout << cards.size();

	return cards.size();
}

void Card::displayCard() {
	for (int i = 0; i < cards.size(); ++i) {
		cout << cards[i] << ", ";
	}

	cout<< endl;
}

//#endif