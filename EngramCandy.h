//
// Created by micha on 4/21/2020.
//

#ifndef DECRYPTIONASSISTANT_ENGRAMCANDY_H
#define DECRYPTIONASSISTANT_ENGRAMCANDY_H

class EngramCandy {
public:
    EngramCandy();
    ~EngramCandy();
    int getRarity();
    int getXPos();
    int getYPos();



private:

    //Represents common, uncommon, rare, legendary, exotic status (numbers 1-5 respectively)
    int rarity;

    //Represents x-position in game board array
    int xPos;

    //Represents y-position in game board array
    int yPos;
};


#endif //DECRYPTIONASSISTANT_ENGRAMCANDY_H
