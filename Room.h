#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include "Item.h"
using namespace std;

class Room {
 public:
  // room object constructor
  Room();
  // function to set an exit for a room
  void setExit(char direction, Room* neighbor);
  // function to set the room description
  void setDescription(char* newDescription);
  // function to get the room description
  void getDescription();
  // function to get the short room description
  char* getShortDescription();
  // function to get the all the exits of a room
  void getExitDescriptions();
  // function to get the next room of an exit from a direction
  Room* getExit(char direction);
  // function to get an item in the room
  Item* getItem(char* name);
  // function to add an item to the room
  void addItem(Item* item);
  // function to remove an item from the room
  void removeItem(char* name);
  // function to set an item
  void setItem();

  // attributes of a Room object 
 protected:
  unordered_map<char, Room*> exitMap;
  vector<Item*> items;
  char* description;
};
