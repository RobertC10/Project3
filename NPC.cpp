// NPC.cpp

// CSCI 1300 Fall 2022
// Editor: Jevan Wiltz
// Recitation: 304 – Nikhith Sannidhi
// Project #3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime> 
#include <cstdlib>
#include <string>
//#include "Mob.h"
#include "actions.h"
#include "Party.h"
#include "NPC.h"
#include "Map.h"
#include "MainDriver.h"
using namespace std;

NPC::NPC()
{
    //default constructor
    //numEncounterd = 0;
    spaceExplored = false;
    puzzleCheck = false;
    //monsters_ = "";
    merchantExit = false;
}

NPC::NPC(bool spaceExplored_, bool puzzleCheck_ /*Mob monsters_[50]*/, bool merchantExit_)
{
    //parameterized constructor
    //numEncounterd = numEncounterd_;
    spaceExplored = spaceExplored_;
    puzzleCheck = puzzleCheck_;
    //monsters = monsters_;
    merchantExit = merchantExit_;
}
/*
int NPC::getNumNPC()
{
    //returns the num of NPC's encounterd thus far
    numEncountered = numEncounterd_;
}

void NPC::setNumNPC(int numEncounterd_)
{
    //if have already spoken to previous NPC's, ongoing count willl increment
}*/

bool NPC::getspaceExplored()
{
   //returns at the end whether the space is already explored or if the NPC interaction ends
    return spaceExplored;
}

bool NPC::setspaceExplored(bool spaceExplored_, bool puzzleCheck_, bool merchantExit_)
{
    //If both the puzzle has been completed and the merchant menu for the NPC is exited, return space as explored
    if (puzzleCheck_ && merchantExit_ == true)
    {
        spaceExplored_ = true;
    }
    else
    {
        spaceExplored_ = false;
    }

    return spaceExplored_;
}

bool NPC::getNPCPuzzle()
{
    //returns the validity of the puzzle NPC presents on first interaction
    return puzzleCheck;
}

bool NPC::setNPCPuzzle(bool puzzleCheck_)
{
    int i = 0;
    string line;
    string userAns = "";
    //string temp_riddle[20];
    //string temp_answer[20];
    string temp_arr[20];

    srand(time(0));
    int riddleChosen = rand() % 19;
    

    ifstream file_input;
    file_input.open("riddles.txt");
    while (getline (file_input, line))
    {
            split(line, '~', temp_arr, 20);

            riddle[i] = temp_arr[0];
            riddleAns[i] = temp_arr[1];
            temp_arr[0] = "";
            temp_arr[1] = "";
            i++;

            /*srand(time(0));
            switch(rand() % 19)
            {
                case 0:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << temp_riddle[0] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "candle")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;
                
                case 1:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[1] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "map")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 2:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[2] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "r")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 3:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[3] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "heroine")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 4:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[4] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "bookkeeper")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 5:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[5] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "silence")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 6:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[6] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "keyboard")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;
                
                case 7:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[7] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "towel")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;
                
                case 8:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[8] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "11")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;
                
                case 9:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[9] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "ENT")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 10:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[10] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "fishhook")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 11:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[11] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "m")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 12:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[12] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "incorrectly")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 13:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[13] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "umbrella")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 14:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[14] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "coin")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 15:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[15] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "alone")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 16:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[16] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "crows")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 17:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[17] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "beauty")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 18:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[18] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "3")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;

                case 19:
                    cout << "Ello there weary traveller! Spare me a moment of your time would you?" << endl;
                    cout << riddle[19] << " What am I?" endl;
                    cin >> userAns;
                    if (userAns == "bubble")
                    {
                        cout << "Congratulations! Great to make yer' acquaintance pal!" << endl;
                        puzzleCheck = true;
                    }
                    else
                    {
                        cout << "Guess this is the end for you, huh? Now DIE!!!" << endl;
                        puzzleCheck == false;
                    }
                    break;
            }*/

            //To be filled wherein the riddle will be separated by riddle and answer
            //They will then be assigned line-by-line to their own temp array
            //From there the array is randomly selected from a random num generator
            //Output array, prompt user input
            //Compare answers and determine the puzzle completion successfully to be returned as puzzleCheck
            //will output a random puzzle and check against after splitting to see if user answer equals riddle key
    }

        cout << riddle[riddleChosen] << endl
        << "What am I?" << endl;
        cin >> userAns;

        if (userAns == riddleAns[riddleChosen])
        {
            cout << "Congratulations! Great to make yer acquaintance mate!" << endl;
            puzzleCheck_ = true;
        }
        else
        {
            cout << "Too bad! You got it wrong...so JUST DIE!" << endl;
            puzzleCheck_ = false;
        }

    return puzzleCheck_;
}

/*Mob getMob()
{
  //returns the monster the NPC holds if the puzzle is failed
  return monsters[];
}

bool setMob (bool puzzleCheck_, *Mob monsters_)
{
    //will ultimately make use of the puzzleCheck, determining if false a random selection of a monster
    //from monster.txt to be given as the punishment for NPC
    int monsterSelect = 0;

    if (puzzleCheck_ == false)
    {
        srand(time(0));
        for (int i = 0; i < 20; i++)
        {
            monsters_[i] = rand() % 20;
        }
        return true;
    }
    else
    {
        return false;
    }

    monsters[] = monsters_[];
}*/

bool NPC::getmerchantUse()
{
    return merchantExit;
}

void NPC::setmerchantUse(bool merchantExit_)
{
    merchantExit = merchantExit_;
}

void NPC::merchantMarket(Map map_, Party party_, bool merchantExit_)
{
    string user = "";
    //will consist of multiple couts to establish a menu in which multiple options can result and produce random
    //products for purchase and will run through series of conditions taking in 
    //party resources to be used for checking/purchasing
    party_.printStats();
  cout<<"There is a prisoner here? He looks kinda odd though..."<<endl;
  cout<<"He asks you if you want to buy something [Y/N]?"<<endl;   
  cin >> user;
  if(user[0]=='y'||user[0]=='Y') {
        int choice = 0;
         cout << "If you're looking to get supplies, you've come to the right place."<< endl
              << "If it ain't broke, it worth some gold!!" << endl;
         cout << "                                       " << endl
              << "Choose one of the following: " << endl
              << "1. Ingredients: Better than rats, I guarantee that mate." << endl
              << "2. Cookware: You fancy Sire Gordon Ramseyth The Fourth?." << endl
              << "3. Weapons: Even the best knights wish they had this!" << endl
              << "4. Armor: You think you can take a hit without this?" << endl
              << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl
              << "6. Leave: Be sure you got eve'ythin mate. I'm gone after 'dis!" << endl;
         cout << "> "; 
         cin >> choice;
         if(choice==1){
                              int itemSelect1 = 0;
                              cout << "How many kg of ingredients mate [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                              cin >> itemSelect1;

                              if (itemSelect1 == 0)
                              {
                                return merchantMarket(map_, party_, merchantExit_);
                              }
                              else if (itemSelect1 % 5 != 0)
                              {
                                cout << "Enter a valid amount: " << endl;
                                cin >> itemSelect1;
                              }
                              else
                              {
                                if(party_.subGold((itemSelect1)) == 0)
                                {
                                    cout<<"You don't have enough gold to buy that."<<endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                }
                                else
                             {
                                party_.addIngredients(itemSelect1);
                                cout << "Thanks for your patronage young sire! *He gives you a toothless grin*" << endl;
                                cout << "" << endl;
                                return merchantMarket(map_, party_, merchantExit_);
                              }
                              }
                            }
         if(choice==2){
                             int itemSelect2 = 0;
                             string choice2 = "";
                             int quantity = 0;
                              cout << "Pots 'n pans I reckon? Some are stronger than the others." << endl;
                              cout << "Choose one of the following:" << endl
                              << "1. (25%) Ceramic Pot [2 Gold]" << endl
                              << "2. (10%) Frying Pan [10 Gold]" << endl
                              << "3. ( 2%) Cauldron [20 Gold]" << endl
                              << "4. Cancel" << endl;
                              cout << "" << endl;
                              cin >> itemSelect2;
                              cout << "> " << itemSelect2 << endl;
                              switch (itemSelect2)
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " pots for " << quantity * 2  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice2;
                                    if (choice2[0] == 'Y' || choice2[0] == 'y')
                                    {
                                        if(party_.subGold((quantity * 2)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addCookwareAt(itemSelect2 - 1, quantity);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice2[0] == 'N' || choice2[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect2;
                                    }
                                    break;

                                case 2:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " pans for " << quantity * 10  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice2;
                                    if (choice2[0] == 'Y' || choice2[0] == 'y')
                                    {
                                        if(party_.subGold((quantity * 10)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addCookwareAt(itemSelect2 - 1, quantity);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice2[0] == 'N' || choice2[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect2;
                                    }
                                    break;
                                
                                case 3:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " cauldrons for " << quantity * 20  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice2;
                                    if (choice2[0] == 'Y' || choice2[0] == 'y')
                                    {
                                        if(party_.subGold((quantity * 20)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addCookwareAt(itemSelect2 - 1, quantity);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice2[0] == 'N' || choice2[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect2;
                                    }
                                    break;

                                case 4:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                    break;

                                default: cout << "Please put a valid choice:" << endl;
                                         cin >> itemSelect2;
                                    break;
                              }

                             }
         if(choice==3) {
                             int itemSelect3 = 0;
                             string choice3 = "";
                             int quantity2 = 0;
                              cout << "Might ya be one of those collectors? I have several combative sets that might put a real kick in yer game." << endl;
                              cout << "Choose one of the following:" << endl
                              << "1. Stone Club [2 Gold]" << endl
                              << "2. Iron Spear [2 Gold]" << endl
                              << "3. (+1) Mythril Rapier [5 Gold]" << endl
                              << "4. (+2) Flaming Battle-Axe [15 Gold]" << endl
                              << "5. (+3) Vorpal Longsword [50 Gold]" << endl
                              << "6. Cancel" << endl;
                              cout << "" << endl;
                              cin >> itemSelect3;
                              cout << "> " << itemSelect3 << endl;
                              switch (itemSelect3)
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " clubs for " << quantity2 * 2  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 2)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(itemSelect3 - 1, quantity2);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect3;
                                    }
                                    break;

                                case 2:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " spears for " << quantity2 * 2  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 2)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(itemSelect3 - 1, quantity2);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect3;
                                    }
                                    break;
                                
                                case 3:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " rapiers for " << quantity2 * 5  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 5)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(itemSelect3 - 1, quantity2);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect3;
                                    }
                                    break;

                                case 4:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " battle-axes for " << quantity2 * 15  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 15)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(itemSelect3 - 1, quantity2);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect3;
                                    }
                                    break;
                                
                                case 5:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " longswords for " << quantity2 * 50  << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 50)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(itemSelect3 - 1, quantity2);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect3;
                                    }
                                    break;

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                    break;
                                
                                default: cout << "Please put a valid choice:" << endl;
                                         cin >> itemSelect3;
                                    break;
                              }
                             }
         if(choice==4) {
                               int itemSelect4 = 0;
                               cout << "The heavier, the more...won't you shake a poor sinner's hand? [5 Gold/suit] (Enter a positive integer, or 0 to cancel)" << endl;
                               cin >> itemSelect4;

                               if (itemSelect4 == 0)
                               {
                                return merchantMarket(map_, party_, merchantExit_);
                               }
                               else
                               {
                                if(party_.subGold((itemSelect4 * 5)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addArmor(itemSelect4);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                               }
                             }
         if(choice==5) {
                             int itemSelect5 = 0;
                             string choice5 = "";
                             int quantity3 = 0;
                              cout << "Oh....my...might I just lighten yer load and take some of those beauts of yer'self?" << endl;
                              cout << "Choose one of the following:" << endl
                              << "1. Silver Ring" << endl
                              << "2. Ruby Necklace" << endl
                              << "3. Emerald Bracelet" << endl
                              << "4. Diamond Circlet" << endl
                              << "5. Gem-Encrusted Goblet" << endl
                              << "6. Cancel" << endl;
                              cout << "" << endl;
                              cin >> itemSelect5;
                              cout << "> " << itemSelect5 << endl;
                              switch (itemSelect5)
                              {
                                case 1:
                                    if (party_.getRoomsCleared() >= 1)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " rings for " << quantity3 * 10 << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice5;
                                    if (choice5[0] == 'Y' || choice5[0] == 'y')
                                    {
                                        if(party_.subTreasuresAt(itemSelect5 - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(itemSelect5 - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect5;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    break;

                                case 2:
                                    if (party_.getRoomsCleared() >= 2)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " necklaces for " << quantity3 * 20 << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice5;
                                    if (choice5[0] == 'Y' || choice5[0] == 'y')
                                    {
                                        if(party_.subTreasuresAt(itemSelect5 - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(itemSelect5 - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect5;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    break;
                                
                                case 3:
                                    if (party_.getRoomsCleared() >= 3)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " bracelets for " << quantity3 * 30 << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice5;
                                    if (choice5[0] == 'Y' || choice5[0] == 'y')
                                    {
                                        if(party_.subTreasuresAt(itemSelect5 - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(itemSelect5 - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect5;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    break;

                                case 4:
                                    if (party_.getRoomsCleared() >= 4)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " rings for " << quantity3 * 40 << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice5;
                                    if (choice5[0] == 'Y' || choice5[0] == 'y')
                                    {
                                        if(party_.subTreasuresAt(itemSelect5 - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(itemSelect5 - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect5;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    break;
                                
                                case 5:
                                    if (party_.getRoomsCleared() >= 5)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " rings for " << quantity3 * 50 << " gold? (y/n)" << endl;
                                    cout << "" << endl;
                                    cin >> choice5;
                                    if (choice5[0] == 'Y' || choice5[0] == 'y')
                                    {
                                        if(party_.subTreasuresAt(itemSelect5 - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(itemSelect5 - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> itemSelect5;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    break;

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                    break;
                                
                                default: cout << "Please put a valid choice:" << endl;
                                         cin >> itemSelect5;
                                    break;
                              }
                             }
         if(choice==6) {
                             string choice6 = "";
                             cout << "Are you completely sure? It'll be terrible if you lose items or run out of things. (Y/n)" << endl;
                             cin >> choice6;

                             if (choice6[0] == 'Y' || choice6[0] == 'y')
                             {
                                cout << "I bid you luck! Hopefully better than mine mate... *He appears rather sad but grins away at you anyways*" << endl;
                                merchantExit_ = true;
                                phaseThree(map_, party_);
                             }
                             else if (choice6[0] == 'N' || choice6[0] == 'n')
                             {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                             }
                             else
                             {
                                        cout << "Please put a valid choice:" << endl;
                                        cin >> choice6; 
                             }
                             }
         else
         {
            cout << "C'mon!!! Waste my time and I'll be as vicious as that ol' wizard." << endl;
            cout << "Please put in a valid response" << endl;
            cin >> choice;
         }
  }
  else if (user[0] == 'N' || user[0] == 'n')
  {
    cout << "Fine you bugger! You look dirt poor anyways!" << endl;
    cout <<"The prisoner disappears. Yet a distinct, pungy smell hangs in the air..." << endl;
    merchantExit_ = true;
    phaseThree(map_, party_);
  }
  else
  {
    cout << "Please put a valid response:" << endl;
    cin >> user;
  }
}