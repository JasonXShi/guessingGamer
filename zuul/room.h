#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct item{
  const char* description[50];
  };

class room {
 public:
  room(const char* newDescription, const char* newName);
  const char* getDescription();
  void displayExits();
  void addItem(item i);
  void removeItem(item i);
  void addExit(const char* direction, room* room);
  const char* getName();
 private:
  const char* description;
  const char* name;
  map<const char*, room*> exits;
  vector<item*> items;
};

#endif
