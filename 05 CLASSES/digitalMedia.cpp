//DIGITAL MEDIA PARENT CLASS
#include "digitalMedia.h"

using namespace std;

//constuctor (not used)
digitalMedia::digitalMedia(char* newTitle, int newYear, int newType) {
  type = newType;
  title = newTitle;
  year = newYear;
}
//getters
char* digitalMedia::getTitle() {
  return title;
}
int digitalMedia::getYear() {
  return year;
}
int digitalMedia::getType(){
  return type;
}
//destructor
digitalMedia::~digitalMedia(){
  delete title;
}
