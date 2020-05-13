//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef DATABASE_H
#define DATABASE_H
#include "BST.h"
#include "Transaction.h"
#include "Rollback.h"
#include "FileIO.h"

class Database{
public:
    Database();
    ~Database();

    void makeTrees();

    void run();
    void printMenu();

    bool isRunning();

private:
    BST<Faculty>* masterFaculty;
    BST<Student>* masterStudent;
    Rollback* history;

    int userAction;
    int someID;

    bool running;


};

#endif
