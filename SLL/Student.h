#ifndef STUDENT_H
#define STUDENT_H

class Student {
 public:
  Student(char* newFirstName, char* newLastName, int newID, float newGPA);
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  ~Student();
 private:
  char* firstName;
  char* lastName;
  int ID;
  float GPA;
};

#endif
