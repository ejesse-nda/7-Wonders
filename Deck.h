/*Deck.h*/
#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "Card.h"
using namespace std;

class Deck : public Card {
public:
	Deck(); //does absolutely nothing, for now
	Deck(int n, int Age); //instantiates n cards into deck
	int dealCard(); //passes out a card
	void shuffle(); //shuffle!
//	int gethandID(); //returns the handID
//	int selectCard(int); //when user selects a card to use
//	int discardCard(int); //discard specified card
//	string getInfo(int); //returns the card description

};
#endif
