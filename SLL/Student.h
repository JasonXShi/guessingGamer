//header file for the student class
#ifndef STUDENT_H
#define STUDENT_H

class student {
 public:
  //constructor
  student(char* newFirstName, char* newLastName, int newID, float newGPA);
  //getters and setters
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  ~student();
 private:
  //member variables
  char* firstName;
  char* lastName;
  int ID;
  float GPA;
};
#endif
