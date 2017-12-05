//ROOM CLASS HEADER FILE
#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <vector>
#include <iostream>

using namespace std;

//struct for items
struct item{
  const char* description;
  item(const char* newDescription){
    description = newDescription;
  }
  };

class room {
 public:
  //constructors
  room(const char* newDescription, const char* newName);
  //functions for GET, GO, and DROP, as well as getters
  const char* getDescription();
  void displayExits();
  void displayItems();
  void addItem(item* i);
  void dropItem(char* description, vector<item*> &inventory);
  void travel(char description[10], room* &current);
  void removeItem(char description[50], vector<item*> &inventory);
  void addExit(const char* direction, room* room);
  const char* getName();
 private:
  //member variables
  const char* description;
  const char* name;
  map<const char*, room*> exits;
  vector<item*> items;
};

#endif
