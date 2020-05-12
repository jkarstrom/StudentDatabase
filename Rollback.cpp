#include "Rollback.h"

Rollback::Rollback(){
    myActions = new GenStack<Transaction>();
}

Rollback::~Rollback(){

}

void Rollback::update(Transaction* t){
    // add transaction to stack
    myActions->push(t);
}

Transaction Rollback::goBack(){
    // return latest transaction
    return myActions->pop();
}
