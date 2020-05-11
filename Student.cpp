//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Student.h"

using namespace std;

//default constructor
Student::Student()
{
    majojr = "";
    gpa = 0;
    advisorID = 0;
}

Student::Student(int i, string n, string l, string m, double g, int a)
{
    Person::Person(int i, string n, string l);
    major = m;
    gpa = g;
    advisorID = a;
}

//overload constructor
Student::Student();
{

}

//deconstructor
Student::~Student()
{

}

void Student::setAdvisor(int id){
    advisorID = a;
}

void Student::printInfo(){
    Person::printInfo();
    cout << "Major: " << major << endl;
    cout << "GPA:" << gpa << endl;
    cout << "Advisor: " << advisorID << endl;
}

bool Student::operator<(Student &original, Student &other){
    return (original.getID() < other.getID());
}

bool Student::operator>(Student &original, Student &other){
    return (original.getID() < other.getID());
}

bool Student::operator==(Student &original, Student &other){
    return (original.getID() == other.getID());
}

int main(){
    Student *me = new Student("111","April","Soph","CS", 4.0, "0000");
    Student *you = new Student("112","May","Fresh","DA", 3.9, "0000");
    cout << me == you << endl;
    return 0;
}
