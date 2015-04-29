#include "SevenWonders.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	/**Initializations**/
	bool exit = false;
	bool nextAge;
	int numPlayers, cardPos, check = 1;
	string newgame, move, input;

	while ( check ) { //select number of players
		cout << "Choose number of players (3-5 players only): ";
		cin >> numPlayers;

		if ( !cin.fail() && numPlayers <= 5 && numPlayers >= 3 ) { //checks if int and < 5 and > 3
			while ( 1 ) { //confirmation of numPlayers
				cout << numPlayers << " players entered. Are you sure? (y/n)\n";
				cin >> input;

				if ( input == "y" ) {
					check = 0;
					break;
				}
				else if ( input == "n" ) {
					break;
				}
			}
		}
		else { //check for invalid input and flush cin
			cout << "Please enter an appropriate number of players (3-5 players only).\n";
			cin.clear();
			cin.ignore(1000000, '\n');
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
		cout << "Hand:	" << Game.getPlayerHand( Game.getPlayerTurn() ); //print hand
		cout << "Coins:	" << Game.getPlayerCoin( Game.getPlayerTurn() ) << endl << endl;

		cout << "Move (p/c/w/e/n): ";
		cin >> move;

		/*Play a Card*/
		if ( move == "p" ) {
			check = 1;

			while ( check ) {
				cout << "Select a card (by position).\n";
				cin >> cardPos;

				if ( !cin.fail() && cardPos >= 1 && cardPos <= Game.getHandSize() ) {
					while ( 1 ) { //confirmation of cardPos
						cout << "Are you sure you want to play card #" << cardPos << "? (y/n)\n";
						cin >> input;
		
						if ( input == "y" ) {
							check = 0;
							break;
						}
						else if ( input == "n" ) {
							break;
						}
					}
				}
				else {
					cout << "Select an appropriate card (by position).\n";
					cin.clear();
					cin.ignore(1000000, '\n');
				}

			}
			Game.playCard( cardPos );
			cout << "In hand:" << Game.getPlayerHand( Game.getPlayerTurn() );
			cout << "In play:" << Game.getPlayerPlayed( Game.getPlayerTurn() );
			cout << "Coins:	" << Game.getPlayerCoin( Game.getPlayerTurn() ) << endl << endl;
			nextAge = Game.nextPlayer();
		}
		/*Convert Card to Coins!*/
		else if ( move == "c" ) {
			check = 1;

			while ( check ) {
				cout << "Select a card (by position).\n";
				cin >> cardPos;

				if ( !cin.fail() && cardPos >= 1 && cardPos <= Game.getHandSize() ) {
					while ( 1 ) { //confirmation of cardPos
						cout << "Are you sure you want to discard card #" << cardPos << "? (y/n)\n";
						cin >> input;
		
						if ( input == "y" ) {
							check = 0;
							break;
						}
						else if ( input == "n" ) {
							break;
						}
					}
				}
				else {
					cout << "Select an appropriate card (by position).\n";
					cin.clear();
					cin.ignore(1000000, '\n');
				}
			}

			Game.disCard( cardPos - 1 );
			cout << "In hand:	" << Game.getPlayerHand( Game.getPlayerTurn() );
			cout << "In play:	" << Game.getPlayerPlayed( Game.getPlayerTurn() );
			cout << "Coins:		" << Game.getPlayerCoin( Game.getPlayerTurn() ) << endl << endl;
			nextAge = Game.nextPlayer();
		}
		/*else if ( move == "w" ) {
			cout << "Make Wonder" << endl;
		}*/
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
			if ( exit ){
				// calculates and displays player scores and winner of game
				Game.calcWinner();
				cout << "Play a new game? (y/n): ";
				cin >> newgame;
				if ( newgame == "y" ){
					exit = false;
					numPlayers = 0;
					while ( numPlayers>7 || numPlayers<=1 ) {
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
