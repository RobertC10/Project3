#include <string>
#include "Member.h"
#include "Party.h"
#include "Map.h"
#include "actions.h"
#include <iostream>
#include <cassert>

using namespace std;

void phaseThree(Map, Party);

void phaseTwo(Map, Party);

void phaseOne(Map, Party/*, Mob*/);

void NormalAction(Map, Party/*, Mob*/);

void NPCAction(Map, Party);

void RoomAction(Map, Party);

int main()
{
    Map map = Map();
    Party my_party = Party();
    //Mob Sorcerer = Sorcerer();
    phaseOne(map, my_party/*, sorcerer*/);
}

void phaseOne(Map map, Party my_party/*, Mob sorcerer*/)
{
    //This function would kind of be the welcome and initializing everything before passing it through the other functions.

    //initializing variables and stuff
    srand(time(0));
    Member temp_member;
    int rand1 = rand() % 12;
    int rand2 = rand() % 12;
    string temp_string = "";

    //adds rooms
    for(int i = 0; i < 5; i++)
    {
        while((rand1 == 0 && rand2 == 0) || (rand1 == 6 && rand2 == 15) || map.isRoomLocation(rand1, rand2))
        {
            rand1 = rand() % 12;
            rand2 = rand() % 12;
        }
        map.addRoom(rand1, rand2); 
    }

    //adds npcs
    for(int i = 0; i < 5; i++)
    {
        while((rand1 == 0 && rand2 == 0) || (rand1 == 11 && rand2 == 6) || map.isRoomLocation(rand1, rand2) || map.isNPCLocation(rand1, rand2))
        {
            rand1 = rand() % 12;
            rand2 = rand() % 12;
        }
        map.addNPC(rand1, rand2);
    }

    cout<<"Welcome, to Dungeon Escape!"<<endl<<endl;
    cout<<"Before we start, may I ask, what's your name?"<<endl;
    cin>>temp_string;
    temp_member.setName(temp_string);
    my_party.setMemberAt(0, temp_member);
    cout<<"It seems you have some friends. What are their names?"<<endl;
    for(int i = 1; i < 5; i++)
    {
        cin>>temp_string;
        temp_member.setName(temp_string);
        my_party.setMemberAt(i, temp_member);
    }


    phaseTwo(map, my_party);
}

void phaseTwo(Map map, Party my_party)
{
    string user = "";
    //will consist of multiple couts to establish a menu in which multiple options can result and produce random
    //products for purchase and will run through series of conditions taking in 
    //party resources to be used for checking/purchasing
cout<<"There is a prisoner here? He looks kinda odd though..."<<endl;
  cout<<"He asks you if you want to buy something [Y/N]?"<<endl<<"> ";   
  my_party.printMenu();
  cin >> user;
  if(user=="y"||user=="Y") {
        string choice = "";
         cout << "If you're looking to get supplies, you've come to the right place."<< endl
              << "If it ain't broke, it worth some gold!!" << endl;
         cout << "                                       " << endl;
              << "Choose one of the following: " << endl;
              << "1. Ingredients: Better than rats, I guarantee that mate." << endl;
              << "2. Cookware: You fancy Sire Gordon Ramseyth The Fourth?." << endl;
              << "3. Weapons: Even the best knights wish they had this!" << endl;
              << "4. Armor: You think you can take a hit without this?" << endl;
              << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
              << "6. Leave: Be sure you got eve'ythin mate. I'm gone after 'dis!" << endl;
         cin >> choice;
         cout << "> " << choice << endl;
         if(choice==1){
                              int itemSelect1 = 0;
                              cout << "How many kg of ingredients mate [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                              cin >> itemSelect1;

                              if (itemSelect1 == 0)
                              {
                                return merchantMarket(my_party);
                              }
                              else if (itemSelect1 % 5 != 0)
                              {
                                cout << "Enter a valid amount: " << endl;
                                cin >> itemSelect1;
                              }
                              else
                              {
                                gold = gold - itemSelect1;
                                ingredients =ingredients_ += itemSelect1;
                                cout << "Thanks for your patronage young sire! *He gives you a toothless grin*" << endl;
                                cout << "" << endl;
                                return merchantMarket(my_party);
                              }
                              }
         if(choice==2){
                             int itemSelect2 = 0;
                             string choice2 = "";
                             int quantity = 0;
                              cout << "Pots 'n pans I reckon? Some are stronger than the others." << endl;
                              cout << "Choose one of the following:" << endl;
                              << "1. (25%) Ceramic Pot [2 Gold]" << endl;
                              << "2. (10%) Frying Pan [10 Gold]" << endl;
                              << "3. ( 2%) Cauldron [20 Gold]" << endl;
                              << "4. Cancel" << endl;
                              << "" << endl;
                              cin >> itemSelect2;
                              cout << "> " << itemSelect2 << endl;
                              switch (itemSelect2)
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " pots for " << quantity * 2  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice2
                                    if (choice2 == 'Y' || choice2 == 'y')
                                    {
                                        gold = gold - (quantity * 2);
                                        cookware[0] += quantity;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }

                                case 2:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " pans for " << quantity * 10  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice2
                                    if (choice2 == 'Y' || choice2 == 'y')
                                    {
                                        gold = gold - (quantity * 10);
                                        cookware[1] += quantity;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                
                                case 3:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity;
                                    cout << "You sure about buying " << quantity << " cauldrons for " << quantity * 20  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice2
                                    if (choice2 == 'Y' || choice2 == 'y')
                                    {
                                        gold = gold - (quantity * 20);
                                        cookware[2] += quantity;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }

                                case 4:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(my_party);
                              }

                             }
         if(choice==3) {
                             int itemSelect3 = 0;
                             string choice3 = "";
                             int quantity2 = 0;
                              cout << "Might ya be one of those collectors? I have several combative sets that might put a real kick in yer game." << endl;
                              cout << "Choose one of the following:" << endl;
                              << "1. Stone Club [2 Gold]" << endl;
                              << "2. Iron Spear [2 Gold]" << endl;
                              << "3. (+1) Mythril Rapier [5 Gold]" << endl;
                              << "4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
                              << "5. (+3) Vorpal Longsword [50 Gold]" << endl;
                              << "6. Cancel" << endl;
                              << "" << endl;
                              cin >> itemSelect3;
                              cout << "> " << itemSelect3 << endl;
                              switch (itemSelect3)
                              {
                                case 1:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " clubs for " << quantity2 * 2  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold - (quantity2 * 2);
                                        weapons[0] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }

                                case 2:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " spears for " << quantity2 * 2  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold - (quantity2 * 2);
                                        weapons[1] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                
                                case 3:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " rapiers for " << quantity2 * 5  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold - (quantity2 * 5);
                                        weapons[2] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }

                                case 4:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " battle-axes for " << quantity2 * 15  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold - (quantity2 * 15);
                                        weapons[3] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                
                                case 5:
                                    cout << "And to how much you prefer? (Enter a positive integer, or 0 to cancel)" << endl;
                                    cin >> quantity2;
                                    cout << "You sure about buying " << quantity2 << " longswords for " << quantity2 * 50  << " gold? (y/n)" << endl;
                                    << "" << endl;
                                    cin >> choice3
                                    if (choice3 == 'Y' || choice3 == 'y')
                                    {
                                        gold = gold - (quantity2 * 50);
                                        weapons[4] += quantity2;
                                        cout << "Thanks as always! Any other fancy catch yer eye?" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(my_party);
                              }
                             }
         if(choice==4) {
                               int itemSelect4 = 0;
                               cout << "The heavier, the more...won't you shake a poor sinner's hand? [5 Gold/suit] (Enter a positive integer, or 0 to cancel)" << endl;
                               cin >> itemSelect4;

                               if (itemSelect4 == 0)
                               {
                                return merchantMarket(my_party);
                               }
                               else
                               {
                                gold = gold - itemSelect4 * 5;
                                armor = armor += itemSelect4;
                                cout << "Thanks for your patronage young sire! *He gives you a toothless grin*" << endl;
                                cout << "" << endl;
                                return merchantMarket(my_party);
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
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(my_party);
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
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(my_party);
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
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(my_party);
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
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(my_party);
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
                                        return merchantMarket(my_party);
                                    }
                                    else
                                    {
                                        cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                        return merchantMarket(my_party);
                                    }
                                    }
                                    else
                                    {
                                        cout << "Ahhh! This must be fake! You need to clear more rooms in order to find the real deal!" << endl;
                                        return merchantMarket(my_party);
                                    }

                                case 6:
                                    cout << "Damn'd bugger...quit wasting my time and decide on something! >:C" << endl;
                                    return merchantMarket(my_party);
                              }
                             }
         if(choice==6) {
                             cout << "Are you completely sure? It'll be terrible if you lose items or run out of things." << endl;
                             cin >> choice;

                             if (choice == 'Y' || choice == 'y')
                             {
                                cout << "I bid you luck! Hopefully better than mine mate... *He appears rather sad but grins away at you anyways*" << endl;
                                phaseThree(map, my_party);
                             }
                             else
                             {
                                return merchantMarket(my_party);
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
    phaseThree(map, my_party);
  }
    //phaseThree(map, my_party);
}

void phaseThree(Map map, Party my_party)
{

    srand(time(0));
    int actionOption = 0;
    bool truefalse = 0;
    char moveDirection = ' ';
    Member temp_member;
    my_party.printMenu();
    cout<<endl;
    map.displayMap();
    
    if(map.isFreeSpace(map.getPlayerRow(), map.getPlayerCol()))
    {
        NormalAction(map, my_party);
    }else
    if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
    {
        NPCAction(map, my_party);
    }else
    if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
    {
        RoomAction(map, my_party);
    }
    
}

void NormalAction(Map map, Party my_party)
{
    int actionOption = 0;
    bool truefalse = 0;
    int temp_int = 0;
    char moveDirection = ' ';
    Member temp_member;
    printActionsNormal();
    int rand1 = 0;
    int rand2 = 0;
    cin>>actionOption;
    switch(actionOption)
    {
        case 1:
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection);
            }
            //reduces parties hunger by 1 if unlucky
            for(int i = 0; i < 5; i++)
            {
                rand1 = rand() % 10;
                if(rand1 == 1 || rand1 == 2)
                {
                    temp_member = my_party.getMembersAt(i);
                    temp_member.subFullness(1);
                    my_party.setMemberAt(i, temp_member);
                }
            }
            break;
        case 2:
            rand1 = rand() % 10;

            if(rand1 == 1)
            {
                my_party.addKeys(1);
                //50% for member to lose hunger
                for(int i = 0; i < 5; i++)
                {
                    rand2 = rand() % 10;
                    if(rand2 < 5)
                    {
                        temp_member = my_party.getMembersAt(i);
                        temp_member.subFullness(1);
                        my_party.setMemberAt(i, temp_member);
                    }
                }
            }

            if(rand1 == 2 || rand1 == 3)
            {
                temp_int = my_party.getRoomsCleared();
                //chooses what treasure you get based on how many rooms you've cleared
                switch (temp_int)
                {
                case 0:
                    cout<<"You were supposed to find treasure but you haven't clearned any rooms yet."<<endl;
                    cout<<"L + Ratio."<<endl;
                    break;
                case 1:
                    cout<<"Wooow. You found a Silver Ring ... They can be sold at the Merchant for 10 gold a pop."<<endl;
                    my_party.addTreasuresAt(0, 1);
                    break;
                case 2:
                    cout<<"Dope. You just found a Ruby Necklace bro. They're valued at like 20 gold for every necklace or something."<<endl;
                    my_party.addTreasuresAt(1, 1);
                    break;
                case 3:
                    cout<<"Nice, you found a Emerald Bracelet. They can be sold at the Merchant for 30 gold."<<endl;
                    my_party.addTreasuresAt(2, 1);
                    break;
                case 4:
                    cout<<"Jeez, nice find. You found a Diamond Circlet. They can be sold for 40 gold at the Merchant."<<endl;
                    my_party.addTreasuresAt(3, 1);
                    break;
                case 5:
                    cout<<"HOLY GUACAMOLY! You just found a Gem-encrusted Goblet. whatever that is. Sold for 50 gold at the Merchant."<<endl;
                    my_party.addTreasuresAt(4, 1);
                    break;
                default:
                    break;
                }
                //50% chance for member to lose hunger
                for(int i = 0; i < 5; i++)
                {
                    rand2 = rand() % 10;
                    if(rand2 < 5)
                    {
                        temp_member = my_party.getMembersAt(i);
                        temp_member.subFullness(1);
                        my_party.setMemberAt(i, temp_member);
                    }
                }
            }

            if(rand1 == 4 || rand1 == 5)
            {
                //monster fight
            }

            if(rand1 > 4)
            {
                cout<<"Darn. You didn't find anything."<<endl;
                //50% chance for member to lose hunger
                for(int i = 0; i < 5; i++)
                {
                    rand2 = rand() % 10;
                    if(rand2 < 5)
                    {
                        temp_member = my_party.getMembersAt(i);
                        temp_member.subFullness(1);
                        my_party.setMemberAt(i, temp_member);
                    }
                }
            }
            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
            break;
            case 3:
                //monster fight
                break;
            case 4:
                //cook and eat
                break;
            case 5:
                //game over
                cout<<"  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  "<<endl;
                cout<<" ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒"<<endl;
                cout<<"▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒"<<endl;
                cout<<"░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  "<<endl;
                cout<<"░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒"<<endl;
                cout<<" ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░"<<endl;
                cout<<"  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░"<<endl;
                cout<<"░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ "<<endl;
                cout<<"      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     "<<endl;
                cout<<"                                                     ░                   "<<endl;
                return;
                break;
            default:
                cout<<"Please enter a valid input."<<endl;
                NormalAction(map, my_party);
                break;
    }
    phaseThree(map, my_party);
}

void NPCAction(Map map, Party my_party)
{
    int actionOption = 0;
    bool truefalse = 0;
    int temp_int = 0;
    char moveDirection = ' ';
    Member temp_member;
    printActionsNPC();
    int rand1 = 0;
    int rand2 = 0;
    cin>>actionOption;
    switch(actionOption)
    {
        case 1:
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection);
            }
            //reduces parties hunger by 1 if unlucky
            for(int i = 0; i < 5; i++)
            {
                rand1 = rand() % 10;
                if(rand1 == 1 || rand1 == 2)
                {
                    temp_member = my_party.getMembersAt(i);
                    temp_member.subFullness(1);
                    my_party.setMemberAt(i, temp_member);
                }
            }
            break;
        case 2:
            //talk to NPC
            break;
        case 3:
            //game over
            cout<<"  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  "<<endl;
            cout<<" ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒"<<endl;
            cout<<"▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒"<<endl;
            cout<<"░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  "<<endl;
            cout<<"░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒"<<endl;
            cout<<" ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░"<<endl;
            cout<<"  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░"<<endl;
            cout<<"░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ "<<endl;
            cout<<"      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     "<<endl;
            cout<<"                                                     ░                   "<<endl;
            return;
            break;
        default:
            cout<<"Please enter a valid input."<<endl;
            NPCAction(map, my_party);
            break;
    }
    phaseThree(map, my_party);
}

void RoomAction(Map map, Party my_party)
{
    int actionOption = 0;
    bool truefalse = 0;
    int temp_int = 0;
    string playerOption = "";
    bool puzzlecompleted = 0;
    char moveDirection = ' ';
    Member temp_member;
    printActionsRoom();
    int rand1 = 0;
    int rand2 = 0;
    cin>>actionOption;
    switch(actionOption)
    {
        case 1:
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection);
            }
            //reduces parties hunger by 1 if unlucky
            for(int i = 0; i < 5; i++)
            {
                rand1 = rand() % 10;
                if(rand1 == 1 || rand1 == 2)
                {
                    temp_member = my_party.getMembersAt(i);
                    temp_member.subFullness(1);
                    my_party.setMemberAt(i, temp_member);
                }
            }
            break;
        case 2:
            if(my_party.getKeys() == 0)
            {
                cout<<endl<<"It seems that you don't have any keys. You'll have to complete a puzzle if you want to enter without a key."<<endl;
                cout<<"If you lose, one of you die. Do you want to try?"<<endl;
                cin>>playerOption;

                //making sure the player actually wants to do this
                if(playerOption[0] == 'Y' || playerOption[0] == 'y')
                {
                cout<<"Are you sure? There's no backing out once you start."<<endl;
                }else if(playerOption[0] == 'N' || playerOption[0] == 'n')
                {
                    cout<<"ok, sounds good."<<endl;
                    RoomAction(map, my_party);
                }
                while(playerOption[0] != 'Y' && playerOption[0] != 'y' && playerOption[0] != 'N' && playerOption[0] != 'n')
                {
                    cout<<"Please enter a valid input."<<endl;
                    cin>>playerOption;
                    if(playerOption[0] == 'Y' || playerOption[0] == 'y')
                    {
                    cout<<"Are you sure? There's no backing out once you start."<<endl;
                    }else if(playerOption[0] == 'N' || playerOption[0] == 'n')
                    {
                        cout<<"ok, sounds good."<<endl;
                        RoomAction(map, my_party);
                    }
                }
                
                cin>>playerOption;
                if(playerOption[0] == 'Y' || playerOption[0] == 'y')
                {
                    cout<<"Ok, here we go."<<endl<<endl;
                }else if(playerOption[0] == 'N' || playerOption[0] == 'n')
                {
                    cout<<"ok, sounds good."<<endl;
                    RoomAction(map, my_party);
                }
                while(playerOption[0] != 'Y' && playerOption[0] != 'y' && playerOption[0] != 'N' && playerOption[0] != 'n')
                {
                    cout<<"Please enter a valid input."<<endl;
                    cin>>playerOption;
                    if(playerOption[0] == 'Y' || playerOption[0] == 'y')
                    {
                        cout<<"Ok, here we go."<<endl<<endl;
                    }else if(playerOption[0] == 'N' || playerOption[0] == 'n')
                    {
                        cout<<"ok, sounds good."<<endl;
                        RoomAction(map, my_party);
                    }
                }

                puzzlecompleted = doorPuzzle();
                if(puzzlecompleted == true)
                {
                    my_party.addKeys(1);
                }else
                {
                    rand2 = rand() % 4 + 1;
                    temp_member = my_party.getMembersAt(rand2);
                    while(temp_member.getAlive() == 0)
                    {
                        rand2 = rand() % 4 + 1;
                        temp_member = my_party.getMembersAt(rand2);
                    }
                    temp_member.setAlive(0);
                    cout<<"Well there you go. You killed "<<temp_member.getName()<<". Good job."<<endl;
                    my_party.setMemberAt(rand2, temp_member);
                }
            }
            if(my_party.getKeys() != 0)
            {
                my_party.subkeys(1);
                //fight monster depending on how many rooms cleared with switch statement
            }
            break;
        case 3:
            //game over
            cout<<"  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  "<<endl;
            cout<<" ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒"<<endl;
            cout<<"▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒"<<endl;
            cout<<"░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  "<<endl;
            cout<<"░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒"<<endl;
            cout<<" ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░"<<endl;
            cout<<"  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░"<<endl;
            cout<<"░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ "<<endl;
            cout<<"      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     "<<endl;
            cout<<"                                                     ░                   "<<endl;
            return;
            break;
        default:
            cout<<"Please enter a valid input."<<endl;
            NPCAction(map, my_party);
            break;
    }
    phaseThree(map, my_party);
}