//
// Created by cardo on 7/29/2019.
//

#include "Tile.h"

Tile::Tile() {
    value = _0;
    position = {0 , 0};
    revealed = false;
    flagged = false;
}

Tile::Tile(TileValue value, Position position) {
    this->value = value;
    this->position = position;
    revealed = false;
    flagged = false;
}

Tile &Tile::operator=(const TileValue &obj) {
    value = obj;
    return *this;
}

void Tile::setValue(TileValue value) {
    this->value = value;
}

TileValue Tile::getValue() {
    return value;
}

void Tile::setPosition(Position position) {
    this->position = position;
}

Position Tile::getPosition() {
    return position;
}

void Tile::reveal() {
    revealed = true;
}

bool Tile::isRevealed() {
    return revealed;
}

void Tile::flag() {
    flagged = !flagged;
}

bool Tile::isFlagged() {
    return flagged;
}

char Tile::symbol() {
    switch (value) {
        case Mine:
            return '*';
        default:
            return '0' + value;
    }
}
