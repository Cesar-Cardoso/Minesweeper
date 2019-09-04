//
// Created by cardo on 7/29/2019.
//

#include "Game.h"
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

using namespace sf;

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
                placedMine(Position (i , j));
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
        uniform_int_distribution<int> distribution(0, emptyTiles.size() - 1);
        int selection = distribution(rand);
        Position selected = emptyTiles[selection];
        emptyTiles.erase(emptyTiles.begin() + selection);
        board[selected.x][selected.y] = Mine;
        placedMine(selected);
    }
}

int Game::getMines() {
	return remainingMines;
}

void Game::setDev() {
	developerMode = !developerMode;
}

void Game::printBoard(Image* images, RenderWindow *window) {
	Texture tempTexture, backTexture;
	backTexture.loadFromImage(images[tile_revealed]);
	Sprite temp, background;

	background.setTexture(backTexture);

	for (int j = 0; j < HEIGHT; ++j) {

		for (int i = 0; i < WIDTH; ++i) {
			Tile current = board[i][j];
			if (current.isFlagged()) {
				backTexture.loadFromImage(images[tile_hidden]);
				tempTexture.loadFromImage(images[flag]);
			}
			else if (current.isRevealed()) {
				backTexture.loadFromImage(images[tile_revealed]);
				tempTexture.loadFromImage(images[current.getValue()]);
			}
			else if (current.getValue() == Mine && developerMode) {
				backTexture.loadFromImage(images[tile_revealed]);
				tempTexture.loadFromImage(images[current.getValue()]);
			}
			else
				tempTexture.loadFromImage(images[tile_hidden]);

			temp.setTexture(tempTexture);
			temp.setPosition(Vector2f(i * 32, j * 32));
			background.setPosition(Vector2f(i * 32, j * 32));
			window->draw(background);
			window->draw(temp);
		}
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
        remainingMines++;
    else
        remainingMines--;
    board[p.x][p.y].flag();
    return true;
}

void Game::endGame(bool wonGame) {
    gameState = wonGame? won : lost;
    developerMode = false;
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
			if (board[i][j].getValue() == Mine)
				if (wonGame) {
					if (!board[i][j].isFlagged()) {
						board[i][j].flag();
						remainingMines--;
					}
				}
				else
					board[i][j].reveal();
        }
    }
}

GameState Game::getState() {
    return gameState;
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
