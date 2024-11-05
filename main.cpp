#include <iostream>
#include <vector>
#include <unordered_map>
#include "Room.h"
#include "Item.h"
using namespace std;

int main() {
  char temp[100] = "you are in the starting room";
  Room* start = new Room();
  start->setDescription(strdup(temp));

  Item* item = new Item();
  char itemName[20] = "#1";
  item->setName(strdup(itemName));
  start->addItem(item);

  Item* item2 = new Item();
  char itemName2[20] = "#2";
  item2->setName(strdup(itemName2));
  start->addItem(item2);

  char removeName[20] = "#1";
  start->getDescription();
  start->removeItem(removeName);
  cout << "-------" << endl;
  start->getDescription();

  
  Room* cppClass = new Room();
  strcpy(temp, "You are in Mr.Galbraith's c++ classroom");
  cppClass->setDescription(strdup(temp));

  Room* courtYard = new Room();
  strcpy(temp, "You are in the beautiful courtyard");
  courtYard->setDescription(strdup(temp));
  
  Room* oneHall = new Room();
  strcpy(temp, "You are in one hall");
  oneHall->setDescription(strdup(temp));
  
  Room* library =  new Room();
  strcpy(temp, "You are in the library. Shhh");
  library->setDescription(strdup(temp));
  
  Room* aWing = new Room();
  strcpy(temp, "You are in a-wing");
  aWing->setDescription(strdup(temp));
  
  Room* aHall = new Room();
  strcpy(temp, "You are in the a-hallway");
  aHall->setDescription(strdup(temp));
  
  Room* englishClass = new Room();
  strcpy(temp, "You are in the english classroom");
  englishClass->setDescription(strdup(temp));
  
  Room* cHall = new Room();
  strcpy(temp, "You are in the c-hallway");
  cHall->setDescription(strdup(temp));
  
  Room* boringClassRoom = new Room();
  strcpy(temp, "You are in a very boring classroom");
  boringClassRoom->setDescription(strdup(temp));
  
  Room* dHall = new Room();
  strcpy(temp, "You are in d hallway");
  dHall->setDescription(strdup(temp));
  
  Room* mainOffice = new Room();
  strcpy(temp, "You are in the school main office");
  mainOffice->setDescription(strdup(temp));
  
  Room* computerLab = new Room();
  strcpy(temp, "You are in the computer lab");
  computerLab->setDescription(strdup(temp));
  
  Room* tWing = new Room();
  strcpy(temp, "You are in the t-building");
  tWing->setDescription(strdup(temp));
  
  Room* artRoom = new Room();
  strcpy(temp, "You are in the art room");
  artRoom->setDescription(strdup(temp));
  
  Room* gym = new Room();
  strcpy(temp, "You are in the gym");
  gym->setDescription(strdup(temp));
  
  Room* spanishClass = new Room();
  strcpy(temp, "You are in the spanish classroom");
  spanishClass->setDescription(strdup(temp));


  start->setExit('n', cppClass);
  start->setExit('s', oneHall);
  start->setExit('w', courtYard);
  start->setExit('e', tWing);

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
  currentRoom = start;
  char input = 'a';
  //char* point = input;
  start->getDescription();
  while(hasItems == false) {
    cout << "Enter a direction \'n\' for north, \'s\' south, \'e\' for east, or \'w\' for west" << endl;
    cin >> input;
    if (input == 'q') {
      hasItems == true;
    }
    currentRoom = currentRoom->getExit(input);
    currentRoom->getDescription();
  }
  
  //unordered_map<char, int> umap;
  //umap['u'] = 10;
  //umap['l'] = 20;
  //cout << umap.at('l') << endl;
  //cout << umap.at('u') << endl;

  //char input[100] = "Exit room description";
  //Room* room = new Room();
  //Room* room2 = new Room();
  //room2->setDescription(input);
  //room->setExit('u', room2);
  //Room* exitRoom = room->getExit('u');
  //exitRoom->getDescription();
  return 0;
}
