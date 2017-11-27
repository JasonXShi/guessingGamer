//MUSIC CLASS HEADER FILE
#include "digitalMedia.h"

using namespace std;

class music : public digitalMedia {
 public:
  //constructor and destructor
  music(char* newTitle, int newYear, char* newArtist, char* newPublisher, float newDuration, int newType);
  virtual ~music();
  //get functions
  char* getArtist();
  char* getPublisher();
  float getDuration();
 private:
  //private variables
  char* artist;
  char* publisher;
  float duration;
};
