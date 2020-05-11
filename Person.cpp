//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Person.h"

Person::Person()
{
  //default constructor
}

//overload constructor
Person::Person(int i, string n, string l)
{
  id = i;
  name = n;
  level = l;
}

//deconstructor
Person::~Person
{

}

void Person::printInfo(){
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}
