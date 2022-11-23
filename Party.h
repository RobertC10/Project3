#ifndef PARTY_H
#define PARTY_H

#include <string>
#include <vector>
#include "Member.h"
#include <iostream>

using namespace std;

class Party
{
    private:
        int num_members_;
        vector<Member> members_;
        int gold_;
        int rooms_cleared_;
        int ingredients_;
        int cookware_[3];
        int weapons_[5];
        int armor_;
        int treasures_[5];
        int keys_;
    public:
        Party();
        Party(int, int, int, int, int, int);
        int getNumMembers();
        int getGold();
        Member getMembersAt(int);
        int getRoomsCleared();
        int getIngredients();
        int getCookwareAt(int);
        int getWeaponsAt(int);
        int getArmor();
        int getTreasuresAt(int);
        int getKeys();
        void setNumMembers(int);
        void addGold(int);
        void setMemberAt(int, Member);
        void addMember(Member);
        void removeMemberAt(int);
        void addRoomsCleared(int);
        void addIngredients(int);
        void setCookwareAt(int, int);
        void setWeaponsAt(int, int);
        void addArmor(int);
        void addTreasuresAt(int, int);
        void subTreasuresAt(int, int);
        void addKeys(int);
        void subkeys(int);
        void printMenu(/*Mob, */);
};

#endif