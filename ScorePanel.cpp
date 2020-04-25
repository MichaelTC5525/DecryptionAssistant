//
// Created by micha on 4/24/2020.
//

#include "GameBoard.h"
#include "ScorePanel.h"

ScorePanel::ScorePanel() {
    currPoints = 0;

    //TODO: Temporary
    pointPassThreshold = 10000;

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

void ScorePanel::checkAboveThreshold() {
    if (currPoints >= pointPassThreshold) {
        isAboveThreshold = true;
    }
}

