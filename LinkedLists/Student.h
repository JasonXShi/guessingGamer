#ifndef STUDENT_H
#define STUDENT_H

class Student{
 public:
  Student(const char* newName, int newID);
  ~Student();
  const char* getName();
  int getID();
 private:
  const char* name;
  int ID;
};
#endif
