/*Card.h*/
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
using namespace std;

class Card {
public:
	void addCard(int); //adds card to cards vector
	int getSize(); //returns size of cards vector
	void displayCard(); //for test purpose
	int checkEmpty(); //returns true (1) when cards vector is empty
protected:
	vector<int> cards;
};

void Card::addCard(int ID) {
	cards.push_back(ID);

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

int Card::checkEmpty() {
	return cards.empty();
}

#endif