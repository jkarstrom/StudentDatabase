//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef TREENODE_H
#define TREENODE_H
#include "Student.h"
#include "Faculty.h"

template<class T>
class TreeNode{
public:
    TreeNode<T>();
    TreeNode<T>(int k);
    TreeNode<T>(int k,T* v);
    ~TreeNode();
    // virtual ~TreeNode(); -when working with a template class

    int key;
    T* value;
    TreeNode<T> *left;
    TreeNode<T> *right;

};

#endif
