#include "Database.h"

int main(int argc, char ** argv){
    
    Database *myDatabase = new Database();
    while(myDatabase->isRunning()){
        myDatabase->run();
    }

    delete myDatabase;
    return 0;
}
