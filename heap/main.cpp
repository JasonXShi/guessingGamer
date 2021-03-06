/*
Kevin Men
C++ Programming
Heap
Constructs a max heap from a user input or file input
3/1/18
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

void printHeap(int A[100], int n, int start, int nodeCount);
//satisfied the properties of a max heap
void max_heapify(int (&A)[100], int i, int nodeCount){
  //left and right child of i
  int l = (2*i) + 1;
  int r = (2*i) + 2;
  //variable to keep track of whether the parent or child is larger
  int largest = i;
  if(l < nodeCount && A[l] > A[i]){
    largest = l;
  }
  if(r < nodeCount && A[r] > A[largest]){
    largest = r;
  }
  if(largest != i){
    //if the child is larger than the parent, swap them and repeat process until it is not true
    swap(A[i], A[largest]);
    max_heapify(A, largest, nodeCount);
  }
  //if the child is smaller than the parent, return
}
//build the heap by editting the original array
void build_max_heap(int (&A)[100], int nodeCount){
  int heapSize = nodeCount;
  //we use the length/2+1 because that is the number of numbers that will be a parent node
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
  //swaps with head, as that is garenteed to be the largest value, remove it from the heap, then continue
  for(int i = nodeCount - 1; i >= 0; i--){
    swap(A[0], A[i]);
    max_heapify(A, 0, i);
  }
}
//uses recursion to print the heap
/*
The parent-child relationship is represented by the depth and location of each number
The first line contains 1 number, which represents the head
The second line contains up to 2 numbers, which represent the left and right child
The third line contains up to 4 numbers. The first two numbers represent the left and right child of the first number from line 2. The other two numbers represent the left and right child of the second number from line 2
This pattern continues for any additional lines 
*/
void printHeap(int A[100], int n, int start, int nodeCount){
  for(int i = 0; i < n; i++){
    if(!(start + i >= nodeCount)){
      cout << A[start + i] << "  ";
    }else{
      return;
    }
  }
  cout << endl;
  printHeap(A, n * 2, start + n, nodeCount);
}
int main(){
  int response;
  char input[500];
  int numbers[100];
  int nodeCount = 0;
  char fileName[20];
  ifstream inFile;
  cout << "Enter 1 for manual input, and 2 for file input" << endl;
  cin >> response;
  cin.get();
  if(response == 1){
    //inputs number from the user and splits their input by a space
    cout << "Enter your numbers separated by spaces: " << endl;
    cin.getline(input, 500, '\n');
  }else if(response == 2){
    //reads in numbers from the file the user provided
    cout << "Enter the name of the file that will be used for the input" << endl;
    //reads in the contents of the file they provide
    cin.getline(fileName, 20, '\n');
    inFile.open(fileName);
    if(!inFile){
      //if the file does not exist, exit the program
      cout << "File does not exist!" << endl;
      return 0;
    }
    inFile.getline(input, 500, '\n');
  }else{
    //not a valid response, exits the program
    cout << "NOT A VALID RESPONSE" << endl;
    return 0;
  }
  //splits input by spaces
  char* split;
  split = strtok(input, " ");
  while(split != NULL){
    numbers[nodeCount] = atoi(split);
    nodeCount++;
    split = strtok(NULL, " ");
  }
  //creates a max heap, then sorts the array
  heapSort(numbers, nodeCount);
  cout << "Printing sorted" << endl;
  for(int i = nodeCount - 1; i >= 0; i--){
    cout << numbers[i] << " ";
  }
  cout << endl;
}
/*
Acknoledgements:
input from file- University of Wollongong
heap functions help- crazyforcode.com
 */
