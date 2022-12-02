// NPC.cpp

// CSCI 1300 Fall 2022
// Editor: Jevan Wiltz
// Recitation: 304 – Nikhith Sannidhi
// Project #3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <ctime> 
#include <cstdlib>
#include <string>
#include "actions.h"
#include "Party.h"
#include "NPC.h"
#include "connect4.h"
#include "Map.h"
#include "MainDriver.h"
using namespace std;

//default constructor
NPC::NPC()
{
    spaceExplored = false;
    puzzleCheck = false;
    merchantExit = false;
}

//parameterized constructor
NPC::NPC(bool spaceExplored_, bool puzzleCheck_, bool merchantExit_)
{
    spaceExplored = spaceExplored_;
    puzzleCheck = puzzleCheck_;
    merchantExit = merchantExit_;
}

//returns at the end whether the space is already explored or if the NPC interaction ends
bool NPC::getspaceExplored()
{
    return spaceExplored;
}

//If both the puzzle has been completed and the merchant menu for the NPC is exited, return space as explored
void NPC::setspaceExplored(bool spaceExplored_, bool puzzleCheck_, bool merchantExit_)
{
    if (puzzleCheck_ && merchantExit_ == true)
    {
        spaceExplored_ = true;
    }
    else
    {
        spaceExplored_ = false;
    }

    spaceExplored = spaceExplored_;
}

//returns the validity of the puzzle NPC presents on first interaction
bool NPC::getNPCPuzzle()
{
    return puzzleCheck;
}

//establishes a puzzle to be taken in place of the once-be riddle for User to pass in order to befriend NPC. 
//outcome of one is given back as a boolean
void NPC::setNPCPuzzle(bool puzzleCheck_)
{
    connect4 game = connect4();
    puzzleCheck_ = game.computerGame();
    
    puzzleCheck = puzzleCheck_;
}

//will consist of multiple couts to establish a menu in which multiple options can result and produce random
    //products for purchase and will run through series of conditions taking in 
    //party resources to be used for checking/purchasing
    //For specific conditions: Prices will vary per item quality as well as, for treasures, a certain number 
    //of rooms must be cleared in order to sell the respective treasure
    //Furthermore, if invalid inputs are given, the comp will request valid response and redo merhcant menu
void NPC::merchantMarket(Map map_, Party party_, bool merchantExit_)
{
    string user = "";
    bool shopExit = false;
    bool choiceExit = false;
    party_.printStats();
  cout<<"There is a prisoner here? He looks kinda odd though..."<<endl;
  cout<<"He asks you if you want to buy something [Y/N]?"<<endl;   
  cin >> user;
  while (choiceExit == false){
  if(user[0]=='y'||user[0]=='Y') {
        string choice = "";
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
         while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
         {
            cout<<"Please enter a valid input."<<endl;
            cin>>choice;
         }
        if(stoi(choice)==1){
                              int itemSelect1 = 0;
                              string choice1 = "";
                              cout << "How many kg of ingredients mate [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                              cin >> itemSelect1;
                              //while (itemSelect1 != )

                              if (itemSelect1 == 0)
                              {
                                return merchantMarket(map_, party_, merchantExit_);
                              }
                              else if (itemSelect1 % 5 != 0)
                              {
                                cout << "Enter a valid amount. " << endl;
                              }
                              else if(party_.subGold((itemSelect1)) == 0)
                                        {
                                        cout<<"You don't have enough gold to buy that."<<endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                        }
                              else
                                        {
                                         party_.addIngredients(itemSelect1);
                                        cout << "Thanks for your patronage young sire! *He gives you a toothless grin*" << endl;
                                        cout << "" << endl;
                                        choiceExit = false;
                                        return merchantMarket(map_, party_, merchantExit_);
                                        }
                            }
         if(stoi(choice)==2){
                             string itemSelect2 = "";
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
                              while (itemSelect2 != "1" && itemSelect2 != "2" && itemSelect2 != "3" && itemSelect2 != "4")
                              {
                                cout<<"Please enter a valid input."<<endl;
                                cin>>itemSelect2;
                              }
                              switch (stoi(itemSelect2))
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addCookwareAt(stoi(itemSelect2) - 1, quantity);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice2[0] == 'N' || choice2[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addCookwareAt(stoi(itemSelect2) - 1, quantity);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice2[0] == 'N' || choice2[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addCookwareAt(stoi(itemSelect2) - 1, quantity);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice2[0] == 'N' || choice2[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    break;

                                case 4:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    cout << "" << endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                    break;

                                default: cout << "Please put a valid choice." << endl;
                                    break;
                              }

                             }
         if(stoi(choice)==3) {
                             string itemSelect3 = "";
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
                              while (itemSelect3 != "1" && itemSelect3 != "2" && itemSelect3 != "3" && itemSelect3 != "4" && itemSelect3 != "5" && itemSelect3 != "6")
                              {
                                cout<<"Please enter a valid input."<<endl;
                                cin>>itemSelect3;
                              }
                              switch (stoi(itemSelect3))
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " clubs for " << quantity2 * 2  << " gold? (y/n)" << endl;
                                    cin >> choice3;
                                    if (choice3[0] == 'Y' || choice3[0] == 'y')
                                    {
                                        if(party_.subGold((quantity2 * 2)) == 0)
                                            {
                                                cout<<"You don't have enough gold to buy that."<<endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(stoi(itemSelect3) - 1, quantity2);
                                                party_.setWeapons();
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(stoi(itemSelect3) - 1, quantity2);
                                                party_.setWeapons();
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(stoi(itemSelect3) - 1, quantity2);
                                                party_.setWeapons();
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(stoi(itemSelect3) - 1, quantity2);
                                                party_.setWeapons();
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addWeaponsAt(stoi(itemSelect3) - 1, quantity2);
                                                party_.setWeapons();
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice3[0] == 'N' || choice3[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    break;

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    cout << "" << endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                    break;
                                
                                default: cout << "Please put a valid choice." << endl;
                                    break;
                              }
                             }
         if(stoi(choice)==4) {
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
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.addArmor(itemSelect4);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                               }
                             }
         if(stoi(choice)==5) {
                             string itemSelect5 = "";
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
                              while (itemSelect5 != "1" && itemSelect5 != "2" && itemSelect5 != "3" && itemSelect5 != "4" && itemSelect5 != "5" && itemSelect5 != "6")
                              {
                                cout<<"Please enter a valid input."<<endl;
                                cin>>itemSelect5;
                              }
                              switch (stoi(itemSelect5))
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
                                        if(party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        cout << "" << endl;
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
                                        if(party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        cout << "" << endl;
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
                                        if(party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        cout << "" << endl;
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
                                        if(party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        cout << "" << endl;
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
                                        if(party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3) <=0)
                                            {
                                                cout<<"You don't have enough any of those mate. L + Ratio."<<endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                        else
                                            {
                                                party_.subTreasuresAt(stoi(itemSelect5) - 1, quantity3);
                                                cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                                cout << "" << endl;
                                                return merchantMarket(map_, party_, merchantExit_);
                                            }
                                    }
                                    else if (choice5[0] == 'N' || choice5[0] == 'n')
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    else
                                    {
                                        cout << "Please put a valid choice." << endl;
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                                    }
                                    break;

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    cout << "" << endl;
                                    return merchantMarket(map_, party_, merchantExit_);
                                    break;
                                
                                default: cout << "Please put a valid choice." << endl;
                                    break;
                              }
                             }
         if(stoi(choice)==6) {
                             string choice6 = "";
                             cout << "Are you completely sure? It'll be terrible if you lose items or run out of things. (Y/n)" << endl;
                             cin >> choice6;

                             if (choice6[0] == 'Y' || choice6[0] == 'y')
                             {
                                cout << "I bid you luck! Hopefully better than mine mate... *He appears rather sad but grins away at you anyways*" << endl;
                                cout << "" << endl;
                                cout << "" << endl;
                                cout << "" << endl;
                                merchantExit_ = true;
                                choiceExit = true;
                                phaseThree(map_, party_);
                             }
                             else if (choice6[0] == 'N' || choice6[0] == 'n')
                             {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        cout << "" << endl;
                                        return merchantMarket(map_, party_, merchantExit_);
                             }
                             else
                             {
                                        cout << "Please put a valid choice." << endl;
                             }
                             }
  }
  else if (user[0] == 'N' || user[0] == 'n')
  {
    cout << "Fine you bugger! You look dirt poor anyways!" << endl;
    cout <<"The prisoner disappears. Yet a distinct, pungy smell hangs in the air..." << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    merchantExit_ = true;
    choiceExit = true;
    phaseThree(map_, party_);
  }
  else
  {
    cout << "Please put a valid response." << endl;
    return merchantMarket(map_, party_, merchantExit_);
  }
}
}