/* Max Walsh, 7 Wonders
 * This is the implementation file for the Player class. This contains the 
 * functions that will be used for the Player class in the 7 Wonders card game.
 * It will keep track of the turn, players to the left and right, and keep
 * track of the players score.
 */

#include <iostream>
#include <string>
#include <cstdlib>	// srand
#include <ctime>	// time to initialize rand
#include "player.h"
#include "Hand.h"
#include "wonder.h"

using namespace std;

// non-default constructor
Player::Player( string n, int t, int w ) {
        srand( time(0) );
	name = n;
	score = 0;
//	playerturn = t;
	coins = 3;
        //Wonder( w, t );
}


int Player::getScore() {
	return score;
}

/*int Player::getTurn() {
	return playerturn;
}// */

int Player::getCoins() {
	return coins;
}

void Player::addCoins( int cardNum ) {
	coins += 2;
	playerHand.discardCard(cardNum);
}

void Player::removeCoins( int val ) {
	if ( val <= coins ) {
		coins -= val;
	} else {
		cout << "Sorry, there are not enough coins!" << endl;
	}
}


void Player::dealtoHand(int i) {
	playerHand.addCard(i);
}

int Player::playPlayerCard( int i ) {
	inPlay.addCard( playerHand.selectCard(i) );
}

Hand Player::getHand() {

	return playerHand;

}

void Player::takeHand(Player &nextPlayer){

	playerHand.clearCard();
	playerHand = nextPlayer.getHand();

}

int Player::clearHand(){

	return playerHand.clearCard();

}


int Player::getHandSize(){
	return playerHand.getSize();
}

void Player::dealPlayed(int cardNum){

	inPlay.addCard(playerHand.selectCard(cardNum));

}



Hand Player::getPlayed(){

	return inPlay;

}


/* not in Hand class
void Player::clearPlayed(){

	inPlay.clear();

}
*/
