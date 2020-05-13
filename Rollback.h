//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef ROLLBACK_H
#define ROLLBACK_H

#include "GenStack.h"
#include "Transaction.h"

class Rollback{
public:
    Rollback();
    ~Rollback();

    void update(Transaction* t);
    Transaction* goBack();

private:
    GenStack<Transaction>* myActions;
};

#endif
