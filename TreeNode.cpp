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
