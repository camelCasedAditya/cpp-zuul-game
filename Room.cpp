#include <iostream>
#include <cstring>
#include <unordered_map>
#include "Room.h"
//#include "Item.h"
using namespace std;

Room::Room() {
  unordered_map<char, Room*> exitMap;
  //items = new vector<Item>;
  description = new char[100];
}

void Room::setExit(char direction, Room* room) {
  exitMap[direction] = room;
}

void Room::setDescription(char* newDescription) {
  description = newDescription;
}

//char* Room::getExitDescriptions() {
//return *"NONE"
  // print out all items in exitMap
//}

Room* Room::getExit(char direction) {
  return exitMap.at(direction);
}

void Room::getDescription() {
  cout << description << endl;
}
