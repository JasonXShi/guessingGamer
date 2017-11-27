#include "room.h"

room::room(char* newDescription){
  description = newDescription;
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
char* room::getDescription(){
  return description;
}
room::displayExits(){
  
}
