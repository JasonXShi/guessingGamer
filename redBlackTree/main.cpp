/*
Kevin Men
Red Black Tree- Allows the user to create a red black tree
C++ Programming
5/24
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
node* search(int n, node* root, bool &found);
node* deletion(node* v, node* root);
node* deleteNode(int n, node* root);
node* rebalance(node* &u, node* &v, node* root, bool twoChild);
node* rightCase32c(node* &u, node* &p, node* &s, node* root);
node* leftCase32c(node* &u, node* &p, node* &s, node* root);
node* llcase32a(node* u, node* p, node* s, node* root);
node* lrcase32a(node* u, node* p, node* s, node* root);
node* rrcase32a(node* u, node* p, node* s, node* root);
node* rlcase32a(node* u, node* p, node* s, node* root);
void removeNode(node* &u);
node* inorderPredacessor(node* n);

int main(){
  int inputType;
  char input[10];
  node* root = NULL;
  int value;
  cout << "Welcome to red black tree" << endl;
  while(true){
    cout << "Type ADD to insert a node" << endl;
    cout << "Type PRINT to print the tree" << endl;
    cout << "Type QUIT to exit the program" << endl;
    cout << "Type READ to read numbers from a file" << endl;
    cout << "Type SEARCH to search for a number in the tree" << endl;
    cout << "Type DELETE to delete a node from the tree" << endl;
    //cin.getline(input, 10, '\n');
    cin >> input;
    cin.get();
    if(strcmp(input, "ADD") == 0){
      //ADD NODE
      cout << "Enter a number to add into the tree" << endl;
      cin >> value;
      cin.get();
      root = insert(root, value, root);
    }else if(strcmp(input, "PRINT") == 0){
      //PRINT TREE
      if(root == NULL){
	cout << "TREE IS EMPTY!" << endl;
      }else{
	cout << "Root value is " << root->getValue() << endl;
	print(root);
      }
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
      cout << "File read" << endl;
      char fileName[20];
      ifstream inFile;
      char fileInput[500];
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
      cout << "test: " << root->getLeft()->getRight()->getValue() << endl;
    }else if(strcmp(input, "DELETE") == 0){
      cout << "Enter the number you would like to delete" << endl;
      cin >> value;
      cin.get();
      root = deleteNode(value, root);
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
      if(tempNode->getSibling() != NULL){
	cout << "Sibling of " << tempNode->getValue() << " is " << tempNode->getSibling()->getValue();
	node* sib = tempNode->getSibling();
	sibling(sib);
      }
      //ADD THE NODE INTO THE TREE
      assignColor(tempNode, root);
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
      if(tempNode->getSibling() != NULL){
	cout << "Sibling of " << tempNode->getValue() << " is " << tempNode->getSibling()->getValue();
	node* sib = tempNode->getSibling();
	sibling(sib);
      }
      assignColor(tempNode, root);
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
    return;
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
  cout << "Current: " << current->getValue() << endl;
  node* x = current;
  node* p = current->getParent();
  node* g = p->getParent();
  node* gg = g->getParent();
  node* gs = g->getSibling();
  node* u = p->getSibling();
  node* t1 = x->getLeft();
  node* t2 = x->getRight();
  node* t3 = p->getRight();
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
    cout << "P: " << p->getValue() << endl;
    cout << "G: " << g->getValue() << endl;
    cout << "Gg: " << gg->getValue() << endl;
    child(p, gg);
    if(gs != NULL){
      sibling(gs);
    }
  }else{
    //adjust root node
    root = p;
  }
}
//first rotatation step in left right case
void leftRight(node* &current, node* &root){
  cout << "left right" << current->getValue() << endl;
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
  p->setRight(t2);
  p->setSibling(t3);
  p->setParent(current);
  //adjusts u
  if(u != NULL){
    u->setSibling(current);
  }
  //adjusts g
  g->setLeft(current);
  //adjusts subtrees
  if(t1 != NULL){
    t1->setSibling(t2);
  }
  if(t2 != NULL){
    t2->setSibling(t1);
    t2->setParent(p);
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
    if(gs != NULL){
      sibling(gs);
    }
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
  //makes sure both nodes exist
  if(c == NULL || p == NULL){
    return;
  }
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
  //if n is null, we cannot assign it a sibling
  if(n == NULL){
    return;
  }
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
node* search(int n, node* root, bool &found){
  if(root == NULL){
    found = false;
    return NULL;
  }
  //search recursively in right subtree
  if(n > root->getValue()){
    node* right = root->getRight();
    return search(n, right, found);
  }
  //search recursively in left subtree
  if(n < root->getValue()){
    node* left = root->getLeft();
    return search(n, left, found);
  }
  //found the node
  if(n == root->getValue()){
    cout << "Found the value " << root->getValue() << endl;
    found = true;
    return root;
  }
}
//delete fuction
node* deleteNode(int n, node* root){
  bool found = false;
  node* v = search(n, root, found);
  if(v == NULL){
    cout << "Node not found!" << endl;
    return root;
  }
  cout << "Deleting..." << v->getValue() << endl;
  return deletion(v, root);
}
//finds inorder predacessor of a node
node* inorderPredacessor(node* n){
  node* current = n;
  while(current->getRight() != NULL){
    current = current->getRight();
  }
  return current;
}
//finds u
node* deletion(node* v, node* root){
  int value = v->getValue();
  bool twoChild = false;
  bool nullU = false;
  node* u;
  node* leftSubtree;
  int x;
  if(v->getRight() == NULL && v->getLeft() == NULL){
    //v has no chilren
    cout << "No children" << endl;
    u = NULL;
    nullU = true;
  }else if(v->getRight() == NULL){
    //replace v with the left child
    u = v->getLeft();
  }else if(v->getLeft() == NULL){
    //replace v with the right child
    u = v->getRight();
  }else{
    //v has 2 chilren
    //find inorder predacessor
    u = inorderPredacessor(v->getLeft());
    leftSubtree = v->getLeft();
    v->setValue(u->getValue());
    //delete predacessor from left subtree
    deleteNode(u->getValue(), leftSubtree);
    return root;
    twoChild = true;
  }
  root = rebalance(u, v,  root, twoChild);
  return root;
}
//function that rebalances the tree for deletion
node* rebalance(node* &u, node* &v, node* root, bool twoChild){
  cout << "Rebalancing" << endl;
  bool lchild;
  bool blacku;
  node* p = v->getParent();
  node* s = v->getSibling();
  //if we are deleting root with a NULL u
  if(p != NULL){
    if(p->getLeft() == v){
      lchild = true;
    }else{
      lchild = false;
    }
  }
  if(v == root && u == NULL){
    //checks if we are removing the only node in the tree
    if(p != NULL){
      root = p;
    }else{
      return NULL;
    }
  }
  //simple cases
  blacku = blackUncle(u);
  cout << v->getColor() << endl;
  if(v->getColor() == 1 || blacku == false){
    cout << "Simple case" << endl;
    
    //simple case (one of them is red)
    node* us = NULL;
    delete(v);
    if(u != NULL){
      //adjust u
      us = u->getSibling();
      u->setColor(0);
      u->setParent(p);
      u->setSibling(s);
      if(us != NULL){
	child(us, u);
	us->setSibling(NULL);	
      }
    }
    if(p != NULL){
      if(lchild){
	p->setLeft(u);
      }else{
	p->setRight(u);
      }
    }else{
      cout << "P is NULL!" << endl;
      //if p is null, then the new root is u
      root = u;
    }
    return root;
  }else{
    bool doubleBlack = true;
    //u and v are both black
    //delete v and put u in its place
    delete(v);
    if(u != NULL){
      node* us = u->getSibling();
      u->setParent(p);
      u->setSibling(s);
      if(us != NULL){
	child(us, u);
      }
    }
    if(p != NULL){
      if(lchild){
	p->setLeft(u);
      }else{
	p->setRight(u);
      }
    }
    if(s != NULL){
      s->setSibling(u);
    }
    //while there is still a double black to be deleted
    while(doubleBlack){
      //if root is double black, set it to black and break;
      if(u == root){
	cout << "root is double black" << endl;
	u->setColor(0);
	return root;
      }
      //sets parent and sibling
      if(u != NULL){
	node* s = u->getSibling();
	node* p = u->getParent();
      }
      node* rr = s->getRight(); //right child of sibling
      node* lr = s->getLeft(); //left child of sibling
      
      //3.2 case a (sibling is black and has at least 1 red child)
      if(s->getColor() == 0 && (redUncle(lr) || (redUncle(rr)))){
	cout << "At least one red child" << endl;
	cout << "Parent: " << p->getValue() << " Sibling: " << s->getValue() << endl;
	if(lr != NULL){
	  if(p->getLeft() == s && lr->getColor() == 1){
	    //left left case
	    cout << "left left case" << endl;
	    root = llcase32a(u, p, s, root);
	    return root;
	  }else if(rr != NULL){
	    if(p->getRight() == s && rr->getColor() == 1){
	      //right right case
	      cout << "right right case" << endl;
	      root = rrcase32a(u, p, s, root);
	      return root;
	    }
	  }else if(p->getRight() == s && lr->getColor() == 1){
	    //right left case
	    cout << "right left case" << endl;
	    root = rlcase32a(u, p, s, root);
	  
	  }
	}
	if(rr != NULL){
	  if(p->getLeft() == s && rr->getColor() == 1){
	    //left right case
	    cout << "left right case" << endl;
	    root = lrcase32a(u, p, s, root);
	  }else if(p->getRight() == s && rr->getColor() == 1){
	    //right right case
	    cout << "right right case" << endl;
	    root = rrcase32a(u, p, s, root);
	    return root;
	  }
	}
	doubleBlack = false;
      }else if(s->getColor() == 0 && blackUncle(rr) == true && blackUncle(lr) == true){	
	//3.2 case b (sibling is black and has 2 black children)
	s->setColor(1);
        //delete u and replace it with NULL
	if(u == NULL){
	  if(p->getLeft() == u){
	    p->setLeft(NULL);
	    delete(u);
	  }else{
	    p->setRight(NULL);
	    delete(u);
	  }
	}else{
	  u->setColor(0);
	}
	sibling(s);
	//if parent is black, turn it to double black
	if(p->getColor() == 0 && p != root){
	  //recursively call rebalance on p
	  u = p;
	  s = p->getSibling();
	  p = p->getParent();
	  if(p != NULL){
	    cout << "new parent " << p->getValue() << endl;
	  }
	  if(s != NULL ){
	    cout << "new sibling " << s->getValue() << endl;
	  }
	  print(root);
	  cout << "recursive call on p" << endl;
	}else{
	  cout << "Don't need to recursive call on p" << endl;
	  p->setColor(0);
	  doubleBlack = false;
	}
      }else if(s->getColor() == 1){
      //case 3.2 c (sibling is red)
	cout << "Case 3.2 red sibling" << endl;
	if(s == p->getLeft()){
	  //left case
	  node* newS = s->getRight();
	  root = leftCase32c(u, p, s, root);
	  if(s->getRight() != NULL){
	    cout << "new sibling(L) " << newS->getValue() << endl;
	  }
	  s = newS;
	}else{
	  //right case
	  node* newS = s->getLeft();
	  root = rightCase32c(u, p, s, root);
	  if(s->getLeft() != NULL){
	    cout << "new sibling(R) " << newS->getValue() << endl;
	  }
	  s = newS;
	}
        
      }
    }
    return root;
  }
  
}

//left left case for 3.2 part a
node* llcase32a(node* u, node* p, node* s, node* root){
  int color = p->getColor();
  node* t1 = s->getLeft();
  node* t2 = s->getRight();
  node* g = p->getParent();
  node* ps = p->getSibling();
  //adjust u
  if(u != NULL){
    u->setSibling(t2);
  }
  //adjust parent
  p->setParent(s);
  p->setSibling(t1);
  p->setLeft(t2);
  p->setRight(u);
  p->setColor(0);
  //adjust sibling
  s->setParent(g);
  s->setSibling(ps);
  s->setLeft(t1);
  s->setRight(p);
  s->setColor(color);
  //adjust subtrees
  t1->setSibling(p);
  t1->setColor(0);
  if(t2 != NULL){
    t2->setSibling(u);
    t2->setParent(p);
  }
  //check if root has been changed
  if(g == NULL){
    root = s;
  }else{
    child(s, g);
    if(ps != NULL){
      sibling(ps);
    }
  }
  return root;
}
//left right case for 3.2 part a
node* lrcase32a(node* u, node* p, node* s, node* root){
  //performs initial rotation followed by left left case
  node* redNode = s->getRight();
  int value = s->getValue();
  s->setValue(redNode->getValue());
  s->setRight(NULL);
  s->setLeft(redNode);
  redNode->setValue(value);
  return llcase32a(u, p, s, root);
  
}
//right right case for 3.2 part a
node* rrcase32a(node* u, node* p, node* s, node* root){
  int color = p->getColor();
  node* t1 = s->getLeft();
  node* t2 = s->getRight();
  node* g = p->getParent();
  node* ps = p->getSibling();
  //adjust u
  if(u != NULL){
    u->setSibling(t1);
  }
  //adjust parent
  p->setColor(0);
  p->setLeft(u);
  p->setRight(t1);
  p->setParent(s);
  p->setSibling(t2);
  //adjust sibling
  s->setParent(g);
  s->setSibling(ps);
  s->setLeft(p);
  s->setRight(t2);
  s->setColor(color);
  //adjust subtrees
  if(t1 != NULL){
    t1->setParent(p);
    t1->setSibling(u);
  }
  if(t2 != NULL){
    t2->setSibling(p);
    t2->setColor(0);
  }
  if(g == NULL){
    root = s;
  }else{
    child(s, g);
    if(ps != NULL){
      sibling(ps);
    }
  }
  return root;
}
//right left case for 3.2 part a
node* rlcase32a(node* u, node* p, node* s, node* root){
  //performs initial rotation followed by right right case
  node* redNode = s->getLeft();
  int value = s->getValue();
  s->setValue(redNode->getValue());
  s->setLeft(NULL);
  s->setRight(redNode);
  redNode->setValue(value);
  return rrcase32a(u, p, s, root);
}
//right case for 3.2 part c
node* rightCase32c(node* &u, node* &p, node* &s, node* root){
  node* t1 = s->getLeft();
  node* t2 = s->getRight();
  node* g = p->getParent();
  node* ps = p->getSibling(); 
  //adjust u
  if(u != NULL){
    u->setParent(p);
    u->setSibling(t1);
  }
  //adjust parent
  p->setColor(1);
  p->setParent(s);
  p->setLeft(u);
  p->setRight(t1);
  p->setSibling(t2);
  //adjust sibling
  s->setColor(0);
  s->setLeft(p);
  s->setRight(t2);
  s->setParent(g);
  s->setSibling(ps);
  //adjust subtrees
  if(t2 != NULL){
    t2->setSibling(p);
  }
  if(t1 != NULL){
    t1->setParent(p);
    t1->setSibling(u);
  }
  //if the root was changed
  if(g == NULL){
    root = s;
  }else{
    child(s, g);
    if(ps != NULL){
      sibling(ps);
    }
  }
  return root;
}
//right case for 3.2 part c
node* leftCase32c(node* &u, node* &p, node* &s, node* root){
  node* t1 = s->getLeft();
  node* t2 = s->getRight();
  node* g = p->getParent();
  node* ps = p->getSibling();
  //adjust u
  if(u != NULL){
    u->setSibling(t2);
  }
  //adjust parent
  p->setColor(1);
  p->setParent(s);
  p->setSibling(t1);
  p->setLeft(t2);
  //adjust sibling
  s->setColor(0);
  s->setRight(p);
  s->setParent(g);
  s->setSibling(ps);
  //adjust subtrees
  if(t2 != NULL){
    t2->setParent(p);
    t2->setSibling(u);
  }
  if(t1 != NULL){
    t1->setSibling(p);
  }
  //if the root was changed
  if(g == NULL){
    root = s;
  }else{
    child(s, g);
    if(ps != NULL){
      sibling(ps);
    }
  }
  return root;
}
