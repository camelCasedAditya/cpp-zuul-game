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
  void getExitDescription();
  Room* getExit(char direction);
  Item* getItem(char name[20]);
  void addItem(Item* item);
  void removeItem(char name[20]);
  void setItem();
  
 protected:
  unordered_map<char, Room*> exitMap;
  vector<Item*> items;
  char* description;
};
