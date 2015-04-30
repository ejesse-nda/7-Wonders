#include "Card.h"
#include <iostream>
using namespace std;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main(){

	Card Mine("Mine");

	vector<string> temp;

	temp = Mine.getResource();
	cout << temp[0] << endl;

	temp = Mine.getCost();
	cout << temp[0] << endl;

	return 0;
}
