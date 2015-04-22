#ifndef CARD_H
#define CARD_H

#include <string>
using std::string;
#include <vector>
using std::vector;

class Card {

	public:
		Card();
		Card(string name);
		vector<string> getCost();
		vector<string> getResource();

	private:
		string Name;
		string Type;
		vector<string> Resource;
		vector<string> Cost;
		string FreePlayReq;

};

#endif
