//
// Created by micha on 4/25/2020.
//

#ifndef DECRYPTIONASSISTANT_MATCHCHECKER_H
#define DECRYPTIONASSISTANT_MATCHCHECKER_H


#include "GameBoard.h"
#include "EngramCandy.h"

class MatchChecker {
public:
    //When simulating or moving items in a direction: Left = 1, Up = 2, Right = 3, Down = 4;
    static void simulate(bool * matchConfirmed, GameBoard * toCheckIn, int rarity, int x, int y, int direction);

    static void move(GameBoard * toMoveIn, int x, int y, int direction);

};


#endif //DECRYPTIONASSISTANT_MATCHCHECKER_H
