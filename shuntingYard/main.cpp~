#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Node.h"

using namespace std;

void addNode(char* value, Node* &head){
  Node* current = head;
  if(current == NULL){
    head = new Node();
    head->setValue(value);
  }else{
    while(current->getRight() != NULL){
      current = current->getRight();
    }
    Node* tempNode = new Node();
    tempNode->setValue(value);
    current->setRight(tempNode);
  }
}
void pushNode(char* value, Node* &head){
  Node* current = head;
  if(current == NULL){
    head = new Node();
    head->setValue(value);
  }else{
    Node* tempNode = new Node();
    tempNode->setValue(value);
    tempNode->setRight(head);
    head = tempNode;
  }
}
void printList(Node* &head){
  Node* current = head;
  if(current != NULL){
    cout << current->getValue() << endl;
  }
  Node* nextNode = current->getRight();
  printList(nextNode);
}
bool isNumber(char* value){
  for(int i = 0; i < strlen(value); i++){
    if(isdigit(value[i]) == false){
      return false;
    }
  }
  return true;
}

int main(){
  map<char, int> precedence;
  precedence['^'] = 4;
  precedence['/'] = 3;
  precedence['*'] = 3;
  precedence['+'] = 2;
  precedence['-'] = 2;

  map<char, int> associativity;
  associativity['^'] = 0;
  associativity['/'] = 1;
  associativity['*'] = 1;
  associativity['+'] = 1;
  associativity['-'] = 1;
  
  char input[100];
  vector<char*> expression;
  vector<char*> output;
  Node* operatorStack = NULL;
  cin.getline(input, 100, '\n');
  char* split;
  split = strtok(input, " ");
  while(split != NULL){
    expression.push_back(split);
    split =  strtok (NULL, " ");
  }
  int type[expression.size()];
  int count = 0;
  for(vector<char*>::iterator it = expression.begin(); it!=expression.end(); ++it){
    //cout << *it;
    if(isNumber(*it)){
      type[count] = 0;
      //cout << *it << " is a number" << endl;
    }else if(strcmp(*it, "(") == 0 || strcmp(*it, ")") == 0){
      type[count] = 1;
    }else if(strcmp(*it, "+") == 0 || strcmp(*it, "-") == 0 || strcmp(*it, "*") == 0 || strcmp(*it, "/") == 0){
      type[count] = 2;
      //cout << *it << " is an operator" << endl;
    }
    count++;									    
  }
  count = 0;
  for(vector<char*>::iterator it = expression.begin(); it!=expression.end(); ++it){
    if(type[count] == 0){
      output.push_back(*it);
      cout << *it << " is a number" << endl;
    }else if(type[count] == 2){
      pushNode(*it, operatorStack);
      cout << *it << " is an operator" << endl;
    }
    count++;
  }
  printList(operatorStack);
}
