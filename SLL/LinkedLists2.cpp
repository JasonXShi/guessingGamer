/*
Kevin Men
C++
Linked Lists Part 2
Allows the user to create a list of students using linkedlists
1/19/18
 */
#include "Node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

//Adds node to the end of the list
void addNode(Student* student, Node* &head){
  Node* current = head;
  //if this is the first node
  if(current == NULL){
    head = new Node(student);
  }else{
    //finds the last node in the list and adds the node to the end
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node(student));
  }
}
//loops through the entire list and prints out the contents
void printList(Node* next){
  if(next != NULL){
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << ", " << next->getStudent()->getID() << ", " << next->getStudent()->getGPA() << endl;							        printList(next->getNext());
  }
}
//prints out the average by dividing the sum of all gpas by the number of students
void findAverage(Node* &current){
  float GPASum = 0;
  float studentCounter = 0;
  while(current != NULL){
    GPASum = GPASum + current->getStudent()->getID();
    studentCounter = studentCounter + 1;
  }
  cout << GPASum/studentCounter << endl;
}
void deleteNode(Node* &head, int ID){
  Node* current = head;
  //loops through the list and deletes the node
  //then adjusts the previous node
  while(current != NULL){
    if(current->getNext()->getStudent()->getID() == ID){
      //DELETE THE STUDENT FOUND
      //SET NEXT EQUAL TO THE NEXT OF THE NEXT
      return;
    }
  }
  cout << "Student is not in the list!" << endl;
}
int main(){
  bool quit = false;
  char command[10];
  Node* head = NULL;
  //introduction
  cout << "Welcome to Linked Lists p2" << endl;
  cout << "ADD- add a student to the list" << endl;
  cout << "PRINT- print out all the students in the list" << endl;
  cout << "DELETE- deletes a student out of the list" << endl;
  cout << "AVERAGE- prints out the average gpa of the students" << endl;
  cout << "QUIT- quits the program" << endl;
  while(!quit){
    char* firstName = new char(20);
    char* lastName = new char(20);
    int ID;
    float GPA;
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD")==0){
      //asks for the info of the student
      cout << "What is the student's first name?" << endl;
      cin.getline(firstName, 20, '\n');
      cout << "What is the student's last name?" << endl;
      cin.getline(lastName, 20, '\n');
      cout << "What is the student's ID number?" << endl;
      cin >> ID;
      cin.get();
      cout << "What is the student's GPA?" << endl;
      cin >> GPA;
      cin.get();
      //adds the student to the list
      Student* tempStudent = new Student(firstName, lastName, ID, GPA);
      addNode(tempStudent, head); 
    }else if(strcmp(command, "PRINT")==0){
      //prints out the contents of the list
      printList(head);
    }else if(strcmp(command, "DELETE")==0){
      //asks for the ID of the student to be deleted, then deletes the student
      cout << "What is the ID of the student you wish to delete" << endl;
      cin >> ID;
      cin.get();
      deleteNode(head, ID);
    }else if(strcmp(command, "AVERAGE")==0){
      //finds the average GPA
      findAverage(head);
    }else if(strcmp(command, "QUIT")==0){
      //quits the program
      quit = true;
    }else{
      cout << "INVALID COMMAND" << endl;
    }
  }//while loop
}//main method
