#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

#include "Player.h"
#include "Deck.h"
#include "TicTacToe.h"

int TicTacToe::toval(string str) {
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        index = index * 10 + (str[i] - '0');
    }
    return index;
}

int TicTacToe::getrow(int index) {
    if (index < 3)
        return 0;
    else if (index < 6)
        return 1;
    else
        return 2;
}

int TicTacToe::getcol(int index) {
    if (index < 3)
        return index;
    else if (index < 6)
        return index - 3;
    else
        return index - 6;
}

TicTacToe::TicTacToe() {
    game_number = 0;
    player_1.name = "X";
    player_1.playing_mark = 'X';
    player_2.name = "O";
    player_2.playing_mark = 'O';
    str = "";
}

bool TicTacToe::validate_user_input(string val) {
    for (int i = 0; i < val.size(); i++) {
        if (val[i] > '9' || val[i] < '0') {
            cout << "invalid move, move should be an integer" << endl;
            return 0;
        }
    }
    int index = toval(val);
    if (index > 8) {
        cout << "invalid move, move should be between 0 and 8" << endl;
        return 0;
    }
    int row = getrow(index), col = getcol(index);
    if (deck_list[game_number].board[row][col] != ' ') {
        cout << "invalid move, move should be in empty place" << endl;
        return 0;
    }
    if (game_number % 2 == 0) {
        deck_list[game_number].board[row][col] = 'X';
        deck_list[game_number].player_1_choices[row][col] = 1;
    } else {
        deck_list[game_number].board[row][col] = 'O';
        deck_list[game_number].player_2_choices[row][col] = 1;
    }
    return 1;
}

bool TicTacToe::is_game_over() {
    for (int i = 0; i < 3; i++) {
        if (deck_list[game_number].board[0][i] != ' ' &&
                deck_list[game_number].board[0][i] == deck_list[game_number].board[1][i] &&
                deck_list[game_number].board[0][i] == deck_list[game_number].board[2][i])
            return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (deck_list[game_number].board[i][0] != ' ' &&
                deck_list[game_number].board[i][0] == deck_list[game_number].board[i][1] &&
                deck_list[game_number].board[i][0] == deck_list[game_number].board[i][2])
            return 1;
    }
    if (deck_list[game_number].board[0][0] != ' ' &&
            deck_list[game_number].board[0][0] == deck_list[game_number].board[1][1] &&
            deck_list[game_number].board[0][0] == deck_list[game_number].board[2][2])
        return 1;
    if (deck_list[game_number].board[0][2] != ' ' &&
            deck_list[game_number].board[0][2] == deck_list[game_number].board[1][1] &&
            deck_list[game_number].board[0][2] == deck_list[game_number].board[2][0])
        return 1;
    return 0;
}

void TicTacToe::get_user_input() {
    string mark = "X";
    if (game_number % 2 == 1) mark = "O";
    while (1) {
        string in;
        cout << "Enter player " << mark << " move: ";
        cin >> in;
        if (validate_user_input(in)) break;
    }

}

void TicTacToe::start_game() {
    inti();
    system("CLS");
    cout << "Tic-Tac-Toe game number: " << (game_number + 1) << endl;
    deck_list[game_number].print();
    get_user_input();
    if (is_game_over()) {
        if (game_number % 2 == 0) {
            cout << "player X win!" << endl;
            player_1.stats.won++;
            player_2.stats.lost++;
        } else {
            cout << "player O win!" << endl;
            player_2.stats.won++;
            player_1.stats.lost++;
        }
        cout << "game over!" << endl;
        cout << player_1 << endl;
        cout << player_2 << endl;
        cout << "start a new game? (Y/N) ";
        string in;
        cin >> in;
        stringstream ss;
        ss << str << endl;
        ss << deck_list[game_number] << endl;
        str = ss.str();
        if (in[0] == 'Y' || in[0] == 'y') {
            game_number = 0;
            start_game();
        } else {
            printFile();
            return;
        }
    } else if (game_number == 8) {
        cout << "Draw, no more moves!" << endl;
        cout << "game over!" << endl;
        cout << player_1 << endl;
        cout << player_2 << endl;
        cout << "start a new game? (Y/N) ";
        string in;
        cin >> in;
        stringstream ss;
        ss << deck_list[game_number] << endl;
        str = ss.str();
        if (in[0] == 'Y' || in[0] == 'y') {
            game_number = 0;
            start_game();
        } else {
            printFile();
            return;
        }
    } else {
        game_number++;
        start_game();
    }
}

void TicTacToe::inti() {
    if (game_number == 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                deck_list[0].board[i][j] = ' ';
                deck_list[0].player_1_choices[i][j] = 0;
                deck_list[0].player_2_choices[i][j] = 0;
            }
        }
    } else {
        deck_list[game_number] = deck_list[game_number - 1];
    }
}

void TicTacToe::printFile() {
    ofstream out("TicTacToe.txt");
    out << str << endl;
    if(player_1 == player_2) out << "Draw" << endl;
    else if(player_1 > player_2) out << "Player X win" << endl;
    else out << "Player O win" << endl;
    out.close();
}
