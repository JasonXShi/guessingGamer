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

//struct for the vertices
struct vertex{
  char* label;
  vector<vertex*> edges;
  vector<int> weights;
};

void print(vector<vertex*> v);
void deleteVertex(vector<vertex*> &v, char* name);
void deleteEdge(vector<vertex*> &v, char a[], char b[]);
void path(vector<vertex*> v, char a[], char b[]);

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
      //reads in the name of the two vertices to be connected
      cout << "Enter the base vertex" << endl;
      cin.getline(firstLabel, 10, '\n');
      cout << "Enter the vertex it's being connected to" << endl;
      cin.getline(secondLabel, 10, '\n');
      cout << "Enter the weight of the edge" << endl;
      cin >> value;
      cin.get();
      //checks to make sure they are both in the vector
      for(vector<vertex*>::iterator it = v.begin(); it != v.end(); ++it){
	if(strcmp((*it)->label, firstLabel) == 0){
	  first = *it;
	}else if(strcmp((*it)->label, secondLabel) == 0){
	  second = *it;
	}
      }
      //if one or more of the inputs were not found
      if(first == NULL || second == NULL){
	cout << "INVALID EDGE" << endl;
      }else{
	//connects to two vertecies
	first->edges.push_back(second);
	first->weights.push_back(value);
      }
    }else if(strcmp(input, "DELETE VERTEX") == 0){
      //delete a vertex
      char* deleteName;
      cout << "Enter the name of the vertex you would like to delete" << endl;
      cin >> deleteName;
      cin.get();
      deleteVertex(v, deleteName);
    }else if(strcmp(input, "DELETE EDGE") == 0){
      //delete an edge
      char start[10];
      char end[10];
      cout << "Enter the name of the starting vertex" << endl;
      cin.getline(start, 10, '\n');
      cout << "Enter the name of the ending vertex" << endl;
      cin.getline(end, 10, '\n');
      deleteEdge(v, start, end);
    }else if(strcmp(input, "PATH") == 0){
      //finds the shortest path between two vertices
      char start[10];
      char end[10];
      cout << "Enter the starting vertex: " << endl;
      cin.getline(start, 10, '\n');
      cout << "Enter the ending vertex: " << endl;
      cin.getline(end, 10, '\n');
    }else if(strcmp(input, "QUIT") == 0){
      //exits the program
      break;
    }else{
      //invalid input
      cout << "INVALID INPUT" << endl;
    }
  }//while loop
  
}//main
//prints out the adjacency matrix
void print(vector<vertex*> v){
  //prints out the top row (the name of all the nodes
  for(vector<vertex*>::iterator it = v.begin();it != v.end(); ++it){
    cout << "\t" << (*it)->label;
  }
  for(vector<vertex*>::iterator it = v.begin();it != v.end(); ++it){
    cout << endl;
    //prints out the row labels
    cout << (*it)->label;
    vector<vertex*> connect = (*it)->edges;
    vector<int> length = (*it)->weights;
    for(vector<vertex*>::iterator it2 = v.begin();it2 != v.end(); ++it2){
      int count = 0;
      bool found = false;
      //if this vertex is not connected to anything, print 0 (no connections)
      if(connect.empty()){
	cout << "\t" << "0";
      }else{
	for(vector<vertex*>::iterator it3 = connect.begin();it3 != connect.end(); ++it3){
	  count++;
	  //loops through the connected vector, if one of the connected vertexes in the row is the column, print out the value of the edge
	  if((*it3)->label == (*it2)->label){
	    cout << "\t" << length.at(count-1);
	    found = true;
	  }
	}
	if(!found){
	  //no connections were found from row to column
	  cout << "\t" << "0";
	}
      }
    }
  }
  cout << endl;
}
//delets a vertex and all edges to it
void deleteVertex(vector<vertex*> &v, char* name){
  vertex* n = NULL;
  //loops through vector and searches for a vertex matching the input
  for(vector<vertex*>::iterator it = v.begin(); it != v.end(); ++it){
    if(strcmp((*it)->label, name) == 0){
      n = (*it);
      cout << "erasing..." << (*it)->label << endl;
      //removes the vertex
      v.erase(it);
      break;
    }
  }
  //if the vertex was not found
  if(n == NULL){
    cout << "VERTEX NOT FOUND" << endl;
    return;
  }
  //loops through the remaining vertices
  for(vector<vertex*>::iterator it = v.begin(); it != v.end(); ++it){
    vector<vertex*> connect = (*it)->edges;
    vector<int> length = (*it)->weights;
    int count = 0;
    for(vector<vertex*>::iterator it2 = connect.begin(); it2 != connect.end(); ++it2){
      //if any of them were connected to the vertex being deleted, remove those connections
      count++;
      if((*it2) == n){
	connect.erase(it);
	length.erase(length.begin()+(count - 1));
	break;
      }
    }
  }
  //deletes n
  delete n;
}
//removes an edge between two vertices
void deleteEdge(vector<vertex*> &v, char a[], char b[]){
  vertex* first = NULL;
  vertex* second = NULL;
  //searches for the start and ending vertex in the vector
  for(vector<vertex*>::iterator it = v.begin(); it != v.end();++it){
    cout << (*it)->label << endl;
    if(strcmp((*it)->label, a) == 0){
      first = (*it);
    }
    if(strcmp((*it)->label, b) == 0){
      second = (*it);
    }
  }
  //if one or more of the input were not found
  if(first == NULL || second == NULL){
    cout << "INVALID VERTICES" << endl;
    return;
  }
  vector<vertex*> connected1 = first->edges;
  vector<int> length1 = first->weights;
  int count = 0;
  bool found = false;
  //loops through the connections of the first vertex
  for(vector<vertex*>::iterator it = connected1.begin(); it != connected1.end(); ++it){
    count++;
    cout << (*it)->label << endl;
    //if there is an edge from the starting vertex to the ending vertex, delete it
    if((*it) == second){
      found = true;
      connected1.erase(it);
      length1.erase(length1.begin()+(count-1));
      first->edges = connected1;
      first->weights = length1;
      break;
    }
  }
  //if there is no edge
  if(!found){
    cout << "That edge does not exist!" << endl;
  }
}
void path(vector<vertex*> &v, char a[], char b[]){
  vertex* start = NULL;
  vertex* end = NULL;
  //finds the target vertecies in the vector
  for(vector<vertex*>::iterator it = v.begin(); it != v.end();++it){
    if(strcmp((*it)->label, a) == 0){
      start = (*it);
    }
    if(strcmp((*it)->label, b) == 0){
      end = (*it);
    }
  }
  //Dijsktra's Algorithm to find the shortest path
  vector<vector<vertex*>> sptSet; //vector used in place of tree set, keeps track of vertices included in the shortest path
  vector<vertex*> connected;
  vector<int> length;
  sptSet.begin().push_back(start);
  while(true){
    
  }
}
