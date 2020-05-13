//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Person.h"

Person::Person()
{
  //default constructor
  id = 0;
  name = "";
  level = "";
}

//overload constructor
Person::Person(int i, string n, string l)
{
  id = i;
  name = n;
  level = l;
}

//deconstructor
Person::~Person()
{

}

void Person::fillInfo(){
    cout << "Enter the ID: ";
    cin >> id;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the level: ";
    cin >> level;
}

int Person::getID(){
    return id;
}

void Person::setID(int i){
    id = i;
}

string Person::getName(){
    return name;
}

void Person::setName(string n){
    name = n;
}

string Person::getLevel(){
    return level;
}

void Person::setLevel(string l){
    level = l;
}

void Person::printInfo(){
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}

void Person::transfer(Person* soul){
    soul->setID(id);
    soul->setName(name);
    soul->setLevel(level);
}
