//
// Created by cardo on 7/29/2019.
//

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Tile.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

enum GameState {
    active, lost, won
};

enum Img {
	debug = 0,
	digits = 1,
	face_happy = 2,
	face_lose = 3,
	face_win = 4,
	flag = 5,
	tile_revealed = 6,
	number_1 = 7,
	number_2 = 8,
	number_3 = 9,
	number_4 = 10,
	number_5 = 11,
	number_6 = 12,
	number_7 = 13,
	number_8 = 14,
	mine = 15,
	test_1 = 16,
	test_2 = 17,
	test_3 = 18,
	tile_hidden = 19
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
	int getMines();
	void setDev();
    void printBoard(Image*, RenderWindow*);
    bool clickTile(Position);
    bool flagTile(Position);
    GameState getState();
};


#endif //PROJECT3_GAME_H
