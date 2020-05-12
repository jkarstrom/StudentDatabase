//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student:public Person
{
public:

  Student();//defalt constructor
  Student(int i, string n, string l, string m, double g, int a);//overload constructor
  ~Student();//deconstructor

  //core functions
  bool operator<(const Student& other);
  bool operator>(const Student& other);
  bool operator==(const Student& other);
  void setMajor(string m);
  void setGPA(double g);
  int getAdvisor();
  void setAdvisor(int id);

  //aux functions
  void fillInfo();
  void printInfo();

  void transfer(Student* soul);

private:
  //vars
  string major;
  double gpa;
  int advisorID;

};

#endif
