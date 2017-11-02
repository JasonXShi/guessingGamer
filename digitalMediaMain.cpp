#include <iostream>
#include <cstring>
#include <vector>
#include "digitalMedia.h"

using namespace std;

//adds a videogame
void addVideoGame(){

}
//adds music
void addMusic(){

}
//adds a movie
void addMovie(){

}
//prints out a media 
void printMedia(){

}
//delets a media
void deleteMedia(){

}
//searches through vector by title
void searchMediaByTitle(int state){

}
//searches through vector by year
void searchMediaByYear(int state){

}

int main(){
  vector<digitalMedia*> v;
  bool quit = false;
  //media information
  char mediaTitle[100];
  int mediaYear;
  char mediaPublisher[50];
  int mediaDuration;
  float mediaRating;
  char mediaDirector[50];
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
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD") == 0){
      //ADD COMMAND
      cout << "What type of media would you like to add? (videogame, music, movie)" << endl;
      cin.getline(mediaType, 10, '\n');
      if(strcmp(mediaType, "videogame") == 0){
	//ADD A VIDEOGAME
	cout << "What is the name of the videogame" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "What year was the videogame published" << endl;
	cin >> mediaYear;
	cout << "Who is the publisher of this game?" << endl;
	cin.getline(mediaPublisher, 50, '\n');
	cout << "What is the rating of the game?" << endl;
	cin >> mediaRating;
	addVideoGame();
      }else if(strcmp(mediaType, "music") == 0){
	//ADD A SONG
	cout << "What is the name of the song?" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "What year was the song published?" << endl;
	cin >> mediaYear;
	cout << "How long is the song (in seconds)" << endl;
	cin >> mediaDuration;
	cout << "Who is the publisher of this song?" << endl;
	cin.getline(mediaPublisher, 50, '\n');
	addMusic();
      }else{
	//ADD A MOVIE
	cout << "What is the name of the movie?" << endl;
	cin.getline(mediaTitle, 100, '\n');
	cout << "What is year was the movie published?" << endl;
	cin >> mediaYear;
	cout << "Who is the director of the movie?" << endl;
	cin.getline(mediaDirector, 50, '\n');
	cout << "How long is the movie? (in minutes)" << endl;
	cin >> mediaDuration;
	cout << "What is the rating of this movie?" << endl;
	cin >> mediaRating;
	addMovie();
      }
      //STATES: 0-DELETE 1-PRINT
    }else if(strcmp(command, "DELETE") == 0){
      //DELETE COMMAND
      cout << "Which method would you like to delete by? (title/year)" << endl;
      cin.getline(searchType, 10, '\n');
      if(strcmp(searchType, "title") == 0){
	//SEARCH BY TITLE AND DELETE
	searchMediaByTitle(0);
      }else{
	//SEARCH BY YEAR AND DELETE
	searchMediaByYear(0);
      }
    }else if(strcmp(command, "SEARCH") == 0){
      //SEARCH COMMAND
      cout << "Which method would you like to search by? (title/year" << endl;
      cin.getline(searchType, 10, '\n');
      if(strcmp(searchType, "title") == 0){
	//SEARCH BY TITLE AND PRINT
	searchMediaByTitle(1);
      }else{
	//SEARCH BY YEAR AND PRINT
	searchMediaByYear(1);
      }
    }else if(strcmp(command, "QUIT") == 0){
      //QUITS PROGRAM
      quit = true;
    }else{
      cout << "NOT A VALID COMMAND" << endl;
    }
    
  }//end of while loop
  
}//end of main method


