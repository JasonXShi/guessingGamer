//MOVIE CLASS
#include "movie.h"

using namespace std;
//constructor
movie::movie(char* newTitle, int newYear, char* newDirector, float newRating, float newDuration, int newType) : digitalMedia(newTitle, newYear, newType){
  director = newDirector;
  duration = newDuration;
  rating = newRating;
}
//getters
char* movie::getDirector(){
  return director;
}
float movie::getDuration(){
  return duration;
}
float movie::getRating(){
  return rating;
}
//destructor
movie::~movie(){
  delete director;
}
