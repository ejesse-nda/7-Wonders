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

void Hand::clearHand() {
        cards.clear();
}
