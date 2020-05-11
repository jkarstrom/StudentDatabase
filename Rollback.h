#include "GenStack.h"
#include "Transaction.h"

class Rollback{
public:
    Rollback();
    ~Rollback();

    void update();
    int goBack();

private:
    GenStack<Transaction> myActions;
};
