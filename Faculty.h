//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Person.h"
#include "SinglyLinkedList.h"

class Faculty : public Person
{
public:
  Faculty();//default constructor
  Faculty(string d);//overload constructor
  ~Faculty();//deconstructor

  //core functions
  void printInfo();
  //aux functions
  void addAdvisee(int ID);
  void removeAdvisee(int ID);

private:
  //vars
  string department;
  SinglyLinkedList advisees;
}
