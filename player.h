/* Max Walsh, 7 Wonders
 * This is the interface file for the Player class. This instantiates for each
 * player in the 7 Wonders card game.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <Card.h>

class Player {

  public:
    Player();
    int getScore();
    void setScore( int );
    int getPlayerTurn();
    void setPlayerTurn( int );
    void PlayerTurn();  // gives player options when it is their turn


  private:
    string name;
    int score;
    string wonder;
    string ltplayer;
    string rtplayer;
    int Age;
    int coins;
    int finalscore;
    vector<Card> resources;
};
#endif
