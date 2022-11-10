#include <string>
#include "Member.h"
#include "Party.h"
#include "Map.h"
#include <iostream>
#include <cassert>

using namespace std;

void phaseOne();

int main()
{
    phaseOne();
}

void phaseOne()
{
    Map map = Map();
    srand(time(0));
    int rand1 = rand() % 12;
    int rand2 = rand() % 12;

    for(int i = 0; i < 5; i++)
    {
        while((rand1 == 0 && rand2 == 0) || (rand1 == 6 && rand2 == 15) || map.isRoomLocation(rand1, rand2))
        {
            rand1 = rand() % 12;
            rand2 = rand() % 12;
        }
        map.addRoom(rand1, rand2); 
    }

    for(int i = 0; i < 5; i++)
    {
        while((rand1 == 0 && rand2 == 0) || (rand1 == 11 && rand2 == 6) || map.isRoomLocation(rand1, rand2) || map.isNPCLocation(rand1, rand2))
        {
            rand1 = rand() % 12;
            rand2 = rand() % 12;
        }
        map.addNPC(rand1, rand2);
    }
}

