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
        // GameBoard::searchBoardForMoves() switch-statement ensures that a case is only called if it will result
        // in a location within the bounds of the board
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

//Returns the largest simulated 1-dimensional length match sourced from a particular point in the gameBoard given
int MatchChecker::simMatchesAt(GameBoard *gb, int xCoord, int yCoord, int rarity) {
    int leftLength = 0;
    if (xCoord > 0) {
        leftLength = sim(gb, xCoord - 1, yCoord, rarity, 1);
    }
    int upLength = 0;
    if (yCoord > 0) {
        upLength = sim(gb, xCoord, yCoord - 1, rarity, 2);
    }
    int rightLength = 0;
    if (xCoord < gb->getBoardDimension() - 1) {
        rightLength = sim(gb, xCoord + 1, yCoord, rarity, 3);
    }
    int downLength = 0;
    if (yCoord < gb->getBoardDimension() - 1) {
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


std::vector<std::pair<int, int>> MatchChecker::findMatchSources(GameBoard *gb) {
    std::vector<std::pair<int, int>> retVal = std::vector<std::pair<int, int>>();
    for (int i = 0; i < gb->getBoardDimension(); i++) {
        for (int j = 0; j < gb->getBoardDimension(); j++) {

            //Lengths extending outside of a source point (i, j);
            int rarityToCheck = gb->getGameBoard()[i][j]->getRarity(); //rarity at this point
            int leftLen = 0;
            int upLen = 0;
            int rightLen = 0;
            int downLen = 0;
            leftLen = sim(gb, i - 1, j, rarityToCheck, 1);
            upLen = sim(gb, i, j - 1, rarityToCheck, 2);
            rightLen = sim(gb, i + 1, j, rarityToCheck, 3);
            downLen = sim(gb, i, j + 1, rarityToCheck, 4);

            // This set of emplacements likely will cause overlapping matches at different source points in the board
            // However, when these elements are deleted in GameBoard::removeCandy(), pointers are set to 0 and so
            //  multiple deletions should not be harmful
            if (1 + leftLen >= 3) {
                retVal.emplace_back(std::make_pair(i, j));
            }
            if (1 + upLen >= 3) {
                retVal.emplace_back(std::make_pair(i, j));
            }
            if (1 + rightLen >= 3) {
                retVal.emplace_back(std::make_pair(i, j));
            }
            if (1 + downLen >= 3) {
                retVal.emplace_back(std::make_pair(i, j));
            }
        }
    }
    return retVal;
}

std::vector<int> MatchChecker::findMatchDirs(GameBoard *gb) {
    std::vector<int> retVal = std::vector<int>();
    for (int i = 0; i < gb->getBoardDimension(); i++) {
        for (int j = 0; j < gb->getBoardDimension(); j++) {

            //Lengths extending outside of a source point (i, j);
            int rarityToCheck = gb->getGameBoard()[i][j]->getRarity(); //rarity at this point
            int leftLen = 0;
            int upLen = 0;
            int rightLen = 0;
            int downLen = 0;
            leftLen = sim(gb, i - 1, j, rarityToCheck, 1);
            upLen = sim(gb, i, j - 1, rarityToCheck, 2);
            rightLen = sim(gb, i + 1, j, rarityToCheck, 3);
            downLen = sim(gb, i, j + 1, rarityToCheck, 4);

            // This set of emplacements likely will cause overlapping matches at different source points in the board
            // However, when these elements are deleted in GameBoard::removeCandy(), pointers are set to 0 and so
            //  multiple deletions should not be harmful
            if (1 + leftLen >= 3) {
                retVal.emplace_back(1);
            }
            if (1 + upLen >= 3) {
                retVal.emplace_back(2);
            }
            if (1 + rightLen >= 3) {
                retVal.emplace_back(3);
            }
            if (1 + downLen >= 3) {
                retVal.emplace_back(4);
            }
        }
    }
    return retVal;
}

std::vector<int> MatchChecker::findMatchLengths(GameBoard *gb) {
    std::vector<int> retVal = std::vector<int>();
    for (int i = 0; i < gb->getBoardDimension(); i++) {
        for (int j = 0; j < gb->getBoardDimension(); j++) {

            //Lengths extending outside of a source point (i, j);
            int rarityToCheck = gb->getGameBoard()[i][j]->getRarity(); //rarity at this point
            int leftLen = 0;
            int upLen = 0;
            int rightLen = 0;
            int downLen = 0;
            leftLen = sim(gb, i - 1, j, rarityToCheck, 1);
            upLen = sim(gb, i, j - 1, rarityToCheck, 2);
            rightLen = sim(gb, i + 1, j, rarityToCheck, 3);
            downLen = sim(gb, i, j + 1, rarityToCheck, 4);

            // This set of emplacements likely will cause overlapping matches at different source points in the board
            // However, when these elements are deleted in GameBoard::removeCandy(), pointers are set to 0 and so
            //  multiple deletions should not be harmful
            if (1 + leftLen >= 3) {
                retVal.emplace_back(1 + leftLen);
            }
            if (1 + upLen >= 3) {
                retVal.emplace_back(1 + upLen);
            }
            if (1 + rightLen >= 3) {
                retVal.emplace_back(1 + rightLen);
            }
            if (1 + downLen >= 3) {
                retVal.emplace_back(1 + downLen);
            }
        }
    }
    return retVal;
}
