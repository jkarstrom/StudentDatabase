//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "ListNode.h"

ListNode::ListNode(){
    data = 0;
    next = NULL;
}

ListNode::ListNode(int d){
    data = d;
    next = NULL;
}

ListNode::~ListNode(){
    next = NULL;
}
