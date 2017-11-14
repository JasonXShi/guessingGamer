#include "music.h"

using namespace std;

music::music(char* newTitle, int newYear, char* newArtist, char* newPublisher, float newDuration, int newType) : digitalMedia(newTitle, newYear, newType){
  artist = newArtist;
  publisher = newPublisher;
  duration = newDuration;
}
char* music::getArtist(){
  return artist;
}
char* music::getPublisher(){
  return publisher;
}
float music::getDuration(){
  return duration;
}
music::~music(){
  delete artist;
  delete publisher; 
}
