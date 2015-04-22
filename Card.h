/*Card.h*/
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <deque>
using namespace std;

class Card {

	friend ostream& operator<<(ostream &, const Card &); //Print the deck, using the delimiter ", "

public:
	void addCard(int); //adds card to cards vector
	int getSize(); //returns size of cards vector
	void displayCard(); //for test purpose
	int checkEmpty(); //returns true (1) when cards vector is empty
	void clearCard();
	int dealCard();
protected:
	deque<int> cards;
};
#endif
