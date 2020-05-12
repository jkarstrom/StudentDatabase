#include "Transaction.h"

Transaction::Transaction(){
    number = 0;
    specialID = 0;
    reversed = false;
    sSoul = new Student();
    fSoul = new Faculty();
}

Transaction::Transaction(int n){
    number = n;
    specialID = 0;
    reversed = false;
    sSoul = new Student();
    fSoul = new Faculty();
}

Transaction::~Transaction(){

}

int Transaction::getNum(){
    return number;
}

void Transaction::proceed(BST<Student>* sTree, BST<Faculty>* fTree){
    if(number == 7){
        if(!reversed){
            // add a NEW student
            Student* rene = new Student();
            rene->fillInfo();
            if(!fTree->search(rene->getAdvisor()))
                cout << "Invalid advisor ID. Please try again." << endl;
            else{
                specialID = rene->getID();
                sTree->insert(specialID, rene);

            }
        }
        else{
            // add a DEAD student
            sTree->insert(specialID, sSoul);
        }

    }
    else if(number == 8){
        if(!reversed){
            cout << "Enter student ID: ";
            cin >> specialID;
        }
        sTree->search(specialID, 7, sSoul);
        sTree->deleteNode(specialID);
    }

}

void Transaction::reverse(){
    if(number == 7)
        number = 8;
    else if(number == 8)
        number = 7;
    else if(number == 9)
        number == 10;
    else if(number == 10)
        number == 9;
    else if(number == 11)
        number == 12;
    else if(number == 12)
        number == 11;
    reversed = true;
}
