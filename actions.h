#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <iostream>
//#include "mob.h"
#include "Map.h"
#include "Party.h"

using namespace std;

void printActionsNormal();

//void NormalActions(Map, Party/*, Mob*/);

void printActionsNPC();

void printActionsRoom();

bool doorPuzzle();

//Map mover(Map);

#endif