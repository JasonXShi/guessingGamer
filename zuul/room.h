#ifndef ROOM_H
#define ROOM_H
#include <map>

struct item{
  char description[50];
};

class room {
 private:
  char* description;
  map<char*, room> exits;
  vector<item*> items;
};

#endif
