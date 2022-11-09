#include "Map.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Map map;
    cout << "Initial map: " << endl;
    map.displayMap(); // starting point
    cout << "Default constructor: " << endl;
    cout << "Room #: " << map.getRoomCount() << endl;
    cout << "Let's add some rooms: " << endl;
    assert(map.addRoom(2, 3));
    assert(map.addRoom(8, 11));
    assert(map.addRoom(2, 7));
    assert(map.addRoom(8, 2));
    assert(!map.addRoom(15, 15)); // should not show on map nor error out, out of bounds
    assert(!map.addRoom(2, 3));   // will not do anything since space is occupied
    assert(map.addRoom(5, 7));
    assert(!map.addRoom(3, 7)); // will fail due to exceeding max_rooms_
    map.displayMap();
    cout << "Spawning some NPCs: " << endl;
    assert(map.addNPC(4, 4));
    assert(map.addNPC(1, 2));
    assert(map.addNPC(7, 2));
    assert(map.addNPC(10, 4));
    assert(!map.addNPC(2, 7)); // should fail due to space being occupied
    assert(map.addNPC(9, 0));
    assert(!map.addNPC(10, 0)); // should fail due to max number of NPCs == 5
    map.displayMap();
    cout << "Let's move a little. First, down:" << endl;
    map.move('s'); // go down
    map.displayMap();
    cout << "Now, right:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On an NPC space? ..." << map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Moving onto an NPC space that was previously hidden:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On NPC space now?..." << map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Let's move off it, should be updated as visible:" << endl;
    map.move('d'); // go right
    map.displayMap();
    cout << "On room right now?..." << map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "Okay, let's move onto the room:" << endl;
    map.move('s');
    map.displayMap();
    cout << "On room right now? " << map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) << endl;
    cout << "... and move left off" << endl;
    map.move('a');
    map.displayMap();
    cout << "Let's remove that room" << endl;
    assert(map.removeRoom(2, 3));
    map.displayMap();
    cout << "Let's explore the current space, then move down." << endl;
    map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
    map.move('s');
    map.displayMap();
    return 0;
}
