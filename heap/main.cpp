/*
Kevin Men
C++ Programming
Heap
Constructs a max heap from a user input or file input
 */
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
void max_heapify(int (&A)[101], int i, int nodeCount){
  int l = 2*i;
  int r = (2*i) + 1;
  int largest;
  if(l <= nodeCount && A[l] > A[i]){
    largest = l;
  }else{
    largest = i;
  }
  if(r <= nodeCount && A[r] > A[largest]){
    largest = r;
  }
  if(largest != i){
    int temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    max_heapify(A, largest, nodeCount);
  }
}
void build_max_heap(int (&A)[101], int nodeCount){
  int heapSize = nodeCount;
  for(int i = nodeCount/2; i > 0; i--){
    max_heapify(A, i, nodeCount);
  }
}
int main(){
  int response;
  char input[500];
  Node* head = NULL;
  int numbers[101];
  int nodeCount = 1;
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
    return 0;
  }
  build_max_heap(numbers, nodeCount);
  for(int i = 1; i < nodeCount; i++){
    cout << numbers[i] << endl;
  }
  
}
