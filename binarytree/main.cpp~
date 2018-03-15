/*
Kevin Men
C++ Programming
Binary Search Tree - Allows the user to create a binary search tree, then delete elements
3/7/18
 */
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

//Adds a node onto the tree
void addNode(Node* &head, int value){
  //if this is the only node, create a new node and give the appropriate value
  if(head == NULL){
    head = new Node();
    head->setValue(value);
    return;
  }
  //if the value is greater than the node, go to the right
  if(value > head->getValue()){
    if(head->getRight() != NULL){
      //if there's another node to the right, recursively add it
      Node* next = head->getRight();
      addNode(next, value);
    }else{
      //if there is no node to the right, add a node with value to the right
      Node* tempNode = new Node();
      tempNode->setValue(value);
      head->setRight(tempNode);
      return;
    }
  //if the value is smaller than or equal to the node, go to the left
  }else{
    if(head->getLeft() != NULL){
      //if there's another node to the left, recurseively add it
      Node* next = head->getLeft();
      addNode(next, value);
    }else{
      //if there is no node to the right, add a node with value to the right
      Node* tempNode = new Node();
      tempNode->setValue(value);
      head->setLeft(tempNode);
      return;
    }
    
  }
}
//finds the smallest node in the tree
Node* minNode(Node* head){
  Node* current = head;
  //goes all the way to the left as smaller values go to the left subtree
  while(current->getLeft() != NULL){
    current = current->getLeft();
  }
  return current;
}
//deletes a node
Node* deleteNode(Node* root, int value){
  if(root == NULL){
    return root;
  }
  if(value < root->getValue()){
    root->setLeft(deleteNode(root->getLeft(), value));
  }else if(value > root->getValue()){
    root->setRight(deleteNode(root->getRight(), value));
  }else{
    if(root->getLeft() == NULL){
      Node* temp = root->getRight();
      free(root);
      return temp;
    }else if(root->getRight() == NULL){
      Node* temp = root->getLeft();
      free(root);
      return temp;
    }
    Node* temp = minNode(root->getRight());
    root->setValue(temp->getValue());
    root->setRight(deleteNode(root->getRight(), temp->getValue()));
  }
  return root;
}
//prints out the tree
void printTree(Node* head){
  
}
//prints inorder of the tree
void inorder(Node* head){
  if(head != NULL){
    //inorder is left, node, right
    inorder(head->getLeft());
    cout << head->getValue() << " ";
    inorder(head->getRight());
  }
}
void postOrder(Node* p, int indent = 0){
  if(p != NULL){
    cout << p->getValue() << "\n ";
    if(p->getLeft()){
      postOrder(p->getLeft(), indent + 4);
    }
    if(p->getRight()){
      postOrder(p->getRight(), indent + 4);
    }
    if(indent){
      cout << std::setw(indent) << ' ';
    }
  }
}
int main(){
  Node* head = NULL;
  int response;
  int value;
  char* action;
  char input[500];
  int numbers[100];
  int nodeCount = 0;
  char fileName[20];
  ifstream inFile;
  //gets input type
  cout << "Enter 1 for manual input and 2 for file input" << endl;
  cin >> response;
  cin.get();
  if(response == 1){
    cout << "Enter your numbers separated by spaces" << endl;
    cin.getline(input, 500, '\n');
  }else if(response == 2){
    cout << "Enter the name of the file" << endl;
    cin.getline(fileName, 20, '\n');
    inFile.open(fileName);
    if(!inFile){
      //invalid file name
      cout << "File does not exist!" << endl;
      return 0;
    }
    inFile.getline(input, 500, '\n');
  }else{
    cout << "INVALID RESPONSE" << endl;
    return 0;
  }
  char* split;
  //splits the input by spaces
  split = strtok(input, " ");
  while(split != NULL){
    numbers[nodeCount] = atoi(split);
    nodeCount++;
    split = strtok(NULL, " ");
  }
  cout << endl;
  //loops through each node and adds it onto the tree
  for(int i = 0; i < nodeCount; i++){
    addNode(head, numbers[i]);
  }
  //prints out tree
  cout << "Inorder traversal: ";
  inorder(head);
  cout << endl;
  while(true){
    cout << "Enter DELETE to delete a node" << endl;
    cout << "Enter PRINT to display the tree" << endl;
    cout << "ENTER QUIT to exit" << endl;
    cin.getline(action, 10, '\n');
    if(strcmp(action, "DELETE") == 0){
      //DELETE NODE
      cout << "Enter the value of the node you wish to delete" << endl;
      cin >> value;
      cin.get();
      deleteNode(head, value);
      cout << "Inorder traversal: ";
      inorder(head);
      cout << endl;
    }else if(strcmp(action, "PRINT") == 0){
      //PRINT THE TREE
      postOrder(head);
    }else if(strcmp(action, "QUIT") == 0){
      //QUIT THE PROGRAM
      break;
    }else{
      //if they enter something else
      cout << "INVALID RESPONSE" << endl;
    }
  }
  return 0;
}
