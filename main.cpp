#include <iostream>
#include "Game.h"

int main() {
    //Game game = Game("./boards/testboard1.brd");
    Game game = Game(50);

    while (game.getState() == active) {
        game.printBoard();
        Position currentPlay;
        char action = '0';
        while (action != 'R' && action != 'F') {
            cout << "(R)eveal tile or (F)lag?\n";
            cin >> action;
            if (action != 'R' && action != 'F')
                cout << "Input must be 'R' or 'F'!\n";
        }
        cout << "Give x,y coordenates:\nx: ";
        cin >> currentPlay.x;
        cout << "\ny: ";
        cin >> currentPlay.y;
        if (action == 'R')
            game.clickTile(currentPlay);
        else if(action == 'F')
            game.flagTile(currentPlay);
        else {
            cout << "WTF happened here!!!\n";
            return 0;
        }
    }

    game.printBoard();
    cout << "You " << (game.getState() == won ? "won " : "lost ") << "the game.";
}