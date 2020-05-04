//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include <iostream>

using namespace std;

class Student
{
public:

  Student();//defalt constructor
  Student(string m, double g, int a);//overload constructor
  ~Student();//deconstructor

  //core functions

  //aux functions

private:
  //vars
  string major;
  double gpa;
  int advisor;

}
