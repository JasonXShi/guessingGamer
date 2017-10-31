#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

digitalMedia::digitalMedia(char* newTitle, int newYear) {
  title = newTitle;
  year = newYear;
}
char* digitalMedia::getTitle() {
  return title;
}
int digitalMedia::getYear() {
  return year;
}
