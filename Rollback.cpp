//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

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

Transaction* Rollback::goBack(){
    // return latest transaction
    return myActions->pop();
}
