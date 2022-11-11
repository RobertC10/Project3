// Mob.h

// CSCI 1300 Fall 2022
// Author: Punith Sandhu
// Recitation: 304 – Nikhith Sannidhi
// Project #3 

#ifndef MOB_H
#define MOB_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Action"
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
        int sorcererRage;
        bool defeated;
        int goldDrop;
        int foodDrop;
        bool keyDrop;
        Action action_[5];


    public:
        Mob();
        Mob(string,int, int, bool, int, int, int);
        string getName();
        void setName(string);
        int getStr();
        void setStr(int);
        int getRage();
        void setRage(int);
        bool getStatus();
        void setStatus(bool, Action);
        int getGold();
        void setGold(int, bool);
        int getFood();
        void setFood(int, bool);
        bool getKey();
        void getKey(bool, bool);
}
#endif
