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
#include "Mob"
using namespace std;

int split (string input_string, char separator, string arr[], int arr_size)
{
    int tracker = 0;
    string temp = "";
   
    for (int i = 0; i < input_string.length(); i++)
    {
            if (tracker >= arr_size)
            {
                return -1;
            }
            
            if (input_string[i] != separator)
            {
                temp += input_string[i];
            }
            else
            {
                arr[tracker] = temp;
                temp = "";
                tracker++;
            }
    }
    
    arr[tracker] = temp;
    
    if (input_string != "")
    {
        tracker++;
    }
    
    return tracker;
}

Mob::Mob()
{
    //default constructor
    monsterName = "";
    mobStr = 0;
    sorcererRage = 0;
    defeated = false;
    goldDrop = 0;
    foodDrop = 0;
    keyDrop = 0;
}

Mob::Mob(string name, int str,int rage, bool status, int gold, int food, int key)
{
    //parameterized constructor
    monsterName = name;
    mobStr = str;
    sorcererRage = rage;
    defeated = status;
    goldDrop = gold;
    foodDrop = food;
    keyDrop = key;
}

int getName()
{
    //returns the monster's name after splitting it
    return name;
}

void setName(string name)
{
    //sets name to name of randomly selected mob based on file number rand
    name = monster[x][0];
}

int getStr()
{
    //returns the monster's strength after splitting it
    return str;
}

void setStr(int str)
{
    //sets str of the monster randomly selected that was split from file
    str = monster[x][1];
}

int getRage()
{
    //will return rage of the sorcerer as a value if the monster is such
    return rage;
}

void setRage(int rage)
{
    bool rageInclude;
    //will first run condition seeing if randomly selected mob is sorcerer
    //then out put it as a value to be adjusted in other classes
    if (monster[x] == 20)
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
}

int getGold()
{
    //returns the gold drop rate of the mob
    return gold;
}

void setGold(int gold, bool status)
{
    //will use a calculation to determine gold drop if defeated

    gold = 10 * str;

    if (status == true)
    {
        return gold;
    }
    else
    {
        return 0;
    }
}

int getFood()
{
    //returns the resource drop rate of the mob
    return food;
}

void setFood(int food, bool status)
{
    //will use a calculation to determine resource drop if defeated
    
    food = 5 * str;

    if (status == true)
    {
        return food;
    }
    else
    {
        return 0;
    }
}

bool getKey()
{
    //returns the key drop rate of the mob
    return key;
}

void setKey(bool key, bool status)
{
    //will use a calculation to determine key drop if defeated
    srand(time(0));
    int x = 0;
    for (int i = 0; i < 20; i++)
    {
       x = rand(i);
    }
    return x;

    if (status == true && x <= 20)
    {
        key = true;
    }
    else
    {
        key = false;
    }
}
