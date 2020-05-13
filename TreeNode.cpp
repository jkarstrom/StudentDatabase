//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#include "TreeNode.h"

// treenode implementation
template<class T>
TreeNode<T>::TreeNode(){
    key = 0;
    value = NULL;
    left = NULL;
    right = NULL;
}

template<class T>
TreeNode<T>::TreeNode(int k, T* v){
    key = k;
    value = v;
    left = NULL;
    right = NULL;
}

// ill leave implementation of destructor to you
template<class T>
TreeNode<T>::~TreeNode(){
    if(left != NULL){
        left = NULL;
    }
    if(right != NULL){
        right = NULL;
    }
}

template class TreeNode<Faculty>;
template class TreeNode<Student>;
