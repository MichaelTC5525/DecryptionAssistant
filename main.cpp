#include <iostream>
#include <ctime>
#include "GameBoard.h"

int main() {
    srand(time(nullptr));
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Is this thing working?" << std::endl;

    int d = 78;
    int * asd = &d;
    std::cout << "The number is: " << *asd << std::endl;


    GameBoard * gameBoard = new GameBoard(10, 10);

    for (int i = 0; i < gameBoard->getBoardDimensionX(); i++) {
        for (int j = 0; j < gameBoard->getBoardDimensionY(); j++) {
            std::cout << gameBoard->getGameBoard()[i][j]->getRarity() << " ";
        }
        std::cout << std::endl;
    }

    delete gameBoard;
    gameBoard = 0;
    //Some startup procedures, initialize GUI (for much later)
    return 0;
}
