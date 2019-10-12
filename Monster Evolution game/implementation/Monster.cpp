/* 
 * File:   Monster.cpp
 * description: Monster class define monster with specified characters
 * Author: Abdelgany
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Monster.h"
using namespace std;

/*
 * return: none
 * constructor without argument
 */
Monster::Monster() {

}

/*
 * return: none
 * constructor with monster name
 */
Monster::Monster(string typee) {
    // defaults of any monster
    type = typee;
    skills = rand() % 4;
    health = 3 + rand() % 4;
    powerModifier = 0;
    // add defaults of the Skeletor monster
    if (equalstrings(type, "Skeletor")) {
        skills = 10;
        health = 20;
        powerModifier = 2;
    }
}

/*
 * return: none
 * constructor with monster name, skill, healthy, power modifier
 */
Monster::Monster(string typee, int skillss, int healthh, int powerModifierr) {
    type = typee;
    skills = skillss;
    health = healthh;
    powerModifier = powerModifierr;
}

/*
 * return: string
 * return monster name
 */
string Monster::getType() {
    return type;
}

/*
 * return: void
 * specify new skills of the monster
 */
void Monster::setSkills(int skillss) {
    skills = skillss;
}

/*
 * return: int
 * return monster skill
 */
int Monster::getSkills() {
    return skills;
}

/*
 * return: void
 * specify new healthy of the monster
 */
void Monster::setHealth(int healthh) {
    health = healthh;
}

/*
 * return: int
 * return monster healthy
 */
int Monster::getHealth() {
    return health;
}

/*
 * return: void
 * specify new power modifier of the monster
 */
void Monster::setPowerModifier(int powerModifierr){
    powerModifier = powerModifierr;
}
/*
 * return: int
 * return monster power modifier
 */
int Monster::getPowerModifier(){
    return powerModifier;
}

/*
 * return:bool
 * if the two strings are equal
*/
bool Monster::equalstrings(string s1, string s2){
	if(s1.size() != s2.size()) return 0;
	int len = s1.size();
	for(int i = 0; i < len; i++){
		if(s1[i] != s2[i]) return 0;
	}
	return 1;
}