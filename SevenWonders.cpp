#include "SevenWonders.h"
#include "player.h"
#include "CardDeck.h"

SevenWonders::SevenWonders(){

	Age = 0;
	PlayerTurn = 1;
	numPlayers = 4;

	CardDeck newDeck(7*numPlayers);

	newDeck.shuffle();
	AgeDeck[0].addToDeck(newDeck, 7*numPlayers);
	newDeck.shuffle();
	AgeDeck[1].addToDeck(newDeck, 7*numPlayers);
	newDeck.shuffle();
	AgeDeck[2].addToDeck(newDeck, 7*numPlayers);

	//DeckPtr->init(Age, numPlayers);

}

void SevenWonders::newGame(int xPlayers){

	Age = 0;
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
	if (Age>0 && Age<=3){
		for (int i=0; i<numPlayers; i++){
cout << "here" << endl;
			Players[i].dealHand(AgeDeck[Age]);
			cout << "To deal: " << AgeDeck[Age].getSize() << endl;
		}
	}

	return (Age>3);

}

CardDeck SevenWonders::getPlayerHand(int i){

	return Players[i-1].getHand();

}
