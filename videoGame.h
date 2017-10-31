#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

class videoGame : public digitalMedia {
 public:
  videoGame(char* newTitle, int newYear, char* newPublisher, float newRating);
  float getRating();
  char* getPublisher();
 private:
  char* publisher;
  float rating;
  
  
};
