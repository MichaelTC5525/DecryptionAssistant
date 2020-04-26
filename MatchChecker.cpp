//
// Created by micha on 4/25/2020.
//

#include "MatchChecker.h"

//Simulate whether a move of an entry in a specified direction will cause a match of at least 3 or more to occur
//Updates a given pointer's dereference value if a match is found in that direction
//Does not change the state of the gameBoard, only checks to see if a match is possible with current state
void MatchChecker::simulate(bool *matchConfirmed, GameBoard *toCheckIn, int rarity, int x, int y, int direction) {
    //TODO: For each of the directional cases, set up recursive function(?) to determine length of match
    switch(direction) {
        case 1: //Left
            break;
        case 2: //Up
            break;
        case 3: //Right
            break;
        case 4: //Down
            break;
        //no default needed
    }
    *matchConfirmed = true;
}

//Moves an EngramCandy at a specified location in a given direction on the board; performs a swap
void MatchChecker::move(GameBoard * toMoveIn, int x, int y, int direction) {
    //TODO: swap depending on direction?
    EngramCandy * swappedCandy;
    switch(direction) {
        case 1: //Left
            swappedCandy = toMoveIn->getGameBoard()[x-1][y];
            toMoveIn->getGameBoard()[x-1][y] = toMoveIn->getGameBoard()[x][y];
            toMoveIn->getGameBoard()[x][y] = swappedCandy;
            break;
        case 2: //Up
            swappedCandy = toMoveIn->getGameBoard()[x][y-1];
            toMoveIn->getGameBoard()[x][y-1] = toMoveIn->getGameBoard()[x][y];
            toMoveIn->getGameBoard()[x][y] = swappedCandy;
            break;
        case 3: //Right
            swappedCandy = toMoveIn->getGameBoard()[x+1][y];
            toMoveIn->getGameBoard()[x+1][y] = toMoveIn->getGameBoard()[x][y];
            toMoveIn->getGameBoard()[x][y] = swappedCandy;
            break;
        case 4: //Down
            swappedCandy = toMoveIn->getGameBoard()[x][y+1];
            toMoveIn->getGameBoard()[x][y+1] = toMoveIn->getGameBoard()[x][y];
            toMoveIn->getGameBoard()[x][y] = swappedCandy;
            break;
        //no default needed
    }
}