//
// Created by micha on 4/21/2020.
//

#include "GameBoard.h"
#include "MatchChecker.h"

GameBoard::GameBoard(int dimension) {
    //Set dimensions of the board (square board)
    boardDimension = dimension;

    //create the 2-Dimensional array; make them pointers to their objects for ease of clearing later
    gameBoard = std::vector<std::vector<EngramCandy *>>();
    gameBoard.reserve(boardDimension);

    for (int i = 0; i < boardDimension; i++) {
        std::vector<EngramCandy *> columnI;
        columnI.reserve(boardDimension);

        for (int j = 0; j < boardDimension; j++) {
            columnI.push_back(new EngramCandy());
        }

        gameBoard.push_back(columnI);
    }
}

GameBoard::~GameBoard() {
    //loop through each of the cells, and free up the space of each EngramCandy?
    for (int i = 0; i < boardDimension; i++) {
        for (int j = 0; j < boardDimension; j++) {
            removeCandy(i, j);
        }
    }
}

//Perform a search to find if a match is possible with current board status?
//Possible usages: called after a move ends in a match and board updates; called after a board reset
void GameBoard::checkForMoves() {
    //searching helper function
    bool moveAvailable = searchBoardForMoves();

    if (!moveAvailable) {
        //Reset the whole board if no matching moves are found
        resetBoard();

        //Check if the new board has available moves
        checkForMoves();
    }
}



bool GameBoard::searchBoardForMoves() {
    //IDEA: Go through each of the elements in the 2-D array, and simulate if a match would occur if
    //      that element was moved left, up, right, or down (in that order)

    //A pointer to a boolean to determine if a match has been found yet; for-loops exit early if triggered early
    //Pass in boolean pointer so that this boolean can be changed by reference
    bool matchFound = false;
    bool * matchFoundPointer = &matchFound;

    //Nested for-loops, switch statement?
    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[i].size(); j++) {

            //Get the rarity of the current Candy at this position
            int rarityToTest = gameBoard[i][j]->getRarity();

            if (i != 0) {
                MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 1);
                if (matchFound) {
                    return true;
                }
            }

            if (j != 0) {
                MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 2);
                if (matchFound) {
                    return true;
                }
            }

            if (i != gameBoard.size() - 1) {
                MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 3);
                if (matchFound) {
                    return true;
                }
            }

            if (j != gameBoard[i].size() - 1) {
                MatchChecker::simulate(matchFoundPointer, this, rarityToTest, i, j, 4);
                if (matchFound) {
                    return true;
                }
            }
        }
    }
    return false;
}

void GameBoard::resetBoard() {
    //Set up a new gameBoard; maybe delete all current elements, and rerandomize to repopulate?
    //Kind of a mixture of both the destructor and constructor of GameBoard objects

    //Copied from destructor; get rid of everything currently in it
    for (int i = 0; i < boardDimension; i++) {
        for (int j = 0; j < boardDimension; j++) {
            removeCandy(i, j);
        }
    }

    //Initialize brand new board, with new EngramCandy instantiations, spaces already reserved
    for (int i = 0; i < boardDimension; i++) {
        for (int j = 0; j < boardDimension; j++) {
            EngramCandy * engramCandy = new EngramCandy();
            engramCandy->setXPos(i);
            engramCandy->setYPos(j);
            gameBoard[i][j] = engramCandy;
        }
    }
}

//Looks for any matches within the board, keeping track of all current matches within associative arrays(?) and then
//performing mass removals to get rid of the current matches
void GameBoard::checkForMatches() {
    //Very likely to need a helper

    //All 3 vectors are used together to locate matches; should all be of equal size
    //Keep track of the (x,y) points at which matches occur
    std::vector<std::pair<int, int>> matchSources;

    //Keep track of the directions in which matches occur from their sources;
    std::vector<int> matchDirs;

    //Keep track of the lengths of those matches
    std::vector<int> matchLengths;

    //Some operations to populate
    matchSources = MatchChecker::findMatchSources(this);
    matchDirs = MatchChecker::findMatchDirs(this);
    matchLengths = MatchChecker::findMatchLengths(this);

    //Iterative condition is within bounds for all 3 vectors; assume same size
    //Removes candies that form a match, but excludes the starting point of those matches
    for (int i = 0; i < matchSources.size(); i++) {
        switch(matchDirs[i]) {
            //Left
            case 1:
                for (int j = matchLengths[i] - 1; j > 0; j--) {
                    removeCandy(matchSources[i].first - j, matchSources[i].second);
                }
                break;
            //Up
            case 2:
                for (int k = matchLengths[i] - 1; k > 0; k--) {
                    removeCandy(matchSources[i].first, matchSources[i].second - k);
                }
                break;
            //Right
            case 3:
                for (int l = matchLengths[i] - 1; l > 0; l--) {
                    removeCandy(matchSources[i].first + l, matchSources[i].second);
                }
                break;
            //Down
            case 4:
                for (int m = matchLengths[i] - 1; m > 0; m--) {
                    removeCandy(matchSources[i].first, matchSources[i].second + m);
                }
                break;
        }
    }

    //Clean up the sources of the matches that were left behind
    for (int k = 0; k < matchSources.size(); k++) {
        removeCandy(matchSources[k].first, matchSources[k].second);
    }
}



//Moves an EngramCandy at a specified location in a given direction on the board; performs a swap
//Does not check for a match-3 in the board; may be used to swap entries back
// Precondition(?): Called only in a direction that will remain within boundaries
void GameBoard::swap(int x, int y, int direction) {

    EngramCandy * swappedCandy;
    switch(direction) {
        case 1: //Left
            swappedCandy = gameBoard[x-1][y];
            gameBoard[x-1][y] = gameBoard[x][y];
            gameBoard[x][y] = swappedCandy;
            break;
        case 2: //Up
            swappedCandy = gameBoard[x][y-1];
            gameBoard[x][y-1] = gameBoard[x][y];
            gameBoard[x][y] = swappedCandy;
            break;
        case 3: //Right
            swappedCandy = gameBoard[x+1][y];
            gameBoard[x+1][y] = gameBoard[x][y];
            gameBoard[x][y] = swappedCandy;
            break;
        case 4: //Down
            swappedCandy = gameBoard[x][y+1];
            gameBoard[x][y+1] = gameBoard[x][y];
            gameBoard[x][y] = swappedCandy;
            break;
        //no default needed
    }
}

//IDEA: Iterate over columns of the board, and count the number of NULL pointers in each column, and keep track
// of what y-positions in that column are NULL; iterate through each of the NULL locations, and shift everything
// above that spot down by a single space; this will also ensure fill-in of intermediate null locations in column
// Every element above the lowest NULL pointer drops down "number of NULL pointers under this element" places,
// and fill the top "number of NULL pointers" spaces with new EngramCandy()
void GameBoard::updateBoardByDrop() {


    //Iterate over board columns
    for (int i = 0; i < gameBoard.size(); i++) {

        //Number of null spaces in this column
        int numberOfNulls = 0;

        //Locations of null spaces (y-pos)
        std::vector<int> nullPlaces = std::vector<int>();
        for (int j = 0; j < gameBoard[i].size(); j++) {

            //If a space is empty (EngramCandy * = nullptr)
            if (gameBoard[i][j] == nullptr) {
                //Increment number of null spaces, and make note of location
                numberOfNulls++;
                nullPlaces.push_back(j);
            }
        }

        for (int nullLoc : nullPlaces) {
            //Move everything above the null space down by one spot
            for (int k = nullLoc - 1; k >= 0; k--) {
                gameBoard[i][k+1] = gameBoard[i][k];
            }
        }

        //Fill in the now opened spaces at the top of the column
        for (int m = 0; m < numberOfNulls; m++) {
            gameBoard[i][m] = new EngramCandy();
        }

    }

}

//Deletes an EngramCandy at specified coordinates in the GameBoard
void GameBoard::removeCandy(int x, int y) {
    //Deallocate the value of the EngramCandy that was pointed to
    delete gameBoard[x][y];
    //In case this gets deleted a second time, it should be set to a null value to prevent double delete bugs
    //Can be reset back to a valid piece of data on a subsequent new EngramCandy()
    gameBoard[x][y] = 0;
}

//Returns the dimension of the board (square-shaped)
int GameBoard::getBoardDimension() {
    return boardDimension;
}

//Returns the gameBoard itself as a 2-D vector
std::vector<std::vector<EngramCandy *>> GameBoard::getGameBoard() {
    return gameBoard;
}
