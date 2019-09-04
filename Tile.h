//
// Created by cardo on 7/29/2019.
//

#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

enum TileValue {
    _0 = 6, _1 = 7, _2 = 8, _3 = 9, _4 = 10, _5 = 11, _6 = 12, __7 = 13, _8 = 14, Mine = 15
};

struct Coordenate { // needed to check if buttons are pressed
	double x, y;
};

struct Position {
    int x, y;

	Position() {
		x = 0;
		y = 0;
	}

	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Position(Coordenate obj) {
		x = int(obj.x);
		y = int(obj.y);
	}

    Position &operator+(const Position &obj) {
        Position* result = new Position;
        result->x = x + obj.x;
        result->y = y + obj.y;
        return *result;
    }
};

class Tile {
    TileValue value;
    Position position;
    bool revealed;
    bool flagged;

public:
    Tile();
    Tile(TileValue, Position);
    Tile &operator=(const TileValue &obj);
    void setValue(TileValue);
    TileValue getValue();
    void setPosition(Position);
    Position getPosition();
    void reveal();
    bool isRevealed();
    void flag();
    bool isFlagged();
    char symbol();
};


#endif //PROJECT3_TILE_H
