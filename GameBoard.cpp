//
// Created by micha on 4/21/2020.
//

#include "GameBoard.h"
using namespace std;

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

//Perform a BFS / DFS search to find if a match is possible with current board status?
//Called after a move ends in a match and board updates
void GameBoard::checkForMoves() {
    //searching helper function
    /**
     * bool moveAvailable = searchBoard();
     * if (!moveAvailable) {
     *  shuffleBoard();
     * }
     */
}

bool GameBoard::searchBoard() {
    return false;
}

void GameBoard::shuffleBoard() {
    //Set up a new gameBoard; maybe delete all current elements, and rerandomize to repopulate?

}