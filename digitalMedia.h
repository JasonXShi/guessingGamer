//DIGITAL MEDIA PARENT CLASS
//header guards
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

using namespace std;

class digitalMedia {
 public:
//constructors and destuctors
  digitalMedia(char* newTitle, int newYear, int newType);
  virtual ~digitalMedia();
//get functions
  int getYear();
  char* getTitle();
  int getType();
 private:
//private variables
  char* title;
  int year;
 protected:
//type to keep track of which type of media something is
  int type;
 
};
#endif /*DIGITALMEDIA_H*/
