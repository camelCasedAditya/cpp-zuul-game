#include <iostream>
#include <vector>
#include <unordered_map>
#include "Room.h"
//#include "Item.h"
using namespace std;

int main() {
  
  //unordered_map<char, int> umap;
  //umap['u'] = 10;
  //umap['l'] = 20;
  //cout << umap.at('l') << endl;
  //cout << umap.at('u') << endl;

  char input[100] = "Exit room description";
  Room* room = new Room();
  Room* room2 = new Room();
  room2->setDescription(input);
  room->setExit('u', room2);
  Room* exitRoom = room->getExit('u');
  exitRoom->getDescription();
  return 0;
}
