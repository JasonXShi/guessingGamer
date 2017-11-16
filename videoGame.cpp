//VIDEOGAME CLASS
#include "videoGame.h"

using namespace std;

//constructor
videoGame::videoGame(char* newTitle, int newYear, char* newPublisher, float newRating, int newType) : digitalMedia(newTitle, newYear, newType){
  publisher = newPublisher;
  rating = newRating;
}
//getters
char* videoGame::getPublisher(){
  return publisher;
}
float videoGame::getRating(){
  return rating;
}
//destructor
videoGame::~videoGame(){
  delete publisher;
}
