#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include "Room.h"
//#include "Item.h"
using namespace std;

// Room onject constructor
Room::Room() {
  unordered_map<char, Room*> exitMap;
  //items = new vector<Item>;
  description = new char[100];
}

// Sets one of the rooms exit to another room
void Room::setExit(char direction, Room* room) {
  exitMap[direction] = room;
}

// Sets the room description
void Room::setDescription(char* newDescription) {
  description = newDescription;
}

// Returns all the exits the room has
void Room::getExitDescriptions() {
  cout << "These are the exits for this room" << endl;
  for (auto i : exitMap) {
    cout << i.first << endl;

  }
}

// Returns the room that an exit leads to
Room* Room::getExit(char direction) {
  for (auto i : exitMap) {
    if (i.first == direction) {
      return i.second;
    }
  }
  return NULL;
}

// returns the short description of the room
char* Room::getShortDescription() {
  return description;
}

// returns the long description of the room
void Room::getDescription() {
  cout << description << endl;
  cout << "Items in this room: " << endl;
  for (int i = 0; i<items.size(); i++) {
    cout << items[i]->getName() << endl;
  }
}

// Adds an item to the room
void Room::addItem(Item* item) {
  items.push_back(item);
}

// Removes an item from the room based on its name
void Room::removeItem(char* name) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getName(), name) == 0) {
      items.erase(items.begin() + i);
      break;
    }
  }
}

// Returns an item if the room has an item with the inputted name
Item* Room::getItem(char* name) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getName(), name) == 0) {
      return items[i];
    }
  }
  return NULL;
}
