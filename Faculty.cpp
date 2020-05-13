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

void Faculty::setDepartment(string d){
    department = d;
}

void Faculty::addAdvisee(int id){
    adviseeList->insertFront(id);
}

void Faculty::removeAdvisee(int id){
    int pos = adviseeList->search(id);
    if(pos != -1)
        adviseeList->removeAtPos(pos);
}

void Faculty::fillInfo()
{
    Person::fillInfo();
    cout << "Enter the department: ";
    cin >> department;
    cout << "Faculty member created. You may now assign advisees to this faculty member." << endl;
}

void Faculty::printAd(){
    cout << "Advisees:" << endl;
    adviseeList->printList();
}

void Faculty::printInfo()
{
    Person::printInfo();
    cout << "Department: " << department << endl;
    printAd();
    cout << endl;
}

void Faculty::transfer(Faculty* soul){
    Person::transfer(soul);
    soul->setDepartment(department);
    soul->copyAdvisee(adviseeList);
}

SinglyLinkedList* Faculty::getAdvisees(){
    return adviseeList;
}

void Faculty::copyAdvisee(SinglyLinkedList* a){
    *adviseeList = *a;
}

bool Faculty::isAdvisor(){
    return (!adviseeList->isEmpty());
}
