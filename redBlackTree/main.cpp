/*
Kevin Men
Red Black Tree- Allows the user to create a red black tree
C++ Programming
3/19
 */
#include "node.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
  int inputType;
  char* fileName;
  ifstream inFile;
  char* fileInput;
  char* input;
  cout << "Welcome to red black binary tree" << endl;
  cout << "Type 1 for manual input and 2 for file input" << endl;
  cin >> inputType;
  cin.get();
  if(inputType ==  2){
    //FILE INPUT
    cout << "Enter the name of the file" << endl;
    cin.getline(fileName, 20, '\n');
    inFile.open(fileName);
    if(!inFile){
      cout << "FILE DOES NOT EXIST" << endl;
      return 0;
    }
    inFile.getline(fileInput, 500, '\n');
    //ADD NUMBERS TO TREE
  }
  while(true){
    cout << "Type ADD to insert a node" << endl;
    cout << "Type PRINT to print the tree" << endl;
    cin.getline(input, 10, '\n');
    if(strcmp(input, "ADD") == 0){
      //ADD NODE
    }else if(strcmp(input, "PRINT") == 0){
      //PRINT TREE
    }else if(strcmp(input, "QUIT") == 0){
      //QUITS PROGRAMS
      return 0;
    }else{
      cout << "NOT A VALID RESPONSE" << endl;
    }
  }
}
