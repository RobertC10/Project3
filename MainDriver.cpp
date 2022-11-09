#include <string>
#include "Member.h"
#include "Party.h"
#include <iostream>

using namespace std;

int main()
{
    Member member1 = Member("Bruh", 25, 1, 'N');
    Party myParty = Party();
    Member temp_member = myParty.getMembersAt(0);
    myParty.setMemberAt(3, member1);
    Member user = Member("Main Character", 50, 1, 'R');
    myParty.printMenu(user);
}