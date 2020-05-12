#ifndef ROLLBACK_H
#define ROLLBACK_H

#include "GenStack.h"
#include "Transaction.h"

class Rollback{
public:
    Rollback();
    ~Rollback();

    void update(Transaction* t);
    Transaction goBack();

private:
    GenStack<Transaction>* myActions;
};

#endif
