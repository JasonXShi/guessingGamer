#include "Node.h"
#include <cstddef>
//constructor
Node::Node(Student* newStudent){
  student = newStudent;
}
//destructor
Node::~Node(){
  next = NULL;
  delete student;
}
//getters and setters
Student* Node::getStudent(){
  return student;
}
void Node::setNext(Node* nextNode){
  next = nextNode;
}
Node* Node::getNext(){
  return next;
}
