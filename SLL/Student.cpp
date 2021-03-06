//student class
#include "student.h"
//creates a new student
student::student(char* newFirstName, char* newLastName, int newID, float newGPA){
  firstName = newFirstName;
  lastName = newLastName;
  ID = newID;
  GPA = newGPA;
}
//getters and setters
char* student::getFirstName(){
  return firstName;
}
char* student::getLastName(){
  return lastName;
}
int student::getID(){
  return ID;
}
float student::getGPA(){
  return GPA;
}
//destructor
student::~student(){
  delete firstName;
  delete lastName;
  delete &ID;
  delete &GPA;
}
