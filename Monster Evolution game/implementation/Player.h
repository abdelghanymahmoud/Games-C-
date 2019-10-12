/* 
 * File:   Player.h
 * Description: Player class define the player and his monsters
 * Author: Abdelgany
 *
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "Monster.h"
using namespace std;

class Player {
private:
    string name;
    int skills;
    int health;
    int Bugbear;
    int Platypie;
    int Emoo;
    int evolved;
    vector<Monster*> BugbearMonster;
    vector<Monster*> PlatypieMonster;
    vector<Monster*> EmooMonster;
    Monster *evolvedMonster;
	/*
	 * return:bool
	 * if the two strings are equal
	*/
	bool equalstrings(string, string);
public:

    /*
     * return: none
     * constructor without argument
     */
    Player();
    /*
     * return: none
     * constructor with player name
     */
    Player(string name);
    /*
     * return: string
     * return player name
     */
    string getName();
    /*
     * return: void
     * specify new skills of the player
     */
    void setSkills(int);
    /*
     * return: int
     * return player skill
     */
    int getSkills();
    /*
     * return: void
     * specify new healthy of the player
     */
    void setHealth(int);
    /*
     * return: int
     * return player healthy
     */
    int getHealth();

    /*
     * return: void
     * specify new number of Bugbear monster
     */
    void setBugbear(int);
    /*
     * return: int
     * return number of Bugbear monster
     */
    int getBugbear();

    /*
     * return: void
     * specify new number of Platypie monster
     */
    void setPlatypie(int);
    /*
     * return: int
     * return number of Platypie monster
     */
    int getPlatypie();

    /*
     * return: void
     * specify new number of Emoo monster
     */
    void setEmoo(int);
    /*
     * return: int
     * return number of Emoo monster
     */
    int getEmoo();

    /*
     * return: void
     * specify new number of Evolved monster
     */
    void setEvolved(int);
    /*
     * return: int
     * return number of Evolved monster
     */
    int getEvolved();

    /*
     * return: void
     * add new monster catches by the player
     */
    void addMonster(Monster *);

    /*
     * return Monster*
     * return object of the evolved monster
     */
    Monster* getEvolvedMonster();
};

#endif	/* PLAYER_H */

