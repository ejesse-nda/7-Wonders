#ifndef SEVENWONDERS_H
#define SEVENWONDERS_H

#include "player.h"
#include "CardDeck.h"

class SevenWonders{

	public:
		SevenWonders();

		void newGame(int xPlayers);
		bool nextPlayer();
		void setNumPlayers(int newNum);
		int getPlayerTurn();
		int getAge();
		//void resolveTurn();
		bool advanceAge();

	private:
		int Age;
		int numPlayers;
		int PlayerTurn;
		Player Players[7];
		CardDeck * DeckPtr;
		CardDeck Age1Deck;
		CardDeck Age2Deck;
		CardDeck Age3Deck;


};

#endif
