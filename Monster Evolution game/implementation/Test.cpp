/* 
 * File:   Test.cpp
 * Description: testing the game classes
 * Author: Abdelgany
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Spot.h"
using namespace std;

int main() {
    /* initialize random seed: */
    srand(time(NULL));
    string name, mode;
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter mode of the game (normal or test): ";
    cin >> mode;
    Game g(name, mode);
    g.startGame();
}