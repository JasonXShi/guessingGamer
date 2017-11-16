//VIDEOGAME CLASS HEADER FILE
#include "digitalMedia.h"

using namespace std;

class videoGame : public digitalMedia {
 public:
  //constructor and destructor
  videoGame(char* newTitle, int newYear, char* newPublisher, float newRating, int newType);
  virtual ~videoGame();
  //get functions
  float getRating();
  char* getPublisher();
 private:
  //private variables
  char* publisher;
  float rating;
  
  
};
