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
#include "Mob.h"
#include "Party.h"
#include "NPC.h"
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

NPC::NPC(int numEncounterd_, bool spaceExplored_, bool puzzleCheck_ /*Mob monsters_[50]*/, void merchantMarket_)
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
    return puzzleCheck;
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
            //To be filled wherein the riddle will be separated by riddle and answer
            //They will then be assigned line-by-line to their own temp array
            //From there the array is randomly selected from a random num generator
            //Output array, prompt user input
            //Compare answers and determine the puzzle completion successfully to be returned as puzzleCheck
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

void merchantMarket(Party party_)
{
    string user = "";
    //will consist of multiple couts to establish a menu in which multiple options can result and produce random
    //products for purchase and will run through series of conditions taking in 
    //party resources to be used for checking/purchasing
    cout<<"There is a prisoner here? He looks kinda odd though..."<<endl;
  cout<<"He asks you if you want to buy something [Y/N]?"<<endl<<"> ";   
  party_.printStats();
  cin >> user;
  if(user=="y"||user=="Y") {
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
         cin >> choice;
         cout << "> " << choice << endl;
         if(choice==1){
                              int itemSelect1 = 0;
                              cout << "How many kg of ingredients mate [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                              cin >> itemSelect1;

                              if (itemSelect1 == 0)
                              {
                                return merchantMarket(party_);
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
                                    }
                                party_.addIngredients(itemSelect1);
                                cout << "Thanks for your patronage young sire! *He gives you a toothless grin*" << endl;
                                cout << "" << endl;
                                return merchantMarket(party_);
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
                              << "4. Cancel" << endl
                              << "" << endl;
                              cin >> itemSelect2;
                              cout << "> " << itemSelect2 << endl;
                              switch (itemSelect2)
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " pots for " << quantity * 2  << " gold? (y/n)" << endl
                                    << "" << endl;
                                    cin >> choice2;
                                    if (choice2[0] == 'Y' || choice2[0] == 'y')
                                    {
                                        if(party_.subGold((quantity * 2)) == 0)
                                        {
                                            cout<<"You don't have enough gold to buy that."<<endl;
                                        }
                                        party_.addCookwareAt(0, quantity);
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 2:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " pans for " << quantity * 10  << " gold? (y/n)" << endl
                                    << "" << endl;
                                    cin >> choice2;
                                    if (choice2[0] == 'Y' || choice2[0] == 'y')
                                    {
                                        if(party_.subGold((quantity * 10)) == 0)
                                        {
                                            cout<<"You don't have enough gold to buy that."<<endl;
                                        }
                                        party_.addCookwareAt(1, quantity);
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                
                                case 3:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " cauldrons for " << quantity * 20  << " gold? (y/n)" << endl
                                    << "" << endl;
                                    cin >> choice2;
                                    if (choice2[0] == 'Y' || choice2[0] == 'y')
                                    {
                                        if(party_.subGold((quantity * 20)) == 0)
                                        {
                                            cout<<"You don't have enough gold to buy that."<<endl;
                                        }
                                        party_.addCookwareAt(2, quantity);
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 4:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(party_);
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
                              << "6. Cancel" << endl
                              << "" << endl;
                              cin >> itemSelect3;
                              cout << "> " << itemSelect3 << endl;
                              switch (itemSelect3)
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " clubs for " << quantity2 * 2  << " gold? (y/n)" << endl
                                    << "" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 2)) == 0)
                                        {
                                            cout<<"You don't have enough gold to buy that."<<endl;
                                        }
                                        party_.addCookwareAt(itemSelect3 - 1, quantity2);
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 2:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " spears for " << quantity2 * 2  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        gold = gold - (quantity2 * 2);
                                        weapons[1] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                
                                case 3:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " rapiers for " << quantity2 * 5  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        gold = gold - (quantity2 * 5);
                                        weapons[2] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 4:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " battle-axes for " << quantity2 * 15  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        gold = gold - (quantity2 * 15);
                                        weapons[3] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                
                                case 5:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " longswords for " << quantity2 * 50  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        gold = gold - (quantity2 * 50);
                                        weapons[4] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(party_);
                              }
                             }
         if(choice==4) {
                               int itemSelect4 = 0;
                               cout << "The heavier, the more...won't you shake a poor sinner's hand? [5 Gold/suit] (Enter a positive integer, or 0 to cancel)" << endl;
                               cin >> itemSelect4;

                               if (itemSelect4 == 0)
                               {
                                return merchantMarket(party_);
                               }
                               else
                               {
                                gold = gold - itemSelect4 * 5;
                                armor = armor += itemSelect4;
                                cout << "Thanks for your patronage young sire! *He gives you a toothless grin*" << endl;
                                cout << "" << endl;
                                return merchantMarket(party_);
                               }
                             }
         if(choice==5) {
                             int itemSelect5 = 0;
                             string choice5 = "";
                             int quantity3 = 0;
                              cout << "Oh....my...might I just lighten yer load and take some of those beauts of yer'self?" << endl;
                              cout << "Choose one of the following:" << endl;
                              << "1. Silver Ring" << endl;
                              << "2. Ruby Necklace" << endl;
                              << "3. Emerald Bracelet" << endl;
                              << "4. Diamond Circlet" << endl;
                              << "5. Gem-Encrusted Goblet" << endl;
                              << "6. Cancel" << endl;
                              << "" << endl;
                              cin >> itemSelect5;
                              cout << "> " << itemSelect5 << endl;
                              switch (itemSelect5)
                              {
                                case 1:
                                    if (rooms_cleared >= 1)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " rings for " << quantity3 * 10 << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold + (quantity3 * 10);
                                        treasures[0] -= quantity3;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 2:
                                    if (rooms_cleared >= 2)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " necklaces for " << quantity3 * 20 << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold + (quantity3 * 20);
                                        treasures[1] -= quantity3;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(party_);
                                    }
                                
                                case 3:
                                    if (rooms_cleared >= 3)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " bracelets for " << quantity3 * 30 << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold + (quantity3 * 30);
                                        treasures[2] -= quantity3;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 4:
                                    if (rooms_cleared >= 4)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " rings for " << quantity3 * 40 << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold + (quantity3 * 40);
                                        treasures[3] -= quantity3;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(party_);
                                    }
                                
                                case 5:
                                    if (rooms_cleared >= 5)
                                    {
                                    cout << "And to how..many..you prefer to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity3;
                                    cout << "You sure about selling " << quantity3 << " rings for " << quantity3 * 50 << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold + (quantity3 * 50);
                                        treasures[4] -= quantity3;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(party_);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(party_);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(party_);
                                    }

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(party_);
                              }
                             }
         if(choice==6) {
                             cout << "Are you completely sure? It'll be terrible if you lose items or run out of things." << endl;
                             cin >> choice;

                             if (choice == 'Y' || choice == 'y')
                             {
                                cout << "I bid you luck! Hopefully better than mine mate... *He appears rather sad but grins away at you anyways*" << endl;
                                phaseThree(map, party_);
                             }
                             else
                             {
                                return merchantMarket(party_);
                             }
                             }
         else
         {
            cout << "C'mon!!! Waste my time and I'll be as vicious as that ol' wizard." << endl;
            cout << "Please put in a valid response" << endl;
            cin >> choice;
         }
  }
  else
  {
    cout << "Fine you bugger! You look dirt poor anyways!" << endl;
    cout <<"The prisoner disappears. Yet a distinct, pungy smell hangs in the air..." << endl;
    phaseThree(map, party_);
  }
}