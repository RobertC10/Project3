// Mob.cpp

// CSCI 1300 Fall 2022
// Author: Punith Sandhu
// Recitation: 304 – Nikhith Sannidhi
// Project #3

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime> 
#include <cstdlib>
#include <string>
#include "Mob.h"
#include "actions.h"
#include "Party.h"
#include "NPC.h"
using namespace std;

Mob::Mob()
{
    //default constructor
    monsterName = "";
    mobStr = 0;
    //sorcererRage = 0;
    //defeated = false;
    goldDrop = 0;
    foodDrop = 0;
    keyDrop = false;
}

Mob::Mob(string name, int str, int gold, int food, bool key)
{
    //parameterized constructor
    monsterName = name;
    mobStr = str;
    //sorcererRage = rage;
    //defeated = status;
    goldDrop = gold;
    foodDrop = food;
    keyDrop = key;
}

int getName()
{
    //returns the monster's name after splitting it
    return monsterName;
}

void setName(string name)
{
    //sets name to name of randomly selected mob based on file number rand
    monsterName = name;
}

int getStr()
{
    //returns the monster's strength after splitting it
    return mobStr;
}

void setStr(int str)
{
    //sets str of the monster randomly selected that was split from file
    mobStr = str;
}

/*int getRage()
{
    //will return rage of the sorcerer as a value if the monster is such
    return rage;
}

void setRage(int rage)
{
    int i = mob.getName();
    bool rageInclude;
    //will first run condition seeing if randomly selected mob is sorcerer
    //then out put it as a value to be adjusted in other classes
    if (name[i] == 20)
    {
        //rage = Action action[1-5];
        rageInclude = true;
    }
}

bool getStatus()
{
    //will determine monsters status as "alive" until defeated in action or etc
    return status;
}

void setStatus(bool status, Action action_)
{
    //will continuously monitor if mob is defeated in action
    while (action_[x])
    {
        if (partyWin = true)
        {
            status = false
        }
        else
        {
            status = true;
        }
    }
}*/

int getGold()
{
    //returns the gold drop rate of the mob
    return goldDrop;
}

void setGold(int gold, bool status)
{
    //will use a calculation to determine gold drop if defeated

    gold = 10 * mobStr;

    goldDrop = gold;
}

int getFood()
{
    //returns the resource drop rate of the mob
    return foodDrop;
}

void setFood(int food, bool status)
{
    //will use a calculation to determine resource drop if defeated
    
    food = 5 * mobStr;

    foodDrop = food;
}

bool getKey()
{
    //returns the key drop rate of the mob
    return keyDrop;
}

void setKey(bool key)
{
    //will use a calculation to determine key drop if defeated
    srand(time(0));
    int rand1 = 0;
    bool dropSuccess = false;

    for (int i = 0; i < 20; i++)
    {
        rand1 = (rand() & 1) < 10;

    }

    if (rand1 == 1)
    {
        dropSuccess = true;
    }
    else
    {
        dropSuccess = false;
    }

    keyDrop = dropSuccess;
}
