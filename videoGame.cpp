#include <iostream>
#include <cstring>
#include "videoGame.h"

using namespace std;

videoGame::videoGame(char* newTitle, int newYear, char* newPublisher, float newRating, int newType) : digitalMedia(newTitle, newYear, newType){
  publisher = newPublisher;
  rating = newRating;
}
char* videoGame::getPublisher(){
  return publisher;
}
float videoGame::getRating(){
  return rating;
}
