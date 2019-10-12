/* 
 * File:   Deck.h
 */

#ifndef DECK_H
#define	DECK_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
#include "Player.h"

class Deck {
public:
    char board[3][3];
    int player_1_choices[3][3];
    int player_2_choices[3][3];

    Deck();

    void print();

    friend ostream& operator<<(ostream& os, const Deck& ob) {
        os << "    |    |    " << endl;
        os << " " << ob.board[0][0] << "  | " << ob.board[0][1] << "  | " << ob.board[0][2] << endl;
        os << "____|____|____" << endl;
        os << " " << ob.board[1][0] << "  | " << ob.board[1][1] << "  | " << ob.board[1][2] << endl;
        os << "____|____|____" << endl;
        os << " " << ob.board[2][0] << "  | " << ob.board[2][1] << "  | " << ob.board[2][2] << endl;
        os << "    |    |    " << endl;
        return os;
    }
};


#endif	/* DECK_H */

