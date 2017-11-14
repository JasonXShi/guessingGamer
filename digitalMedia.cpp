#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

digitalMedia::digitalMedia(char* newTitle, int newYear, int newType) {
  type = newType;
  title = newTitle;
  year = newYear;
}
char* digitalMedia::getTitle() {
  return title;
}
int digitalMedia::getYear() {
  return year;
}
int digitalMedia::getType(){
  return type;
}
digitalMedia::~digitalMedia(){
  delete title;
}
