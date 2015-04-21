/* Max Walsh, 7 Wonders
 * This is the interface file for the Player class. This instantiates for each
 * player in the 7 Wonders card game.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "CardDeck.h"
//#include "Card.h"

using namespace std;

class Player {

	public:
		Player( string = "Bob", int = 1, int = 1 );
		int getScore();
//		int getTurn();
//		void setPlayerTurn( int );

		int getCoins();
		void addCoins( int );
		void removeCoins( int );

		void dealHand(CardDeck &AgeDeck);
		CardDeck getHand();
		void clearHand();
		void dealPlayed(int cardNum);
		CardDeck getPlayed();
		void clearPlayed();


	private:
		string name;
		int score;
//		int playerturn;
		int coins;
		vector<int> resources; // Card instead of int
		int calcScore();
		//Wonder wond;

		CardDeck Played;
		CardDeck Hand;

};
#endif
