/* Max Walsh, wonder.cpp
 * This file contains the implementation for the wonder class. This class is
 * inherited from the Player base class and will have 7 inherited class for
 *  each wonder.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "player.h"
#include "wonder.h"

using namespace std;

// non-default constructor
Wonder::Wonder( int w, int p ) {
// assigns the correct values to for each wonder based on the inputted value
  switch ( w ) {
    case 1:
      name = "Colossus of Rhodes";
      wonderID = 1;
      playerID = p;
      WonderLevel = 2;
      WonderBonus = 2;
      break;

    case 2:
      name = "Great Pyramid of Giza";
      wonderID = 2;
      playerID = p;
      WonderLevel = 3;
      WonderBonus = 2;
      break;

    case 3:
      name = "Hanging Gardens of Babylon";
      wonderID = 3;
      playerID = p;
      WonderLevel = 1;
      WonderBonus = 3;
      break;

    case 4:
      name = "Lighthouse of Alexandria";
      wonderID = 4;
      playerID = p;
      WonderLevel = 4;
      WonderBonus = 2;
      break;

    case 5:
      name = "Mausoleum at Halicarnassus";
      wonderID = 5;
      playerID = p;
      WonderLevel = 3;
      WonderBonus = 3;
      break;

    case 6:
      name = "Statue of Zeus at Olympia";
      wonderID = 6;
      playerID = p;
      WonderLevel = 5;
      WonderBonus = 2;
      break;

    case 7:
      name = "Temple of Artemis at Ephesus";
      wonderID = 7;
      playerID = p;
      WonderLevel = 2;
      WonderBonus = 4;
      break;
  }
}


// returns score multiplier
int Wonder::getMult() {
  return ( WonderLevel + WonderBonus );
}

// displays the information for the wonder
void Wonder::displayWonder() {
  cout << "Wonder: " << setw(30) << setiosflags(ios::left) << name << "Level: "
       << setw(6) << WonderLevel << "Bonus: " << WonderBonus << endl;
}
