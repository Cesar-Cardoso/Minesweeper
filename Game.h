//
// Created by cardo on 7/29/2019.
//

#ifndef PROJECT3_GAME_H
#define PROJECT3_GAME_H

#include "Tile.h"
#include <iostream>

using namespace std;

enum GameState {
    active, lost, won
};

class Game {
    static const int WIDTH = 25, HEIGHT = 16;
    Tile board[WIDTH][HEIGHT];
    GameState gameState;
    int remainingMines;
    bool developerMode;
    int emptyTiles;

    bool isValid(Position);
    void placedMine(Position);
    void clickedEmpty(Position);
    void endGame(bool);

public:
    explicit Game(string boardPath);
    Game(int mineAmount);
    void printBoard();
    bool clickTile(Position);
    bool flagTile(Position);
    GameState getState();
    void restartGame();
};


#endif //PROJECT3_GAME_H
