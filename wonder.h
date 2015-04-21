/* Max Walsh, wonder.h
 * This file contains the interface for the Wonder class which contains all of
 * the information for the Wonders that will be used in the game.
 * The wonder class is an inherited class of the base class.
 */

#ifndef WONDER_H
#define WONDER_H

#include <iostream>
#include <string>
//#include "Database.h" //pull information form a database of card types/effects/etc.

class Wonder {
	public:
		Wonder( int, int ); // non-default constructor
		//getInfo(); //pulls from the database
		//displayWonder(); //displays the Wonder name and information

	private:
		string name;
		int wonderID; //used to identify which info to pull from database
		int playerID; //player the wonder is tied to.
		int WonderLevel;
		int WonderBonus;
};
#endif
