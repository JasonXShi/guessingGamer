#include "room.h"
#include <iostream>

room::room(char* newDescription, char* newName){
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
char* room::getName(){
  return name;
}
char* room::getDescription(){
  return description;
}
room::displayExits(){
  for(map<char*, room*>::iterator it = exits.begin(); it!=exits.end(); ++it){
   
  }
}
room::addExit(char* direction, room room ){
  exits[direction] = room;
}
