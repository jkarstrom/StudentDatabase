#ifndef DATABASE_H
#define DATABASE_H
#include "BST.h"
#include "Transaction.h"
#include "Rollback.h"

class Database{
public:
    Database();
    ~Database();

    void makeTrees();

    void run();
    void printMenu();

private:
    BST<Faculty>* masterFaculty;
    BST<Student>* masterStudent;
    Rollback* history;

    int userAction;
    int someID;


};

#endif
