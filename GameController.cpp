//
// File: GameController.cpp
// CSE20212, Sp2015
//
// Description: A text based driver program for the 7 Wonders game
//

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

	while ( numPlayers<3 || numPlayers>7 ) { //select number of players
		cout << "Choose number of players (3-7 players only): ";
		cin >> numPlayers;

		if ( !cin.fail() && numPlayers <= 7 && numPlayers >= 3 ) { //checks if int and < 5 and > 3
			do { //confirmation of numPlayers
				cout << numPlayers << " players entered. Are you sure? (y/n) ";
				cin >> input;
			} while ( input!="y" && input!="n" );
		}
		else { //check for invalid input and flush cin
			cout << "Please enter an appropriate number of players (3-5 players only).\n";
			cin.clear();
			cin.ignore(1000000, '\n');
		}
	}

	//Create game object
	SevenWonders Game(numPlayers);
	//Start a new game
	Game.newGame();


	/**Game Driver**/
	while (!exit){

		//Clear the screen
		system("clear");
		//Display age
		cout << "Age: " << Game.getAge() << endl << endl;
		//Display cards played and coins for each player
		for (int i=0; i<numPlayers; i++){
			cout << "Player " << i+1 << " Cards: " << Game.getPlayerPlayed(i+1);
			cout << "Player " << i+1 << " Coins: " << Game.getPlayerCoin(i+1) << endl << endl;
		}
		//Display current player's turn and current hand
		cout << endl << "It is Player " << Game.getPlayerTurn() << "'s turn." << endl;
		cout << "Hand:	" << Game.getPlayerHand( Game.getPlayerTurn() );
		
		// clears move to force into loop
		move = "0";
		//Get player's move
		while (move != "p" && move!="c" && move!="e"){
			cout << "Move [Play Card (p), Get Coins (c), Exit Game (e)]: ";
			cin >> move;
		}

		/**Moves**/
		/*Play a Card*/
		if ( move == "p" ) {
			//Get card to play
			cardPos = 0;
			while ( cardPos < 1 || cardPos > Game.getHandSize() ) {
				cout << "Select a card (by position).\n";
				cin >> cardPos;
				//Confirm card to play
				if ( !cin.fail() && cardPos >= 1 && cardPos <= Game.getHandSize() ) {
					do{
						cout << "Are you sure you want to play card #" << cardPos << "? (y/n) ";
						cin >> input;
					} while (input !="y" && input !="n"); //confirmation of cardPos

				}
				//Error check cardPos input
				else {
					cout << "Select an appropriate card (by position).\n";
					cin.clear();
					cin.ignore(1000000, '\n');
				}
			//Check that card is valid
			}

			//Add card to play queue
			Game.queuePlayCard( cardPos );
			//Next player's turn
			nextAge = Game.nextPlayer();
		}


		/*Convert Card to Coins!*/
		else if ( move == "c" ) {
			//Get card to turn into coins
			cardPos = 0;
			while ( cardPos < 1 || cardPos > Game.getHandSize() ) {
				cout << "Select a card to convert to coins (by position).\n";
				cin >> cardPos;
				//Confirm card to play
				if ( !cin.fail() && cardPos >= 1 && cardPos <= Game.getHandSize() ) {
					do {
						cout << "Are you sure you want to discard card #" << cardPos << "? (y/n) ";
						cin >> input;
					} while (input !="y" && input !="n"); //confirmation of cardPos
				}
				//Error check
				else {
					cout << "Select an appropriate card (by position).\n";
					cin.clear();
					cin.ignore(1000000, '\n');
				}
			} 

			//Queue to discard
			Game.queueDiscard( cardPos - 1 );
			//Next player's turn
			nextAge = Game.nextPlayer();
		}

		/*Exit*/
		else if ( move == "e" ) {
			cout << "Exiting..." << endl;
			exit = true;
		}

		//If the game calls for a new age, and the player did not specifically say to exit
		if ( nextAge && !exit ) {
			//AdvanceAge function returns whether the game is over
			exit = Game.advanceAge();
			//If the game is over...
			if ( exit ){
				//...calculate and display player scores and winner of game
				Game.calcWinner();

				//Get user input on playing a new game
				newgame = "\0";
				while (newgame != "y" && newgame!="n"){
					cout << "Play a new game? (y/n): ";
					cin >> newgame;
				}

				//If player decides to play again...
				if ( newgame == "y" ){
					//Reset main loop conditional
					exit = false;
					//Get number of players for a new game
					numPlayers = 0;
					while ( numPlayers<3 || numPlayers>7 ) { //select number of players
						cout << "Choose number of players (3-7 players only): ";
						cin >> numPlayers;

						if ( !cin.fail() && numPlayers <= 7 && numPlayers >= 3 ) { //checks if int and < 5 and > 3
							while ( input!="y" && input!="n" ) { //confirmation of numPlayers
								cout << numPlayers << " players entered. Are you sure? (y/n) ";
								cin >> input;
							}
						}
						else { //check for invalid input and flush cin
							cout << "Please enter an appropriate number of players (3-5 players only).\n";
							cin.clear();
							cin.ignore(1000000, '\n');
						}
					}

					//Set new num of players and start a new game
					Game.setNumPlayers(numPlayers);
					Game.newGame();
				}
			}//End game over condition
		}//End advance age condition
	}//End main driver loop

	return 0;

}
