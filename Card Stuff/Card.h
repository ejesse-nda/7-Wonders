/*Card.cpp*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Card {
public:
	Card();
	void addCard(int);
	int getSize();
	void displayCards();
protected:
	vector<T> cards;
};

/*ostream &operator << (ostream &out, CardDeck d) { //overloaded stream operator that prints deck
	for (deque<int>::iterator it = d.deck.begin(); it != d.deck.end(); it++) {
		if (it < d.deck.end() - 1) {
			out << (*it % 13) + 1 << ", "; //modulo shows correct card value
		}
		else {
			out << (*it % 13) + 1 << endl;
		}
	}

	return out;
}*/

template <typename T>
void Hand<T>::addCard(int ID) {
	cards.intsert(cards.begin(), ID);

	return;
}

int Card::getSize() {
	cout << cards.size();

	return cards.size();
}