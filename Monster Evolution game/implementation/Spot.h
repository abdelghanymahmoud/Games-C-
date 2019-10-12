/* 
 * File:   Spot.h
 * Description: Spot class define a single cell of the game board in which having a player, monster or free space
 * Author: Abdelgany
 *
 */

#ifndef SPOT_H
#define	SPOT_H

#include <iostream>
#include "Player.h"
#include "Monster.h"
using namespace std;

class Spot {
private:
    int id; // player = 1, monster = 2, space = 3
    Player *p;
    Monster *m;
public:

    /*
     * return: none
     * constructor without argument
     */
    Spot();

    /*
     * return: none
     * constructor with player object
     */
    Spot(Player *);

    /*
     * return: none
     * constructor with monster object
     */
    Spot(Monster *);

    /*
     * return: void
     * specify new id of the spot
     */
    void setId(int);
    /*
     * return: int
     * return id of the spot
     */
    int getId();

    /*
     * return: void
     * specify new player of the spot
     */
    void setPlayer(Player *);

    /*
     * return: Player*
     * return player of the spot
     */
    Player* getPlayer();

    /*
     * return: void
     * specify monster of the spot
     */
    void setMonster(Monster *);

    /*
     * return: Monster*
     * return monster of the spot
     */
    Monster* getMonster();
};

#endif	/* SPOT_H */

