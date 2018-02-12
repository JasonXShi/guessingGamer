//Header class for the node class
#ifndef NODE_H
#define NODE_H
class Node {
 public:
  Node* getRight();
  Node* getLeft();
  void setRight(Node*);
  void setLeft(Node*);
  void setValue(char*);
  char* getValue();
  Node();

 private:
  Node* rightChild;
  Node* leftChild;
  char* value;
};
#endif
