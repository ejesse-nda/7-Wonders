#ifndef SEVENWONDERS_H
#define SEVENWONDERS_H

class SevenWonders{

	public:
		SevenWonders();

		void newGame(int xPlayers);
		void nextPlayer();
		void changeNumPlayers(int newNum);
		void resolveTurn();
		void advanceAge();
		

	private:
		int Age;
		int numPlayers;
		int PlayerTurn;
		Player Players[7];
		Deck * DeckPtr;


};

#endif
