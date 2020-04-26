//
// Created by micha on 4/21/2020.
//

#include "GameBoard.h"
#include "MatchChecker.h"

GameBoard::GameBoard(int dimension) {
    //create the 2-Dimensional array; make them pointers to their objects for ease of clearing later
    gameBoard = std::vector<std::vector<EngramCandy *>>();
    //Set dimensions of the board (square board)
    boardDimension = dimension;
    for (int i = 0; i < boardDimension; i++) {
        for (int j = 0; j < boardDimension; j++) {
            //Create new EngramCandy pointers for each slot
            EngramCandy * engramCandy = new EngramCandy();
            engramCandy->setXPos(i);
            engramCandy->setYPos(j);

            //Set the entry to the new created EngramCandy
            gameBoard[i][j] = engramCandy;
        }
    }


}

GameBoard::~GameBoard() {
    //loop through each of the cells, and free up the space of each EngramCandy?
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {
            removeCandy(i, j);
        }
    }
}

//Perform a search to find if a match is possible with current board status?
//Possible usages: called after a move ends in a match and board updates; called after a board reset
void GameBoard::checkForMoves() {
    //searching helper function
    bool moveAvailable = searchBoardForMoves();

    if (!moveAvailable) {
        //Reset the whole board if no matching moves are found
        resetBoard();

        //Check if the new board has available moves
        checkForMoves();
    }
}



bool GameBoard::searchBoardForMoves() {
    //Not a breadth-first search
    //IDEA: Go through each of the elements in the 2-D array, and simulate if a match would occur if
    //      that element was moved left, up, right, or down (in that order)

    //A pointer to a boolean to determine if a match has been found yet; for-loops exit early if triggered early
    //Pass in boolean pointer so that this boolean can be changed by reference
    bool matchFound = false;
    bool * matchFoundPointer = &matchFound;

    //Nested for-loops, switch statement?
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {

            //Get the rarity of the current Candy at this position
            int rarityToTest = gameBoard[i][j]->getRarity();

            switch(i) {
                case 0:
                    switch(j) {
                        case 0:
                            //Right, Down
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                            if (matchFound) {
                                return true;
                            }
                            break;
                        case 9:
                            //Up, Right
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                            if (matchFound) {
                                return true;
                            }
                            break;
                        default:
                            //Up, Right, Down
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                            if (matchFound) {
                                return true;
                            }
                            break;
                    }
                    break;
                case 9:
                    switch(j) {
                        case 0:
                            //Left, Down
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                            if (matchFound) {
                                return true;
                            }
                            break;
                        case 9:
                            //Left, Up
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                            if (matchFound) {
                                return true;
                            }
                            break;
                        default:
                            //Left, Up, Down
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                            if (matchFound) {
                                return true;
                            }
                            break;
                    }
                    break;
                default:
                    switch(j) {
                        case 0:
                            //Left, Right, Down
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                            if (matchFound) {
                                return true;
                            }
                            break;
                        case 9:
                            //Left, Up, Right
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                            if (matchFound) {
                                return true;
                            }
                            break;
                        default:
                            //Left, Up, Right, Down
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                            if (matchFound) {
                                return true;
                            }
                            MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                            if (matchFound) {
                                return true;
                            }
                            break;
                    }
                    break;
            }

        }
    }
    return false;
}

void GameBoard::resetBoard() {
    //Set up a new gameBoard; maybe delete all current elements, and rerandomize to repopulate?
    //Kind of a mixture of both the destructor and constructor of GameBoard objects

    //Copied from destructor; get rid of everything currently in it
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {
           removeCandy(i, j);
        }
    }

    //Copied from constructor
    //Initialize brand new board, with new EngramCandy instantiations
    for (int i = 0; i < boardDimension; i++) {
        for (int j = 0; j < boardDimension; j++) {
            EngramCandy * engramCandy = new EngramCandy();
            engramCandy->setXPos(i);
            engramCandy->setYPos(j);
            gameBoard[i][j] = engramCandy;
        }
    }
}

//Deletes an EngramCandy at specified coordinates in the GameBoard
void GameBoard::removeCandy(int x, int y) {
    delete gameBoard[x][y];
}

int GameBoard::getBoardDimension() {
    return boardDimension;
}

std::vector<std::vector<EngramCandy *>> GameBoard::getGameBoard() {
    return gameBoard;
}
