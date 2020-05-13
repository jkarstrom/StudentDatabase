//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 5: Student Database

#ifndef BST_H
#define BST_H
#include "TreeNode.h"

template <class T>
class BST{
public:
    BST<T>();
    ~BST();
    // virtual ~BST() - when working with template classes

    void insert(int id, T* value);
    bool search(int id, int action = 0, T* soul = NULL);
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();

    TreeNode<T>* getSuccessor(TreeNode<T>*d);
    void printTree(TreeNode<T> *d = NULL);
    TreeNode<T>* getRoot();


private:
    TreeNode<T> *root;
};
#endif
