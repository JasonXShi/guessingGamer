
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include <iostream>
#include <cstring>
using namespace std;

class digitalMedia {
 public:
  digitalMedia(char* newTitle, int newYear);
  int getYear();
  char* getTitle();
 private:
  char* title;
  int year;
 
};
#endif /*DIGITALMEDIA_H*/
