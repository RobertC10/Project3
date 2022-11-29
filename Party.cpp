//Editor: Robert Church

#include <string>
#include "Party.h"
#include "Member.h"
#include <iostream>

//#include "Mob.h"

using namespace std;

    Party::Party()
    {
        Member temp_member;
        num_members_ = 5;
        members_ = {temp_member, temp_member, temp_member, temp_member, temp_member};
        gold_ = 100;
        rooms_cleared_ = 0;
        ingredients_ = 0;
        for(int i = 0; i < 3; i++)
        {
            cookware_[i] = 0;
        }
        for(int i = 0; i < 5; i++)
        {
            weapons_[i] = 0;
        }
        armor_ = 0;
        for(int i = 0; i < 5; i++)
        {
            treasures_[i] = 0;
        }
        keys_ = 0;
    }

    Party::Party(int party_members, int gold, int rooms_cleared, int ingredients, int armor, int keys)
    {
        Member temp_member;
        num_members_ = party_members;
        gold_ = gold;
        rooms_cleared_ = rooms_cleared;
        ingredients_ = ingredients;
        armor_ = armor;
        keys_ = keys;
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

    int Party::getNumMembers()
    {
        return num_members_;
    }

    int Party::getGold()
    {
        return gold_;
    }

    Member Party::getMembersAt(int index)
    {
        return members_.at(index);
    }

    int Party::getRoomsCleared()
    {
        return rooms_cleared_;
    }

    int Party::getIngredients()
    {
        return ingredients_;
    }
    
    int Party::getCookwareAt(int index)
    {
        return cookware_[index];
    }

    int Party::getWeaponsAt(int index)
    {
        return weapons_[index];
    }

    int Party::getArmor()
    {
        return armor_;
    }

    int Party::getTreasuresAt(int index)
    {
        return treasures_[index];
    }

    int Party::getKeys()
    {
        return keys_;
    }

    void Party::setNumMembers(int num_members)
    {
        num_members_ = num_members;
    }

    void Party::addGold(int gold)
    {
        gold_ += gold;
    }

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

    void Party::setMemberAt(int index, Member myMember)
    {
        members_.erase(members_.begin()+index);
        members_.emplace(members_.begin()+index, myMember);
    }

    void Party::addMember(Member myMember)
    {
        members_.push_back(myMember);
        num_members_++;
    }

    void Party::removeMemberAt(int index)
    {
        members_.erase(members_.begin()+index);
        num_members_--;
    }

    void Party::addRoomsCleared(int rooms_cleared)
    {
        rooms_cleared_ += rooms_cleared;
    }

    void Party::addIngredients(int ingredients)
    {
        ingredients_ += ingredients;
    }
    
    bool Party::subIngredients(int ingredients)
    {
        if(ingredients_ - ingredients >= 0)
        {
            ingredients_ -= ingredients;
            return 1;
        }else
        {
            return 0;
        }
    }

    void Party::addCookwareAt(int index, int number)
    {
        cookware_[index] += number;
    }

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

    void Party::addWeaponsAt(int index, int number)
    {
        weapons_[index] = number;
    }

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

    void Party::addArmor(int armor)
    {
        armor_ += armor;
    }

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

    void Party::addTreasuresAt(int index, int treasures)
    {
        treasures_[index] += treasures;
    }

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

    void Party::addKeys(int keys)
    {
        keys_ += keys;
    }

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

    void Party::printMenu(/*Mob sorcerer, */)
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
        for(int i = 0; i < getNumMembers(); i++)
        {
            if(getMembersAt(i).getAlive() == 1)
            {
                cout<<"| "<<getMembersAt(i).getName()<<" | Fullness: "<<getMembersAt(i).getFullness()<<endl;    
            }
        }
        cout<<"+-------------+"<<endl;
        
    }

void Party::printStats()
{
    cout<<"+-------------+"<<endl;
        cout<<"| STATUS      |"<<endl;
        cout<<"+-------------+"<<endl;
        cout<<"| Rooms Cleared: "<<getRoomsCleared()<<" | Keys: "<<keys_<<" | Anger Level: "<</*sorcerer.getAnger()<<*/endl;
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

void Party::addAnger(int anger)
{
    anger_ += anger;
}

int Party::getAnger()
{
    return anger_;
}






