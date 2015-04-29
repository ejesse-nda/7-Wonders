/* Max Walsh, player.cpp
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
Player::Player( int t, int w ) {
        srand( time(0) );
	//name = n;
	score = 3; // number of coins initially
//	playerturn = t;
	coins = 3;
	Wonder( w, t );

	for (int i = 0; i < 4; ++i) {
		resources.push_back(0);
	}
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
        score = coins;
	playerHand.discardCard(cardNum);
}

void Player::removeCoins( int val ) {
	if ( val <= coins ) {
		coins -= val;
		score = coins;
	} else {
		cout << "Sorry, there are not enough coins!" << endl;
	}
}

void Player::addResource(string type, int val) {
	if (type.find('w') != string::npos) {
		resources[0] += val;
	}
	if (type.find('s') != string::npos) {
		resources[1] += val;
	}
	if (type.find('b') != string::npos) {
		resources[2] += val;
	}
	if (type.find('o') != string::npos) {
		resources[3] += val;
	}
	if (type.find('v') != string::npos) {
		victory += val;
	}
	if (type.find('m') != string::npos) {
		military += val;
	}
	if (type.find('c') != string::npos) {
		coins += val;
	}
}

void Player::checkCard(int ID) {
	string line, type;
	int value;

	fstream inFile("database.txt");
	inFile.seekg(ios::beg); //returns file iterator to beginning of file
	for (int i = 0; i < ID; ++i) { //loop skips lines to appropriate data
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	for (int i = 0; i < 4; ++i) {
		inFile >> line;
	}

	type = line.substr(0, line.size() - 1);
	inFile >> line;
	value = atoi(line.substr(0, line.size() - 1).c_str());
	cout << "t: " << type << " v: " << value << endl;

	addResource(type, value);
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
	checkCard(cardNum);

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
