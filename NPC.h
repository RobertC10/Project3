// NPC.h

// CSCI 1300 Fall 2022
// Editor: Jevan Wiltz
// Recitation: 304 – Nikhith Sannidhi
// Project #3 

#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime> 
#include <cstdlib>
#include <string>

#include "Party.h"
#include "Map.h"
#include "MainDriver.h"
using namespace std;


/** Algorithm: An interface designed specifically for NPCs
 * 1. Initialize and establish all private and public members and member functions
 * Parameters: Various Items
 * Returns: Various Items
 * */

class NPC
{
    private:
        Party party_;
        Map map_;
        bool spaceExplored;
        bool puzzleCheck;
        bool merchantExit;
        string riddle[20];
        string riddleAns[20];

    public:
        NPC();
        NPC(bool, bool, bool);
        bool getspaceExplored();
        void setspaceExplored(bool, bool, bool);;
        bool getNPCPuzzle();
        void setNPCPuzzle(bool);
        void merchantMarket(Map, Party, bool);      
};

#endif
