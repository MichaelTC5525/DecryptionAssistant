//
// Created by micha on 5/2/2020.
//

#include "DAGame.h"

DAGame::DAGame() {
    gameBoard = new GameBoard(10);
    scorePanel = new ScorePanel(10000, 30);
}

DAGame::~DAGame() {
    delete[] gameBoard;
    delete scorePanel;
}

void DAGame::performMove() {

}

void DAGame::updateScore() {

}
