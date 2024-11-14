#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;

// Constructor for item object
Item::Item() {
  name = new char[20];
  description = new char[100];
}

// function to return item name
char* Item::getName() {
  return name;
}

// function to return item description
char* Item::getDescription() {
  return description;
}

// function to set item name
void Item::setName(char* newname) {
  name = newname;
}

// function to set item description
void Item::setDescription(char* newdescription) {
  description = newdescription;
}
