//
// Created by micha on 4/25/2020.
//

#ifndef DECRYPTIONASSISTANT_MATCHCHECKER_H
#define DECRYPTIONASSISTANT_MATCHCHECKER_H


#include "GameBoard.h"
#include "EngramCandy.h"
#include <cmath>
#include <algorithm>

class MatchChecker {
public:
    //When simulating or moving items in a direction: Left = 1, Up = 2, Right = 3, Down = 4;
    static void simulate(bool * matchConfirmed, GameBoard * toCheckIn, int rarity, int x, int y, int direction);

    static std::vector<std::pair<int, int>> findMatchSources(GameBoard * gb);

    static std::vector<int> findMatchDirs(GameBoard * gb);

    static std::vector<int> findMatchLengths(GameBoard * gb);

private:
    static int simMatchesAt(GameBoard * gb, int xCoord, int yCoord, int rarity);
    static int sim(GameBoard * gameBoard, int x, int y, int rarity, int dir);
};


#endif //DECRYPTIONASSISTANT_MATCHCHECKER_H
