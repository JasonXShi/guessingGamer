#include "room.h"
#include <iostream>

using namespace std;

room::room(const char* newDescription, const char* newName){
  description = newDescription;
  name = newName
}
room::addItem(item i){
  items.push_back(i);
}
room::removeItem(item i){
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
room::displayExits(){
  for(map<const char*, room*>::iterator it = exits.begin(); it!=exits.end(); ++it){
   
  }
}
room::addExit(char* direction, room room ){
  exits[direction] = room;
}
