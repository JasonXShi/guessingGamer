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
    current->setRight(new Node());
    current->getRight()->setValue(value);
  }
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
  vector<int> type;
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
    cout << *it;
    if(isdigit(*it)){
      type[count] = 0;
    }else if(strcmp(it, "(") == 0 || strcmp(it, ")") == 0){
      type[count] = 1;
    }else if(strcmp(it, "+") == 0 || strcmp(it, "-") == 0 || strcmp(it, "*") == 0 || strcmp(it, "/") == 0){
      type[count] = 2;
    }
    count++;									    
  }
  
}
