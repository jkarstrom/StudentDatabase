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

int Student::getAdvisor(){
    return advisorID;
}

void Student::setAdvisor(int id){
    advisorID = id;
}

void Student::printInfo(){
    Person::printInfo();
    cout << "Major: " << major << endl;
    cout << "GPA:" << gpa << endl;
    cout << "Advisor: " << advisorID << endl;
    cout << endl;
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
