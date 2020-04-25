//
// Created by micha on 4/21/2020.
//

#include "GameBoard.h"

GameBoard::GameBoard() {
    //create the 2-Dimensional array; make them pointers to their objects for ease of clearing later
    gameBoard = std::vector<std::vector<EngramCandy *>>();
    boardDimension = 10;
    for (int i = 0; i < boardDimension; i++) {
        for (int j = 0; j < boardDimension; j++) {
            EngramCandy * engramCandy = new EngramCandy();
            engramCandy->setXPos(i);
            engramCandy->setYPos(j);
            gameBoard[i][j] = engramCandy;
        }
    }


}

GameBoard::~GameBoard() {
    //loop through each of the cells, and free up the space of each EngramCandy?
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {
            delete gameBoard[i][j];
        }
    }
}

//Perform a search to find if a match is possible with current board status?
//Called after a move ends in a match and board updates
void GameBoard::checkForMoves() {
    //searching helper function
    bool moveAvailable = searchBoardForMoves();

    if (!moveAvailable) {
        //Reset the whole board if no matching moves are found
        resetBoard();
    }
}

void GameBoard::removeCandy(int x, int y) {
    delete gameBoard[x][y];
}

bool GameBoard::searchBoardForMoves() {
    //TODO: Complete a search through the array
    //Not a breadth-first search
    //IDEA: Go through each of the elements in the 2-D array, and simulate if a match will occur if
    //      that element was moved left, up, right, or down (in that order)

    //A pointer to a boolean to determine if a match has been found yet; for-loops exit early if triggered early
    bool matchFound = false;
    bool * matchFoundPointer = &matchFound;

    //Nested for-loops, switch statement?
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {

            //Get the rarity of the current Candy at this position
            int rarityToTest = gameBoard[i][j]->getRarity();

            switch(i) {
                case 0:
                    //TODO: Switch-statement in first column of 2-D array
                    switch(j) {
                        case 0:
                            //simulateRight(rarityToTest);
                            //simulateDown(rarityToTest);
                            break;
                        case 9:
                            //simulateUp(rarityToTest);
                            //simulateRight(rarityToTest);
                            break;
                        default:
                            //simulateUp(rarityToTest);
                            //simulateRight(rarityToTest);
                            //simulateDown(rarityToTest);
                            break;
                    }

                    break;
                case 9:
                    //TODO: Switch-statement in last column of 2-D array
                    switch(j) {
                        case 0:
                            //simulateLeft(rarityToTest);
                            //simulateDown(rarityToTest);
                            break;
                        case 9:
                            //simulateLeft(rarityToTest);
                            //simulateUp(rarityToTest);
                            break;
                        default:
                            //simulateLeft(rarityToTest);
                            //simulateUp(rarityToTest);
                            //simulateDown(rarityToTest);
                            break;
                    }
                    break;
                default:
                    //TODO: Switch-statement in arbitrary column of 2-D array
                    switch(j) {
                        case 0:
                            //simulateLeft(rarityToTest);
                            //simulateRight(rarityToTest);
                            //simulateDown(rarityToTest);
                            break;
                        case 9:
                            //simulateLeft(rarityToTest);
                            //simulateUp(rarityToTest);
                            //simulateRight(rarityToTest);
                            break;
                        default:
                            //simulateLeft(rarityToTest);
                            //simulateUp(rarityToTest);
                            //simulateRight(rarityToTest);
                            //simulateDown(rarityToTest);
                            break;
                    }
                    break;
            }

        }
    }

    return false;
}

int GameBoard::getBoardDimension() {
    return boardDimension;
}

void GameBoard::resetBoard() {
    //Set up a new gameBoard; maybe delete all current elements, and rerandomize to repopulate?
    //Kind of a mixture of both the destructor and constructor of GameBoard objects

    //From destructor; get rid of everything currently in it
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {
            delete gameBoard[i][j];
        }
    }

    //From constructor
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