#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
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

void Room::getExitDescriptions() {
  cout << "These are the exits for this room" << endl;
  for (auto i : exitMap) {
    cout << i.first << " - " << i.second->getShortDescription() << endl;

  }
}
Room* Room::getExit(char direction) {
  return exitMap.at(direction);
}

char* Room::getShortDescription() {
  return description;
}

void Room::getDescription() {
  cout << description << endl;
  cout << "Items in this room: " << endl;
  for (int i = 0; i<items.size(); i++) {
    cout << items[i]->getName() << endl;
  }
}

void Room::addItem(Item* item) {
  items.push_back(item);
}

void Room::removeItem(char* name) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getName(), name) == 0) {
      items.erase(items.begin() + i);
      break;
    }
  }
}

Item* Room::getItem(char* name) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getName(), name) == 0) {
      return items[i];
    }
  }
  return NULL;
}
