// Mob.h

// CSCI 1300 Fall 2022
// Editor: Jevan Wiltz
// Recitation: 304 – Nikhith Sannidhi
// Project #3 

#ifndef MOB_H
#define MOB_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime> 
#include <cstdlib>
#include <string>
#include "actions.h"
#include "Party.h"
#include "NPC.h"
using namespace std;


/** Algorithm: An interface designed specifically for Buffchat
 * 1. Initialize and establish all private and public members and member functions
 * Parameters: Various items
 * Returns: Various Items
 * */

class Mob
{
    private:
        string name;
        string mobName[21];
        string mobStr[21];
        int mobChosen;
        int str;
        int gold;
        int food;

    public:
        Mob();
        Mob(string,int, int, int, int);
        string getName();
        void setName(string);
        int getStr();
        void setStr(int);
        int getGold();
        void setGold(int, int);
        int getFood();
        void setFood(int, int);
        int getmobChoices();
        void setmobChoices(int);
        void setMob(string, int, int, int, int);
};
#endif
