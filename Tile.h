//
// Created by cardo on 7/29/2019.
//

#ifndef PROJECT3_TILE_H
#define PROJECT3_TILE_H

enum TileValue {
    _0 = 0, _1 = 1,_2 = 2, _3 = 3, _4 = 4, _5 = 5, _6 = 6, __7 = 7, _8 = 8, Mine = -1
};

struct Position {
    int x, y;

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
    Tile &operator=(const Tile &obj);
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
