//
// Created by micha on 4/25/2020.
//

#include "MatchChecker.h"

//Simulate whether a move of an entry in a specified direction will cause a match of at least 3 or more to occur
//Updates a given pointer's dereference value if a match is found in that direction
//Does not change the state of the gameBoard, only checks to see if a match is possible with current state
void MatchChecker::simulate(bool *matchConfirmed, GameBoard *toCheckIn, int rarity, int x, int y, int direction) {
    int matchLength = 0;
    switch(direction) {
        //ANY SIMULATED DIRECTION THAT IS TRIGGERED IS GUARANTEED TO EXIST WITHIN BOUNDS OF GAMEBOARD; as checked in
        // GameBoard::searchBoardForMoves() switch-statement; may or may not need to check for bounds when looking
        // at match length
        case 1: //Left
            matchLength = simMatchesAt(toCheckIn, x - 1, y, rarity);
            break;
        case 2: //Up
            matchLength = simMatchesAt(toCheckIn, x, y - 1, rarity);
            break;
        case 3: //Right
            matchLength = simMatchesAt(toCheckIn, x + 1, y, rarity);
            break;
        case 4: //Down
            matchLength = simMatchesAt(toCheckIn, x, y + 1, rarity);
            break;
        //no default needed
    }
    *matchConfirmed = (matchLength >= 3);
}

//Returns the largest 1-dimensional length match sourced from a particular point in the gameBoard given
int MatchChecker::simMatchesAt(GameBoard *gb, int xCoord, int yCoord, int rarity) {
    int leftLength = 0;
    if (xCoord != 0) {
        //leftLength = some recursion;
        leftLength = sim(gb, xCoord - 1, yCoord, rarity, 1);
    }
    int upLength = 0;
    if (yCoord != 0) {
        //upLength = some recursion
        upLength = sim(gb, xCoord, yCoord - 1, rarity, 2);
    }
    int rightLength = 0;
    if (xCoord != gb->getBoardDimension() - 1) {
        rightLength = sim(gb, xCoord + 1, yCoord, rarity, 3);
    }
    int downLength = 0;
    if (yCoord != gb->getBoardDimension() - 1) {
        downLength = sim(gb, xCoord, yCoord + 1, rarity, 4);
    }
    return 1 + std::max(leftLength + rightLength, upLength + downLength);
}

int MatchChecker::sim(GameBoard * gameBoard, int x, int y, int rarity, int dir) {
    //Check first for if the rarity matches
    if (gameBoard->getGameBoard()[x][y]->getRarity() == rarity) {
        //Check for edge cases; if we want to continue in a direction but are at a boundary of the board
        if ((x == 0 && dir == 1) || (x == gameBoard->getBoardDimension() - 1 && dir == 3) || (y == 0 && dir == 2) ||
            (y == gameBoard->getBoardDimension() - 1 && dir == 4)) {
            return 1;
        } else {
            //Determine which direction to continue in
            switch(dir) {
                //Continue accumulation
                case 1:
                    return 1 + sim(gameBoard, x - 1, y, rarity, dir);
                case 2:
                    return 1 + sim(gameBoard, x, y - 1, rarity, dir);
                case 3:
                    return 1 + sim(gameBoard, x + 1, y, rarity, dir);
                case 4:
                    return 1 + sim(gameBoard, x, y + 1, rarity, dir);
                //no default needed
            }
        }
    } else { //Rarity does not match, do not add any value to accumulated value
        return 0;
    }
}

//Moves an EngramCandy at a specified location in a given direction on the board; performs a swap
//Does not check for a match-3 in the board; may be used to swap entries back
// Precondition(?): When called, moving in a particular direction does not go outside GameBoard
void MatchChecker::swap(GameBoard * toMoveIn, int x, int y, int direction) {

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
