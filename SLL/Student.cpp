#include "Student.h"

Student::Student(char* newFirstName, char* newLastName, int newID, float newGPA){
  firstName = newFirstName;
  lastName = newLastName;
  ID = newID;
  GPA = newGPA;
}
char* Student::getFirstName(){
  return firstName;
}
char* Student::getLastName(){
  return lastName;
}
int Student::getID(){
  return ID;
}
float Student::getGPA(){
  return GPA;
}
Student::~Student(){
  delete firstName;
  delete lastName;
  delete &ID;
  delete &GPA;
}
