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
        string monsterName;
        int mobStr;
        //int sorcererRage;
        //bool defeated;
        int goldDrop;
        int foodDrop;
        bool keyDrop;
        //actions action_[5];


    public:
        Mob();
        Mob(string,int, int, int, bool);
        string getName();
        void setName(string);
        int getStr();
        void setStr(int);
        /*int getRage();
        void setRage(int);
        bool getStatus();
        void setStatus(bool, Action);*/
        int getGold();
        void setGold(int, bool);
        int getFood();
        void setFood(int, bool);
        bool getKey();
        void setKey(bool);
};
#endif
