//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Student.h"

using namespace std;

//default constructor
Student::Student():Person()
{
    major = "";
    gpa = 0;
    advisorID = 0;
}

Student::Student(int i, string n, string l, string m, double g, int a):Person(i, n, l)
{
    major = m;
    gpa = g;
    advisorID = a;
}

//deconstructor
Student::~Student()
{

}

bool Student::operator<(const Student& other){
    return (id < other.id);
}

bool Student::operator>(const Student& other){
    return (id > other.id);
}

bool Student::operator==(const Student& other){
    return (id == other.id);
}

void Student::setMajor(string m){
    major = m;
}

void Student::setGPA(double g){
    gpa = g;
}

int Student::getAdvisor(){
    return advisorID;
}

void Student::setAdvisor(int id){
    advisorID = id;
}

void Student::fillInfo()
{
    Person::fillInfo();
    cout << "Enter the major: ";
    cin >> major;
    cout << "Enter the GPA: ";
    cin >> gpa;
    cout << "Enter the advisor ID: ";
    cin >> advisorID;
}

void Student::printInfo(){
    Person::printInfo();
    cout << "Major: " << major << endl;
    cout << "GPA:" << gpa << endl;
    cout << "Advisor: " << advisorID << endl;
    cout << endl;
}

void Student::transfer(Student* soul){
    Person::transfer(soul);
    soul->setMajor(major);
    soul->setGPA(gpa);
    soul->setAdvisor(advisorID);

}
