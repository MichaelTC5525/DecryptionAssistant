//
// Created by micha on 5/2/2020.
//

#ifndef DECRYPTIONASSISTANT_DAGAME_H
#define DECRYPTIONASSISTANT_DAGAME_H


#include "GameBoard.h"
#include "ScorePanel.h"

class DAGame {
public:
    DAGame();
    ~DAGame();

    void performMove();
    void updateScore();

private:
    GameBoard * gameBoard;
    ScorePanel * scorePanel;

};


#endif //DECRYPTIONASSISTANT_DAGAME_H
