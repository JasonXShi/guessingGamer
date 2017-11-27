//MUSIC CLASS
#include "music.h"

using namespace std;
//constructor
music::music(char* newTitle, int newYear, char* newArtist, char* newPublisher, float newDuration, int newType) : digitalMedia(newTitle, newYear, newType){
  artist = newArtist;
  publisher = newPublisher;
  duration = newDuration;
}
//getters
char* music::getArtist(){
  return artist;
}
char* music::getPublisher(){
  return publisher;
}
float music::getDuration(){
  return duration;
}
//destructor
music::~music(){
  delete artist;
  delete publisher; 
}
