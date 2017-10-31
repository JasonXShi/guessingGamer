/*Kevin Men
Student List
Allows the user to create a list of students
10/23/17
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student {

  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};



//function declaration
Student* addStudent(char firstName[20], char lastName[20], int id, float gpa);
void deleteStudent(vector<Student*> &v, int inputID);
void printList(vector<Student*> v);

int main(){
  //input command and playing state
  char command[10];
  bool quit = false;
  //vector to keep track of students
  //vector help from: http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm
  vector<Student*> v;
  //characteristics of a student
  char firstName[20];
  char lastName[20];
  int id;
  int inputID;
  float gpa;
  //introduction
  cout << "Welcome to student list, here are the commands" << endl;
  cout << "ADD- add a student to the lsit" << endl;
  cout << "DELETE- delete a student from the list" << endl;
  cout << "PRINT- prints out all the students in the list" << endl;
  cout << "QUIT- quits the program" << endl;
  while(!quit){
    //takes in a command
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD") == 0){
      //if they type add, ask for the student's information
      cout << "What is the student's name?" << endl;
      cin.getline(firstName, 20, '\n');
      cout << "What is the student's last name?" << endl;
      cin.getline(lastName, 20, '\n');
      cout << "What is the student's id number?" << endl;
      cin >> id;
      cin.get();
      cout << "What is the student's GPA?" << endl;
      cin >> gpa;
      cin.get();
      v.push_back(addStudent(firstName, lastName, id, gpa));
    }else if(strcmp(command, "DELETE") == 0){
      //if they type DELETE, ask for the id of the student they want to delete
      cout << "What is the id number of the student you want to delete?" << endl;
      cin >> inputID;
      cin.get();
      deleteStudent(v, inputID);
    }else if(strcmp(command, "PRINT") == 0){
      //prints out list of students
      printList(v);
    }else if(strcmp(command, "HELP") == 0){
      //tells the commands
      cout << "Here are the commands:" << endl;
      cout << "ADD, DELETE, PRINT, HELP" << endl;
    }else if(strcmp(command, "QUIT") == 0){
      //quits the program
      quit = true;
    }else{
      //if they don't input a valid command
      cout << "NOT A VALID COMMAND" << endl;
      cout << "For help, enter HELP" << endl;
    }
  }
  return 0;
}
//adds a student to the vector
Student* addStudent(char firstName[20], char lastName[20], int id, float gpa){
  Student* pNewStudent = new Student;
  //copies all the information into a student
  for(int i = 0; i < 20; i++){
  pNewStudent->firstName[i] = firstName[i];
  pNewStudent->lastName[i] = lastName[i];
  }
  pNewStudent->id = id;
  pNewStudent->gpa = gpa;
}
//deletes a student
//iterator help from: https://stackoverflow.com/questions/33218031/print-a-vector-using-iterator-c
void deleteStudent(vector<Student*> &v, int inputID){
  //loops through the vector, finds the student, and deletes it
  for(vector<Student*>::iterator it = v.begin(); it!=v.end(); ++it){
    if((*it)->id == inputID){
      delete(*it);
      v.erase(it);
      break;
    }
  }
}
//prints out all the students
void printList(vector<Student*> v){
  //round to 2 decimal places
  cout << fixed;
  cout << setprecision(2);
  //loops through the vector and prints out all the students
  for(vector<Student*>::iterator it = v.begin(); it!= v.end(); ++it){
    cout << (*it)-> firstName << " " << (*it)->lastName << ", " << (*it)->id << ", " << (*it)->gpa << endl;
  }
}

  


