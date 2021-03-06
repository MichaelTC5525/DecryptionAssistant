//
// Created by micha on 5/2/2020.
//

#ifndef DECRYPTIONASSISTANT_DAGAME_H
#define DECRYPTIONASSISTANT_DAGAME_H


#include "GameBoard.h"
#include "ScorePanel.h"

class DAGame {
public:
    DAGame(int gameDimX, int gameDimY, int scoreToBeat, int movesToStart);
    ~DAGame();

    void performMove();
    void updateScore();

private:
    GameBoard * gameBoard;
    ScorePanel * scorePanel;

};


#endif //DECRYPTIONASSISTANT_DAGAME_H
