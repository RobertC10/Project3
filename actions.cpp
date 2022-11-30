//Editors: Robert Church & Jevan Wiltz

#include <string>
#include <iostream>
#include "actions.h"
#include "Map.h"
//#include "Mob.h"
#include "Party.h"
#include "connect4.h"
#include "NPC.h"

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

void printActionsRoom()
{
    cout<<"You're currently on a Room space. What do you want to do?"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Open the door"<<endl;
    cout<<"3. Give up"<<endl;
}

bool doorPuzzle()
{
    srand(time(0));
    int rand1 = rand() % 2;
    int rand2 = 0;

    switch (rand1)
    {
    case 0:
    {
        char rpsUsrChoice = ' ';
        char rpsComChoice = ' ';
        int comScore = 0;
        int usrScore = 0;
        bool winCondition = 0;
        // Boulder/Parchment/Shears
        cout<<"It's time for a game of Boulder-Parchment-Shears. (its kinda like rock paper scissors)"<<endl;
        cout<<"Best 2 out of 3, here we go."<<endl;
        cout<<"Enter either 'B' for Boulder, 'P' for Parchment, or 'S' for Shears:"<<endl;
        
        while(!winCondition)
        {
            rand2 = rand() % 3;
            //COM choosing rps
            switch (rand2)
            {
            case 0:
                rpsComChoice = 'B';
                break;
            case 1:
                rpsComChoice = 'P';
                break;
            case 2:
                rpsComChoice = 'S';
                break;
            default:
                break;
            }

            cout<<"Score is "<<usrScore<<" - "<<comScore<<"."<<endl;
            cout<<"Boulder, Parchment, Shears, SHOOT!"<<endl;

            //User choice for rps
            cin>>rpsUsrChoice;
            while(rpsUsrChoice != 'B' && rpsUsrChoice != 'P' && rpsUsrChoice != 'S')
            {
                cout<<"Please enter a valid input."<<endl;
                cin>>rpsUsrChoice;
            }
            cout<<rpsComChoice<<endl;

            //seeing who wins the round
            if(rpsUsrChoice == rpsComChoice)
            {
                cout<<"It's a tie. Go again."<<endl;
                continue;
            }else
            if((rpsComChoice == 'B' && rpsUsrChoice == 'S') || (rpsComChoice == 'P' && rpsUsrChoice == 'B') || (rpsComChoice == 'S' && rpsUsrChoice == 'P'))
            {
                comScore++;
            }else
            if((rpsUsrChoice == 'B' && rpsComChoice == 'S') || (rpsUsrChoice == 'P' && rpsComChoice == 'B') || (rpsUsrChoice == 'S' && rpsComChoice == 'P'))
            {
                usrScore++;
            }

            //checks win condition
            if(usrScore == 2)
            {
                cout<<"Dang, you won. You may enter."<<endl;
                return 1;
            }else
            if(comScore == 2)
            {
                cout<<"dude. you lost..."<<endl;
                return 0;
            }
        }
    }
    break;
    case 1:
        {
            bool winloss = 0;
            connect4 game = connect4();
            winloss = game.computerGame();
            if(winloss == 1)
            {
                cout<<"You may enter."<<endl;
                return 1;
            }else
            if(winloss == 0)
            {
                return 0;
            }
        }
    break;    
    default:
        break;
    }

    return 0;
}

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

/*bool setWeaponsMarket(Map map, Party my_party, bool merchant_Exit_)
{
    string yesNo = "";
    string squad = "";

    cout<<"Do you want to edit who has what weapon in your party?"<<endl;
    cin>>yesNo;
    while(yesNo[0] == 'y' || yesNo[0] == 'Y')
    {  
        cout<<"You have: "<<my_party.getWeaponsAt(0)<<" club(s), "<<my_party.getWeaponsAt(1)<<" iron sword(s), "<<my_party.getWeaponsAt(2)<<" rapier(s), "<<my_party.getWeaponsAt(3)<<" battle-axe(s), "<<my_party.getWeaponsAt(4)<<" longsword(s)."<<endl;
        my_party.printParty();
        cout<<"Whos weapon do you want to change?(type their name)"<<endl;
        cin>>squad;
        while(squad != my_party.getMembersAt(0).getName() && squad != my_party.getMembersAt(1).getName() && squad != my_party.getMembersAt(2).getName() && squad != my_party.getMembersAt(3).getName() && squad != my_party.getMembersAt(4).getName())
        {
            cout<<"Please enter a valid name."<<endl;
            cin>>squad;
        }
        cout<<"Do you want to still edit who has what weapon in your party?"<<endl;
        cin>>yesNo;
    }

    return 0;
}*/

/*
int readMobs(Mob monsters_[])
{
    ifstream file_input;
    file_input.open("monsters.txt");

    int index = 2;
    int countMobs = 0;
    Mob newMob;
    string line;
    string temp_mob[2];

    if (file_input.fail())
    {
        cout << "Could not open file." << endl;
        return -1;
    }
    else
    {
        for (int i = 21; getline(file_input, line) && i < 21; i++)
        {
            int count = split (line, ',', temp_mob, 2);

            if (count == 2)
            {
                newMob.setName(temp_mob[0]);
                newMob.setStr(stoi(temp_mob[1]));

                monsters_[i] = newMob;
                countMobs++;
            }
        }
        return countMobs;
    }
    return 0;
}
*/


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
