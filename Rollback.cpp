#include "Rollback.h"

Rollback::Rollback(){
    myActions = new GenStack<Transaction>(5);
}

Rollback::~Rollback(){

}

void Rollback::update(){

}

void Rollback::goBack(){

}
