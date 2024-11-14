#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>
using namespace std;

class Item {
 public:
  // Item object constructor
  Item();
  // function that returns the items name
  char* getName();
  // function that sets the items name
  void setName(char* newname);
  // function that returns the item description
  char* getDescription();
  // function that sets the item description
  void setDescription(char* newdescription);

  // Attributes of item object
 protected:
  char* name;
  char* description;
};

#endif
