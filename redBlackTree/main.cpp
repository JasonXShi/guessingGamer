/*
Kevin Men
Red Black Tree- Allows the user to create a red black tree
C++ Programming
5/4
 */
#include "node.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

node* insert(node* &current, int value, node* &root);
void assignColor(node* &n, node* &root);
void print(node* root, int indent = 0);
void rotate(node* &current, node* &root);
void rotateRight(node* &current, node* &root);
void rotateLeft(node* &current, node* &root);
void sibling(node* &n);
void child(node* &c, node* &p);
void rightLeft(node* &current, node* &root);
void leftRight(node* &current, node* &root);
bool blackUncle(node* n);
bool redUncle(node* n);
void read(node* &root);
void search(int n, node* root, bool &found);

int main(){
  int inputType;
  char* input;
  node* root = NULL;
  int value;
  cout << "Welcome to red black tree" << endl;
  while(true){
    cout << "Type ADD to insert a node" << endl;
    cout << "Type PRINT to print the tree" << endl;
    cout << "Type QUIT to exit the program" << endl;
    cout << "Type READ to read numbers from a file" << endl;
    cout << "Type SEARCH to search for a number in the tree" << endl;
    cin.getline(input, 10, '\n');
    if(strcmp(input, "ADD") == 0){
      //ADD NODE
      cout << "Enter a number to add into the tree" << endl;
      cin >> value;
      cin.get();
      root = insert(root, value, root);
    }else if(strcmp(input, "PRINT") == 0){
      //PRINT TREE
      print(root);
      cout << "Root value is " << root->getValue() << endl;
    }else if(strcmp(input, "QUIT") == 0){
      //QUITS PROGRAMS
      return 0;
    }else if(strcmp(input, "SEARCH") == 0){
      //checks to see if a node is in the list
      cout << "Enter a number to search for" << endl;
      int value;
      cin >> value;
      cin.get();
      bool found = false;
      search(value, root, found);
      if(found){
	cout << "Node found!" << endl;
      }else{
	cout << "Node not found!" << endl;
      }
    }else if(strcmp(input, "READ") == 0){
      //read from a file input
      read(root);
      cout << "File read" << endl;
      char* fileName;
      ifstream inFile;
      char* fileInput;
      int nodeCount;
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
	insert(root, atoi(split), root);
	nodeCount++;
	split = strtok(NULL, " ");
      }
    }else{
      cout << "NOT A VALID RESPONSE" << endl;
    }
  }
}
//inserts a node into the tree
node* insert(node* &current, int value, node* &root){
  //if this is the first node
  if(root == NULL){
    root = new node();
    root->setColor(0);
    root->setValue(value);
    return root;
  }
  //goes into right subtree
  if(value > current->getValue()){
    //if current has a right child, recursively call
    if(current->getRight() != NULL){
      node* next = current->getRight();
      insert(next, value, root);
    }else{
      //if we've reached the end of the tree, create a new node and add it on
      node* tempNode = new node();
      tempNode->setValue(value);
      current->setRight(tempNode);
      tempNode->setParent(current);
      sibling(tempNode);
      assignColor(tempNode, root);
      cout << "Added the node " << tempNode->getValue() << " as the right child of " << root->getValue() << endl;
      cout << "Tree: " << endl;
      print(root);
      return root;
    }
    //goes into left subtree
  }else{
    //if current has a left child, recursively call
    if(current->getLeft() != NULL){
      node* next = current->getLeft();
      insert(next, value, root);
    }else{
      //if we've reached the end of the tree, create a new node and add it on
      node* tempNode = new node();
      tempNode->setValue(value);
      current->setLeft(tempNode);
      tempNode->setParent(current);
      sibling(tempNode);
      assignColor(tempNode, root);
      cout << "Added the node " << tempNode->getValue() << " as the left child of " << root->getValue() << endl;
      cout << "Tree: " << endl;
      print(root);
      return root;
    }
  }
}
//assigns the correct color to a node
void assignColor(node* &n, node* &root){
  //default to red
  n->setColor(1);
  //if n is the root, set it to black
  if(n->getParent() == NULL){
    cout<< "root node!" << endl;
    n->setColor(0);
    return;
  }
  //if the parent is black
  if(n->getParent()->getColor() == 0){
    cout << "parent is black" << endl;
    return;
  }
  //if parent and uncle are both red
  if(n->getParent()->getColor() == 1 && redUncle(n->getParent()->getSibling()) == true){
    cout << "red uncle" << endl;
    n->getParent()->setColor(0);
    n->getParent()->getSibling()->setColor(0);
    n->getParent()->getParent()->setColor(1);
    node* gp = n->getParent()->getParent();
    assignColor(gp, root);
  }
  //checks for black uncle case
  rotate(n, root);
}
//checks if a node is red (for red uncle case)
bool blackUncle(node* n){
  if(n == NULL){
    return true;
  }
  if(n->getColor() == 0){
    return true;
  }
  return false;
}
//checks if a node is NULL or black (for black uncle case)
bool redUncle(node* n){
  if(n == NULL){
    return false;
  }
  if(n->getColor() == 1){
    return true;
  }
  return false;
}
//if uncle is black case
void rotate(node* &current, node* &root){
  node* x = current;
  node* p = x->getParent();
  node* u = p->getSibling();
  node* g = p->getParent();
  //the node and its parent must be red, the uncle must be black, and the grandparent must not be null
  if(x->getColor() == 1 && p->getColor() == 1 && blackUncle(u) == true && g != NULL){
    cout << "Rotation made!" << endl;
    if(p->getValue() <= g->getValue() && x->getValue() <= p->getValue()){
      //left left case
      rotateRight(current, root);
    }else if(p->getValue() <= g->getValue() && x->getValue() > p->getValue()){
      //left right case
      leftRight(current, root);
    }else if(p->getValue() > g->getValue() && x->getValue() > p->getValue()){
      //right right case
      rotateLeft(current, root);
    }else if(p->getValue() > g->getValue() && x->getValue() <= p->getValue()){
      //right left case
      rightLeft(current, root);
    }
  }
}
//performs a right rotation (L-L case)
void rotateRight(node* &current, node* &root){
  node* x = current;
  node* p = current->getParent();
  node* g = p->getParent();
  node* gg = g->getParent();
  node* gs = g->getSibling();
  node* u = p->getSibling();
  node* t1 = x->getLeft();
  node* t2 = x->getRight();
  node* t3 = p->getLeft();
  //adjust current
  x->setColor(1);
  x->setSibling(g);
  x->setLeft(t1);
  x->setRight(t2);
  x->setParent(p);
  //adjust parent
  p->setColor(0);
  p->setSibling(gs);
  p->setLeft(x);
  p->setRight(g);
  p->setParent(gg);
  //adjust uncle
  if(u != NULL){
    u->setColor(0);
    u->setSibling(t3);
    u->setParent(g);
  }
  //adjust grandparent
  g->setColor(1);
  g->setSibling(x);
  g->setLeft(t3);
  g->setRight(u);
  g->setParent(p);
  //adjust subtrees
  //t1,t2,t4,t5 stay the same
  //t3
  if(t3 != NULL){
    t3->setParent(g);
    t3->setSibling(u);
  }
  //adjust grandparents
  if(gg != NULL){
    child(p, gg);
  }else{
    //adjust root node
    root = p;
  }
}
//first rotatation step in left right case
void leftRight(node* &current, node* &root){
  node* p = current->getParent();
  node* u = p->getSibling();
  node* g = p->getParent();
  node* t1 = p->getLeft();
  node* t2 = current->getLeft();
  node* t3 = current->getRight();
  //adjusts current
  current->setParent(g);
  current->setSibling(u);
  current->setLeft(p);
  current->setRight(t3);
  //adjusts parent
  p->setLeft(t1);
  p->setRight(t1);
  p->setSibling(t3);
  p->setParent(current);
  //adjusts u
  if(u != NULL){
    u->setSibling(current);
  }
  //adjusts g
  g->setLeft(p);
  //adjusts subtrees
  if(t1 != NULL){
    t1->setSibling(t2);
  }
  if(t2 != NULL){
    t2->setSibling(t1);
    t2->setParent(current);
  }
  if(t3 != NULL){
    t3->setSibling(p);
    t3->setParent(current);
  }
  //performs second rotation
  rotateRight(p, root);
}
//first rotation step in the right left case
void rightLeft(node* &current, node* &root){
  node* p = current->getParent();
  node* u = p->getSibling();
  node* g = p->getParent();
  node* t3 = current->getLeft();
  node* t4 = current->getRight();
  node* t5 = p->getRight();
  //adjust current
  current->setParent(g);
  current->setSibling(u);
  current->setLeft(t3);
  current->setRight(p);
  //adjust parent
  p->setParent(current);
  p->setSibling(t3);
  p->setLeft(t4);
  p->setRight(t5);
  //adjust u
  if(u != NULL){
    u->setSibling(current);
  }
  //adjust g
  g->setRight(current);
  //adjust subtrees
  if(t3 != NULL){
    t3->setSibling(p);
  }
  if(t4 != NULL){
    t4->setSibling(t5);
    t4->setParent(p);
  }
  if(t5 != NULL){
    t5->setSibling(t4);
    t5->setParent(p);
  }
  //performs second rotation
  rotateLeft(p, root);
}
//performs a left rotation (R-R case)
void rotateLeft(node* &current, node* &root){
  node* x = current;
  node* p = current->getParent();
  node* g = p->getParent();
  node* gg = g->getParent();
  node* gs = g->getSibling();
  node* u = p->getSibling();
  node* t3 = p->getLeft();
  node* t4 = x->getLeft();
  node* t5 = x->getRight();
  //adjust current
  x->setColor(1);
  x->setSibling(g);
  x->setLeft(t4);
  x->setRight(t5);
  x->setParent(p);
  //adjust parent
  p->setColor(0);
  p->setSibling(gs);
  p->setLeft(g);
  p->setRight(x);
  p->setParent(gg);
  //adjust uncle
  if(u != NULL){
    u->setColor(0);
    u->setSibling(t3);
    u->setParent(g);
  }
  //adjust grandparent
  g->setColor(1);
  g->setSibling(x);
  g->setLeft(u);
  g->setRight(t3);
  g->setParent(p);
  //adjusts subtrees
  //t1,t2,t4,t5 stay the same
  if(t3 != NULL){
    t3->setParent(g);
    t3->setSibling(u);
  }
  //adjust great grand parent
  if(gg != NULL){
    child(p, gg);
  }else{
    root = p;
  }
}
//prints out the tree
void print(node* p, int indent){
  if(p != NULL){
    if(indent){
      cout << std::setw(indent) << ' ';
    }
    //correctly colors the number and tells whether it's left or right child
    if(p->getColor() == 1){
      if(p->getParent() != NULL){
	if(p->getValue() > p->getParent()->getValue()){
	  cout << "\033[1;31m" << p->getValue() << "R" << "\033[0m\n";
	}else{
	  cout << "\033[1;31m" << p->getValue() << "L" << "\033[0m\n";
	}
      }else{
	cout << "\033[1;31m" << p->getValue() << "\033[0m\n";
      }
    }else{
      if(p->getParent() != NULL){
	if(p->getValue() > p->getParent()->getValue()){
	  cout << p->getValue() << "R" << endl;
	}else{
	  cout << p->getValue() << "L" << endl;
	}
      }else{
	cout << p->getValue() << endl;
      }
    }
    if(p->getLeft()){
      print(p->getLeft(), indent + 4);
    }
    if(p->getRight()){
      print(p->getRight(), indent + 4);
    }
  }
}
//assigns the child based on whether its greater than or less than the parent
void child(node* &c, node* &p){
  if(c->getValue() > p->getValue()){
    p->setRight(c);
    c->setSibling(p->getLeft());
  }else{
    p->setLeft(c);
    c->setSibling(p->getRight());
  }
}
//returns the sibling of a node
void sibling(node* &n){
  //if n has no parent, it is the root node
  if(n->getParent() == NULL){
    n->setSibling(NULL);
    return;
  }
  //n is a right child
  if(n->getValue() > n->getParent()->getValue()){
    n->setSibling(n->getParent()->getLeft());
  //n is a left child
  }else{
    n->setSibling(n->getParent()->getRight());
  }
}
//checks to see if a number is in the tree
void search(int n, node* root, bool &found){
  if(root == NULL){
    found = false;
    return;
  }
  if(n > root->getValue()){
    node* right = root->getRight();
    search(n, right, found);
  }
  if(n < root->getValue()){
    node* left = root->getLeft();
    search(n, left, found);
  }
  if(n == root->getValue()){
    cout << "Found the value " << root->getValue() << endl;
    found = true;
    return;
  }
}
void read(node* &root){
  
}
