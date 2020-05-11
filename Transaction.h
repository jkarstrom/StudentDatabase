#include <iostream>
using namespace std;

class Transaction{
public:
    Transaction();
    Transaction(int n);
    ~Transaction();

    int getNum();

private:
    int number;
};
