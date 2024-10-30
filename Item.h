#include <iostream>
#include <cstring>
using namespace std;

class Item {
 public:
  Item();
  void getName();
  void getDescription();
 protected:
  char name[20];
  char description[100];
}
