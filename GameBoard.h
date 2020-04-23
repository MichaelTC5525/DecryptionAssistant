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
    GameBoard();
    ~GameBoard();
    void checkForMoves();

private:
    //Helper function for public checkForMoves()
    bool searchBoard();

    //Helper function for public checkForMoves()
    void shuffleBoard();

    //Representation of the gameBoard as a 2-Dimensional vector array
    std::vector<std::vector<EngramCandy *>> gameBoard;

    //X and Y Dimensions of the GameBoard
    int boardDimension;

};


#endif //DECRYPTIONASSISTANT_GAMEBOARD_H
