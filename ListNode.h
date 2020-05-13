//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode *next;

    ListNode(); //constructor
    ListNode(int d); // overloaded
    ~ListNode();
};

#endif
