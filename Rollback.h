#include "GenStack.h"

class Rollback{
public:
    Rollback();
    ~Rollback();

    void update();
    int goBack();

private:
    GenStack<Transaction> myActions;
};
