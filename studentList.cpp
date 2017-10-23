#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {

  char firstName[20];
  char lastName[20];
  int id;
  float gpa;

};

Student* addStudent(char firstName[20], char lastName[20], int id, float gpa);
void deleteStudent();
void printList(vector<Student*> v);

int main(){

  char command[10];
  bool quit = false;
  vector<Student*> v;
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
  while(!quit){
    cout << "Enter a command" << endl;
    cin.getline(command, 10, '\n');
    if(strcmp(command, "ADD") == 0){
      cout << "ADD" << endl;
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
      cout << "DELETE" << endl;
      deleteStudent();
    }else if(strcmp(command, "PRINT") == 0){
      cout << "PRINT" << endl;
      printList(v);
    }else if(strcmp(command, "HELP") == 0){
      cout << "Here are the commands:" << endl;
      cout << "ADD, DELETE, PRINT, HELP" << endl;
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
void deleteStudent(){

}
void printList(vector<Student*> v){
  for(vector<Student*>::iterator it = v.begin(); it!= v.end(); ++it)
    cout << (*it)-> firstName << endl;
}
  

