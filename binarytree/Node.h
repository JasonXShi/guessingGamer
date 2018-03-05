#ifndef NODE_H
#define NODE_H

class Node{
 public:
  ~Node();
  Node();
  Node* getRight();
  Node* getLeft();
  Node* getParent();
  int getValue();
  void setValue(int);
  void setLeft(Node*);
  void setRight(Node*);
  void setParent(Node*);
 private:
  Node* leftChild;
  Node* rightChild;
  Node* parent;
  int value;
};
#endif
