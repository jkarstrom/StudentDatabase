//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database


#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:

  Person();//default constructor
  Person(int i, string n, string l);//overload constructor
  ~Person();//deconstructor

  //core functions
  int getID();
  void setID(int i);
  string getName();
  void setName(string n);
  string getLevel();
  void setLevel(string l);
  //aux functions
  void fillInfo();
  void printInfo();

  void transfer(Person* soul);

protected:
  //vars
  int id;
  string name;
  string level;
};

#endif
