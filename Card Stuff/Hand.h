/*Hand.cpp*/
#include <iostream>
#include <vector>
#include "Card.cpp"
using namespace std;

template <typename T>
class Hand: public Card {
public:
	Hand(int);
	
	int selectCard(int);
	discardCard(int);
	increasePoints();
private:
	int handID;
};

template <typename T>
Hand<T>:Hand(int ID) {
	handID = ID;

	return;
}

template <typename T>
void Hand<T>::selectCard(int n) {
	int ID = discardCard(n);

	return ID;
}

int Hand<T>::discardCard(int n) {
	int ID = cards[n];
	for (i = n; i < cards.size; ++i) {
		cards[i] = cards[i + 1];
	}
	cards.pop_back();

	return ID;
}