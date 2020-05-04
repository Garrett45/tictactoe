#include <iostream>
#include "game.hpp"

int main() {
    char player;
    int size, rowIn, colIn;
    //default to true, change to false if no moves left
    bool isGameWon = true;

    std::cout << "This game is played on an nxn board. What size board would you like?\n";
    std::cout << "n=";

    std::cin >> size;

    game tictactoe = game(size);

    //hasWon runs after every play, so when it turns to true, we know the last play
    //caused the win
    while(tictactoe.hasWon() == false) {
        //since X is set in else, X is default and starts game
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
        std::cout << player << "'s turn" << std::endl;
        tictactoe.printBoard();
        tictactoe.move(player);

        if (tictactoe.isMovesLeft() == false) {
            isGameWon = false;
            break;
        }
    }

    tictactoe.printBoard();

    //there may be a case where the game is won on the last move. It's why
    //the isGameWon variable exist
    if (isGameWon) {
        std::cout << player << " has won!\n";
    }
    else {
        std::cout << "Draw :(" << std::endl;
    }
    
}