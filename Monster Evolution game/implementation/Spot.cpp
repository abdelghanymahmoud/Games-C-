/* 
 * File:   Spot.cpp
 * Description: Spot class define a single cell of the game board in which having a player, monster or free space
 * Author: Abdelgany
 *
 */

#include <iostream>
#include "Spot.h"
#include "Player.h"
#include "Monster.h"
using namespace std;

/*
 * return: none
 * constructor without argument
 */
Spot::Spot() {
    id = 3;
}

/*
 * return: none
 * constructor with player object
 */
Spot::Spot(Player *pp) {
    id = 1;
    p = pp;
}

/*
 * return: none
 * constructor with monster object
 */
Spot::Spot(Monster *mm) {
    id = 2;
    m = mm;
}

/*
 * return: void
 * specify new id of the spot
 */
void Spot::setId(int idd) {
    id = idd;
}

/*
 * return: int
 * return id of the spot
 */
int Spot::getId() {
    return id;
}

/*
 * return: void
 * specify new player of the spot
 */
void Spot::setPlayer(Player *pp) {
    p = pp;
}

/*
 * return: Player*
 * return player of the spot
 */
Player* Spot::getPlayer() {
    return p;
}

/*
 * return: void
 * specify monster of the spot
 */
void Spot::setMonster(Monster *mm) {
    m = mm;
}

/*
 * return: Monster*
 * return monster of the spot
 */
Monster* Spot::getMonster() {
    return m;
}