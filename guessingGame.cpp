//Kevin Men
//9/11/17
//Guessing game
//This program generates a random number 0-100 and the user tries to guess it
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
  //variables to keep track of players guess, the number, and whether they want to continue playing
  srand(time(NULL));
  bool stillPlaying = true;
  int randomNumber;
  int input;
  char playState;
  int guessCount = 0;
  //while loop to check if the player is still playing
  while(stillPlaying == true){
    guessCount = 0;
    //generates a random number between 0-100
    randomNumber = rand()%101;
    while(input != randomNumber){
      // prompts the user to input a number and stores it in a variable
    cout << "Guess a number" << endl;
    cin >> input;
    if(input > randomNumber){
      //if their guess is too high
      cout << "Too high" << endl;
      guessCount++;
    } else if(input < randomNumber){
      //if their guess is too low
      cout << "Too low" << endl;
      guessCount++;
    } else {
      //if their guess is correct
      cout << "You got it in " <<  guessCount << " tries" << endl;
      cout << "Continue playing (y/n)" << endl;
      cin >> playState;
      //asks if they want to continue playing
      if(playState == 'y'){

      }else {
	stillPlaying = false;
      }
    }
    }

      }
  

}
