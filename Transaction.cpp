#include "Transaction.h"

Transaction::Transaction(){

}

Transaction::Transaction(int n){
    number = n;
}

Transaction::~Transaction(){

}

int Transaction::getNum(){
    return number;
}
