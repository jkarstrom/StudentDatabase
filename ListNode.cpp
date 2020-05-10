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
