//Editors: Robert Church & Jevan Wiltz

#include <string>
#include "Member.h"
#include "Party.h"
#include "NPC.h"
#include "Map.h"
#include "actions.h"
#include <iostream>
#include <cassert>
#include "MainDriver.h"

using namespace std;

int main()
{
    Map map = Map();
    Party my_party = Party();
    int angerLvl = 0;
    //Mob Sorcerer = Sorcerer();
    phaseOne(map, my_party/*, sorcerer*/);
}

void phaseOne(Map map, Party my_party)
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
    getline(cin, temp_string);
    temp_member.setName(temp_string);
    my_party.setMemberAt(0, temp_member);
    cout<<"It seems you have some friends. What are their names?"<<endl;
    for(int i = 1; i < 5; i++)
    {
        getline(cin, temp_string);
        temp_member.setName(temp_string);
        my_party.setMemberAt(i, temp_member);
    }


    phaseTwo(map, my_party);
}

void phaseTwo(Map map, Party my_party)
{
    //bool marketUsed = false;
    NPC my_npc = NPC(false, true, false);
    my_npc.merchantMarket(map, my_party, false);    

    /*if (marketUsed == true)
    {
        phaseThree(map, my_party);
    }
    else
    {
        cout << "Fail" << endl;
    }*/
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
    
    //checks for all deaths, win condition, lose conditions

    //checks all party members livelyness, if all party members are dead, send to phase four to end game
    for(int i = 1; i < 5; i++)
    {
        temp_member = my_party.getMembersAt(i);
        if(temp_member.getAlive() == 1)
        {
            truefalse = 1;
        }
    }
    if(truefalse == 0)
    {
        phaseFour(map, my_party, 0);
        return;
    }
    truefalse = 0;

    //checks if user is dead
    if(my_party.getMembersAt(0).getAlive() == 0)
    {
        phaseFour(map, my_party, 0);
        return;
    }

    //checks if Anger is 100
    if(my_party.getAnger() == 100)
    {
        phaseFour(map, my_party, 0);
        return;
    }

    //checks if player got to the end
    if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) && my_party.getRoomsCleared() == 5)
    {
        phaseFour(map, my_party, 1);
    }

    //checking spaces    
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
    }else
    if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
    {
        ExitAction(map, my_party);
    }
    
}

void phaseFour(Map map, Party my_party, bool win_lose)
{
    if(win_lose == 0)
    {
        cout<<"_/      _/    _/_/    _/    _/      _/          _/_/      _/_/_/  _/_/_/_/_/   "<<endl
            <<" _/  _/    _/    _/  _/    _/      _/        _/    _/  _/            _/        "<<endl
            <<"  _/      _/    _/  _/    _/      _/        _/    _/    _/_/        _/         "<<endl
            <<" _/      _/    _/  _/    _/      _/        _/    _/        _/      _/          "<<endl
            <<"_/        _/_/      _/_/        _/_/_/_/    _/_/    _/_/_/        _/           "<<endl<<endl;
        my_party.printFinalStats();

    }
    if(win_lose == 1)
    {
        
    }
}

void ExitAction(Map map, Party my_party)
{
    string actionOption = "";
    bool truefalse = 0;
    string moveDirection = "";
    int rand1 = 0;
    Member temp_member;

    cout<<"It seems that you haven't cleared 5 rooms yet. You can't leave."<<endl;
    cout<<"What would you like to do?"<<endl
    <<"1. Move"<<endl
    <<"2. Give up."<<endl;
    cin>>actionOption;
    while(actionOption != "1" && actionOption != "2" && actionOption != "3" && actionOption != "4" && actionOption != "5")
    {
        cout<<"Please enter a valid input."<<endl;
        cin>>actionOption;
    }
    switch(stoi(actionOption))
    {
        case 1:
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection[0]);
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
            phaseFour(map, my_party, 0);
        return;
            break;
        default:
            cout<<"Please enter a valid input."<<endl;
            ExitAction(map, my_party);
            break;

    }
    if(my_party.getRoomsCleared() != 5)
    {
        my_party.addAnger(1);
    }
    my_party.addTurns(1);
    phaseThree(map, my_party);
}

void NormalAction(Map map, Party my_party)
{
    string actionOption = "";
    bool truefalse = 0;
    int temp_int = 0;
    string moveDirection = "";
    Member temp_member;
    printActionsNormal();
    int rand1 = 0;
    int rand2 = 0;
    cin>>actionOption;
    while(actionOption != "1" && actionOption != "2" && actionOption != "3" && actionOption != "4" && actionOption != "5")
    {
        cout<<"Please enter a valid input."<<endl;
        cin>>actionOption;
    }
    switch(stoi(actionOption))
    {
        case 1:
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection[0]);
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

            if(rand1 > 4) /*double check this does interfere with above chance*/
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
            my_party.addnumExplored(1);
            
            //misfortunes
            rand1 = rand() % 10;
            if(rand1 == 0 || rand2 == 1 || rand2 ==2)
            {
                cout<<"OH NO! Your team was robbed by dungeon bandits!"<<endl;
                my_party.subIngredients(10);
                if(my_party.getCookwareAt(0) != 0 || my_party.getCookwareAt(1) != 0 || my_party.getCookwareAt(2) != 0)
                {
                    rand2 = rand() % 3;
                    while(my_party.subCookwareAt(rand2, 1) == 0)
                    {
                        rand2 = rand() % 3;
                    }
                    switch (rand2)
                    {
                    case 0:
                        cout<<"You lost 1 Pot"<<endl;
                        break;
                    case 1:
                        cout<<"You lost 1 Pan"<<endl;
                        break;
                    case 2:
                        cout<<"You lost 1 Cauldron"<<endl;
                        break;
                    default:
                        break;
                    }
                }

            }else
            if(rand1 == 3)
            {
                rand2 = rand() % 5;
                if(my_party.getWeaponsAt(0) != 0 || my_party.getWeaponsAt(1) != 0 || my_party.getWeaponsAt(2) != 0 || my_party.getWeaponsAt(3) != 0 || my_party.getWeaponsAt(4) != 0)
                    {
                    while(my_party.getWeaponsAt(rand2) != 0 && my_party.subWeaponsAt(rand2, 1))
                    {
                        rand2 = rand() % 5;
                    }
                    for(int i = 0; i < 5; i++)
                    {
                        temp_member = my_party.getMembersAt(i);
                        if(temp_member.getWeapon() == rand2)
                        {
                            temp_member.setWeapon(-1);
                            my_party.setMemberAt(i, temp_member);
                            break;
                        }
                    }
                    switch (rand2)
                    {
                    case 0:
                        cout<<"OH NO! Your Club broke!"<<endl;
                        break;
                    case 1:
                        cout<<"OH NO! Your Spear broke!"<<endl;
                        break;
                    case 2:
                        cout<<"OH NO! Your +1 Rapier broke!"<<endl;
                        break;
                    case 3:
                        cout<<"OH NO! Your +2 Battle-Axe broke!"<<endl;
                        break;
                    case 4:
                        cout<<"OH NO! Your +3 Long Sword broke!"<<endl;
                        break;
                    default:
                        break;
                    }
                }
            }else
            if(rand1 == 4 || rand1 == 5 || rand1 == 6)
            {
                rand2 = rand() % 4;
                while (my_party.getMembersAt(rand2+1).getAlive() == 0)
                {
                    rand2 = rand() % 4;
                }
                temp_member = my_party.getMembersAt(rand2+1);
                cout<<"OH NO! "<<temp_member.getName()<<" got food poisining!"<<endl;
                temp_member.subFullness(10);
                if(temp_member.getAlive() == 0)
                {
                    cout<<"OH DANG! "<<temp_member.getName()<<" just died!"<<endl;
                }
                
            }else
            if(rand1 == 7 || rand1 == 8 || rand1 == 9)
            {

            }

            break;
            case 3:
                //monster fight
                break;
            case 4:
                {
                    srand(time(0));
                    int numkg = 0;
                    int cookware = 0;
                    int chance = 0;
                    bool success = 1;
                    Member temp_member;

                    cout<<"What cookware item would you like to use to cook? You have: "<<endl;
                    cout<<"(1) "<<my_party.getCookwareAt(0)<<" ceramic pot(s)"<<endl
                    <<"(2) "<<my_party.getCookwareAt(1)<<" frying pan(s)"<<endl
                    <<"(3) "<<my_party.getCookwareAt(2)<<" cauldron(s)"<<endl
                    <<"(4) Exit"<<endl;
                    cin>>cookware;
                    if(cookware == 4)
                    {
                        break;
                    }
                    //check that the user has a non-zero amount of the cookware;
                    cout<<"How many kg of ingredients would you like to cook?"<<endl;
                    cout<<"For every 5kg you cook successfully, each party member will gain 1 hunger"<<endl;
                    cin>>numkg;
                    while(numkg % 5 != 0)
                    {
                        cout<<"Please enter an amount that is divisible by 5"<<endl;
                        cin>>numkg;
                    }
                    if(numkg % 5 == 0)
                    {
                        my_party.subIngredients(numkg);
                        switch (cookware)
                        {
                        case 1:
                            chance = rand() % 4;
                            if(chance == 0)
                            {
                                my_party.subCookwareAt(0, 1);
                                success = 0;
                            }
                            break;
                        case 2:
                            chance = rand() % 10;
                            if(chance == 0)
                            {
                                my_party.subCookwareAt(1, 1);
                                success = 0;
                            }
                        case 3:
                            chance = rand() % 50;
                            if(chance == 0)
                            {
                                my_party.subCookwareAt(2, 1);
                                success = 0;
                            }
                        default:
                            break;
                        }
                        
                        if(success == 0)
                        {
                            cout<<"It seems that your cookware item has broken!!1!!1!"<<endl;
                            cout<<"You just lost all of the ingredients you were going to use to make a meal."<<endl
                            <<"sad."<<endl;
                        }else
                        {
                            cout<<"It was a success!"<<endl;
                            cout<<"All party members will gain "<<numkg/5<<"hunger."<<endl;
                            for(int i = 0; i < 5; i++)
                            {
                                temp_member = my_party.getMembersAt(i);
                                temp_member.addFullness(numkg/5);
                                my_party.setMemberAt(i, temp_member);
                            }
                        }
                    }
                    //misfortunes
                    rand1 = rand() % 10;
                    if(rand1 == 0 || rand2 == 1 || rand2 ==2)
                    {
                        cout<<"OH NO! Your team was robbed by dungeon bandits!"<<endl;
                        my_party.subIngredients(10);
                        if(my_party.getCookwareAt(0) != 0 || my_party.getCookwareAt(1) != 0 || my_party.getCookwareAt(2) != 0)
                        {
                            rand2 = rand() % 3;
                            while(my_party.subCookwareAt(rand2, 1) == 0)
                            {
                                rand2 = rand() % 3;
                            }
                            switch (rand2)
                            {
                            case 0:
                                cout<<"You lost 1 Pot"<<endl;
                                break;
                            case 1:
                                cout<<"You lost 1 Pan"<<endl;
                                break;
                            case 2:
                                cout<<"You lost 1 Cauldron"<<endl;
                                break;
                            default:
                                break;
                            }
                        }

                    }else
                    if(rand1 == 3)
                    {
                        rand2 = rand() % 5;
                        if(my_party.getWeaponsAt(0) != 0 || my_party.getWeaponsAt(1) != 0 || my_party.getWeaponsAt(2) != 0 || my_party.getWeaponsAt(3) != 0 || my_party.getWeaponsAt(4) != 0)
                            {
                            while(my_party.getWeaponsAt(rand2) != 0 && my_party.subWeaponsAt(rand2, 1))
                            {
                                rand2 = rand() % 5;
                            }
                            for(int i = 0; i < 5; i++)
                            {
                                temp_member = my_party.getMembersAt(i);
                                if(temp_member.getWeapon() == rand2)
                                {
                                    temp_member.setWeapon(-1);
                                    my_party.setMemberAt(i, temp_member);
                                    break;
                                }
                            }
                            switch (rand2)
                            {
                            case 0:
                                cout<<"OH NO! Your Club broke!"<<endl;
                                break;
                            case 1:
                                cout<<"OH NO! Your Spear broke!"<<endl;
                                break;
                            case 2:
                                cout<<"OH NO! Your +1 Rapier broke!"<<endl;
                                break;
                            case 3:
                                cout<<"OH NO! Your +2 Battle-Axe broke!"<<endl;
                                break;
                            case 4:
                                cout<<"OH NO! Your +3 Long Sword broke!"<<endl;
                                break;
                            default:
                                break;
                            }
                        }
                    }else
                    if(rand1 == 4 || rand1 == 5 || rand1 == 6)
                    {
                        rand2 = rand() % 4;
                        while (my_party.getMembersAt(rand2+1).getAlive() == 0)
                        {
                            rand2 = rand() % 4;
                        }
                        temp_member = my_party.getMembersAt(rand2+1);
                        cout<<"OH NO! "<<temp_member.getName()<<" got food poisining!"<<endl;
                        temp_member.subFullness(10);
                        if(temp_member.getAlive() == 0)
                        {
                            cout<<"OH DANG! "<<temp_member.getName()<<" just died!"<<endl;
                        }
                        
                    }else
                    if(rand1 == 7 || rand1 == 8 || rand1 == 9)
                    {

                    }
                }
                break;
            case 5:
                phaseFour(map, my_party, 0);
                return;
                break;
            default:
                cout<<"Please enter a valid input."<<endl;
                NormalAction(map, my_party);
                break;
    }
    if(my_party.getRoomsCleared() != 5)
    {
        my_party.addAnger(1);
    }
    my_party.addTurns(1);
    phaseThree(map, my_party);
}

void NPCAction(Map map, Party my_party)
{
    string actionOption = "";
    bool truefalse = 0;
    bool talkTrue = true;
    bool NPCtrust = false;
    bool NPCused = false;
    bool marketUsage = false;
    string NPCaccept = "";
    int temp_int = 0;
    int NPCrow = map.getPlayerRow();
    int NPCcol = map.getPlayerCol();
    string moveDirection = "";
    Member temp_member;
    NPC randomNPC = NPC(NPCused, NPCtrust, marketUsage);
    printActionsNPC();
    int rand1 = 0;
    int rand2 = 0;
    cin>>actionOption;
    while(actionOption != "1" && actionOption != "2" && actionOption != "3")
    {
        cout<<"Please enter a valid input."<<endl;
        cin>>actionOption;
    }
    switch(stoi(actionOption))
    {
        case 1:   
            //NPCrow = map.getPlayerRow();
            //NPCcol = map.getPlayerCol();       
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection[0]);

                if (randomNPC.getspaceExplored() == true)
                {
                    map.removeNPC(NPCrow, NPCcol);
                }
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
           while (talkTrue == true)
           {
           cout << "Before I agree to do anything...you must answer this riddle of mine weary lad. Dare you take on me in this witty battle? (y/n)" << endl;
           cin >> NPCaccept;
           if (NPCaccept[0] == 'y' || NPCaccept[0] == 'Y')
           {
                cout << "Very well then..." << endl;
                cout << "" << endl;
                randomNPC.setNPCPuzzle(NPCtrust);

                if (randomNPC.getNPCPuzzle() == true)
                {
                    randomNPC.merchantMarket(map, my_party, marketUsage);
                    randomNPC.setspaceExplored(NPCused, NPCtrust, marketUsage);
                }
                else
                {
                  talkTrue = false;
                }
           }
           else if (NPCaccept[0] == 'n' || NPCaccept[0] == 'N')
           {
            cout << "Aight, peace bruv!" << endl;
            cout << "" << endl;
            talkTrue = false;
           }
           else
           {
            cout << "Please give a valid input." << endl;
           }
           }

            //misfortunes
            rand1 = rand() % 10;
            if(rand1 == 0 || rand2 == 1 || rand2 ==2)
            {
                cout<<"OH NO! Your team was robbed by dungeon bandits!"<<endl;
                my_party.subIngredients(10);
                if(my_party.getCookwareAt(0) != 0 || my_party.getCookwareAt(1) != 0 || my_party.getCookwareAt(2) != 0)
                {
                    rand2 = rand() % 3;
                    while(my_party.subCookwareAt(rand2, 1) == 0)
                    {
                        rand2 = rand() % 3;
                    }
                    switch (rand2)
                    {
                    case 0:
                        cout<<"You lost 1 Pot"<<endl;
                        break;
                    case 1:
                        cout<<"You lost 1 Pan"<<endl;
                        break;
                    case 2:
                        cout<<"You lost 1 Cauldron"<<endl;
                        break;
                    default:
                        break;
                    }
                }

            }else
            if(rand1 == 3)
            {
                rand2 = rand() % 5;
                if(my_party.getWeaponsAt(0) != 0 || my_party.getWeaponsAt(1) != 0 || my_party.getWeaponsAt(2) != 0 || my_party.getWeaponsAt(3) != 0 || my_party.getWeaponsAt(4) != 0)
                    {
                    while(my_party.getWeaponsAt(rand2) != 0 && my_party.subWeaponsAt(rand2, 1))
                    {
                        rand2 = rand() % 5;
                    }
                    for(int i = 0; i < 5; i++)
                    {
                        temp_member = my_party.getMembersAt(i);
                        if(temp_member.getWeapon() == rand2)
                        {
                            temp_member.setWeapon(-1);
                            my_party.setMemberAt(i, temp_member);
                            break;
                        }
                    }
                    switch (rand2)
                    {
                    case 0:
                        cout<<"OH NO! Your Club broke!"<<endl;
                        break;
                    case 1:
                        cout<<"OH NO! Your Spear broke!"<<endl;
                        break;
                    case 2:
                        cout<<"OH NO! Your +1 Rapier broke!"<<endl;
                        break;
                    case 3:
                        cout<<"OH NO! Your +2 Battle-Axe broke!"<<endl;
                        break;
                    case 4:
                        cout<<"OH NO! Your +3 Long Sword broke!"<<endl;
                        break;
                    default:
                        break;
                    }
                }
            }else
            if(rand1 == 4 || rand1 == 5 || rand1 == 6)
            {
                rand2 = rand() % 4;
                while (my_party.getMembersAt(rand2+1).getAlive() == 0)
                {
                    rand2 = rand() % 4;
                }
                temp_member = my_party.getMembersAt(rand2+1);
                cout<<"OH NO! "<<temp_member.getName()<<" got food poisining!"<<endl;
                temp_member.subFullness(10);
                if(temp_member.getAlive() == 0)
                {
                    cout<<"OH DANG! "<<temp_member.getName()<<" just died!"<<endl;
                }
                
            }else
            if(rand1 == 7 || rand1 == 8 || rand1 == 9)
            {

            }
            break;
        case 3:
            phaseFour(map, my_party, 0);
            return;
            break;
        default:
            cout<<"Please enter a valid input."<<endl;
            NPCAction(map, my_party);
            break;
    }
    if(my_party.getRoomsCleared() != 5)
    {
        my_party.addAnger(1);
    }
    my_party.addTurns(1);
    phaseThree(map, my_party);
}

void RoomAction(Map map, Party my_party)
{
    string actionOption = "";
    bool truefalse = 0;
    int temp_int = 0;
    string playerOption = "";
    bool puzzlecompleted = 0;
    string moveDirection = "";
    Member temp_member;
    printActionsRoom();
    int rand1 = 0;
    int rand2 = 0;
    cin>>actionOption;
    while(actionOption != "1" && actionOption != "2" && actionOption != "3" && actionOption != "4")
    {
        cout<<"Please enter a valid input."<<endl;
        cin>>actionOption;
    }
    switch(stoi(actionOption))
    {
        case 1:
            //repeats until user gives a vaild character
            while(!truefalse)
            {
                cout<<"What direction do you want to move? w, a, s, or d:";
                cin>>moveDirection;
                truefalse = map.move(moveDirection[0]);
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
                    //misfortunes
                    rand1 = rand() % 10;
                    if(rand1 == 0 || rand2 == 1 || rand2 ==2)
                    {
                        cout<<"OH NO! Your team was robbed by dungeon bandits!"<<endl;
                        my_party.subIngredients(10);
                        if(my_party.getCookwareAt(0) != 0 || my_party.getCookwareAt(1) != 0 || my_party.getCookwareAt(2) != 0)
                        {
                            rand2 = rand() % 3;
                            while(my_party.subCookwareAt(rand2, 1) == 0)
                            {
                                rand2 = rand() % 3;
                            }
                            switch (rand2)
                            {
                            case 0:
                                cout<<"You lost 1 Pot"<<endl;
                                break;
                            case 1:
                                cout<<"You lost 1 Pan"<<endl;
                                break;
                            case 2:
                                cout<<"You lost 1 Cauldron"<<endl;
                                break;
                            default:
                                break;
                            }
                        }

                    }else
                    if(rand1 == 3)
                    {
                        rand2 = rand() % 5;
                        if(my_party.getWeaponsAt(0) != 0 || my_party.getWeaponsAt(1) != 0 || my_party.getWeaponsAt(2) != 0 || my_party.getWeaponsAt(3) != 0 || my_party.getWeaponsAt(4) != 0)
                            {
                            while(my_party.getWeaponsAt(rand2) != 0 && my_party.subWeaponsAt(rand2, 1))
                            {
                                rand2 = rand() % 5;
                            }
                            for(int i = 0; i < 5; i++)
                            {
                                temp_member = my_party.getMembersAt(i);
                                if(temp_member.getWeapon() == rand2)
                                {
                                    temp_member.setWeapon(-1);
                                    my_party.setMemberAt(i, temp_member);
                                    break;
                                }
                            }
                            switch (rand2)
                            {
                            case 0:
                                cout<<"OH NO! Your Club broke!"<<endl;
                                break;
                            case 1:
                                cout<<"OH NO! Your Spear broke!"<<endl;
                                break;
                            case 2:
                                cout<<"OH NO! Your +1 Rapier broke!"<<endl;
                                break;
                            case 3:
                                cout<<"OH NO! Your +2 Battle-Axe broke!"<<endl;
                                break;
                            case 4:
                                cout<<"OH NO! Your +3 Long Sword broke!"<<endl;
                                break;
                            default:
                                break;
                            }
                        }
                    }else
                    if(rand1 == 4 || rand1 == 5 || rand1 == 6)
                    {
                        rand2 = rand() % 4;
                        while (my_party.getMembersAt(rand2+1).getAlive() == 0)
                        {
                            rand2 = rand() % 4;
                        }
                        temp_member = my_party.getMembersAt(rand2+1);
                        cout<<"OH NO! "<<temp_member.getName()<<" got food poisoning!"<<endl;
                        temp_member.subFullness(10);
                        if(temp_member.getAlive() == 0)
                        {
                            cout<<"OH DANG! "<<temp_member.getName()<<" just died!"<<endl;
                        }
                        
                    }else
                    if(rand1 == 7 || rand1 == 8 || rand1 == 9)
                    {
                        rand2 = rand() % 4 + 1;
                        temp_member = my_party.getMembersAt(rand2);
                        while(temp_member.getAlive() == 0)
                        {
                            rand2 = rand() % 4 + 1;
                            temp_member = my_party.getMembersAt(rand2);
                        }
                        temp_member.setAlive(0);
                        //my_party.setMemberAt(rand2, temp_member);
                        my_party.removeMemberAt(rand2);
                        my_party.setNumMembers();
                        cout<<"OH NO! Your teammate "<<temp_member.getName()<<" is trapped in the previous room and is unable to get through. You must continue without them."<<endl
                        <<"Your party size has reduced to "<<my_party.getNumMembers()<<" members. "<<endl;
                    }
                    
                }
            }
            if(my_party.getKeys() != 0)
            {
                my_party.subkeys(1);
                //fight monster depending on how many rooms cleared with switch statement

                //misfortunes
                rand1 = rand() % 10;
                if(rand1 == 0 || rand2 == 1 || rand2 ==2)
                {
                    cout<<"OH NO! Your team was robbed by dungeon bandits!"<<endl;
                    my_party.subIngredients(10);
                    if(my_party.getCookwareAt(0) != 0 || my_party.getCookwareAt(1) != 0 || my_party.getCookwareAt(2) != 0)
                    {
                        rand2 = rand() % 3;
                        while(my_party.subCookwareAt(rand2, 1) == 0)
                        {
                            rand2 = rand() % 3;
                        }
                        switch (rand2)
                        {
                        case 0:
                            cout<<"You lost 1 Pot"<<endl;
                            break;
                        case 1:
                            cout<<"You lost 1 Pan"<<endl;
                            break;
                        case 2:
                            cout<<"You lost 1 Cauldron"<<endl;
                            break;
                        default:
                            break;
                        }
                    }

                }else
                if(rand1 == 3)
                {
                    rand2 = rand() % 5;
                    if(my_party.getWeaponsAt(0) != 0 || my_party.getWeaponsAt(1) != 0 || my_party.getWeaponsAt(2) != 0 || my_party.getWeaponsAt(3) != 0 || my_party.getWeaponsAt(4) != 0)
                        {
                        while(my_party.getWeaponsAt(rand2) != 0 && my_party.subWeaponsAt(rand2, 1))
                        {
                            rand2 = rand() % 5;
                        }
                        for(int i = 0; i < 5; i++)
                        {
                            temp_member = my_party.getMembersAt(i);
                            if(temp_member.getWeapon() == rand2)
                            {
                                temp_member.setWeapon(-1);
                                my_party.setMemberAt(i, temp_member);
                                break;
                            }
                        }
                        switch (rand2)
                        {
                        case 0:
                            cout<<"OH NO! Your Club broke!"<<endl;
                            break;
                        case 1:
                            cout<<"OH NO! Your Spear broke!"<<endl;
                            break;
                        case 2:
                            cout<<"OH NO! Your +1 Rapier broke!"<<endl;
                            break;
                        case 3:
                            cout<<"OH NO! Your +2 Battle-Axe broke!"<<endl;
                            break;
                        case 4:
                            cout<<"OH NO! Your +3 Long Sword broke!"<<endl;
                            break;
                        default:
                            break;
                        }
                    }
                }else
                if(rand1 == 4 || rand1 == 5 || rand1 == 6)
                {
                    rand2 = rand() % 4;
                    while (my_party.getMembersAt(rand2+1).getAlive() == 0)
                    {
                        rand2 = rand() % 4;
                    }
                    temp_member = my_party.getMembersAt(rand2+1);
                    cout<<"OH NO! "<<temp_member.getName()<<" got food poisining!"<<endl;
                    temp_member.subFullness(10);
                    if(temp_member.getAlive() == 0)
                    {
                        cout<<"OH DANG! "<<temp_member.getName()<<" just died!"<<endl;
                    }
                    
                }else
                if(rand1 == 7 || rand1 == 8 || rand1 == 9)
                {

                }
            }
            break;
        case 3:
            my_party.setWeapons();
            break;
        case 4:
            phaseFour(map, my_party, 0);
            return;
            break;
        default:
            cout<<"Please enter a valid input."<<endl;
            RoomAction(map, my_party);
            break;
    }
    if(my_party.getRoomsCleared() != 5)
    {
        my_party.addAnger(1);
    }
    my_party.addTurns(1);
    phaseThree(map, my_party);
}