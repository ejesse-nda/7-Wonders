#ifndef SEVENWONDERS_H
#define SEVENWONDERS_H

#include <vector>
#include "player.h"
#include "Deck.h"

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

		Hand getPlayerHand(int i);
		Hand getPlayerPlayed(int i);
		int getPlayerCoin(int i);

		void playCard(int cardNum);
		void disCard(int cardNum);
		
		void calcWinner();

	private:
		int Age;
		int numPlayers;
		int PlayerTurn;
		vector<Player> players;
		vector<Deck> AgeDeck;
		Deck discardPile;
};

#endif
