/* 
 * File:   Monster.h
 * description: Monster class define monster with specified characters
 * Author: Abdelgany
 *
 */

#ifndef MONSTER_H
#define	MONSTER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Monster {
private:
    string type;
    int skills;
    int health;
    int powerModifier;
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
    Monster();

    /*
     * return: none
     * constructor with monster name
     */
    Monster(string);

    /*
     * return: none
     * constructor with monster name, skill, healthy, power modifier
     */
    Monster(string, int, int, int);

    /*
     * return: string
     * return monster name
     */
    string getType();


    /*
     * return: void
     * specify new skills of the monster
     */
    void setSkills(int);
    /*
     * return: int
     * return monster skill
     */
    int getSkills();

    /*
     * return: void
     * specify new healthy of the monster
     */
    void setHealth(int);
    /*
     * return: int
     * return monster healthy
     */
    int getHealth();
    /*
     * return: void
     * specify new power modifier of the monster
     */
    void setPowerModifier(int);
    /*
     * return: int
     * return monster power modifier
     */
    int getPowerModifier();
};

#endif	/* MONSTER_H */

