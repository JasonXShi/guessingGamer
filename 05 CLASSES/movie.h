//MOVIE CLASS HEADER FILE
#include "digitalMedia.h"

using namespace std;

class movie : public digitalMedia {
 public:
  //constructor and destructor
  movie(char* newTitle, int newYear, char* newDirector, float newRating, float newDuration, int newType);
  virtual ~movie();
  //get functions
  char* getDirector();
  float getDuration();
  float getRating();
 private:
  //private variables
  char* director;
  float duration;
  float rating;
};
