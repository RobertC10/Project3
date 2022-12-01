//Editor: Robert Church

#include <string>
#include <iostream>
#include "Member.h"

using namespace std;
    /*
    - Default unperameterized constructor
    */
    Member::Member()
    {
        /*
        - Default unperameterized constructor
        */
        name_ = "";
        fullness_ = 50;
        weapon_type_ = -1;
        is_alive_ = true;
    }

    /*
    - perameterized constructor
    */
    Member::Member(string name, int fullness, bool is_alive, int weapon_type)
    {
        /*
        - perameterized constructor
        */
        name_ = name;
        fullness_ = fullness;
        is_alive_ = is_alive;
        weapon_type_ = weapon_type;
    }
     //returns name
    string Member::getName()
    {
        //returns name
        return name_;
    }
    //returns fullness
    int Member::getFullness()
    {
        //returns fullness
        return fullness_;
    }
    //returns whether the Member is alive or not
    bool Member::getAlive()
    {
        //returns whether the Member is alive or not
        return is_alive_;
    }
    //returns what weapon the member has
    int Member::getWeapon()
    {
        //returns what weapon the member has
        return weapon_type_;
    }
    //sets name to input
    void Member::setName(string name)
    {
        //sets name to input
        name_ = name;
    }
    //if fullness is greater than 50 and less than 0, return, if not, then set fullness_ to fullness
    void Member::addFullness(int fullness)
    {
        //if fullness is greater than 50 and less than 0, return, if not, then set fullness_ to fullness
        if(fullness_ + fullness >= 50)
        {
            fullness_ = 50;
            return;
        }
        fullness_ += fullness;
    }
    // subtracts amount of fullness from fullness_ if less then 0, sets fullness_ to 0 and sets is_alive_ to 0
    void Member::subFullness(int fullness)
    {
        if(fullness_ - fullness <= 0)
        {
            fullness_ = 0;
            is_alive_ = false;
            return;
        }
        fullness_ -= fullness;
    }
    //sets if member is alive or not
    void Member::setAlive(bool is_alive)
    {
        //sets if member is alive or not
        is_alive_ = is_alive;
    }
    //if the weapon_type is valid, then set weapon_type
    void Member::setWeapon(int weapon_type)
    {
        //if the weapon_type is valid, then set weapon_type
        if(weapon_type == 0 || weapon_type == 1 || weapon_type == 2 || weapon_type == 3 || weapon_type == 4 || weapon_type == -1)
        {
        weapon_type_ = weapon_type;
        }
    }
