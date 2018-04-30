/*
Kevin Men
Red Black Tree- Allows the user to create a red black tree
C++ Programming
3/19
 */
#include "node.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void insert(node* &root, int value);
void assignColor(node* &n);
void print(node* root);
void rotate(node* &current);
void rotateRight(node* &current);
void rotateLeft(node* &current);
node* sibling(node* &n);

int main(){
  int inputType;
  int nodeCount;
  char* fileName;
  ifstream inFile;
  char* fileInput;
  char* input;
  node* root = NULL;
  int value;
  cout << "\033[1;31mbold red text\033[0m\n";
  cout << "Welcome to red black binary tree" << endl;
  cout << "Type 1 for manual input and 2 for file input" << endl;
  cin >> inputType;
  cin.get();
  if(inputType ==  2){
    //FILE INPUT
    cout << "Enter the name of the file" << endl;
    cin.getline(fileName, 20, '\n');
    inFile.open(fileName);
    if(!inFile){
      cout << "FILE DOES NOT EXIST" << endl;
      return 0;
    }
    inFile.getline(fileInput, 500, '\n');
    //ADD NUMBERS TO TREE
    char* split;
    split = strtok(fileInput, " ");
    while(split != NULL){
      insert(root, atoi(split));
      nodeCount++;
      split = strtok(NULL, " ");
    }
  }
  while(true){
    cout << "Type ADD to insert a node" << endl;
    cout << "Type PRINT to print the tree" << endl;
    cin.getline(input, 10, '\n');
    if(strcmp(input, "ADD") == 0){
      //ADD NODE
      cout << "Enter a number to add into the tree" << endl;
      cin >> value;
      cin.get();
      insert(root, value);
      nodeCount++;
    }else if(strcmp(input, "PRINT") == 0){
      //PRINT TREE
      //print(root);
    }else if(strcmp(input, "QUIT") == 0){
      //QUITS PROGRAMS
      return 0;
    }else{
      cout << "NOT A VALID RESPONSE" << endl;
    }
  }
}
//inserts a node into the tree
void insert(node* &root, int value){
  if(root == NULL){
    root = new node();
    root->setColor(0);
    root->setValue(value);
    return;
  }
  if(value > root->getValue()){
    if(root->getRight() != NULL){
      node* next = root->getRight();
      insert(next, value);
    }else{
      node* tempNode = new node();
      assignColor(tempNode);
      tempNode->setValue(value);
      root->setRight(tempNode);
      return;
    }
  }else{
    if(root->getLeft() != NULL){
      node* next = root->getLeft();
      insert(next, value);
    }else{
      node* tempNode = new node();
      assignColor(tempNode);
      tempNode->setValue(value);
      root->setLeft(tempNode);
      return;
    }
  }
}
//assigns the correct color to a node
void assignColor(node* &n){
  n->setColor(1);
  //if the parent is black, 
  if(n->getParent()->getColor() == 0){
    return;
  }
  if(n->getParent()->getColor() == 1 && n->getParent()->getSibling()->getColor() == 1){
    n->getParent()->setColor(0);
    n->getParent()->getSibling()->setColor(0);
    n->getParent()->getParent()->setColor(1);
    node* gp = n->getParent()->getParent();
    assignColor(gp);
  }
}
//if uncle is black case
void rotate(node* &current){
  //if the uncle is black and the parent and node are both red
  if(current->getParent()->getSibling()->getColor() == 0 && current->getParent()->getColor() == 1 && current->getColor() == 1){
    node* grand = current->getParent()->getParent();
    node* greatg = grand->getParent();
    node* uncle = current->getParent()->getSibling();
    node* parent = current->getParent();
    node* temp = current;
    //left-left case
    if(current->getValue() <= current->getParent()->getValue() && current->getParent()->getValue() <= current->getParent()->getParent()->getValue()){
      //if grandparent isn't root
      if(greatg != NULL){
	if(parent->getValue() > greatg->getValue()){
	  greatg->setRight(parent);
	}else{
	  greatg->setLeft(parent);
	}
	sibling(parent);
      }else{
	parent->setSibling(NULL);
      }
      //adjust current
      current->setSibling(grand);
      //adjust parent
      parent->setColor(0);
      parent->setLeft(current);
      parent->setRight(grand);
      //adjust uncle
      uncle->setParent(grand);
      sibling(uncle);
      //adjust granparent
      grand->setRight(NULL);
      grand->setParent(parent);
      sibling(grand);
      grand->setColor(1);
    //left-right case
    }else if(current->getValue() > current->getParent()->getValue() && current->getParent()->getValue() <= current->getParent()->getParent()->getValue()){

    //right-right case
    }else if(current->getValue() > current->getParent()->getValue() && current->getParent()->getValue() > current->getParent()->getParent()->getValue()){

    //right-left case
    }else if(current->getValue() <= current->getParent()->getValue() && current->getParent()->getValue() > current->getParent()->getParent()->getValue()){

    }
  }
  return;
}
//performs a right rotation (L-L case)
void rotateRight(node* &current){
  node* x = current;
  node* p = current->getParent();
  node* g = p->getParent();
  node* u = p->getSibling();
  //adjust current
  x->setSibling(g);
  //adjust parent
  p->setColor(0);
  p->setLeft(x);
  p->setRight(g);
  //adjust uncle
  sibling(u);
  //adjust grandparent
  g->setRight(u);
  g->setParent(p);
  sibling(grand);
  grand->setColor(1);
  return x;
}
//performs a left rotation (R-R case)
void rotateLeft(node* &current){
  node* x = current;
  node* p = current->getParent();
  node* g = p->getParent();
  node* u = p->getSibling();
  //adjust current
  x->setSibling(g);
  //adjust parent
  p->setColor(0);
  p->setParent(g->getParent());
  sibling(p);
  p->setLeft(g);
  p->setRight(x);
  //adjust uncle
  sibling(u);
  //adjust granparent
  g->setLeft(u);
  g->setParent(p);
  g->setSibling(x);
  g->setColor(1);
}
//prints out the tree
void print(node* p, int indent = 0){
  if(p != NULL){
    if(indent){
      cout << std::setw(indent) << ' ';
    }
    cout << p->getValue() << "\n";
    if(p->getLeft()){
      print(p->getLeft(), indent + 4);
    }
    if(p->getRight()){
      print(p->getRight(), indent + 4);
    }
  }
}
//returns the sibling of a node
node* sibling(node* &n){
  //n is a right child
  if(n->getValue() > n->getParent()->getValue()){
    n->setSibling(n->getParent()->getLeft());
  //n is a left child
  }else{
    n->setSibling(n->getParent()->getRight());
  }
}
