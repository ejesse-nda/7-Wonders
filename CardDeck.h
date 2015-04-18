/*
 * File: CardDeck.h
 * Author: Eric Jesse
 * Class: CSE20212, Sp 2015
 * Lab: 4
 * Description: Header file for CardDeck class.
 *
 */

#ifndef CARDDECK_H
#define CARDDECK_H

#include <deque>
using std::deque;
#include <iostream>
using std::ostream;

class CardDeck {

	public:
		CardDeck(int = 0);	//default 0 cards
		int getSize(); 		//returns the number of cards in the deck
		void shuffle();		//randomize the order of the cards
		bool inOrder();		//return if the cards are in order
		friend ostream& operator<<(ostream &, const CardDeck &); //Print the deck, using the delimiter ", "

		//Copy cards from another deck to this deck.
		//The cards are not removed from the other deck.
		void addToDeck(const CardDeck &newDeck, int numCards);

		//Deal cards from this deck to another deck. Cards are removed from this deck.
		void Deal(CardDeck &Hand, int numCards);

		//Treat the deck like a blackjack hand, and return the number of points
		int getBlackJackValue();

		void clear();

	private:
		deque<int> Deck;

};

#endif

