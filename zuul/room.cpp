//ROOM CLASS CPP FILE
#include "room.h"
#include <iostream>
#include <cstring>

using namespace std;
//constructor
room::room(const char* newDescription, const char* newName){
  description = newDescription;
  name = newName;
}
//adds an item to the room
void room::addItem(item* i){
  items.push_back(i);
}
//moves an item from your inventory to the room
void room::dropItem(char* description, vector<item*> &inventory){
  //loops through inventory, once it finds the item, adds it to the room and erases from inventory
  for(vector<item*>::iterator it = inventory.begin(); it!=inventory.end(); ++it){
    if(strcmp((*it)->description, description) == 0){
      addItem(*it);
      inventory.erase(it);
      return;
    }
  }
  cout << "You do not have that item!" << endl;
}
//moves an item from the room into your inventory
void room::removeItem(char description[50], vector<item*> &inventory){
  //loops through room vector, finds item, removes from room and ands into inventory
  bool foundItem = false;
  for(vector<item*>::iterator it = items.begin(); it!=items.end(); ++it){
    if(strcmp((*it)->description, description) == 0){
      inventory.push_back(*it);
      items.erase(it);
      foundItem = true;
      break;
    }
  }
  //if the item isn't in the room
  if(!foundItem){
    cout << "That item is not here!" << endl;
  }
}
//getters
const char* room::getName(){
  return name;
}
const char* room::getDescription(){
  return description;
}
//displays all exits
void room::displayExits(){
  //loops through map and displays all directions and rooms
  for(map<const char*, room*>::iterator it = exits.begin(); it!=exits.end(); ++it){
    cout << it->first << " " << (it->second)->getName() << endl;
  }
}
//displays all items
void room::displayItems(){
  //loops through items vector and displays all item names inside the room
  cout << "Items in this room: " << endl;
  for(vector<item*>::iterator it = items.begin(); it!=items.end(); ++it){
    cout << (*it)->description << endl;
  }
}
//travels to another room
void room::travel(char direction[10], room* &current){
  //finds the destination, and sets current equal to it
  for(map<const char*, room*>::iterator it = exits.begin(); it!=exits.end(); ++it){
    if(strcmp(it->first, direction) == 0){
      current = (it->second);
      return;
    }
    }
  cout << "INVALID DIRECTION" << endl;
}
//adds an exit to the room
void room::addExit(const char* direction, room* room ){
  exits[direction] = room;
}
