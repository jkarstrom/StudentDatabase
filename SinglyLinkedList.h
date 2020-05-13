//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
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
    bool isEmpty();
    void printList();
};

#endif
