/* 
 * File:   Game.cpp
 * Author: Abdelgany
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Spot.h"
using namespace std;

/*
 * return void
 * initilize the spots of the dungeon
 */
void Game::init(string playerName) {
    // default parameters
    height = 10;
    width = 20;
    // specify the dimension of the board
    board.resize(height);
    visited.resize(height);
    for (int i = 0; i < height; i++) {
        board[i].resize(width);
        visited[i].resize(width);
    }
    // call placePlayer method to place the player in the dungeon
    placePlayer(playerName);
    // call placeMonsters method to place the monsters in the dungeon
    placeMonsters();
    // call initDirections mehtod to initializing the dirctions
    initDirections();
}

/*
 * return: void
 * initialize the direction at I-axis and J-axis
 *      up, right, down, left
 * di:  -1   0       1    0
 * dj   0    1       0    -1
 */
void Game::initDirections() {
    // up
    di.push_back(-1);
    dj.push_back(0);
    // right
    di.push_back(0);
    dj.push_back(1);
    // down
    di.push_back(1);
    dj.push_back(0);
    // left
    di.push_back(0);
    dj.push_back(-1);
}

/*
 * return: void
 * placing the monster of the game at random point in the dungeon
 * friend and unfriend monster in any free spot but Skeletor in the right edge of the dungeon
 */
void Game::placeMonsters() {
	int I = randomI(), J = randomJ();
    // inhabit 10 Bugbear monster
    int Bugbear = 10;
    // iterate until all inhabit
    while (Bugbear > 0) {
        // if the spot is free space
        if (board[I][J].getId() == 3) {
            board[I][J].setId(2);
            board[I][J].setMonster(new Monster("Bugbear"));
            Bugbear--;
        }
        I = randomI();
        J = randomJ();
    }
    // inhabit 10 Platypie monster
    int Platypie = 10;
    // iterate until all inhabit
    while (Platypie > 0) {
        // if the spot is free space
        if (board[I][J].getId() == 3) {
            board[I][J].setId(2);
            board[I][J].setMonster(new Monster("Platypie"));
            Platypie--;
        }
        I = randomI();
        J = randomJ();
    }
    // inhabit 10 Emoo monster
    int Emoo = 10;
    // iterate until all inhabit
    while (Emoo > 0) {
        // if the spot is free space
        if (board[I][J].getId() == 3) {
            board[I][J].setId(2);
            board[I][J].setMonster(new Monster("Emoo"));
            Emoo--;
        }
        I = randomI();
        J = randomJ();
    }
    // inhabit 10 Octopod monster
    int Octopod = 10;
    // iterate until all inhabit
    while (Octopod > 0) {
        // if the spot is free space
        if (board[I][J].getId() == 3) {
            board[I][J].setId(2);
            board[I][J].setMonster(new Monster("Octopod"));
            Octopod--;
        }
        I = randomI();
        J = randomJ();
    }
    // inhabit 1 Skeletor monster
    int Skeletor = 1;
    J = width - 1;
    // iterate until inhabit
    while (Skeletor > 0) {
        // if the spot is free space
        if (board[I][J].getId() == 3) {
            board[I][J].setId(2);
            board[I][J].setMonster(new Monster("Skeletor"));
            Skeletor--;
        }
        I = randomI();
    }
}

/*
 * return: void
 * placing the player of the game at random point in the left edge of the dungeon
 */
void Game::placePlayer(string playerName) {
    int I = randomI(), J = 0;
    // iterate until reach to a free space spot
    while (true) {
        if (board[I][J].getId() == 3) {
            // set its id to player id ( = 1)
            board[I][J].setId(1);
            // set the player in this spot
            board[I][J].setPlayer(new Player(playerName));
            // specify the start point of the player
            playerPosition = make_pair(I, J);
            startPosition = make_pair(I, J);
            break;
        }
        I = randomI();
    }
}

/*
 * return: bool
 * check weather a point in the range of the dungeon
 */
bool Game::validPoint(int I, int J) {
    return I >= 0 && I < height && J >= 0 && J < width;
}

/*
 * return: int
 * random number between 0 to 9
 * a number on the I-axis
 */
int Game::randomI() {
    return rand() % height;
}

/*
 * return: int
 * random number between 0 to 19
 * a number on the J-axis
 */
int Game::randomJ() {
    return rand() % width;
}

/*
 * return: void
 * print the whole dungeon spots
 * if the mode test it will be seen else it will be hidden
 */
void Game::print() {
	cout << "Player name: " << board[playerPosition.first][playerPosition.second].getPlayer()->getName() << ", ";
	cout << "Healthy: " << board[playerPosition.first][playerPosition.second].getPlayer()->getHealth() << ", ";
	cout << "Skills: " << board[playerPosition.first][playerPosition.second].getPlayer()->getSkills() << endl;
	cout << "Bugbear monster catches: " << board[playerPosition.first][playerPosition.second].getPlayer()->getBugbear() << ", ";
	cout << "Platypie monster catches: " << board[playerPosition.first][playerPosition.second].getPlayer()->getPlatypie() << ", ";
	cout << "Emoo monster catches: " << board[playerPosition.first][playerPosition.second].getPlayer()->getEmoo() << ", ";
	cout << "Evolved monster evolved: " << board[playerPosition.first][playerPosition.second].getPlayer()->getEvolved() << endl;
	if(board[playerPosition.first][playerPosition.second].getPlayer()->getEvolved() != 0){
		cout << "Evolved monster type: " << board[playerPosition.first][playerPosition.second].getPlayer()->getEvolvedMonster()->getType() << ", ";
		cout << "Skills: " << board[playerPosition.first][playerPosition.second].getPlayer()->getEvolvedMonster()->getSkills() << ", ";
		cout << "Healthy: " << board[playerPosition.first][playerPosition.second].getPlayer()->getEvolvedMonster()->getHealth() << ", ";
		cout << "Power modifier: " << board[playerPosition.first][playerPosition.second].getPlayer()->getEvolvedMonster()->getPowerModifier() << endl;
	}
    for (int i = 0; i < height; i++) {
        cout << "\t\t\t";
        for (int j = 0; j < width; j++) {
            // if the mode test
            if (view) {
                if (board[i][j].getId() == 1) { // if player spot
                    cout << "V ";
                } else if (board[i][j].getId() == 2) { // if monster sppot
                    if (board[i][j].getMonster()->getType() == "Bugbear") {
                        cout << "B ";
                    } else if (board[i][j].getMonster()->getType() == "Platypie") {
                        cout << "P ";
                    } else if (board[i][j].getMonster()->getType() == "Emoo") {
                        cout << "E ";
                    } else if (board[i][j].getMonster()->getType() == "Octopod") {
                        cout << "O ";
                    } else { // if Skeletor monster spot
                        cout << "S ";
                    }
                } else { // free space spot
                    cout << "- ";
                }
            } else { // if the mode normal
                if (board[i][j].getId() == 1) { // if the player spot
                    cout << "V ";
                } else if (visited[i][j]) { // visited spot
                    cout << "- ";
                } else { // unknown spot
                    cout << "* ";
                }
            }
        }
        cout << endl;
    }
    cout << "\t";
    cout << "Bugbear -> B, Platypie -> P, Emoo -> E, Octopod-> O, Skeletor -> S" << endl;
    cout << "\t\t\t";
    cout << "you -> V, space -> -, unknown -> *" << endl;
}

/*
 * return: void
 * call when user enter a direction to move for
 * direction = 0 -> up, 1 right, 2 down, 3 left
 */
void Game::move(int dir) {
    // mark the current position as visited
    visited[playerPosition.first][playerPosition.second] = true;
    int I = playerPosition.first + di[dir], J = playerPosition.second + dj[dir];
    // if not valid point return without execute any thing
    if (!validPoint(I, J)) {
        cout << "Can not move outside the dungeon." << endl;
        return;
    }
    // change the id of the last spot to free space
    board[playerPosition.first][playerPosition.second].setId(3);
    // specify the player of the new spot
    board[I][J].setPlayer(board[playerPosition.first][playerPosition.second].getPlayer());
    // change the player position to the new position
    playerPosition = make_pair(I, J);
    // if the new spot was free space the change its id to be player spot and return else call playWithMonster method with the new spot
    if (board[I][J].getId() == 3) {
        board[I][J].setId(1);
        return;
    }
    board[I][J].setId(1);
    playWithMonster(I, J);
}

/*
 * return: void
 * handle the meeting of a monster (friend or unfriend) at a given position
 * call other method after know the monster
 */
void Game::playWithMonster(int I, int J) {
    string monsterType = board[I][J].getMonster()->getType();
    cout << "You are with " << monsterType << " monster." << endl;
    // if friend monster call catchMonster method
    if (monsterType == "Bugbear" || monsterType == "Platypie" || monsterType == "Emoo") {
        catchMonster(I, J);
    } else if (monsterType == "Octopod") { // if unfriend and Octopod call fightOctopod methd
        fightOctopod(I, J);
    } else { // if Skeletor monster call fightSkeletor method
        fightSkeletor(I, J);
    }
}

/*
 * return: void
 * handle the catch of the friend monster at a specified position
 */
void Game::catchMonster(int I, int J) {
	string s;
	getline(cin, s);
    int value = 1 + rand() % 6;
    cout << "\t\tMonster skills level: " << board[I][J].getMonster()->getSkills() << endl;
	cout << "\t\tYour random generated number: " << value << endl;
    // catch the monster if the number entered greater than or equals the monster skills
    if (value >= board[I][J].getMonster()->getSkills()) {
        cout << "The monster add to your collection." << endl;
        board[I][J].getPlayer()->addMonster(board[I][J].getMonster());
    } else {
        cout << "The monster runs away." << endl;
    }
	cout << "Press enter to continue";
	getline(cin, s);
}

/*
 * return: void
 * handle a fight with Octopod monster at a specified position
 */
void Game::fightOctopod(int I, int J) {
	string s;
	getline(cin, s);
	while (true) {
		cout << "\t\tYour healthy: " << board[I][J].getPlayer()->getHealth() << endl;
		cout << "\t\tMonster healthy: " << board[I][J].getMonster()->getHealth() << endl;
		cout << "\t\tYour skills: " << board[I][J].getPlayer()->getSkills() << endl;
		cout << "\t\tMonster skills: " << board[I][J].getMonster()->getSkills() << endl;
        int randP = 1 + rand() % 6; // random number for player
        int randM = 1 + rand() % 6;// random number for the monster
		cout << "Random number generated for you: " << randP << endl;
		cout << "Random number generated for the Octopod monster: " << randM << endl;
        board[I][J].getPlayer()->setSkills(board[I][J].getPlayer()->getSkills() + randP);
        board[I][J].getMonster()->setSkills(board[I][J].getMonster()->getSkills() + randM);
        int pSkills = board[I][J].getPlayer()->getSkills();
        int mSkills = board[I][J].getMonster()->getSkills();
        if (pSkills > mSkills) {// player skills grater than monster skills
            cout << "The monster healthy reduced by one point." << endl;
             // reduce monster healthy
            board[I][J].getMonster()->setHealth(board[I][J].getMonster()->getHealth() - 1);
        } else if (pSkills < mSkills) {// monster skills grater than player skills
            cout << "Your healthy reduced by one point." << endl;
            // reduce player healthy
            board[I][J].getPlayer()->setHealth(board[I][J].getPlayer()->getHealth() - 1);
        } else { // draw
            cout << "Draw" << endl;
        }
        // if the player healthy finished the player eaten by the monster and lose
        if (board[I][J].getPlayer()->getHealth() == 0) {
            cout << "You lose the game." << endl << "\t\t\tGame Over..." << endl;
            system("PAUSE");
			exit(0);
        }
        // monster healthy finished and the player win
        if (board[I][J].getMonster()->getHealth() == 0) {
            cout << "You beat the Octopod monster." << endl;
            break;
        }
		cout << "Press enter to continue";
		getline(cin, s);
    }
}

/*
 * return: void
 * handle a fight with Skeletor monster at a specified position
 */
void Game::fightSkeletor(int I, int J) {
    // if the player do not have evolved monster return to his first point
    if (board[I][J].getPlayer()->getEvolved() == 0) {
        cout << "you do not have an evolved monster, you will return to start point of the dungeon." << endl;
        board[startPosition.first][startPosition.second].setPlayer(board[I][J].getPlayer());
        playerPosition = make_pair(startPosition.first, startPosition.second);
        board[startPosition.first][startPosition.second].setId(1);
        board[I][J].setId(2);
        return;
    }
	string s;
	getline(cin, s);
    while (true) {
		cout << "\t\tYour evolved monster healthy: " << board[I][J].getPlayer()->getEvolvedMonster()->getHealth() << endl;
		cout << "\t\tSkeletor monster healthy: " << board[I][J].getMonster()->getHealth() << endl;
		cout << "\t\tYour evolved monster skills: " << board[I][J].getPlayer()->getEvolvedMonster()->getSkills() << endl;
		cout << "\t\tSkeletor monster skills: " << board[I][J].getMonster()->getSkills() << endl;
		cout << "\t\tYour Power Modifier: " << board[I][J].getPlayer()->getEvolvedMonster()->getPowerModifier() << endl;
		cout << "\t\tSkeletor monster Power Modifier: " << board[I][J].getMonster()->getPowerModifier() << endl;
        int randP = 1 + rand() % 6; // random number for player
        int randM = 1 + rand() % 6; // random number for the monster
        cout << "Random number generated for your evoled monster: " << randP << endl;
		cout << "Random number generated for the Skeletor monster: " << randM << endl;
        // add the power modifier to the skills of each monster
        randP += board[I][J].getPlayer()->getEvolvedMonster()->getPowerModifier();
        randM += board[I][J].getMonster()->getPowerModifier();
        // change the skills of monster and player 's monster to the new values
        board[I][J].getPlayer()->getEvolvedMonster()->
                setSkills(board[I][J].getPlayer()->getEvolvedMonster()->getSkills() + randP);
        board[I][J].getMonster()->setSkills(board[I][J].getMonster()->getSkills() + randM);
        
        int pSkills = board[I][J].getPlayer()->getEvolvedMonster()->getSkills();
        int mSkills = board[I][J].getMonster()->getSkills();
//        cout << pSkills << " " << mSkills << endl;
        if (pSkills > mSkills) { // player monster skills grater than monster skills
            cout << "The Skeletor monster healthy reduced by one point." << endl;
            board[I][J].getMonster()->setHealth(board[I][J].getMonster()->getHealth() - 1); // reduce monster healthy
        } else if (pSkills < mSkills) {// monster skills grater than player monster skills
            cout << "Your evolved monster healthy reduced by one point." << endl;
            // reduce player monster healthy
            board[I][J].getPlayer()->getEvolvedMonster()->setHealth(board[I][J].getPlayer()->getEvolvedMonster()->getHealth() - 1);
        } else { // draw
            cout << "Draw" << endl;
        }
        // if the player monster healthy finished the player eaten by the monster and lose
        if (board[I][J].getPlayer()->getEvolvedMonster()->getHealth() == 0) {
            cout << "You lose the game." << endl << "\t\t\tGame Over..." << endl;
            system("PAUSE");
			exit(0);
        }
        // monster healthy finished and the player win
        if (board[I][J].getMonster()->getHealth() == 0) {
            cout << "You beat the Skeletor monster." << endl;
            cout << "Congratulation " << board[I][J].getPlayer()->getName() << " You Win The Game.";
            system("PAUSE");
			exit(0);
			
        }
		cout << "Press enter to continue";
		getline(cin, s);
    }
}

/*
 * return: none
 * constructor with name of the player and the mode of the game (test, normal)
 */
Game::Game(string playerName, string mode) {
    // calling the initializing method
    init(playerName);
    /*
     * create a view variable true if the user mode test and false otherwise
     */
    if (mode == "test") this->view = true;
    else this->view = false;
}

/*
 * return: void
 * start the game play
 */
void Game::startGame() {
    string instruction = "\t\t\t\tControl Keys:\n\t\tUP -> w, Right -> d, Down -> s, Left a, Quit -> q";
    char input;
    while (true) {
        // print instructions every iteration
        cout << instruction << endl;
        print();
        // take input from user
        cout << "Enter a key: ";
        cin >> input;
        if (input == 'w') { // means up
            move(0);// move up
        } else if (input == 'd') {// means right
            move(1);// move right
        } else if (input == 's') {// means down
            move(2);// move down
        } else if (input == 'a') {// means left
            move(3);// move left
        } else if (input == 'q') {// means quit
            break;
        } else { // invalid input
            cout << "Invalid input." << endl;
        }
    }
}
