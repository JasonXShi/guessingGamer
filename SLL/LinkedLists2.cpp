#include "Node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

void addNode(Student* student, Node* &head){

}
void printList(Node* head){

}
int main(){
  bool quit = false;
  char[10] command;
   
  cout << "Welcome to Linked Lists p2" << endl;
  cout << "ADD- add a student to the list" << endl;
  cout << "PRINT- print out all the students in the list" << endl;
  cout << "DELETE- deletes a student out of the list" << endl;
  cout << "AVERAGE- prints out the average gpa of the students" << endl;
  cout << "QUIT- quits the program" << endl;
  while(!quit){
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD")==0){

    }else if(strcmp(command, "PRINT")==0){
      
    }else if(strcmp(command, "DELETE")==0){

    }else if(strcmp(command, "AVERAGE")==0){

    }else if(strcmp(command, "QUIT")==0){

    }else{
      cout << "INVALID COMMAND" << endl;
    }
  }//while loop
}//main method
