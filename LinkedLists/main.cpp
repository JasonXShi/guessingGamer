#include "Student.h"
#include "Node.h"
#include <iostream>

using namespace std;

void addNode(Student* student, Node* &head){
  Node* current = head;
  //if this is the first node being added
  if(current == NULL){
    head = new Node(student);
  }else{
    //goes to the end of the list, and adds the node
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node(student));
  }
}
void printList(Node* head){
  Node* current = head;
  //while we haven't reached the end of the list, print out the student
  while(current != NULL){
    cout << "Printing" << endl;
    cout << "Name: " << current->getStudent()->getName() << endl;
    cout << "ID: " << current->getStudent()->getID() << endl;
    cout << endl;
    current = current->getNext();
  }
}
int main(){
  cout << "Linked Lists" << endl;
  Node* head = NULL;
  //creates students and print them out
  addNode(new Student("Jason Shi", 322023), head);
  addNode(new Student("Russell Chai", 100000), head);
  addNode(new Student("Connor Shu", 111111), head);
  addNode(new Student("Kevin Men", 321491), head);
  printList(head);
}
