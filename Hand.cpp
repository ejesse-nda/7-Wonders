#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "Card.h"
#include "Hand.h"

using namespace std;


Hand::Hand() {}

Hand::Hand(int ID) : Card() {
        handID = ID;
}

int Hand::gethandID() {
        return handID;
}

int Hand::selectCard(int n) {
        int ID = discardCard(n - 1);

        return ID;
}

int Hand::discardCard(int n) {
        int ID = cards[n];
        cards.erase(cards.begin() + n); //removes selected card from vector

        return ID;
}

string Hand::getInfo(int n) { //its a monster
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

void Hand::clearHand() {
        cards.clear();
}
