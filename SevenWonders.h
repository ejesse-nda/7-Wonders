////////////////////////////
//
// File: SevenWonders.h
// CSE20212, Sp2015
//
// Description: Header file for the 7 wonders, or game class. The game class
//   drives all the basic functions of the game (playing cards, next turn, etc.)
//
////////////////////////////

#ifndef SEVENWONDERS_H
#define SEVENWONDERS_H

#include <vector>
#include "player.h"
#include "Deck.h"

class SevenWonders{

	public:
		//Constructor
		SevenWonders( int );


		void newGame(); //Start a new game
		bool nextPlayer(); //Go to next player's turn
		void setNumPlayers(int newNum); //Set the number of players
		int getPlayerTurn(); //Get current player's turn

		int getAge(); //Get the current Age
		void resolveTurn(); //Play all card/discards at once
		bool advanceAge(); //Go to next age

		Hand getPlayerHand(int i); //return the player's hand
		Hand getPlayerPlayed(int i); //return the cards the player has played
		int getPlayerCoin(int i); //return the number of coins the player has
 		int getHandSize(); //return the size of the current player's turn

		void queuePlayCard(int cardNum); //Add card to queue and remember to play it
		void playCard(int cardNum); //Play a card
		void queueDiscard(int cardNum); //Add card to queue and remember to discard it
		void disCard(int cardNum); //Discard a card for coins

		void calcWinner(); //Determine scores and the winner
		void displayWonder(); // displays wonder information
		void displayResources(); // displays resources

	private:
		int Age; //Current Age
		int numPlayers; //Current number of players
		int PlayerTurn; //Current player's turn
		vector<int> toBe; //Vector describing how to play the corresponding card
		vector<int> toBePlayed; //Vector of cards to be used as described by toBe vector
		vector<Player> players; //Vector of players
		vector<Deck> AgeDeck; //The decks for each age are stored in this vector for indexing purposes
		Deck discardPile; //discard pile. In the real game, the discard pile may be looked through under special circumstances that are not currently available in our game.
};

#endif
