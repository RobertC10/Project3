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
#include "Mob.h"
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
        int numEncounterd;
        bool spaceExplored;
        string NPCPuzzle[50];
        bool puzzleCheck;
        //Mob npcHostile[50];
        void merchantMarket;

    public:
        NPC();
        NPC(int, bool, bool,/*Mob*/ void);
        int getNumNPC();
        bool setNumNPC(int);
        bool getspaceExplored();
        int setspaceExplored(bool);
        void setNPCPuzzle(bool);
        bool getbefriendPuzzle();
        int setbefriendPuzzle(bool);
        /*Mob getMob();
        bool setMob(bool, Mob)*/
        void merchantMarket(Party);
};

#endif
