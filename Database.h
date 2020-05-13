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
    void importFiles()
    void outputFaculty(TreeNode<Faculty> *fac, string fileName);
    void outputStudent(TreeNode<Student> *stu, string fileName);

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
