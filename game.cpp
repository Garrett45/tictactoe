#include "game.hpp"
#include <iostream>

//this class is used for one object, but the destructor, copy constructor
//and assignment operator are created to ensure that there is no memory leaks
//and everything works as planned

game::game(int sizeIn) {
    board = new char*[sizeIn];
    size = sizeIn;

    for (int row = 0; row < size; row++) {
        board[row] = new char[size];
    }

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            board[row][col]=' ';
        }
    }
}

game::~game() {
    //ensure no memory leaks
    for (int row = 0; row < size; row++) {
        delete [] board[row];
    }
    delete [] board;
}

game::game(const game & g) {
    //ensures that if something of game class is copied that its
    //board pointer points to its own unique board
    board = new char*[g.size];
    size = g.size;

    for (int row = 0; row < size; row++) {
        board[row] = new char[size];
    }

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            board[row][col]=g.board[row][col];
        }
    }
}

game game::operator=(const game & g) {
    //this literally copies the copy contructor code, should look to fix
    board = new char*[g.size];
    size = g.size;

    for (int row = 0; row < size; row++) {
        board[row] = new char[size];
    }

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            board[row][col]=g.board[row][col];
        }
    }
}


void game::move(char player) {
    int rowIn, colIn;
    std::cout << "Where would you like to play? (row col)\n";
    std::cin >> rowIn >> colIn;

    if (rowIn >= 0 && rowIn < size && colIn >= 0 && colIn <size && board[rowIn][colIn] == ' ') {
        board[rowIn][colIn] = player;
    }
    else {
        std::cout << "Sorry! Invalid move. Try again.\n";
        move(player);
    }
}

void game::printBoard() {
    for(int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (col == size-1) {
                std::cout << " " << board[row][col] << " ";
            }
            else {
                std::cout << " " << board[row][col] << " |";
            }
        }
        std::cout << "\n";
        if (row != size-1) {
            for (int i = 0; i < size; i++) {
                std::cout << "--- ";
            }
            std::cout << "\n";
        }  
    }
}

bool game::hasWon() {
    char p;

    //check rows
    for (int row = 0; row < size; row++) {
        p = board[row][0];

        for (int col = 0; col < size; col++) {
            //if there is an item not filled in with the players
            //character, they did not win that row.
            //if the first of any row is blank, then no one will win the row
            if (board[row][col] != p||p==' ') {
                break;
            }
            //if it hasn't broken, and we've reached the lasted column,
            //and it is equal to player, they have won
            else if (col == size - 1) {
                return true;
            }
        }
    }

    //check cols
    for (int col = 0; col < size; col++) {
        p = board[0][col];

        for (int row = 0; row < size; row++) {
            //this uses similar logic to checking for rows,
            //just now in the column direction
            if (board[row][col] != p || p==' ') {
                break;
            }
            else if (row == size - 1) {
                return true;
            }
        }
    }

    //check diag
    int count = 0;
    p = board[0][0];
    if (p!=' ') {
        for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (row == col && board[row][col] == p) {
                count++;
            }
        }
    }
    }
    

    if (count == size) {
        return true;
    }

    //check anti-diag
    count = 0;
    p = board[0][size-1];
    if(p!=' ') {
        for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            //size is not indexed from 0, so subtract 1
            if (col == (size-1)-row && board[row][col] == p) {
                count++;
            }
        }
    }

    }
    
    if (count == size) {
        return true;
    }
    else {
        return false;
    }
}

bool game::isMovesLeft() {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col]==' ') {
                return true;
            }
        }
    }

    return false;
}