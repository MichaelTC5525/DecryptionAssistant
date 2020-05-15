//
// Created by micha on 5/2/2020.
//

#include "DAGame.h"

DAGame::DAGame(int gameDimX, int gameDimY, int scoreToBeat, int movesToStart) {
    gameBoard = new GameBoard(gameDimX, gameDimY);
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
