//Editors: Robert Church & Jevan Wiltz

#include <string>
#include "Member.h"
#include "Party.h"
#include "NPC.h"
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
    int angerLvl = 0;
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
    bool marketUsed = false;
    NPC my_npc = NPC(false, true, marketUsed);
    my_npc.merchantMarket(my_party, marketUsed);    

    if (marketUsed == true)
    {
        phaseThree(map, my_party);
    }
    else
    {
        cout << "Fail" << endl;
    }
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
        sorcerersAnger(angerLvl);
        NormalAction(map, my_party);
    }else
    if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
    {
        sorcerersAnger(angerLvl);
        NPCAction(map, my_party);
    }else
    if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
    {
        sorcerersAnger(angerLvl);
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
                }
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

int sorcerersAnger(int anger)
{
    //To be updated in a few hours since last commit -JW
    anger++;

    if (anger == 100)
    {
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
    }
    else
    {
        return anger;
        continue;
    }
}