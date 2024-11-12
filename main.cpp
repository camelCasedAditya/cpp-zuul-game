#include <iostream>
#include <vector>
#include <unordered_map>
#include "Room.h"
#include "Item.h"
using namespace std;

void printInventory(vector<Item*> inventory);
bool checkWin(vector<Item*> inventory);

int main() {
  char itemName[20] = "computer";

  Item* computer = new Item();
  computer->setName(strdup(itemName));

  Item* book = new Item();
  strcpy(itemName, "book");
  book->setName(strdup(itemName));

  Item* lunch = new Item();
  strcpy(itemName, "lunch");
  lunch->setName(strdup(itemName));

  Item* marker = new Item();
  strcpy(itemName, "marker");
  marker->setName(strdup(itemName));

  Item* basketball = new Item();
  strcpy(itemName, "basketball");
  basketball->setName(strdup(itemName));
  
  
  char temp[100] = "you are in the starting room";
  Room* start = new Room();
  start->setDescription(strdup(temp));
  
  Room* cppClass = new Room();
  strcpy(temp, "You are in Mr.Galbraith's c++ classroom");
  cppClass->setDescription(strdup(temp));

  Room* courtYard = new Room();
  strcpy(temp, "You are in the beautiful courtyard");
  courtYard->setDescription(strdup(temp));
  courtYard->addItem(lunch);

  
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
  englishClass->addItem(book);
  
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
  computerLab->addItem(computer);
  
  Room* tWing = new Room();
  strcpy(temp, "You are in the t-building");
  tWing->setDescription(strdup(temp));
  
  Room* artRoom = new Room();
  strcpy(temp, "You are in the art room");
  artRoom->setDescription(strdup(temp));
  artRoom->addItem(marker);
  
  Room* gym = new Room();
  strcpy(temp, "You are in the gym");
  gym->setDescription(strdup(temp));
  gym->addItem(basketball);
  
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
  char input[100];
  while(hasItems == false) {
    cout << "\n";
    currentRoom->getDescription();
    currentRoom->getExitDescriptions();
    cout << "\n";
    cout << "What do you want to do? Go to another room: \'MOVE\' or pick/drop items: \'ITEMS\' or quit: \'QUIT\'" << endl;
    cin >> input;
    if (strcmp(input, "MOVE") == 0) {
      cout << "Enter a direction \'n\' for north, \'s\' south, \'e\' for east, or \'w\' for west" << endl;
      cin >> input;
      currentRoom = currentRoom->getExit(input[0]);
    }
    else if (strcmp(input, "ITEMS") == 0) {
      cout << "Do you want to pick up an item or drop an item? Enter \'PICK\' or \'DROP\'" << endl;
      cin >> input;
      if (strcmp(input, "PICK") == 0) {
        cout << "Enter the name of the item you want to pick up" << endl;
        cin >> input;
	if (currentRoom->getItem(input) != NULL) {
	  inventory.push_back(currentRoom->getItem(input));
	  currentRoom->removeItem(input);
	}
	else {
	  cout << "There is no item with this name" << endl;
	}
      }
      if (strcmp(input, "DROP") == 0) {
	cout << "Enter the name of the item you want to drop" << endl;
	cin >> input;
	for (int i = 0; i < inventory.size(); i++) {
	  if (strcmp(inventory[i]->getName(), input) == 0) {
	    currentRoom->addItem(inventory[i]);
	    inventory.erase(inventory.begin() + i);
	  }
	}
      }
    }
    else if (strcmp(input, "QUIT")) {
      hasItems = true;
    }
    else {
      hasItems = checkWin(inventory);
    }
  }
  
  return 0;
}

void printInventory(vector<Item*> inventory) {
  cout << "These are the items in your inventory:" << endl;
  for (int i = 0; i<inventory.size(); i++){
    cout << inventory[i]->getName() << endl;
  }
}

bool checkWin(vector<Item*> inventory) {
  int itemCount = 0;
  for (int i = 0; i<inventory.size(); i++) {
    if ((strcmp(inventory[i]->getName(), "book") == 0) ||
	(strcmp(inventory[i]->getName(), "marker") == 0) ||
	(strcmp(inventory[i]->getName(), "basketball") == 0) ||
	(strcmp(inventory[i]->getName(), "computer") == 0)) {
      itemCount++;
    }
  }
  if (itemCount == 4) {
    return true;
  }
  else {
    return false;
  }
}
