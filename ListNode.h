#include <iosteam>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *next;

    ListNode(); //constructor
    ListNode(int d); // overloaded
    ~ListNode();
};
