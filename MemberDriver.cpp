#include <string>
#include <cassert>
#include "Member.h"

using namespace std;

int main()
{
    Member member1 = Member();
    assert(member1.getAlive() == 1);
    assert(member1.getFullness() == 50);
    assert(member1.getName() == "");
    assert(member1.getWeapon() == 'N');

    Member member2 = Member();
    member2.setAlive(false);
    assert(member2.getAlive() == 0);
    member2.setFullness(49);
    assert(member2.getFullness() == 49);

    Member member3 = Member("Bobby", 25, true, 'C');
    assert(member3.getAlive() == true);
    assert(member3.getFullness() == 25);
    assert(member3.getName() == "Bobby");
    assert(member3.getWeapon() == 'C');
}