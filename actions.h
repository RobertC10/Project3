//Editors: Robert Church & Jevan Wiltz

#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <iostream>
#include "Map.h"
#include "Party.h"

using namespace std;


void printActionsNormal();

void printActionsNPC();

void printActionsRoom();

bool doorPuzzle();

int split(string, char, string[], int);

void results(Party, bool);

//Map mover(Map);

#endif
