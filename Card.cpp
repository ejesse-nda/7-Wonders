#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <limits>
#include "Card.h"

using namespace std;

void Card::addCard(int ID) {
        cards.push_back(ID);

        return;
}

int Card::dealCard() {
        int ID = cards[0];

        cards.erase(cards.begin()); //destroys first cell since card is being passed out (REMINDER: empty checking)

        return ID;
}


ostream& operator<<(ostream &output, const Card &A){

	Card B;

	//If there are cards in the Deck
	if (A.cards.size()>0){

		//Initiate deque iterator
		deque<int>::const_iterator i;

		//output first card
		i=A.cards.begin();
		output << "(1) " << B.getInfo(*i);

		int j = 1;
		//output ", " then next card until deck end is reached
		for (i= A.cards.begin()+1; i!= A.cards.end(); ++i) {
			j++;
			output << ", (" << j << ") " << B.getInfo(*i);
		}

		//output end line, as requested
		output << std::endl;

		//If no cards in the deck, print [Empty]
	} else {

		output << "[Empty]" << std::endl;

	}

	//Return output stream
	return output;

}

int Card::getSize() {
        return cards.size();
}

void Card::displayCard() {
        for (int i = 0; i < cards.size(); i++) {
                cout << cards[i] << ", ";
        }

        cout << endl;
}

int Card::checkEmpty() {
        return cards.empty();
}

int Card::clearCard() {
		int hold=cards[0];
        cards.clear();
		return hold;
}

int Card::returnCard(int cardNum){
	return cards[cardNum];
}


string Card::getInfo(int n) { //its a monster
        int ID = n; //cards[n];
        string line;

        fstream inFile("database.txt");

        inFile.seekg(ios::beg);
        for (int i = 0; i < ID; ++i) {
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        getline(inFile, line);

        string::size_type leftpos = line.find_first_of("\"") + 1;
        string::size_type rightpos = line.find_last_of("\"");

        return line.substr(leftpos, rightpos - leftpos);
}
