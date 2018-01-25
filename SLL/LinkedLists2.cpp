/*
Kevin Men
C++
Linked Lists Part 2
Allows the user to create a list of students using linkedlists
1/25/18
 */
#include "node.h"
#include "student.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

//Adds nodes in the correct order
void addNode(student* tempStudent, node* &current){
  if(current != NULL){
    node* nextNode = current->getnext();
    if(current->getnext() != NULL){
      //if the student's id is in between two others
      if(current->getvalue()->getID() < tempStudent->getID() && current->getnext()->getvalue()->getID() > tempStudent->getID()){
	node* tempNode = current->getnext();
	//adds the node between the two nodes
	current->setnext(new node());
	current->getnext()->setvalue(tempStudent);
	nextNode = current->getnext();
	nextNode->setnext(tempNode);
	return;
      }
    }else{
      //if this is the last node, add it to the end
      current->setnext(new node());
      current->getnext()->setvalue(tempStudent);
      return;
    }
    //if this is the first node, set head equal to it
  }else{
    current = new node();
    current->setvalue(tempStudent);
   return;
 }
  //recursively calls add node
  node* nextNode = current->getnext();
  addNode(tempStudent, nextNode);
}

//loops through the entire list and prints out the contents
void printList(node* next){
  if(next != NULL){
    cout << next->getvalue()->getFirstName() << " " << next->getvalue()->getLastName() << ", " << next->getvalue()->getID() << ", " << next->getvalue()->getGPA() << endl;
    //uses recursion to print the list
    printList(next->getnext());
  }
}
//prints out the average by dividing the sum of all gpas by the number of students
void findAverage(node* current){
  float GPASum = 0;
  float studentCounter = 0;
  while(current != NULL){
    //adds all the GPA'S together, while keeping track of the number of students
    GPASum = GPASum + current->getvalue()->getGPA();
    studentCounter = studentCounter + 1;
    current = current->getnext();
  }
  cout << "Average GPA of all students: " << GPASum/studentCounter << endl;
}
void deleteNode(node* &head, int ID){
  node* current = head;
  node* previous = NULL;
  //loops through the list and deletes the node
  //then adjusts the previous node
  while(current != NULL){
    if(current->getvalue()->getID() == ID){
      //DELETE THE STUDENT FOUND
      //if this isn't the first node, then set the previous node's next equal to the node after the deleted student
      if(previous != NULL){
	previous->setnext(current->getnext());
	//if this is the first node
      }else{
	//if there is a node after this node, set it equal to the next
	if(head->getnext() != NULL){
	  head = head->getnext();
	}else{
	  //if this is the only node, set it equal to null
	  head = NULL;
	}
      }
      //delete the student
      delete(current);
      //SET NEXT EQUAL TO THE NEXT OF THE NEXT
      return;
    }else{
      //set previous equal to the current and increment current
      previous = current;
      current = current->getnext();
    }
  }
  //if the student was not found
  cout << "Student is not in the list!" << endl;
}
int main(){
  bool quit = false;
  char command[10];
  node* head = NULL;
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
      student* tempStudent = new student(firstName, lastName, ID, GPA);
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
      //INVALID COMMAND
      cout << "INVALID COMMAND" << endl;
    }
  }//while loop
}//main method
