#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"

class Transaction{
public:
    Transaction();
    Transaction(int n);
    ~Transaction();

    int getNum();

    void proceed(BST<Student>* sTree, BST<Faculty>* fTree);
    void reverse();

private:
    int number;
    int specialID;
    bool reversed;
    Student* sSoul;
    Faculty* fSoul;
};

#endif
