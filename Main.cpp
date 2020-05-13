//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "Database.h"

int main(int argc, char ** argv){

    Database *myDatabase = new Database();
    while(myDatabase->isRunning()){
        myDatabase->run();
    }

    delete myDatabase;
    return 0;
}
