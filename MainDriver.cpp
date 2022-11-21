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
    //will basically just be Merchant menu
    phaseThree(map, my_party);
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

//m
