/*
  Aditya Chandrashekaran
  11/14/2024
  Allows the user to play the zuul adventure game.
  The game allows the user to move from room to room
  The player can pick up and drop items
  The player wins if they collect all the required items
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Room.h"
#include "Item.h"
using namespace std;

void printInventory(vector<Item*> inventory);
bool checkWin(vector<Item*> inventory);

int main() {
  // Creating all item objects and setting their names
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
  

  // Creating all room objects and setting the description
  char temp[100] = "you are in the starting room";
  Room* start = new Room();
  start->setDescription(strdup(temp));
  
  Room* cppClass = new Room();
  strcpy(temp, "You are in Mr.Galbraith's c++ classroom");
  cppClass->setDescription(strdup(temp));

  Room* courtYard = new Room();
  strcpy(temp, "You are in the beautiful courtyard");
  courtYard->setDescription(strdup(temp));
  // Add lunch item to courtyard
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
  // Add book item to english class room
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
  // Add computer item to computer lab
  computerLab->addItem(computer);
  
  Room* tWing = new Room();
  strcpy(temp, "You are in the t-building");
  tWing->setDescription(strdup(temp));
  
  Room* artRoom = new Room();
  strcpy(temp, "You are in the art room");
  artRoom->setDescription(strdup(temp));
  // Add marker item to art room
  artRoom->addItem(marker);
  
  Room* gym = new Room();
  strcpy(temp, "You are in the gym");
  gym->setDescription(strdup(temp));
  // Add basketball item to gym room
  gym->addItem(basketball);
  
  Room* spanishClass = new Room();
  strcpy(temp, "You are in the spanish classroom");
  spanishClass->setDescription(strdup(temp));

  // Set the exits for each room with the room that exit leads into
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

  // Initialize variables to run the game like player inventory, win check, and the current room the player is in.
  bool hasItems = false;
  vector<Item*> inventory;
  Room* currentRoom;
  currentRoom = start;
  char input[100];
  while(hasItems == false) {
    // Print out info for the players like the room description, possible exits, and the items in the room and the players inventory
    cout << "\n";
    currentRoom->getDescription();
    currentRoom->getExitDescriptions();
    cout << "\n";
    printInventory(inventory);
    cout << "\n";
    
    // Gets the players command
    cout << "What do you want to do? Go to another room: \'MOVE\' or pick/drop items: \'ITEMS\' or quit: \'QUIT\'" << endl;
    cin >> input;

    // If the player wants to move to a different room we get the exit they want to use
    if (strcmp(input, "MOVE") == 0) {
      cout << "Enter a direction \'n\' for north, \'s\' south, \'e\' for east, or \'w\' for west" << endl;
      cin >> input;
      // If the exit is valid the player is moved to the new room
      if (currentRoom->getExit(input[0]) != NULL) {
	currentRoom = currentRoom->getExit(input[0]);
      }
      else {
	cout << "This room does not have that exit" << endl;
      }
    }
    // If the user wants to pick or drop an item
    else if (strcmp(input, "ITEMS") == 0) {

      // Gets user input on if they want to pick or drop an item
      cout << "Do you want to pick up an item or drop an item? Enter \'PICK\' or \'DROP\'" << endl;
      cin >> input;
      // If the user wants to pick an item the user can input the item name and if that item exists, it is added to the players inventory
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
      // If the user wants to drop an item the user can input the item name and if that item exists in their inventory, it is added to the room
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
    // Quits the game if the user wants to stop playing
    else if (strcmp(input, "QUIT") == 0) {
      hasItems = true;
    }
    // Checks if the user has won the game
    if (checkWin(inventory) == true) {
      hasItems = true;
      cout << "You have won by finding all the needed items" << endl;
    }
    cout << "\n\n\n" << endl;
  }
  return 0;
}


// Function to print out all items in the players inventory vector
void printInventory(vector<Item*> inventory) {
  cout << "These are the items in your inventory:" << endl;
  for (int i = 0; i<inventory.size(); i++){
    cout << inventory[i]->getName() << endl;
  }
}

// Counts the number of required items the play has.
// If the player has all the required items the function returns true indicating that the player has won the game.
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
