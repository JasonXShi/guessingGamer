#include "Node.h"
#include <cstddef>

Node::Node(){
  rightChild = NULL;
  leftChild = NULL;
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
char* Node::getValue(){
  return value;
}
void Node::setRight(Node* newRightChild){
  rightChild = newRightChild;
}
void Node::setLeft(Node* newLeftChild){
  leftChild = newLeftChild;
}
void Node::setParent(Node* newParent){
  parent = newParent;
}
void Node::setValue(char* newValue){
  value = newValue;
}
