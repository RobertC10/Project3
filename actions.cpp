//Editors: Robert Church & Jevan Wiltz

#include <string>
#include <iostream>
#include "actions.h"
#include <fstream>
#include <vector>
#include "Map.h"
//#include "Mob.h"
#include "Party.h"
#include "connect4.h"
#include "NPC.h"

//prints actions available for a normal space
void printActionsNormal()
{
    cout<<"Select one:"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Investigate"<<endl;
    cout<<"3. Pick a Fight"<<endl;
    cout<<"4. Cook and Eat"<<endl;
    cout<<"5. Give up"<<endl;
}

//prints actions available for a NPC space
void printActionsNPC()
{
    cout<<"It seems there's a Non-Player-Character here."<<endl;
    cout<<"You can do a few things:"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Speak to NPC"<<endl;
    cout<<"3. Give up"<<endl;
}

//prints actions available for a Room space
void printActionsRoom()
{
    cout<<"You're currently on a Room space. What do you want to do?"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Open the door"<<endl;
    cout<<"3. Change your party's Loadout"<<endl;
    cout<<"4. Give up"<<endl;
}

//chooses randomly from available puzzles and gives it to user
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

//splits strings
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

//prints and writes results to screen, results.txt, and scoreboard.txt if the player won
void results(Party my_party, bool win_lose)
{
    cin.ignore();
    string temp_string;
    string temp_temp_string;
    
    int finalScore = 0;
    string arr[2];
    string temp;
    string arrr[2];
    ofstream output;
    output.open("results.txt");
    output<<"RESULTS:"<<endl
    <<"+-------------------------------------------+"<<endl;
    if(win_lose == 0)
    {
        output<<"YOU LOST"<<endl;
    }else
    {
        output<<"YOU WON"<<endl;
    }
    
        output<<"+-------------+"<<endl; 
        output<<"| PARTY       |"<<endl;
        output<<"+-------------+"<<endl; 
        for(int i = 0; i < my_party.getNumMembers(); i++)
        {
            if(my_party.getMembersAt(i).getAlive() == 1)
            {
                output<<"| "<<my_party.getMembersAt(i).getName()<<" | Fullness: "<<my_party.getMembersAt(i).getFullness()<<" | Weapon: "<<my_party.getMembersAt(i).getWeapon()<<endl;    
            }
        }
        output<<"+-------------+"<<endl; 
        output<<"| Rooms Cleared     | "<<my_party.getRoomsCleared()<<endl;
        output<<"| Gold              | "<<my_party.getGold()<<endl;
        output<<"| Treasures         | R: "<<my_party.getTreasuresAt(0)<<" | N: "<<my_party.getTreasuresAt(1)<<" | B: "<<my_party.getTreasuresAt(2)<<" | C: "<<my_party.getTreasuresAt(3)<<" | G: "<<my_party.getTreasuresAt(4)<<endl;
        output<<"| Spaces Explored   | "<<my_party.getNumExplored()<<endl;
        output<<"| Monsters Defeated | "<<my_party.getMonstersDefeated()<<endl;
        output<<"| Turns             | "<<my_party.getTurns()<<endl;
        output<<"+------------------------------------------+"<<endl<<endl;

        finalScore = my_party.getRoomsCleared() * 1000 + my_party.getGold() * 100 + my_party.getTreasuresAt(0) * 1000 + my_party.getTreasuresAt(1) * 2000 
        + my_party.getTreasuresAt(2) * 3000 + my_party.getTreasuresAt(3) * 4000 + my_party.getTreasuresAt(4) * 5000 + my_party.getNumExplored() * 100
        + my_party.getMonstersDefeated() * 100 + my_party.getNumMembers() * 1000 + my_party.getWeaponsAt(0) * 1000 + my_party.getWeaponsAt(1) * 2000 
        + my_party.getWeaponsAt(2) * 3000 + my_party.getWeaponsAt(3) * 4000 + my_party.getWeaponsAt(4) * 5000;
        
        finalScore -= my_party.getTurns() * 500;
        cout<<"Your final score was: "<<finalScore<<endl;
        output<<"Your final score was: "<<finalScore<<endl<<endl;

        if(win_lose == 1)
        {
            ifstream in;
            ofstream out;
            in.open("scoreboard.txt");
            if(in.is_open() == false)
            {
                out.open("scoreboard.txt");
                out<<"LEADERBOARD"<<endl;
                out<<"+-----------------------------+"<<endl;
                out.close();
                in.open("scoreboard.txt");
            }
            vector<string> notscores;
            vector<string> scores;
            for(int i = 0; getline(in, temp_string); i++)
            {   
                if(i == 0 || i == 1)
                {
                    notscores.push_back(temp_string);
                }else
                {
                    scores.push_back(temp_string);
                }
                
            }
            temp_string = my_party.getMembersAt(0).getName() + "~" + to_string(finalScore);
            scores.push_back(temp_string);
            for(int j = 0; j < scores.size(); j++){
                for(int i = 0; i <scores.size()-1; i++)
                {
                    split(scores.at(i), '~', arr, 2);
                    split(scores.at(i+1), '~', arrr, 2);
                    if (stoi(arr[1]) < stoi(arrr[1]))
                    {
                        temp = scores.at(i);
                        scores.at(i) = scores.at(i+1);
                        scores.at(i+1) = temp;
                    }
                }
            }
            out.open("scoreboard.txt");
            for(int i = 0; i < notscores.size(); i++)
            {
                out<<notscores.at(i)<<endl;
            }
            for(int i = 0; i < scores.size(); i++)
            {
                out<<scores.at(i)<<endl;
            }
        }

        return;
}

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
