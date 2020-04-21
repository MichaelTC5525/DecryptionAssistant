//
// Created by micha on 4/21/2020.
//
#ifndef DECRYPTIONASSISTANT_GAMEBOARD_H
#define DECRYPTIONASSISTANT_GAMEBOARD_H


#include "EngramCandy.h"

class GameBoard {

public:
    GameBoard();
    ~GameBoard();
    void checkForMoves();

private:
    //Representation of the gameBoard as a 2-Dimensional vector array
    //std::vector<std::vector<EngramCandy>> gameBoard;

};


#endif //DECRYPTIONASSISTANT_GAMEBOARD_H
