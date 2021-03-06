//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Databases

#include "Database.h"

Database::Database(){
    masterFaculty = new BST<Faculty>();
    masterStudent = new BST<Student>();
    history = new Rollback();
    running = true;
}

Database::~Database(){

}

void Database::makeTrees(){
    // check if files for trees are already there, if so, update

}

void Database::run(){
    // look for trees


    // print menu
    printMenu();

    // make user's selection
    cin >> userAction;

    if(userAction == 1)
        masterStudent->printTree(masterStudent->getRoot());
    else if(userAction == 2)
        masterFaculty->printTree(masterFaculty->getRoot());
    else if(userAction == 3 || userAction == 5){
        cout << "Enter student id: ";
        cin >> someID;
        masterStudent->search(someID, userAction);
    }
    else if(userAction == 4 || userAction == 6){
        cout << "Enter faculty id: ";
        cin >> someID;
        masterFaculty->search(someID, userAction);
    }

    // add transaction to rollback
    else if(userAction >= 7 && userAction <= 12){
        Transaction* myMove = new Transaction(userAction);
        myMove->proceed(masterStudent, masterFaculty);
        myMove->reverse();
        history->update(myMove);
    }
    else if(userAction == 13){
        // rollback
        Transaction* myReverse = history->goBack();
        myReverse->proceed(masterStudent, masterFaculty);
        delete myReverse;
    }
    else if(userAction == 14)
        running = false;

}

bool Database::isRunning(){
    return running;
}


void Database::printMenu(){
    cout << endl << "Main Menu" << endl;
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
}
