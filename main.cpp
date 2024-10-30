#include <iostream>
#include <vector>
#include <unordered_map>
#include "Room.h"
#include "Item.h"
using namespace std;

int main() {
  char temp[100] = "you are in the starting room";
  Room* start = new Room();
  start->setDescription(temp);
  
  Room* cppClass = new Room();
  strcpy(temp, "You are in Mr.Galbraith's c++ classroom");
  cppClass->setDescription(temp);

  Room* courtYard = new Room();
  strcpy(temp, "You are in the beautiful courtyard");
  courtYard->setDescription(temp);
  
  Room* oneHall = new Room();
  strcpy(temp, "You are in one hall");
  oneHall->setDescription(temp);
  
  Room* library =  new Room();
  strcpy(temp, "You are in the library. Shhh");
  library->setDescription(temp);
  
  Room* aWing = new Room();
  strcpy(temp, "You are in a-wing");
  aWing->setDescription(temp);
  
  Room* aHall = new Room();
  strcpy(temp, "You are in the a-hallway");
  aHall->setDescription(temp);
  
  Room* englishClass = new Room();
  strcpy(temp, "You are in the english classroom");
  englishClass->setDescription(temp);
  
  Room* cHall = new Room();
  strcpy(temp, "You are in the c-hallway");
  cHall->setDescription(temp);
  
  Room* boringClassRoom = new Room();
  
  Room* dHall = new Room();
  Room* mainOffice = new Room();
  Room* computerLab = new Room();
  Room* tWing = new Room();
  Room* artRoom = new Room();
  Room* gym = new Room();
  Room* spanishClass = new Room();

  
  bool hasItems = false;
  vector<Item*> inventory;
  Room* currentRoom;
  while(hasItems == false) {
    break;
  }
  
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
