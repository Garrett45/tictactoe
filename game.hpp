#ifndef GAME_HPP
#define GAME_HPP


class game {
private:
    //will become a 2d char pointer array
    char** board;
    int size;
public:
    game(int sizeIn);
    ~game();
    game(const game & g);
    game operator=(const game & g);
    void move (char player);
    void printBoard();
    bool hasWon();
    bool isMovesLeft();
};
#endif