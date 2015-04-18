/* Max Walsh, 7 Wonders
 * This is the implementation file for the Player class. This contains the 
 * functions that will be used for the Player class in the 7 Wonders card game.
 * It will keep track of the turn, players to the left and right, and keep
 * track of the players score.
 */

#include <iostream>
#include <string>
#include "player.h"
#include "CardDeck.h"
//#include "Card.h"

using namespace std;

// non-default constructor
Player::Player( string n, int t ) {
  name = n;
  score = 0;
// playerturn = t;
  coins = 3;



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

void Player::addCoins( int val ) {
  coins += val;
}

void Player::removeCoins( int val ) {
  if ( val <= coins ) {
    coins -= val;
  } else {
    cout << "Sorry, there are not enough coins!" << endl;
  }
}
