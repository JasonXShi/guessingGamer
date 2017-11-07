
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include <iostream>
#include <cstring>
using namespace std;

class digitalMedia {
 public:
  digitalMedia(char* newTitle, int newYear, int newType);
  int getYear();
  char* getTitle();
  int getType();
 private:
  char* title;
  int year;
 protected:
  int type;
 
};
#endif /*DIGITALMEDIA_H*/
