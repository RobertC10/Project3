#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <iostream>
//#include "mob.h"
#include "Map.h"
#include "Party.h"

using namespace std;

void printActionsNormal();

void NormalActions(Map, Party/*, Mob*/);

//Map mover(Map);

bool investigate();

bool fight();

bool cookAndEat();

void giveUp();

bool readMonster();

#endif