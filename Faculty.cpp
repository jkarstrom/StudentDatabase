//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database


#include "Faculty.h"


Faculty::Faculty():Person()
{
    department = "";
    adviseeList = new SinglyLinkedList();
}

Faculty::Faculty(int i, string n, string l, string d):Person(i, n, l)
{
    department = d;
    adviseeList = new SinglyLinkedList();
}

Faculty::~Faculty()
{

}

void Faculty::addAdvisee(int id){
    adviseeList->insertFront(id);
}

void Faculty::removeAdvisee(int id){
    int pos = adviseeList->search(id);
    if(pos != -1)
        adviseeList->removeAtPos(pos);
}

void Faculty::printAdvisees(){
    cout << "Advisees:" << endl;
    adviseeList->printList();
}

void Faculty::printInfo(){
    Person::printInfo();
    cout << "Department: " << department << endl;
    printAdvisees();
    cout << endl;
}

int main(){
    Faculty *me = new Faculty(111,"Rene","Professor","Fowler");
    me->addAdvisee(1234);
    me->addAdvisee(2345);
    me->removeAdvisee(1234);
    me->printInfo();

    delete me;
    return 0;
}
