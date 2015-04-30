//
// File: SevenWonders.cpp
// CSE20212, Sp2015
//
// Description: The instantiation of the 7Wonders/Game object. The game object
//   contains functions typical to the game (next player turn, discarding, etc.)

#include <string>
#include <ctime>	// time
#include <cstdlib>	// srand and ran
#include <vector>
#include <algorithm>
#include "SevenWonders.h"
#include "player.h"
#include "Deck.h"
#include "Hand.h"

//Constructor
SevenWonders::SevenWonders( int np ){

	//Dummy settings to be fixed in newGame
	Age = 0;
	PlayerTurn = 1;
	numPlayers = np;

	//Create new decks, for Age 1, 2, and 3
	Deck newDeck1(numPlayers,1);
	Deck newDeck2(numPlayers,2);
	Deck newDeck3(numPlayers,3);

	//Create Age Deck vector(decks will be chuffled in newGame)
	AgeDeck.push_back(newDeck1);
	AgeDeck.push_back(newDeck2);
	AgeDeck.push_back(newDeck3);

}


//Start a new game
void SevenWonders::newGame(){

	//Create new decks, for Age 1, 2, and 3
	Deck newDeck1(numPlayers,1);
	Deck newDeck2(numPlayers,2);
	Deck newDeck3(numPlayers,3);

	//Shuffle decks then add to Age Deck vector
	newDeck1.shuffle();
	AgeDeck[0]=(newDeck1);
	newDeck2.shuffle();
	AgeDeck[1]=(newDeck2);
	newDeck3.shuffle();
	AgeDeck[2]=(newDeck3);

	//clear players(which clears the hands and played too) and any old discard
	players.clear();
	discardPile.clearCard();

	srand( time(0) );
	string name;
      	int w;
	Age = 0;
	PlayerTurn = 1;
	// initialize vector
	vector<int> wonders;
	for ( int i = 0; i < 7; i++ ) {
	  wonders.push_back( i );
	}
	random_shuffle( wonders.begin(), wonders.end() );

// player 1
	w = wonders.back();
	wonders.pop_back();
	Player playerone( 1, w+1 );
    players.push_back( playerone );

// player 2
	w = wonders.back();
	wonders.pop_back();
	Player playertwo( 2, w+1 );
	players.push_back( playertwo );

// player 3
	w = wonders.back();
	wonders.pop_back();
	Player playerthree( 3, w+1 );
	players.push_back( playerthree );

// player 4
	if ( numPlayers >= 4 ) {
	  w = wonders.back();
	  wonders.pop_back();
	  Player playerfour( 4, w+1 );
	  players.push_back( playerfour );
	}

// player 5
	if ( numPlayers >= 5 ) {
	  w = wonders.back();
	  wonders.pop_back();
	  Player playerfive( 5, w+1 );
	  players.push_back( playerfive );
	}

// player 6
	if ( numPlayers >= 6 ) {
	  w = wonders.back();
	  wonders.pop_back();
	  Player playersix( 6, w+1 );
	  players.push_back( playersix );
	}

// player 7
	if ( numPlayers == 7 ) {
	  w = wonders.back();
	  wonders.pop_back();
	  Player playerseven( 7, w+1 );
	  players.push_back( playerseven );
	}

	//Psuedo player for hand passing
	players.push_back(playerone);
	SevenWonders::advanceAge();
}


//Advance to next player. Returns whether to advance the age.
bool SevenWonders::nextPlayer(){
	PlayerTurn++;
	if (PlayerTurn>numPlayers) {
		PlayerTurn = 1;
		resolveTurn();
		int x = 1-(Age%2);
		if (x==0) {
			players[numPlayers].takeHand(players[0]);
			for(int i=0; i<numPlayers; i++){
				players[i].takeHand(players[i+1]);
			}
		} else {
			for(int i=numPlayers; i>0; i--){
				players[i].takeHand(players[i-1]);
			}
			players[0].takeHand(players[numPlayers]);
		}
		players[numPlayers].clearHand();
	}

	return (PlayerTurn==1 && players[0].getHandSize()==1);
}


//Set the number of players
void SevenWonders::setNumPlayers(int newNum){
	numPlayers = newNum;
}


//Return current player's turn
int SevenWonders::getPlayerTurn(){
	return PlayerTurn;
}


//Return the current Age
int SevenWonders::getAge(){
	return Age;
}


//Play all cards/Discards in queue
void SevenWonders::resolveTurn(){
	//Store turn. PlayTurn decides which player to use playCard/disCard on.
	int temp = PlayerTurn;
	PlayerTurn = 1;
	for (int i=0; i<toBePlayed.size(); i++){
		if (toBe[i]==1)	playCard(toBePlayed[i]);
		else disCard(toBePlayed[i]);
		PlayerTurn++;
	}
	//Clear queue and put PlayerTurn back
	toBePlayed.clear();
	toBe.clear();
	PlayerTurn = temp;
}



bool SevenWonders::advanceAge(){
	PlayerTurn = 1;
	Age++;
	if (Age>0 && Age<=3){
		for (int i=0; i<numPlayers; i++) {
			if (Age>1) discardPile.addCard(players[i].clearHand());
			for (int j=0; j<7; j++)	players[i].dealtoHand(AgeDeck[Age-1].dealCard() );
		}
	}
	return (Age>3);
}



Hand SevenWonders::getPlayerHand(int i){
	return players[i-1].getHand();
}


//
Hand SevenWonders::getPlayerPlayed(int i){
	return players[i-1].getPlayed();
}


//
int SevenWonders::getPlayerCoin(int i){
	return players[i-1].getCoins();
}


//
void SevenWonders::queuePlayCard(int cardNum){
	toBePlayed.push_back(cardNum);
	toBe.push_back(1);
}


//
void SevenWonders::playCard(int cardNum){
	players[PlayerTurn-1].dealPlayed(cardNum);
}


//
void SevenWonders::queueDiscard(int cardNum){
	toBePlayed.push_back(cardNum);
	toBe.push_back(0);
}


//
void SevenWonders::disCard(int cardNum){
	Hand Temp = players[PlayerTurn-1].getHand();
	discardPile.addCard(Temp.returnCard(cardNum));

	players[PlayerTurn-1].addCoins(cardNum);
}


// returns hand size
int SevenWonders::getHandSize() {
  return players[PlayerTurn - 1].getHandSize();
}


// Calculates the winner of the game
void SevenWonders::calcWinner() {
  int highscore = 0;
  int winner = 0;
  int pnum = 1;
  int tie = 0;
  vector<Player>::iterator it = players.begin();
  cout << "Players:     Score:" << endl;
  for ( it; it != players.end()-1; ++it ) {
    cout << "Player " << pnum << ":	" << it->getScore() << endl;
    if ( it->getScore() == highscore ) {
      tie = 1;
    } else if ( it->getScore() > highscore ) {
      highscore = it->getScore();
      winner = pnum;
      tie = 0;
    }
    pnum++;
  }

  if ( tie ) {
    cout << "There has been a tie!" << endl;
  } else {
    cout << "Player " << winner << " has won the game!" << endl;
  }
}


// displays wonder information
void SevenWonders::displayWonder() {
  players[PlayerTurn - 1].showWonder();
}

// displays resources
void SevenWonders::displayResources() {
  players[PlayerTurn - 1].showResources();
}

