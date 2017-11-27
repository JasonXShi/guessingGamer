#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <vector>
#include <iostream>

struct item{
  char description[50];
};

class room {
 public:
  room(char* newDescription, char* newName);
  char* getDescription();
  void displayExits();
  void addItem(item i);
  void removeItem(item i);
  void displayExits();
  void addExit(char* direction, room room);
  char* getName();
 private:
  char* description;
  char* name;
  map<char*, room*> exits;
  vector<item*> items;
};

#endif
