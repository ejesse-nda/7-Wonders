#include "SevenWonders.h"
#include <iostream>
using namespace std;

int main(){

	bool exit=false;
	bool nextAge;
	int players=0;
char newgame;

	while (players>7 || players<=0){
		cout << "Choose number of players: ";
		cin >> players;
	}
	SevenWonders Game;
	Game.newGame(players);

	cout << "It is Age " << Game.getAge() << "." << endl;
	while (!exit){

		cout << "It is player " << Game.getPlayerTurn() << "'s turn." << endl;
		nextAge = Game.nextPlayer();
		if (nextAge) {
			exit = Game.advanceAge();
			if (exit){
				cout << "Play a new game? (y/n): ";
				cin >> newgame;
				if (newgame=='y'){
					exit = false;
					players = 0;
					while (players>7 || players<=1){
						cout << "Choose number of players: ";
						cin >> players;
					}
					Game.newGame(players);
					cout << "It is Age " << Game.getAge() << "." << endl;
				}
			} else cout << "It is Age " << Game.getAge() << "." << endl;
		}





	}

	return 0;

}
