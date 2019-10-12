/* 
 * File:   TicTacToe.h
 */

#ifndef TICTACTOE_H
#define	TICTACTOE_H


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

#include "Player.h"
#include "Deck.h"

class TicTacToe {
private:
    string str;

    int toval(string str);

    int getrow(int index);

    int getcol(int index);
public:
    Deck deck_list[10];
    int game_number;
    Player player_1;
    Player player_2;

    TicTacToe();

    bool validate_user_input(string);

    bool is_game_over();

    void get_user_input();

    void start_game();

    void inti();

    void printFile();
};

#endif	/* TICTACTOE_H */

