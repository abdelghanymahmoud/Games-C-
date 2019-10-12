#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

#include "Player.h"

Player::Player() {

}

Player::Player(string na, char playing_ma) {
    name = na;
    playing_mark = playing_ma;
}

int Player::get_score() const {
    return ((stats.won * 2) + stats.draw - stats.lost);
}

bool Player::operator<(Player obj) {
    return get_score() < obj.get_score();
}

bool Player::operator>(Player obj) {
    return get_score() > obj.get_score();
}

bool Player::operator==(Player obj) {
    return get_score() == obj.get_score();
}