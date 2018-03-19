//cpp file for node class
#include "node.h"
#include <cstddef>

//initializes everything to NULL
node::node(){
  leftChild = NULL;
  rightChild = NULL;
  sibling = NULL;
  parent = NULL;
  grandparent = NULL;
  uncle = NULL;
  color;
  value;
}
//destructor
node::~node(){
  leftChild = NULL;
  rightChild = NULL;
  sibling = NULL;
  parent = NULL;
  grandparent = NULL;
  uncle = NULL;
}
//getters
node* node::getRight(){
  return rightChild;
}
node* node::getLeft(){
  return leftChild;
}
node* node::getSibling(){
  return sibling;
}
node* node::getParent(){
  return parent;
}
node* node::getGrandparent(){
  return grandparent;
}
node* node::getUncle(){
  return uncle;
}
int node::getColor(){
  return color;
}
int node::getValue(){
  return value;
}
//setters
void node::setRight(node* newRight){
  rightChild = newRight;
}
void node::setLeft(node* newLeft){
  leftChild = newLeft;
}
void node::setSibling(node* newSibling){
  sibling = newSibling;
}
void node::setParent(node* newParent){
  parent = newParent;
}
void node::setGrandparent(node* newGrand){
  grandparent = newGrand;
}
void node::setUncle(node* newUncle){
  uncle = newUncle;
}
void node::setColor(int newColor){
  color = newColor;
}
void node::setValue(int newValue){
  value = newValue;
}
