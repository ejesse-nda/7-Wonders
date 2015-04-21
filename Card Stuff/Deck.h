/*Deck.cpp*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Card.cpp"
using namespace std;

template <typename T>
class Deck public Card{
public:
	Deck(/*ifstream&*/);
	void dealCard();
	void shuffle();
};

template <typename T>
void Deck<T>::Deck(/*ifsteam& inFile*/) {
	for (int i = 0; i < 4; ++i) {
		addCard(i);
	}
	shuffle();

	return;
}

template <typename T>
void Deck<T>::dealCard() {
	int ID = cards[cards.size() - 1];
	cards.pop_back();

	return ID;
}

template <typename T>
void Deck<T>::shuffle() {
	random_shuffle(cards.begin(), cards.end());

	return;
}