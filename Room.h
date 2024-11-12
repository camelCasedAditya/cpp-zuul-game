#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include "Item.h"
using namespace std;

class Room {
 public:
  Room();
  void setExit(char direction, Room* neighbor);
  void setDescription(char* newDescription);
  void getDescription();
  char* getShortDescription();
  void getExitDescriptions();
  Room* getExit(char direction);
  Item* getItem(char* name);
  void addItem(Item* item);
  void removeItem(char* name);
  void setItem();
  
 protected:
  unordered_map<char, Room*> exitMap;
  vector<Item*> items;
  char* description;
};
