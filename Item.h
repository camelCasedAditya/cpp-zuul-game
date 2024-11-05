#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>
using namespace std;

class Item {
 public:
  Item();
  char* getName();
  void setName(char* newname);
  char* getDescription();
  void setDescription(char* newdescription);
 protected:
  char* name;
  char* description;
};

#endif
