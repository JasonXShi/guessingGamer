#include <iostream>
#include <cstring>
#include <vector>
#include "digitalMedia.h"
#include "videoGame.h"
#include "music.h"
#include "movie.h"
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
    cout << "Artist: " << ((music*) media)->getArtist() << endl;
    cout << "Duration(s): " << ((music*) media)->getDuration() << endl;
    cout << "Publisher: " << ((music*) media)->getPublisher() << endl;
  }else{
    //MOVIE
    cout << "Director: " << ((movie*) media)->getDirector() << endl;
    cout << "Duration(m): " << ((movie*) media)->getDuration() << endl;
    cout << "Rating: " << ((movie*) media)->getRating() << endl;
  }
  
}

//searches through vector by title
void searchMediaByTitle(int state, char* searchTitle, vector<digitalMedia*> &v){
  for(vector<digitalMedia*>::iterator it = v.begin(); it!=v.end(); ++it){
    if(strcmp((*it)->getTitle(), searchTitle)==0){
      if(state == 0){
	//deletes media
	delete(*it);
	v.erase(it);
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
	//deletes media
	delete(*it);
	v.erase(it);
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
  char sureDelete[2];
  char* mediaTitle;
  char* mediaPublisher;
  char* mediaArtist;
  char* mediaDirector;
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
	mediaTitle = new char[100];
	mediaPublisher = new char[50];
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
	mediaTitle = new char[100];
	mediaPublisher = new char[50];
	mediaArtist = new char[50];
	cout << "What is the name of the song?" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "Who is the artist of this song?" << endl;
	cin.getline(mediaArtist, 50, '\n');
	cout << "What year was the song published?" << endl;
	cin >> mediaYear;
	cin.get();
	cout << "How long is the song (in seconds)" << endl;
	cin >> mediaDuration;
	cin.get();
	cout << "Who is the publisher of this song?" << endl;
	cin.getline(mediaPublisher, 50, '\n');
	music* tempSong = new music(mediaTitle, mediaYear, mediaArtist, mediaPublisher, mediaDuration, 2);
	v.push_back(tempSong);
      }else if(strcmp(mediaType, "movie") == 0){
	//ADD A MOVIE
	mediaTitle = new char[100];
	mediaPublisher = new char[50];
	mediaDirector = new char[50];
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
	movie* tempMovie = new movie(mediaTitle, mediaYear, mediaDirector, mediaRating, mediaDuration, 3);
	v.push_back(tempMovie);
      }else {
	  cout << "NOT A VALID MEDIA TYPE" << endl;
      }
      //STATES: 0-DELETE 1-PRINT
    }else
      
        if(strcmp(command, "DELETE") == 0){
      //DELETE COMMAND
      cout << "Which method would you like to delete by? (title/year)" << endl;
      cin.getline(searchType, 10, '\n');
      if(strcmp(searchType, "title") == 0){
	//SEARCH BY TITLE AND DELETE
	cout << "What is the name of the media you wish to delete?" << endl;
	cin.getline(searchTitle, 100, '\n');
	cout << "Are you sure? Type y to delete." << endl;
        cin.getline(sureDelete, 2, '\n');
	if(strcmp(sureDelete, "y") == 0){
	    searchMediaByTitle(0, searchTitle, v);
	  }
    }else if(strcmp(searchType, "year") == 0){
	//SEARCH BY YEAR AND DELETE
	cout << "What is the year that the media you with to delete was published?" <<  endl;
	cin >> searchYear;
	cin.get();
	cout << "Are you sure? Type y to delete." << endl;
	cin.getline(sureDelete, 2, '\n');
	if(strcmp(sureDelete, "y") == 0){
	  searchMediaByYear(0, searchYear, v);
	}
      }else{
	cout << "INVALID PRINT TYPE" << endl;
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


