//Header class for the node class
#ifndef NODE_H
#define NODE_H
class Node {
 public:
  //getters and setters
  Node* getRight();
  Node* getLeft();
  void setRight(Node*);
  void setLeft(Node*);
  void setValue(char*);
  char* getValue();
  Node();

 private:
  //left and right child variables
  Node* rightChild;
  Node* leftChild;
  //stores value of the node
  char* value;
};
#endif
