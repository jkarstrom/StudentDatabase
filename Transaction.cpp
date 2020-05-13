//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Transaction.h"

Transaction::Transaction(){
    number = 0;
    specialID = 0;
    reversed = false;
    sSoul = new Student();
    fSoul = new Faculty();
    holdingID = 0;
}

Transaction::Transaction(int n){
    number = n;
    specialID = 0;
    reversed = false;
    sSoul = new Student();
    fSoul = new Faculty();
    holdingID = 0;
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

                int aID = rene->getAdvisor();
                fTree->search(aID,7,fSoul);
                fSoul->addAdvisee(specialID);
                fTree->deleteNode(aID);
                fTree->insert(aID, fSoul);

                sTree->insert(specialID, rene);
            }
        }
        else{
            // resurrect DEAD student
            sTree->insert(specialID, sSoul);
            // add to advisor
            int aID = sSoul->getAdvisor();
            fTree->search(aID,7,fSoul);
            fSoul->addAdvisee(specialID);
            fTree->deleteNode(aID);
            fTree->insert(aID, fSoul);
        }

    }
    else if(number == 8){
        // delete a student
        if(!reversed){
            cout << "Enter student ID: ";
            cin >> specialID;
            sTree->search(specialID, 8, sSoul);
        }
        // remove from advisor
        int aID = sSoul->getAdvisor();
        fTree->search(aID,7,fSoul);
        fSoul->removeAdvisee(specialID);
        fTree->deleteNode(aID);
        fTree->insert(aID, fSoul);

        sTree->deleteNode(specialID);
    }
    else if(number == 9){
        if(!reversed){
            // add a NEW faculty member
            Faculty* german = new Faculty();

            german->fillInfo();
            specialID = german->getID();
            fTree->insert(specialID, german);
        }
        else{
            // resurrect DEAD faculty
            fTree->insert(specialID, fSoul);
        }
    }
    else if(number == 10){
        // delete a faculty member
        Faculty* temp;
        if(!reversed){
            cout << "Enter faculty ID: ";
            cin >> specialID;
            fTree->search(specialID, 10, fSoul);
            temp = fSoul; // temp is faculty to delete
        }
        // reassign advisees to another faculty
        if(fSoul->isAdvisor()){
            cout << "Enter advisor ID for reassigned advisees: ";
            cin >> holdingID;
            if(!fTree->search(holdingID))
                cout << "Invalid advisor ID. Please try again." << endl;
            else{
                fTree->search(holdingID,7,fSoul); // fSoul is now replacement
                fSoul->copyAdvisee(temp->getAdvisees());
                fTree->deleteNode(holdingID);
                fTree->insert(holdingID, fSoul);
            }
        }
        else{
            fTree->deleteNode(specialID);
        }
        temp = NULL;

    }
    else if(number == 11){
        if(!reversed){
            // change advisor
            cout << "Enter student ID: ";
            cin >> specialID;
            sTree->search(specialID, 11, sSoul);
            int temp = sSoul->getAdvisor();
            cout << "Enter new advisor ID: ";
            cin >> holdingID;
            if(!fTree->search(holdingID))
                cout << "Invalid advisor ID. Please try again." << endl;
            else{
                sSoul->setAdvisor(holdingID);
                sTree->deleteNode(specialID);
                sTree->insert(specialID, sSoul);
            }
            holdingID = temp;
        }
        else{
            // switch back advisor
            sSoul->setAdvisor(holdingID);
            sTree->deleteNode(specialID);
            sTree->insert(specialID, sSoul);
        }
    }
    else if(number == 12){
        if(!reversed){
            // remove advisee
            cout << "Enter faculty ID: ";
            cin >> specialID;
            fTree->search(specialID, 12, fSoul);
            cout << "Enter advisee ID: ";
            cin >> holdingID;
            if(!sTree->search(holdingID))
                cout << "Invalid advisee ID. Please try again." << endl;
            else{
                fSoul->removeAdvisee(holdingID);
                fTree->deleteNode(specialID);
                fTree->insert(specialID, fSoul);
            }
        }
        else{
            // add back advisee
            fSoul->addAdvisee(holdingID);
            fTree->deleteNode(specialID);
            fTree->insert(specialID, fSoul);
        }

    }

}

void Transaction::reverse(){
    if(number == 7)
        number = 8;
    else if(number == 8)
        number = 7;
    else if(number == 9)
        number = 10;
    else if(number == 10)
        number = 9;

    reversed = true;
}
