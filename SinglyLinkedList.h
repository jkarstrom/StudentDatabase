#include "ListNode.h"

class SinglyLinkedList{
private:
    ListNode *front;
    unsigned int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertFront(int id);
    int removeFront();
    int search(int val); //will return position of node
    int removeAtPos(int pos);

    unsigned int getSize();
    book isEmpty();
    void printList();
};
