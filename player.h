/* Max Walsh, 7 Wonders
 * This is the interface file for the Player class. This instantiates for each
 * player in the 7 Wonders card game.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Hand.h"

using namespace std;

class Player {

	public:
		Player( string = "Bob", int = 1, int = 1 );
		int getScore();

		//Coin Stuff
		int getCoins();
		void addCoins( int );
		void removeCoins( int );

		//Cards in hand stuff
		void dealtoHand(int);
		Hand getHand();
		int getHandSize();
		int clearHand();

		//Cards in play Stuff
		void dealPlayed(int cardNum);
		Hand getPlayed();
		void clearPlayed();


	private:
		string name;
		int score;
//		int playerturn;
		int coins;
		vector<int> resources; // Card instead of int
		int calcScore();
		//Wonder wond;
		int playPlayerCard( int ); // moves playerHand card to inPlay

		Hand inPlay;
		Hand playerHand;

};
#endif
