//
// Created by micha on 4/21/2020.
//

#include "EngramCandy.h"
#include <stdlib.h>

//Constructor for generic engram candy
EngramCandy::EngramCandy() {
    //initialize rarity value; setup x and y coordinates?
}

EngramCandy::~EngramCandy() {
    //delete this
}

//Returns rarity of this object
int EngramCandy::getRarity() {
    return rarity;
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


