/*
 * File: CardDeck.cpp
 * Author: Eric Jesse
 * Class: CSE20212, Sp 2015
 * Lab: 4
 * Description: Implementation file for CardDeck class.
 *
 */

#include "CardDeck.h"
#include <algorithm> //For random_shuffle
#include <deque>
#include <cstdlib> 	//For srand()
#include <ctime>	//For time(0)
#include <iostream>
using std::ostream;


//Constructor
CardDeck::CardDeck(int n){
	//Create random seed
	std::srand(std::time(0));

	//Push back requested number of cards (default is 52)
	int i;
	for (i=0; i<n; i++) Deck.push_back(i);
}


//Return the size of the deck
int CardDeck::getSize(){
	return Deck.size();
}


//Shuffle the deck using algorithm function
void CardDeck::shuffle(){
	std::random_shuffle(Deck.begin(),Deck.end());
}


//Is the Deck in order? (1 if it is in order, 0 if it is not in order)
bool CardDeck::inOrder(){

	//Set deck to "in order" status
	bool isInOrder=1;

	int i;
	//For every card up to the second last card...
	for (i=0; i<getSize()-1; i++){
		//...compare value with next card. If the first card is larger, the deck is not in order.
		if (Deck[i] > Deck[i+1]) isInOrder=0;
	}

	return isInOrder;
}


//Prints out the deck
ostream& operator<<(ostream &output, const CardDeck &A){

	//If there are cards in the Deck
	if (A.Deck.size()>0){

		//Initiate deque iterator
		deque<int>::const_iterator i;

		//output first card
		i=A.Deck.begin();
		output << *i;

		//output ", " then next card until deck end is reached
		for (i= A.Deck.begin()+1; i!= A.Deck.end(); ++i) output << ", " << *i;

		//output end line, as requested
		output << std::endl;

	//If no cards in the deck, print [Empty]
	} else {

		output << "[Empty]" << std::endl;

	}

	//Return output stream
	return output;

}


//Adds all cards from top of newDeck to bottom of this Deck.
void CardDeck::addToDeck(const CardDeck &newDeck, int numCards){


	//For loop iterator
	deque<int>::const_iterator i;


	//Stop adding cards at the specified number of cards
	deque<int>::const_iterator stop=newDeck.Deck.begin()+numCards;


	//If trying to add more cards than in newDeck, just reset stop to end of deck.
	if (numCards > newDeck.Deck.size()) stop = newDeck.Deck.end();


	//Add the new cards to the bottom of this Deck
	for (i=newDeck.Deck.begin(); i!=stop; ++i) Deck.push_back(*i);

}


void CardDeck::addToDeckS(deque<int> &newDeck, int cardPos){

	Deck.push_back(newDeck[cardPos]);

}


//Deals cards from this deck
void CardDeck::Deal(CardDeck &Hand, int numCards){
	int i;

	//Add cards to the hand "deck"
	Hand.addToDeck(*this, numCards);

	//Remove the cards added from front, or top of the deck
	for(i=0; i<numCards; i++) Deck.pop_front();

}


void CardDeck::DealS(CardDeck &Hand, int cardNum){
	int i, position=-1;

	for (i=0; i<Deck.size(); i++) if (Deck[i]==cardNum) position=i;


	if (position > -1){
		//Add cards to the hand "deck"
		Hand.addToDeckS(Deck, position);

		//Remove the cards added from front, or top of the deck
		Deck.erase(Deck.begin()+position);
	}

}


//Returns the value of the deck/hand according to BlackJack
int CardDeck::getBlackJackValue(){

	deque<int>::const_iterator i;

	//Initiate value to 0
	int value=0;

	//For entire deck...
	for(i=Deck.begin(); i!=Deck.end(); ++i){
		//...check mod 13 plus 2.
		//This means that values run from 2 to 14 instead of 0 to 12, so deck runs 2-10, A(always 11), J, Q, K
		//if greater than 11 (i.e. J,Q,K), add only 10
		if ( ((*i)%13)+2 > 11) {
			value += 10;
		//else add result value
		}else{
			value += ((*i)%13) + 2;
		}
	}

	//Return claculated value
	return value;

}

void CardDeck::clear(){
	Deck.clear();

}
