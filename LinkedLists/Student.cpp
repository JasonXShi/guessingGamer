#include "Student.h"

Student::Student(const char* newName, int newID){
  name = newName;
  ID = newID;
}
Student::~Student(){
  delete name;
  delete &ID;
}
const char* Student::getName(){
  return name;
}
int Student::getID(){
  return ID;
}
