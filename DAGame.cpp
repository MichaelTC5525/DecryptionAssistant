//
// Created by micha on 5/2/2020.
//

#include "DAGame.h"

DAGame::DAGame(int gameDim, int scoreToBeat, int movesToStart) {
    gameBoard = new GameBoard(gameDim);
    scorePanel = new ScorePanel(scoreToBeat, movesToStart);
}

DAGame::~DAGame() {
    delete[] gameBoard;
    delete scorePanel;
}

//May parameterize
void DAGame::performMove() {

}

//May parameterize
void DAGame::updateScore() {

}
