// NPC.cpp

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
#include "Party"
#include "NPC"
using namespace std;

NPC::NPC()
{
    //default constructor
    numEncounterd = 0;
    spaceExplored = false;
    puzzleCheck = false;
    monsters_ = "";
    merchantMarket = "";
}

NPC::NPC(int numEncounterd_, bool spaceExplored_, bool puzzleCheck_, Mob monsters_[50], void merchantMarket_)
{
    //parameterized constructor
    numEncountered = numEncounterd_;
    spaceExplored = spaceExplored_;
    puzzleCheck = puzzleCheck_;
    monsters = monsters_;
    merchantMarket = merchantMarket_;
}

int NPC::getNumNPC()
{
    //returns the num of NPC's encounterd thus far
    return numEncounterd_;
}

bool NPC::setNumNPC(int talkNPC)
{
    //if have already spoken to previous NPC's, ongoing count willl increment
}

bool NPC::getspaceExplored()
{
   //returns at the end whether the space is already explored or if the NPC interaction ends
    return spaceExplored_;
}

int NPC::setspaceExplored(bool puzzleCheck_)
{
    //If both the puzzle has been completed and the merchant menu for the NPC is exited, return space as explored
    if (puzzleCheck_ && merchantExit == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


bool NPC::getbefriendPuzzle()
{
    //returns the validity of the puzzle NPC presents on first interaction
    return puzzleCheck_;
}

void NPC::setNPCPuzzle(bool puzzleCheck)
{
    ifstream file_input;
    file_input.open(filename);

    int user_number = 0;
    string riddle;
    string temp_riddle[50];
    if (file_input.fail())
        {
            //cout << "Could not open file." << endl;
            return -1;
        }
    else
    {
        while (getline(file_input, riddle))
        {
            split (riddle, ',', temp_riddle, 50);
            //To be filled
        }
    }

    //will output a random puzzle and check against after splitting to see if user answer equals riddle key
}
int NPC::setbefriendPuzzle(bool puzzleCheck_)
{
    //if the player succeeds at completing the puzzle, return as such
    if (puzzleCheck_ == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Mob getMob()
{
  //returns the monster the NPC holds if the puzzle is failed
  return monsters_[1];
}

bool setMob (bool puzzleCheck_, Mob monsters_)
{
    //will ultimately make use of the puzzleCheck, determining if false a random selection of a monster
    //from monster.txt to be given as the punishment for NPC
    int monsterSelect = 0;

    if (puzzleCheck == false)
    {
        srand(time(0));
        for (int i = 0; i < 19; i++)
        {
            monsters_[i] = rand() % 19;
        }
        return true;
    }
    else
    {
        return false;
    }
}

void merchantMarket(Party party_)
{
    //will consist of multiple couts to establish a menu in which multiple options can result and produce random
    //products for purchase and will run through series of conditions taking in 
    //party resources to be used for checking/purchasing
}
