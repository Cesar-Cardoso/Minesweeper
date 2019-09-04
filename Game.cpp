//
// Created by cardo on 7/29/2019.
//

#include "Game.h"
#include <fstream>
#include <vector>
#include <random>
#include <chrono>


Game::Game(string boardPath) {
    remainingMines = 0;
    ifstream input;
    input.open(boardPath);

    if (!input.good()){
        cout << "Problem loading board!" << endl;
        return;
    }

    for (int j = 0; j < HEIGHT; ++j) {
        for (int i = 0; i < WIDTH; ++i) {
            bool mine = input.get() == '1';

            if(mine) {
                board[i][j] = Mine;
                placedMine(Position {i , j});
                remainingMines++;
            }
        }
        input.ignore();
    }
     gameState = active;
     developerMode = false;
     emptyTiles = 400 - remainingMines;
}

Game::Game(int mineAmount) {
    remainingMines = mineAmount;
    gameState = active;
    developerMode = false;
    emptyTiles = 400 - remainingMines;

    vector<Position> emptyTiles;
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rand (seed);

    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            emptyTiles.push_back(Position {i , j});
        }
    }

    for (int _ = 0; _ < mineAmount; ++_) {
        uniform_int_distribution<int> distribution(0, emptyTiles.size());
        int selection = distribution(rand);
        Position selected = emptyTiles[selection];
        emptyTiles.erase(emptyTiles.begin() + selection);
        board[selected.x][selected.y] = Mine;
        placedMine(selected);
    }
}

void Game::printBoard() {
    cout << "\n\n\n";
    cout << "     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24\n";
    for (int j = 0; j < HEIGHT; ++j) {
        cout << j << " - " << (j < 10 ? " " : "");
        for (int i = 0; i < WIDTH; ++i) {
            Tile current = board[i][j];
            if (current.isFlagged())
                cout << "F  ";
            else if(developerMode || current.isRevealed())
                cout << current.symbol() << "  ";
            else
                cout << ".  ";
        }
        cout << endl;
    }
}

bool Game::clickTile(Position p) {

    Tile currentTile = board[p.x][p.y];

    if (currentTile.isRevealed() || currentTile.isFlagged())
        return false;

    if (currentTile.getValue() == Mine)
        endGame(false);

    else if (currentTile.getValue() == _0) {
        clickedEmpty(p);
        emptyTiles--;
    }

    else {
        board[p.x][p.y].reveal();
        emptyTiles--;
    }
    if(emptyTiles == 0)
        endGame(true);
    return true;
}

bool Game::flagTile(Position p) {
    if (board[p.x][p.y].isRevealed())
            return false;
    if (board[p.x][p.y].isFlagged())
        remainingMines--;
    else
        remainingMines++;
    board[p.x][p.y].flag();
    return true;
}

void Game::endGame(bool wonGame) {
    gameState = wonGame? won : lost;
    developerMode = false;
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            board[i][j] = board[i][j];
            board[i][j].reveal();
        }
    }
    cout << (wonGame ? ":)" : ":(");
}

GameState Game::getState() {
    return gameState;
}


void Game::restartGame() {
    gameState = active;
    developerMode = false;
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            board[i][j] = board[i][j];
        }
    }
}

bool Game::isValid(Position p) {
    return (p.x > -1 && p.x < WIDTH && p.y > -1 && p.y < HEIGHT);
}

void Game::placedMine(Position p) {
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            Position current = p + Position { i , j};
            TileValue temp = board[current.x][current.y].getValue();
            if (isValid(current) && temp != Mine) {
                TileValue v = (TileValue) (temp + 1);
                board[current.x][current.y].setValue(v);
            }
        }
    }
}

void Game::clickedEmpty(Position p) {
    board[p.x][p.y].reveal();

    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            Position current = p + Position{i, j};

            if (!isValid(current))
                continue;

            Tile currentTile = board[current.x][current.y];
            if (currentTile.getValue() != Mine && !currentTile.isRevealed() && !currentTile.isFlagged()) {
                board[current.x][current.y].reveal();
                emptyTiles--;
                if (currentTile.getValue() == _0)
                    clickedEmpty(current);
            }
        }
    }
}
