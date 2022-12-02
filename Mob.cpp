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

//default constructor
Mob::Mob()
{
    name = "";
    str = 0;
    gold = 0;
    food = 0;
    mobChosen = 0;
}

//parameterized constructor
Mob::Mob(string name_, int str_, int gold_, int food_, int mobChosen_)
{
    name = name_;
    str = str_;
    gold = gold_;
    food = food_;
    mobChosen = mobChosen_;
}

//returns the monster's name after splitting it
string Mob::getName()
{
    return name;
}

//sets name to name of randomly selected mob based on monster line number randomly selected and split
void Mob::setName(string name_)
{
    name = name_;
}

//returns the monster's strength after splitting it
int Mob::getStr()
{
    return str;
}

//sets str of the monster randomly selected that was split from file
void Mob::setStr(int str_)
{
    str = str_;
}

//returns the gold drop rate of the mob
int Mob::getGold()
{
    return gold;
}

//will use a calculation to determine gold drop if defeated
void Mob::setGold(int str_, int gold_)
{

    gold_ = 10 * str_;

    gold = gold_;
}

//returns the ingredient/resource drop rate of the mob
int Mob::getFood()
{
    return food;
}

//will use a calculation to determine ingredient/resource drop if defeated
void Mob::setFood(int str_, int food_)
{
    
    food_ = 5 * str_;

    food = food_;
}

//will return a number that randomly decides number of monster to be split based on inputs
int Mob::getmobChoices()
{
    return mobChosen;
}

//will set mob choices based on random rated declared based on the situation
void Mob::setmobChoices(int mobChosen_)
{
    mobChosen = mobChosen_;
}

//to allow a list of monsters to be split up line by line into monster name and strength/rating and
//store those in temporary arrays for later use, also allowing the gold and food drop rates to be 
//determined by the monster randomly chosen and split
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