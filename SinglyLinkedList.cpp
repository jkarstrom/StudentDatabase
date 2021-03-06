//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database
#include "SinglyLinkedList.h"

//implementation file
SinglyLinkedList::SinglyLinkedList(){
    size = 0;
    front = NULL;
}

SinglyLinkedList::~SinglyLinkedList(){
    front = NULL;
}

void SinglyLinkedList::insertFront(int id){
    ListNode *node = new ListNode(id);
    node->next = front;
    front = node;
    size++;
}

int SinglyLinkedList::removeFront(){
    //check if isEmpty
    int temp = front->data;
    ListNode *ft = front;
    front = front->next;
    ft->next = NULL;
    delete ft;
    size--;
    return temp;
}

// O(n)
int SinglyLinkedList::search(int val){
    int pos = -1;
    ListNode *curr = front;
    // let's loop and attempt to find the value
    while(curr != NULL){
        ++pos;
        if(curr->data == val){
            // we found it
            break;
        }
        else{
            // we didn't find it, continue iterating
            curr = curr->next;
        }

        if(curr == NULL){
            // we didn't find it
            pos = -1;
        }

    }
    return pos;
}

int SinglyLinkedList::removeAtPos(int pos){
    // error to make sure pos doesn't exceed size of ListNode
    int idx = 0;
    ListNode *curr = front;
    ListNode *prev = front;

    while(idx != pos){
        // loop until I find the position
        prev = curr;
        curr = curr->next;
        idx++;
    }

    // now let's continue with the deletion process
    prev->next = curr->next;
    curr->next = NULL;
    int temp = curr->data;
    delete curr;
    size--;

    return temp;
}

unsigned int SinglyLinkedList::getSize(){
    return size;
}

bool SinglyLinkedList::isEmpty(){
    return (size == 0);
}

void SinglyLinkedList::printList(){
    ListNode *curr = front;
    if(!isEmpty()){
        while(curr != NULL){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
}
