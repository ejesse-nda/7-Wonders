/*Deck.h*/
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <algorithm>
#include "Card.h"
using namespace std;

class Deck : public Card{
public:
	Deck();
	Deck(int);
	int dealCard();
	void shuffle();
};

Deck::Deck() {}

Deck::Deck(int n) {
	for (int i = 0; i < n; ++i) {
		addCard(i);
	}
	shuffle();
}

int Deck::dealCard() {
	int ID = *cards.end();
	cards.pop_back();

	return ID;
}

void Deck::shuffle() {
	random_shuffle(cards.begin(), cards.end());

	return;
}

#endif