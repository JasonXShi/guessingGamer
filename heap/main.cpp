#include "Node.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void pushNode(Node* head, char* value){
  Node* current = head;
  if(current == NULL){
    head->setValue(value);
    return;
  }
  while(current->getRight() != NULL){
    current = current->getRight();
  }
  Node* tempNode = new Node();
  tempNode->setValue(value);
  current->setRight(tempNode);
}
char* popNode(Node* head){
  Node* tempNode = head;
  if(head->getRight() != NULL){
    head = head->getRight();
    return tempNode->getValue();
  }else{
    head = NULL;
    return tempNode->getValue();
  }
}
int main(){
  int response;
  char input[500];
  Node* head = NULL;
  int numbers[100];
  int nodeCount = 0;
  cout << "Enter 1 for manual input, and 2 for file input" << endl;
  cin >> response;
  cin.get();
  if(response == 1){
    cout << "Enter your numbers separated by spaces: " << endl;
    cin.getline(input, 500, '\n');
    char* split;
    split = strtok(input, " ");
    while(split != NULL){
      //cout << split << endl;
      numbers[nodeCount] = atoi(split);
      nodeCount++;
      split = strtok(NULL, " ");
    }
  }else if(response == 2){
    //INPUT TEXT INPUT HERE
  }else{
    cout << "NOT A VALID RESPONSE" << endl;
  }
  for(int i = 0; i < nodeCount; i++){
    cout << numbers[i] << endl;
  }
}
