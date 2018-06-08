/*
Kevin Men
C++ Programming
Hash Table
Allows the user to create a list of students using a hash table
6/8/18
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

//struct to store a student's data
struct student{
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};
//struct used for the linked lists in the hash table
struct node{
  student* value = NULL;
  node* next = NULL;
};

//function prototypes
int hash(int id, int size);
void rehash(node* newHash[], node* oldHash[]);
void print(node* table[], int size);
student* create(char* firstName, char* lastName, int id, float gpa);
bool add(node* hashTable[], int index, student* s);
void deleteStudent(node* hashTable[], int id, int size);

int main(){
  cout << "Welcome to hash table!" << endl;
  char input[10];
  node* hashTable[100]; //hash table
  vector<int> ids; //stores all student ids to make sure we don't have duplicates
  for(int i = 0; i < 100; i++){
    hashTable[i] = NULL;
  }
  int size = 100;
  ifstream inFile;
  char fileName[20];
  char* fileInput;
  char* split;
  cout << "Enter the file name for first names" << endl;
  cin.getline(fileName, 20, '\n');
  inFile.open(fileName);
  if(!inFile){
    cout << "file does not exist!" << endl;
    return 0;
  }
  inFile.getline(fileInput, 1000, '\n');
  split = strtok(fileInput, " ");
  while(split != NULL){
    
  }
  while(true){
    cout << "Type 'add' to manual add a student to the list" << endl;
    cout << "Type 'rand' to generate a random student" << endl;
    cout << "Type 'print' to print out all the students" << endl;
    cout << "Type 'delete' to delete a student from the list" << endl;
    cout << "Type 'quit' to exit the program" << endl;
    cin.getline(input, 10, '\n');
    if(strcmp(input, "add") == 0){
      //add a student into the list
      student* s;
      int id;
      float gpa;
      char* firstName = new char(30);
      char* lastName = new char(30);
      //gets the information for the new student
      cout << "Enter the student's first name" << endl;
      cin.getline(firstName, 30, '\n');
      cout << "Enter the student's last name" << endl;
      cin.getline(lastName, 30, '\n');
      cout << "Enter the student's id number" << endl;
      cin >> id;
      cin.get();
      cout << "Enter the student's gpa " << endl;
      cin >> gpa;
      cin.get();
      s = create(firstName, lastName, id, gpa);
      int index = hash(id, size);
      bool valid = add(hashTable, index, s);
      if(!valid){
	//need to rehash the table
      }
    }else if(strcmp(input, "rand") == 0){
      //randomly generate a new student
      int loop;
      cout << "How many students would you like to add?" << endl;
      cin >> loop;
      cin.get();
      for(int i = 0; i < loop; i++){
	
      }
    }else if(strcmp(input, "print") == 0){
      //print out the list of students
      print(hashTable, size);
    }else if(strcmp(input, "delete") == 0){
      //deletes a student from the list
      int id;
      cout << "Enter the ID of the student to be deleted" << endl;
      cin >> id;
      cin.get();
      ids.push_back(id);
      deleteStudent(hashTable, id, size);
    }else if(strcmp(input, "quit") == 0){
      //exits the program
      break;
    }else{
      //invalid input
      cout << "INVALID INPUT!" << endl;
    }
  } //while loop
} //main

//returns the hash value for a given id
int hash(int id, int size){
  //gets the sum of all the digits in the id
  int sum = 0;
  while(id != 0){
    sum = sum + id % 10;
    id = id / 10;
  }
  int multiplier = trunc(size/7);
  return ((sum  * multiplier) % size);
}

//creates a new student
student* create(char* firstName, char* lastName, int id, float gpa){
  student* temp = new student();
  //creates a new student
  temp->firstName = firstName;
  temp->lastName = lastName;
  temp->id = id;
  temp->gpa = gpa;
  return temp;
}

//adds a student into the has table
bool add(node* hashTable[], int index, student* s){
  //if we don't need to chain nodes together
  if(hashTable[index] == NULL){
    node* temp = new node();
    temp->value = s;
    hashTable[index] = temp;
    return true;
  }
  //if not, add this node to the beginning of the linked list
  node* current = hashTable[index];
  node* temp = new node();
  temp->next = current;
  temp->value = s;
  hashTable[index] = temp;
  current = temp;
  int count = 1;
  //checks to see how long the chain is
  while(current != NULL){
    current = current->next;
    count++;
  }
  //if we have more than 3 nodes in the chain, we need to rehash
  if(count > 3){
    //rehash
    return false;
  }else{
    //we don't need to rehash
    return true;
  }
}

//prints out the list of students
void print(node* table[], int size){
  //sets the precision to 2 decimal points
  cout << fixed;
  cout << setprecision(2);
  node* current;
  for(int i = 0; i < size; i++){
    if(table[i] != NULL){
      //makes sure there is a student at the index
      current = table[i];
      while(current != NULL){
	//while there are still students in the current chain, keep printing them out
	if(current->value != NULL){
	  cout << "First Name: " << current->value->firstName << endl;
	  cout << "Last Name: " << current->value->lastName << endl;
	  cout << "ID: " << current->value->id << endl;
	  cout << "GPA: " << current->value->gpa << endl;
	  cout << endl;
	}
	current = current->next;
	
      }
    }
  }
}

//deletes a student from the hash table
void deleteStudent(node* hashTable[], int id, int size){
  //finds which position in the hash table the given id is at
  int hashID = hash(id, size);
  node* current = hashTable[hashID];
  node* previous = NULL;
  //there are no nodes at the hashID
  if(current == NULL){
    cout << "Student not found! (nothing in hashID)" << endl;
    return;
  }
  //loops through the chain and searches for that id
  while(current != NULL){
    if(current->value->id == id){
      if(previous == NULL){
	//if there is only one node in the chain
	delete current;
	hashTable[hashID] = NULL;
      }else{
	//if there are multiple nodes in the chain
	previous->next = current->next;
	delete current;
      }
      return;
    }
    //keep looping though the chain until we find that id
    previous = current;
    current = current->next;
  }
  //the student was not found
  cout << "Student not found! (ID was not in hashID)" << endl;
  return;
}
