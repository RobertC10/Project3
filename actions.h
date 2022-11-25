#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <iostream>
#include "Mob.h"
#include "Map.h"
#include "Party.h"

using namespace std;


void printActionsNormal();

//void NormalActions(Map, Party/*, Mob*/);

void printActionsNPC();

void printActionsRoom();

bool doorPuzzle();

int split(string, char, string[], int);

int readMobs(Mob[]);

void sorcerersAnger();

//Map mover(Map);

#endif