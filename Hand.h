/*Hand.h*/
#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "Card.h"
using namespace std;

class Hand : public Card {
public:
	Hand();
	Hand(int); //tags the hand with an ID
	int gethandID(); //returns the handID
	int selectCard(int); //when user selects a card to use
	string getInfo( int );
	int discardCard(int); //discard specified card
	void clearHand(); // clears Hand vector
private:
	int handID; //player 1, 2, 3, etc.
};
#endif
