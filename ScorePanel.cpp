//
// Created by micha on 4/24/2020.
//

#include "GameBoard.h"
#include "ScorePanel.h"

ScorePanel::ScorePanel(int pointThreshold, int initMovesLeft) {
    currPoints = 0;
    pointPassThreshold = pointThreshold;
    movesLeft = initMovesLeft;
    isAboveThreshold = false;
}


ScorePanel::~ScorePanel() {

}

int ScorePanel::getCurrPoints() {
    return currPoints;
}

int ScorePanel::getPointPassThreshold() {
    return pointPassThreshold;
}

int ScorePanel::getMovesLeft() {
    return movesLeft;
}

void ScorePanel::checkAboveThreshold() {
    if (currPoints >= pointPassThreshold) {
        isAboveThreshold = true;
    }
}

