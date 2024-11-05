#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;

Item::Item() {
  name = new char[20];
  description = new char[100];
}

char* Item::getName() {
  return name;
}

char* Item::getDescription() {
  return description;
}

void Item::setName(char* newname) {
  name = newname;
}

void Item::setDescription(char* newdescription) {
  description = newdescription;
}
