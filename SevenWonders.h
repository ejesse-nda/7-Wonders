#ifndef SEVENWONDERS_H
#define SEVENWONDERS_H

#include "player.h"
#include "CardDeck.h"

class SevenWonders{

	public:
		SevenWonders( int );

		void newGame();
		bool nextPlayer();
		void setNumPlayers(int newNum);
		int getPlayerTurn();
		int getAge();
		//void resolveTurn();
		bool advanceAge();
		CardDeck getPlayerHand(int i);
		CardDeck getPlayerPlayed(int i);
		void playCard(int cardNum);

	private:
		int Age;
		int numPlayers;
		int PlayerTurn;
		vector<Player> players;
		CardDeck * DeckPtr;
		CardDeck AgeDeck[3];

};

#endif
