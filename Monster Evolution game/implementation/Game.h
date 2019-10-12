/* 
 * File:   Game.h
 * Author: Abdelgany
 *
 */

#ifndef GAME_H
#define	GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Monster.h"
#include "Spot.h"
using namespace std;

class Game {
private:
    vector<vector<Spot> > board;
    vector<vector<bool> > visited;
    vector<int> di, dj;
    int height;
    int width;
    pair<int, int> playerPosition, startPosition;
    bool view;

    /*
     * return void
     * initilize the spots of the dungeon
     */
    void init(string playerName);

    /*
     * return: void
     * initialize the direction at I-axis and J-axis
     *      up, right, down, left
     * di:  -1   0       1    0
     * dj   0    1       0    -1
     */
    void initDirections();

    /*
     * return: void
     * placing the monster of the game at random point in the dungeon
     * friend and unfriend monster in any free spot but Skeletor in the right edge of the dungeon
     */
    void placeMonsters();

    /*
     * return: void
     * placing the player of the game at random point in the left edge of the dungeon
     */
    void placePlayer(string);

    /*
     * return: bool
     * check weather a point in the range of the dungeon
     */
    bool validPoint(int, int);

    /*
     * return: int
     * random number between 0 to 9
     * a number on the I-axis
     */
    int randomI();

    /*
     * return: int
     * random number between 0 to 19
     * a number on the J-axis
     */
    int randomJ();

    /*
     * return: void
     * print the whole dungeon spots
     * if the mode test it will be seen else it will be hidden
     */
    void print();
    /*
     * return: void
     * call when user enter a direction to move for
     * direction = 0 -> up, 1 right, 2 down, 3 left
     */
    void move(int);

    /*
     * return: void
     * handle the meeting of a monster (friend or unfriend) at a given position
     * call other method after know the monster
     */
    void playWithMonster(int, int);

    /*
     * return: void
     * handle the catch of the friend monster at a specified position
     */
    void catchMonster(int, int);

    /*
     * return: void
     * handle a fight with Octopod monster at a specified position
     */
    void fightOctopod(int, int);

    /*
     * return: void
     * handle a fight with Skeletor monster at a specified position
     */
    void fightSkeletor(int, int);
public:
    /*
     * return: none
     * constructor with name of the player and the mode of the game (test, normal)
     */
    Game(string, string);

    /*
     * return: void
     * start the game play
     */
    void startGame();
};

#endif	/* GAME_H */

