/*Hand.h*/
#ifndef HAND_H
#define HAND_H

#include <iostream>
#include "Card.h"
using namespace std;

class Hand : public Card {
public:
	Hand(int);
	int selectCard(int); //when user selects a card to use
	int discardCard(int); //discard specified card
private:
	int handID;
};

Hand::Hand(int ID) { //tags the hand as the hand identifier
	handID = ID;

	for (int i = 0; i < 10; ++i) {
		cards.push_back(i);
	}
}

int Hand::selectCard(int n) {
	int ID = discardCard(n);

	return ID;
}

int Hand::discardCard(int n) {
	int ID = cards[n];
	cards.erase(cards.begin() + n);

	return ID;
}

#endif