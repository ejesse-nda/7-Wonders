#include "SevenWonders.h"

SevenWonders::SevenWonders(){

	Age = 1;
	PlayerTurn = 1;
	numPlayers = 4;

	DeckPtr = new Deck[numPlayers];

	Deck 

	DeckPtr->init(Age, numPlayers);

}

void newGame(int xPlayers){

	Age = 1;
	PlayerTurn = 1;
	numPlayers = xPlayers;

	delete DeckPtr;
	DeckPtr = new Deck;

	DeckPtr->init(Age, numPlayers);

}
