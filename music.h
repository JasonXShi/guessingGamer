#include "digitalMedia.h"

using namespace std;

class music : public digitalMedia {
 public:
  music(char* newTitle, int newYear, char* newArtist, char* newPublisher, float newDuration, int newType);
  char* getArtist();
  char* getPublisher();
  float getDuration();
 private:
  char* artist;
  char* publisher;
  float duration;
};
