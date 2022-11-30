//Editor: Robert Church

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

using namespace std;

class Member
{
    private:
        string name_;
        int fullness_;
        bool is_alive_;
        int weapon_type_;
    public:
        Member();
        Member(string, int, bool, char);
        string getName();
        int getFullness();
        bool getAlive();
        int getWeapon();
        void setName(string);
        void addFullness(int);
        void subFullness(int);
        void setAlive(bool);
        void setWeapon(int);

};

#endif
