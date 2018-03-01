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

//NODE FUNCTIONS NOT USED
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
//END OF NODE FUNCTIONS
void printHeap(int A[100], int n, int start, int nodeCount);
//satisfied the properties of a max heap
void max_heapify(int (&A)[100], int i, int nodeCount){
  int l = (2*i) + 1;
  int r = (2*i) + 2;
  int largest = i;
  if(l < nodeCount && A[l] > A[i]){
    largest = l;
  }
  if(r < nodeCount && A[r] > A[largest]){
    largest = r;
  }
  if(largest != i){
    swap(A[i], A[largest]);
    max_heapify(A, largest, nodeCount);
  }
}
//build the heap by editting the original array
void build_max_heap(int (&A)[100], int nodeCount){
  int heapSize = nodeCount;
  for(int i = (nodeCount/2) - 1; i >= 0; i--){
    max_heapify(A, i, nodeCount);
  }
}
//sorts heap from low to high
void heapSort(int (&A)[100], int nodeCount){
  build_max_heap(A, nodeCount);
  cout << "Printing max heap" << endl;
  printHeap(A, 1, 0, nodeCount);
  cout << endl;
  for(int i = nodeCount - 1; i >= 0; i--){
    swap(A[0], A[i]);
    max_heapify(A, 0, i);
  }
}
//uses recursion to print the heap
void printHeap(int A[100], int n, int start, int nodeCount){
  for(int i = 0; i < n; i++){
    if(!(start + i >= nodeCount)){
      cout << A[start + i] << "  ";
    }else{
      return;
    }
  }
  cout << endl;
  printHeap(A, n + 1, start + n, nodeCount);
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
    return 0;
  }
  //cout << nodeCount << endl;
  heapSort(numbers, nodeCount);
  cout << "Printing sorted" << endl;
  for(int i = nodeCount - 1; i >= 0; i--){
    cout << numbers[i] << " ";
  }
  cout << endl;
}
