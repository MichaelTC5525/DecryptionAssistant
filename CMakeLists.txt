cmake_minimum_required(VERSION 3.15)
project(DecryptionAssistant)

set(CMAKE_CXX_STANDARD 14)

add_executable(DecryptionAssistant main.cpp EngramCandy.cpp EngramCandy.h GameBoard.cpp GameBoard.h ScorePanel.cpp ScorePanel.h MatchChecker.cpp MatchChecker.h DAGame.cpp DAGame.h)