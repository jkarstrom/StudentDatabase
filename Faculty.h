//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
#include "SinglyLinkedList.h"

class Faculty:public Person
{
public:
  Faculty();//default constructor
  Faculty(int i, string n, string l, string d);//overload constructor
  ~Faculty();//deconstructor

  //core functions
  void setDepartment(string d);

  void addAdvisee(int id);
  void removeAdvisee(int id);

  //aux functions
  void fillInfo();
  void printAd();
  void printInfo();

  void transfer(Faculty* soul);

  SinglyLinkedList* getAdvisees();
  void copyAdvisee(SinglyLinkedList* a);
  bool isAdvisor();

private:
  //vars
  string department;
  SinglyLinkedList* adviseeList;
};

#endif
