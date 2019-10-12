/* 
 * File:   Player.h
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

struct Statistics {
    int won, draw, lost;

    Statistics() {
        won = draw = lost = 0;
    }
};

class Player {
public:
    string name;
    char playing_mark;
    Statistics stats;

    Player();

    Player(string na, char playing_ma);

    int get_score() const;

    friend ostream& operator<<(ostream& os, const Player& ob) {
        os << "Player: " << ob.name << ", Mark: " << ob.playing_mark << ", Score: " << ob.get_score();
        return os;
    }

    bool operator<(Player obj);

    bool operator>(Player obj);

    bool operator==(Player obj);
};

#endif	/* PLAYER_H */

