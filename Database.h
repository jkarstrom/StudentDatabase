#include "BST.h"
#include "Transaction.h"
#include "Rollback.h"

class Database{
public:
    Database();
    ~Database();

    void run();

private:
    BST masterFaculty;
    BST masterStudent;

    int userAction;


};
