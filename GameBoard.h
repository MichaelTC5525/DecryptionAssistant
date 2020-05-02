//
// Created by micha on 4/21/2020.
//
#ifndef DECRYPTIONASSISTANT_GAMEBOARD_H
#define DECRYPTIONASSISTANT_GAMEBOARD_H

#include <iostream>
#include <vector>
#include "EngramCandy.h"

class GameBoard {

public:
    //Standard parameterized constructor
    GameBoard(int dimension);

    //Destructor
    ~GameBoard();

    //Scans the current board state for possible moves that would result in matches
    void checkForMoves();

    //Deletes the candy at the specified coordinates in the gameBoard;
    void removeCandy(int x, int y);

    //Returns size of square board
    int getBoardDimension();

    //Returns the gameBoard 2-D vector
    std::vector<std::vector<EngramCandy *>> getGameBoard();

    //Scans current board state for present matches, and removes them; drops down candies above removed ones
    void checkForMatches();

    //Swaps positions of 2 elements: one specified at x-y and the other directly next to it in a direction
    void swap(int x, int y, int direction);

private:
    //Helper function for public checkForMoves()
    bool searchBoardForMoves();

    //Helper function for public checkForMoves()
    void resetBoard();

    //Representation of the gameBoard as a 2-Dimensional vector array
    std::vector<std::vector<EngramCandy *>> gameBoard;

    //X and Y Dimensions of the GameBoard
    int boardDimension;

};


#endif //DECRYPTIONASSISTANT_GAMEBOARD_H
