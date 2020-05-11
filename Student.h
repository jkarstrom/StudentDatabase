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
  Student(string m, double g, int a);//overload constructor
  ~Student();//deconstructor

  //core functions
  void setAdvisor(int id);
  void printInfo();
  //aux functions
  bool operator<(Student &original, Student &other);
  bool operator>(Student &original, Student &other);
  bool operator==(Student &original, Student &other);

private:
  //vars
  string major;
  double gpa;
  int advisorID;

}
