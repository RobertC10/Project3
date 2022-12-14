#ifndef MAINDRIVER_H
#define MAINDRIVER_H

#include "Map.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Party.h"

int main();

void phaseThree(Map, Party);

void phaseTwo(Map, Party);

void phaseOne(Map, Party);

void phaseFour(Map, Party, bool);

void ExitAction(Map, Party);

void NormalAction(Map, Party);

void NPCAction(Map, Party);

void RoomAction(Map, Party);

#endif