#include <iostream>
#include <deque>
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

        //If there are cards in the Deck
        if (A.cards.size()>0){

                //Initiate deque iterator
                deque<int>::const_iterator i;

                //output first card
                i=A.cards.begin();
                output << *i;

                //output ", " then next card until deck end is reached
                for (i= A.cards.begin()+1; i!= A.cards.end(); ++i) output << ", " << *i;

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
        cout << cards.size();

        return cards.size();
}

void Card::displayCard() {
        for (int i = 0; i < cards.size(); i++) {
                cout << cards[i] << ", ";
        }

        cout<< endl;
}

int Card::checkEmpty() {
        return cards.empty();
}

void Card::clearCard() {
        cards.clear();
}
