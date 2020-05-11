//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include <iostream>

using namespace std;

class Person
{
public:

  Person();//default constructor
  Person(int i, string n, string l);//overload constructor
  ~Person();//deconstructor

  //core functions
  int getID();
  string getName();
  string getLevel();
  void setLevel();
  //aux functions
  void printInfo();

protected:
  //vars
  int id;
  string name;
  string level;
};
