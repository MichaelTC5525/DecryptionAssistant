//
// Created by micha on 4/24/2020.
//

#ifndef DECRYPTIONASSISTANT_SCOREPANEL_H
#define DECRYPTIONASSISTANT_SCOREPANEL_H


class ScorePanel {
public:
    ScorePanel();
    ~ScorePanel();
    int getPointPassThreshold();
    int getCurrPoints();
    void checkAboveThreshold();

private:
    int pointPassThreshold;
    int currPoints;
    bool isAboveThreshold;


};


#endif //DECRYPTIONASSISTANT_SCOREPANEL_H
