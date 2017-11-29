#include "room.h"
#include <iostream>

using namespace std;

void room::room(const char* newDescription, const char* newName){
  description = newDescription;
  name = newName
}
void room::addItem(item i){
  items.push_back(i);
}
void room::removeItem(item i){
  for(vector<item*>::iterator it = items.begin(); it!=items.end(); ++it){
    if(strcmp((*it)->description, i.description) == 0){
      items.erase(it);
      break;
    }
  }
}
const char* room::getName(){
  return name;
}
const char* room::getDescription(){
  return description;
}
void room::displayExits(){
  for(map<const char*, room*>::iterator it = exits.begin(); it!=exits.end(); ++it){
   
  }
}
void room::addExit(const char* direction, room* room ){
  exits[direction] = room;
}
