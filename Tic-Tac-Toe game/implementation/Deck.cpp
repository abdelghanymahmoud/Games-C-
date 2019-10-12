#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
#include "Player.h"
#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
            player_1_choices[i][j] = 0;
            player_2_choices[i][j] = 0;
        }
    }
}

void Deck::print() {
    cout << "    |    |    " << endl;
    cout << " " << board[0][0] << "  | " << board[0][1] << "  | " << board[0][2] << endl;
    cout << "____|____|____" << endl;
    cout << " " << board[1][0] << "  | " << board[1][1] << "  | " << board[1][2] << endl;
    cout << "____|____|____" << endl;
    cout << " " << board[2][0] << "  | " << board[2][1] << "  | " << board[2][2] << endl;
    cout << "    |    |    " << endl;
}
