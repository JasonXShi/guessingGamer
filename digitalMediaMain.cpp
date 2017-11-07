#include <iostream>
#include <cstring>
#include <vector>
#include "digitalMedia.h"
#include "videoGame.h"
using namespace std;

//prints out a media 
void printMedia(digitalMedia* media){
  int type = media->getType();
  cout << endl;
  cout << "Title: " << media->getTitle() << endl;
  cout << "Year: " << media->getYear() << endl;
  if(type == 1){
    //VIDEO GAME
    cout << "Publisher: " << ((videoGame*) media)->getPublisher() << endl;
    cout << "Rating: " << ((videoGame*) media)->getRating() << endl;
  }else if (type == 2){
    //MUSIC
    //cout << "Artist: " << media->getArtist() << endl;
    //cout << "Duration(s): " << media->getDuration() << endl;
    //cout << "Publisher: " << media->getPublisher() << endl;
  }else{
    //MOVIE
  }
  
}
//deletes a media
void deleteMedia(){

}
//searches through vector by title
void searchMediaByTitle(int state, char* searchTitle, vector<digitalMedia*> v){
  for(vector<digitalMedia*>::iterator it = v.begin(); it!=v.end(); ++it){
    if(strcmp((*it)->getTitle(), searchTitle)==0){
      if(state == 0){
	//deleteMedia(*it);
      }else{
	printMedia(*it);
      }
    }
  }
}
//searches through vector by year
void searchMediaByYear(int state, int searchYear, vector<digitalMedia*> v){
  for(vector<digitalMedia*>::iterator it = v.begin(); it!=v.end(); ++it){
    if( (*it)->getYear() == searchYear){
      if(state == 0){
	//deleteMedia(*it);
	break;
      }else{
	printMedia(*it);
      }
    }
  }
}

int main(){
  vector<digitalMedia*> v;
  bool quit = false;
  //media information
  int mediaYear;
  int mediaDuration;
  float mediaRating;
  char command[10];
  char mediaType[10];
  char searchType[10];
  float searchYear;
  char searchTitle[100];
  //introduction
  cout << "Welcome to digital media" << endl;
  cout << "ADD- Add a digital media for the database" << endl;
  cout << "SEARCH- Search for a digital media based off its title or year" << endl;
  cout << "DELETE- Delete an item" << endl;
  cout << "QUIT- Quits the program" << endl;
  while(!quit){
    //TYPES: 1-VIDEOGAME 2-MUSIC 3-MOVIE
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD") == 0){
      //ADD COMMAND
      cout << "What type of media would you like to add? (videogame, music, movie)" << endl;
      cin.getline(mediaType, 10, '\n');
      if(strcmp(mediaType, "videogame") == 0){
	//ADD A VIDEOGAME
	char* mediaTitle = new char[100];
	char* mediaPublisher = new char[50];
	cout << "What is the name of the videogame" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "What year was the videogame published" << endl;
	cin >> mediaYear;
	cin.get();
	cout << "Who is the publisher of this game?" << endl;
	cin.getline(mediaPublisher, 50, '\n');
	cout << "What is the rating of the game?" << endl;
	cin >> mediaRating;
	cin.get();
	videoGame* tempGame = new videoGame(mediaTitle, mediaYear, mediaPublisher, mediaRating, 1);
	v.push_back(tempGame);
	cout << "Done" << endl;
      }else if(strcmp(mediaType, "music") == 0){
	//ADD A SONG
	char* mediaTitle = new char[100];
	char* mediaPublisher = new char[50];
	cout << "What is the name of the song?" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "What year was the song published?" << endl;
	cin >> mediaYear;
	cin.get();
	cout << "How long is the song (in seconds)" << endl;
	cin >> mediaDuration;
	cin.get();
	cout << "Who is the publisher of this song?" << endl;
	cin.getline(mediaPublisher, 50, '\n');
	
      }else if(strcmp(mediaType, "movie") == 0){
	//ADD A MOVIE
	char* mediaTitle = new char[100];
	char* mediaPublisher = new char[50];
	char mediaDirector[50];
	cout << "What is the name of the movie?" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "What is year was the movie published?" << endl;
	cin >> mediaYear;
	cin.get();
	cout << "Who is the director of the movie?" << endl;
	cin.getline(mediaDirector, 50, '\n');
	cout << "How long is the movie? (in minutes)" << endl;
	cin >> mediaDuration;
	cin.get();
	cout << "What is the rating of this movie?" << endl;
	cin >> mediaRating;
	cin.get();
      }else {
	  cout << "NOT A VALID MEDIA TYPE" << endl;
      }
      //STATES: 0-DELETE 1-PRINT
    }else if(strcmp(command, "DELETE") == 0){
      //DELETE COMMAND
      cout << "Which method would you like to delete by? (title/year)" << endl;
      cin.getline(searchType, 10, '\n');
      if(strcmp(searchType, "title") == 0){
	//SEARCH BY TITLE AND DELETE
	//searchMediaByTitle(0);
      }else{
	//SEARCH BY YEAR AND DELETE
	//searchMediaByYear(0);
      }
    }else if(strcmp(command, "SEARCH") == 0){
      //SEARCH COMMAND
      cout << "Which method would you like to search by? (title/year)" << endl;
      cin.getline(searchType, 10, '\n');
      if(strcmp(searchType, "title") == 0){
	//SEARCH BY TITLE AND PRINT
	cout << "What is the title of the media?" << endl;
	cin.getline(searchTitle, 100, '\n');
	searchMediaByTitle(1, searchTitle, v);
      }else if (strcmp(searchType, "year") == 0){
	//SEARCH BY YEAR AND PRINT
	cout << "What year was the media published?" << endl;
	cin >> searchYear;
	cin.get();
	searchMediaByYear(1, searchYear, v);
      }else{
	cout << "INVALID SEARCH TYPE" << endl;
      }
    }else if(strcmp(command, "QUIT") == 0){
      //QUITS PROGRAM
      quit = true;
    }else{
      cout << "NOT A VALID COMMAND" << endl;
    }
    
  }//end of while loop
  return 0;
}//end of main method


