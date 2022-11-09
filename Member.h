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
        char weapon_type_;
    public:
        Member();
        Member(string, int, bool, char);
        string getName();
        int getFullness();
        bool getAlive();
        char getWeapon();
        void setName(string);
        void setFullness(int);
        void setAlive(bool);
        void setWeapon(char);

};

#endif