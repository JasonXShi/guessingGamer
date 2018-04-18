//.h file for the node class
#ifndef NODE_H
#define NODE_H

class node{
 public:
  //constructor and destructor
  node();
  ~node();
  //getters
  node* getRight();
  node* getLeft();
  node* getSibling();
  node* getParent();
  node* getGrandparent();
  node* getUncle();
  int getValue();
  int getColor();
  //setters
  void setRight(node*);
  void setLeft(node*);
  void setSibling(node*);
  void setParent(node*);
  void setGrandparent(node*);
  void setUncle(node*);
  void setValue(int);
  void setColor(int);
 private:
  //member variables
  node* leftChild;
  node* rightChild;
  node* sibling;
  node* parent;
  node* grandparent;
  node* uncle;
  int value;
  //0- BLACK
  //1- RED
  int color;
};
#endif 
