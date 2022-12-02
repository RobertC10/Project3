//Editor: Robert Church

#include <string>
#include "Party.h"
#include "Member.h"
#include <iostream>

//#include "Mob.h"

using namespace std;

    //default constructor
    Party::Party()
    {
        Member temp_member;
        num_members_ = 5;
        members_ = {temp_member, temp_member, temp_member, temp_member, temp_member};
        gold_ = 100;
        rooms_cleared_ = 0;
        ingredients_ = 0;
        anger_ = 0;
        numExplored_ = 0;
        monsters_defeated_ = 0;
        turns_ = 0;
        
        for(int i = 0; i < 3; i++)
        {
            cookware_[i] = 0;
        }
        for(int i = 0; i < 5; i++)
        {
            weapons_[i] = 0;
            partyWeapons_[i] = 0;
        }
        armor_ = 0;
        for(int i = 0; i < 5; i++)
        {
            treasures_[i] = 0;
        }
        keys_ = 0;
    }

    //parametarized constructor
    Party::Party(int party_members, int gold, int rooms_cleared, int ingredients, int armor, int keys, int anger)
    {
        Member temp_member;
        num_members_ = party_members;
        gold_ = gold;
        rooms_cleared_ = rooms_cleared;
        ingredients_ = ingredients;
        armor_ = armor;
        keys_ = keys;
        anger_ = anger;
        members_ = {temp_member, temp_member, temp_member, temp_member, temp_member};
        for(int i = 0; i < 3; i++)
        {
            cookware_[i] = 0;
        }
        for(int i = 0; i < 5; i++)
        {
            weapons_[i] = 0;
        }
        for(int i = 0; i < 5; i++)
        {
            treasures_[i] = 0;
        }
    }

    //returns number of members that are alive
    int Party::getNumMembers()
    {
        int memebrs = 0;
        for(int i = 0; i < 5; i++)
        {
            if(getMembersAt(i).getAlive() == 1)
            {
                memebrs ++;
            }
        }
        return memebrs;
    }

    //returns amount of gold
    int Party::getGold()
    {
        return gold_;
    }

    //returns member at position index
    Member Party::getMembersAt(int index)
    {
        return members_.at(index);
    }

    //returns number of rooms cleared
    int Party::getRoomsCleared()
    {
        return rooms_cleared_;
    }

    //returns number of ingredients
    int Party::getIngredients()
    {
        return ingredients_;
    }
    
    //returns number of cookware at index
    int Party::getCookwareAt(int index)
    {
        return cookware_[index];
    }

    //returns number of weapons at index
    int Party::getWeaponsAt(int index)
    {
        return weapons_[index];
    }

    //returns amount of armor
    int Party::getArmor()
    {
        return armor_;
    }

    //returns how much treasure is at index
    int Party::getTreasuresAt(int index)
    {
        return treasures_[index];
    }

    //returns amount of keys
    int Party::getKeys()
    {
        return keys_;
    }

    //sets number of members to the amount that are alive
    void Party::setNumMembers()
    {
        int num_members = 0;
        for(int i = 0; i < 5; i++)
        {
            if(getMembersAt(i).getAlive() == 1)
            {
                num_members++;
            }
        }
        num_members_ = num_members;
    }

    //adds gold
    void Party::addGold(int gold)
    {
        gold_ += gold;
    }

    //takes away specified amount of gold. If insufficient amount, returns 0;
    bool Party::subGold(int gold)
    {
        if(gold_ - gold >= 0)
        {
            gold_ -= gold;
            return 1;
        }
        else
        {
            return 0;
        }

    }

    //sets member at index
    void Party::setMemberAt(int index, Member myMember)
    {
        members_.erase(members_.begin()+index);
        members_.emplace(members_.begin()+index, myMember);
    }

    //adds a member to the vector (unused)
    void Party::addMember(Member myMember)
    {
        members_.push_back(myMember);
        num_members_++;
    }

    //removes member from vector (unused)
    void Party::removeMemberAt(int index)
    {
        members_.erase(members_.begin()+index);
        num_members_--;
    }

    //adds to number of rooms cleared
    void Party::addRoomsCleared(int rooms_cleared)
    {
        rooms_cleared_ += rooms_cleared;
    }

    //adds number of ingredients
    void Party::addIngredients(int ingredients)
    {
        ingredients_ += ingredients;
    }
    
    //takes away specified amount of ingredients. If insufficient amount, returns 0;
    bool Party::subIngredients(int ingredients)
    {
        if(ingredients_ - ingredients >= 0)
        {
            ingredients_ -= ingredients;
            return 1;
        }else
        {
            ingredients_ = 0;
            return 0;
        }
    }

    //adds number of cookware at index
    void Party::addCookwareAt(int index, int number)
    {
        cookware_[index] += number;
    }

    //takes away specified amount of cookware at index. If insufficient amount, returns 0;
    bool Party::subCookwareAt(int index, int number)
    {
        if(cookware_[index] - number >= 0)
        {
            cookware_[index] -= number;
            return 1;
        }else
        {
            return 0;
        }
    }

    //adds number of weapons at index
    void Party::addWeaponsAt(int index, int number)
    {
        weapons_[index] = number;
    }

    //takes away specified amount of weapons from index. If insufficient amount, returns 0;
    bool Party::subWeaponsAt(int index, int number)
    {
        if(weapons_[index] - number >= 0)
        {
            weapons_[index] -= number;
            return 1;
        }else
        {
            return 0;
        }
    }

    //adds armor
    void Party::addArmor(int armor)
    {
        armor_ += armor;
    }

    //takes away specified amount of armor. If insufficient amount, returns 0;
    bool Party::subArmor(int armor)
    {
        if(armor_ - armor >= 0)
        {
            armor_ -= armor;
            return 1;
        }else
        {
            return 0;
        }
    }

    //adds treasure at index
    void Party::addTreasuresAt(int index, int treasures)
    {
        treasures_[index] += treasures;
    }

    //takes away specified amount of treasure at index. If insufficient amount, returns 0;
    bool Party::subTreasuresAt(int index, int treasures)
    {
        if(treasures_[index] - treasures >= 0)
        {
            treasures_[index] -= treasures;
            return 1;
        }else
        {
            return 0;
        }
    }

    //adds number of keys.
    void Party::addKeys(int keys)
    {
        keys_ += keys;
    }

    //takes away specified amount of keys. If insufficient amount, returns 0;
    bool Party::subkeys(int keys)
    {
        if(keys_ - keys >= 0)
        {
            keys_ -= keys;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //prints the Menu. This includes all stats and party members
    void Party::printMenu()
    {
        cout<<"+-------------+"<<endl;
        cout<<"| STATUS      |"<<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| Rooms Cleared: "<<getRoomsCleared()<<" | Keys: "<<keys_<<" | Anger Level: "<<getAnger()<<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| INVENTORY   |"<<endl;  
        cout<<"+-------------+"<<endl;
        cout<<"| Gold        | "<<gold_<<endl;
        cout<<"| Ingredients | "<<ingredients_<<" kg"<<endl;
        cout<<"| Cookware    | P: "<<getCookwareAt(0)<<" | F: "<<getCookwareAt(1)<<" | C: "<<getCookwareAt(2)<<endl;
        cout<<"| Weapons     | C: "<<getWeaponsAt(0)<<" | S: "<<getWeaponsAt(1)<<" | R: "<<getWeaponsAt(2)<<" | B: "<<getWeaponsAt(3)<<" | L: "<<getWeaponsAt(4)<<endl;
        cout<<"| Armor       | "<<getArmor()<<endl;
        cout<<"| Treasures   | R: "<<getTreasuresAt(0)<<" | N: "<<getTreasuresAt(1)<<" | B: "<<getTreasuresAt(2)<<" | C: "<<getTreasuresAt(3)<<" | G: "<<getTreasuresAt(4)<<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| PARTY       |"<<endl;
        cout<<"+-------------+"<<endl; 
        for(int i = 0; i < 5; i++)
        {
            if(getMembersAt(i).getAlive() == 1)
            {
                cout<<"| "<<getMembersAt(i).getName()<<" | Fullness: "<<getMembersAt(i).getFullness()<<endl;    
            }
        }
        cout<<"+-------------+"<<endl;
        
    }

    //prints just the stats for the party
    void Party::printStats()
    {
        cout<<"+-------------+"<<endl;
            cout<<"| STATUS      |"<<endl;
            cout<<"+-------------+"<<endl;
            cout<<"| Rooms Cleared: "<<getRoomsCleared()<<" | Keys: "<<keys_<<" | Anger Level: "<<getAnger()<<endl;
            cout<<"+-------------+"<<endl;
            cout<<"| INVENTORY   |"<<endl;  
            cout<<"+-------------+"<<endl;
            cout<<"| Gold        | "<<gold_<<endl;
            cout<<"| Ingredients | "<<ingredients_<<" kg"<<endl;
            cout<<"| Cookware    | P: "<<getCookwareAt(0)<<" | F: "<<getCookwareAt(1)<<" | C: "<<getCookwareAt(2)<<endl;
            cout<<"| Weapons     | C: "<<getWeaponsAt(0)<<" | S: "<<getWeaponsAt(1)<<" | R: "<<getWeaponsAt(2)<<" | B: "<<getWeaponsAt(3)<<" | L: "<<getWeaponsAt(4)<<endl;
            cout<<"| Armor       | "<<getArmor()<<endl;
            cout<<"| Treasures   | R: "<<getTreasuresAt(0)<<" | N: "<<getTreasuresAt(1)<<" | B: "<<getTreasuresAt(2)<<" | C: "<<getTreasuresAt(3)<<" | G: "<<getTreasuresAt(4)<<endl;
    }

    //prints just the party members
    void Party::printParty()
    {
            cout<<"+-------------+"<<endl; 
            cout<<"| PARTY       |"<<endl;
            cout<<"+-------------+"<<endl; 
            for(int i = 0; i < 5; i++)
            {
                if(getMembersAt(i).getAlive() == 1)
                {
                    cout<<"| "<<getMembersAt(i).getName()<<" | Fullness: "<<getMembersAt(i).getFullness()<<" | Weapon: "<<getMembersAt(i).getWeapon()<<endl;    
                }
            }
            cout<<"+-------------+"<<endl; 
    }

    //adds to sorcerer anger
    void Party::addAnger(int anger)
    {
        anger_ += anger;
    }

    //returns anger
    int Party::getAnger()
    {
        return anger_;
    }

    //sets the amount of weapons of each type the party is currently holding not in the inventory
    void Party::setPartyWeapons()
    {
        for(int i = 0; i < 5; i++)
        {
            partyWeapons_[i] = 0;
        }

        int weapon;
        for(int i = 0; i < 5; i++)
        {
            weapon = getMembersAt(i).getWeapon();
            switch (weapon)
            {
            case 1:
                partyWeapons_[0]++;
                break;
            case 2:
                partyWeapons_[1]++;
                break;
            case 3:
                partyWeapons_[2]++;
                break;
            case 4:
                partyWeapons_[3]++;
                break;
            case 5:
                partyWeapons_[4]++;
                break;
            
            default:
                break;
            }
        }
    }

    //returns number of weapons the party is currently holding not in the inventory at index
    int Party::getPartyWeaponsAt(int index)
    {
        return partyWeapons_[index];
    }

    //prompts user to change what weapon each member in the party is holding 
    bool Party::setWeapons()
    {
        string yesNo = "";
        string squad = "";
        string weapon = "";
        Member temp_member;

        cout<<"Do you want to edit who has what weapon in your party?"<<endl;
        cin>>yesNo;
        cout << "" << endl;
        while(yesNo[0] == 'y' || yesNo[0] == 'Y')
        {  
            cout<<"You have: "<<getWeaponsAt(0)<<" club(s), "<<getWeaponsAt(1)<<" iron spear(s), "<<getWeaponsAt(2)<<" rapier(s), "<<getWeaponsAt(3)<<" battle-axe(s), "<<getWeaponsAt(4)<<" longsword(s)."<<endl;
            printParty();
            cout<<"Whos weapon do you want to change?(type their position)"<<endl;
            cin>>squad;
            while(squad != "1" && squad != "2" && squad != "3" && squad != "4" && squad != "5")
            {
                cout<<"Please enter a valid input."<<endl;
                cin>>squad;
            }
            cout<<"What weapon would you like to give them?"<<endl
            <<"-1) Nothing"<<endl
            <<"1) Club"<<endl
            <<"2) Iron Spear"<<endl
            <<"3) Rapier"<<endl
            <<"4) Battle-Axe"<<endl
            <<"5) LongSword"<<endl;
            cin>>weapon;
            while(weapon != "-1" && weapon != "1" && weapon != "2" && weapon != "3" && weapon != "4" && weapon != "5")
            {
                cout<<"Please enter a valid input."<<endl;
                cin>>weapon;
            }
            if(weapon == "-1")
            {
                temp_member = getMembersAt(stoi(squad)-1);
                temp_member.setWeapon(-1);
                setMemberAt(stoi(squad)-1, temp_member);
            }else
            if(partyWeapons_[stoi(weapon)-1] < weapons_[stoi(weapon)-1])
            {
                temp_member = getMembersAt(stoi(squad)-1);
                temp_member.setWeapon(stoi(weapon));
                setMemberAt(stoi(squad)-1, temp_member);
            }else
            {
                cout<<"You do not have enough of that weapon to do that."<<endl;
                cout << "" << endl;
            }

            setPartyWeapons();

            cout<<"Do you want to still edit who has what weapon in your party?"<<endl;
            cin>>yesNo;
        }

        return 1;
    }

    //adds to number of spaces explored
    void Party::addnumExplored(int rooms)
    {
        numExplored_ += rooms;
    }

    //returns numebr of spaces explored
    int Party::getNumExplored()
    {
        return numExplored_;
    }

    //adds to the amount of monsters defeated
    void Party::addMonstersDefeated(int monsters)
    {
        monsters_defeated_ += monsters;
    }

    //returns numebr of monsters defeated
    int Party::getMonstersDefeated()
    {
        return monsters_defeated_;
    }

    //adds to the number of turns taken
    void Party::addTurns(int turns)
    {
        turns_ += turns;
    }

    //returns number of turns taken
    int Party::getTurns()
    {
        return turns_;
    }
    
    //prints stats of the party when the game ends.
    void Party::printFinalStats()
    {
        printParty();
        cout<<"| Rooms Cleared     | "<<getRoomsCleared()<<endl;
        cout<<"| Gold              | "<<getGold()<<endl;
        cout<<"| Treasures         | R: "<<getTreasuresAt(0)<<" | N: "<<getTreasuresAt(1)<<" | B: "<<getTreasuresAt(2)<<" | C: "<<getTreasuresAt(3)<<" | G: "<<getTreasuresAt(4)<<endl;
        cout<<"| Spaces Explored   | "<<getNumExplored()<<endl;
        cout<<"| Monsters Defeated | "<<getMonstersDefeated()<<endl;
        cout<<"| Turns             | "<<getTurns()<<endl;
        cout<<"+------------------------------------------+"<<endl;
    }




