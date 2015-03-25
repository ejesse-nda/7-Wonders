/*Harrison Le
Wonder.h
*/
#include <iostream>
#include <string>
#include "Database.h" //pull information form a database of card types/effects/etc.

class Wonder {
	public:
		Wonder(); //initializes variables
		getInfo(); //pulls from the database
		displayWonder(); //displays the Wonder name and information

	private:
		string name;
		int WonderID; //used to identify which info to pull from database
		int PlayerID; //player the wonder is tied to.
		int WonderLevel;
		int WonderBonus;
};