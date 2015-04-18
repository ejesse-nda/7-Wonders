#include "SevenWonders.h"

SevenWonders::SevenWonders(){

	Age = 1;
	PlayerTurn = 1;
	numPlayers = 4;

	//DeckPtr = new Deck[numPlayers];

	//Deck 

	//DeckPtr->init(Age, numPlayers);

}

void SevenWonders::newGame(int xPlayers){

	Age = 1;
	PlayerTurn = 1;
	numPlayers = xPlayers;

	//delete DeckPtr;
	//DeckPtr = new Deck;

	//DeckPtr->init(Age, numPlayers);

}

bool SevenWonders::nextPlayer(){
	PlayerTurn++;
	return (PlayerTurn>numPlayers);
}

void SevenWonders::setNumPlayers(int newNum){
	numPlayers = newNum;
}

int SevenWonders::getPlayerTurn(){
	return PlayerTurn;
}

int SevenWonders::getAge(){
	return Age;
}

//void SevenWonders::resolveTurn(){

//}

bool SevenWonders::advanceAge(){
	PlayerTurn = 1;
	Age++;
	return (Age>3);
	//delete DeckPtr;
	//DeckPtr = new Deck;
	//DeckPtr->init(Age, numPlayers);

}
