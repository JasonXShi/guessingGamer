/*
Kevin Men
Tictactoe
A 2 player tictactoe game where moves are made using a coordinate system
10/11/17
 */
#include <iostream>
#include <cstring>
using namespace std;

void printBoard(char board[3][3]);
bool checkWin(int boardState[3][3], int player);
bool checkTie(int boardState[3][3]);

  int main(){
    //constants
  char board[3][3];
  int boardState[3][3];
  int X_TURN = 0;
  int O_TURN = 1;
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int currentTurn = X_TURN;
  bool stillPlaying = true;
  char coordinates[2];
  int row;
  int column;
  char response[2];
  int xwins;
  int owins;
  cout << "Welcome to tictactoe" << endl;
  cout << "Use coordinates to chose your move" << endl;
  cout << "X goes first" << endl;
  cout << " A    B    C" << endl;
  cout << "1" << endl;
  cout << "2" << endl;
  cout << "3" << endl;
  //while the game is still going
  while(stillPlaying){
    //clears the board before each game
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	boardState[i][j] = BLANK;
	board[i][j] = ' ';
      }
    }
    //game loops- continues as long as there are no wins or ties
    while(checkWin(boardState, X_MOVE) == false && checkWin(boardState, O_MOVE) == false && checkTie(boardState) == false){
      cout << "Enter a move: " << endl;
      cin.get(coordinates, 3);
      cin.get();
      //checks for a valid coordinate
      if((coordinates[1] == '1' || coordinates[1] =='2' || coordinates[1] == '3') && (coordinates[0] == 'a' || coordinates[0] == 'b' || coordinates[0] == 'c')){
	

	//plots that coordinate on the board and prints it out
      column = coordinates[1] - 49;
      row = coordinates[0] - 'a';
      if(boardState[row][column] == BLANK){
      if(currentTurn == X_TURN){
	boardState[row][column] = X_MOVE;
	board[row][column] = 'X';
	currentTurn = O_TURN;
      }else{
	boardState[row][column] = O_MOVE;
	board[row][column] = 'O';
	currentTurn = X_TURN;
      }
      printBoard(board);
      }else{
	//if the space is occupited
	cout << "That space is already occupied" << endl;
      }
      }else{
	cout << "That is not a valid coordinate" << endl;
      }
    }
    //once someone wins(or is a tie game), asks to play again
    if(checkTie(boardState) == true && checkWin(boardState, X_MOVE) == false && checkWin(boardState, O_MOVE) == false){
      cout << "Tie game! Would you like to keep player?(y/n)" << endl;
    }else if(currentTurn == X_TURN){
      owins++;
      cout << "O has won " << owins << " times" << endl;
      cout << "X has won " << xwins << " times" << endl;
      cout << "O wins! Would you like to keep playing?(y/n)" << endl;
    }else {
      xwins++;
      cout << "O has won " << owins << " times" << endl;
      cout << "X has won " << xwins << " times" << endl;
      cout << "X wins! Would you like to keep playing?(y/n)" << endl;
    }
    cin.get(response, 2);
    cin.get();
    if(response[0] == 'y'){
      stillPlaying = true;
    }else{
      stillPlaying = false;
    }
    
  }
}
//algorithm taken from last year's ttt project
bool checkWin(int boardState[3][3], int player){
  //checks for a win
  if(boardState[0][0] == player && boardState[0][1] == player && boardState[0][2] == player){
    return true;
  }
  if(boardState[0][0] == player && boardState[1][1] == player && boardState[2][2] == player){
    return true;
  }
  if(boardState[1][0] == player && boardState[1][1] == player && boardState[1][2] == player){
    return true;
  }
  if(boardState[2][0] == player && boardState[2][1] == player && boardState[2][2] == player){
    return true;
  }
  if(boardState[0][0] == player && boardState[1][0] == player && boardState[2][0] == player){
    return true;
  }
  if(boardState[1][0] == player && boardState[1][1] == player && boardState[1][2] == player){
    return true;
  }
  if(boardState[0][2] == player && boardState[1][1] == player && boardState[2][0] == player){
    return true;
  }
  return false;
}
//algorithm taken from last year's ttt project
bool checkTie(int boardState[3][3]){
  //checks for a tie
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(boardState[i][j] == 0){
	return false;
      }
    }
  }
  return true;
}
//prints out board
void printBoard(char board[3][3]){
  cout << "  1    2    3" << endl;
  cout << "a " << board[0][0] << "    " << board[0][1] << "    " << board[0][2] << endl;
  cout << "b " << board[1][0] << "    " << board[1][1] << "    " << board[1][2] << endl;
  cout << "c " << board[2][0] << "    " << board[2][1] << "    " << board[2][2] << endl;
										 
								     									       
}
