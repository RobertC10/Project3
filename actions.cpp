#include <string>
#include <iostream>
#include "actions.h"
#include "Map.h"
#include "Party.h"

void printActionsNormal()
{
    cout<<"Select one:"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Investigate"<<endl;
    cout<<"3. Pick a Fight"<<endl;
    cout<<"4. Cook and Eat"<<endl;
    cout<<"5. Give up"<<endl;
}

void printActionsNPC()
{
    cout<<"It seems there's a Non-Player-Character here."<<endl;
    cout<<"You can do a few things:"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Speak to NPC"<<endl;
    cout<<"3. Give up"<<endl;
}


/*void NormalAction(Map map, Party my_party)
{
    int actionOption = 0;
    bool truefalse = 0;
    char moveDirection = ' ';
    Member temp_member;
    printActionsNormal();
    int rand1 = 0;
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
                    temp_member.setFullness(temp_member.getFullness()-1);
                    my_party.setMemberAt(i, temp_member);
                }
            }
            break;
    }
    
}*/


/*

*Does not work*

Map mover(Map map)
{
    char direction = ' ';
    bool tf = 0;
    while(!tf)
    {
    cout<<"What cardinal direction would you like to move?"<<endl;
    cout<<"Please enter w, a, s, or, d"<<endl;
    cin>>direction;
    tf = map.move(direction);
    }
    return map;
}*/