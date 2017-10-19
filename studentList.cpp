#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {

  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
  
  
};

int main(){
  char command[10];
  bool quit = false;
  vector<student*> v = new vector<student*>();
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD") == 0){
      cout << "add" << endl;
    }else if(strcmp(command, "DELETE") == 0){
      cout << "delete" << endl;
    }else if(strcmp(command, "PRINT") == 0){
      cout << "print" << endl;
    }else if(strcmp(command, "QUIT") == 0){
      cout << "quit" << endl;
    }else {
      cout << "not a valid comman" << endl;
    }
  
  
}
public void printStudents(){

}
public void deleteStrudent(){

}
public void addStudent(){

}
