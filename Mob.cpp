// Mob.cpp

// CSCI 1300 Fall 2022
// Editor: Jevan Wiltz
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
    name = "";
    str = 0;
    gold = 0;
    food = 0;
    mobChosen = 0;
    //defeated = false;
}

Mob::Mob(string name_, int str_, int gold_, int food_, int mobChosen_)
{
    //parameterized constructor
    name = name_;
    str = str_;
    gold = gold_;
    food = food_;
    mobChosen = mobChosen_;
    //defeated = status;
}

string Mob::getName()
{
    //returns the monster's name after splitting it
    return name;
}

void Mob::setName(string name_)
{
    //sets name to name of randomly selected mob based on file number rand
    name = name_;
}

int Mob::getStr()
{
    //returns the monster's strength after splitting it
    return str;
}

void Mob::setStr(int str_)
{
    //sets str of the monster randomly selected that was split from file
    str = str_;
}

int Mob::getGold()
{
    //returns the gold drop rate of the mob
    return gold;
}

void Mob::setGold(int str_, int gold_)
{
    //will use a calculation to determine gold drop if defeated

    gold_ = 10 * str_;

    gold = gold_;
}

int Mob::getFood()
{
    //returns the resource drop rate of the mob
    return food;
}

void Mob::setFood(int str_, int food_)
{
    //will use a calculation to determine resource drop if defeated
    
    food_ = 5 * str_;

    food = food_;
}

int Mob::getmobChoices()
{
    return mobChosen;
}

void Mob::setmobChoices(int mobChosen_)
{
    mobChosen = mobChosen_;
}

void Mob::setMob(string name_, int str_, int mobChosen_, int gold_, int food_)
{
    int i = 0;
    string line;
    string temp_arr[21];

    srand(time(0));    
    //To be filled wherein the mob will be separated by name and strength/rating
            //They will then be assigned line-by-line to their own temp array
            //From there the array is randomly selected from a random num generator
            //Output array, and assign name and strength to respective mobs
            
    ifstream file_input;
    file_input.open("monsters.txt");
    while (getline (file_input, line))
    {
            split(line, ',', temp_arr, 21);

            mobName[i] = temp_arr[0];
            mobStr[i] = temp_arr[1];
            temp_arr[0] = "";
            temp_arr[1] = "";
            i++;
    }

        name_ = mobName[mobChosen_];
        str_ = stoi(mobStr[mobChosen_]);
        gold_ = 10 * str_;
        food_ = 5 * str_;

        name = name_;
        str = str_;
        gold = gold_;
        food = food_;
}

/*bool getStatus()
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