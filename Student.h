//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database


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
  int getAdvisor();
  void setAdvisor(int id);

  //aux functions
  void printInfo();

private:
  //vars
  string major;
  double gpa;
  int advisorID;

};
