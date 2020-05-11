#include "Transaction.h"

Transaction::Transaction(){
    number = 0;
    specialID = 0;
}

Transaction::Transaction(int n, int id){
    number = n;
    specialID = id;
}

Transaction::~Transaction(){

}

int Transaction::getNum(){
    return number;
}
