//
// Created by micha on 4/21/2020.
//

#include "EngramCandy.h"
#include <cstdlib>
#include <ctime>

//Constructor for generic engram candy
EngramCandy::EngramCandy() {
    //TODO: improve randomization of rarity generator; maybe in main?

    //Seed rand()?

    //Init rarity and points based on randomized rarity
    rarity = rand() % 5 + 1;
    pointValue = rarity * 100;
}

EngramCandy::~EngramCandy() {
    //delete this and other cleanup if needed
}

//Returns rarity of this object
int EngramCandy::getRarity() {
    return rarity;
}

int EngramCandy::getPointValue() {
    return pointValue;
}

//Returns x-position within game board array
int EngramCandy::getXPos() {
    return xPos;
}

//Returns y-position within game board array
int EngramCandy::getYPos() {
    return yPos;
}

void EngramCandy::setXPos(int x) {
    xPos = x;
}

void EngramCandy::setYPos(int y) {
    yPos = y;
}


