/*
Kevin Men
C++ Programming
Shunting Yard Algorithm
2/21/18
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Node.h"

using namespace std;

//returns the value of the first node in the stack
char* peepNode(Node* head){
  if(head == NULL){
    return NULL;
  }
  return head->getValue();
}
//pushes a node into the front of the stack
void pushNode(char* value, Node* &head){
  Node* current = head;
  if(current == NULL){
    //adds the node before the current head
    head = new Node();
    head->setValue(value);
    Node* tempNode = NULL;
    head->setRight(tempNode);
  }else{
    //if this is the first node in the stacl
    Node* tempNode = new Node();
    tempNode->setValue(value);
    tempNode->setRight(head);
    head = tempNode;
  }
}
//removes the top node from the stack
char* popNode(Node* &head){
  Node* tempNode = head;
  if(head->getRight() != NULL){
    //sets head equal to the second node and returns the first ndoe
    head = head->getRight();
    return tempNode->getValue();
  }else{
    head = NULL;
    return tempNode->getValue();
  }
}
//checks if a char is a number
bool isNumber(char* value){
  //loops through and checks to make sure all characters are digits
  for(int i = 0; i < strlen(value); i++){
    if(isdigit(value[i]) == false){
      return false;
    }
  }
  return true;
}
//loops through the operator stack and pops all nodes until the left bracket is reached, then pops the left bracket out of the stack
void popLeft(Node* &head, vector<char*> &output){
  while(strcmp(head->getValue(), "(") != 0){
    output.push_back(head->getValue());
    popNode(head);
  }
  popNode(head);
}
//pushes the remaining operators into the output vector
void popRest(Node* &head, vector<char*> &output){
  Node* current = head;
  while(current != NULL){
    output.push_back(current->getValue());
    current = current->getRight();
  }
  head = NULL;
}
//converts expression tree to infix notation
void printInfix(Node* treeHead, int counter, int length){
  Node* current = treeHead;
  //checks to make sure the current node isn't null
  if(current != NULL){
    //prints out opening bracket if there's an operator
    if(!isNumber(current->getValue())){
      cout << "( ";
    }
    //recursively calls infix on left and right children
    if(current->getLeft() != NULL){
      printInfix(current->getLeft(), counter, length);
    }
    cout << current->getValue() << " ";
    //if we have printed everything out, exit the function
    counter++;
    if(counter == length){
      return;
    }
    if(current->getRight() != NULL){
      printInfix(current->getRight(), counter, length);
    }
    //closes opening bracket
    if(!isNumber(current->getValue())){
      cout << ") ";
    }
  }
}
//converts expression tree to prefix notation
void printPrefix(Node* treeHead, int counter, int length){
  Node* current = treeHead;
  //makes sure the current node isn't null
  if(current != NULL){
    //print statement goes in between recursion because this is prefix
    cout << current->getValue() << " ";
    //if we have printed everything out, exit the function
    counter++;
    if(counter == length){
      return;
    }
    //if we can, recursively call function on left and right children
    if(current->getLeft() != NULL){
      printPrefix(current->getLeft(), counter, length);
    }
    if(current->getRight() != NULL){
      printPrefix(current->getRight(), counter, length);
    }
  }
}
//converts expression tree to prefix notation
void printPostfix(Node* treeHead, int counter, int length){
  Node* current = treeHead;
  //makes sure the current node isn't null
  if(current != NULL){
    //recursively call function on left and right children
    if(current->getLeft() != NULL){
      printPostfix(current->getLeft(), counter, length);
    }
    if(current->getRight() != NULL){
      printPostfix(current->getRight(), counter, length);
    }
    //print statement goes after recursion because this is postfix
    cout << current->getValue() << " ";
    counter++;
    //if we have printed everything out, exit the funtion
    if(counter == length){
      return;
    }
  }
}
//takes the last two elements of a vector and creates a node out of them
void addTreeNode(vector<Node*> &treeStack, Node* &treeHead, char* value){
  //saves last two nodes
  Node* first = treeStack.end()[-2];
  Node* second = treeStack.end()[-1];
  //erases last two noders from vector
  treeStack.erase(treeStack.end()-1);
  treeStack.erase(treeStack.end()-1);
  //adds in another node that uses the operator as the parent
  //and the numbers as the children
  Node* tempNode = new Node();
  tempNode->setLeft(first);
  tempNode->setRight(second);
  tempNode->setValue(value);
  treeStack.push_back(tempNode);
  treeHead = tempNode;
}
//creates an expression tree out of a postfix expression
Node* expressionTree(vector<char*> expression, int type[]){
  Node* treeHead = NULL;
  vector<Node*> treeStack;
  int count = 0;
  //loops through the expression
  for(vector<char*>::iterator it = expression.begin(); it!=expression.end(); ++it){
    if(isNumber(*it)){
      //if it's a number, add it to the stack
      Node* tempNode = new Node();
      tempNode->setValue(*it);
      treeStack.push_back(tempNode);
    }else{
      //if it's an operator, create another node
      addTreeNode(treeStack, treeHead, *it);
    }
    count++;
  }
  //returns the head of the tree
  return treeHead;
}
//converts infix to postfix
void shuntingYard(vector<char*> expression, vector<char*> &output, Node* operatorStack, int type[], map<char, int> precedence, map<char,int> associativity){
  int count = 0;
  for(vector<char*>::iterator it = expression.begin(); it!=expression.end(); ++it){
    if(type[count] == 0){
      //if it's a number, add it to the output vector
      output.push_back(*it);
    }else if(type[count] == 2){
      if(peepNode(operatorStack) != NULL){
	//adds operators according to the shunting yard algorithm
	while((precedence[*peepNode(operatorStack)] > precedence[**it] || (precedence[*peepNode(operatorStack)] == precedence[**it] && associativity[**it] == 1) && strcmp(peepNode(operatorStack), ")") != 0)){
	  output.push_back(popNode(operatorStack));
	}
      }
      pushNode(*it, operatorStack);
    }else if(strcmp(*it, "(") == 0){
      //if it's an opening bracket, push it onto the operator stack
      pushNode(*it, operatorStack);
    }else if(strcmp(*it, ")") == 0){
      //loops through until the closing brace is found
      popLeft(operatorStack, output);  			 			 
    }			 
    count++;
  }
  //pops the rest of the operators onto the output
  popRest(operatorStack, output);
}
int main(){
  //keeps track of precedence
  map<char, int> precedence;
  precedence['^'] = 4;
  precedence['/'] = 3;
  precedence['*'] = 3;
  precedence['+'] = 2;
  precedence['-'] = 2;
  //keeps track of associativity
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
  cout << "Enter your infix expression: ";
  cin.getline(input, 100, '\n');
  //splits the input into tokens split by a space
  char* split;
  split = strtok(input, " ");
  while(split != NULL){
    expression.push_back(split);
    split =  strtok (NULL, " ");
  }
  int type[expression.size()];
  int type2[expression.size()];
  int count = 0;
  //assigns each token a type
  //0- number
  //1- bracket
  //2- operator
  for(vector<char*>::iterator it = expression.begin(); it!=expression.end(); ++it){
    if(isNumber(*it)){
      type[count] = 0;
    }else if(strcmp(*it, "(") == 0 || strcmp(*it, ")") == 0){
      type[count] = 1;
    }else if(strcmp(*it, "+") == 0 || strcmp(*it, "-") == 0 || strcmp(*it, "*") == 0 || strcmp(*it, "/") == 0 || strcmp(*it, "^") == 0){
      type[count] = 2;
    }
    count++;									    
  }
  count = 0;
  //displays shunting yard output
  cout << "Shunting Yard: ";
  shuntingYard(expression, output, operatorStack, type, precedence, associativity);
  for(vector<char*>::iterator it = output.begin(); it!=output.end(); ++it){
    cout << *it << " ";
    if(isNumber(*it)){
      type2[count] = 0;
    }else{
      type2[count] = 1;
    }
    count++;
  }
  cout << endl;
  int counter = 0;
  int length = output.size();
  //creates expression tree and prints out different notations
  Node* treeHead = expressionTree(output, type2);
  cout << "Using Expression Tree: " << endl;
  cout << "Infix: ";
  printInfix(treeHead, counter, length);
  cout << endl;
  cout << "Prefix: ";
  printPrefix(treeHead, counter, length);
  cout << endl;
  cout << "Postfix: ";
  printPostfix(treeHead, counter, length);
}
