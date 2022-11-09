#include <string>
#include <iostream>
#include "Member.h"

using namespace std;

    Member::Member()
    {
        /*
        - Default unperameterized constructor
        */
        name_ = "";
        fullness_ = 50;
        weapon_type_ = 'N';
        is_alive_ = true;
    }

    Member::Member(string name, int fullness, bool is_alive, char weapon_type)
    {
        /*
        - perameterized constructor
        */
        name_ = name;
        fullness_ = fullness;
        is_alive_ = is_alive;
        weapon_type_ = weapon_type;
    }

    string Member::getName()
    {
        //returns name
        return name_;
    }

    int Member::getFullness()
    {
        //returns fullness
        return fullness_;
    }

    bool Member::getAlive()
    {
        //returns whether the Member is alive or not
        return is_alive_;
    }

    char Member::getWeapon()
    {
        //returns what weapon the member has
        return weapon_type_;
    }

    void Member::setName(string name)
    {
        //sets name to input
        name_ = name;
    }

    void Member::setFullness(int fullness)
    {
        //if fullness is greater than 50 and less than 0, return, if not, then set fullness_ to fullness
        if(fullness>50 || fullness<0)
        {
            return;
        }
        fullness_ = fullness;
    }

    void Member::setAlive(bool is_alive)
    {
        //sets if member is alive or not
        is_alive_ = is_alive;
    }

    void Member::setWeapon(char weapon_type)
    {
        //if the weapon_type is valid, then set weapon_type
        if(weapon_type == 'C' || weapon_type == 'R' || weapon_type == 'S' || weapon_type == 'B' || weapon_type == 'L' || weapon_type == 'N')
        {
        weapon_type_ = weapon_type;
        }
    }