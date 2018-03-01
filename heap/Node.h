#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  Node* getRight();
  Node* getLeft();
  Node* getParent();
  char* getValue();
  void setRight(Node*);
  void setLeft(Node*);
  void setParent(Node*);
  void setValue(char*);
 private:
  Node* rightChild;
  Node* leftChild;
  Node* parent;
  char* value;
};
#endif
