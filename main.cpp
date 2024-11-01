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
  strcpy(temp, "You are in a very boring classroom");
  boringClassRoom->setDescription(temp);
  
  Room* dHall = new Room();
  strcpy(temp, "You are in d hallway");
  dHall->setDescription(temp);
  
  Room* mainOffice = new Room();
  strcpy(temp, "You are in the school main office");
  mainOffice->setDescription(temp);
  
  Room* computerLab = new Room();
  strcpy(temp, "You are in the computer lab");
  computerLab->setDescription(temp);
  
  Room* tWing = new Room();
  strcpy(temp, "You are in the t-building");
  tWing->setDescription(temp);
  
  Room* artRoom = new Room();
  strcpy(temp, "You are in the art room");
  artRoom->setDescription(temp);
  
  Room* gym = new Room();
  strcpy(temp, "You are in the gym");
  gym->setDescription(temp);
  
  Room* spanishClass = new Room();
  strcpy(temp, "You are in the spanish classroom");
  spanishClass->setDescription(temp);


  start->setExit('n', cppClass);
  start->setExit('s', oneHall);
  start->setExit('e', courtYard);
  start->setExit('w', tWing);

  cppClass->setExit('n', spanishClass);
  cppClass->setExit('s', start);

  spanishClass->setExit('s', cppClass);

  tWing->setExit('w', start);
  tWing->setExit('e', artRoom);
  
  artRoom->setExit('w', tWing);
  artRoom->setExit('s', gym);

  gym->setExit('n', artRoom);

  courtYard->setExit('e', start);
  courtYard->setExit('w', mainOffice);

  mainOffice->setExit('n', computerLab);
  mainOffice->setExit('s', dHall);
  mainOffice->setExit('e', courtYard);

  computerLab->setExit('s', mainOffice);

  dHall->setExit('n', mainOffice);
  dHall->setExit('s', cHall);

  cHall->setExit('n', dHall);
  cHall->setExit('s', englishClass);
  cHall->setExit('w', boringClassRoom);

  boringClassRoom->setExit('e', cHall);

  englishClass->setExit('n', cHall);
  englishClass->setExit('e', aHall);

  aHall->setExit('w', englishClass);
  aHall->setExit('e', aWing);

  aWing->setExit('n', library);
  aWing->setExit('w', aHall);

  library->setExit('n', oneHall);
  library->setExit('s', aWing);

  oneHall->setExit('n', start);
  oneHall->setExit('s', library);
  
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
