#include "Database.h"

Database::Database(){

}

Database::~Database(){

}

Database::run(){
    // print menu
    cout << "Main Menu" << endl;
    cout << "(1) Print all students and their information" << endl;
    cout << "(2) Print all faculty and their information" << endl;
    cout << "(3) Print a student's information" << endl;
    cout << "(4) Print a faculty member's information" << endl;
    cout << "(5) Find a student's faculty advisor" << endl;
    cout << "(6) Find all advisees of a faculty member" << endl;

    cout << "(7) Add a new student" << endl;
    cout << "(8) Delete a student" << endl;

    cout << "(9) Add a new faculty member" << endl;
    cout << "(10) Delete a faculty member" << endl;

    cout << "(11) Change a student's advisor" << endl;
    cout << "(12) Remove an advisee from a faculty member" << endl;
    
    cout << "(13) Rollback" << endl;
    cout << "(14) Exit" << endl;
    // update Rollback
    cin >> userAction;




}
