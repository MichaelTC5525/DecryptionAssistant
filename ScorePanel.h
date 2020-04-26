//
// Created by micha on 4/24/2020.
//

#ifndef DECRYPTIONASSISTANT_SCOREPANEL_H
#define DECRYPTIONASSISTANT_SCOREPANEL_H


class ScorePanel {
public:
    ScorePanel(int pointThreshold, int initMovesLeft);
    ~ScorePanel();
    int getPointPassThreshold();
    int getCurrPoints();
    int getMovesLeft();
    void checkAboveThreshold();

private:
    int pointPassThreshold;
    int currPoints;
    bool isAboveThreshold;
    int movesLeft;


};


#endif //DECRYPTIONASSISTANT_SCOREPANEL_H
