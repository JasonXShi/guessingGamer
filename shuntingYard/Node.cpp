#include "Node.h"
Node::Node(){
}
void Node::setRight(Node* rightNode){
  rightChild = rightNode;
}
void Node::setLeft(Node* leftNode){
  leftChild = leftNode;
}
void Node::setValue(char* newValue){
  value = newValue;
}
char* Node::getValue(){
  return value;
}
Node* Node::getRight(){
  return rightChild;
}
Node* Node::getLeft(){
  return leftChild;
}
