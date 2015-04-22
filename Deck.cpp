#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "Card.h"
#include "Deck.h"

using namespace std;

Deck::Deck() : Card() {}

Deck::Deck(int n, int Age) {
        srand(time(0)); //seed for shuffle

        for (int i = 0; i < n; ++i) {
                addCard(i+(Age-1)*49);
        }

}

int Deck::dealCard() {
        int ID = cards[0];

        cards.erase(cards.begin()); //destroys first cell since card is being passed out (REMINDER: empty checking)

        return ID;
}

void Deck::shuffle() {
        random_shuffle(cards.begin(), cards.end()); //ah, algorithms

        return;
}

