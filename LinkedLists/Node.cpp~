#include "Node.h"
#include <cstddef>

Node::Node(Student* newStudent){
  student = newStudent;
}
Node::~Node(){
  next = NULL;
  delete student;
}
Student* Node::getStudent(){
  return student;
}
void Node::setNext(Node* nextNode){
  next = nextNode;
}
Node* Node::getNext(){
  return next;
}
