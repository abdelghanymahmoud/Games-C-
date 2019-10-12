/* 
 * File:   Player.cpp
 * Description: Player class define the player and his monsters
 * Author: Abdelgany
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Player.h"
#include "Monster.h"
using namespace std;

/*
 * return: none
 * constructor without argument
 */
Player::Player() {

}

/*
 * return: none
 * constructor with player name
 */
Player::Player(string namee) {
    name = namee;
    skills = 6;
    health = 10;
    Bugbear = 0;
    Platypie = 0;
    Emoo = 0;
    evolved = 0;
}

/*
 * return: string
 * return player name
 */
string Player::getName() {
    return name;
}

/*
 * return: void
 * specify new skills of the player
 */
void Player::setSkills(int skillss) {
    skills = skillss;
}

/*
 * return: int
 * return player skill
 */
int Player::getSkills() {
    return skills;
}

/*
 * return: void
 * specify new healthy of the player
 */
void Player::setHealth(int healthh) {
    health = healthh;
}

/*
 * return: int
 * return player healthy
 */
int Player::getHealth() {
    return health;
}

/*
 * return: void
 * specify new number of Bugbear monster
 */
void Player::setBugbear(int Bugbearr) {
    Bugbear = Bugbearr;
}

/*
 * return: int
 * return number of Bugbear monster
 */
int Player::getBugbear() {
    return Bugbear;
}

/*
 * return: void
 * specify new number of Platypie monster
 */
void Player::setPlatypie(int Platypiee) {
    Platypie = Platypiee;
}

/*
 * return: int
 * return number of Platypie monster
 */
int Player::getPlatypie() {
    return Platypie;
}

/*
 * return: void
 * specify new number of Emoo monster
 */
void Player::setEmoo(int Emooo) {
    Emoo = Emooo;
}

/*
 * return: int
 * return number of Emoo monster
 */
int Player::getEmoo() {
    return Emoo;
}

/*
 * return: void
 * specify new number of Evolved monster
 */
void Player::setEvolved(int evolvedd) {
    evolved = evolvedd;
}

/*
 * return: int
 * return number of Evolved monster
 */
int Player::getEvolved() {
    return evolved;
}

/*
 * return: void
 * add new monster catches by the player
 */
void Player::addMonster(Monster *m) {
    // distinguish between monsters (Bugbear, Platypie, Emoo)
    if (equalstrings(m->getType(), "Bugbear")) {
        // add the monster to the Bugbear list
        BugbearMonster.push_back(m);
        // increase number of Bugbear monsters
        Bugbear++;
        // when collecting 5 of the Bugbear monster
        if (Bugbear == 5) {
            // sum the total skills and healthy
            int skillsSum = 0, healthSum = 0;
            for (int i = 0; i < 5; i++) {
                skillsSum += BugbearMonster[i]->getSkills();
                healthSum += BugbearMonster[i]->getHealth();
            }
            // add the total summations to an evolved monster
            evolvedMonster = new Monster("Bugbear", skillsSum, healthSum, 1);
            Bugbear = 0;
            evolved++;
            // remove all monster
            BugbearMonster.clear();
            cout << "You have now evolved monster" << endl;
        }
    } else if (equalstrings(m->getType(), "Platypie")) {
        // add the monster to the Platypie list
        PlatypieMonster.push_back(m);
        // increase number of Platypie monsters
        Platypie++;
        // when collecting 5 of the Platypie monster
        if (Platypie == 5) {
            // sum the total skills and healthy
            int skillsSum = 0, healthSum = 0;
            for (int i = 0; i < 5; i++) {
                skillsSum += PlatypieMonster[i]->getSkills();
                healthSum += PlatypieMonster[i]->getHealth();
            }
            // add the total summations to an evolved monster
            evolvedMonster = new Monster("Platypie", skillsSum, healthSum, 2);
            Platypie = 0;
            evolved++;
            PlatypieMonster.clear();
            cout << "You have now evolved monster" << endl;
        }
    } else {
        // add the monster to the Emoo list
        EmooMonster.push_back(m);
        // increase number of Emoo monsters
        Emoo++;
        // when collecting 5 of the Emoo monster
        if (Emoo == 5) {
            // sum the total skills and healthy
            int skillsSum = 0, healthSum = 0;
            for (int i = 0; i < 5; i++) {
                skillsSum += EmooMonster[i]->getSkills();
                healthSum += EmooMonster[i]->getHealth();
            }
            // add the total summations to an evolved monster
            evolvedMonster = new Monster("Emoo", skillsSum, healthSum, 3);
            Emoo = 0;
            evolved++;
            // remove all monster
            EmooMonster.clear();
            cout << "You have now evolved monster" << endl;
        }
    }
}

/*
 * return Monster*
 * return object of the evolved monster
 */
Monster* Player::getEvolvedMonster() {
    return evolvedMonster;
}

/*
 * return:bool
 * if the two strings are equal
*/
bool Player::equalstrings(string s1, string s2){
	if(s1.size() != s2.size()) return 0;
	int len = s1.size();
	for(int i = 0; i < len; i++){
		if(s1[i] != s2[i]) return 0;
	}
	return 1;
}