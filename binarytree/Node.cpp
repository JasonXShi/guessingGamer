#include "Node.h"
#include <cstddef>

Node::Node(){
  leftChild = NULL;
  rightChild = NULL;
  parent = NULL;
}
Node::~Node(){
  leftChild = NULL;
  rightChild = NULL;
  parent = NULL;
}
Node* Node::getRight(){
  return rightChild;
}
Node* Node::getLeft(){
  return leftChild;
}
Node* Node::getParent(){
  return parent;
}
int Node::getValue(){
  return value;
}
void Node::setValue(int newValue){
  value = newValue;
}
void Node::setRight(Node* newRight){
  rightChild = newRight;
}
void Node::setLeft(Node* newLeft){
  leftChild = newLeft;
}
void Node::setParent(Node* newParent){
  parent = newParent;
}
