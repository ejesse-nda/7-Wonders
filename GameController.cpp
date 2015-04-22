#include "SevenWonders.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	bool exit=false;
	bool nextAge;
	int players=0, cardNum;
	string newgame, move;

	while (players>7 || players<=0){
		cout << "Choose number of players: ";
		cin >> players;
	}
	SevenWonders Game( players );
	cout << "before new game" << endl;
	Game.newGame();
	cout << "after new game" << endl;

	exit = Game.advanceAge();
	cout << "It is Age " << Game.getAge() << "." << endl;
	while (!exit){

		cout << "It is player " << Game.getPlayerTurn() << "'s turn." << endl;
		cout << "Hand: " << Game.getPlayerHand(Game.getPlayerTurn()) << endl;

		cout << "Move (p/c/w/o/n): ";
		cin >> move;
		if (move == "p"){
			cin >> cardNum;

			Game.playCard(cardNum);
			cout << "In  Hand: " << Game.getPlayerHand(Game.getPlayerTurn()) << endl;
			cout << "In front: " << Game.getPlayerPlayed(Game.getPlayerTurn()) << endl;

		} else if (move == "c"){
			cout << "Get Coins" << endl;
		} else if (move == "w"){
			cout << "Make Wonder" << endl;
		} else if (move == "o"){
			cout << "Options" << endl;
		} else if (move == "e"){
			cout << "Exiting..." << endl;
			exit = true;
		} else if (move == "n"){
			cout << "Next Player..." << endl;
			nextAge = Game.nextPlayer();
		} else {
			cout << "Invalid Move" << endl;
		}

		if (nextAge) {
			exit = Game.advanceAge();
			if (exit){
				cout << "Play a new game? (y/n): ";
				cin >> newgame;
				if (newgame=="y"){
					exit = false;
					players = 0;
					while (players>7 || players<=1){
						cout << "Choose number of players: ";
						cin >> players;
					}
// must call SevenWonders class and reshuffle deck
					Game.newGame();
					exit = Game.advanceAge();
					cout << "It is Age " << Game.getAge() << "." << endl;
				} // what if press n or something else
			} else cout << "It is Age " << Game.getAge() << "." << endl;
		}





	}

	return 0;

}
