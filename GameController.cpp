#include "SevenWonders.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	/**Initializations**/
	bool exit = false;
	bool nextAge;
	int numPlayers, cardPos, check = 1;
	char input;
	string newgame, move;

	while ( check ) { //select number of players
		cout << "Choose number of players (3-5 players only): ";
		cin >> numPlayers;

		if ( cin.fail() || numPlayers > 5 || numPlayers < 3 ) { //checks if int and < 5 and > 3
			cout << "Please enter an appropriate number of players (3-5 players only).\n";
		}
		else {
			while ( 1 ) { //confirmation of numPlayers
				cout << numPlayers << " players entered. Are you sure? (y/n)\n";
				cin >> input;

				if ( input == 'y' ) {
					check = 0;
					break;
				}
				else if ( input == 'n' ) {
					break;
				}
			}
		}
	}

	SevenWonders Game( numPlayers );
	cout << "before new game" << endl;
	Game.newGame();
	cout << "after new game" << endl;


	/**Game Driver**/
	cout << "Welcome to Age " << Game.getAge() << "." << endl;
	while (!exit){

		cout << "It is Player " << Game.getPlayerTurn() << "'s turn." << endl;
		cout << "Hand:		" << Game.getPlayerHand( Game.getPlayerTurn() );
		cout << "Coins:		" << Game.getPlayerCoin( Game.getPlayerTurn() ) << endl << endl;

		cout << "Move (p/c/w/o/e/n): ";
		cin >> move;

		if ( move == "p" ) {
			while (1) {
				cin >> cardPos;

				if ( cin.fail() || cardPos < 1 || cardPos > Game.getHandSize() ) {
					cout << "Select an appropriate card (by position).\n";
				}
				else {
					break;
				}
			}
			Game.playCard( cardPos );
			cout << "In hand:	" << Game.getPlayerHand( Game.getPlayerTurn() );
			cout << "In play:	" << Game.getPlayerPlayed( Game.getPlayerTurn() );
			cout << "Coins:		" << Game.getPlayerCoin( Game.getPlayerTurn() ) << endl << endl;
			nextAge = Game.nextPlayer();
		}
		else if ( move == "c" ) {
			cin >> cardPos;

			Game.disCard( cardPos - 1 );
			cout << "In hand:	" << Game.getPlayerHand( Game.getPlayerTurn() );
			cout << "In play:	" << Game.getPlayerPlayed( Game.getPlayerTurn() );
			cout << "Coins:		" << Game.getPlayerCoin( Game.getPlayerTurn() ) << endl << endl;
			nextAge = Game.nextPlayer();
		}
		else if ( move == "w" ) {
			cout << "Make Wonder" << endl;
		}
		else if ( move == "o" ) {
			cout << "Options" << endl;
		}
		else if ( move == "e" ) {
			cout << "Exiting..." << endl;
			exit = true;
		}
		else if ( move == "n" ) {
			cout << "Next Player..." << endl;
			nextAge = Game.nextPlayer();
		}
		else {
			cout << "Invalid Move" << endl;
		}

		if ( nextAge && !exit ) {
			exit = Game.advanceAge();
			if (exit){
				// calculates and displays player scores and winner of game
				Game.calcWinner();
				cout << "Play a new game? (y/n): ";
				cin >> newgame;
				if (newgame=="y"){
					exit = false;
					numPlayers = 0;
					while (numPlayers>7 || numPlayers<=1){
						cout << "Choose number of players: ";
						cin >> numPlayers;
					}
					Game.newGame();
					exit = Game.advanceAge();
					cout << "Welcome to Age " << Game.getAge() << "." << endl;
				} // what if press n or something else
			}
			else {
				cout << "Welcome to Age " << Game.getAge() << "." << endl;
			}
		}
	}

	return 0;

}
