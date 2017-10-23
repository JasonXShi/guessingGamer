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


/*Still need to add:
-comments
-rounding gpa to 2 decimal places
-final check
 */

Student* addStudent(char firstName[20], char lastName[20], int id, float gpa);
void deleteStudent(vector<Student*> &v, int inputID);
void printList(vector<Student*> v);

int main(){

  char command[10];
  bool quit = false;
  vector<Student*> v;
  char firstName[20];
  char lastName[20];
  int id;
  int inputID;
  float gpa;
  cout << "Welcome to student list, here are the commands" << endl;
  cout << "ADD- add a student to the lsit" << endl;
  cout << "DELETE- delete a student from the list" << endl;
  cout << "PRINT- prints out all the students in the list" << endl;
  cout << "QUIT- quits the program" << endl;
  while(!quit){
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD") == 0){
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
      cout << "What is the id number of the student you want to delete?" << endl;
      cin >> inputID;
      cin.get();
      deleteStudent(v, inputID);
    }else if(strcmp(command, "PRINT") == 0){
      printList(v);
    }else if(strcmp(command, "HELP") == 0){
      cout << "Here are the commands:" << endl;
      cout << "ADD, DELETE, PRINT, HELP" << endl;
    }else if(strcmp(command, "QUIT") == 0){
      quit = true;
    }else{
      cout << "NOT A VALID COMMAND" << endl;
      cout << "For help, enter HELP" << endl;
    }
  }
  return 0;
}
Student* addStudent(char firstName[20], char lastName[20], int id, float gpa){
  Student* pNewStudent = new Student;
  for(int i = 0; i < 20; i++){
  pNewStudent->firstName[i] = firstName[i];
  pNewStudent->lastName[i] = lastName[i];
  }
  pNewStudent->id = id;
  pNewStudent->gpa = gpa;
}
void deleteStudent(vector<Student*> &v, int inputID){
  for(vector<Student*>::iterator it = v.begin(); it!=v.end(); ++it){
    if((*it)->id == inputID){
      delete(*it);
      v.erase(it);
      break;
    }
  }
}
void printList(vector<Student*> v){
  cout << fixed;
  cout << setprecision(2);
  for(vector<Student*>::iterator it = v.begin(); it!= v.end(); ++it){
    cout << (*it)-> firstName << " " << (*it)->lastName << ", " << (*it)->id << ", " << (*it)->gpa << endl;
  }
}
  


