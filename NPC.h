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
//#include "Mob.h"
#include "Party.h"
using namespace std;


/** Algorithm: An interface designed specifically for NPCs
 * 1. Initialize and establish all private and public members and member functions
 * Parameters: Various Items
 * Returns: Various Items
 * */

class NPC
{
    private:
        //Mob monsters[50];
        Party party_;
        //int numEncounterd;
        bool spaceExplored;
        bool puzzleCheck;
        bool merchantExit;
        string riddle[20];
        string riddleAns[20];

    public:
        NPC();
        NPC(bool, bool/*Mob*/, bool);
        /*int getNumNPC();
        void setNumNPC(int);*/
        bool getspaceExplored();
        bool setspaceExplored(bool, bool, bool);;
        bool getNPCPuzzle();
        bool setNPCPuzzle(bool);
        /*Mob getMob();
        bool setMob(bool, Mob)*/
        void merchantMarket(Party, bool);
};

#endif
