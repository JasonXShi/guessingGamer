#include "digitalMedia.h"

using namespace std;

class movie : public digitalMedia {
 public:
  movie(char* newTitle, int newYear, char* newDirector, float newRating, float newDuration, int newType);
  virtual ~movie();
  char* getDirector();
  float getDuration();
  float getRating();
 private:
  char* director;
  float duration;
  float rating;
};
