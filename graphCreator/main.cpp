/*
Graph Creator
Kevin Men
Allows the user to create a directed graph
5/29
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct vertex{
  char* label;
  vector<vertex*> edges;
  vector<int> weights;
};

void print(vector<vertex*> v);
  
int main(){
  cout << "Welcome to graph creator!" << endl;
  vector<vertex*> v;
  while(true){
    cout << "Type 'PRINT' to print out the adjacency matrix" << endl;
    cout << "Type 'VERTEX' to add a vertex" << endl;
    cout << "Type 'EDGE' to add an edge" << endl;
    cout << "Type 'DELETE VERTEX' to delete a vertex" << endl;
    cout << "Type 'DELETE EDGE' to delete an edge" << endl;
    cout << "Type 'PATH' to find the shortest path between two vertices" << endl;
    cout << "Type 'QUIT' to exit the program" << endl;
    char input[20];
    cin.getline(input, 20, '\n');
    if(strcmp(input, "PRINT") == 0){
      //print adjacency matrix
      print(v);
    }else if(strcmp(input, "VERTEX") == 0){
      //insert a vertex
      char* labelName = new char();
      cout << "Enter the label for the vertex" << endl;
      cin >> labelName;
      cin.get();
      vertex* tempNode = new vertex();
      tempNode->label = labelName;
      v.push_back(tempNode);
    }else if(strcmp(input, "EDGE") == 0){
      //insert an edge
      vertex* first = NULL;
      vertex* second = NULL;
      char firstLabel[10];
      char secondLabel[10];
      int value;
      cout << "Enter the base vertex" << endl;
      cin.getline(firstLabel, 10, '\n');
      cout << "Enter the vertex it's being connected to" << endl;
      cin.getline(secondLabel, 10, '\n');
      cout << "Enter the weight of the edge" << endl;
      cin >> value;
      cin.get();
      for(vector<vertex*>::iterator it = v.begin(); it != v.end(); ++it){
	if(strcmp((*it)->label, firstLabel) == 0){
	  first = *it;
	}else if(strcmp((*it)->label, secondLabel) == 0){
	  second = *it;
	}
      }
      if(first == NULL || second == NULL){
	cout << "INVALID EDGE" << endl;
      }else{
	first->edges.push_back(second);
	first->weights.push_back(value);
      }
    }else if(strcmp(input, "DELETE VERTEX") == 0){
      //delete a vertex
    }else if(strcmp(input, "DELETE EDGE") == 0){
      //delete an edge
    }else if(strcmp(input, "PATH") == 0){
      //finds the shortest path between two vertices
    }else if(strcmp(input, "QUIT") == 0){
      //exits the program
      break;
    }else{
      //invalid input
      cout << "INVALID INPUT" << endl;
    }
  }//while loop
  
}//main
void print(vector<vertex*> v){
  for(vector<vertex*>::iterator it = v.begin();it != v.end(); ++it){
    cout << "\t" << (*it)->label;
  }
  cout << endl;
}
