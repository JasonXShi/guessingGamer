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

using namespace std;

void addNode(Node* &head, int value){
  if(head == NULL){
    head->setValue(value);
    return;
  }
  if(value > head->getValue()){
    if(head->getRight() != NULL){
      Node* next = head->getRight();
      addNode(next, value);
    }else{
      Node* tempNode = new Node();
      tempNode->setValue(value);
      head->setRight(tempNode);
      return;
    }
  }else{
    if(head->getLeft() != NULL){
      Node* next = head->getLeft();
      addNode(next, value);
    }else{
      Node* tempNode = new Node();
      tempNode->setValue(value);
      head->setLeft(tempNode);
      return;
    }
    
  }
}
Node* minNode(Node* head){
  Node* current = head;
  while(current->getLeft() != NULL){
    current = current->getLeft();
  }
  return current;
}
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

int main(){
  Node* head = NULL;
  int response;
  char input[500];
  int numbers[100];
  int nodeCount = 0;
  char fileName[20];
  ifstream inFile;
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
      cout << "File does not exist!" << endl;
      return 0;
    }
    inFile.getline(input, 500, '\n');
  }else{
    cout << "INVALID RESPONSE" << endl;
    return 0;
  }
  char* split;
  split = strtok(input, " ");
  while(split != NULL){
    numbers[nodeCount] = atoi(split);
    nodeCount++;
    split = strtok(NULL, " ");
  }
  for(int i = 0; i < nodeCount; i++){
    addNode(head, numbers[i]);
  }
}
